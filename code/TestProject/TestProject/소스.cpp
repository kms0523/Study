#include <iostream>
#include <memory>
#include <type_traits>
#include <vector>

#include "���2.h"

int main(void) {
  {
    Number_Handler nc1;
    const auto* ptr1 = nc1.get_ptr("2", 1);
    const auto* ptr2 = nc1.get_ptr("2", 1);
    const auto* ptr3 = nc1.get_ptr("2", 3);
    const auto* ptr4 = nc1.get_ptr("3", 2);
    const auto* ptr5 = nc1.get_ptr("3", 2);
    const auto* ptr6 = nc1.get_ptr("3", 2);

    ptr1->print();
    ptr2->print();
    ptr3->print();
    ptr4->print();
    ptr5->print();

    ptr6->print();
  }

  {
    Number_Handler nc2;
    const auto ptr1 = nc2.get_ptr("2", 1);
    const auto ptr2 = nc2.get_ptr("2", 1);
    const auto ptr3 = nc2.get_ptr("2", 3);
    const auto ptr4 = nc2.get_ptr("3", 2);
    const auto ptr5 = nc2.get_ptr("3", 2);
    const auto ptr6 = nc2.get_ptr("3", 2);

    ptr1->print();
    ptr2->print();
    ptr3->print();
    ptr4->print();
    ptr5->print();

    ptr6->print();
  }

}