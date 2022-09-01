#include "pch.h"
#include "../Test/Çì´õ.h"

#include <random>
#include <vector>
#include <utility>

static constexpr auto epsilon = 9.0e-8;

class Edge_point_generator
{
public:
	Edge_point_generator(const std::vector<double>& x_coordinates, const std::vector<double>& y_coordinates)
		: x_coordinates_(x_coordinates)
		, y_coordinates_(y_coordinates) {};

public:
	std::vector<std::vector<std::pair<double,double>>> generate_line_index_to_edge_points(const size_t num_division) const
	{
		constexpr auto num_line = 4;
		std::vector<std::vector<std::pair<double, double>>> line_index_to_edge_points(num_line);
		
		for (size_t i = 0; i < num_line; i++)
		{			
			auto& edge_points = line_index_to_edge_points[i];

			const auto num_points = num_division + 1;
			edge_points.resize(num_points);
			
			const auto next_point_index = (i + 1) % 4;
			const auto x_diff = x_coordinates_[next_point_index] - x_coordinates_[i];
			const auto y_diff = y_coordinates_[next_point_index] - y_coordinates_[i];

			constexpr auto epsilon = 1.0e-13;
			if (std::abs(x_diff) < epsilon)
			{
				const auto delta_y = y_diff / num_division;

				for (size_t j = 0; j <= num_division; j++)
				{
					const auto x_j = x_coordinates_[i];
					const auto y_j = y_coordinates_[i] + delta_y * j;

					edge_points[j] = { x_j,y_j };
				}
			}
			else
			{
				const auto delta_x = x_diff / num_division;
				const auto slope = y_diff / x_diff;
				for (size_t j = 0; j <= num_division; j++)
				{
					const auto x_j = x_coordinates_[i] + delta_x * j;
					const auto y_j = slope * (x_j - x_coordinates_[i]) + y_coordinates_[i];

					edge_points[j] = { x_j,y_j };
				}
			}
		}

		return line_index_to_edge_points;
	}

private:
	std::vector<double> x_coordinates_;
	std::vector<double> y_coordinates_;
};


TEST(quadratic_formula, edge_test1)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;
	
	Edge_point_generator generator({ x1,x2,x3,x4 }, { y1,y2,y3,y4 });

	constexpr auto num_division_per_edge = 1000;
	const auto line_index_to_edge_points = generator.generate_line_index_to_edge_points(num_division_per_edge);

	constexpr auto delta = 2.0 / num_division_per_edge;
	const auto num_points = num_division_per_edge + 1;


	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[0][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;
		quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);

		const auto ref_xi = -1 + delta * i;
		const auto ref_eta = -1;

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}

	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[2][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;
		quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);

		const auto ref_xi = 1 - delta * i;
		const auto ref_eta = 1;

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}

	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[1][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;
		quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);

		const auto ref_xi = 1;
		const auto ref_eta = -1 + delta * i;

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}

	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[3][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;
		quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);

		const auto ref_xi = -1;
		const auto ref_eta = 1 - delta * i;

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}
}


TEST(quadratic_formula, edge_test2)
{
	const double x1 = 1, x2 = 0, x3 = 50000, x4 = 2;
	const double y1 = 0, y2 = 5, y3 = 50000, y4 = -1;

	Edge_point_generator generator({ x1,x2,x3,x4 }, { y1,y2,y3,y4 });

	constexpr auto num_division_per_edge = 100;
	const auto line_index_to_edge_points = generator.generate_line_index_to_edge_points(num_division_per_edge);

	
	constexpr auto delta = 2.0 / num_division_per_edge;
	const auto num_points = num_division_per_edge + 1;


	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[0][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;

		const auto ref_xi = -1 + delta * i;
		const auto ref_eta = -1;

		try
		{
			quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
		}
		catch (...)
		{
			std::cout << "ref_xi : " << ref_xi << "\n";
			std::cout << "ref_eta : " << ref_eta << "\n";
			exit(523);
		}

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}

	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[2][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;
		
		const auto ref_xi = 1 - delta * i;
		const auto ref_eta = 1;

		try
		{
			quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
		}
		catch (...)
		{
			std::cout << "ref_xi : " << ref_xi << "\n";
			std::cout << "ref_eta : " << ref_eta << "\n";
			exit(523);
		}

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}

	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[1][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;
		
		const auto ref_xi = 1;
		const auto ref_eta = -1 + delta * i;

		try
		{
			quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
		}
		catch (...)
		{
			std::cout << "ref_xi : " << ref_xi << "\n";
			std::cout << "ref_eta : " << ref_eta << "\n";
			exit(523);
		}

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}

	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[3][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;
		
		const auto ref_xi = -1;
		const auto ref_eta = 1 - delta * i;

		try
		{
			quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
		}
		catch (...)
		{
			std::cout << "ref_xi : " << ref_xi << "\n";
			std::cout << "ref_eta : " << ref_eta << "\n";
			exit(523);
		}

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}
}


TEST(newton_method, edge_test2)
{
	const double x1 = 1, x2 = 0, x3 = 50000, x4 = 2;
	const double y1 = 0, y2 = 5, y3 = 50000, y4 = -1;

	Edge_point_generator generator({ x1,x2,x3,x4 }, { y1,y2,y3,y4 });

	constexpr auto num_division_per_edge = 100;
	const auto line_index_to_edge_points = generator.generate_line_index_to_edge_points(num_division_per_edge);

	
	constexpr auto delta = 2.0 / num_division_per_edge;
	const auto num_points = num_division_per_edge + 1;


	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[0][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;

		const auto ref_xi = -1 + delta * i;
		const auto ref_eta = -1;

		try
		{
			quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
		}
		catch (...)
		{
			std::cout << "ref_xi : " << ref_xi << "\n";
			std::cout << "ref_eta : " << ref_eta << "\n";
			exit(523);
		}

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}

	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[2][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;

		const auto ref_xi = 1 - delta * i;
		const auto ref_eta = 1;

		try
		{
			quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
		}
		catch (...)
		{
			std::cout << "ref_xi : " << ref_xi << "\n";
			std::cout << "ref_eta : " << ref_eta << "\n";
			exit(523);
		}

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}

	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[1][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;

		const auto ref_xi = 1;
		const auto ref_eta = -1 + delta * i;

		try
		{
			quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
		}
		catch (...)
		{
			std::cout << "ref_xi : " << ref_xi << "\n";
			std::cout << "ref_eta : " << ref_eta << "\n";
			exit(523);
		}

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}

	for (size_t i = 0; i < num_points; i++)
	{
		const auto& edge_point = line_index_to_edge_points[3][i];
		const auto xp = edge_point.first;
		const auto yp = edge_point.second;

		auto xi = 0.0;
		auto eta = 0.0;

		const auto ref_xi = -1;
		const auto ref_eta = 1 - delta * i;

		try
		{
			quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
		}
		catch (...)
		{
			std::cout << "ref_xi : " << ref_xi << "\n";
			std::cout << "ref_eta : " << ref_eta << "\n";
			exit(523);
		}

		EXPECT_NEAR(xi, ref_xi, epsilon);
		EXPECT_NEAR(eta, ref_eta, epsilon);
	}
}

