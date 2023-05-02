#include "../TestProject/PHS2_2.h"
#include "gtest/gtest.h"

TEST(PHS2_2, 1_1)
{
  const auto     count = solution1({ 8, 7, 6, 1, 5, 4, 3, 2 });
  constexpr auto ref   = 1;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_2, 1_2)
{
  const auto     count = solution1({ 8, 7, 6, 1, 5, 4, 1, 2 });
  constexpr auto ref   = 0;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_2, 2_1)
{
  const auto     count = solution2(20, { 10, 5, 1, 2, 3, 4, 5, 6, 7, 8, 5, 3, 1, 2, 3, 4, 5, 6, 7, 8 }, { 1, 2, 3, 4, 5, 6, 7, 8 });
  constexpr auto ref   = 3;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_2, 3_1)
{
  const auto     count = solution3(10, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 0, 0, 1, 2, 3, 4, 5, 6, 7, 8 }, { 1, 2, 3, 4, 5, 6, 7, 8 }, 7);
  constexpr auto ref   = -127;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_2, 3_2)
{
  const auto     count = solution3(10, { 0, 0, 1, 2, 3, 4, 5, 6, 7, 8 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8 }, 7);
  constexpr auto ref   = 127;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_2, 4_1)
{
  const auto       N = 10;
  std::vector<int> F = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 0 };
  std::vector<int> S = { 1, 2, 3, 4, 5, 6, 7, 8, 0, 0 };
  std::vector<int> B = { 1, 2, 3, 4, 5, 6, 7, 8 };
  const auto       T = 123;
  const auto       P = 1;
  const auto       Q = 412;

  const auto     count = solution4(N, F, S, B, T, P, Q);
  constexpr auto ref   = 4228;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_2, 5_1)
{
  constexpr auto   N = 10;
  std::vector<int> F = { 1, 2, 3, 4, 5, 6, 7, 8, 0, 0 };
  std::vector<int> S = { 0, 0, 1, 2, 3, 4, 5, 6, 7, 8 };
  std::vector<int> B = { 1, 2, 3, 4, 5, 6, 7, 8 };
  constexpr auto   T = 60;
  constexpr auto   P = 13;
  constexpr auto   Q = 11;
  constexpr auto   W = 15;
  constexpr auto   O = 4;

  const auto     count = solution5(N, F, S, B, T, P, Q, W, O);
  constexpr auto ref   = 217;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_2, 5_2)
{
  constexpr auto   N = 10;
  std::vector<int> F = { 0,0,1,2,3,4,5,6,7,8 };
  std::vector<int> S = { 0,0,1,2,3,4,5,6,7,8 };
  std::vector<int> B = { 1,2,3,4,5,6,7,8 };
  constexpr auto   T = 7;
  constexpr auto   P = 28;
  constexpr auto   Q = 4;
  constexpr auto   W = 0;
  constexpr auto   O = 1234;

  const auto     count = solution5(N, F, S, B, T, P, Q, W, O);
  constexpr auto ref   = -1;
  EXPECT_EQ(count, ref);
}
TEST(PHS2_2, 5_3)
{
  constexpr auto   N = 10;
	std::vector<int> F = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 0 };
  std::vector<int> S = { 0, 0, 1, 2, 3, 4, 5, 6, 7, 8 };
  std::vector<int> B = { 1, 2, 3, 4, 5, 6, 7, 8 };
  constexpr auto   T = 7;
  constexpr auto   P = 0;
  constexpr auto   Q = 4;
  constexpr auto   W = 0;
  constexpr auto   O = 1234;

  const auto     count = solution5(N, F, S, B, T, P, Q, W, O);
  constexpr auto ref   = 0;
  EXPECT_EQ(count, ref);
}
