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

    auto result = solution4(TN, P, V, Q);

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

    auto result = solution4(TN, P, V, Q);
    std::vector<std::vector<std::string>> ref = { { "kang" } };
    EXPECT_EQ(result, ref);
}

TEST(ct2, 4_3)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "22", "kang", "teacher", "male" } };
    const std::string Q = "select (name, job, gender, address) from custom where age >= 10";

    auto result = solution4(TN, P, V, Q);

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

    auto result = solution4(TN, P, V, Q);

    for (const auto vec : result) {
        for (const auto str : vec) {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }
}

TEST(ct2, 4_5)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "22", "kang", "teacher", "male" } };
    const std::string Q = "select (name, job, gender, address) from custom where address = seoul";

    auto result = solution4(TN, P, V, Q);

    for (const auto vec : result) {
        for (const auto str : vec) {
            std::cout << str << " ";
        }
        std::cout << "\n";
    }
}

TEST(ct2, 4_6)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "kang", "teacher", "male" } };
    const std::string Q = "select (name, job, gender, address) from custom where age >= 10";

    auto result = solution4(TN, P, V, Q);
    std::vector<std::vector<std::string>> ref = { { "hong", "-", "-", "seoul" } };
    EXPECT_EQ(result, ref); 
}

TEST(ct2, 5_1)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "22", "kang", "teacher", "male" } };
    const std::string Q = "update custom set job = student where age <= 19";

    auto result = solution(TN, P, V, Q);
		std::vector<std::vector<std::string>> ref = { {"seoul", "19","-","student","hong"},{ "-","22", "male","teacher","kang"} };
    EXPECT_EQ(result, ref);
}
TEST(ct2, 5_2)
{
    const std::string TN = "custom";
    const std::vector<std::vector<std::string>> P = { { "age", "name", "address" }, { "age", "name", "job", "gender" } };
    const std::vector<std::vector<std::string>> V = { { "19", "hong", "seoul" }, { "22", "kang", "teacher", "male" } };
    const std::string Q = "update custom set job = student where age <= 10";

    auto result = solution(TN, P, V, Q);
    std::vector<std::vector<std::string>> ref = { { "seoul", "19", "-", "-", "hong" }, { "-", "22", "male", "teacher", "kang" } };
    EXPECT_EQ(result, ref);
}


TEST(sv, parse)
{
    std::string_view sv = "ab,cd,ef";
    auto parsed_sv = parse(sv, ",");

    EXPECT_EQ(parsed_sv[0], "ab");
    EXPECT_EQ(parsed_sv[1], "cd");
    EXPECT_EQ(parsed_sv[2], "ef");
}
TEST(sv, parse2)
{
    std::string_view sv = "ab,cd,ef,";
    auto parsed_sv = parse(sv, ",");

    EXPECT_EQ(parsed_sv.size(), 3);
    EXPECT_EQ(parsed_sv[0], "ab");
    EXPECT_EQ(parsed_sv[1], "cd");
    EXPECT_EQ(parsed_sv[2], "ef");
}
TEST(sv, parse3)
{
    std::string_view sv = "ab,,cd,ef,";
    auto parsed_sv = parse(sv, ",");

    EXPECT_EQ(parsed_sv[0], "ab");
    EXPECT_EQ(parsed_sv[1], "cd");
    EXPECT_EQ(parsed_sv[2], "ef");
}

TEST(sv, compare)
{
    std::string_view sv1 = "6";
    std::string_view sv2 = "20";

    EXPECT_LE(std::stod(sv1.data()), std::stod(sv2.data()));
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