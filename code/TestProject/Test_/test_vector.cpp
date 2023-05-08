#include "gtest/gtest.h"
#include <vector>

TEST(vector, reserve1)
{
  constexpr auto new_capacity = 1;

  std::vector<int> v;
  v.reserve(new_capacity);

  EXPECT_EQ(v.capacity(), new_capacity);
}
TEST(vector, reserve2)
{
  constexpr auto new_capacity = 11;

  std::vector<int> v;
  v.reserve(new_capacity);

  EXPECT_EQ(v.capacity(), new_capacity);
}

TEST(vector, resize1)
{
  constexpr auto new_size = 11;

  std::vector<int> v;
  v.resize(new_size);

  EXPECT_EQ(v.capacity(), new_size);
}

TEST(vector, push_back1)
{
  constexpr auto new_size = 11;

  std::vector<int> v;

	for (auto i = 0; i < new_size; ++i)
	{
		v.push_back(0);
    EXPECT_EQ(v.capacity(), i+1);
	}
}