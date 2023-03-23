#ifndef __MEC_ARRAY_ITERATOR_H
#define __MEC_ARRAY_ITERATOR_H

namespace Mec {

template <typename LeftType,typename RightType>
struct ScalarResultType { typedef LeftType T_numtype; };

template <>
struct ScalarResultType<idx_type,real_type> { typedef real_type T_numtype; };

template <>
struct ScalarResultType<idx_type,real4_type> { typedef real4_type T_numtype; };

template <>
struct ScalarResultType<real4_type,real_type> { typedef real_type T_numtype; };

template <typename LeftType,typename RightType>
struct ArrayResultType {
  typedef typename ScalarResultType<typename LeftType::T_numtype,typename RightType::T_numtype>::T_numtype T_numtype;
  static size_type size(const LeftType& left,const RightType& right) { assert(left.size()==right.size()); return right.size(); }
};

#define DEF_ARRAY_RES_TYPE(data_type) \
template <typename RightType> \
struct ArrayResultType<data_type,RightType> { \
  typedef typename ScalarResultType<data_type,typename RightType::T_numtype>::T_numtype T_numtype; \
  static size_type size(const data_type& left,const RightType& right) { return right.size(); } \
}; \
template <typename LeftType> \
struct ArrayResultType<LeftType,data_type> { \
  typedef typename ScalarResultType<typename LeftType::T_numtype,data_type>::T_numtype T_numtype; \
  static size_type size(const LeftType& left,const data_type& right) { return left.size(); } \
}; \

DEF_ARRAY_RES_TYPE(real_type)
DEF_ARRAY_RES_TYPE(real4_type)
DEF_ARRAY_RES_TYPE(idx_type)

template <typename data_type>
class ScalarIterator {
private:
  const data_type& _val;

public:
  typedef data_type T_numtype;

  ScalarIterator(const data_type& val):_val(val) {}

  T_numtype operator * (void) { return _val; }
  T_numtype operator [] (idx_type i) { return _val; }
  void operator ++ (void) {}
  void operator += (size_type str) {}
  void advance(void) {}
  void advance(idx_type str) {}

  bool operator == (const ScalarIterator& sit) { return true; }
  bool operator != (const ScalarIterator& sit) { return false; }
};

template <typename ArrayType>
struct IteratorTraits {
  typedef typename ArrayType::iterator iterator;
  typedef typename ArrayType::const_iterator const_iterator;  
};

#define DEF_SCALAR_ITERATOR_TYPE(data_type) \
template <> \
struct IteratorTraits<data_type> { \
  typedef ScalarIterator<data_type> iterator; \
  typedef ScalarIterator<data_type> const_iterator; \
};

DEF_SCALAR_ITERATOR_TYPE(real_type)
DEF_SCALAR_ITERATOR_TYPE(real4_type)
DEF_SCALAR_ITERATOR_TYPE(idx_type)

#define DEF_SCALAR_GET_VALUE(data_type) \
inline data_type get_value(data_type val,idx_type i) { return val; }

#define DEF_SCALAR_ITER_BEGIN(data_type) \
inline ScalarIterator<data_type> begin(const data_type& dat) { return ScalarIterator<data_type>(dat); } \
inline ScalarIterator<data_type> begin(const data_type& dat,idx_type i) { return ScalarIterator<data_type>(dat); }

#define DEF_SCALAR_ITER_END(data_type) \
inline ScalarIterator<data_type> end(const data_type& dat) { return ScalarIterator<data_type>(dat); } \
inline ScalarIterator<data_type> end(const data_type& dat,idx_type i) { return ScalarIterator<data_type>(dat); }

#define DEF_SCALAR_BOOL_FUNC(data_type) \
inline bool has_unit_stride(const data_type& dat) { return true; } \
inline bool has_continuous_storage(const data_type& dat) { return true; } \
inline bool transposed(const data_type& dat) { return true; } \
inline bool not_transposed(const data_type& dat) { return true; } \

namespace IteratorFunc {

template <typename VectorType>
inline typename VectorType::T_numtype get_value(const VectorType& vec,idx_type i) { return vec(i); }

DEF_SCALAR_GET_VALUE(real_type)
DEF_SCALAR_GET_VALUE(real4_type)
DEF_SCALAR_GET_VALUE(idx_type)

template <typename VectorType>
inline typename VectorType::const_iterator begin(const VectorType& vec) { return vec.begin(); }

template <typename VectorType>
inline typename VectorType::const_iterator begin(const VectorType& vec,idx_type i) { return vec.begin(i); }

DEF_SCALAR_ITER_BEGIN(real_type)
DEF_SCALAR_ITER_BEGIN(real4_type)
DEF_SCALAR_ITER_BEGIN(idx_type)

template <typename VectorType>
inline typename VectorType::const_iterator end(const VectorType& vec) { return vec.end(); }

template <typename VectorType>
inline typename VectorType::const_iterator end(const VectorType& vec,idx_type i) { return vec.end(i); }

DEF_SCALAR_ITER_END(real_type)
DEF_SCALAR_ITER_END(real4_type)
DEF_SCALAR_ITER_END(idx_type)

template <typename VectorType>
inline bool has_unit_stride(const VectorType& vec) { return vec.has_unit_stride(); }

template <typename MatrixType>
inline bool has_continuous_storage(const MatrixType& mat) { return mat.has_continuous_storage(); }

template <typename MatrixType>
inline bool transposed(const MatrixType& mat) { return mat.transposed(); }

template <typename MatrixType>
inline bool not_transposed(const MatrixType& mat) { return mat.not_transposed(); }

DEF_SCALAR_BOOL_FUNC(real_type)
DEF_SCALAR_BOOL_FUNC(real4_type)
DEF_SCALAR_BOOL_FUNC(idx_type)

template <typename IteratorType>
inline void advance(IteratorType& iter) { ++iter; }

template <typename IteratorType>
inline void advance(IteratorType& iter,idx_type str) { iter+=str; }

};

template <typename OprType,typename ArrayType>
class Array1Iterator {
private:
  typedef typename IteratorTraits<ArrayType>::const_iterator const_iterator;
  const_iterator  _vit;

public:
  typedef typename ArrayType::T_numtype T_numtype;

