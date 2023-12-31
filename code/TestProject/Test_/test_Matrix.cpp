#include "../TestProject/mec/MecDenseMatrix.h"
//#include "../TestProject/mec/MecTinyMatrix.h"
#include "gtest/gtest.h"

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

template <typename T1, typename T2>
void expect_equal(const Mec::DenseMatrix<T1>& m1, const Mec::DenseMatrix<T2>& m2)
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
void expect_equal(const Mec::RealVector& m1, const Mec::RealVector& m2)
{
  EXPECT_EQ(m1.size(), m2.size());

  const auto num_rows = m1.size();

  for (int i = 0; i < num_rows; ++i)
  {
    EXPECT_EQ(m1(i), m2(i));
  }
}

using Matrix  = Mec::DenseMatrix<double>;
using fMatrix = Mec::DenseMatrix<float>;

TEST(test, begin_end)
{
  Matrix mat(4, 1);
  mat = 1, 2, 1, 1;

  for (const auto val : mat)
  {
    std::cout << val;
  }
}
TEST(test, range)
{
  Matrix mat(2, 2);
  mat = 1, 2, 1, 1;

  Matrix m1 = mat(blitz::Range::all(), blitz::Range(0, 0));
  Matrix ref(2, 1);
  ref = 1, 2;

  expect_equal(m1, ref);
}
TEST(test, range2)
{
  Mec::Real3x3Matrix mat;
  mat = 1., 0., 0., 0., -1., 0., 0., 0., 1.;

  const Mec::RealVector v1 = mat(1, blitz::Range(0, 2));

  Mec::RealVector3 ref;
  ref = 0., -1., 0.;
  expect_equal(ref, v1);
}

TEST(Matrix, comma_operator)
{
  Matrix mat(2, 2);
  mat = 1, 2, 3, 4;

  //column major matrix
  Matrix ref(2, 2);
  ref(0, 0) = 1;
  ref(0, 1) = 3;
  ref(1, 0) = 2;
  ref(1, 1) = 4;

  expect_equal(mat, ref);
}

//// Dense Matrix는 component wise mulitplication밖에 안된다.
//TEST(Test, muliplication1)
//{
//	Matrix matrix;
//	matrix.resize(2, 2);
//	matrix = 1, 2, 1, 2;
//
//	Matrix matrix2;
//	matrix2.resize(2, 2);
//	matrix2 = 2, 1, 2, 1;
//
//	Matrix matrix3;
//	matrix3 = matrix * matrix2;
//
//	Matrix ref;
//	ref.resize(2, 2);
//	ref = 2, 2, 2, 2;
//
//	expect_equal(ref, matrix3);
//}
//TEST(Test, muliplication2)
//{
//	Matrix matrix;
//	matrix.resize(2, 2);
//	matrix = 1, 2, 1, 2;
//
//	Matrix matrix2;
//	matrix2.resize(2, 2);
//	matrix2 = 2, 1, 2, 1;
//
//	matrix *= matrix2;
//
//	Matrix ref;
//	ref.resize(2, 2);
//	ref = 2, 2, 2, 2;
//
//	expect_equal(ref, matrix);
//}

//// Vector = Vector 할 때 data type이 다르면 stride가 고려되지 않는 버그가 있다.
//TEST(Test, copy)
//{
//	Matrix matrix;
//	matrix.resize(2, 3);
//	matrix = 1, 2,3,4, 5, 6;
//
//	fMatrix matrix2;
//	matrix2.resize(1, 3);
//
//	const auto rall = blitz::Range::all();
//	matrix2(0, rall) = matrix(1, rall);
//
//	print(matrix2);
//
//	//Matrix ref;
//	//ref.resize(1, 3);
//	//ref = 2,4,6;
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
//
//
