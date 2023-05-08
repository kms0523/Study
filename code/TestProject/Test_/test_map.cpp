#include "gtest/gtest.h"
#include <map>

TEST(map, lower_bound)
{
	//map에 lower_bound(하한선)을 줬을 때 하한선에 가장 가까운 key값을 갖은 iter를 return

  std::map<int, int> m;
	m.insert(std::pair(1, 1));
  m.insert(std::pair(3, 3));
  m.insert(std::pair(4, 4));

	const auto& [key, value] = *m.lower_bound(2);

  EXPECT_EQ(key, 1);
}
TEST(map, upper_bound)
{
	//map에 upper_bound(상한선)을 줬을 때 상한선에 가장 가까운 key값을 갖은 iter를 return

  std::map<int, int> m;
  m.insert(std::pair(1, 1));
  m.insert(std::pair(3, 3));
  m.insert(std::pair(4, 4));

  const auto& [key, value] = *m.upper_bound(3);

  EXPECT_EQ(key, 3);
}