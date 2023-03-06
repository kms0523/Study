#include "gtest/gtest.h"

TEST(Test, test)
{
	if (1)
		std::cout << "true\n";
	else
		std::cout << "false\n";

	if (1) std::cout << "true\n";
}

//#include "../TestProject/¼Ò½º.cpp"
//#include "gtest/gtest.h"
//
//#include <optional>
//
// std::pair<std::optional<CDates>, std::optional<CDates>> find_right_before_and_after(const std::vector<CDates>& cdatess, const CDates& target)
//{
//    std::pair<std::optional<CDates>, std::optional<CDates>> result;
//
//    bool exist_right_back = true;
//    bool exist_right_after = true;
//
//    if (target.begin_date() < cdatess.front().end_date()) {
//        exist_right_back = false;
//    }
//
//    if (cdatess.back().end_date() < target.end_date()) {
//        exist_right_after = false;
//    }
//
//    auto index = 0;
//    if (exist_right_back) {
//        while (true) {
//            if (cdatess[index].end_date() < target.begin_date() && target.begin_date() <= cdatess[index + 1].end_date()) {
//                result.first = cdatess[index];
//								index++;
//                break;
//            } else {
//                index++;
//            }
//        }
//    }
//
//    if (exist_right_after) {
//        while (true) {
//            if (cdatess[index - 1].begin_date() <= target.end_date() && target.end_date() < cdatess[index].begin_date()) {
//                result.second = cdatess[index];
//                break;
//            } else {
//                index++;
//            }
//        }
//    }
//
//    return result;
//}
//
//
// TEST(Consecutive_Dates, find_right_before_and_after)
//{
//    Date d1(1, 3);
//    Date d2(1, 5);
//    Date d3(1, 7);
//    Date d4(1, 11);
//    Date d5(1, 15);
//
//    CDates cdates1(d1, d2);
//    CDates cdates2(d3, d3);
//    CDates cdates3(d4, d4);
//
//    std::vector<Consecutive_Dates> cdatess;
//    cdatess.push_back(cdates1);
//    cdatess.push_back(cdates2);
//    cdatess.push_back(cdates3);
//
//    auto result = find_right_before_and_after(cdatess, cdates2);
//    EXPECT_EQ(result.first.has_value(), true);
//    EXPECT_EQ(result.second.has_value(), true);
//}
//
// TEST(CT, test1_5) {
//    std::vector<std::vector<int>> H = { { 1, 1 }, { 1, 21 }, { 1, 22 }, { 1, 23 }, { 3, 1 }, { 5, 5 }, { 5, 27 }, { 6, 6 }, { 8, 15 }, { 9, 28 }, {
//    9, 29 }, { 9, 30 }, { 10, 3 }, { 10, 9 }, { 12, 25 } };
//
//    auto result = solution(7, H, 3);
//
//}