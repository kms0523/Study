## 클래스 선언과 정의
일반적으로 객체(변수, 배열)나 함수가 가상 메모리 영역을 차지하는 것에 비하여 클래스는 오직 개념적인 구조로서만 존재할 뿐이다. 즉, 클래스는 메모리 영역과는 전혀 상관이 없다.

아래의 예시 코드를 보자.

```cpp
//A.cpp TU1
int g_val;
class Test
{
public:
    int m_val;
}

//Main.cpp
extern int g_val;
class Test;

void main(void)
{
    g_val = 1;

    Test t;         //compile error
    t.m_val = 1;    //compile error
}
```

선언을 통해서 g_val이 int 전역 변수라는 것을 알고 있다. 따라서 컴파일러는 g_val이 4byte의 메모리 영역을 차지하고 있음을 알 수 있다. 이로써 컴파일 단계에서는 어셈블리로 특정 주소를 시작으로 4byte 영역을 1로 채우는 코드를 작성하면 되고 링크 단계에서는 특정 주소를 실제 g_val이 위치하는 주소로 변경하면 된다.

그러나 class의 경우에는 문제가 달라진다. Test 객체를 생성해야 하는데 Test의 크기를 알 수가 없다. Test의 크기를 알기 위해서는 정의가 필요하다. A.cpp에 Test의 정의가 있지만 이는 오직 TU1에서만 알 수 있다. 따라서 컴파일러는 여지없이 에러를 발생시키는 것이다.

컴파일러에게 필요한 것은 Test가 클래스라는 선언이 아니라 Test의 설계도인 정의이다. 결국 Main.cpp에도 Test를 정의해줘야 한다. 결국 클래스의 정의는 사용되는 모든 소스(cpp) 파일마다 정의되어야만 하기 때문에 일반 객체나 함수의 정의와는 다르게 중복을 허용한다.

클래스의 정의가 내용이 많을 경우 클래스를 사용하는 소스 파일마다 클래스의 정의를 똑같이 붙여 넣는 것은 분명히 비효율적인 방법이다. 그래서 클래스의 정의는 보통 헤더 파일에 작성하고, 클래스 내부의 멤버 함수의 정의 같은것은 소스 파일에 작성한다.

이렇게 클래스 정의가 중복될 수 있음으로 문제가 발생하기도 하는데 바로 중복되는 정의가 서로 다른 경우이다. 아래의 예제를 보자.

```cpp
//A.cpp
class Test
{
public:
    Test(const int val1, const int val2)
        : val1_(val1)
        , val2_(val2) {};

    int val2_;
    int val1_;
};

extern Test g_test;

int get_val1(void)
{
    return g_test.val1_;
}

//Main.cpp
class Test
{
public:
    Test(const int val1, const int val2)
        : val1_(val1)
        , val2_(val2) {};

    int val1_;
    int val2_;
};

Test g_test(1, 2);

int get_val1(void);

void main(void)
{
    std::cout << get_val1() << "\n"; // 2가 출력됨
}

```
코드를 살펴보면 1이 출력되야 될 것 같지만 실제 결과는 2가 출력이 된다. 이를 이해해 보기 위해 먼저
A.cpp와 Main.cpp에 클래스 Test가 중복으로 정의되어 있지만 멤버 변수가 정의된 순서가 다르다는걸 알아야한다. Main.cpp에서 `g_test.val1_;`이 의미하는 것은 g_test의 메모리 영역 중에서 `첫 번째 멤버 변수`를 나타내지만  A.cpp에서 `g_test.val1_;`이 의미하는 것은 g_test의 메모리 영역 중에서 `두 번째 멤버 변수`를 나타낸다는 점에서 문제가 발생한다.

Main.cpp에서 `Test g_test(1, 2);`이 실행될 때는 이미 첫번째 4btye에는 1을 두번째 4byte에는 2를 작성하였다. 이후에 A.cpp에서 `g_test.val1_;`이 실행될 때 두번째 4byte 값을 읽기 때문에 결과로 2가 출력되는 것이다.

여기서 알 수 있는 점은 클래스의 멤버 변수에 접근하는 것은 클래스 정의에 따라 해당 멤버 변수의 메모리 오프셋에 의해서 계산된 위치를 기준으로 한다는 점이다. 즉, 멤버 변수의 이름은 오직 오프셋 계산을 위해서 사용되는 것이지, 그 자체가 하나의 고정된 영역을 나타내는 것은 아니라는 점이다.

보통은 이름만 같고 정의가 완전히 다른 경우에는 런타임 에러가 발생해서 어느 정도 문제를 빠르게 확인할 수 있을수도 있지만, 같은 라이브러리를 사용하지만 버전이 서로 다른 것이 혼합되어 있을 경우 클래스 정의가 유사하지만 약간 다른 부분이 가끔씩 문제를 일이클 경우에는 어디서 문제가 잘못되었는지 파악하기 어려울 수 있다.


### 참고
김화수. (2015). Fundamental C++ 프로그래밍 원리 기초부터 고급까지.

## 클래스의 멤버 함수의 링크 방식
클래스 멤버 함수의 링크 방식은 외부 링크 방식이다.

아래의 예제 코드를 통해 확인해보자

```cpp
// A.h
#include <iostream>

class A
{
public:
	void tell(void) const;
};

// A.cpp TU1
#include "A.h"

void A::tell(void) const
{
	std::cout << "I'm A\n";
}

// Main.cpp TU2
int main() {
	A a;
	a.tell();
}
```

TU2에서 TU1에 정의되어 있는 함수를 사용하였음으로 TU1에 정의된 A class의 tell 멤버 함수는 외부 링크 방식임을 알 수 있다.


## 익명 클래스 
익명 클래스(unnamed, anonymus class)는 이름이 주어지지 않은 클래스이다.

익명 클래스는 생성자는 갖을 수 없으나 소멸자는 갖을수 있으며 함수의 인자나 리턴 값으로 사용될 수 없다.

아래의 예시 코드를 보자.

```cpp
#include <iostream>

class //익명 클래스
{
public:
    void setData(int i)
    {
        this->i = i;
    }
    void print()
    {
        std::cout << "Value for i : " << this->i << std::endl;
    }

private:
    int i;       
} obj1;     //익명 클래스의 객체
            //obj1, obj2, ...; 와 같이 ,로 연결하여 여러개를 생성할 수 있음
  
int main()
{
    obj1.setData(10);   //익명 클래스의 객체의 저장 기간(stroage duration)과 링크 방식(linkage)??
    obj1.print();
    return 0;
}
```


### 참고
[geeks for geeks](https://www.geeksforgeeks.org/anonymous-classes-in-cpp/)