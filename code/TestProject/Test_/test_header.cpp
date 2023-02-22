#include "../TestProject/Çì´õ.h"
#include "gtest/gtest.h"

TEST(Calender, cal_num_break_day) {
  int X = 7;
	std::vector<std::vector<int>> H = { { 1, 1 }, { 1, 21 }, { 1, 22 }, { 1, 23 }, { 3, 1 }, { 5, 5 }, { 5, 27 }, { 6, 6 }, { 8, 15 }, { 9, 28 }, { 9, 29 }, { 9, 30 }, { 10, 3 }, { 10, 9 }, { 12, 25 } };
	
	Calender c(X,H);
	EXPECT_EQ(c.cal_num_break_day(),120);
}  

TEST(Calender, cal_best_vaction_plan)
{
    int X = 7;
    std::vector<std::vector<int>> H = { { 1, 1 }, { 1, 21 }, { 1, 22 }, { 1, 23 }, { 3, 1 }, { 5, 5 }, { 5, 27 }, { 6, 6 }, { 8, 15 }, { 9, 28 }, { 9, 29 }, { 9, 30 }, { 10, 3 }, { 10, 9 }, { 12, 25 } };
		int N = 3;

    Calender c(X, H);
		auto result = c.cal_best_vacation_plan(N);
		std::vector<int> ref = { 11,9,23,10,3 };
    EXPECT_EQ(result,ref);
}
