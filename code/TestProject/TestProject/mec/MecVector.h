#ifndef __MEC_VECTOR_H
#define __MEC_VECTOR_H

#include <blitz/array.h>
#include "MecSimpleVector.h"
#include "MecMiniVector.h"
//#include "MecSparseVector.h"

#if !defined(__BLITZ_DEFAULT_STORAGE)
#if __BLITZ_DEFAULT_STORAGE!=ColumnMajorArray<N_rank>()
  "Blitz default storage should be ColumnMajorArray<N_rank>()"
#endif
#endif

namespace Mec {



//! Caution : copy constructor makes shallow copy while = operator performs deep copy
template <typename data_type>
class Vector : public SimpleVector<data_type> {
private:

  typedef Vector            ThisVectorType;
//#ifdef _LINUX
  //typedef data_type* iterator;
  //typedef const data_type* const_iterator;
//#endif
  idx_type _stride; 
  bool     _alloc;

// static protected member functions
  static Vector range_strd(Vector& vec,idx_type ibegin,idx_type iend,idx_type strd);

public:
  typedef data_type T_numtype;
  typedef Vector<data_type> VectorRangeType;
#ifdef _LINUX
  typedef typename SimpleVector<data_type>::iterator iterator;
  typedef typename SimpleVector<data_type>::const_iterator const_iterator;
#endif


// constructors
  Vector(void):SimpleVector<data_type>(),_alloc(true),_stride(1) {}
  explicit Vector(size_type n):SimpleVector<data_type>(n),_alloc(true),_stride(1) {}
  // shallow copy constructors
  Vector(const Vector& vec)
    :SimpleVector<data_type>(vec.data(),vec.size()),_stride(vec.get_stride()) { if(this->data()==NULL) { assert(this->size()==0); _alloc=true; } else _alloc=false; }
  Vector(const data_type* _RESTRICT dp,size_type n,idx_type stride=1):SimpleVector<data_type>(dp,n),_alloc(false),_stride(stride) { /*assert(this->data());*/ }
  template <size_type n>
  Vector(const MiniVector<data_type,n>& vec):SimpleVector<data_type>(vec.data(),vec.size()),_alloc(false),_stride(1) {}
  //Vector(const VectorRef<data_type>& vec):SimpleVector<data_type>(vec.data(),vec.size()),_alloc(false),_stride(1) { assert(this->data()); }
  // will be removed
  //template <size_type n>
  //explicit Vector(const TinyVector<data_type,n>& vec):SimpleVector<data_type>(vec.data(),n),_alloc(false),_stride(1) {}
  //explicit Vector(const BlitzVectorType& vec):SimpleVector<data_type>(vec.data(),vec.size()),_alloc(false),_stride(1) { assert(this->data()); }

// destructor
  ~Vector(void) { if(!_alloc) this->set_ptr(NULL); }

// non-virtual member functions
  idx_type  get_stride(void) const { return _stride; }
  bool      has_unit_stride(void) const { return (_stride==1); }

  void      resize(size_type n) { if(!_alloc) assert(n==this->size()); else SimpleVector<data_type>::resize(n); }
  void      resize_preserve(size_type n) { assert(_alloc); SimpleVector<data_type>::resize_preserve(n); }
  void      try_resize(size_type n);
  void      free(void) { assert(_alloc); SimpleVector<data_type>::free(); }
  void      clear(void) { assert(_alloc); SimpleVector<data_type>::clear(); }

  void      reference(const Vector& vec) { assert(this->size()==0 || _alloc==false); VectorRef<data_type>::copy_member_(vec); _stride=vec._stride; if(this->size()) _alloc=false; else _alloc=true; }

  Vector& operator=(const Vector& dr) { return copy_vec(*this,dr); }
  //template <typename VectorType>
  //Vector& operator=(const VectorType& dr) { return copy_vec(*this,dr); }
  template <typename data_type1>
  Vector& operator=(const SimpleVector<data_type1>& dr) { return this->copy_vec(*this,dr); }
  template <typename OprType,typename VectorType>
  Vector& operator=(const VectorExpr1<OprType,VectorType>& dr) { return this->copy_vec(*this,dr); }
  template <typename LeftType,typename OprType,typename RightType>
  Vector& operator=(const VectorExpr2<LeftType,OprType,RightType>& dr) { return this->copy_vec(*this,dr); }
  template <typename data_type1,size_type N>
  Vector& operator=(const MiniVector<data_type1,N>& dr) { return this->copy_vec(*this,dr); }
  template <typename data_type1>
  Vector& operator=(const SparseVector<data_type1>& dr) { return this->copy_sparse_vec(*this,dr); }

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

  data_type&       _RESTRICT operator()(idx_type idx) { this->valid_range(idx); return this->get_(idx*_stride); }
  const data_type& _RESTRICT operator()(idx_type idx) const { this->valid_range(idx); return this->get_(idx*_stride); }

