#include "gtest/gtest.h"
#include <map>

TEST(map, lower_bound)
{
	//map�� lower_bound(���Ѽ�)�� ���� �� ���Ѽ��� ���� ����� key���� ���� iter�� return

  std::map<int, int> m;
	m.insert(std::pair(1, 1));
  m.insert(std::pair(3, 3));
  m.insert(std::pair(4, 4));

	const auto& [key, value] = *m.lower_bound(2);

  EXPECT_EQ(key, 1);
}
TEST(map, upper_bound)
{
	//map�� upper_bound(���Ѽ�)�� ���� �� ���Ѽ��� ���� ����� key���� ���� iter�� return

  std::map<int, int> m;
  m.insert(std::pair(1, 1));
  m.insert(std::pair(3, 3));
  m.insert(std::pair(4, 4));

  const auto& [key, value] = *m.upper_bound(3);

  EXPECT_EQ(key, 3);
}