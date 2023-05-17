#include "gtest/gtest.h"

TEST(class, inheritance)
{
  class A
  {
  public:
    virtual void test(void) const = 0;
  };
  class B : public A
  {
  public:
    void test(void) const override { std::cout << "B"; };
  };
  class C : public B
  {

  public:
		void test(void) const override { std::cout << "C"; };
  };

	A* b_ptr = new B();
	A* c_ptr = new C();
	b_ptr->test();
	c_ptr->test();
}
