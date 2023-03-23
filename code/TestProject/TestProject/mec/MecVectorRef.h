#ifndef __MEC_VECTOR_REF_H
#define __MEC_VECTOR_REF_H

#include <blitz/range.h>
#include <stdarg.h>
#include <iostream>
#include "MecCommaAssignment.h"
#include "MecArrayIterator.h"
#ifdef _LINUX
#include "boost/format/format_fwd.hpp"
using namespace std;
#endif
//#include "MecSparseVector.h"

using blitz::Range;

//#ifdef _USE_MKL
//extern "C" void* MKL_malloc(size_t size, int align); /* Allocate the aligned buffer */
//extern "C" void  MKL_free(void *ptr);  
//
//#define ALIGNED_MALLOC(sz) MKL_malloc(sz,16)
//#define ALIGNED_FREE(ptr)  MKL_free(ptr)
//#else
//#include <malloc.h>
//#include <exception>
//#define ALIGNED_MALLOC(sz) malloc(sz)
//#define ALIGNED_FREE(ptr)  free(ptr)
//#endif

#ifdef _DEBUG
#define _RESTRICT
#else
#ifdef _LINUX
#define _RESTRICT 
#else
#define _RESTRICT restrict
#endif
#endif

namespace Mec {

template <typename data_type>
class SparseVector; 

#define DEF_VEC_VEC_OPR(opr) \
template <typename VectorType> \
ThisVectorType& operator opr (const VectorType& vec) { \
  assert(this->size() <= vec.size()); \
  if(this->has_unit_stride() && vec.has_unit_stride()) { \
    iterator it1=this->begin(); \
    typename VectorType::const_iterator it2=vec.begin(); \
    size_type sz=this->size(); \
    for(idx_type i=0;i<sz;++i) it1[i] opr it2[i]; \
  } \
  else { \
    for(idx_type i=0;i<this->size();i++) this->operator()(i) opr vec(i); \
  } \
  return *this; \
} \
template <typename data_type> \
ThisVectorType& operator opr (const SparseVector<data_type>& vec) { \
  typename SparseVector<data_type>::const_iterator it=vec.begin(); \
  for(idx_type i=0;i<vec.physical_size();i++,it++) { this->get_(it->first) opr it->second; }\
  return *this; \
} /*\
__pragma(intel optimization_parameter target_arch=AVX) \
ThisVectorType& operator opr (const ThisVectorType& vec) { \
  assert(this->size() <= vec.size()); \
  if(this->has_unit_stride() && vec.has_unit_stride()) { \
    iterator it1=this->begin(); \
    typename ThisVectorType::const_iterator it2=vec.begin(); \
    size_type sz=this->size(); \
__pragma(omp simd aligned(it1,it2:_MEM_ALIGN_BND)) \
    for(idx_type i=0;i<sz;++i) it1[i] opr it2[i]; \
  } \
  else { \
    for(idx_type i=0;i<this->size();i++) this->operator()(i) opr vec(i); \
  } \
  return *this; \
} */  //(lkb1024-vec) 

#define DEF_VEC_SCAL_OPR(opr) \
ThisVectorType& operator opr (const data_type& val) { \
  iterator it1=this->begin(); \
  iterator iend=this->end(); \
  if(this->has_unit_stride()) { \
    for(;it1!=iend;IteratorFunc::advance(it1)) *it1 opr val; \
  } \
  else { \
    idx_type st1=this->get_stride(); \
    for(;it1!=iend;IteratorFunc::advance(it1,st1)) *it1 opr val; \
  } \
  return *this; \
} 

/*#define DEF_VEC_SCAL_OPR(opr) \
__pragma(intel optimization_parameter target_arch=AVX) \
ThisVectorType& operator opr (const data_type& val) { \
  if(this->has_unit_stride()) { \
    data_type* it1=this->begin(); \
    size_type sz=this->size(); \
__pragma(omp simd aligned(it1:_MEM_ALIGN_BND)) \
    for(idx_type i=0;i<sz;++i) it1[i] opr val; \
  } \
  else { \
    iterator it1=this->begin(); \
    iterator iend=this->end(); \
    idx_type st1=this->get_stride(); \
    for(;it1!=iend;IteratorFunc::advance(it1,st1)) *it1 opr val; \
  } \
  return *this; \
} */  //(lkb1024-vec) 

#define DEF_VEC_SET \
ThisVectorType& set(data_type da0,...) { \
  va_list ap; \
  iterator it1=begin(); \
  iterator iend=end(); \
  *it1 = da0; \
  va_start(ap,da0); \
  if(has_unit_stride()) { \
    for(++it1;it1!=iend;IteratorFunc::advance(it1)) *it1 = va_arg(ap,data_type); \
  } \
  else { \
    idx_type st1=get_stride(); \
    for(it1+=st1;it1!=iend;IteratorFunc::advance(it1,st1)) *it1 = va_arg(ap,data_type); \
  } \
  return *this; \
} \
ThisVectorType& set_val(const data_type& da0) { \
  iterator it1=begin(); \
  iterator iend=end(); \
  if(has_unit_stride()) { \
    for(;it1!=iend;IteratorFunc::advance(it1)) *it1 = da0; \
  } \
  else { \
    idx_type st1=get_stride(); \
    for(;it1!=iend;IteratorFunc::advance(it1,st1)) *it1 = da0; \
  } \
  return *this; \
}

#define DEF_VEC_COUNT \
size_type count(const data_type& val) const { \
  size_type cnt=0; \
  const_iterator it1=begin(); \
  const_iterator iend=end(); \
  if(has_unit_stride()) { \
    for(;it1!=iend;IteratorFunc::advance(it1)) if ( *it1 == val ) ++cnt; \
  } \
  else { \
    idx_type st1=get_stride(); \
    for(;it1!=iend;IteratorFunc::advance(it1,st1)) if ( *it1 == val ) ++cnt; \
  } \
  return cnt; \
}

#define DEF_VEC_WRITE \
ostream& write(ostream& os) const { \
  os<<this->size()<<" = [ "; \
  for(idx_type i=0;i<this->size();++i) os<<boost::format("%20.10E")%operator()(i)<<" "; \
  os<<"]"; \
  os<<"\n"; \
  return os; \
}

#define DEF_VEC_CMP \
bool operator==(const ThisVectorType& vec) const { \
  if( !(size()==vec.size()) ) return false; \
  if(has_unit_stride() && vec.has_unit_stride()) { \
    const_iterator it1=begin(); \
    ThisVectorType::const_iterator it2=vec.begin(); \
    size_type sz=size(); \
    for(idx_type i=0;i<sz;++i) if( !(it1[i]==it2[i]) ) return false; \
  } \
  else { \
    for(idx_type i=0;i<size();i++) if( ! (operator()(i) == vec(i) ) ) return false; \
  } \
  return true; \
}


#define DEF_VEC_REDUCE_MEM(opr,opr_mem) \
data_type opr(void) const { \
  const_iterator it1=begin(); \
  const_iterator iend=end(); \
  data_type val=*it1; \
  if(has_unit_stride()) { \
    for(++it1;it1!=iend;IteratorFunc::advance(it1)) val=opr_mem(val,*it1); \
  } \
  else { \
    idx_type st1=get_stride(); \
    for(it1+=st1;it1!=iend;IteratorFunc::advance(it1,st1)) val=opr_mem(val,*it1); \
  } \
  return val; \
}

#define DEF_VEC_REDUCE_ARG(opr,opr_mem,VectorType) \
inline typename VectorType::T_numtype opr(const VectorType& vec) { \
  typename VectorType::const_iterator it1=vec.begin(); \
  typename VectorType::const_iterator iend=vec.end(); \
  typename VectorType::T_numtype val=*it1; \
  if(vec.has_unit_stride()) { \
    for(++it1;it1!=iend;IteratorFunc::advance(it1)) val=opr_mem(val,*it1); \
  } \
  else { \
    for(idx_type i=1;i<vec.size();i++) val=opr_mem(val,vec(i)); \
  } \
  return val; \
}

template <typename data_type>
inline data_type __sum2(const data_type& a,const data_type& b) { return a+b; }

template <typename data_type>
inline data_type __pow2(const data_type& a) { return a*a; }

template <typename data_type>
inline data_type __pow3(const data_type& a) { return a*a*a; }

template <typename data_type>
inline data_type __pow4(const data_type& a) { return a*a*a*a; }

template <typename data_type>
class SimpleVector;

namespace VectorRange {
  enum { IBEGIN=0, IEND=-1 };
}

//! class for partial operation of SimpleVector
template <typename data_type>
class VectorRef {
public:
  typedef data_type               EntryType;
  typedef data_type               T_numtype;
  typedef VectorRef               VectorRefType;
  typedef SimpleVector<data_type> T_array;
  typedef data_type*              iterator;
  typedef const data_type*        const_iterator;
  typedef VectorRef<data_type>    VectorRangeType;

private:
  typedef VectorRef ThisVectorType;

