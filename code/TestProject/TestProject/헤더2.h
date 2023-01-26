#pragma once
#include <map>
#include <string>

#include "Çì´õ1.h"

class Number_Handler {
 public:
  const Number* get_ptr(const std::string& str, const int order) {

    if (str == "2") {
      if (this->order_to_two_sptr.find(order) ==
          this->order_to_two_sptr.end()) { 
        this->order_to_two_sptr.emplace(order, new Two(order));
      }

      return this->order_to_two_sptr[order];
    } else {
      if (this->order_to_three_sptr.find(order) ==
          this->order_to_three_sptr.end()) {
        this->order_to_three_sptr.emplace(order, new Three(order));
      }

      return this->order_to_three_sptr[order];
    }
  }

 public:
  Number_Handler(void) = default;
  ~Number_Handler(void) {
     for (auto& iter : order_to_two_sptr) {
			delete iter.second;
    }

    for (auto& iter : order_to_three_sptr) {
      delete iter.second;
    }
  }

 private:
  using Order_To_Number_Ptr = std::map<int, const Number*>;

  Order_To_Number_Ptr order_to_two_sptr;
  Order_To_Number_Ptr order_to_three_sptr;
};

// class Number_Container {
//  using This = Number_Container;
//
// public:
//   const Number* get_ptr(const std::string& str, const int order) {
//    if (str == "2") {
//      if (This::order_to_two_sptr.find(order) ==
//          This::order_to_two_sptr.end()) {
//        This::order_to_two_sptr.emplace(order, new Two(order));
//      }
//
//      return This::order_to_two_sptr[order];
//    } else {
//      if (This::order_to_three_sptr.find(order) ==
//          This::order_to_three_sptr.end()) {
//        This::order_to_three_sptr.emplace(order, new Three(order));
//      }
//
//      return This::order_to_three_sptr[order];
//    }
//  }
//
// private:
//  Number_Container(void) = default;
//  ~Number_Container(void) {
//    for (auto& iter : order_to_two_sptr) {
//      delete iter.second;
//    }
//
//    for (auto& iter : order_to_three_sptr) {
//      delete iter.second;
//    }
//  }
//
// private:
//  using Order_To_Number_Ptr = std::map<int, const Number*>;
//
//  inline static Order_To_Number_Ptr order_to_two_sptr;
//  inline static Order_To_Number_Ptr order_to_three_sptr;
//};