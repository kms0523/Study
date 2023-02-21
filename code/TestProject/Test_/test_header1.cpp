#include "../TestProject/Çì´õ1.h"
#include "gtest/gtest.h"

TEST(ct2, 1)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };

    std::cout << solution1(TN, P) << "\n";
}

TEST(ct2, 2)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "22", "kang", "teacher", "male" } };

    auto result = solution2(TN, P, V);

    for (const auto str : result)
        std::cout << str << "\n";
}

TEST(ct2, 3)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "22", "kang", "teacher", "male" } };

    auto result = solution(TN, P, V);

		for (const auto& vec : result) {
			for (const auto& str : vec) {
				std::cout << str << " ";
			}
			std::cout << "\n";
		}

}