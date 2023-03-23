#ifndef __MEC_SHARED_PTR_HPP__
#define __MEC_SHARED_PTR_HPP__

#include "MecSharedPtr.h"


namespace Mec {

template<typename T> 
template<typename Y>
inline shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<Y> const & r) 
{
  if(_pn && _pn->dec_ref()==0)
    delete _pn;
  
  _px=r.get(); _pn=r.get_counter_ptr(); 
  if(_pn) _pn->add_ref(); 
  return *this; 
}

template<typename T>
inline shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr<T> const & r) 
{ 
  if(_pn && _pn->dec_ref()==0)
    delete _pn;

  _px=r._px; _pn=r._pn; 
  if(_pn) _pn->add_ref(); 
  return *this; 
}


}

#endif