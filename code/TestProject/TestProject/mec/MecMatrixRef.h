#ifndef __MEC_MATRIXREF_H
#define __MEC_MATRIXREF_H

#include "MecCommaAssignment.h"
#include "MecVector.h"
#ifdef _LINUX
#include "boost/format/format_fwd.hpp"
#endif

namespace Mec {

#define DEF_MAT_SCAL_OPERATOR(opr) \
ThisType& operator opr (const data_type& val) { \
  if(this->has_continuous_storage()) { \
    iterator it1=this->begin(); \
    iterator iend=this->end(); \
    for(;it1!=iend;++it1) *it1 opr val; \
  } \
  else { \
    for(idx_type i=0;i<this->columns();++i) { \
      iterator it1=this->begin(i); \
      iterator iend=this->end(i); \
      for(;it1!=iend;++it1) *it1 opr val; \
    } \
  } \
  return *this; \
}

/*#define DEF_MAT_SCAL_OPERATOR(opr) \
__pragma(intel optimization_parameter target_arch=AVX) \
ThisType& operator opr (const data_type& val) { \
  if(this->has_continuous_storage()) { \
    data_type* it1=this->begin(); \
    size_type sz=this->size(); \
__pragma(omp simd aligned(it1:_MEM_ALIGN_BND)) \
    for(idx_type i=0;i<sz;++i) it1[i] opr val; \
  } \
  else { \
    for(idx_type i=0;i<this->columns();++i) { \
      iterator it1=this->begin(i); \
      iterator iend=this->end(i); \
      for(;it1!=iend;++it1) *it1 opr val; \
    } \
  } \
  return *this; \
}*/ //(lkb1024-vec)

#define DEF_MAT_MAT_OPERATOR(opr) \
template <typename MatrixArgType> \
ThisType& operator opr (const MatrixArgType& mat) { \
  assert(this->rows()==mat.rows() && this->columns()==mat.columns()); \
  if(mat.not_transposed()) { \
    if(this->has_continuous_storage() && mat.has_continuous_storage()) { \
      iterator it1=this->begin(); \
      typename MatrixArgType::const_iterator it2=mat.begin(); \
      size_type sz=this->size(); \
      for(idx_type i=0;i<sz;++i) it1[i] opr it2[i]; \
    } \
    else { \
      size_type sz=this->rows(); \
      for(idx_type i=0;i<this->columns();++i) { \
        iterator it1=this->begin(i); \
        typename MatrixArgType::const_iterator it2=mat.begin(i); \
        for(idx_type i=0;i<sz;++i) it1[i] opr it2[i]; \
      } \
    } \
  } \
  else { \
    idx_type i,j; \
    for(i=0;i<this->columns();i++) for(j=0;j<this->rows();j++) operator()(j,i) opr mat(j,i); \
  } \
  return *this; \
} /*\
__pragma(intel optimization_parameter target_arch=AVX) \
ThisType& operator opr (const ThisType& mat) { \
  assert(this->rows()==mat.rows() && this->columns()==mat.columns()); \
  if(mat.not_transposed()) { \
    if(this->has_continuous_storage() && mat.has_continuous_storage()) { \
      iterator it1=this->begin(); \
      typename ThisType::const_iterator it2=mat.begin(); \
      size_type sz=this->size(); \
__pragma(omp simd aligned(it1,it2:_MEM_ALIGN_BND)) \
      for(idx_type i=0;i<sz;++i) it1[i] opr it2[i]; \
    } \
    else { \
      size_type sz=this->rows(); \
      for(idx_type i=0;i<this->columns();++i) { \
        iterator it1=this->begin(i); \
        typename ThisType::const_iterator it2=mat.begin(i); \
        for(idx_type i=0;i<sz;++i) it1[i] opr it2[i]; \
      } \
    } \
  } \
  else { \
    idx_type i,j; \
    for(i=0;i<this->columns();i++) for(j=0;j<this->rows();j++) operator()(j,i) opr mat(j,i); \
  } \
  return *this; \
}*/ //(lkb1024-vec)

#define DEF_MAT_MAT_OPERATOR_TR(opr) \
template <typename MatrixArgType> \
ThisType& operator opr (const MatrixArgType& mat) { \
  assert(this->rows()==mat.rows() && this->columns()==mat.columns()); \
  if(mat.transposed()) { \
    if(has_continuous_storage() && mat.has_continuous_storage()) { \
      iterator it1=begin(); \
      MatrixArgType::const_iterator it2=mat.begin(); \
      size_type sz=size(); \
      for(idx_type i=0;i<sz;++i) it1[i] opr it2[i]; \
    } \
    else { \
      size_type sz=MatrixDim::rows(); \
      for(idx_type i=0;i<MatrixDim::columns();++i) { \
        iterator it1=begin(i); \
        MatrixArgType::const_iterator it2=mat.begin(i); \
        for(idx_type i=0;i<sz;++i) it1[i] opr it2[i]; \
      } \
    } \
  } \
  else { \
    idx_type i,j; \
    for(i=0;i<columns();i++) for(j=0;j<rows();j++) operator()(j,i) opr mat(j,i); \
  } \
  return *this; \
}

#define DEF_MAT_REDUCE_ARG(opr,opr_mem,MatrixType,__cols__) \
inline typename MatrixType::T_numtype opr(const MatrixType& mat) { \
  typename MatrixType::T_numtype val; \
  if(mat.has_continuous_storage()) { \
    typename MatrixType::iterator it1=mat.begin(); \
    typename MatrixType::iterator iend=mat.end(); \
    val= *it1; \
    for(++it1;it1!=iend;++it1) val=opr_mem(val,*it1); \
  } \
  else { \
    typename MatrixType::iterator it1=mat.begin(0); \
    typename MatrixType::iterator iend=mat.end(0); \
    val= *it1; \
    for(++it1;it1!=iend;++it1) val=opr_mem(val,*it1); \
    for(idx_type i=1;i<mat.__cols__();++i) { \
      it1=mat.begin(i); \
      iend=mat.end(i); \
      for(;it1!=iend;++it1) val=opr_mem(val,*it1); \
    } \
  } \
  return val; \
}

class MatrixDim {
private:
  size_type _nr,_nc;

protected:
  void set_dim(size_type nr,size_type nc) { _nr=nr; _nc=nc; }
  void assert_idx(idx_type ir,idx_type ic) const { assert(ir>=0 && ir<_nr); assert(ic>=0 && ic<_nc); }

