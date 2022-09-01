#include "Çì´õ.h"

bool is_in_reference_domain(const double xi)
{
	constexpr auto epsilon = 1.0e-10;
	if (xi < -(1.0 + epsilon) || xi > 1.0 + epsilon)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void quadratic_formula(double & xi, double & eta, const double xp, const double yp,
	const double x1, const double x2, const double x3, const double x4, const double y1, const double y2, const double y3, const double y4)
{
	//f1	= shape_function1*x1 + ... + shape_function4*x4 - xp
	//		= a_0 + a_1 * xi + a_2 * eta + a_3 * xi*eta;
	const auto a_0 = 0.25 * (x1 + x2 + x3 + x4) - xp;
	const auto a_1 = 0.25 * (-x1 + x2 + x3 - x4);
	const auto a_2 = 0.25 * (-x1 - x2 + x3 + x4);
	const auto a_3 = 0.25 * (x1 - x2 + x3 - x4);

	//f2	= shape_function1*y1 + ... + shape_function4*y4 - yp
	//		= b_0 + b_1 * xi + b_2 * eta + b_3 * xi*eta;
	const auto b_0 = 0.25 * (y1 + y2 + y3 + y4) - yp;
	const auto b_1 = 0.25 * (-y1 + y2 + y3 - y4);
	const auto b_2 = 0.25 * (-y1 - y2 + y3 + y4);
	const auto b_3 = 0.25 * (y1 - y2 + y3 - y4);

	//a xi^2 + b xi + c = 0
	const auto a = a_1 * b_3 - a_3 * b_1;
	const auto b = a_1 * b_2 - a_2 * b_1 + a_0 * b_3 - a_3 * b_0;
	const auto c = a_0 * b_2 - a_2 * b_0;

	if (a == 0)
	{
		xi = -c / b;

		if (a_2 + a_3 * xi == 0)
		{
			eta = -(b_0 + b_1 * xi) / (b_2 + b_3 * xi);
		}
		else
		{
			eta = -(a_0 + a_1 * xi) / (a_2 + a_3 * xi);
		}

		return;
	}

	const auto discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		std::cout << "Negative discriminant Bug! \n";
		return;
	}

	const auto temp1 = std::sqrt(discriminant);
	const auto temp2 = 1.0 / (2 * a);

	const auto xi_1 = (-b + temp1) * temp2;
	const auto xi_2 = (-b - temp1) * temp2;

	if (is_in_reference_domain(xi_1))
	{
		xi = xi_1;
		if (a_2 + a_3 * xi_1 == 0)
		{
			eta = -(b_0 + b_1 * xi_1) / (b_2 + b_3 * xi_1);
		}
		else
		{
			eta = -(a_0 + a_1 * xi_1) / (a_2 + a_3 * xi_1);
		}
	}
	else if (is_in_reference_domain(xi_2))
	{
		xi = xi_2;
		if (a_2 + a_3 * xi_2 == 0)
		{
			eta = -(b_0 + b_1 * xi_2) / (b_2 + b_3 * xi_2);
		}
		else
		{
			eta = -(a_0 + a_1 * xi_2) / (a_2 + a_3 * xi_2);
		}
	}
	else
	{
		std::cout << "xp : " << xp << "\n";
		std::cout << "yp : " << yp << "\n";
		throw std::runtime_error("Out of range Bug!\n");
	}
}

void newton_method(double & xi, double & eta, const double xp, const double yp,
	const double x1, const double x2, const double x3, const double x4, const double y1, const double y2, const double y3, const double y4)
{
	//f1 = a_0 + a_1 * xi + a_2 * eta + a_3 * xi*eta;
	//f2 = b_0 + b_1 * xi + b_2 * eta + b_3 * xi*eta;

	const auto a_0 = 0.25 * (x1 + x2 + x3 + x4) - xp;
	const auto a_1 = 0.25 * (-x1 + x2 + x3 - x4);
	const auto a_2 = 0.25 * (-x1 - x2 + x3 + x4);
	const auto a_3 = 0.25 * (x1 - x2 + x3 - x4);

	const auto b_0 = 0.25 * (y1 + y2 + y3 + y4) - yp;
	const auto b_1 = 0.25 * (-y1 + y2 + y3 - y4);
	const auto b_2 = 0.25 * (-y1 - y2 + y3 + y4);
	const auto b_3 = 0.25 * (y1 - y2 + y3 - y4);

	constexpr auto convergence_criterion = 1.0e-13;
	constexpr auto iteration_limit = 1000;
	xi = 0.5;
	eta = 0.5;

	auto iter = 0;
	while (true)
	{
		const auto f1 = a_0 + a_1 * xi + a_2 * eta + a_3 * xi*eta;
		const auto f2 = b_0 + b_1 * xi + b_2 * eta + b_3 * xi*eta;

		const auto residual = std::sqrt(f1 * f1 + f2 * f2);
		if (residual < convergence_criterion)
		{
			return;
		}
		else
		{
			iter++;
			if (iteration_limit < iter)
			{
				return;
			}
		}

		const auto J_11 = a_1 + a_3 * eta;
		const auto J_12 = a_2 + a_3 * xi;
		const auto J_21 = b_1 + b_3 * eta;
		const auto J_22 = b_2 + b_3 * xi;

		const auto det = J_11 * J_22 - J_12 * J_21;
		if (det == 0)
		{
			std::cout << "xp : " << xp << "\n";
			std::cout << "yp : " << yp << "\n";
			std::cout << "Zero determinant Bug! \n";
			std::exit(523);
			return;
		}

		const auto temp = 1.0 / det;
		xi = xi - temp * (J_22 * f1 - J_12 * f2);
		eta = eta - temp * (-J_21 * f1 + J_11 * f2);
	}
}

