#ifndef __MEC_MATRIX_EXPR_H
#define __MEC_MATRIX_EXPR_H

#include "MecArrayIterator.h"

namespace Mec {

template <typename OprType,typename MatrixType>
class MatrixExpr1 {
private:
  const MatrixType& _mat;

  template <typename MatrixType>
  MatrixExpr1(const MatrixType& mat);

public:
  typedef typename MatrixType::T_numtype T_numtype;
  typedef typename ::Mec::Array1Iterator<OprType,MatrixType> iterator;
  typedef typename ::Mec::Array1Iterator<OprType,MatrixType> const_iterator;

  MatrixExpr1(const MatrixType& mat):_mat(mat) {}
  T_numtype _RESTRICT operator()(idx_type i,idx_type j) const { return OprType::compute(_mat(i,j)); }
  size_type rows(void) const { return _mat.rows(); }
  size_type columns(void) const { return _mat.columns(); }
  // interface for vector expressions
  T_numtype _RESTRICT operator[](idx_type i) const { idx_type ir=i%rows(),ic=i/rows(); return operator()(ir,ic); }
  size_type size(void) const { return rows()*columns(); }

  bool has_continuous_storage(void) const { return _mat.has_continuous_storage(); }
  bool has_unit_stride(void) const { return _mat.has_unit_stride(); }
  bool transposed(void) const { return _mat.transposed(); }
  bool not_transposed(void) const { return _mat.not_transposed(); }

  const_iterator begin(void) const { return const_iterator(_mat.begin()); }
  const_iterator end(void) const { return const_iterator(_mat.end()); }
  const_iterator begin(idx_type i) const { return const_iterator(_mat.begin(i)); }
  const_iterator end(idx_type i) const { return const_iterator(_mat.end(i)); }
};

template <typename LeftType,typename RightType>
struct MatrixResultType {
  typedef typename ScalarResultType<typename LeftType::T_numtype,typename RightType::T_numtype>::T_numtype T_numtype;
  static size_type rows(const LeftType& left,const RightType& right) { assert(left.rows()==right.rows()); return right.rows(); }
  static size_type columns(const LeftType& left,const RightType& right) { assert(left.columns()==right.columns()); return right.columns(); }
};

#define DEF_MAT_RES_TYPE(data_type) \
template <typename RightType> \
struct MatrixResultType<data_type,RightType> { \
  typedef typename ScalarResultType<data_type,typename RightType::T_numtype>::T_numtype T_numtype; \
  static size_type rows(const data_type& left,const RightType& right) { return right.rows(); } \
  static size_type columns(const data_type& left,const RightType& right) { return right.columns(); } \
}; \
template <typename LeftType> \
struct MatrixResultType<LeftType,data_type> { \
  typedef typename ScalarResultType<typename LeftType::T_numtype,data_type>::T_numtype T_numtype; \
  static size_type rows(const LeftType& left,const data_type& right) { return left.rows(); } \
  static size_type columns(const LeftType& left,const data_type& right) { return left.columns(); } \
}; \

DEF_MAT_RES_TYPE(real_type)
DEF_MAT_RES_TYPE(real4_type)
DEF_MAT_RES_TYPE(idx_type)

template <typename LeftType,typename OprType,typename RightType>
class MatrixExpr2 {
private:
  const LeftType&  _left;
  const RightType& _right;

  template <typename MatrixType>
  MatrixExpr2(const MatrixType& mat);

public:
  typedef typename MatrixResultType<LeftType,RightType>::T_numtype T_numtype;
  typedef typename ::Mec::Array2Iterator<LeftType,OprType,RightType> iterator;
  typedef typename ::Mec::Array2Iterator<LeftType,OprType,RightType> const_iterator;

  MatrixExpr2(const LeftType& left,const RightType& right):_left(left),_right(right) {}
  T_numtype _RESTRICT operator()(idx_type i,idx_type j) const { return OprType::compute2(_left,_right,i,j); }
  size_type rows(void) const { return MatrixResultType<LeftType,RightType>::rows(_left,_right); }
  size_type columns(void) const { return MatrixResultType<LeftType,RightType>::columns(_left,_right); }
  // interface for vector expressions
  T_numtype _RESTRICT operator[](idx_type i) const { idx_type ir=i%rows(),ic=i/rows(); return operator()(ir,ic); }
  size_type size(void) const { return rows()*columns(); }

