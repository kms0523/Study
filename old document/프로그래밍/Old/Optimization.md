- [MKL-VM](#mkl-vm)
	- [vdAbs](#vdabs)
		- [Comment](#comment)
- [vector array push_back vs copy](#vector-array-push_back-vs-copy)
	- [comment](#comment-1)
- [copy vs jump](#copy-vs-jump)
	- [Comment](#comment-2)
- [MKL_BLAS](#mkl_blas)
	- [Leve1](#leve1)
		- [dcopy](#dcopy)
			- [Comment](#comment-3)
		- [dasum](#dasum)
			- [Comment](#comment-4)
	- [ddot](#ddot)
		- [Comment](#comment-5)
	- [Mat(Vec) + Mat(Vec)](#matvec--matvec)
		- [comment](#comment-6)
	- [Mat(Vec) Scalar multiplication](#matvec-scalar-multiplication)
		- [comment](#comment-7)
	- [Mat $\times$ Vec](#mat-times-vec)
		- [comment](#comment-8)
	- [Mat Mat multiplication](#mat-mat-multiplication)
		- [comment](#comment-9)
- [SFINAE vs if constexpr](#sfinae-vs-if-constexpr)
	- [comment](#comment-10)
- [For loop](#for-loop)
	- [one for vs multiple for version1](#one-for-vs-multiple-for-version1)
	- [one for vs multiple for version2](#one-for-vs-multiple-for-version2)
		- [comment](#comment-11)
	- [for with unsigned and signed](#for-with-unsigned-and-signed)
		- [comment](#comment-12)


# MKL-VM
## vdAbs
```cpp
int main(void) {
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 10000000;

	constexpr size_t num_value = 100;
	constexpr double value = -0.00000001;


	for (size_t c = 0; c < num_case; ++c) {
		std::vector<double> v1(num_value, value);
		std::cout << "normal \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			for (size_t j = 0; j < num_value; ++j)
				v1[j] = std::abs(v1[j]);
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";
	}


	for (size_t c = 0; c < num_case; ++c) {
		std::vector<double> v2(num_value, value);
		std::cout << "VM \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i)
			vdAbs(num_value, v2.data(), v2.data());
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";
	}	
}
```
### Comment
200 $\le$ num_value : VM 

# vector array push_back vs copy
``` cpp
int main(void) {
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 100000000;
	constexpr size_t num_value = 10;

	std::array<double, num_value> ar;
	ar.fill(num_value);


	std::vector<std::array<double, num_value>> v1(num_iter);
	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "대입 \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) 
				v1[i] = ar;		
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << v1[num_case][num_case] << "\n";
	}


	std::vector<std::array<double, num_value>> v2;
	v2.reserve(num_iter);

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "push back \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i)
			v2.push_back(ar);
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << v2[num_case][num_case] << "\n";
		v2.clear();
	}
}
```
## comment
1. 비슷비슷하나 push_back이 첫 iter가 많이 걸림
# copy vs jump
``` cpp
int main(void){
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 100;
	constexpr size_t num_value = 1000;

	std::vector<double> v1(num_value);	

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "copy \t";
		double result1 = 0;
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			for (size_t j = 0; j < num_value; ++j)
				v1[j] = num_case;
		}
		const auto v2 = v1;
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << v2[num_case] << "\n";
	}

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "jump \t";
		RECORD_CONSUMED_TIME;
		std::vector<double> v2(num_value);
		for (size_t i = 0; i < num_iter; ++i) {
			for (size_t j = 0; j < num_value; ++j) {
				v1[j] = num_case;
				v2[j] = num_case;
			}
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << v2[num_case] << "\n";
	}
}
```
## Comment
1. copy 압승
2. num_value가 증가할수록 차이는 더 심하게 벌어짐

# MKL_BLAS

## Leve1
### dcopy
```cpp
int main(void) {
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 10000000;
	constexpr size_t num_value = 50;
	constexpr double value = 0.00000001;

	std::vector<double> v1(num_value, value);
	std::vector<double> v2(num_value);

	for (size_t c = 0; c < num_case; ++c) 
	{
		std::cout << "normal \t";
		Profiler::set_time_point();
		for (size_t i = 0; i < num_iter; ++i) 
		{
			for (size_t j = 0; j < num_value; ++j)
			{
				v1[j] = v2[j];
			}
					
		}		
		std::cout << Profiler::get_time_duration() << "s\n";
	}

	std::vector<double> v3(num_value, value);
	std::vector<double> v4(num_value);

	for (size_t c = 0; c < num_case; ++c) 
	{
		std::cout << "blas \t";
		Profiler::set_time_point();
		for (size_t i = 0; i < num_iter; ++i)
		{
			cblas_dcopy(num_value, v3.data(), 1, v4.data(), 1);
		}
		std::cout << Profiler::get_time_duration() << "s\n";
	}

	std::cout << v2[0] << "\t" << v4[0] << "\n";
}
```
#### Comment
1. num value $<$ 50 : normal
2. 50 $\le$ num value : blas 

### dasum
```cpp
int main(void)
{
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 1000000;

	constexpr size_t num_value = 10;
	std::vector<double> v1(num_value, -11);

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "no blas \t";
		double result1 = 0;
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			for (size_t j = 0; j < num_value; ++j)
				result1 += std::abs(v1[j]);
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << result1 << "\n";
	}

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "blas      \t";
		double result2 = 0;
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			const MKL_INT n = static_cast<int>(v1.size());
			const MKL_INT incx = 1;
			result2 += cblas_dasum(n, v1.data(), incx);
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << result2 << "\n";
	}
}
```
#### Comment
$$ \begin{aligned}
\text{num value} < 10 \quad &  \text{no blas} \\
10 \le \text{num value} \quad & \text{blas}
\end{aligned} $$

## ddot
```cpp
int main(void)
{
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 1000000;
	
	constexpr size_t num_value = 100;
	std::vector<double> v1(num_value, 1);
	std::vector<double> v2(num_value, 1);

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "no blas \t";
		double result1 = 0;
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			for (size_t j = 0; j < num_value; ++j)
				result1 += v1[j] * v2[j];
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << result1 << "\n";
	}

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "blas      \t";
		double result2 = 0;
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			const MKL_INT n = static_cast<int>(v1.size());
			const MKL_INT incx = 1;
			const MKL_INT incy = 1;
			result2 += cblas_ddot(n, v1.data(), incx, v2.data(), incy);
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << result2 << "\n";
	}
}
```
### Comment
$$ \begin{aligned}
\text{num value} \le 5 \quad &  \text{no blas} \\
5 \le \text{num value} \le 15 \quad &  \approx \\
15 \le \text{num value} \quad & \text{blas}
\end{aligned} $$


## Mat(Vec) + Mat(Vec)
``` cpp
int main(void) {
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 10000000;

	constexpr size_t num_row = 5;
	constexpr size_t num_column = 5;
	constexpr double value = 0.00000001;

	std::vector<double> v1(num_row * num_column, value);
	std::vector<double> v2(num_row * num_column, value);

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "normal \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			for (size_t j = 0; j < num_row; ++j)
				for (size_t k = 0; k < num_column; ++k)
					v1[j * num_column + k] += v2[j * num_column + k];
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";
	}

	std::vector<double> v3(num_row * num_column, value);
	std::vector<double> v4(num_row * num_column, value);

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "blas \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i)
			cblas_daxpy(num_row * num_column, 1.0, v4.data(), 1, v3.data(),1);
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";
	}

	std::cout << v1[0] << "\t" << v3[0] << "\n";
}
```
### comment
Heuristic
1. num value $<$ 20 : normal
2. 20 $\le$ num value : blas 

## Mat(Vec) Scalar multiplication
```cpp
int main(void) {
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 10000000;

	constexpr size_t num_row = 10;
	constexpr size_t num_column = 1;
	constexpr double value = 0.9999999;

	std::vector<double> v1(num_row * num_column, value);
	std::vector<double> v2(num_row * num_column, value);

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "normal \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			for (size_t j = 0; j < num_row; ++j)
				for (size_t k = 0; k < num_column; ++k)
					v1[j * num_column + k] *= value;
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";		
	}

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "blas \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i)
			cblas_dscal(num_row * num_column, value, v2.data(), 1);
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";
	}

	std::cout << v1[0] << "\t" <<  v2[0] << "\n";
}
```
### comment
Heuristic
1. num value $<$ 10 : normal
2. 10 $\le$ num value : blas 

## Mat $\times$ Vec
``` cpp
int main(void) {
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 1000000;

	constexpr size_t num_row = 16;
	constexpr size_t num_column = 8;
	constexpr size_t value = 10;

	std::vector<double> v1(num_row * num_column, value);
	std::vector<double> v2(num_column, value);
	std::vector<double> v3(num_row);
	std::vector<double> v4(num_row);

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "normal \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			for (size_t j = 0; j < num_row; ++j)
				for (size_t k = 0; k < num_column; ++k)
					v3[j] += v1[j * num_column + k] * v2[k];
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" <<  "\n";
	}

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "blas \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i)
			cblas_dgemv(CBLAS_LAYOUT::CblasRowMajor, CBLAS_TRANSPOSE::CblasNoTrans, num_row, num_column, 1.0, v1.data(), num_column, v2.data(), 1, 0.0, v4.data(), 1);
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";
	}
}
```
### comment
Heuristic
1. num value $<$ 50 : normal
2. 50 $\le$ num value : blas 

## Mat Mat multiplication
```cpp
int main(void) {
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 100000;

	constexpr size_t m = 8;
	constexpr size_t k = 8;
	constexpr size_t n = 4;
	constexpr size_t value = 10;

	std::vector<double> v1(m * k, value);
	std::vector<double> v2(k * n, value);
	std::vector<double> v3(m*n);
	std::vector<double> v4(m*n);

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "normal \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			for (size_t a = 0; a < m; ++a)
				for (size_t b = 0; b < n; ++b)
					for (size_t c = 0; c < k; ++c)
						v3[a * n + b] += v1[a * k + c] * v2[c * n + b];
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";
	}

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "blas \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i)
			cblas_dgemm(CBLAS_LAYOUT::CblasRowMajor, CBLAS_TRANSPOSE::CblasNoTrans, CBLAS_TRANSPOSE::CblasNoTrans,
				m, n, k, 1.0, v1.data(), k, v2.data(), n, 0.0, v4.data(), n);
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";
	}

	//std::cout << std::boolalpha;
	//std::cout << (v3 == v4);
}
```
### comment
Heuristic
1. max num value $<$ 25 : normal
2. 25 $\le$ max num value : blas


# SFINAE vs if constexpr
``` cpp
template <size_t N>
void func1(void) {
	if constexpr (N < 10)
		std::vector<double> v(1000, 1000);
	else
		std::cout << "Not";
}

template <size_t N, std::enable_if_t< (N <10), bool> = true >
void func2(void) {
	std::vector<double> v(1000, 1000);
}
template <size_t N, std::enable_if_t< (10 < N), bool> = true >
void func2(void) {
	std::cout << "Not";
}

int main(void) {
	constexpr size_t num_case = 5;
	constexpr size_t num_iter = 1000000;

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "SFINAE \t\t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			func2<5>();
			func2<1>();
			func2<7>();
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";
	}

	for (size_t c = 0; c < num_case; ++c) {
		std::cout << "if constexpr \t";
		RECORD_CONSUMED_TIME;
		for (size_t i = 0; i < num_iter; ++i) {
			func1<5>();
			func1<8>();
			func1<3>();
		}
		PRINT_CONSUMED_TIME;
		std::cout << "\t" << "\n";
	}
}
```
## comment
No meaningful difference.

https://stackoverflow.com/questions/40972666/constexpr-if-vs-if-with-optimizations-why-is-constexpr-needed

# For loop
## one for vs multiple for version1
```cpp
int main(void) {
	constexpr auto case_iter = 5;
	constexpr auto iter = 100000000;

	std::cout << "multi for \n";
	for (size_t c=0; c<case_iter; ++c)
	{
		RECORD_CONSUMED_TIME;

		double result1 = 0;
		for (size_t i = 0; i < iter; ++i)
			result1 += i;

		double result2 = 0;
		for (size_t i = 0; i < iter; ++i)
			result2 += i;

		double result3 = 0;
		for (size_t i = 0; i < iter; ++i)
			result3 += i;

		PRINT_CONSUMED_TIME;
		std::cout << "\n";
		std::cout << result1 << result2 << result3;
		std::cout << "\n";

	}
	
	std::cout << "1 for \n";
	for (size_t c = 0; c < case_iter; ++c)
	{
		RECORD_CONSUMED_TIME;

		double result1 = 0;
		double result2 = 0;
		double result3 = 0;

		for (size_t i = 0; i < iter; ++i) {
			result1 += i;
			result2 += i;
			result3 += i;
		}

		PRINT_CONSUMED_TIME;
		std::cout << "\n";

		std::cout << result1 << result2 << result3;
		std::cout << "\n";

	}
}
```

## one for vs multiple for version2
``` cpp
constexpr auto case_iter = 5;
constexpr auto iter = 10000;
constexpr auto num_value = 100000;

double test1(void) 
{
	return 0.03;
}
double test2(void)
{
	return 0.02;
}
std::vector<double> test3(void)
{	
	return std::vector<double>(num_value, 0.03);
}
std::vector<double> test4(void)
{
	return std::vector<double>(num_value, 0.02);
}

int main(void) {
	std::cout << "multi for \n";
	for (size_t c = 0; c < case_iter; ++c)
	{
		double dummy = 0.0;
		SET_TIME_POINT;
		for (int i = 0; i < iter; ++i)
		{
			const auto values1 = test3();
			const auto values2 = test4();
			for (size_t i = 0; i < num_value; ++i)
			{
				dummy += values1[i] + values2[i];
			}
		}

		std::cout << "conssumed time : " << GET_TIME_DURATION << "\n";
		std::cout << "dummy : " << dummy << "\n";
	}

	std::cout << "1 for \n";
	for (size_t c = 0; c < case_iter; ++c)
	{
		double dummy = 0.0;
		SET_TIME_POINT;
		for (int i = 0; i < iter; ++i)
		{
			for (size_t i = 0; i < num_value; ++i)
			{
				dummy += test1() + test2();
			}
		}

		std::cout << "conssumed time : " << GET_TIME_DURATION << "\n";
		std::cout << "dummy : " << dummy << "\n";
	}
}
```
### comment
* Version 1 : 1 for 압승
* Version 2 : 1 for 근소하게 승

## for with unsigned and signed
```cpp
constexpr auto case_iter = 10;
constexpr auto iter = 10000;
constexpr auto num_value = 100000;

int main(void) {
	std::vector<double> values(num_value, 0.1);

	std::cout << "signed\n";
	double total_time2 = 0.0;
	for (int c = 0; c < case_iter; ++c)
	{
		double dummy = 0.0;
		SET_TIME_POINT;
		for (int i = 0; i < iter; ++i)
		{
			for (int j = 0; j < num_value; ++j)
			{
				dummy += values[j];
			}
		}
		const auto consumed_time = GET_TIME_DURATION;
		std::cout << "conssumed time : " << consumed_time << "\n";
		std::cout << "dummy : " << dummy << "\n";
		total_time2 += consumed_time;

	}
	std::cout << "average consumed time : " << total_time2 / case_iter << "\n";

	std::cout << "unsigned\n";
	size_t unum = static_cast<size_t>(num_value);
	double total_time1 = 0.0;
	for (int c = 0; c < case_iter; ++c)
	{
		double dummy = 0.0;
		SET_TIME_POINT;
		for (int i = 0; i < iter; ++i)
		{
			for (size_t j = 0; j < unum; ++j)
			{
				dummy += values[j];
			}
		}
		const auto consumed_time = GET_TIME_DURATION;
		std::cout << "conssumed time : " << consumed_time << "\n";
		std::cout << "dummy : " << dummy << "\n";
		total_time1 += consumed_time;
	}
	std::cout << "average consumed time : " << total_time1 / case_iter << "\n";
}
```
### comment
차이 없음