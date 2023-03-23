#ifndef __MEC_MINI_VECTOR_H
#define __MEC_MINI_VECTOR_H

#include "MecVectorRef.h"

namespace Mec {

template <typename data_type>
class Vector;

template <typename OprType,typename VectorType>
class VectorExpr1;

template <typename LeftType,typename OprType,typename RightType>
class VectorExpr2;

template <typename data_type,size_type n>
class MiniVector {
public:
  typedef data_type               EntryType;
  typedef data_type               T_numtype;
  typedef SimpleVector<data_type> T_array;
  typedef Vector<data_type>       VectorRangeType;

protected:
  data_type _data[n];

private:
  typedef MiniVector ThisVectorType;

  void valid_range(idx_type idx) const { assert(idx>=0 && idx<size()); }
  data_type& _RESTRICT get_(idx_type idx) 
  { 
#ifdef DEBUG
    valid_range(idx);
#endif
    return _data[idx]; 
  }
  const data_type& _RESTRICT get_(idx_type idx) const 
  { 
#ifdef DEBUG
    valid_range(idx);
#endif
    return _data[idx]; 
  }

  template <typename VectorType>
  MiniVector& check_size_copy_(const VectorType& src) { return VectorRef<data_type>::copy_vec(*this,src); }

public:
  typedef data_type*       iterator;
  typedef const data_type* const_iterator;

  MiniVector(void) {}
  MiniVector(const MiniVector& src) { check_size_copy_(src); }
  MiniVector(const VectorRef<data_type>& src) { check_size_copy_(src); }
  MiniVector(const data_type& a1,const data_type& a2) { assert(n==2); _data[0]=a1; _data[1]=a2; }
  MiniVector(const data_type& a1,const data_type& a2,const data_type& a3) { assert(n==3); _data[0]=a1; _data[1]=a2; _data[2]=a3; }
  MiniVector(const data_type& a1,const data_type& a2,const data_type& a3,const data_type& a4) { assert(n==4); _data[0]=a1; _data[1]=a2; _data[2]=a3; _data[3]=a4; }
  MiniVector(const data_type& a) { for(idx_type i=0; i<n; ++i) _data[i]=a; }
  MiniVector(const array<data_type, n>& a) { for (idx_type i = 0; i < n; ++i) _data[i] = a[i]; }
  explicit MiniVector(size_type len) { assert(len==n); }
  template<typename OprType,typename VectorType>
  MiniVector(const VectorExpr1<OprType,VectorType>& exp) { *this = exp; }
  template<typename LeftType,typename OprType,typename RightType>
  MiniVector(const VectorExpr2<LeftType,OprType,RightType>& exp) { *this = exp; }

  ~MiniVector(void) {}
  
  idx_type get_stride(void) const { return 1; }
  bool     has_unit_stride(void) const { return true; }

  MiniVector& operator=(const MiniVector& dr) { return check_size_copy_(dr); }
  template <typename VectorType>
  MiniVector& operator=(const VectorType& dr) { return check_size_copy_(dr); }
  MiniVector& operator=(const SparseVector<data_type>& dr) { return copy_sparse_vec(*this,dr); }

  
  DEF_VEC_COMMA_ASSIGNMENT

  DEF_VEC_VEC_OPR(+=)
  DEF_VEC_VEC_OPR(-=)
  DEF_VEC_VEC_OPR(*=)
  DEF_VEC_VEC_OPR(/=)  

  DEF_VEC_SCAL_OPR(+=)
  DEF_VEC_SCAL_OPR(-=)
  DEF_VEC_SCAL_OPR(*=)
  DEF_VEC_SCAL_OPR(/=)

  DEF_VEC_SET
  DEF_VEC_COUNT
  DEF_VEC_WRITE
  DEF_VEC_CMP  

  //MiniVector& set(data_type da0,...);
  //data_type   max(void) const;
  //data_type   min(void) const;
  //size_type   count(const data_type& val) const;
  //ostream&    write(ostream& os) const;
  //bool        operator==(const MiniVector& dr) const;

  bool        operator!=(const MiniVector& dr) const { return !(operator==(dr)); }

  data_type*       _RESTRICT data(void) { return _data; }
  const data_type* _RESTRICT data(void) const { return _data; }

  data_type&       _RESTRICT operator()(idx_type idx) { return get_(idx); }
  const data_type& _RESTRICT operator()(idx_type idx) const { return get_(idx); }

