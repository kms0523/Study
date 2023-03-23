#ifndef __MEC_VECTOR_EXPR_H
#define __MEC_VECTOR_EXPR_H

#include <math.h>
#include "MecArrayIterator.h"

namespace Mec {

template <typename OprType,typename VectorType>
class VectorExpr1 {
private:
  const VectorType& _vec;

  template <typename VectorType>
  VectorExpr1(const VectorType& vec);

public:
  typedef typename OprType::T_numtype T_numtype;
  typedef typename ::Mec::Array1Iterator<OprType,VectorType> iterator;
  typedef typename ::Mec::Array1Iterator<OprType,VectorType> const_iterator;

  VectorExpr1(const VectorType& vec):_vec(vec) {}
  T_numtype _RESTRICT operator[](idx_type i) const { return OprType::compute(IteratorFunc::get_value(_vec,i)); }
  T_numtype _RESTRICT operator()(idx_type i) const { return OprType::compute(IteratorFunc::get_value(_vec,i)); }
  size_type size(void) const { return _vec.size(); }

  bool           has_unit_stride(void) const { return IteratorFunc::has_unit_stride(_vec); }
  const_iterator begin(void) const { return const_iterator(_vec.begin()); }
  const_iterator end(void) const { return const_iterator(_vec.end()); }
};

template <typename LeftType,typename OprType,typename RightType>
class VectorExpr2 {
private:
  const LeftType&  _left;
  const RightType& _right;

  template <typename VectorType>
  VectorExpr2(const VectorType& vec);

public:
  typedef typename ArrayResultType<LeftType,RightType>::T_numtype T_numtype;
  typedef typename ::Mec::Array2Iterator<LeftType,OprType,RightType> iterator;
  typedef typename ::Mec::Array2Iterator<LeftType,OprType,RightType> const_iterator;

  VectorExpr2(const LeftType& left,const RightType& right):_left(left),_right(right) {}
  T_numtype _RESTRICT operator[](idx_type i) const { return OprType::compute(IteratorFunc::get_value(_left,i),IteratorFunc::get_value(_right,i)); }
  T_numtype _RESTRICT operator()(idx_type i) const { return OprType::compute(IteratorFunc::get_value(_left,i),IteratorFunc::get_value(_right,i)); }
  size_type size(void) const { return ArrayResultType<LeftType,RightType>::size(_left,_right); }

