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

TEST(temp,1)
{
	A a1(2);
	A a2(3);
	std::cout << A::sum(a1, a2);

	

	//constexpr auto pi = 3.14159265359;

	//const auto c1 = 2 * std::sqrt(3) / 4.0;
 // const auto c2 = -2.0 / 4.0;

	//const auto theta = std::atan2(c2, c1);
	//const auto degree = theta * 180.0 / pi;

	//std::cout << theta << "\t" << degree;
}