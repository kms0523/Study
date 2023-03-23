#include "gtest/gtest.h"
#include "../TestProject/mec/MecDenseMatrix.h"

template <typename T>
void print(const Mec::DenseMatrix<T>& m)
{
	const auto num_rows = m.rows();
	const auto num_cols = m.columns();

	for (int i = 0; i < num_rows; ++i)
	{
		for (int j = 0; j < num_cols; ++j)
		{
			std::cout << m(i, j) << " ";
		}
		std::cout << "\n";
	}
}

template <typename T>
void expect_equal(const Mec::DenseMatrix<T>& m1, const Mec::DenseMatrix<T>& m2)
{
	EXPECT_EQ(m1.rows(), m2.rows());
	EXPECT_EQ(m1.columns(), m2.columns());

	const auto num_rows = m1.rows();
	const auto num_cols = m2.columns();

	for (int i = 0; i < num_rows; ++i)
	{
		for (int j = 0; j < num_cols; ++j)
		{
			EXPECT_EQ(m1(i, j), m2(i, j));
		}
	}
}

using Matrix = Mec::DenseMatrix<double>;


// Dense Matrix는 component wise mulitplication밖에 안된다.
TEST(Test, muliplication1)
{
	Matrix matrix;
	matrix.resize(2, 2);
	matrix = 1, 2, 1, 2;

	Matrix matrix2;
	matrix2.resize(2, 2);
	matrix2 = 2, 1, 2, 1;

	Matrix matrix3;
	matrix3 = matrix * matrix2;

	Matrix ref;
	ref.resize(2, 2);
	ref = 2, 2, 2, 2;

	expect_equal(ref, matrix3);
}
TEST(Test, muliplication2)
{
	Matrix matrix;
	matrix.resize(2, 2);
	matrix = 1, 2, 1, 2;

	Matrix matrix2;
	matrix2.resize(2, 2);
	matrix2 = 2, 1, 2, 1;

	matrix *= matrix2;

	Matrix ref;
	ref.resize(2, 2);
	ref = 2, 2, 2, 2;

	expect_equal(ref, matrix);
}
TEST(Test, muliplication3)
{
	Matrix matrix;
	matrix.resize(2, 2);
	matrix = 1, 2, 1, 2;

	Matrix matrix2;
	matrix2.resize(2, 2);
	matrix2 = 2, 1, 2, 1;

	auto m = matrix * matrix2;
	auto m2 = m * matrix;
	auto m3 = m * m2;

	Matrix matrix3;
	matrix3 = m3;

	print(matrix3);

	//Matrix ref;
	//ref.resize(2, 2);
	//ref = 2, 2, 2, 2;

	//expect_equal(ref, matrix3);
}


//TEST(Test, muliplication3)
//{
//	Matrix matrix;
//	matrix.resize(1, 2);
//	matrix = 1, 2;
//
//	Matrix matrix2;
//	matrix2.resize(2, 1);
//	matrix2 = 2, 1;
//}

//TEST(Test, vector_push_back)
//{
//	Matrix matrix;
//	matrix.resize(3, 3);
//	matrix = 1,2,3,1,2,3,1,2,3;
//
//	blitz::Range r1(0, 1);
//
//	std::vector<Matrix> mat_vec;
//	{
//		for (int i =0; i < 3; ++i)
//		  mat_vec.push_back(matrix(r1, r1));
//	}
//
//	for (const auto& m : mat_vec)
//	{
//		print(m);
//	}
//}


