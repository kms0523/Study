#pragma once

#include <iostream>

class A {
 public:
  virtual void dummy(void) const {};
};

class B {
public:
  virtual void dummy(void) const {
		std::cout << "B";
  }
};

class C : public A, public B{
public:
	void dummy(void) const {
		std::cout << "C";
	}
};

void f(const A& a) { a.dummy(); }
void f2(const B& a) { a.dummy(); }


int main(void) {
  C c;
	c.dummy();
  f(c);
	f2(c);
}
