#include "pch.h"
#include "../Test/Çì´õ.h"

static constexpr auto epsilon = 9.0e-8;

TEST(quadratic_formula, Test1)
{
	const double x1 = 0, x2 = 5, x3 = 5, x4 = 1;
	const double y1 = 5, y2 = 5, y3 = -1, y4 = 0;	
	const double xp = 0;
	const double yp = 5;

	double xi = 0, eta = 0; 
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(quadratic_formula, Test2)
{
	const double x1 = 0, x2 = 5, x3 = 5, x4 = 1;
	const double y1 = 5, y2 = 5, y3 = -1, y4 = 0;
	const double xp = 5;
	const double yp = 5;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, 1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(quadratic_formula, Test3)
{
	const double x1 = 0, x2 = 5, x3 = 5, x4 = 1;
	const double y1 = 5, y2 = 5, y3 = -1, y4 = 0;
	const double xp = 5;
	const double yp = -1;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, 1.0, epsilon);
	EXPECT_NEAR(eta, 1.0, epsilon);
}
TEST(quadratic_formula, Test4)
{
	const double x1 = 0, x2 = 5, x3 = 5, x4 = 1;
	const double y1 = 5, y2 = 5, y3 = -1, y4 = 0;
	const double xp = 1;
	const double yp = 0;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, 1.0, epsilon);
}
TEST(quadratic_formula, Test5)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;
	const double xp = 1;
	const double yp = 0;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(quadratic_formula, Test6)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;
	const double xp = 0;
	const double yp = 5;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, 1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(quadratic_formula, Test7)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;
	const double xp = 5;
	const double yp = 5;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, 1.0, epsilon);
	EXPECT_NEAR(eta, 1.0, epsilon);
}
TEST(quadratic_formula, Test8)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;
	const double xp = 5;
	const double yp = -1;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, 1.0, epsilon);
}
TEST(quadratic_formula, Test9)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 6;
	const double y1 = -1, y2 = 5, y3 = 5, y4 = -1;
	const double xp = 1;
	const double yp = -1;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(quadratic_formula, Test10)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1.1;
	const double xp = 1;
	const double yp = 0;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(quadratic_formula, Test11)
{
	const double x1 = 1, x2 = 0, x3 = 5.123424, x4 = 5.12311;
	const double y1 = 0, y2 = 5, y3 = 5.00000000001, y4 = -1.000001;
	const double xp = 1;
	const double yp = 0;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(quadratic_formula, Test12)
{
	const double x1 = 1, x2 = 0, x3 = 50000, x4 = 2;
	const double y1 = 0, y2 = 5, y3 = 50000, y4 = -1;
	const double xp = 500;
	const double yp = 504.95;

	double xi = 0, eta = 0;
	quadratic_formula(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, 1, epsilon);
	EXPECT_NEAR(eta, -0.98, epsilon);
}




TEST(newton_method, Test1)
{
	const double x1 = 0, x2 = 5, x3 = 5, x4 = 1;
	const double y1 = 5, y2 = 5, y3 = -1, y4 = 0;
	const double xp = 0;
	const double yp = 5;

	double xi = 0, eta = 0;
	newton_method(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(newton_method, Test2)
{
	const double x1 = 0, x2 = 5, x3 = 5, x4 = 1;
	const double y1 = 5, y2 = 5, y3 = -1, y4 = 0;
	const double xp = 5;
	const double yp = 5;

	double xi = 0, eta = 0;
	newton_method(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, 1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(newton_method, Test3)
{
	const double x1 = 0, x2 = 5, x3 = 5, x4 = 1;
	const double y1 = 5, y2 = 5, y3 = -1, y4 = 0;
	const double xp = 5;
	const double yp = -1;

	double xi = 0, eta = 0;
	newton_method(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, 1.0, epsilon);
	EXPECT_NEAR(eta, 1.0, epsilon);
}
TEST(newton_method, Test4)
{
	const double x1 = 0, x2 = 5, x3 = 5, x4 = 1;
	const double y1 = 5, y2 = 5, y3 = -1, y4 = 0;
	const double xp = 1;
	const double yp = 0;

	double xi = 0, eta = 0;
	newton_method(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, 1.0, epsilon);
}
TEST(newton_method, Test5)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;
	const double xp = 1;
	const double yp = 0;

	double xi = 0, eta = 0;
	newton_method(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(newton_method, Test6)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;
	const double xp = 0;
	const double yp = 5;

	double xi = 0, eta = 0;
	newton_method(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, 1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(newton_method, Test7)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;
	const double xp = 5;
	const double yp = 5;

	double xi = 0, eta = 0;
	newton_method(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, 1.0, epsilon);
	EXPECT_NEAR(eta, 1.0, epsilon);
}
TEST(newton_method, Test8)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1;
	const double xp = 5;
	const double yp = -1;

	double xi = 0, eta = 0;
	newton_method(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, 1.0, epsilon);
}
TEST(newton_method, Test9)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 6;
	const double y1 = -1, y2 = 5, y3 = 5, y4 = -1;
	const double xp = 1;
	const double yp = -1;

	double xi = 0, eta = 0;
	newton_method(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}
TEST(newton_method, Test10)
{
	const double x1 = 1, x2 = 0, x3 = 5, x4 = 5;
	const double y1 = 0, y2 = 5, y3 = 5, y4 = -1.1;
	const double xp = 1;
	const double yp = 0;

	double xi = 0, eta = 0;
	newton_method(xi, eta, xp, yp, x1, x2, x3, x4, y1, y2, y3, y4);
	EXPECT_NEAR(xi, -1.0, epsilon);
	EXPECT_NEAR(eta, -1.0, epsilon);
}