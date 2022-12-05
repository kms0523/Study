#include "pch.h"
#include "../Test/Çì´õ.h"

#include <random>
#include <vector>
#include <utility>

static constexpr auto epsilon = 9.0e-8;

class transformation_function
{
public:
	transformation_function(const std::vector<double>& x_coordinates, const std::vector<double>& y_coordinates)
		: x_coordinates_(x_coordinates)
		, y_coordinates_(y_coordinates) {};

public:
	std::pair<double, double> ref_to_physical(const double xi, const double eta) const
	{
		const auto a1 = 1 + xi;
		const auto a2 = 1 - xi;
		const auto b1 = 1 + eta;
		const auto b2 = 1 - eta;

		const auto sf1 = a2 * b2 * 0.25;
		const auto sf2 = a1 * b2 * 0.25;
		const auto sf3 = a1 * b1 * 0.25;
		const auto sf4 = a2 * b1 * 0.25;

		const auto x = sf1 * x_coordinates_[0] + sf2 * x_coordinates_[1] + sf3 * x_coordinates_[2] + sf4 * x_coordinates_[3];
		const auto y = sf1 * y_coordinates_[0] + sf2 * y_coordinates_[1] + sf3 * y_coordinates_[2] + sf4 * y_coordinates_[3];

		return { x,y };
	}

private:
	std::vector<double> x_coordinates_;
	std::vector<double> y_coordinates_;
};

TEST(quadratic_formula, random_test1)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;

	transformation_function tf({ x1,x2,x3,x4 }, { y1,y2,y3,y4 });

	constexpr auto iter = 10000;

	for (size_t i = 0; i < iter; i++)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dis(-1, 1);

		const auto random_xi = dis(gen);
		const auto random_eta = dis(gen);

		const auto result = tf.ref_to_physical(random_xi, random_eta);
		const auto xp = result.first;
		const auto yp = result.second;

		auto xi = 0.0;
		auto eta = 0.0;
		quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);

		EXPECT_NEAR(xi, random_xi, epsilon) << "quadratic formula \n";
		EXPECT_NEAR(eta, random_eta, epsilon) << "quadratic formula \n";
	}
}
TEST(quadratic_formula, random_test2)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 2;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;

	transformation_function tf({ x1,x2,x3,x4 }, { y1,y2,y3,y4 });

	constexpr auto iter = 10000;

	for (size_t i = 0; i < iter; i++)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dis(-1, 1);

		const auto random_xi = dis(gen);
		const auto random_eta = dis(gen);

		const auto result = tf.ref_to_physical(random_xi, random_eta);
		const auto xp = result.first;
		const auto yp = result.second;

		auto xi = 0.0;
		auto eta = 0.0;
		quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);

		EXPECT_NEAR(xi, random_xi, epsilon) << "quadratic formula \n";
		EXPECT_NEAR(eta, random_eta, epsilon) << "quadratic formula \n";
	}
}
TEST(quadratic_formula, random_test3)
{
	const double x1 = 1.0021304, x2 = 0.0000043, x3 = 5.7546341, x4 = 5.345634543;
	const double y1 = 0.00123402, y2 = 5.123444432, y3 = 5.09123423, y4 = -1.001902312;

	transformation_function tf({ x1,x2,x3,x4 }, { y1,y2,y3,y4 });

	constexpr auto iter = 10000;

	for (size_t i = 0; i < iter; i++)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dis(-1, 1);

		const auto random_xi = dis(gen);
		const auto random_eta = dis(gen);

		const auto result = tf.ref_to_physical(random_xi, random_eta);
		const auto xp = result.first;
		const auto yp = result.second;

		auto xi = 0.0;
		auto eta = 0.0;
		quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);

		EXPECT_NEAR(xi, random_xi, epsilon) << "quadratic formula \n";
		EXPECT_NEAR(eta, random_eta, epsilon) << "quadratic formula \n";
	}
}