  data_type* _RESTRICT _data;
  idx_type   _size;

  explicit VectorRef(data_type& data) {} // not allowed
  explicit VectorRef(const data_type& data) {} // not allowed

protected:
// non-virtual protected member functions
  void set_ptr(data_type* ptr) { _data=ptr; }
  void valid_range(idx_type idx) const { assert(idx>=0 && idx<_size); }
  data_type& get_(idx_type idx) {  return _data[idx]; }
  const data_type& get_(idx_type idx) const { return _data[idx]; }
  // only for SimpleVector
  void clear_(void);
  void resize_(size_type size);
  void resize_preserve_(size_type size);
  void copy_member_(const VectorRef& vec) { _data=vec._data; _size=vec._size; }

// static protected member functions
  // only for SimpleVector
  static data_type* alloc_data_(size_type size);

public:
  VectorRef(void):_data(NULL),_size(0) {}
//VectorRef(VectorRef<data_type>& sv);  // definition not needed : use default copy constructor
  VectorRef(const data_type* _RESTRICT data,idx_type ibegin,idx_type iend)
            :_data(const_cast<data_type*>(data)+ibegin),_size(iend-ibegin+1) {}
  VectorRef(const VectorRef<data_type>& sv,idx_type ibegin,idx_type iend)
            :_data(const_cast<data_type*>(sv.data())+ibegin),_size(iend-ibegin+1) {}
  VectorRef(const data_type* _RESTRICT data,size_type size)
            :_data(const_cast<data_type*>(data)),_size(size) {}
  template <typename VectorType>
  VectorRef(const VectorType& vec)
            :_data(const_cast<data_type*>(vec.data())),_size(vec.size()) {}

// destructor
  ~VectorRef(void) {}

