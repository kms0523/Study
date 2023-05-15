#include "Header3.h"

#include <iostream>

template <typename T>
void A::test(const T val) const
{
  std::cout << val << "\n";
}

template void A::test<int>(const int) const;