  bool           has_unit_stride(void) const { return IteratorFunc::has_unit_stride(_left) && IteratorFunc::has_unit_stride(_right); }
  const_iterator begin(void) const { return const_iterator(IteratorFunc::begin(_left),IteratorFunc::begin(_right)); }
  const_iterator end(void) const { return const_iterator(IteratorFunc::end(_left),IteratorFunc::end(_right)); }
};

template <typename data_type,size_type n>
class MiniVector;

#define DEF_VEC_EXPR1(OprName,opr) \
template <typename data_type> \
struct OprName { \
  typedef data_type T_numtype; \
  static T_numtype compute(const data_type& a) { return opr a; } \
}; \
template <typename data_type> \
inline VectorExpr1< OprName<data_type>,Vector<data_type> > operator opr (const Vector<data_type>& a) \
{ return VectorExpr1< OprName<data_type>,Vector<data_type> >(a); } \
template <typename data_type,size_type n> \
inline VectorExpr1< OprName<data_type>,MiniVector<data_type,n> > operator opr (const MiniVector<data_type,n>& a) \
{ return VectorExpr1< OprName<data_type>,MiniVector<data_type,n> >(a); }\
template <typename OprType,typename RightType> \
inline VectorExpr1< OprName<typename VectorExpr1<OprType,RightType>::T_numtype>,VectorExpr1<OprType,RightType> > operator opr (const VectorExpr1<OprType,RightType>& a) \
{ return VectorExpr1< OprName<typename VectorExpr1<OprType,RightType>::T_numtype>,VectorExpr1<OprType,RightType> >(a); } \
template <typename LeftType,typename OprType,typename RightType> \
inline VectorExpr1< OprName<typename VectorExpr2<LeftType,OprType,RightType>::T_numtype>,VectorExpr2<LeftType,OprType,RightType> > operator opr (const VectorExpr2<LeftType,OprType,RightType>& a) \
{ return VectorExpr1< OprName<typename VectorExpr2<LeftType,OprType,RightType>::T_numtype>,VectorExpr2<LeftType,OprType,RightType> >(a); } \

DEF_VEC_EXPR1(VecNeg,-)

#define DEF_VEC_FUNC1(FuncName,GlobFuncName) \
template <typename data_type> \
struct Vec ## FuncName { \
  typedef data_type T_numtype; \
  static T_numtype compute(const data_type& a) { return GlobFuncName(a); } \
}; \
template <typename data_type> \
inline VectorExpr1< Vec ## FuncName<data_type>,Vector<data_type> > FuncName(const Vector<data_type>& a) \
{ return VectorExpr1< Vec ## FuncName<data_type>,Vector<data_type> >(a); } \
template <typename data_type,size_type n> \
inline VectorExpr1< Vec ## FuncName<data_type>,MiniVector<data_type,n> > FuncName(const MiniVector<data_type,n>& a) \
{ return VectorExpr1< Vec ## FuncName<data_type>,MiniVector<data_type,n> >(a); } \
template <typename OprType,typename RightType> \
inline VectorExpr1< Vec ## FuncName<typename VectorExpr1<OprType,RightType>::T_numtype>,VectorExpr1<OprType,RightType> > FuncName(const VectorExpr1<OprType,RightType>& a) \
{ return VectorExpr1< Vec ## FuncName<typename VectorExpr1<OprType,RightType>::T_numtype>,VectorExpr1<OprType,RightType> >(a); } \
template <typename LeftType,typename OprType,typename RightType> \
inline VectorExpr1< Vec ## FuncName<typename VectorExpr2<LeftType,OprType,RightType>::T_numtype>,VectorExpr2<LeftType,OprType,RightType> > FuncName(const VectorExpr2<LeftType,OprType,RightType>& a) \
{ return VectorExpr1< Vec ## FuncName<typename VectorExpr2<LeftType,OprType,RightType>::T_numtype>,VectorExpr2<LeftType,OprType,RightType> >(a); } \

#define DEF_VEC_COND_IDX(__func,__init,__cond,__ret) \
template <typename VectorType> \
inline idx_type __func(const VectorType& vec) \
{ \
  typename __func ## _traits<typename VectorType::T_numtype>::result_type newval,val=__init; \
  idx_type i,idx=0; \
  for(i=1;i<vec.size();i++) if(__cond) { val=newval; idx=i; __ret } \
  return idx; \
} \

#define __MINI_VECTOR  MiniVector<data_type,n>
#define __VECTOR_EXPR1 VectorExpr1<OprType,RightType>
#define __VECTOR_EXPR2 VectorExpr2<LeftType,OprType,RightType>

#define __PREVENT_MACRO_SUBSTITUTION

#define DEF_VEC_REDUCE(opr,opr_mem) \
template <typename data_type> \
DEF_VEC_REDUCE_ARG(opr,opr_mem,Vector<data_type>) \
template <typename data_type,size_type n> \
DEF_VEC_REDUCE_ARG(opr,opr_mem,__MINI_VECTOR) \
template <typename OprType,typename RightType> \
DEF_VEC_REDUCE_ARG(opr,opr_mem,__VECTOR_EXPR1) \
template <typename LeftType,typename OprType,typename RightType> \
DEF_VEC_REDUCE_ARG(opr,opr_mem,__VECTOR_EXPR2) \

namespace VectorExpr {

template <typename VectorType1,typename VectorType2>
inline typename VectorType1::T_numtype dot(const VectorType1& vec1,const VectorType2& vec2) 
{
  assert(vec1.size()==3 && vec2.size()==3);
  return (vec1[0]*vec2[0]+vec1[1]*vec2[1]+vec1[2]*vec2[2]);
}

//template <typename VectorType>
//inline typename VectorType::T_numtype norm(const VectorType& vec) 
//{
//  assert(vec.size()==3);
//  return ::sqrt(vec[0]*vec[0]+vec[1]*vec[1]+vec[2]*vec[2]);
//}

template <typename VectorType1,typename VectorType2>
inline MiniVector<typename VectorType1::T_numtype,3> cross(const VectorType1& vec1,const VectorType2& vec2) 
{
  assert(vec1.size()==3 && vec2.size()==3);
  return MiniVector<typename VectorType1::T_numtype,3>(vec1[1]*vec2[2]-vec1[2]*vec2[1],
                       vec1[2]*vec2[0]-vec1[0]*vec2[2],vec1[0]*vec2[1]-vec1[1]*vec2[0]);
}

template <typename data_type>
struct max_index_traits { typedef data_type result_type; };
template <typename data_type>
struct min_index_traits { typedef data_type result_type; };
template <typename data_type>
struct max_abs_index_traits { typedef data_type result_type; };
template <typename data_type>
struct min_abs_index_traits { typedef data_type result_type; };
template <>
struct max_abs_index_traits<complex_type> { typedef real_type result_type; };
template <>
struct min_abs_index_traits<complex_type> { typedef real_type result_type; };

DEF_VEC_COND_IDX(max_index,vec[0],(newval=vec[i])>val, )
DEF_VEC_COND_IDX(min_index,vec[0],(newval=vec[i])<val, )
DEF_VEC_COND_IDX(max_abs_index,::fabs(vec[0]),(newval=::fabs(vec[i]))>val, )
DEF_VEC_COND_IDX(min_abs_index,::fabs(vec[0]),(newval=::fabs(vec[i]))<val, )

DEF_VEC_REDUCE(max __PREVENT_MACRO_SUBSTITUTION,std::max)
DEF_VEC_REDUCE(min __PREVENT_MACRO_SUBSTITUTION,std::min)
DEF_VEC_REDUCE(sum,__sum2)

DEF_VEC_FUNC1(sqrt,::sqrt)
DEF_VEC_FUNC1(sin,::sin)
DEF_VEC_FUNC1(cos,::cos)
DEF_VEC_FUNC1(pow2,__pow2)
DEF_VEC_FUNC1(pow3,__pow3)
DEF_VEC_FUNC1(pow4,__pow4)

DEF_VEC_FUNC1(fabs,::fabs)

template <>
struct Vecfabs<complex_type> {
  typedef real_type T_numtype;
  static T_numtype compute(const complex_type& a) { return std::abs(a); } 
}; 

template <typename VectorType>
inline typename VectorType::T_numtype max_abs(const VectorType& vec) { return max(fabs(vec)); }

template <typename VectorType>
inline typename VectorType::T_numtype min_abs(const VectorType& vec) { return min(fabs(vec)); }

template <typename VectorType1,typename VectorType2>
void vector_swap__(VectorType1& v1,VectorType2& v2)
{
  assert(v1.size()==v2.size());
  for(idx_type i=0;i<v1.size();i++) std::swap(v1(i),v2(i));
}

template <typename data_type,typename VectorType>
inline void swap(Vector<data_type>& v1,VectorType& v2) { vector_swap__(v1,v2); }

template <typename data_type,size_type n,typename VectorType>
inline void swap(MiniVector<data_type,n>& v1,VectorType& v2) { vector_swap__(v1,v2); }

template <typename data_type,typename VectorType>
inline void swap(SimpleVector<data_type>& v1,VectorType& v2) { vector_swap__(v1,v2); }

template <typename OprType,typename VectorType1,typename VectorType2>
inline void swap(VectorExpr1<OprType,VectorType1>& v1,VectorType2& v2) { vector_swap__(v1,v2); }

template <typename OprType,typename VectorType1,typename VectorType2,typename VectorType3>
inline void swap(VectorExpr2<OprType,VectorType1,VectorType2>& v1,VectorType3& v2) { vector_swap__(v1,v2); }

}

#define DEF_VEC_EXPR2_SCAL(OprName,opr,data_type) \
inline VectorExpr2< Vector<data_type>,OprName,data_type > operator opr (const Vector<data_type>& a,const data_type& b) \
{ return VectorExpr2< Vector<data_type>,OprName,data_type >(a,b); } \
template <size_type n> \
inline VectorExpr2< MiniVector<data_type,n>,OprName,data_type > operator opr (const MiniVector<data_type,n>& a,const data_type& b) \
{ return VectorExpr2< MiniVector<data_type,n>,OprName,data_type >(a,b); } \
template <typename OprType,typename RightType> \
inline VectorExpr2< VectorExpr1<OprType,RightType>,OprName,data_type > operator opr (const VectorExpr1<OprType,RightType>& a,const data_type& b) \
{ return VectorExpr2< VectorExpr1<OprType,RightType>,OprName,data_type >(a,b); } \
template <typename LeftType,typename OprType,typename RightType> \
inline VectorExpr2< VectorExpr2<LeftType,OprType,RightType>,OprName,data_type > operator opr (const VectorExpr2<LeftType,OprType,RightType>& a,const data_type& b) \
{ return VectorExpr2< VectorExpr2<LeftType,OprType,RightType>,OprName,data_type >(a,b); } \
inline VectorExpr2< data_type,OprName,Vector<data_type> > operator opr (const data_type& a,const Vector<data_type>& b) \
{ return VectorExpr2< data_type,OprName,Vector<data_type> >(a,b); } \
template <size_type n> \
inline VectorExpr2< data_type,OprName,MiniVector<data_type,n> > operator opr (const data_type& a,const MiniVector<data_type,n>& b) \
{ return VectorExpr2< data_type,OprName,MiniVector<data_type,n> >(a,b); } \
template <typename OprType,typename RightType> \
inline VectorExpr2< data_type,OprName,VectorExpr1<OprType,RightType> > operator opr (const data_type& a,const VectorExpr1<OprType,RightType>& b) \
{ return VectorExpr2< data_type,OprName,VectorExpr1<OprType,RightType> >(a,b); } \
template <typename LeftType,typename OprType,typename RightType> \
inline VectorExpr2< data_type,OprName,VectorExpr2<LeftType,OprType,RightType> > operator opr (const data_type& a,const VectorExpr2<LeftType,OprType,RightType>& b) \
{ return VectorExpr2< data_type,OprName,VectorExpr2<LeftType,OprType,RightType> >(a,b); } \

#define DEF_VEC_EXPR2(OprName,opr) \
struct OprName { \
  template <typename data_type1,typename data_type2> \
  static typename ScalarResultType<data_type1,data_type2>::T_numtype compute(const data_type1& a,const data_type2& b) { return a opr b; } \
}; \
template <typename VectorType,typename data_type> \
inline VectorExpr2< VectorType,OprName,Vector<data_type> > operator opr (const VectorType& a,const Vector<data_type>& b) \
{ return VectorExpr2< VectorType,OprName,Vector<data_type> >(a,b); } \
template <typename VectorType,typename data_type,size_type n> \
inline VectorExpr2< VectorType,OprName,MiniVector<data_type,n> > operator opr (const VectorType& a,const MiniVector<data_type,n>& b) \
{ return VectorExpr2< VectorType,OprName,MiniVector<data_type,n> >(a,b); } \
template <typename VectorType,typename OprType,typename RightType> \
inline VectorExpr2< VectorType,OprName,VectorExpr1<OprType,RightType> > operator opr (const VectorType& a,const VectorExpr1<OprType,RightType>& b) \
{ return VectorExpr2< VectorType,OprName,VectorExpr1<OprType,RightType> >(a,b); } \
template <typename VectorType,typename LeftType,typename OprType,typename RightType> \
inline VectorExpr2< VectorType,OprName,VectorExpr2<LeftType,OprType,RightType> > operator opr (const VectorType& a,const VectorExpr2<LeftType,OprType,RightType>& b) \
{ return VectorExpr2< VectorType,OprName,VectorExpr2<LeftType,OprType,RightType> >(a,b); } \
DEF_VEC_EXPR2_SCAL(OprName,opr,real_type) \
DEF_VEC_EXPR2_SCAL(OprName,opr,real4_type) \
DEF_VEC_EXPR2_SCAL(OprName,opr,idx_type) \

DEF_VEC_EXPR2(VecAdd,+)
DEF_VEC_EXPR2(VecSub,-)
DEF_VEC_EXPR2(VecMul,*)
DEF_VEC_EXPR2(VecDiv,/)

} // namespace Mec

#undef __MEMBER_TYPE

#endif