  VectorRef& operator=(const VectorRef& dr) { return copy_vec(*this,dr); }
  template <typename VectorType>
  VectorRef& operator=(const VectorType& dr) { return copy_vec(*this,dr); }
  
  DEF_VEC_COMMA_ASSIGNMENT

  //DEF_VEC_VEC_OPR(=)
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
  DEF_VEC_REDUCE_MEM(max,std::max)
  DEF_VEC_REDUCE_MEM(min,std::min)
  DEF_VEC_REDUCE_MEM(sum,__sum2)

  //VectorRef& set(data_type da0,...);
  //data_type  max(void) const;
  //data_type  min(void) const;
  //size_type  count(const data_type& val) const;
  //ostream&   write(ostream& os) const;
  //bool       operator==(const VectorRef& dr) const;

  idx_type get_stride(void) const { return 1; }
  bool     has_unit_stride(void) const { return true; }

  bool      operator!=(const VectorRef& dr) { return !(operator==(dr)); }

  data_type*       _RESTRICT data(void) { return _data; }
  const data_type* _RESTRICT data(void) const { return _data; }

  data_type&       _RESTRICT operator()(idx_type idx) { valid_range(idx); return get_(idx); }
  const data_type& _RESTRICT operator()(idx_type idx) const { valid_range(idx); return get_(idx); }

