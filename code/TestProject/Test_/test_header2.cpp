#include "../TestProject/Çì´õ2.h"
#include "gtest/gtest.h"

TEST(sort, mscompare)
{
    std::vector<std::vector<int>> vvec = { { 1, 2 }, { 3, 1 }, { 5, 6 }, { 4, 4 }, { 5, 4 } };
    std::sort(vvec.begin(), vvec.end(), myCompare());

    std::vector<std::vector<int>> ref = { { 3, 1 }, { 1, 2 }, { 4, 4 }, { 5, 4 }, { 5, 6 } };

    EXPECT_EQ(vvec, ref);
}

TEST(ct, 1_1)
{
    int N = 3;
    std::vector<std::vector<int>> H = { { 2, 2 }, { 5, 5 }, { 1, 7 } };
    int D = 2;
    auto result = solution(N, H, D);
		
    EXPECT_EQ(result, 2);
}
TEST(ct, 1_2)
{
    int N = 3;
    std::vector<std::vector<int>> H = { { 2, 2 }, { 3, 3 }, { 3, 4 } };
    int D = 3;
    auto result = solution(N, H, D);

    EXPECT_EQ(result, 4);
}
TEST(ct, 1_3)
{
	std::vector<std::vector<int>> H = { { 2, 2 }, { 3, 3 }, { 3, 4 }, {4,3}, {5,4}, {5,5} };
    int D = 2;
    auto result = solution(H.size(), H, D);

    EXPECT_EQ(result, 5 ); 
}
TEST(ct, 1_4)
{
	std::vector<std::vector<int>> H = { { 2, 2 }, { 3, 3 }, { 4, 4 }, { 5, 3 }, { 5,5 }, { 7, 3 }, {7,5}, {7,7}, {10,10} };
    int D = 2;
    auto result = solution(H.size(), H, D);

    EXPECT_EQ(result, 7);
}

TEST(ct, intmax)
{
		int x = 1.0e9;

		std::cout << x;
    
    //EXPECT_EQ(result, 7);
}