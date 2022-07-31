- [Test Class](#test-class)
- [STL Container](#stl-container)
	- [Queue](#queue)
	- [Set](#set)
		- [멤버 함수](#멤버-함수)
			- [insert](#insert)
			- [erase](#erase)
- [Multi Thread](#multi-thread)
	- [기본](#기본)
		- [작동방식1](#작동방식1)
		- [Join](#join)
		- [작동방식2 with join](#작동방식2-with-join)
	- [STL Container](#stl-container-1)
		- [std::vector](#stdvector)
	- [Performance](#performance)
		- [False Sharing](#false-sharing)
- [I/O](#io)
	- [std::cin](#stdcin)
		- [operator>>](#operator)
		- [std::getline](#stdgetline)
	- [iomanip](#iomanip)
- [Integral Type](#integral-type)
- [constexpr](#constexpr)
	- [class](#class)
	- [this](#this)
- [local static variable](#local-static-variable)
	- [performance degrade](#performance-degrade)
- [함수 포인터](#함수-포인터)
	- [기본 함수 포인터](#기본-함수-포인터)
	- [멤버 함수 포인터](#멤버-함수-포인터)
- [배열](#배열)
	- [원형](#원형)
	- [배열의 참조](#배열의-참조)
	- [배열을 반환하는 함수](#배열을-반환하는-함수)
	- [배열의 참조를 반환하는 함수](#배열의-참조를-반환하는-함수)
	- [배열의 주소](#배열의-주소)
- [decltype](#decltype)
	- [auto와의 차이점](#auto와의-차이점)
- [Comma operator](#comma-operator)
- [static assert](#static-assert)
		- [예시](#예시)
		- [static assert vs SFINAE](#static-assert-vs-sfinae)
			- [static assert](#static-assert-1)
			- [SFINAE](#sfinae)
- [inline](#inline)
	- [static constexpr member function](#static-constexpr-member-function)
	- [inline constexpr vs constexpr](#inline-constexpr-vs-constexpr)
	- [constexpr function](#constexpr-function)
- [filesystem](#filesystem)
- [Chrono](#chrono)
- [Header only magic](#header-only-magic)
- [stream manipulators](#stream-manipulators)
- [auto return](#auto-return)
- [User-Define Conversion function](#user-define-conversion-function)
- [Mixin](#mixin)
- [명시적으로 삭제된 함수](#명시적으로-삭제된-함수)
	- [참고](#참고)
- [초기화, 할당](#초기화-할당)
- [코드](#코드)
- [미리 정의된 매크로](#미리-정의된-매크로)
	- [C++ 표준에서 지원하는 매크로](#c-표준에서-지원하는-매크로)
	- [MSVC에서 지원하는 매크로](#msvc에서-지원하는-매크로)
	- [참고](#참고-1)
- [컴파일러 옵션](#컴파일러-옵션)
	- [/MTd](#mtd)
	- [/MDd](#mdd)
	- [참고](#참고-2)
- [Namespace](#namespace)
- [Cmake](#cmake)

* [comparing double](https://stackoverflow.com/questions/12278523/comparing-double-values-in-c/35252979)
* [ULP](https://en.wikipedia.org/wiki/Unit_in_the_last_place)
  * Unit in the last place
  * measur of accuracy in numeric calculations

<br><br>

# Test Class
```cpp
class A
{
public:
	A(void) { std::cout << "constructor\n"; };
	A(const A& a) { std::cout << "copy constructor\n"; };
	A(A&& a) { std::cout << "move constructor\n"; };

	A& operator=(const A& a) { std::cout << "A copy operator\n"; return *this; };
	A& operator=(A&& a) noexcept { std::cout << "move operator\n"; return *this; };
};
```
# STL Container

## Queue
FIFO(First in first out) container.

pop시 앞의 메모리를 낭비하거나, 모든 데이터를 옮기는 경우를 방지하기 위해 원형 큐를 사용해서 구현

## Set

### 멤버 함수
#### insert
``` cpp
std::set<size_t> s;
s.insert(3);
s.insert(4);
s.insert(3);    // nothing happen!
```

#### erase
```cpp
std::set<size_t> s = {1, 3};

const auto result1 = s.erase(2); // fail erase return size_t 0
const auto result2 = s.erase(3); // success erase return size_t 1
```

# Multi Thread

## 기본
### 작동방식1
```cpp
void PrintMessage(const std::string& msg) { std::cout << msg << std::endl; }

void main()
{
    std::thread my_thread1(PrintMessage, "Hello, I'm a child thread");
    PrintMessage("Hello, I'm a main thread");
}
```
우리가 생성한 스레드들은 모두 메인 스레드의 자식 스레드들이다. 메인 스레드는 프로그램 실행 시 기본적으로 하나 생성되는 스레드를 말한다. 메인 스레드는 프로그램을 진행하다가 자식 스레드를 새로 만들라는 명령을 받고 PrintMessage() 함수를 실행하는 자식 스레드를 생성한다. 자식 스레드를 생성 후 메인 스레드는 다음 작업을 계속 이어서 한다. 여기서 다음 작업은 PrintMessage() 함수를 실행하는 것이다. 자식 스레드는 만들어지는 순간 PrintMessage() 함수를 실행한다. 결과는 실행될 때마다 다를 수도 있다. 이는 스케줄러가 선택하는 스레드가 매번 다를 수 있기 때문이다. [참고](https://woo-dev.tistory.com/161)

### Join
단순히 스레드를 생성만하고 손을 놓으면 문제가 발생할 수 있다. 예를 들어 자식 스레드가 아직 실행 중인데 부모 스레드가 return 0;에 도달하여 프로그램이 종료되는 경우이다. 기본적으로 메인 스레드가 종료되고도 자식 스레드가 계속 실행 중인 것은 비정상적인 상황으로 본다. 때문에 이 경우, 강제로 오류를 발생시킨다. 만약 이것이 정말 프로그래머가 의도한 경우라면 잠시 후 볼 detach() 함수를 사용해야 한다.

만약 my_thread1가 join()을 호출하게 되면 현재 스레드(부모 스레드)는 my_thread1 스레드가 실행이 끝날 때까지 멈추게 된다. 즉 my_thread1 스레드의 실행이 끝나면 실행을 재개한다. join이라는 의미는 부모 스레드에 의해 갈라진 자식 스레드가 실행이 종료되어 부모 스레드에 합류한다는 것으로 생각하면 이해하기 편하다.

### 작동방식2 with join
```cpp
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main()
{
    thread th1([]()
        {
            cout << "Hello from th1\n";
            this_thread::sleep_for(chrono::milliseconds(1000));
        });

    thread th2([]()
        {
            cout << "Hello from th2\n";
        });


    th1.join();
    cout << "Hello from main" << endl;
    th2.join();

    return 0;
}
```

우선 메인 스레드는 th1, th2 스레드를 순서대로 실행한다. 그리고 th1과 th2는 스케줄러에 의해 선택되는대로 각각 실행될 것이고 메인 스레드는 계속해서 자기 갈 길을 갈 것이다. 그럼 th1.join() 함수를 만나게 되고 메인 스레드는 blocking(블락) 상태가 된다. 블락 상태란 실행이 중단되고, 현재 스레드 대신 다른 스레드가 스케줄링될 수 있는 상태라고 생각해두자. th1 스레드의 실행이 종료되면 메인 스레드는 계속해서 다음 코드를 실행하게 된다. 

## STL Container
There is no thread-safe guaranty on anything in the containers and algorithms of the the STL.[[참고]](https://stackoverflow.com/questions/4205392/is-stl-empty-threadsafe)

### std::vector
push_back은 thread safe하지 않다.

```cpp
#include <vector>
#include <string>

void producer(std::vector<std::string>* pages)
{
	constexpr auto num_web_site = 10;

	for (size_t i = 0; i < num_web_site; ++i)
	{
		std::this_thread::sleep_for(std::chrono::microseconds(100*i));
		std::string content = std::to_string(i) + " website contents\n";

		pages->push_back(content); // Error!
	}
}

int main(void)
{
	std::vector<std::string> pages;

	constexpr auto num_producer_thread = 5;

	std::vector<std::thread> producers;
	for (size_t i = 0; i < num_producer_thread; i++)
	{
		producers.push_back(std::thread(producer, &pages));
	}

	for (auto& prod : producers)
	{
		prod.join();
	}

	for (const auto& page : pages)
	{
		std::cout << page;
	}
}
```

## Performance

### False Sharing
> 참고  
> [C++ false sharing이란? - HwanShell](https://hwan-shell.tistory.com/230)


# I/O

## std::cin

### operator>>
```cpp
#include <iostream>
#include <string>

int main() 
{
	size_t num = 0;
	std::cin >> num;	//std::cin>>는 변수에 '\n'을 담지 않는다.
						//std::cin의 buffer에는 '\n'이 남아있음.

	std::string input_string;
	std::getline(std::cin, input_string) 	//std::getline은 변수에 '\n'을 담음
											//buffer에 남아있는 '\n'이 담김
}
```

### std::getline
```cpp
#include <iostream>
#include <string>

int main() 
{
	std::string input_string;
	while (std::getline(std::cin, input_string))
	{		
		std::cout << input_string << "\n";
	}
	//ctrl + z (window)를 입력하면 EOF가 입력됨.
	//이 경우 static_cast<bool>(std::cin)는 false가 됨
	return 0;
}
```

## iomanip
```cpp
int main(){
	size_t b = 1;	
    std::cout << std::setw(9) << b  //기본으로 std::right
	std::cout << std::left;         //한번 설정하면 계속 유지
	std::cout << std::setw(9) << b << b << b << "\n"; //setw는 바로 다음 입력에만 영향을 줌	

    double d = 1.2345;
    std::fixed << std::setprecision(2) // 2자리 고정소수점으로 출력, 한번 설정으로 계속 유지
    std::cout << d << "\n";
	std::cout << std::defaultfloat << std::setprecision(6); //initial precision
	std::cout << d << "\n";
}
```











# Integral Type
```cpp
int main(void) {
	std::cout << std::numeric_limits<unsigned short>::max() << "\n";	//65535
	std::cout << std::numeric_limits<unsigned int>::max() << "\n";		//4294967295
	std::cout << std::numeric_limits<unsigned long long>::max() << "\n";//18446744073709551615		
}
```

# constexpr
## class
``` cpp
class A
{
public:
    std::array<double,3> ar;
    //std::vector<double> vec; vector가 있으면 constexpr class가 될 수 없음
}
```
## this
``` cpp
class A
{
public:
	static constexpr int f(void) {
		return 3;
	}

	void test(void) {
		//constexpr int i = this->f();  //this는 constexpr로 사용할 수 없음
	}
};
```

<br><br>

# local static variable
## performance degrade
the stack is likely to be in cached memory while a static variable is not.  
https://stackoverflow.com/questions/21032885/performance-gain-from-static-const-and-global-variables
https://stackoverflow.com/questions/21488559/is-there-a-penalty-for-using-static-variables-in-c11
https://stackoverflow.com/questions/3730000/can-static-local-variables-cut-down-on-memory-allocation-time

<br><br>

# 함수 포인터
## 기본 함수 포인터
    Ret func(Arg1 arg1, Arg2 arg2)      //함수 원형
    Ret (*ptr_name)(Arg1, Arg2) = func  //함수 포인터  
    func(arg1,arg2)                     //사용 문법
    
## 멤버 함수 포인터
    Ret Class::func(Arg1 arg1, Arg2 arg2)               //함수 원형
    Ret (Class::*ptr_name)(Arg1,Arg2) = &Class::func    //함수 포인터  
    Class c;    (c.*ptr_name)(arg1,arg2);               //사용 문법

<br><br>

# 배열
## 원형
    int (arr_name)[N];

## 배열의 참조    
    int (&ref_name)[N] = arr;

## 배열을 반환하는 함수
    //배열을 반환하는 함수는 정의가 안된다. Compile error 발생
    int[N] func(void){ 
      static int arr[N];
      return arr;
    }

## 배열의 참조를 반환하는 함수
    //원형
    int (&func(void))[N]{ 
      static int arr[N];
      return arr;
    }

    //using 사용
    using IntArrayN = int[N];
    IntArrayN& func(void){
      static int arr[N];
      return arr;
    }
https://stackoverflow.com/questions/34439284/c-function-returning-reference-to-array

## 배열의 주소
    int arr[N];
    &arr    // 전체 배열의 주소
    &arr[0] // 첫번째 원소의 주소, 전체 배열의 주소와 동일하다.
    arr     // 첫번째 원소의 주소, array-to-pointer conversion 발생
https://stackoverflow.com/questions/8412694/address-of-an-array

<br><br>

# decltype
## auto와의 차이점
auto는 엄밀하게 정확한 타입을 표현하지 않지만 decltype은 타입 그대로 정확하게 전달한다.  
예를들어 배열의 경우 auto는 암시적으로 포인터로 변환하지만, decltype의 경우 배열 타입 그대로 전달한다.

    int arr[10];
    auto arr2 = arr;    // int* arr2 = arr;
    decltype(arr) arr3; // int arr3[10];

<br><br>

# Comma operator
```cpp
//콤마 연산자는 첫 번째 표현식을 먼저 평가한 후, 그 다음 표현식을 평가한다.
i = 20, j = 2 * i;  //i에 20이 대입된채로, j에 대한 연산을 수행한다.

// 최종적으로 평가된 표현식이 그 표현식 전체의 값이 된다.
cats = (17, 240);   //17이라는 표현식을 평가한 뒤 240이라는 표현식이 최종적으로 평가되고 240을 변수 cats에 대입시킨다.
                    //cats = 240;

//콤마 연산자는 연산자들중 우선순위가 가장 낮다.
cats = 17, 240;     //(cats = 17), 240;
                    //cast = 17;

// comma는 operator와 인접한 변수 이름을 분리하는 seperator로 사용된다.
++j, --i                        //comma operator
int j, i;                       //comma seperator 
int j = 0, i = word.size() - 1; //comma seperator
```
<br><br>


# static assert

### 예시
```cpp
template <int dimension>
class Point
{
	static_assert(0 <= dimension, "dimension shold be positive");
};

int main(void) {
	Point<2> p1;
	//Point<-2> p2; // Error message와 함께 compile error 발생	
}
```

### static assert vs SFINAE
#### static assert
static assert는 위의 예시처럼 컴파일 타임에 제약조건을 서술할 때 적절하다. static assert는 compile 해서 static assert 구문에 걸려야 error가 발생한다. error 발생시 SFINAE로 인해 오버로딩 목록에서 제외되서 적절한 대상을 못찾을 때보다 더 명확한 compiler error message를 얻을 수 있으며, 사용자 지정 error message도 출력할 수 있어 가독성이 좋다.

#### SFINAE
SFINAE 문법은 오버로딩 목록에서 제외하기 위해 사용하는 것이 옳바른 사용법이다. SFINAE 문법을 사용할 경우 compile전에 오버로딩 목록에서 제외되어 intellisense에 의해 빨간줄이 뜬다.

<br><br>

# inline
## static constexpr member function
```cpp
//A.h
class A{
    static constexpr size_t num_equation(void) {    //implict inline
        return num_equation_;
    }

    static constexpr size_t dimension(void) {       //definition should be here not .cpp file
        return dimension_;
    };
}
```

## inline constexpr vs constexpr
https://stackoverflow.com/questions/57704807/difference-between-constexpr-and-inline-constexpr-global-variable

## constexpr function
```cpp
class A
{
public:
	static constexpr size_t func(void);
};

constexpr size_t A::func(void) {
	return 2;
}

constexpr size_t func(void) {   //constexpr function implies inline
	return 2;
}
```
https://stackoverflow.com/questions/14391272/does-constexpr-imply-inline  
https://stackoverflow.com/questions/38043442/how-do-inline-variables-work/53896763#53896763

<br><br>

# filesystem
```cpp
#include <iostream>
#include <filesystem>

int main() {
	std::filesystem::path p("RSC");
	std::cout << "current  path  : " << std::filesystem::current_path() << "\n";
	std::cout << "relative path  : " << p.relative_path() << "\n";
	std::cout << "absolute path  : " << std::filesystem::absolute(p) << "\n";
	std::cout << "canonical path : " << std::filesystem::canonical(p) << "\n";
}
// current  path  : "C:\\Users\\KimMinSeok\\source\\repos\\MS_Test\\GoogleTest"
// relative path  : "RSC"
// absolute path  : "C:\\Users\\KimMinSeok\\source\\repos\\MS_Test\\GoogleTest\\RSC"
// canonical path : "C:\\Users\\KimMinSeok\\source\\repos\\MS_Test\\GoogleTest\\RSC"
```

# Chrono
```cpp
int main() {
	std::vector<size_t> vec;

	const auto time_point1 = std::chrono::steady_clock::now();
	for (size_t i = 0; i < 10000000; ++i)
		vec.resize(i, i);
	const auto time_point2 = std::chrono::steady_clock::now();

	std::chrono::nanoseconds nanosec = time_point2 - time_point1;

	//기본 시간 단위는 암시적 형변환 안됨
	//std::chrono::microseconds microsec = time_point2 - time_point1;	//signed integer 55bits
	//std::chrono::milliseconds milisec = time_point2 - time_point1;	//signed integer 45bits
	//std::chrono::seconds sec = time_point2 - time_point1;				//signed integer 35bits

	//기본 시간 단위는 duration_cast로 형변환 해야됨
	const auto microsec = std::chrono::duration_cast<std::chrono::microseconds>(nanosec);	
	const auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(nanosec);	
	const auto sec		= std::chrono::duration_cast<std::chrono::seconds>(nanosec);		

	std::cout << "nanosec: \t" << nanosec.count() << "\n";
	std::cout << "microsec: \t" << microsec.count() << "\n";
	std::cout << "milisec: \t" << millisec.count() << "\n";
	std::cout << "sec: \t\t" << sec.count() << "\n";

	//사용자 정의 시간 단위는 암시적 형변한 됨
	std::chrono::duration<double, std::micro>	d_microsec	= time_point2 - time_point1;
	std::chrono::duration<double, std::milli>	d_millisec	= time_point2 - time_point1;
	std::chrono::duration<double>				d_sec		= time_point2 - time_point1;

	std::cout << "d_microsec: \t" << d_microsec.count() << "\n";
	std::cout << "d_milisec: \t" << d_millisec.count() << "\n";
	std::cout << "d_sec: \t\t" << d_sec.count() << "\n";
}
```



# Header only magic
```cpp
//헤더.h
#define QWER 3

//헤더2.h
void inline func(void) {
	std::cout << QWER; //main에서 include 되어 있기 때문에 헤더2가 QWE을 알고 있다..??!
}
class A 
{
public:
	A() { std::cout << QWER; };
};

//main.cpp
#include "../INC/헤더.h"
#include "../INC/헤더2.h"
int main(void){
	func();
	A a;    // it works! 
}

//header include 순서를 바꾸거나, 헤더2를 include 하는 cpp file이 있으면 오류 발생.

//전처리문 순서에 따른 magic임
//main을 제외한 cpp file의 #include를 먼저 전처리한후 main이 있는 cpp file의 #include를 전처리한다.
//따라서 다른 cpp file이 헤더2를 include하는 순간에 QWER을 알 수 없음으로 오류가 발생한다.
//만약 다른 cpp file이 없다면 헤더 밑에 헤더2가 전처리가 되고 main문을 돌때 QWER을 알 수 있다.
```

# stream manipulators
how can use function without argumnet?  
https://stackoverflow.com/questions/23043127/how-can-stream-manipulators-in-c-be-functions  
https://docs.microsoft.com/ko-kr/cpp/standard-library/writing-your-own-manipulators-without-arguments?view=msvc-160

# auto return
```cpp 
constexpr int f1(void) {
	constexpr int i = 1;
	return i;
}
constexpr auto f2(void) {
	constexpr int i = 1;
	return i;
}
auto f3(void) {
	constexpr int i = 1;
	return i;
}

//auto f4(void);    // definition should be placed at same file
// https://stackoverflow.com/questions/40694607/auto-return-type-in-context-of-class-members

int main(void) {
	std::array<double, f1()> ar = { 1.0 };
	std::array<double, f2()> ar = { 1.0 };
	// std::array<double, f3()> ar = { 1.0 }; constexpr을 안붙이면 int return
}
```

# User-Define Conversion function
https://en.cppreference.com/w/cpp/language/cast_operator


# Mixin
https://stackoverflow.com/questions/18773367/what-are-mixins-as-a-concept


# 명시적으로 삭제된 함수

delete 키워드는 명시적으로 사용을 원치 않는 함수를 삭제시키는 방법으로 C++ 11에 추가된 기능이다. 아래와 예제 코드를 살펴보자.

```cpp
#include <iostream>

class A 
{
public:
A(int a){};
A(const A& a) = delete;
};

int main() 
{
A a = 3; // 가능
A b = a; // 불가능 (복사 생성자는 삭제됨)
}
```

컴파일 하게 된다면 복사 생성자를 호출하는 부분에서 오류가 발생한다. 왜냐하면, `A(const A& a) = delete;`와 같이 복사 생성자를 명시적으로 삭제하였기 때문이다. 따라서, 클래스 A 의 복사 생성자는 존재하지 않는다. 위와 같이 = delete; 를 사용하게 되면, 프로그래머가 명시적으로 ’이 함수는 쓰지 마!’ 라고 표현할 수 있다. 혹시나 사용하더라도 컴파일 오류가 발생한다.

std의 unique_ptr도 마찬가지로 unique_ptr의 복사 생성자가 명시적으로 삭제되었다. 그 이유는 unique_ptr는 어떠한 객체를 유일하게 소유해야 하기 때문이다. 만일 unique_ptr를 복사 생성할 수 있게 된다면, 특정 객체를 여러 개의 unique_ptr들이 소유하게 되는 문제가 발생한다. 만약 그럴 경우 각각의 unique_ptr 들이 소멸될 때 전부 객체를 delete하려 해 double free 버그가 발생하게 된다.

## 참고
[book] (이재범) 씹어먹는 C++

# 초기화, 할당

초기화와 할당

[여러가지 변수 초기화 방법 - 소년코딩 블로그](https://boycoding.tistory.com/181)  
[초기화와 할당의 차이 - woo-dev 블로그](https://woo-dev.tistory.com/78)  

[direct initialization vs copy initializaition - stack over flow](https://stackoverflow.com/questions/1051379/is-there-a-difference-between-copy-initialization-and-direct-initialization)  
[How to understand the differences between direct initialization and copy initialization - stack over flow](https://stackoverflow.com/questions/41907306/how-to-understand-the-differences-between-direct-initialization-and-copy-initial)  
[Copy-initialization vs direct-initialization has changed? - stack over flow](https://stackoverflow.com/questions/45722686/copy-initialization-vs-direct-initialization-has-changed)  
[Is it direct-initialization or copy-initialization? - stack over flow](https://stackoverflow.com/questions/46634869/is-it-direct-initialization-or-copy-initialization)

[initialization - cppreference](https://en.cppreference.com/w/cpp/language/initialization)   
[list initialization - cppreference](https://en.cppreference.com/w/cpp/language/list_initialization)  
[copy initialization - cppreference](https://en.cppreference.com/w/cpp/language/copy_initialization)



# 코드
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.29.30133\crt\src 에 코드가 들어있다.

new 는 new_scalar.cpp에 있다.

# 미리 정의된 매크로

## C++ 표준에서 지원하는 매크로 
* `__FILE__` 현재 소스파일의 이름  
* `__LINE__` Defined as the integer line number in the current source file.


## MSVC에서 지원하는 매크로
* `_DEBUG` Defined as 1 when the /LDd, /MDd, or /MTd compiler option is set. Otherwise, undefined.

## 참고
[Predefined macros - MSVC](https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?redirectedfrom=MSDN&view=msvc-170)


# 컴파일러 옵션
## /MTd
`_DEBUG` 및 `_MT`를 정의합니다. 또한, 이 옵션은 컴파일러가 .obj 파일에 라이브러리 이름 LIBCMTD.lib를 배치하여 링커가 LIBCMTD.lib를 사용하여 외부 기호를 확인하도록 만듭니다.

## /MDd	
`_DEBUG`, `_MT` 및 `_DLL`을 정의하고 애플리케이션에서 런타임 라이브러리의 디버그 다중 스레드 DLL별 버전을 사용하게 됩니다. 또한 컴파일러가 라이브러리 이름 MSVCRTD.lib를 .obj 파일에 배치하게 만듭니다.

## 참고
[/MD, /MT, /LD](https://docs.microsoft.com/ko-kr/cpp/build/reference/md-mt-ld-use-run-time-library?view=msvc-170)


# Namespace
:: 연산자 앞에 namespace를 선언하지 않으면 전역 namespace에 있는 함수를 호출하도록 한다.

standard library를 활용한 표준 함수를 사용할 때 매번 네이밍을 붙이는 것이 귀찮을 수 있다. 이때는 using이라는 keyword를 사용하면 된다. using 선언 같은 경우 해당 이름의 함수를 현재 scope로 가져온다라는 의미이다.

```
void my_code (vector<int>& x, vector<int>& y) {
	using std::swap;

	swap(x,y);
}
```
위의 코드를 보면 standard library의 swap 함수를 using과 함께 사용한 것을 볼 수 있다. using을 사용할 경우 현재 scope로 변환되기 때문에 std:: namespace를 붙일 필요가 없다.

만약, 특정함수 뿐만아니라 library 내 모든 함수를 해당 scope로 변경하고 싶다면 아래의 코드를 추가하자.

```
using namespace std;
```
해당 코드를 코드 선언부에 작성해준다면 scope를 해당 코드 scope로 변경함으로 namespace를 추가해 줄 필요가 없어진다. 하지만, 위와 같은 방법을 한다면 언제 name 충돌이 발생할지 모르고 또 프로그램이 커지면 버그도 찾기 어려워 진다. 따라서, 간단한 코드가 아니라면 namespace를 다 적어주는 습관을 기르도록 하자.

[참고 블로그](https://nerdooit.github.io/2020/09/08/cpp_book_2.html)

# Cmake
[참고 블로그](https://gist.github.com/luncliff/6e2d4eb7ca29a0afd5b592f72b80cb5c)