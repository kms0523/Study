#ifndef __MEC_TINY_MATRIX_H
#define __MEC_TINY_MATRIX_H

#include "MecMatrixRef.h"
#include "MecVector.h"

namespace Mec {

template <typename data_type>
class DenseMatrix;

template <typename data_type,size_type max_rows,size_type max_cols>
class TinyMatrix : public MatrixDim {
private:

  typedef TinyMatrix              ThisType;
  typedef DenseMatrix<data_type>  MatrixRangeType;
  typedef Vector<data_type>       VectorRangeType;

  data_type _data[max_cols][max_rows];
  //size_type _nr,_nc;
  
  void assert_size(size_type nr,size_type nc) const { assert(nr>=0 && nr<=max_rows); assert(nc>=0 && nc<=max_cols); }

  //template <typename MatrixType>
  //TinyMatrix& copy(const MatrixType& mat);

public:
  typedef data_type  T_numtype;
  typedef DenseMatrix<data_type> T_array;
  typedef data_type*             iterator;
  typedef const data_type*       const_iterator;

// constructors
  //TinyMatrix(void):_nr(max_rows),_nc(max_cols) {}
  TinyMatrix(void):MatrixDim(max_rows,max_cols) {}
  //TinyMatrix(size_type nr,size_type nc):_nr(nr),_nc(nc) { assert_size(nr,nc); }
  TinyMatrix(size_type nr,size_type nc):MatrixDim(nr,nc) { assert_size(nr,nc); }

// non-virtual member functions
  //void resize(size_type nr,size_type nc) { assert_size(nr,nc); _nr=nr; _nc=nc; }
  //void free(void) { _nr=_nc=0; }
  void resize(size_type nr,size_type nc) { assert_size(nr,nc); set_dim(nr,nc); }
  void free(void) { set_dim(0,0); }

  //size_type size(void) const { return _nr*_nc; }
  //size_type rows(void) const { return _nr; }
  //size_type columns(void) const { return _nc; }
  size_type get_ld(void) const { return max_rows; }

  data_type&       _RESTRICT operator[](idx_type i) { idx_type ir=i%rows(),ic=i/rows(); return _data[ic][ir]; } 
  const data_type& _RESTRICT operator[](idx_type i) const { idx_type ir=i%rows(),ic=i/rows(); return _data[ic][ir]; }

  data_type&       _RESTRICT operator()(idx_type ir,idx_type ic) { assert_idx(ir,ic); return _data[ic][ir]; }
  const data_type& _RESTRICT operator()(idx_type ir,idx_type ic) const { assert_idx(ir,ic); return _data[ic][ir]; }

  DenseMatrix<data_type>       operator()(const Range& r_r,const Range& r_c);
  const DenseMatrix<data_type> operator()(const Range& r_r,const Range& r_c) const;
  Vector<data_type>            operator()(const Range& r_r,idx_type ic);
  const Vector<data_type>      operator()(const Range& r_r,idx_type ic) const;
  Vector<data_type>            operator()(idx_type ir,const Range& r_c);
  const Vector<data_type>      operator()(idx_type ir,const Range& r_c) const;

  //CommaAssignment<data_type> operator=(data_type val); //!< assignment using comma (ex> a = 1,2,3,4) 
  DEF_MAT_COMMA_ASSIGNMENT

  //TinyMatrix& operator=(const TinyMatrix& mat) { return copy(mat); }
  //template <typename MatrixType>
  //TinyMatrix& operator=(const MatrixType& mat) { return copy(mat); }
  TinyMatrix& operator=(const TinyMatrix& mat) { return copy_mat(*this,mat); }
  template <typename MatrixType>
  TinyMatrix& operator=(const MatrixType& mat) { return copy_mat(*this,mat); }

  //template <typename MatrixType>
  //TinyMatrix& copy_transpose(const MatrixType& mat) { return copy_transpose_mat(*this,mat); }

  data_type*       _RESTRICT data(void) { return &(_data[0][0]); }
  const data_type* _RESTRICT data(void) const { return &(_data[0][0]); }

// type conversion
  
  

  TransposeRef<data_type> transpose(void) const { return TransposeRef<data_type>(*this); }
  TransposeRef<data_type> transpose(idx_type i,idx_type j) const { return TransposeRef<data_type>(*this); }

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
  //  BlitzMatrixType tmat(data(),blitz::shape(get_ld(),columns()),blitz::neverDeleteData);
  //  if(rows()<get_ld())
  //    return tmat(Range(0,rows()-1),Range::all());
  //  return tmat;
  //}