  data_type&       _RESTRICT operator[](idx_type idx) { valid_range(idx); return get_(idx); }
  const data_type& _RESTRICT operator[](idx_type idx) const { valid_range(idx); return get_(idx); }

  size_type        size(void) const { return _size; }
  size_type        physical_size(void) const { return _size; }
  size_type        rows(void) const { return size(); }
  size_type        columns(void) const { return 1; }
  
  data_type*       _RESTRICT begin(void) { return _data;  }
  const data_type* _RESTRICT begin(void) const { return _data;  }
  data_type*       _RESTRICT end(void) { return _data+_size; }
  const data_type* _RESTRICT end(void) const { return _data+_size; }

  VectorRef<data_type> operator()(idx_type ibegin,idx_type iend) { return range(*this,ibegin,iend); }
  VectorRef<data_type> operator()(idx_type ibegin,idx_type iend) const { return range(*const_cast<ThisVectorType*>(this),ibegin,iend); }

  VectorRef<data_type> operator()(const Range& r) { assert(r.stride()==1); return range(*this,r.first(),r.last(size()-1)); }
  VectorRef<data_type> operator()(const Range& r) const { assert(r.stride()==1); return range(*const_cast<ThisVectorType*>(this),r.first(),r.last(size()-1)); }
 
  void resize(size_type sz) { assert(size()==sz); }

// static member functions
  template <typename VectorType>
  static typename VectorType::VectorRefType range(VectorType& vec,idx_type ibegin=0,idx_type iend=VectorRange::IEND);
  template <typename VectorType1,typename VectorType2>
  static VectorType1& copy_vec(VectorType1& dest,const VectorType2& src);
  template <typename VectorType>
  static VectorType& copy_sparse_vec(VectorType& dest,const SparseVector<data_type>& src);
  static void         free_data_(data_type** ptr);
};

template <typename data_type>
inline ostream& operator<<(ostream& os,const VectorRef<data_type>& vr) { return vr.write(os); }

template <typename data_type>
template <typename VectorType1,typename VectorType2>
inline VectorType1& VectorRef<data_type>::copy_vec(VectorType1& dest,const VectorType2& src)
{ 
  dest.resize(src.size()); 
  if(dest.has_unit_stride() && src.has_unit_stride()) {
    typename VectorType1::iterator it1=dest.begin();
    typename VectorType2::const_iterator it2=src.begin();
    size_type sz=dest.size();
    for(idx_type i=0;i<sz;++i) it1[i] = it2[i];
    //memcpy(it1,it2,sizeof(VectorType1::T_numtype)*sz);  //(lkb1024-vec)
  }
  else {
    for(idx_type i=0;i<src.size();i++) dest(i) = src(i);
  }
  return dest; 
}

template <typename data_type>
template <typename VectorType>
inline VectorType& VectorRef<data_type>::copy_sparse_vec(VectorType& dest,const SparseVector<data_type>& src)
{ 
  dest.resize(src.size()); 
  dest = data_type(0.0);
  typename SparseVector<data_type>::const_iterator it = src.begin();
  for(idx_type i=0; i<src.physical_size();i++,it++) dest(it->first) = it->second;
  return dest; 
}


template <typename data_type>
template <typename VectorType>
inline typename VectorType::VectorRefType VectorRef<data_type>::range(VectorType& vec,idx_type ibegin,idx_type iend)
{ 
  if(iend==VectorRange::IEND) iend=vec.size()-1;
  assert(ibegin>=0 && iend<vec.size()); 
  return VectorType::VectorRefType(vec,ibegin,iend);
}

/*
//! class for strided access of vector elements
template <typename data_type>
class RVectorRef : public VectorRef<data_type> {
private:
  typedef RVectorRef ThisVectorType;
  typedef RVectorRef VectorRefType;

  idx_type _stride;

  explicit RVectorRef(data_type& data) {} // not allowed
  explicit RVectorRef(const data_type& data) {} // not allowed

// static protected member functions
  static RVectorRef range_strd(RVectorRef& vec,idx_type ibegin,idx_type iend,idx_type strd);

public:
  RVectorRef(void):VectorRef(),_stride(1) {}
  RVectorRef(const data_type* data,size_type size,idx_type stride=1)
                :VectorRef(data,size),_stride(stride) {}
  RVectorRef(const RVectorRef<data_type>& sv,idx_type ibegin,idx_type iend)
                :VectorRef(&sv(ibegin),iend-ibegin+1),_stride(sv._stride)  {}
  template <typename VectorType>
  RVectorRef(const VectorType& vec);

  RVectorRef& operator=(const RVectorRef& dr) { return copy_vec(*this,dr); }
  template <typename VectorType>
  RVectorRef& operator=(const VectorType& dr) { return copy_vec(*this,dr); }
  
  //DEF_VEC_COMMA_ASSIGNMENT

  DEF_VEC_VEC_OPR(+=)
  DEF_VEC_VEC_OPR(-=)
  DEF_VEC_VEC_OPR(*=)
  DEF_VEC_VEC_OPR(/=)

  DEF_VEC_SCAL_OPR(=)
  DEF_VEC_SCAL_OPR(+=)
  DEF_VEC_SCAL_OPR(-=)
  DEF_VEC_SCAL_OPR(*=)
  DEF_VEC_SCAL_OPR(/=)

  DEF_VEC_SET
  DEF_VEC_REDUCE(max)
  DEF_VEC_REDUCE(min)
  DEF_VEC_COUNT
  DEF_VEC_WRITE
  DEF_VEC_CMP

  idx_type         get_stride(void) const { return _stride; }

  data_type&       operator()(idx_type idx) { valid_range(idx); return get_(idx*_stride); }
  const data_type& operator()(idx_type idx) const { valid_range(idx); return get_(idx*_stride); }

  data_type&       operator[](idx_type idx) { valid_range(idx); return get_(idx*_stride); }
  const data_type& operator[](idx_type idx) const { valid_range(idx); return get_(idx*_stride); }

  data_type*       end(void) { return data()+size()*_stride; }
  const data_type* end(void) const { return data()+size()*_stride; }

  RVectorRef<data_type> operator()(idx_type ibegin,idx_type iend) { return range(*this,ibegin,iend); }
  RVectorRef<data_type> operator()(idx_type ibegin,idx_type iend) const { return range(*const_cast<ThisVectorType*>(this),ibegin,iend); }

  RVectorRef<data_type> operator()(const Range& r) { return range_strd(*this,r.first(),r.last(size()-1),r.stride()); }
  RVectorRef<data_type> operator()(const Range& r) const { return range_strd(*const_cast<ThisVectorType*>(this),r.first(),r.last(size()-1),r.stride()); }
};

template <typename data_type>
inline RVectorRef<data_type> RVectorRef<data_type>::range_strd(RVectorRef<data_type>& vec,
                                                          idx_type ibegin,idx_type iend,idx_type strd)
{ 
  return RVectorRef<data_type>(&vec(ibegin),iend-ibegin+1,vec._stride*strd); 
}
*/

typedef VectorRef<real_type>     RealVectorRef;
typedef VectorRef<idx_type>      IdxVectorRef;
typedef VectorRef<tag_type>      TagVectorRef;

//typedef RVectorRef<real_type> RealRVectorRef;
//typedef RVectorRef<idx_type>  IdxRVectorRef;
//typedef RVectorRef<tag_type>  TagRVectorRef;

}	// namespace Mec

namespace BLAS {

template <typename data_type>
inline Mec::size_type get_stride(const Mec::VectorRef<data_type>& vec) 
{ 
  return 1;
}

} // namespace BLAS

#endif