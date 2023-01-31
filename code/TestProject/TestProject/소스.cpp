#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <type_traits>
#include <vector>

#include "헤더2.h"

void func(const std::vector<double*>& val) { *(val[0]) = 4; }

int main(void) {
  std::multimap<int, int> m;
  m.emplace(1, 1);
  m.emplace(1, 2);
  m.emplace(1, 3);

	if (not m.empty()) {
		std::cout << "m is not empty";
	}

	std::vector<double> v = { 1 };

	if (not v.empty()) {
		//...
	}

	if (v.size() > 0 and v.front() == 1) {
		std::cout << "이게 되네?";
	}

  std::cout << "Debug";
}

// int main(void) {
//  {
//    Number_Handler nc1;
//    const auto* ptr1 = nc1.get_ptr("2", 1);
//    const auto* ptr2 = nc1.get_ptr("2", 1);
//    const auto* ptr3 = nc1.get_ptr("2", 3);
//    const auto* ptr4 = nc1.get_ptr("3", 2);
//    const auto* ptr5 = nc1.get_ptr("3", 2);
//    const auto* ptr6 = nc1.get_ptr("3", 2);
//
//    ptr1->print();
//    ptr2->print();
//    ptr3->print();
//    ptr4->print();
//    ptr5->print();
//
//    ptr6->print();
//  }
//
//  {
//    Number_Handler nc2;
//    const auto ptr1 = nc2.get_ptr("2", 1);
//    const auto ptr2 = nc2.get_ptr("2", 1);
//    const auto ptr3 = nc2.get_ptr("2", 3);
//    const auto ptr4 = nc2.get_ptr("3", 2);
//    const auto ptr5 = nc2.get_ptr("3", 2);
//    const auto ptr6 = nc2.get_ptr("3", 2);
//
//    ptr1->print();
//    ptr2->print();
//    ptr3->print();
//    ptr4->print();
//    ptr5->print();
//
//    ptr6->print();
//  }
//
//}