  data_type&       _RESTRICT operator[](idx_type idx) { this->valid_range(idx); return this->get_(idx*_stride); }
  const data_type& _RESTRICT operator[](idx_type idx) const { this->valid_range(idx); return this->get_(idx*_stride); }

  data_type*       _RESTRICT end(void) { return this->data()+this->size()*_stride; }
  const data_type* _RESTRICT end(void) const { return this->data()+this->size()*_stride; }

  Vector       operator()(const Range& r) { return range_strd(*this,r.first(),r.last(this->size()-1),r.stride()); }
  const Vector operator()(const Range& r) const { return range_strd(*const_cast<ThisVectorType*>(this),r.first(),r.last(this->size()-1),r.stride()); }

  // will be removed
  //BlitzVectorType       get(void);
  //const BlitzVectorType get(void) const;
  //Vector& get(void) { return *this; }
  //const Vector& get(void) const { return *this; }
};




lsize_type release_memory(lsize_type nb);

template <typename data_type>
inline void Vector<data_type>::try_resize(size_type n) 
{ 
  try {
    resize(n);
  }
  catch ( std::bad_alloc &e ) {
    release_memory(0); 
    resize(n);
  }
}

template <typename data_type>
inline Vector<data_type> Vector<data_type>::range_strd(Vector<data_type>& vec,idx_type ibegin,
                                                       idx_type iend,idx_type strd)
{ 
  return Vector<data_type>(&vec(ibegin),iend-ibegin+1,vec._stride*strd); 
}

// range operator for MiniVector

template <typename data_type,size_type n>
inline Vector<data_type> MiniVector<data_type,n>::operator()(idx_type ibegin,idx_type iend)
{
  return Vector<data_type>(data()+ibegin,iend-ibegin+1,1); 
}

template <typename data_type,size_type n>
inline Vector<data_type> MiniVector<data_type,n>::operator()(idx_type ibegin,idx_type iend) const 
{
  return Vector<data_type>(data()+ibegin,iend-ibegin+1,1); 
}

template <typename data_type,size_type n>
inline Vector<data_type> MiniVector<data_type,n>::operator()(const Range& r)
{ 
  assert(r.stride()==1); 
  idx_type ibegin=r.first();
  idx_type iend=r.last(this->size()-1);
  return Vector<data_type>(data()+ibegin,iend-ibegin+1,1); 
}

template <typename data_type,size_type n>
inline Vector<data_type> MiniVector<data_type,n>::operator()(const Range& r) const
{ 
  assert(r.stride()==1); 
  idx_type ibegin=r.first();
  idx_type iend=r.last(this->size()-1);
  return Vector<data_type>(data()+ibegin,iend-ibegin+1,1); 
}

// will be removed
//template <typename data_type>
//typename Vector<data_type>::BlitzVectorType Vector<data_type>::get(void) 
//{ 
//  if(data()==NULL) return BlitzVectorType();
//  BlitzVectorType tvec(data(),size()*get_stride(),blitz::neverDeleteData); 
//  if(get_stride()==1)
//    return tvec;
//  return BlitzVectorType( tvec(Range(0,(size()-1)*get_stride(),get_stride())) );
//}

//template <typename data_type>
//const typename Vector<data_type>::BlitzVectorType Vector<data_type>::get(void) const
//{ 
//  if(data()==NULL) return BlitzVectorType();
//  BlitzVectorType tvec(const_cast<data_type*>(data()),size()*get_stride(),blitz::neverDeleteData); 
//  if(get_stride()==1)
//    return tvec;
//  return BlitzVectorType( tvec(Range(0,(size()-1)*get_stride(),get_stride())) );
//}

using blitz::firstIndex;
using blitz::pow2;
using blitz::pow3;
using blitz::pow4;
using blitz::pow5;
using blitz::pow6;
using blitz::pow7;
using blitz::pow8;

// typedefs for Vector class

typedef Vector<complex_type>  ComplexVector;
typedef Vector<real4_type>    FloatVector;
typedef Vector<real_type>     RealVector;
typedef Vector<idx_type>      IdxVector;

DEF_SHARED_PTR(ComplexVector)
DEF_SHARED_PTR(FloatVector)
DEF_SHARED_PTR(RealVector)
DEF_SHARED_PTR(IdxVector)


// global functions for Vector class

template <typename data_type>
inline ostream& operator<<(ostream& os,const Vector<data_type>& v) { return v.write(os); }

//! sort values of 'datvec' in ascending order, and the order is returned in 'idxvec'
//! 'datvec' not changed
//! 'datvec(idxvec(i))' has i'th element 
template <typename VectorType>
void get_sorted_index(const VectorType& datvec,IdxSVector& idxvec);

template <typename VectorType>
real_type get_nonzero_min(const VectorType& datvec);

} // namespace Mec

namespace BLAS {

template <typename data_type>
inline Mec::size_type get_stride(const Mec::Vector<data_type>& vec) 
{ 
  return vec.get_stride();
}

} // namespace BLAS

#include "MecVectorExpr.h"

#endif