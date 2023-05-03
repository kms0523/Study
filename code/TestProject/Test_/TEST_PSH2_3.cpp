#include "../TestProject/PHS2_3.h"
#include "gtest/gtest.h"

//TEST(PHS2_3, 1_1)
//{
//  int                      N = 5;
//  std::vector<std::string> W = { "apple", "everyone", "element", "truck", "kite" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "Yes";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 1_2)
//{
//  int                      N = 3;
//  std::vector<std::string> W = { "apple", "bce", "ce" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "No";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 1_3)
//{
//  int                      N = 3;
//  std::vector<std::string> W = { "apple", "eb", "fcf" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "No";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 1_4)
//{
//  int                      N = 4;
//  std::vector<std::string> W = { "apple", "ef", "fce", "eb" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "Yes";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 1_5)
//{
//  int                      N = 3;
//  std::vector<std::string> W = { "apple", "ef", "fea" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "Yes";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 1_6)
//{
//  int                      N = 3;
//  std::vector<std::string> W = { "fef", "fa", "ab" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "Yes";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 1_7)
//{
//  int                      N = 4;
//  std::vector<std::string> W = { "ae", "efe", "eb", "fcf" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "No";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 1_8)
//{
//  int                      N = 3;
//  std::vector<std::string> W = { "apple", "everyone", "element" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "Yes";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 1_9)
//{
//  int                      N = 3;
//  std::vector<std::string> W = { "aa", "bb", "cc" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "No";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 1_10)
//{
//  int                      N = 3;
//  std::vector<std::string> W = { "ba", "af", "fcf" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "Yes";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 1_11)
//{
//  int                      N = 3;
//  std::vector<std::string> W = { "ba", "af", "fcf", "cf" };
//
//  const auto result = solution1(N, W);
//  const auto ref    = "No";
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 2_1)
//{
//  int                      N = 3;
//  std::vector<std::string> W = { "apple", "egg", "gravity" };
//
//  const auto                     result = solution2(N, W);
//  const std::vector<std::string> ref    = { "apple" };
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 2_2)
//{
//  int                      N = 2;
//  std::vector<std::string> W = { "everyone", "eve" };
//
//  const auto                     result = solution2(N, W);
//  const std::vector<std::string> ref    = { "eve", "everyone" };
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 2_3)
//{
//  int                      N = 3;
//  std::vector<std::string> W = { "ba", "abc", "ab" };
//
//  const auto                     result = solution2(N, W);
//  const std::vector<std::string> ref    = { "ab" };
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 2_4)
//{
//  int                      N = 5;
//  std::vector<std::string> W = { "ae", "ea", "ab", "ac", "ca" };
//
//  const auto                     result = solution2(N, W);
//  const std::vector<std::string> ref    = { "ac", "ae" };
//  EXPECT_EQ(result, ref);
//}
//TEST(PHS2_3, 2_5)
//{
//  int                      N = 6;
//  std::vector<std::string> W = { "ab", "bc", "cb", "ba", "ad", "de" };
//
//  const auto                     result = solution2(N, W);
//  const std::vector<std::string> ref    = { "ab", "bc", "cb" };
//  EXPECT_EQ(result, ref);
//}

TEST(test1,test1)
{
	std::vector<double> v = { 1 };

  if (not v.empty())
  {
		std::cout << "noe empty";
  }
}