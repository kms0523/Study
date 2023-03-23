#ifndef __MEC_DENSEMATRIX_H
#define __MEC_DENSEMATRIX_H

#include "MecVector.h"
#include "MecTinyMatrix.h"
#include "MecSimpleMatrix.h"

namespace Mec {

template <typename OprType,typename MatrixType>
class MatrixExpr1;

template <typename LeftType,typename OprType,typename RightType>
class MatrixExpr2;

template <typename data_type>
class DenseSystemMatrix;

template <typename data_type>
class ColVarMatrix;

//! Fortran style storage (column major) but indexing starts from 0
//! Caution : copy constructor makes shallow copy while = operator performs deep copy
template <typename data_type>
class DenseMatrix : public SimpleMatrix<data_type> {
private:

  typedef DenseMatrix       ThisType;
  bool _alloc;

public:
  typedef data_type   EntryType;
  typedef data_type   T_numtype;
  typedef DenseMatrix T_array;
  typedef data_type*             iterator;
  typedef const data_type*       const_iterator;
  typedef DenseMatrix       MatrixRangeType;
  typedef Vector<data_type> VectorRangeType;

// constructors
  DenseMatrix(void):SimpleMatrix<data_type>(),_alloc(true) {}
  DenseMatrix(size_type nr,size_type nc):SimpleMatrix<data_type>(nr,nc),_alloc(true) {}
  // shallow copy constructors
  DenseMatrix(const DenseMatrix<data_type>& mat)
    :SimpleMatrix<data_type>(mat.rows(),mat.columns(),mat.data(),mat.get_ld()),_alloc(false) { if(this->data()==NULL) _alloc=true; }
  template <size_type max_rows,size_type max_cols>
  DenseMatrix(const TinyMatrix<data_type,max_rows,max_cols>& mat)
    :SimpleMatrix<data_type>(mat.rows(),mat.columns(),mat.data(),mat.get_ld()),_alloc(false) {}
  DenseMatrix(const Vector<data_type>& vec)
    :SimpleMatrix<data_type>(vec.size(),1,vec.data()),_alloc(false) { assert(this->data()); assert(vec.get_stride()==1); }
  DenseMatrix(size_type nr,size_type nc,const data_type* _RESTRICT dp,size_type ld=0)
    :SimpleMatrix<data_type>(nr,nc,dp,ld),_alloc(false) { assert(this->data()); }
  // will be removed
  //explicit DenseMatrix(const BlitzMatrixType& mat)
  //  :SimpleMatrix<data_type>(mat.rows(),mat.columns(),mat.data(),mat.stride(blitz::secondDim)),_alloc(false) { assert(this->data()); }

// destructor
  ~DenseMatrix(void) { if(!_alloc) MatrixRef<data_type>::set_ptr(NULL); }

// non-virtual member functions
  void resize(size_type nr,size_type nc)  { if(!_alloc) assert(this->equal_shape(nr,nc)); else SimpleMatrix<data_type>::resize(nr,nc); }
  void resize_preserve(size_type nr,size_type nc) { assert(_alloc); SimpleMatrix<data_type>::resize_preserve(nr,nc); }
  void try_resize(size_type nr,size_type nc);
  void free(void) { assert(_alloc); SimpleMatrix<data_type>::free(); }
  void clear(void) { assert(_alloc); SimpleMatrix<data_type>::clear(); }

  void reference(const DenseMatrix& mat) { assert(this->size()==0 || _alloc==false); MatrixRef<data_type>::copy_member_(mat); if(this->size()) _alloc=false; else _alloc=true; }

  template <typename MatrixType>
  MatrixRef<data_type>& set(MatrixType& mat) {
    if(_alloc) clear();
    _alloc=false;
    return MatrixRef<data_type>::set(mat);
  }

  data_type&              _RESTRICT operator[](idx_type i) { idx_type ir=i%this->rows(),ic=i/this->rows(); return this->get_(ir,ic); } 
  const data_type&        _RESTRICT operator[](idx_type i) const { idx_type ir=i%this->rows(),ic=i/this->rows(); return this->get_(ir,ic); }

  data_type&              _RESTRICT operator()(idx_type i,idx_type j) { return this->get_(i,j); } 
  const data_type&        _RESTRICT operator()(idx_type i,idx_type j) const { return this->get_(i,j); }
  DenseMatrix             operator()(const Range& r_r,const Range& r_c);
  const DenseMatrix       operator()(const Range& r_r,const Range& r_c) const;
  Vector<data_type>       operator()(const Range& r_r,idx_type ic);
  const Vector<data_type> operator()(const Range& r_r,idx_type ic) const;
  Vector<data_type>       operator()(idx_type ir,const Range& r_c);
  const Vector<data_type> operator()(idx_type ir,const Range& r_c) const;