  MatrixDim(void):_nr(0),_nc(0) {}
  MatrixDim(size_type nr,size_type nc):_nr(nr),_nc(nc) {}

public:
  lsize_type size(void) const { return (lsize_type)_nr*_nc; }
  size_type rows(void) const { return _nr; }
  size_type columns(void) const { return _nc; }
  bool      equal_shape(size_type nr,size_type nc) { return (_nr==nr && _nc==nc); }
  void      resize(size_type nr,size_type nc) { assert(equal_shape(nr,nc)); }
  template <typename MatrixType>
  bool      equal_shape(const MatrixType& mat) { return equal_shape(mat.rows(),mat.columns()); }

  template <typename MatrixType1,typename MatrixType2>
  static MatrixType1& copy_mat_(MatrixType1& dest,const MatrixType2& src)
  {
    size_type nr=src.rows();
    size_type nc=src.columns();
    idx_type i,j;
    for(i=0;i<nc;i++) for(j=0;j<nr;j++) dest(j,i) = src(j,i);
    return dest;
  }

  template <typename MatrixType1,typename MatrixType2>
  static MatrixType1& copy_mat(MatrixType1& dest,const MatrixType2& src)
  {
    size_type nr=src.rows();
    size_type nc=src.columns();
    dest.resize(nr,nc);
    if(src.not_transposed()) {
      if(dest.has_continuous_storage() && src.has_continuous_storage()) {
        typename MatrixType1::iterator it1=dest.begin();
        typename MatrixType2::const_iterator it2=src.begin();
        size_type sz=dest.size();
        for(idx_type i=0;i<sz;++i) it1[i] = it2[i];
        //memcpy(it1,it2,sizeof(MatrixType1::T_numtype)*sz); //(lkb1024-vec)
      }
      else { 
        for(idx_type i=0;i<nc;++i) {
          typename MatrixType1::iterator it1=dest.begin(i);
          typename MatrixType2::const_iterator it2=src.begin(i);
          for(idx_type i=0;i<nr;++i) it1[i] = it2[i];
        }
      }
    }
    else
      copy_mat_(dest,src);
    return dest;
  }

