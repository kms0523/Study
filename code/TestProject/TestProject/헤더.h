#pragma once
#include <type_traits>
#include <vector>

class Number_Handler;

class Number {
  friend Number_Handler;

 public:
  virtual void print(void) const = 0;

 protected:
  Number(void) = default;
  virtual ~Number(void) = default;
};
