#include "gtest/gtest.h"
#include <cmath>

class A
{
public:
	A(const int val) : value(val) {};

	static int sum(const A& a1, const A& a2)
	{
		return a1.value + a2.value;
	}

private:
	int value = 0;
};


class Base
{
public:
  virtual void f1(void) const { f2(); };
  virtual void f2(void) const { std::cout << "f2 in Base\n"; };

};

class Derive : public Base
{
public:
  void f1(void) const override { Base::f1(); };
  void f2(void) const override { std::cout << "f2 in Derive\n"; };

};


TEST(temp,1)
{
  std::unique_ptr<Base> uptr = std::make_unique<Derive>();
  uptr->f1();

	

	//constexpr auto pi = 3.14159265359;

	//const auto c1 = 2 * std::sqrt(3) / 4.0;
 // const auto c2 = -2.0 / 4.0;

	//const auto theta = std::atan2(c2, c1);
	//const auto degree = theta * 180.0 / pi;

	//std::cout << theta << "\t" << degree;
}