  DenseMatrix& operator=(const DenseMatrix& mat) { return copy_mat(*this,mat); }
  //template <typename MatrixType>
  //DenseMatrix& operator=(const MatrixType& mat) { return copy_mat(*this,mat); }
  template <typename data_type1>
  DenseMatrix& operator=(const SimpleMatrix<data_type1>& mat) { return copy_mat(*this,mat); }
  template <typename OprType,typename MatrixType>
  DenseMatrix& operator=(const MatrixExpr1<OprType,MatrixType>& mat) { return copy_mat(*this,mat); }
  template <typename LeftType,typename OprType,typename RightType>
  DenseMatrix& operator=(const MatrixExpr2<LeftType,OprType,RightType>& mat) { return copy_mat(*this,mat); }
  template <typename data_type1,size_type NR,size_type NC>
  DenseMatrix& operator=(const TinyMatrix<data_type1,NR,NC>& mat) { return copy_mat(*this,mat); }
  template <typename data_type1>
  DenseMatrix& operator=(const DenseSystemMatrix<data_type1>& mat) { return copy_mat(*this,mat); }
  template <typename data_type1>
  DenseMatrix& operator=(const TransposeRef<data_type1>& mat) { return copy_mat(*this,mat); }
  template <typename data_type1>
  DenseMatrix& operator=(const ColVarMatrix<data_type1>& mat);

  TransposeRef<data_type> transpose(void) const { return TransposeRef<data_type>(*this); }
  TransposeRef<data_type> transpose(idx_type i,idx_type j) const { return TransposeRef<data_type>(*this); }

  DEF_MAT_COMMA_ASSIGNMENT

  DEF_MAT_MAT_OPERATOR(+=)
  DEF_MAT_MAT_OPERATOR(-=)
  DEF_MAT_MAT_OPERATOR(*=)
  DEF_MAT_MAT_OPERATOR(/=)

  DEF_MAT_SCAL_OPERATOR(+=)
  DEF_MAT_SCAL_OPERATOR(-=)
  DEF_MAT_SCAL_OPERATOR(*=)
  DEF_MAT_SCAL_OPERATOR(/=)

  // will be removed
  //BlitzMatrixType get(void) {
  //  if(this->data()==NULL) return BlitzMatrixType();
  //  BlitzMatrixType tmat(this->data(),blitz::shape(get_ld(),this->columns()),blitz::neverDeleteData);
  //  if(rows()<get_ld())
  //    return tmat(Range(0,rows()-1),Range::all());
  //  return tmat;
  //}

  //const BlitzMatrixType get(void) const {
  //  if(this->data()==NULL) return BlitzMatrixType();
  //  BlitzMatrixType tmat(const_cast<data_type*>(this->data()),blitz::shape(get_ld(),this->columns()),blitz::neverDeleteData);
  //  if(rows()<get_ld())
  //    return tmat(Range(0,rows()-1),Range::all());
  //  return tmat;
  //}