  template <typename MatrixType1,typename MatrixType2>
  static MatrixType1& copy_mat_tr(MatrixType1& dest,const MatrixType2& src)
  {
    size_type nr=src.rows();
    size_type nc=src.columns();
    dest.resize(nr,nc);
    if(src.transposed()) {
      if(dest.has_continuous_storage() && src.has_continuous_storage()) {
        MatrixType1::iterator it1=dest.begin();
        MatrixType2::const_iterator it2=src.begin();
        size_type sz=dest.size();
        for(idx_type i=0;i<sz;++i) it1[i] = it2[i];
      }
      else { 
        for(idx_type i=0;i<nr;++i) {
          MatrixType1::iterator it1=dest.begin(i);
          MatrixType2::const_iterator it2=src.begin(i);
          for(idx_type i=0;i<nc;++i) it1[i] = it2[i];
        }
      }
    }
    else
      copy_mat_(dest,src);
    return dest;
  }

};

///////////////////////////////////////////////////////////////////////////////////

template <typename data_type>
class DenseMatrix;

template <typename data_type,size_type max_rows,size_type max_cols>
class TinyMatrix;

template <typename data_type>
class TransposeRef;

template <typename data_type>
class MatrixRef : public MatrixDim {
public:
  typedef data_type              T_numtype;
  typedef DenseMatrix<data_type> T_array;
  typedef data_type*             iterator;
  typedef const data_type*       const_iterator;
  typedef MatrixRef<data_type>   MatrixRangeType;
  typedef VectorRef<data_type>   VectorRangeType;
  typedef Vector<data_type>      VectorRangeType2;

private:
  typedef MatrixRef ThisType;

  data_type* _RESTRICT _dp;
  size_type _ld;

  MatrixRef& set(data_type *dp,size_type nr,size_type nc,size_type ld=0) {
    _dp=dp; 
    set_dim(nr,nc); 
    if(ld==0) { _ld=nr; } else _ld=ld; 
    return *this;
  }

  explicit MatrixRef(data_type& data) {} // not allowed
  explicit MatrixRef(const data_type& data) {} // not allowed

protected:
  data_type&       _RESTRICT get_(idx_type ir, idx_type ic) { assert_idx(ir, ic);  return *(_dp + ir + (lsize_type)ic*_ld); }
  const data_type& _RESTRICT get_(idx_type ir, idx_type ic) const { assert_idx(ir, ic); return *(_dp + ir + (lsize_type)ic*_ld); }

// only used in SimpleMatrix
  void resize_(size_type nr,size_type nc);
  void resize_preserve_(size_type nr,size_type nc);
  void clear_(void);

  void copy_member_(const MatrixRef& mat) { set(mat._dp,mat.rows(),mat.columns(),mat._ld); }

// static protected member functions
  // only for SimpleMatrix
  static data_type* alloc_data_(size_type nr,size_type nc);
  //static void       free_data_(data_type** ptr);

public:
  MatrixRef(void):MatrixDim(),_dp(NULL),_ld(0) {}
  template <typename MatrixType>
  MatrixRef(const MatrixType& mat):MatrixDim(mat.rows(),mat.columns()),_dp(const_cast<data_type*>(mat.data())),_ld(mat.get_ld()) {}
  template <typename MatrixType>
  MatrixRef(const MatrixType& mat,size_type nr,size_type nc,idx_type ir=0,idx_type ic=0):MatrixDim(nr,nc),_dp(const_cast<data_type*>(&mat(ir,ic))),_ld(mat.get_ld()) {}
  MatrixRef(size_type nr,size_type nc,const data_type* _RESTRICT dp=NULL,size_type ld=0):MatrixDim(nr,nc),_dp(const_cast<data_type*>(dp)),_ld(ld) { if(_ld==0) _ld=nr; }

  ~MatrixRef(void) {}

  //MatrixRef(data_type *dp,size_type nr,size_type nc,size_type ld=0):MatrixDim(nr,nc),_dp(dp) 
  //{ if(ld==0) { _ld=nr; } else _ld=ld; }

  MatrixRef& set_ptr(data_type *dp) { _dp=dp; return *this; }

