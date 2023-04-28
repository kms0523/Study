#include "../TestProject/PHS2_1.h"
#include "gtest/gtest.h"

TEST(PHS2_1, 1)
{
  const auto     count = solution1(10, 10, { 1, 5, 15, 13, 2, 4, 10, 9, 11 });
  constexpr auto ref   = 4;
  EXPECT_EQ(count, ref);
}
//TEST(PHS2_1, 2_1)
//{
//  const auto     count = solution2(4, 7, { 2, 6, 3, 5, 3, 5 });
//  constexpr auto ref   = 5;
//  EXPECT_EQ(count, ref);
//}
//TEST(PHS2_1, 2_2)
//{
//  const auto     count = solution2(4, 3, { 1,10,3 });
//  constexpr auto ref   = 2;
//  EXPECT_EQ(count, ref);
//}
TEST(PHS2_1, 3_1)
{
  const auto     count = solution3(5, 6, { 9, 7, 2, 1, 4 });
  constexpr auto ref   = 3;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_1, 3_2)
{
  const auto     count = solution3(17, 21, { 4, 4, 13, 24, 9, 18, 4, 12, 24, 14, 9, 10, 1, 8, 5, 25, 6, 22, 15, 12 });
  constexpr auto ref   = 8;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_1, 4_1)
{
  const auto     count = solution4(5, 7, { 9, 7, 6, 3, 4, 1 });
  constexpr auto ref   = 6;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_1, 4_2)
{
	const auto     count = solution4(7, 7, { 11,9,7,2,1,4 });
  constexpr auto ref   = 4;
  EXPECT_EQ(count, ref);
}