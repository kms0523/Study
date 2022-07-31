# 생성자
## explicit
explicit 키워드는 자신이 원하지 않은 형변환이 일어나지 않도록 제한하는 키워드이다.

아래 예제코드를 통해 생성자에 explicit이 있을때와 없을 때의 차이를 알아보자. 
```cpp
struct A
{
    A(int) { }      // converting constructor
    A(int, int) { } // converting constructor (C++11)
    operator bool() const { return true; }
};
 
struct B
{
    explicit B(int) { }
    explicit B(int, int) { }
    explicit operator bool() const { return true; }
};
 
int main()
{
    A a1 = 1;      // OK: copy-initialization selects A::A(int)
    A a2(2);       // OK: direct-initialization selects A::A(int)
    A a3 {4, 5};   // OK: direct-list-initialization selects A::A(int, int)
    A a4 = {4, 5}; // OK: copy-list-initialization selects A::A(int, int)
    A a5 = (A)1;   // OK: explicit cast performs static_cast
    if (a1) ;      // OK: A::operator bool()
    bool na1 = a1; // OK: copy-initialization selects A::operator bool()
    bool na2 = static_cast<bool>(a1); // OK: static_cast performs direct-initialization
 
//  B b1 = 1;      // error: copy-initialization does not consider B::B(int)
    B b2(2);       // OK: direct-initialization selects B::B(int)
    B b3 {4, 5};   // OK: direct-list-initialization selects B::B(int, int)
//  B b4 = {4, 5}; // error: copy-list-initialization does not consider B::B(int,int)
    B b5 = (B)1;   // OK: explicit cast performs static_cast
    if (b2) ;      // OK: B::operator bool()
//  bool nb1 = b2; // error: copy-initialization does not consider B::operator bool()
    bool nb2 = static_cast<bool>(b2); // OK: static_cast performs direct-initialization
}
```
> 참고  
> [explicit - cppreference](https://en.cppreference.com/w/cpp/language/explicit)


## copy list initialization
``` cpp
class A {
public:
  template <typename... Args> 
  A(Args... args) { std::cout << "calling constuctor\n"; }
  
  A(const A& a) { std::cout << "calling copy constructor\n"; }
};

int main(void)
{
  A a, b, c;
  A d = { a,b,c }; // A(A arg1, A arg2, A arg3) copy is occur here
}
```


## Precautions

### Virtual Functions
Pure virtual function can not use in `base class constructor` and virtual function call can be invoke unwanted behavior.

https://stackoverflow.com/questions/8630160/call-to-pure-virtual-function-from-base-class-constructor

### variadic template with perfect forwarding
copy constructor doesn't work.
```cpp
class A
{
public:
	template <typename ... Args> A(Args&&... args)
		: values_(std::forward<Args>(args)...) {};

private:
	std::vector<double> values_;
};

int main(void) 
{
	std::vector<A> a(50);
	std::vector<A> b;

	b = a;

	std::cout << "Debug";
}
```

# 상속
## 부모클래스 매서드 숨김 문제
먼저 아래 예제코드를 보자.

``` cpp
#include <iostream>

class A
{
public:
	int test(void) const
	{
		return 1;
	}
};

class B : public A
{
public:
	int test(int a) const
	{
		return 2;
	}
};

int main(void)
{
	const B b;
	std::cout << b.test(); //Error!

	return 0;
}
```

B클래스는 A클래스를 상속하였음으로 인자를 받지 않는 test함수가 클래스 B에 존재하고 int를 인자로 받는 또 다른 test함수가 overloading 될 것으로 기대한다.

하지만 예제코드에서 알 수 있듯이, int를 인자로 받는 test함수가 정의가 되면 A 클래스에 있는 test 함수가 숨겨지고 에러가 발생한다.

기대와 다르게 클래스 A와 B사이에는 어떠한 overloading도 발생하지 않는다. 그 이유는 overloading은 개념적으로 하나의 범위(scope)만을 살펴보기 때문이다. 예제 코드를 보면 객체 b가 test 함수를 호출할 때 컴파일러는 B 클래스의 범위를 살펴본 뒤 int 타입을 인자로 받는 함수만을 찾게된다. A 클래스에 정의된 test함수는 A 클래스의 범위에 속하기 때문에 컴파일러가 overloading을 위해 하나의 범위만을 살펴본다는 기본 규칙에 의해 살펴보는 범위가 아니게 된다. 따라서 컴파일러는 인자를 받지 않는 함수를 찾지 못해 에러를 발생시킨다. 

C++에서는 범위를 넘어서는 overloading을 지원하지 않으며 이 기본규칙은 상속관계에 있는 Base - Derived 클래스의 경우일지라도 일관되게 적용된다.

이 문제는 다음 방법으로 해결할 수 있다.
``` cpp
#include <iostream>

class A
{
public:
	int test(void) const
	{
		return 1;
	}
};

class B : public A
{
public:
	using A::test;
	int test(int a) const
	{
		return 2;
	}
};

int main(void)
{
	const B b;
	std::cout << b.test();

	return 0;
}
```

숨겨진 함수를 using을 사용한 선언(declaration)을 통해 드러낼 수 있다.


#### 참고
[Why should I use the "using" keyword to access my base class method? - stackoverflow](https://stackoverflow.com/questions/1896830/why-should-i-use-the-using-keyword-to-access-my-base-class-method)  
[What’s the meaning of, Warning: Derived::f(char) hides Base::f(double)? - CppFAQ](https://isocpp.org/wiki/faq/strange-inheritance#hiding-rule)

## Derive 클래스의 복사
다음 예제 코드를 보자
```cpp

#include <iostream>

class A
{
public:
	A(void) = default;
	A(const A& a) { std::cout << "A copy constructor\n"; };
	
	A& operator=(const A& a) { std::cout << "A copy operator\n"; return *this; };
};

class B : public A
{
public:
	B(void) = default;
	B(const B& b) { std::cout << "B copy constructor\n"; };             //wrong
	//B(const B& b) : A(b) { std::cout << "B copy constructor\n"; };    //right

	B& operator=(const B& other) { std::cout << "B copy operator\n"; return *this; };   //wrong
	//B& operator=(const B& other) { A::operator=(other); std::cout << "B copy operator\n"; return *this; }; //right
};

int main(void)
{
	B b1, b2;
	
	B b3 = b1;

	b2 = b1;

	return 0;
}

```

코드를 실행시킬경우 Parent 클래스와 관련된 복사는 발생하지 않는다. 

이런 문제를 해결하기 위해서 Derive 클래스의 복사생성자를 작성할 때는 initializer list를 사용해서 Parent 클래스의 복사생성자가 먼저 호출되게 해줘야 한다. 또한 Derive 클래스의 복사 연산자를 구현할 때도 가장 먼저 Parent class의 복사 연산자가 먼저 호출되게 해줘야 한다. 이러한 과정이 주석처리된 코드에 나타나있다.

# Friend Class

## Across namespace
```cpp
//header1.h

//class ms::A; // doesn't work!

namespace ms {
	class A;
}

class B {
private:
	friend class ms::A;
private:
	double value = 3.14;
};

//header2.h
#include "header1.h"

namespace ms {
	class A
	{
	public:
		A() {
			B b;
			b.value = 5.14; // can access!
		};
	};
}

```