  bool has_continuous_storage(void) const { return IteratorFunc::has_continuous_storage(_left) && IteratorFunc::has_continuous_storage(_right); }
  bool has_unit_stride(void) const { return IteratorFunc::has_unit_stride(_left) && IteratorFunc::has_unit_stride(_right); }
  bool transposed(void) const { return IteratorFunc::transposed(_left) && IteratorFunc::transposed(_right); }
  bool not_transposed(void) const { return IteratorFunc::not_transposed(_left) && IteratorFunc::not_transposed(_right); }

  const_iterator begin(void) const { return const_iterator(IteratorFunc::begin(_left),IteratorFunc::begin(_right)); }
  const_iterator end(void) const { return const_iterator(IteratorFunc::end(_left),IteratorFunc::end(_right)); }
  const_iterator begin(idx_type i) const { return const_iterator(IteratorFunc::begin(_left,i),IteratorFunc::begin(_right,i)); }
  const_iterator end(idx_type i) const { return const_iterator(IteratorFunc::end(_left,i),IteratorFunc::end(_right,i)); }
};

#define DEF_MAT_EXPR1(OprName,opr) \
struct OprName { \
  template <typename data_type> \
  static data_type compute(const data_type& a) { return opr a; } \
}; \
template <typename data_type> \
inline MatrixExpr1< OprName,DenseMatrix<data_type> > operator opr (const DenseMatrix<data_type>& a) \
{ return MatrixExpr1< OprName,DenseMatrix<data_type> >(a); } \
template <typename data_type> \
inline MatrixExpr1< OprName,TransposeRef<data_type> > operator opr (const TransposeRef<data_type>& a) \
{ return MatrixExpr1< OprName,TransposeRef<data_type> >(a); } \
template <typename data_type,size_type nr,size_type nc> \
inline MatrixExpr1< OprName,TinyMatrix<data_type,nr,nc> > operator opr (const TinyMatrix<data_type,nr,nc>& a) \
{ return MatrixExpr1< OprName,TinyMatrix<data_type,nr,nc> >(a); } \
template <typename OprType,typename RightType> \
inline MatrixExpr1< OprName,MatrixExpr1<OprType,RightType> > operator opr (const MatrixExpr1<OprType,RightType>& a) \
{ return MatrixExpr1< OprName,MatrixExpr1<OprType,RightType> >(a); } \
template <typename LeftType,typename OprType,typename RightType> \
inline MatrixExpr1< OprName,MatrixExpr2<LeftType,OprType,RightType> > operator opr (const MatrixExpr2<LeftType,OprType,RightType>& a) \
{ return MatrixExpr1< OprName,MatrixExpr2<LeftType,OprType,RightType> >(a); } \

DEF_MAT_EXPR1(MatNeg,-)

#define DEF_MAT_FUNC1(FuncName,GlobFuncName) \
struct Mat ## FuncName { \
  template <typename data_type> \
  static data_type compute(const data_type& a) { return GlobFuncName(a); } \
}; \
template <typename data_type> \
inline MatrixExpr1< Mat ## FuncName,DenseMatrix<data_type> > FuncName(const DenseMatrix<data_type>& a) \
{ return MatrixExpr1< Mat ## FuncName,DenseMatrix<data_type> >(a); } \
template <typename data_type> \
inline MatrixExpr1< Mat ## FuncName,TransposeRef<data_type> > FuncName(const TransposeRef<data_type>& a) \
{ return MatrixExpr1< Mat ## FuncName,TransposeRef<data_type> >(a); } \
template <typename data_type,size_type nr,size_type nc> \
inline MatrixExpr1< Mat ## FuncName,TinyMatrix<data_type,nr,nc> > FuncName(const TinyMatrix<data_type,nr,nc>& a) \
{ return MatrixExpr1< Mat ## FuncName,TinyMatrix<data_type,nr,nc> >(a); } \
template <typename OprType,typename RightType> \
inline MatrixExpr1< Mat ## FuncName,MatrixExpr1<OprType,RightType> > FuncName(const MatrixExpr1<OprType,RightType>& a) \
{ return MatrixExpr1< Mat ## FuncName,MatrixExpr1<OprType,RightType> >(a); } \
template <typename LeftType,typename OprType,typename RightType> \
inline MatrixExpr1< Mat ## FuncName,MatrixExpr2<LeftType,OprType,RightType> > FuncName(const MatrixExpr2<LeftType,OprType,RightType>& a) \
{ return MatrixExpr1< Mat ## FuncName,MatrixExpr2<LeftType,OprType,RightType> >(a); } \

#define __TINY_MATRIX  TinyMatrix<data_type,nr,nc>
#define __MATRIX_EXPR1 MatrixExpr1<OprType,RightType>
#define __MATRIX_EXPR2 MatrixExpr2<LeftType,OprType,RightType>

#define DEF_MAT_REDUCE(opr,opr_mem) \
template <typename data_type> \
DEF_MAT_REDUCE_ARG(opr,opr_mem,MatrixRef<data_type>,columns) \
template <typename data_type> \
DEF_MAT_REDUCE_ARG(opr,opr_mem,TransposeRef<data_type>,rows) \
template <typename data_type,size_type nr,size_type nc> \
DEF_MAT_REDUCE_ARG(opr,opr_mem,__TINY_MATRIX,columns) \
template <typename OprType,typename RightType> \
DEF_MAT_REDUCE_ARG(opr,opr_mem,__MATRIX_EXPR1,columns) \
template <typename LeftType,typename OprType,typename RightType> \
DEF_MAT_REDUCE_ARG(opr,opr_mem,__MATRIX_EXPR2,columns) \

namespace MatrixExpr {

DEF_MAT_REDUCE(max __PREVENT_MACRO_SUBSTITUTION,std::max)
DEF_MAT_REDUCE(min __PREVENT_MACRO_SUBSTITUTION,std::min)
DEF_MAT_REDUCE(sum,__sum2)

DEF_MAT_FUNC1(sqrt,::sqrt)
DEF_MAT_FUNC1(fabs,::fabs)
DEF_MAT_FUNC1(sin,::sin)
DEF_MAT_FUNC1(cos,::cos)
DEF_MAT_FUNC1(pow2,__pow2)
DEF_MAT_FUNC1(pow3,__pow3)
DEF_MAT_FUNC1(pow4,__pow4)

template <typename MatrixType>
inline typename MatrixType::T_numtype max_abs(const MatrixType& mat) { return max(fabs(mat)); }

template <typename MatrixType>
inline typename MatrixType::T_numtype min_abs(const MatrixType& mat) { return min(fabs(mat)); }

}

template <typename data_type,size_type nr,size_type nc>
class TinyMatrix;

#define DEF_MAT_EXPR2_SCAL(OprName,opr,data_type) \
inline MatrixExpr2< DenseMatrix<data_type>,OprName,data_type > operator opr (const DenseMatrix<data_type>& a,const data_type& b) \
{ return MatrixExpr2< DenseMatrix<data_type>,OprName,data_type >(a,b); } \
inline MatrixExpr2< TransposeRef<data_type>,OprName,data_type > operator opr (const TransposeRef<data_type>& a,const data_type& b) \
{ return MatrixExpr2< TransposeRef<data_type>,OprName,data_type >(a,b); } \
template <size_type nr,size_type nc> \
inline MatrixExpr2< TinyMatrix<data_type,nr,nc>,OprName,data_type > operator opr (const TinyMatrix<data_type,nr,nc>& a,const data_type& b) \
{ return MatrixExpr2< TinyMatrix<data_type,nr,nc>,OprName,data_type >(a,b); } \
template <typename OprType,typename RightType> \
inline MatrixExpr2< MatrixExpr1<OprType,RightType>,OprName,data_type > operator opr (const MatrixExpr1<OprType,RightType>& a,const data_type& b) \
{ return MatrixExpr2< MatrixExpr1<OprType,RightType>,OprName,data_type >(a,b); } \
template <typename LeftType,typename OprType,typename RightType> \
inline MatrixExpr2< MatrixExpr2<LeftType,OprType,RightType>,OprName,data_type > operator opr (const MatrixExpr2<LeftType,OprType,RightType>& a,const data_type& b) \
{ return MatrixExpr2< MatrixExpr2<LeftType,OprType,RightType>,OprName,data_type >(a,b); } \
inline MatrixExpr2< data_type,OprName,DenseMatrix<data_type> > operator opr (const data_type& a,const DenseMatrix<data_type>& b) \
{ return MatrixExpr2< data_type,OprName,DenseMatrix<data_type> >(a,b); } \
inline MatrixExpr2< data_type,OprName,TransposeRef<data_type> > operator opr (const data_type& a,const TransposeRef<data_type>& b) \
{ return MatrixExpr2< data_type,OprName,TransposeRef<data_type> >(a,b); } \
template <size_type nr,size_type nc> \
inline MatrixExpr2< data_type,OprName,TinyMatrix<data_type,nr,nc> > operator opr (const data_type& a,const TinyMatrix<data_type,nr,nc>& b) \
{ return MatrixExpr2< data_type,OprName,TinyMatrix<data_type,nr,nc> >(a,b); } \
template <typename OprType,typename RightType> \
inline MatrixExpr2< data_type,OprName,MatrixExpr1<OprType,RightType> > operator opr (const data_type& a,const MatrixExpr1<OprType,RightType>& b) \
{ return MatrixExpr2< data_type,OprName,MatrixExpr1<OprType,RightType> >(a,b); } \
template <typename LeftType,typename OprType,typename RightType> \
inline MatrixExpr2< data_type,OprName,MatrixExpr2<LeftType,OprType,RightType> > operator opr (const data_type& a,const MatrixExpr2<LeftType,OprType,RightType>& b) \
{ return MatrixExpr2< data_type,OprName,MatrixExpr2<LeftType,OprType,RightType> >(a,b); } \

#define DEF_MAT_EXPR2_COMPUTE_SCAL(opr,data_type) \
template <typename data_type1> \
static typename MatrixResultType<data_type,DenseMatrix<data_type1> >::T_numtype compute2(data_type a,const DenseMatrix<data_type1>& b,idx_type i,idx_type j) { return a opr b(i,j); } \
template <typename data_type1> \
static typename MatrixResultType<DenseMatrix<data_type1>,data_type>::T_numtype compute2(const DenseMatrix<data_type1>& a,data_type b,idx_type i,idx_type j) { return a(i,j) opr b; } \
template <typename data_type1> \
static typename MatrixResultType<data_type,TransposeRef<data_type1> >::T_numtype compute2(data_type a,const TransposeRef<data_type1>& b,idx_type i,idx_type j) { return a opr b(i,j); } \
template <typename data_type1> \
static typename MatrixResultType<TransposeRef<data_type1>,data_type>::T_numtype compute2(const TransposeRef<data_type1>& a,data_type b,idx_type i,idx_type j) { return a(i,j) opr b; } \
template <typename data_type1,size_type nr,size_type nc> \
static typename MatrixResultType<data_type,TinyMatrix<data_type1,nr,nc> >::T_numtype compute2(data_type a,const TinyMatrix<data_type1,nr,nc>& b,idx_type i,idx_type j) { return a opr b(i,j); } \
template <typename data_type1,size_type nr,size_type nc> \
static typename MatrixResultType<TinyMatrix<data_type1,nr,nc>,data_type>::T_numtype compute2(const TinyMatrix<data_type1,nr,nc>& a,data_type b,idx_type i,idx_type j) { return a(i,j) opr b; } \
template <typename OprType,typename RightType> \
static typename MatrixResultType<data_type,MatrixExpr1<OprType,RightType> >::T_numtype compute2(data_type a,const MatrixExpr1<OprType,RightType>& b,idx_type i,idx_type j) { return a opr b(i,j); } \
template <typename OprType,typename RightType> \
static typename MatrixResultType<MatrixExpr1<OprType,RightType>,data_type>::T_numtype compute2(const MatrixExpr1<OprType,RightType>& a,data_type b,idx_type i,idx_type j) { return a(i,j) opr b; } \
template <typename LeftType,typename OprType,typename RightType> \
static typename MatrixResultType<data_type,MatrixExpr2<LeftType,OprType,RightType> >::T_numtype compute2(data_type a,const MatrixExpr2<LeftType,OprType,RightType>& b,idx_type i,idx_type j) { return a opr b(i,j); } \
template <typename LeftType,typename OprType,typename RightType> \
static typename MatrixResultType<MatrixExpr2<LeftType,OprType,RightType>,data_type>::T_numtype compute2(const MatrixExpr2<LeftType,OprType,RightType>& a,data_type b,idx_type i,idx_type j) { return a(i,j) opr b; } \

#define DEF_MAT_EXPR2(OprName,opr) \
struct OprName { \
  template <typename data_type1,typename data_type2> \
  static typename ScalarResultType<data_type1,data_type2>::T_numtype compute(const data_type1& a,const data_type2& b) { return a opr b; } \
  template <typename MatrixType1,typename MatrixType2> \
  static typename MatrixResultType<MatrixType1,MatrixType2>::T_numtype compute2(const MatrixType1& a,const MatrixType2& b,idx_type i,idx_type j) { return a(i,j) opr b(i,j); } \
  DEF_MAT_EXPR2_COMPUTE_SCAL(opr,real_type) \
  DEF_MAT_EXPR2_COMPUTE_SCAL(opr,real4_type) \
  DEF_MAT_EXPR2_COMPUTE_SCAL(opr,idx_type) \
}; \
template <typename MatrixType,typename data_type> \
inline MatrixExpr2< MatrixType,OprName,DenseMatrix<data_type> > operator opr (const MatrixType& a,const DenseMatrix<data_type>& b) \
{ return MatrixExpr2< MatrixType,OprName,DenseMatrix<data_type> >(a,b); } \
template <typename MatrixType,typename data_type> \
inline MatrixExpr2< MatrixType,OprName,TransposeRef<data_type> > operator opr (const MatrixType& a,const TransposeRef<data_type>& b) \
{ return MatrixExpr2< MatrixType,OprName,TransposeRef<data_type> >(a,b); } \
template <typename MatrixType,typename data_type,size_type nr,size_type nc> \
inline MatrixExpr2< MatrixType,OprName,TinyMatrix<data_type,nr,nc> > operator opr (const MatrixType& a,const TinyMatrix<data_type,nr,nc>& b) \
{ return MatrixExpr2< MatrixType,OprName,TinyMatrix<data_type,nr,nc> >(a,b); } \
template <typename MatrixType,typename OprType,typename RightType> \
inline MatrixExpr2< MatrixType,OprName,MatrixExpr1<OprType,RightType> > operator opr (const MatrixType& a,const MatrixExpr1<OprType,RightType>& b) \
{ return MatrixExpr2< MatrixType,OprName,MatrixExpr1<OprType,RightType> >(a,b); } \
template <typename MatrixType,typename LeftType,typename OprType,typename RightType> \
inline MatrixExpr2< MatrixType,OprName,MatrixExpr2<LeftType,OprType,RightType> > operator opr (const MatrixType& a,const MatrixExpr2<LeftType,OprType,RightType>& b) \
{ return MatrixExpr2< MatrixType,OprName,MatrixExpr2<LeftType,OprType,RightType> >(a,b); } \
DEF_MAT_EXPR2_SCAL(OprName,opr,real_type) \
DEF_MAT_EXPR2_SCAL(OprName,opr,real4_type) \
DEF_MAT_EXPR2_SCAL(OprName,opr,idx_type) \

DEF_MAT_EXPR2(MatAdd,+)
DEF_MAT_EXPR2(MatSub,-)
DEF_MAT_EXPR2(MatMul,*)
DEF_MAT_EXPR2(MatDiv,/)

} // namespace Mec

#endif