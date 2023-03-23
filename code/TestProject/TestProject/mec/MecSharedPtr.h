#ifndef __MEC_SHARED_PTR_H__
#define __MEC_SHARED_PTR_H__

#include <boost/detail/atomic_count.hpp>
#ifdef _LINUX
#include <functional>
#endif

namespace Mec {

class counted_base {
protected:
  boost::detail::atomic_count _count;
        
public:
  counted_base():_count(1) { }
  virtual ~counted_base() { }
    
  void add_ref() { ++_count; }
  virtual long dec_ref(void)=0;  
};

template<typename Y>
class counted_impl : public counted_base {
private:
  Y* _pc;

public:
  explicit counted_impl(Y* p):_pc(p),counted_base() { }
  ~counted_impl(){}

  long dec_ref(void) { if(--_count==0) delete _pc;  return _count; }
};

template<typename T>
class shared_ptr {
private:
  T            *_px;
  counted_base *_pn;

  typedef shared_ptr<T> this_type;

public:
  typedef T element_type;
  typedef T value_type;
  typedef T *pointer;
    
  ~shared_ptr() { if(_pn && _pn->dec_ref()==0) delete _pn; }

  shared_ptr(): _px(0), _pn(0) { }
  template<typename Y>
  explicit shared_ptr(Y* p) : _px(p) { if(_px) _pn = new counted_impl<Y>(p); else _pn=0; }
  shared_ptr(T* p,counted_base* pn) : _px(p) { if(_px) { _pn=pn; _pn->add_ref(); } else _pn=0; }  
  template<typename Y>
  shared_ptr( shared_ptr<Y> const & r ) : _px(r.get()), _pn(r.get_counter_ptr()) { if(_pn) _pn->add_ref(); }
  shared_ptr( shared_ptr<T> const & r ) : _px(r._px), _pn(r._pn) { if(_pn) _pn->add_ref(); }
  
  template<typename Y> 
  shared_ptr<T>& operator=(shared_ptr<Y> const & r);
  shared_ptr<T>& operator=(shared_ptr<T> const & r);
  void reset(void) { if(_pn && _pn->dec_ref()==0) delete _pn; _pn=0; _px=0; }

  counted_base* get_counter_ptr() const { return _pn; }
  T* get() const { return _px; }  
  T& operator*() const  {  return *_px;  }
  T* operator->() const {  return _px;   }
  operator bool () const {  return _px != 0; }

};  // shared_ptr


template<typename T, typename Y> inline bool operator==(shared_ptr<T> const & a, shared_ptr<Y> const & b) { return a.get() == b.get(); }
template<typename T, typename Y> inline bool operator!=(shared_ptr<T> const & a, shared_ptr<Y> const & b) { return a.get() != b.get(); }
template<typename T, typename Y> inline bool operator==(shared_ptr<T> const & a, Y * b) { return a.get() == b; }
template<typename T, typename Y> inline bool operator!=(shared_ptr<T> const & a, Y * b) { return a.get() != b; }
template<typename T, typename Y> inline bool operator==(T * a, shared_ptr<Y> const & b) { return a == b.get(); }
template<typename T, typename Y> inline bool operator!=(T * a, shared_ptr<Y> const & b) { return a != b.get(); }
template<typename T> inline bool operator<(shared_ptr<T> const & a, shared_ptr<T> const & b) { return std::less<T *>()(a.get(), b.get()); }
template<typename T> inline T * get_pointer(shared_ptr<T> const & p) { return p.get(); }
template<typename T, typename Y> inline shared_ptr<T> static_pointer_cast(shared_ptr<Y> const & p)  { return shared_ptr<T>(static_cast<T*>(p.get()),p.get_counter_ptr()); }
template<typename T, typename Y> inline shared_ptr<T> dynamic_pointer_cast(shared_ptr<Y> const & p) { return shared_ptr<T>(dynamic_cast<T*>(p.get()),p.get_counter_ptr()); }
template<typename T, typename Y> inline shared_ptr<T> const_pointer_cast(shared_ptr<Y> const & p) { return shared_ptr<T>(const_cast<T*>(p.get()),p.get_counter_ptr()); }


}
#endif
