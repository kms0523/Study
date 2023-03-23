#ifndef __MEC_GLOBALTYPEDEFS_H
#define __MEC_GLOBALTYPEDEFS_H

#define USE_MEC_SHARED_PTR
//#define USE_VC_SHARED_PTR
//#define USE_BOOST_SHARED_PTR

#if defined(USE_MEC_SHARED_PTR)
#include "MecSharedPtr.hpp"  
#define MEC_SHARED_PTR            ::Mec::shared_ptr
#define MEC_STATIC_POINTER_CAST   ::Mec::static_pointer_cast
#define MEC_DYNAMIC_POINTER_CAST  ::Mec::dynamic_pointer_cast
#define MEC_CONST_POINTER_CAST    ::Mec::const_pointer_cast
#elif defined(USE_VC_SHARED_PTR)
  #include <memory>
  #define MEC_SHARED_PTR            ::std::shared_ptr
  #define MEC_STATIC_POINTER_CAST   ::std::static_pointer_cast
  #define MEC_DYNAMIC_POINTER_CAST  ::std::dynamic_pointer_cast
  #define MEC_CONST_POINTER_CAST    ::std::const_pointer_cast
#elif defined(USE_BOOST_SHARED_PTR)
#include <boost/smart_ptr/shared_ptr.hpp>
#define MEC_SHARED_PTR            ::boost::shared_ptr
#define MEC_STATIC_POINTER_CAST   ::boost::static_pointer_cast
#define MEC_DYNAMIC_POINTER_CAST  ::boost::dynamic_pointer_cast
#define MEC_CONST_POINTER_CAST    ::boost::const_pointer_cast
#endif

#include <complex>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>

// unordered map for fast map access not supported in boost 1.35
#ifndef _DEBUG 
//#define _UNORDERED_MAP
#ifdef _LINUX
#define _BST_UNORDERED_MAP
#else
#define _STD_UNORDERED_MAP
#endif
#endif

//#ifdef _UNORDERED_MAP  
#ifdef _BST_UNORDERED_MAP
#define f_map boost::unordered_map
#define f_set boost::unordered_set
namespace boost{
template <class T> 
struct hash <Mec::shared_ptr<T> >
{
  typedef Mec::shared_ptr<T> argument_type;
  std::size_t operator() (const argument_type& _Keyval) const {
   return (hash<T *>() (_Keyval.get()));
  }
};
}


//template <typename A, typename B>
//class f_map : public f_bmap<A, B, boost::hash<A> > {};
//template <typename A>
//class f_set : public f_bset<A, boost::hash<A> > {};
#elif defined(_STD_UNORDERED_MAP)
#include <unordered_map>
#include <unordered_set>
#include <boost/container_hash/hash.hpp>

namespace std
{
  template<class _Ty>
  struct hash<Mec::shared_ptr<_Ty> >
  {	// hash functor
    typedef Mec::shared_ptr<_Ty> argument_type;
    typedef size_t result_type;

    size_t operator()(const argument_type& _Keyval) const
    {	// hash _Keyval to size_t value by pseudorandomizing transform
      return (hash<_Ty *>()(_Keyval.get()));
    }
  };

  template<class _TyA, class _TyB>
  struct hash<std::pair<_TyA, _TyB> >
  {	// hash functor
    typedef std::pair<_TyA, _TyB> argument_type;
    typedef size_t result_type;

    size_t operator()(const argument_type& _Keyval) const
    {	// hash _Keyval to size_t value by pseudorandomizing transform
      std::size_t seed = 0;
      boost::hash_combine(seed, _Keyval.first);
      boost::hash_combine(seed, _Keyval.second);
      return seed;
    }
  };

  template <class T, class A>
  struct hash<std::vector<T, A> >
  {	// hash functor
    typedef std::vector<T, A> argument_type;
    typedef size_t result_type;

    size_t operator()(const argument_type& _Keyval) const
    {
      return boost::hash_range(_Keyval.begin(), _Keyval.end());
    }
  };
}

#define f_map std::unordered_map
#define f_set std::unordered_set
#else
#define f_map std::map
#define f_set std::set
#endif

using namespace std;

namespace Mec {

  typedef double          real_type;
  typedef float           real4_type;
  typedef double          real8_type;
  typedef complex<double> complex_type;
  typedef complex<float>  complex4_type;
  typedef complex<double> complex8_type;

  typedef int               idx_type;
  typedef int               size_type;
#ifdef _WIN64
  typedef __int64           lidx_type;
  typedef __int64           lsize_type;
#elif _LINUX
  typedef __int64           lidx_type;
  typedef __int64           lsize_type;
#else
  typedef long int          lidx_type;
  typedef size_t            lsize_type;
#endif
  typedef __int64           size8_type;
  typedef unsigned __int64  usize8_type;
  typedef int               tag_type;
  typedef const char*       name_type;

  typedef	vector<tag_type>	       TagArray;
  typedef	list<tag_type>	         TagList;
  typedef	set<tag_type>	           TagSet;
  typedef	vector<idx_type>	       IdxArray;
  typedef	list<idx_type>	         IdxList;
  typedef	set<idx_type>	           IdxSet;
  typedef f_map<idx_type, idx_type> IdxMap;
  typedef	list<real_type>	         RealList;
  typedef vector<bool>             BoolArray;

#define DEF_SHARED_PTR(DataType) \
  typedef MEC_SHARED_PTR< DataType >                        DataType ## Ptr;  \
  typedef MEC_SHARED_PTR< const DataType >                  DataType ## CPtr;  

#define DEF_SPTR_VECTOR(DataType) \
  typedef std::vector< MEC_SHARED_PTR< DataType > >         DataType ## Array;

#define DEF_SPTR_LIST(DataType) \
  typedef std::list< MEC_SHARED_PTR< DataType > >           DataType ## List;

#define DEF_SPTR_MAP(DataType) \
  typedef std::map< tag_type, MEC_SHARED_PTR< DataType > >  DataType ## Map;

#define DEF_SPTR_TYPES(DataType) \
  typedef MEC_SHARED_PTR< DataType >                         DataType ## Ptr;    \
  typedef MEC_SHARED_PTR< const DataType >                   DataType ## CPtr;   \
  typedef std::vector< MEC_SHARED_PTR< DataType > >          DataType ## Array;  \
  typedef std::list< MEC_SHARED_PTR< DataType > >            DataType ## List;   \
  typedef std::map< tag_type, MEC_SHARED_PTR< DataType > >   DataType ## Map; 

  const real_type MACH_EPS = 2.2e-16;
  const real_type BIG_NUMBER = 1.e100;
  const real_type REAL_TYPE_MAX = std::numeric_limits<real_type>::max();

//#define _MEM_ALIGN_BND 64 // for tbb cache-aligned allocator //(lkb1024-vec)

} // namespace Mec

#endif