  //const BlitzMatrixType get(void) const {
  //  BlitzMatrixType tmat(const_cast<data_type*>(data()),blitz::shape(get_ld(),columns()),blitz::neverDeleteData);
  //  if(rows()<get_ld())
  //    return tmat(Range(0,rows()-1),Range::all());
  //  return tmat;
  //}

  //DenseMatrix<data_type> get(void);
  //const DenseMatrix<data_type> get(void) const;

// static member functions
  static size_type get_max_rows(void) { return max_rows; }
  static size_type get_max_columns(void) { return max_columns; }

  bool has_continuous_storage(void) const { return (rows()==get_ld()); }
  bool has_unit_stride(void) const { return has_continuous_storage(); }
  bool transposed(void) const { return false; }
  bool not_transposed(void) const { return true; }

  iterator       _RESTRICT begin(void) { return _data[0]; }
  const_iterator _RESTRICT begin(void) const { return _data[0]; }
  iterator       _RESTRICT end(void) { return end(columns()-1); }
  const_iterator _RESTRICT end(void) const { return end(columns()-1); }
  iterator       _RESTRICT begin(idx_type i) { return _data[0]+i*get_ld(); }
  const_iterator _RESTRICT begin(idx_type i) const { return _data[0]+i*get_ld(); }
  iterator       _RESTRICT end(idx_type i) { return _data[0]+i*get_ld()+rows(); }
  const_iterator _RESTRICT end(idx_type i) const { return _data[0]+i*get_ld()+rows(); }

  static const size_type _rows = max_rows;
  static const size_type _columns = max_cols;
};



template <typename data_type,size_type max_rows,size_type max_cols>
inline Vector<data_type> TinyMatrix<data_type,max_rows,max_cols>::operator()(const Range& r_r,idx_type ic)
{
  assert(r_r.stride()==1); 
  idx_type ir=r_r.first();
  Vector<data_type> svr(&_data[ic][ir],r_r.last(rows()-1)-ir+1,1);
  return svr;
}

template <typename data_type,size_type max_rows,size_type max_cols>
inline const Vector<data_type> TinyMatrix<data_type,max_rows,max_cols>::operator()(const Range& r_r,idx_type ic) const
{
  assert(r_r.stride()==1); 
  idx_type ir=r_r.first();
  Vector<data_type> svr(&_data[ic][ir],r_r.last(rows()-1)-ir+1,1);
  return svr;
}

template <typename data_type,size_type max_rows,size_type max_cols>
inline Vector<data_type> TinyMatrix<data_type,max_rows,max_cols>::operator()(idx_type ir,const Range& r_c)
{
  assert(r_c.stride()==1); 
  idx_type ic=r_c.first();
  Vector<data_type> svc(&_data[ic][ir],r_c.last(columns()-1)-ic+1,get_ld());
  return svc;
}

template <typename data_type,size_type max_rows,size_type max_cols>
inline const Vector<data_type> TinyMatrix<data_type,max_rows,max_cols>::operator()(idx_type ir,const Range& r_c) const
{
  assert(r_c.stride()==1); 
  idx_type ic=r_c.first();
  Vector<data_type> svc(&_data[ic][ir],r_c.last(columns()-1)-ic+1,get_ld());
  return svc;
}



typedef TinyMatrix<real_type,2,2> Real2x2Matrix;
typedef TinyMatrix<real_type,3,3> Real3x3Matrix;
typedef TinyMatrix<real_type,4,4> Real4x4Matrix;
typedef TinyMatrix<real_type,5,5> Real5x5Matrix;
typedef TinyMatrix<real_type,6,6> Real6x6Matrix;
typedef TinyMatrix<real_type,7,7> Real7x7Matrix;

typedef TinyMatrix<complex_type,2,2> Complex2x2Matrix;
typedef TinyMatrix<complex_type,3,3> Complex3x3Matrix;
typedef TinyMatrix<complex_type,4,4> Complex4x4Matrix;
typedef TinyMatrix<complex_type,5,5> Complex5x5Matrix;
typedef TinyMatrix<complex_type,6,6> Complex6x6Matrix;
} // namespace Mec

namespace BLAS {

template <typename data_type,Mec::size_type nr,Mec::size_type nc>
inline Mec::size_type get_ld(const Mec::TinyMatrix<data_type,nr,nc>& mat)
{
  return mat.get_ld();
}

} // namespace BLAS

#endif