  data_type&       _RESTRICT operator[](idx_type idx) { return get_(idx); }
  const data_type& _RESTRICT operator[](idx_type idx) const { return get_(idx); }

  size_type        size(void) const { return n; }
  size_type        physical_size(void) const { return n; }
  size_type        rows(void) const { return size(); }
  size_type        columns(void) const { return 1; }
  
  data_type*       _RESTRICT begin(void) { return _data;  }
  const data_type* _RESTRICT begin(void) const { return _data;  }
  data_type*       _RESTRICT end(void) { return _data+size(); }
  const data_type* _RESTRICT end(void) const { return _data+size(); }

  Vector<data_type> operator()(idx_type ibegin,idx_type iend);       // { return VectorRef<data_type>::range(*this,ibegin,iend); }
  Vector<data_type> operator()(idx_type ibegin,idx_type iend) const; // { return VectorRef<data_type>::range(*const_cast<ThisVectorType*>(this),ibegin,iend); }

  Vector<data_type> operator()(const Range& r);       // { assert(r.stride()==1); return VectorRef<data_type>::range(*this,r.first(),r.last(size()-1)); }
  Vector<data_type> operator()(const Range& r) const; // { assert(r.stride()==1); return VectorRef<data_type>::range(*const_cast<ThisVectorType*>(this),r.first(),r.last(size()-1)); }

  void resize(size_type sz) { assert(size()==sz); }
};

template <typename data_type,size_type n>
inline ostream& operator<<(ostream& os,const MiniVector<data_type,n>& vr) { return vr.write(os); }

typedef MiniVector<real_type,2>  RealVector2;
typedef MiniVector<real_type,3>  RealVector3;
typedef MiniVector<real_type,4>  RealVector4;
typedef MiniVector<real_type,5>  RealVector5;
typedef MiniVector<real_type,6>  RealVector6;
typedef MiniVector<real_type,7>  RealVector7;
typedef MiniVector<real_type,8> RealVector8;
typedef MiniVector<real_type,9>  RealVector9;
typedef MiniVector<real_type, 10>  RealVector10;
typedef MiniVector<real_type,12> RealVector12;
typedef MiniVector<real_type,15> RealVector15;
typedef MiniVector<real_type,18> RealVector18;
typedef MiniVector<real_type,24> RealVector24;

typedef MiniVector<complex_type,2>  ComplexVector2;
typedef MiniVector<complex_type,3>  ComplexVector3;
typedef MiniVector<complex_type,4>  ComplexVector4;
typedef MiniVector<complex_type,5>  ComplexVector5;
typedef MiniVector<complex_type,6>  ComplexVector6;
typedef MiniVector<complex_type,9>  ComplexVector9;
typedef MiniVector<complex_type,12> ComplexVector12;
typedef MiniVector<complex_type,15> ComplexVector15;
typedef MiniVector<complex_type,18> ComplexVector18;
typedef MiniVector<complex_type,24> ComplexVector24;

typedef MiniVector<idx_type,2> IdxVector2;
typedef MiniVector<idx_type,3> IdxVector3;
typedef MiniVector<idx_type,4> IdxVector4;
typedef MiniVector<idx_type,5> IdxVector5;
typedef MiniVector<idx_type,6> IdxVector6;

inline RealVector3 cross(const RealVector3& x,const RealVector3& y)
{
  RealVector3 p;
  p[0]=x[1]*y[2] - y[1]*x[2];
  p[1]=y[0]*x[2] - x[0]*y[2];
  p[2]=x[0]*y[1] - y[0]*x[1];
  return p;
}

template <size_type N>
inline real_type dot(const MiniVector<real_type, N>& x, const MiniVector<real_type, N>& y)
{
  real_type value = 0;
  auto x_data = x.data();
  auto y_data = y.data();
  for (idx_type i = 0; i < N; i++) {
    value += x_data[i] * y_data[i];
  }
  return value;
}

template <size_type N>
inline real_type square(const MiniVector<real_type,N>& x)
{
  return dot(x,x);
}

inline real_type dot(const RealVector3& x,const RealVector3& y)
{
  return ( x[0]*y[0] + x[1]*y[1] + x[2]*y[2] );
}

inline real_type square(const RealVector3& x)
{
  return dot(x, x);
}

} // namespace Mec

namespace BLAS {

template <typename data_type,Mec::size_type n>
inline Mec::size_type get_stride(const Mec::MiniVector<data_type,n>& vec) 
{ 
  return 1;
}

} 

#endif