  template <typename MatrixType>
  MatrixRef& set(MatrixType& mat) {
    set_dim(mat.rows(),mat.columns());
    _dp=mat.data();
    _ld=mat.get_ld();
    return *this;
  }

  data_type*       _RESTRICT data(void) { return _dp; }
  const data_type* _RESTRICT data(void) const{ return _dp; }

  data_type&       _RESTRICT operator()(idx_type ir,idx_type ic) { return get_(ir,ic); }
  const data_type& _RESTRICT operator()(idx_type ir,idx_type ic) const { return get_(ir,ic); }

  size_type get_ld(void) const { return _ld; }

  MatrixRef& operator=(const MatrixRef& mat) { return copy_mat(*this,mat); }
  template <typename MatrixType>
  MatrixRef& operator=(const MatrixType& mat) { return copy_mat(*this,mat); }

  MatrixRef<data_type>       operator()(const Range& r_r,const Range& r_c);
  const MatrixRef<data_type> operator()(const Range& r_r,const Range& r_c) const;
  VectorRef<data_type>       operator()(const Range& r_r,idx_type ic);
  const VectorRef<data_type> operator()(const Range& r_r,idx_type ic) const;
  Vector<data_type>          operator()(idx_type ir,const Range& r_c);
  const Vector<data_type>    operator()(idx_type ir,const Range& r_c) const;

  DEF_MAT_COMMA_ASSIGNMENT

  //DEF_MAT_MAT_OPERATOR(=)
  DEF_MAT_MAT_OPERATOR(+=)
  DEF_MAT_MAT_OPERATOR(-=)
  DEF_MAT_MAT_OPERATOR(*=)
  DEF_MAT_MAT_OPERATOR(/=)

  DEF_MAT_SCAL_OPERATOR(+=)
  DEF_MAT_SCAL_OPERATOR(-=)
  DEF_MAT_SCAL_OPERATOR(*=)
  DEF_MAT_SCAL_OPERATOR(/=)

  ostream& write(ostream& os) const;

  bool has_continuous_storage(void) const { return (rows()==get_ld()); }
  bool has_unit_stride(void) const { return has_continuous_storage(); }
  bool transposed(void) const { return false; }
  bool not_transposed(void) const { return true; }

  iterator       _RESTRICT begin(void) { return _dp; }
  const_iterator _RESTRICT begin(void) const { return _dp; }
  iterator       _RESTRICT end(void) { return end(columns()-1); }
  const_iterator _RESTRICT end(void) const { return end(columns()-1); }
  iterator       _RESTRICT begin(idx_type i) { return _dp+i*_ld; }
  const_iterator _RESTRICT begin(idx_type i) const { return _dp+i*_ld; }
  iterator       _RESTRICT end(idx_type i) { return _dp+i*_ld+rows(); }
  const_iterator _RESTRICT end(idx_type i) const { return _dp+i*_ld+rows(); }
};

template <typename data_type>
inline ostream& MatrixRef<data_type>::write(ostream& os) const 
{
  idx_type i,j;
  os<<"( "<<rows()<<", "<<columns()<<" ) = [ \n"; 
  for(j=0;j<rows();++j) {
    os<<"  ";
    for(i=0;i<columns();++i) os<<boost::format("%20.10E")%operator()(j,i)<<" "; 
    os<<"\n";
  }
  os<<"]\n"; 
  return os; 
}

template <typename data_type>
inline MatrixRef<data_type> MatrixRef<data_type>::operator()(const Range& r_r,const Range& r_c) 
{ 
  assert(r_r.stride()==1); 
  assert(r_c.stride()==1); 
  idx_type ir=r_r.first();
  idx_type ic=r_c.first();
  idx_type nr=r_r.last(rows()-1)-ir+1;
  idx_type nc=r_c.last(columns()-1)-ic+1;
  MatrixRef<data_type> mr(*this,nr,nc,ir,ic); 
  return mr;
}

template <typename data_type>
inline const MatrixRef<data_type> MatrixRef<data_type>::operator()(const Range& r_r,const Range& r_c) const
{ 
  assert(r_r.stride()==1); 
  assert(r_c.stride()==1); 
  idx_type ir=r_r.first();
  idx_type ic=r_c.first();
  idx_type nr=r_r.last(rows()-1)-ir+1;
  idx_type nc=r_c.last(columns()-1)-ic+1;
  MatrixRef<data_type> mr(*this,nr,nc,ir,ic);
  return mr;
}

template <typename data_type>
inline VectorRef<data_type> MatrixRef<data_type>::operator()(const Range& r_r,idx_type ic) 
{
  assert(r_r.stride()==1); 
  idx_type ir=r_r.first();
  VectorRef<data_type> svr(&(operator()(ir,ic)),r_r.last(rows()-1)-ir+1);
  return svr;
}

template <typename data_type>
inline const VectorRef<data_type> MatrixRef<data_type>::operator()(const Range& r_r,idx_type ic) const 
{
  assert(r_r.stride()==1); 
  idx_type ir=r_r.first();
  VectorRef<data_type> svr(&(operator()(ir,ic)),r_r.last(rows()-1)-ir+1);
  return svr;
}

template <typename data_type>
inline Vector<data_type> MatrixRef<data_type>::operator()(idx_type ir,const Range& r_c)
{
  assert(r_c.stride()==1); 
  idx_type ic=r_c.first();
  Vector<data_type> svc(&(operator()(ir,ic)),r_c.last(columns()-1)-ic+1,get_ld());
  return svc;
}

template <typename data_type>
inline const Vector<data_type> MatrixRef<data_type>::operator()(idx_type ir,const Range& r_c) const
{
  assert(r_c.stride()==1); 
  idx_type ic=r_c.first();
  Vector<data_type> svc(&(operator()(ir,ic)),r_c.last(columns()-1)-ic+1,get_ld());
  return svc;
}

template <typename data_type>
inline ostream& operator<<(ostream& os,const MatrixRef<data_type>& mr) { return mr.write(os); }

//! used only for transposed copy
template <typename data_type>
class TransposeRef : public MatrixRef<data_type> {
private:
  typedef TransposeRef ThisType;