  Array1Iterator(const_iterator vit):_vit(vit) {}

  T_numtype operator * (void) { return OprType::compute(*_vit); }
  T_numtype operator [] (idx_type i) { return OprType::compute(_vit[i]); }
  void operator ++ (void) { ++_vit; }  // prefix operator
  void operator += (size_type str) { _vit+=str; }
  void advance(void) { IteratorFunc::advance(_vit); }
  void advance(idx_type str) { IteratorFunc::advance(_vit,str); }
  bool operator == (const Array1Iterator& vit) { return (_vit==vit._vit); }
  bool operator != (const Array1Iterator& vit) { return !(_vit==vit._vit); }
};

template <typename LeftType,typename OprType,typename RightType>
class Array2Iterator {
private:
  typedef typename IteratorTraits<LeftType>::const_iterator  iteratorL;
  typedef typename IteratorTraits<RightType>::const_iterator iteratorR;
  iteratorL _lit;
  iteratorR _rit;

public:
  typedef typename ArrayResultType<LeftType,RightType>::T_numtype T_numtype;

  //Array2Iterator(const LeftType& left,const RightType& right):_lit(VectorExpr::begin(left)),_rit(VectorExpr::begin(right)) {}
  Array2Iterator(iteratorL lit,iteratorR rit):_lit(lit),_rit(rit) {}

  T_numtype operator * (void) { return OprType::compute(*_lit,*_rit); }
  T_numtype operator [] (idx_type i) { return OprType::compute(_lit[i],_rit[i]); }
  void operator ++ (void) { ++_lit; ++_rit; }
  void operator += (size_type str) { _lit+=str; _rit+=str; }
  void advance(void) {IteratorFunc::advance(_lit); IteratorFunc::advance(_rit); }
  void advance(idx_type str) { IteratorFunc::advance(_lit,str); IteratorFunc::advance(_rit,str); }

  bool operator == (const Array2Iterator& vit) { return (_lit==vit._lit && _rit==vit._rit); }
  bool operator != (const Array2Iterator& vit) { return !(_lit==vit._lit && _rit==vit._rit); }
};

} // namespace Mec

#endif