#pragma once
#include "Çì´õ.h"

#include <iostream>

class Number_Handler;

class Two : public Number {
  friend Number_Handler;

  void print(void) const override { std::cout << std::pow(2, order_) << "\n"; };

 private:
  Two(int order) {
    this->order_ = order;
    std::cout << "Two construct \n";
  }

  ~Two(void) { std::cout << "Two destruct \n"; }

 private:
  int order_ = 0;
};

class Three : public Number {
  friend Number_Handler;

  void print(void) const override { std::cout << std::pow(3, order_) << "\n"; };

 private:
  Three(int order) {
    this->order_ = order;
    std::cout << "Three construct \n";
  }

  ~Three(void) { std::cout << "Three destruct \n"; }

 private:
  int order_ = 0;
};