  void resize(size_type nr,size_type nc);

  TransposeRef& operator=(const data_type& val);
  TransposeRef<data_type> transpose(void);

public:
  //template <typename MatrixType>
  //TransposeRef(const MatrixType& matr):MatrixRef<data_type>(matr) {}
  template <typename data_type,size_type max_rows,size_type max_cols>
  TransposeRef(const TinyMatrix<data_type,max_rows,max_cols>& matr):MatrixRef<data_type>(matr) {}
  template <typename data_type>
  TransposeRef(const DenseMatrix<data_type>& matr):MatrixRef<data_type>(matr) {}

  data_type&       operator()(idx_type ir,idx_type ic) { return MatrixRef<data_type>::operator()(ic,ir); }
  const data_type& operator()(idx_type ir,idx_type ic) const { return MatrixRef<data_type>::operator()(ic,ir); }

  size_type rows(void) const { return MatrixDim::columns(); }
  size_type columns(void) const { return MatrixDim::rows(); }

  TransposeRef& operator=(const TransposeRef& mat) { return copy_mat_tr(*this,mat); }
  template <typename MatrixType>
  TransposeRef& operator=(const MatrixType& mat) { return copy_mat_tr(*this,mat); }

  DEF_MAT_MAT_OPERATOR_TR(+=)
  DEF_MAT_MAT_OPERATOR_TR(-=)
  DEF_MAT_MAT_OPERATOR_TR(*=)
  DEF_MAT_MAT_OPERATOR_TR(/=)

  DEF_MAT_SCAL_OPERATOR(+=)
  DEF_MAT_SCAL_OPERATOR(-=)
  DEF_MAT_SCAL_OPERATOR(*=)
  DEF_MAT_SCAL_OPERATOR(/=)

  bool has_continuous_storage(void) const { return (rows()==this->get_ld()); }
  bool has_unit_stride(void) const { return has_continuous_storage(); }
  bool transposed(void) const { return true; }
  bool not_transposed(void) const { return false; }
};

typedef MatrixRef<real_type>    RealMatrixRef;
typedef TransposeRef<real_type> TransRealMatrixRef;

} // namespace Mec

namespace BLAS {

template <typename data_type>
Mec::size_type get_ld(const Mec::MatrixRef<data_type>& mat)
{
  return mat.get_ld();
}

} // namespace BLAS

#endif
