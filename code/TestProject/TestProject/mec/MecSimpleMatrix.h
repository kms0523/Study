#ifndef __MEC_SIMPLE_MATRIX_H
#define __MEC_SIMPLE_MATRIX_H

#include "MecMatrixRef.h"
// #include "tbb/scalable_allocator.h" //(lkb1024-vec)

namespace Mec {

template <typename data_type>
class SimpleMatrix : public MatrixRef<data_type> {
public:
  typedef data_type    EntryType;
  typedef data_type    T_numtype;
  typedef SimpleMatrix T_array;
  typedef data_type*             iterator;
  typedef const data_type*       const_iterator;
  typedef MatrixRef<data_type>   MatrixRangeType;
  typedef VectorRef<data_type>   VectorRangeType;
  typedef Vector<data_type>      VectorRangeType2;

private:
  typedef SimpleMatrix ThisType;

  MatrixRef<data_type>& set_ptr(data_type *dp) { assert(false); return *this; }
  template <typename MatrixType>
  MatrixRef<data_type>& set(MatrixType& mat) { assert(false); return *this; }

protected:
  SimpleMatrix(size_type nr,size_type nc,const data_type* _RESTRICT dp,size_type ld=0):MatrixRef<data_type>(nr,nc,dp,ld) {}

public:
  SimpleMatrix(void):MatrixRef<data_type>() {}
  SimpleMatrix(size_type nr,size_type nc):MatrixRef<data_type>(nr,nc,MatrixRef<data_type>::alloc_data_(nr,nc)) {}
  // copy constructor of SimpleMatrix should be defined explicitly 
  SimpleMatrix(const SimpleMatrix<data_type>& src):MatrixRef<data_type>() { copy_mat(*this,src); }
  //SimpleMatrix(const MatrixRef<data_type>& src):MatrixRef<data_type>() { copy_mat(*this,src); }

  ~SimpleMatrix(void) { clear(); }

  SimpleMatrix& operator=(const SimpleMatrix& mat) { return copy_mat(*this,mat); }
  template <typename MatrixType>
  SimpleMatrix& operator=(const MatrixType& mat) { return copy_mat(*this,mat); }

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

  void resize(size_type nr,size_type nc) { this->resize_(nr,nc); }
  void resize_preserve(size_type nr,size_type nc) { this->resize_preserve_(nr,nc); }
  void clear(void) { this->clear_(); } 
  void free(void) { this->clear_(); }
};

//// memory managers for SimpleMatrix defined in MatrixRef

template <typename data_type>
inline data_type* MatrixRef<data_type>::alloc_data_(size_type nr,size_type nc)
{ 
  lsize_type size=lsize_type(nr)*nc;
  if(size==0) return NULL; 
  return (new data_type[size]);
  //return (data_type*) scalable_aligned_malloc(size*sizeof(data_type),_MEM_ALIGN_BND); //(lkb1024-vec)
}

//template <>
//inline real_type* MatrixRef<real_type>::alloc_data_(size_type nr,size_type nc)
//{ 
//  lsize_type size=lsize_type(nr)*nc;
//  if(size==0) return NULL; 
//  real_type* ptr=(real_type*)ALIGNED_MALLOC(size*sizeof(real_type));
//  if(ptr==NULL) throw std::bad_alloc();
//  return ptr;
//}
//
//template <>
//inline idx_type* MatrixRef<idx_type>::alloc_data_(size_type nr,size_type nc)
//{ 
//  lsize_type size=lsize_type(nr)*nc;
//  if(size==0) return NULL; 
//  idx_type* ptr=(idx_type*)ALIGNED_MALLOC(size*sizeof(idx_type));
//  if(ptr==NULL) throw std::bad_alloc();
//  return ptr;
//}

//template <typename data_type>
//inline void MatrixRef<data_type>::free_data_(data_type** ptr)
//{
//  if(*ptr) {
//    delete[] *ptr;
//    *ptr=NULL;
//  }
//}

//template <>
//inline void MatrixRef<real_type>::free_data_(real_type* ptr)
//{
//  if(ptr) ALIGNED_FREE(ptr);
//}
//
//template <>
//inline void MatrixRef<idx_type>::free_data_(idx_type* ptr)
//{
//  if(ptr) ALIGNED_FREE(ptr);
//}

template <typename data_type>
inline void MatrixRef<data_type>::clear_(void)
{
  VectorRef<data_type>::free_data_(&_dp);
  set_dim(0,0);
  _ld=0;
}

template <typename data_type>
inline void MatrixRef<data_type>::resize_(size_type nr,size_type nc)
{
  if(!this->equal_shape(nr,nc)) {
    VectorRef<data_type>::free_data_(&_dp);
    _dp=this->alloc_data_(nr,nc);
    set_dim(nr,nc);
    _ld=nr;
  }
}

template <typename data_type>
inline void MatrixRef<data_type>::resize_preserve_(size_type nr,size_type nc)
{
  if(!this->equal_shape(nr,nc)) {
    MatrixRef<data_type> mold(*this);
    _dp=this->alloc_data_(nr,nc);
    size_type nr0=std::min(nr,rows());
    size_type nc0=std::min(nc,columns());
    set_dim(nr,nc);
    _ld=nr;
    idx_type i,j;
    for(i=0;i<nc0;i++) for(j=0;j<nr0;j++) operator()(j,i) = mold(j,i);
    mold.clear_();
  }
}

//typedef SimpleMatrix<idx_type> IdxSMatrix;
//typedef SimpleMatrix<tag_type> TagSMatrix;
typedef SimpleMatrix<real_type> RealSMatrix;
typedef SimpleMatrix<idx_type>  IdxSMatrix;
typedef SimpleMatrix<tag_type>  TagSMatrix;

DEF_SHARED_PTR(RealSMatrix)
DEF_SHARED_PTR(IdxSMatrix)

}	// namespace Mec

#endif
