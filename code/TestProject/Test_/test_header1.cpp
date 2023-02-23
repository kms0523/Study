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

    auto result = solution3(TN, P, V);
}

TEST(ct2, 4_1)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "22", "kang", "teacher", "male" } };
    const std::string Q = "select (age, gender) from custom";

    auto result = solution(TN, P, V, Q);

    for (const auto vec : result) {
        for (const auto str : vec) {
            std::cout << str << " ";
        }
				std::cout << "\n";
    }
}

TEST(ct2, 4_2)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "22", "kang", "teacher", "male" } };
		const std::string Q = "select (name) from custom where age >= 20";

    auto result = solution(TN, P, V, Q);

    for (const auto vec : result) {
        for (const auto str : vec) {
            std::cout << str << " ";
        }
        std::cout << "\n";
    } 
}

TEST(ct2, 4_3)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "22", "kang", "teacher", "male" } };
		const std::string Q = "select (name, job, gender, address) from custom where age >= 10";

    auto result = solution(TN, P, V, Q);

    for (const auto vec : result) {
        for (const auto str : vec) {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }
}

TEST(ct2, 4_4)
{
    const std::string TN = "custom2";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "22", "kang", "teacher", "male" } };
    const std::string Q = "select (name, job, gender, address) from custom where age >= 10";

    auto result = solution(TN, P, V, Q);

    for (const auto vec : result) {
        for (const auto str : vec) {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }
}

TEST(sv, parse)
{
    std::string_view sv = "ab,cd,ef";
    auto parsed_sv = parse(sv, ",");

    for (const auto sv : parsed_sv)
        std::cout << sv << "\n";
}

TEST(sv, compare)
{
    std::string_view sv1 = "6";
		std::string_view sv2 = "20";
    
		EXPECT_LE(std::stoi(sv1.data()), std::stoi(sv2.data()));
}
TEST(sv, compare2)
{
    std::string_view sv1 = "ab";
    std::string_view sv2 = "aba";

    EXPECT_LE(sv1, sv2);
}
TEST(sv, compare3)
{
    std::string_view sv1 = "aba";
    std::string_view sv2 = "ac";

    EXPECT_LE(sv1, sv2);
}