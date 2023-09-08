#include "gtest/gtest.h"
#include <map>

TEST(map, lower_bound)
{
  std::map<int, int> m;
	m.insert(std::pair(1, 1));
  m.insert(std::pair(3, 3));
  m.insert(std::pair(4, 4));

	// Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
	const auto& [key, value] = *m.lower_bound(2); 

  EXPECT_EQ(key, 3);
}
TEST(map, upper_bound)
{
  std::map<int, int> m;
  m.insert(std::pair(1, 1));
  m.insert(std::pair(3, 3));
  m.insert(std::pair(4, 4));

	// Returns an iterator pointing to the first element that is greater than key.
  const auto& [key, value] = *m.upper_bound(3);

  EXPECT_EQ(key, 4);
}
TEST(map, emplace)
{
  std::map<int, int> m;
	m.emplace(1, 1);
	m.emplace(1, 2);

	EXPECT_EQ(m.size(), 1);
  EXPECT_EQ(m[1], 1);
}