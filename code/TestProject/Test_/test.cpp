#include "gtest/gtest.h"
#include <cmath>

TEST(temp,1)
{
	constexpr auto pi = 3.14159265359;

	const auto c1 = 2 * std::sqrt(3) / 4.0;
  const auto c2 = -2.0 / 4.0;

	const auto theta = std::atan2(c2, c1);
	const auto degree = theta * 180.0 / pi;

	std::cout << theta << "\t" << degree;
}