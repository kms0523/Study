#ifndef __MEC_COMMAASSIGNMENT_H
#define __MEC_COMMAASSIGNMENT_H

#include "MecGlobalTypedefs.h"

namespace Mec {

template <typename VectorType>
class CommaAssignment {
private:
  typedef typename VectorType::T_numtype data_type;

  VectorType* _pvec;
  idx_type    _ip;
  data_type   _val;

public:
  CommaAssignment(VectorType *pvec,idx_type ip,data_type val):_pvec(pvec),_ip(ip),_val(val) {}

  ~CommaAssignment(void) { 
    if(_pvec) for(idx_type i=_ip;i<_pvec->size();i++) (*_pvec)(i)=_val;
  }

/*#pragma intel optimization_parameter target_arch=AVX
  ~CommaAssignment(void) { 
    if(_pvec) {
      if(_pvec->has_unit_stride()) {
        VectorType::iterator it1=_pvec->begin();
        const size_type sz=_pvec->size();
#pragma omp simd aligned(it1:_MEM_ALIGN_BND)
        for(idx_type i=_ip;i<sz;i++) it1[i]=_val;
      }
      else {
        for(idx_type i=_ip;i<_pvec->size();i++) (*_pvec)(i)=_val;
      }
    }
  }*/ //(lkb1024-vec)

  operator data_type(void) { return _val; }

  CommaAssignment operator,(data_type val) {
    VectorType* pvec=_pvec;
    if(_ip<_pvec->size()) {
      (*_pvec)(_ip)=val;
      _pvec=NULL;
    }
    return CommaAssignment(pvec,_ip+1,val);
  }
};

template <typename MatrixType>
class CommaMatrixAssignment {
private:
  typedef typename MatrixType::T_numtype data_type;

  MatrixType* _pmat;
  idx_type    _ip;
  data_type   _val;

  void get_crd(idx_type& ir,idx_type& ic) { ir=_ip%_pmat->rows(); ic=_ip/_pmat->rows(); }

public:
  CommaMatrixAssignment(MatrixType *pmat,idx_type ip,data_type val):_pmat(pmat),_ip(ip),_val(val) {}

  ~CommaMatrixAssignment(void) { 
    if(_pmat && _ip<_pmat->size()) {
      idx_type i,j,ir,ic;
      get_crd(ir,ic);
      for(i=ir;i<_pmat->rows();i++) (*_pmat)(i,ic)=_val;
      for(j=ic+1;j<_pmat->columns();j++)
        for(i=0;i<_pmat->rows();i++)
          (*_pmat)(i,j)=_val;
    }
  }
/*
#pragma intel optimization_parameter target_arch=AVX
  ~CommaMatrixAssignment(void) { 
    if(_pmat && _ip<_pmat->size()) {
      if(_pmat->has_continuous_storage()) {
        MatrixType::iterator it1=_pmat->begin();
        const size_type sz=_pmat->size();
#pragma omp simd aligned(it1:_MEM_ALIGN_BND)
        for(idx_type i=_ip;i<sz;++i) it1[i] = _val;
      }
      else {
        idx_type i,j,ir,ic;
        get_crd(ir,ic);
        for(i=ir;i<_pmat->rows();i++) (*_pmat)(i,ic)=_val;
        for(j=ic+1;j<_pmat->columns();j++)
          for(i=0;i<_pmat->rows();i++)
            (*_pmat)(i,j)=_val;
      }
    }
  }*/  //(lkb1024-vec)

  operator data_type(void) { return _val; }

  CommaMatrixAssignment operator,(const data_type& val) {
    MatrixType* pmat=_pmat;
    if(_ip<_pmat->size()) {
      idx_type ir,ic;
      get_crd(ir,ic);
      (*_pmat)(ir,ic) = val;
      _pmat=NULL;
    }
    return CommaMatrixAssignment(pmat,_ip+1,val);
  }
};

//!< assignment using comma (ex> a = 1,2,3,4) 
//#define DEF_MAT_COMMA_ASSIGNMENT \
//CommaAssignment<data_type> operator=(const data_type& val) { \
//  assert(get_ld()==rows()); \
//  if(size()>0) *data()=val; \
//  return CommaAssignment<data_type>(data()+1,size()-1,val); \
//}
#define DEF_MAT_COMMA_ASSIGNMENT \
CommaMatrixAssignment<ThisType> operator=(const data_type& val) { \
  if(this->size()>0) *(this->data())=val; \
  return CommaMatrixAssignment<ThisType>(this,1,val); \
}

#define DEF_VEC_COMMA_ASSIGNMENT \
CommaAssignment<ThisVectorType> operator=(const data_type& val) { \
  if(this->size()>0) *(this->data())=val; \
  return CommaAssignment<ThisVectorType>(this,1,val); \
}

} // namespace Mec

#endif