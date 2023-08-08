#include "gtest/gtest.h"
#include <numeric>

TEST(numeric, infinity)
{
	constexpr auto inf = std::numeric_limits<double>::infinity();
	EXPECT_TRUE(inf == std::numeric_limits<double>::infinity());
}