  //DenseMatrix& get(void) { return *this; }
  //const DenseMatrix& get(void) const { return *this; }
};

template <typename data_type>
inline DenseMatrix<data_type> DenseMatrix<data_type>::operator()(const Range& r_r,const Range& r_c) 
{ 
  assert(r_r.stride()==1); 
  assert(r_c.stride()==1); 
  idx_type ir=r_r.first();
  idx_type ic=r_c.first();
  idx_type nr=r_r.last(this->rows()-1)-ir+1;
  idx_type nc=r_c.last(this->columns()-1)-ic+1;
  return DenseMatrix<data_type>(nr,nc,&(operator()(ir,ic)),this->get_ld());
}

template <typename data_type>
inline const DenseMatrix<data_type> DenseMatrix<data_type>::operator()(const Range& r_r,const Range& r_c) const
{ 
  assert(r_r.stride()==1); 
  assert(r_c.stride()==1); 
  idx_type ir=r_r.first();
  idx_type ic=r_c.first();
  idx_type nr=r_r.last(this->rows()-1)-ir+1;
  idx_type nc=r_c.last(this->columns()-1)-ic+1;
  return DenseMatrix<data_type>(nr,nc,&(operator()(ir,ic)),this->get_ld());
}

template <typename data_type>
inline Vector<data_type> DenseMatrix<data_type>::operator()(const Range& r_r,idx_type ic) 
{
  assert(r_r.stride()==1); 
  idx_type ir=r_r.first();
  return Vector<data_type>(&(operator()(ir,ic)),r_r.last(this->rows()-1)-ir+1,1);
}

template <typename data_type>
inline const Vector<data_type> DenseMatrix<data_type>::operator()(const Range& r_r,idx_type ic) const
{
  assert(r_r.stride()==1); 
  idx_type ir=r_r.first();
  return Vector<data_type>(&(operator()(ir,ic)),r_r.last(this->rows()-1)-ir+1,1);
}

template <typename data_type>
inline Vector<data_type> DenseMatrix<data_type>::operator()(idx_type ir,const Range& r_c)
{
  assert(r_c.stride()==1); 
  idx_type ic=r_c.first();
  return Vector<data_type>(&(operator()(ir,ic)),r_c.last(this->columns()-1)-ic+1,this->get_ld());
}

template <typename data_type>
inline const Vector<data_type> DenseMatrix<data_type>::operator()(idx_type ir,const Range& r_c) const
{
  assert(r_c.stride()==1); 
  idx_type ic=r_c.first();
  return Vector<data_type>(&(operator()(ir,ic)),r_c.last(this->columns()-1)-ic+1,this->get_ld());
}

template <typename data_type>
inline void DenseMatrix<data_type>::try_resize(size_type nr,size_type nc) 
{ 
  try {
    resize(nr,nc);
  }
  catch ( std::bad_alloc &e ) {
    release_memory(0); 
    resize(nr,nc);
  }
}

template <typename data_type>
template <typename data_type1>
inline DenseMatrix<data_type>& DenseMatrix<data_type>::operator=(const ColVarMatrix<data_type1>& mat)
{
  size_type nr=mat.rows();
  size_type nc=mat.columns();
  this->resize(nr,nc);
  idx_type ic;
  for(ic=0; ic<nc; ic++) operator()(Range::all(),ic) = mat(Range::all(),ic);
  return *this;
}

//template <typename data_type,size_type max_rows,size_type max_cols>
//inline DenseMatrix<data_type> TinyMatrix<data_type,max_rows,max_cols>::get(void)
//{
//  return DenseMatrix<data_type>(*this);
//}
//
//template <typename data_type,size_type max_rows,size_type max_cols>
//inline const DenseMatrix<data_type> TinyMatrix<data_type,max_rows,max_cols>::get(void) const
//{
//  return DenseMatrix<data_type>(*this);
//}

template <typename data_type,size_type max_rows,size_type max_cols>
inline DenseMatrix<data_type> TinyMatrix<data_type,max_rows,max_cols>::operator()(const Range& r_r,const Range& r_c)
{
  assert(r_r.stride()==1); 
  assert(r_c.stride()==1); 
  idx_type ir=r_r.first();
  idx_type ic=r_c.first();
  idx_type nr=r_r.last(this->rows()-1)-ir+1;
  idx_type nc=r_c.last(this->columns()-1)-ic+1;
  DenseMatrix<data_type> mr(nr,nc,&_data[ic][ir],max_rows); //mr(&_data[ic][ir],nr,nc);
  return mr;
}

template <typename data_type,size_type max_rows,size_type max_cols>
inline const DenseMatrix<data_type> TinyMatrix<data_type,max_rows,max_cols>::operator()(const Range& r_r,const Range& r_c) const
{
  assert(r_r.stride()==1); 
  assert(r_c.stride()==1); 
  idx_type ir=r_r.first();
  idx_type ic=r_c.first();
  idx_type nr=r_r.last(this->rows()-1)-ir+1;
  idx_type nc=r_c.last(this->columns()-1)-ic+1;
  DenseMatrix<data_type> mr(nr,nc,&_data[ic][ir],max_rows); //mr(&_data[ic][ir],nr,nc);
  return mr;
}



typedef DenseMatrix<real_type>    RealDenseMatrix;
typedef RealDenseMatrix           RealMatrix;
typedef DenseMatrix<real4_type>   FloatMatrix;
typedef DenseMatrix<idx_type>     IdxDenseMatrix;
typedef IdxDenseMatrix            IdxMatrix;

typedef DenseMatrix<complex_type> ComplexMatrix;

DEF_SHARED_PTR(RealDenseMatrix)
DEF_SHARED_PTR(IdxDenseMatrix)
DEF_SHARED_PTR(RealMatrix)
DEF_SHARED_PTR(IdxMatrix)
DEF_SHARED_PTR(ComplexMatrix)
DEF_SHARED_PTR(FloatMatrix)

} // namespace Mec

namespace BLAS {

template <typename data_type>
inline Mec::size_type get_ld(const Mec::DenseMatrix<data_type>& mat) 
{ 
  return mat.get_ld(); 
}

} // namespace BLAS

#include "MecMatrixExpr.h"

#endif
