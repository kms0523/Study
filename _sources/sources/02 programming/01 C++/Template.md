# Template
## User define deduction guide
```cpp
//user-defined deduction guides
template <typename... Args>
EuclideanVector(Args... args)->EuclideanVector<sizeof...(Args)>;
EuclideanVector(const std::vector<double>& vec)->EuclideanVector<0>;
```

## default template type
```cpp
template <typename T1, typename T2>
void func1(T1 val);

template <typename T1, typename T2 = int>
void func2(T1 val);

func1(1) // instantiation fail! because T2 = ??
func2(1) // instantiation success! T1 = int T2 = int
```
## Sepcialization
```cpp
// A.h
template<size_t N>
class A{
    void func(void);    
    
    template<typename T>
    void func2(void);
};

template<size_t N>
void A<N>::func(void) {};   // definition

template<>
void A<0>::func(void);      // deceleration only
                            // signature should be same!

template<>
template<typename T>
void A<0>::func2(void) {};  // definition

template <>
class A<2> {
public:
	void func2(void);

	template<typename T>
	void func3(void);
};

// template<>
// void A<2>::func2(void) {	// ODR
// 	std::cout << "ODR?\n";
// }

//template<>
template <typename T>
void A<2>::func3(void) {
	std::cout << "ODR?\n";
}

// A.cpp
template<>
void A<0>::func(void){};    // definition

void A<2>::func2(void) {	
	std::cout << "ODR?\n";
}
```

### Nested template call
```cpp
template<typename T> 
struct Base{
    template<class U> 
    void example() {}
};

template<typename T>
struct X : Base<T>
{
    void example()
    {
        // Base<T>::example<int>(); // C7510: 'example': use of dependent
                                    // template name must be prefixed with 'template'
                                    // note: see reference to class template instantiation
                                    // 'X<T>' being compiled
               
        Base<T>::template example<int>();   // Add template keyword here
    }
};
```
https://docs.microsoft.com/ko-kr/cpp/error-messages/compiler-errors-2/compiler-error-c7510?view=msvc-160

### typename
``` cpp
//Polynomial<DomainDim>::SimplePolyTerm이 변수인지 type인지 명확하게 하기 위해
//typename을 붙여 타입임을 명시해야한다.
template <size_t DomainDim> 
typename Polynomial<DomainDim>::SimplePolyTerm& Polynomial<DomainDim>::SimplePolyTerm::operator+=(const SimplePolyTerm& other) {...}
```

<br><br>

### Template Parameter Pack (Variadic Template)
#### 기본문법
https://en.cppreference.com/w/cpp/language/parameter_pack

#### Fold Expression
##### Example1
```cpp
template <typename... Args>
bool contains_icase(const std::string& str, const Args... args) {		
	static_require((... && std::is_same_v<Args, const char*>), "every arguments should be array of char");
	return (ms::contains_icase(str, args) && ...);
};
```

> Reference
> [cppreference](https://en.cppreference.com/w/cpp/language/fold)

#### Parameter pack expansion
A pattern followed by an ellipsis is expanded into ***zero or more comma-separated instantiations of the pattern***, where the name of the parameter pack is replaced by each of the elements from the pack, in order.

##### Example1
```cpp
template<typename... Us> void f(Us... pargs) {}
template<typename... Ts> void g(Ts... args) { f(&args...); }

g(1, 0.2, "a");
//(Ts... args) expand to (int E1, double E2, const char* E3)
//(&args...) expands to (&E1, &E2, &E3), “&args” is its pattern
// Us... pargs expand to int* E1, double* E2, const char** E3
```

#### Recursive call
##### Example1
```cpp
template <typename T, typename... Args>
std::vector<T>& merge(std::vector<T>& vec1, std::vector<T>&& vec2, Args&&... args) {
    static_require((... && std::is_same_v<Args, std::vector<T>>), "every arguments should be vector of same type");

    vec1.reserve(vec1.size() + vec2.size());
    vec1.insert(vec1.end(), std::make_move_iterator(vec2.begin()), std::make_move_iterator(vec2.end()));

    if constexpr (sizeof...(Args) == 0) 
        return vec1;
    else 
        return ms::merge(vec1, std::move(args)...);
}
```

#### non type template parameter pack
```cpp
template<int... x>
void f(){ //인자로 x... xs를 쓰면 compile이 안됨
    constexpr int x_array[] = { x... };
    for (int i = 0; i < sizeof...(x); i++)
        std::cout << x_array[i] << " ";
}

int main(void) {
    f<1,2,3>();
}
```

#### Locaton of template parameter pack
```cpp
//In a primary class template, the template parameter pack must be the final parameter in the template parameter list.
template<typename... Ts, typename U> struct Invalid; //Error

//In a function template, the template parameter pack may appear earlier in the list provided that all following parameters can be deduced from the function arguments, or have default arguments
template<typename ...Ts, typename U, typename=void>
void valid(U, Ts...);     // OK: can deduce U

template<typename ...Ts, typename U, typename=void>
void invalid(Ts..., U);  // Error: cna not deduce U 
```

#### Issue1 - resolved
    struct A {
        template <typename... Args, std::enable_if_t<(...&&std::is_arithmetic_v<Args>), bool> = true>
        A(Args... args) {};
    };
    
    template <size_t N> struct C {
        template <typename... Args, std::enable_if_t<(...&&std::is_arithmetic_v<Args>), bool> = true>
        C(Args... args) {};
    };
    template <typename... Args> C(Args... args)->C<sizeof...(Args)>;

    int main(void) {
        A a(1, 2, 3); 
        C c(1, 2, 3); //c2059 error: '...'
    }

    // resolve issue when use c++ language standard c++latest 

## SFINAE
만일 템플릿 인자 치환이 올바르지 않는 타입이나 구문을 생성한다면 인자 치환에 실패한다. 올바르지 않는 타입이나 구문이라 하면, 치환된 인자로 썼을 때 문법상 틀린 것을 의미한다. 이 때, `즉각적인 맥락(immediate context)`의 타입이나 구문만이 고려되고, 여기에서 발생한 오류 만이 인자 치환을 실패시킬 수 있다. 만약 인자 치환에 실패하게 되면 이를 오버로딩 목록에서 제외한다.

아래 예재 코드를 보자.
```cpp
template <typename T>
typename T::value_type func(const T& t) {
    std::cout<< "template\n";
}

unsigned int func(const unsigned int t) {
    std::cout<< "not template\n";
}

int main(void){
    func(2) 
    //2는 int이기 때문에 템플릿 func에서 int로 타입 치환된다.
    //하지만 int::value_type이 존재하지 않기 때문에 인자 치환은 실패하고 오버로딩 후보에서 제외된다.
    //따라서 int >> unsigned int로 implicit casting되고 밑에 func가 실행된다.
}
```

SFINAE를 이용해서 템플릿 인자에 따라 오버로딩 목록에 들어갈지 빠질지 결정하는 컴파일 타임 스위치를 만들 수 있다. 

### Immediate context
즉각적인 맥락이 무엇인지 아래 예제 코드들을 살펴보자.

#### Example1
아래 예시 코드를 통해 return type은 immediate context이지만, 함수 본문은 immediate context가 아님을 알 수 있다.

```cpp
template <typename T>
void func(const T& t) {
std::cout << typename T::value_type n = 2*t;
}

void func(const unsigned int t) {
std::cout << t * 3;
}

int main(void){
    func(2);
    //typename T::value_type가 함수 타입과 템플릿 타입 인자의 즉각적인 맥락 바깥에 있다.
    //그로인해 오버로딩 목록에서 제외되지 않고 compile time error를 발생시킨다.
}
```

#### Example2
아래 예시 코드를 통해, class의 template type은 class를 인스턴스화 할때는 immediate context이지만, 생성자에서는 immediate context가 아님을 알 수 있다.

```cpp
template <typename... Args>
struct Test1 {        
    template <std::enable_if_t<(sizeof...(Args) != 2), bool> = true>
    Test1() { std::cout << "2\n"; }

    template <std::enable_if_t<(sizeof...(Args) == 2), bool> = true>
    Test1() { std::cout << "not 2\n"; }
};

template <typename... Args>
struct Test2 {
    template <std::size_t i = sizeof...(Args), std::enable_if_t<i != 2, int> = 0> 
    Test2() { std::cout << "2\n"; }

    template <std::size_t i = sizeof...(Args), std::enable_if_t<i == 2, int> = 0>
    Test2() { std::cout << "not 2\n"; }
};

int main() {
Test1<int, int> t1; //compile time error!
//Args are an immediate context when instantiation Test1 class.
//Args are not an immediate context in constructor.

Test2<int, int> t1;
//Args are an immediate context in constructor because of adding new template parameter i
}
```
>참고  
[what-exactly-is-the-immediate-context... - StackoverFlow](https://stackoverflow.com/questions/15260685/what-exactly-is-the-immediate-context-mentioned-in-the-c11-standard-for-whic)  
[problem-with-sizeof-of-parameter-pack... - StackoverFlow](https://stackoverflow.com/questions/59895810/problem-with-sizeof-of-parameter-pack-in-enable-if)  
[correct way to use ... - StackoverFlow](https://stackoverflow.com/questions/57449491/correct-way-to-use-stdenable-if)  
[c-template-instantations-using-enable-if... - StackoverFlow](https://stackoverflow.com/questions/28985936/c-template-instantations-using-enable-if-directly-or-with-an-auxiliary-class)


## std::enable_if
SFINAE로 컴파일 타임 스위치를 만들 때 자주 사용하는 도구로 std::enable_if가 있다. std::enable_if는 아래처럼 구현되어 있다.
```cpp
template <bool B, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> {
typedef T type;
};
```

enable_if 구조체의 type에 접근하는 코드를 단순화하기 위해 enable_if_t를 제공한다.
```cpp
template <bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;
```

>참고  
[씹어먹는 C ++ 토막글 3 - SFINAE 와 enable_if - 모두의 코드](https://modoocode.com/255)  


### Alias
enable_if_t를 이용해서 코드가 단순해 지기는 했지만 아직도 SINAE문법은 매우 복잡하다. 이 떄, using keyword를 사용해서 Alias를 만듬으로써 가독성을 크게 향상시킬 수 있다.
```cpp
#include <type_traits>
#include <iostream>

template <typename T>
using is_int = std::enable_if_t<std::is_same_v<int, T>, bool>;

template <typename T>
using is_char = std::enable_if_t<std::is_same_v<char, T>, bool>;

template<typename T, is_int<T> = true>
void func(const T value)
{
	std::cout << "int!\n";
}

template<typename T, is_char<T> = true>
void func(const T value)
{
	std::cout << "char!\n";
}

int main(void)
{
	func(1);
	func('a');

	return 0;
}
```

### 사용 예시
#### example1
```cpp
#include <type_traits>
#include <iostream>

template <typename T>
using is_int = std::enable_if_t<std::is_same_v<int, T>, bool>;

template <typename T>
using is_char = std::enable_if_t<std::is_same_v<char, T>, bool>;

template <typename T1>
class A 
{
public:
	template<typename T2 = T1, is_int<T2> = true>
	A() {
		std::cout << "int!\n";
	}

	template<typename T2 = T1, is_char<T2> = true>
	A() {
		std::cout << "char!\n";
	}
};

int main(void) {
	A<int> a1;
	A<char> a2;
	//A<double> a3; //적절한 생성자를 찾지 못해 Error 발생
}
```

#### example2
``` cpp
// check template parameter pack arguments type 

// fold expression
template<typename... Args, std::enable_if_t<(... && std::is_same_v<int, Args>), bool> = true>
void func(const Args&... args) { std::cout << "only int\n"; };

// conjunction
template <typename... Args, std::enable_if_t<std::conjunction_v<std::is_same_v<Args,int>...>, bool> = true>
void func(const Args&... args) { std::cout << "only int\n"; };

// using
template <typename... Args>
using are_ints = std::enable_if<std::conjunction_v<std::is_same_v<Args,int>...>,bool>;

template <typename... Args, are_ints<Args...> = true>
void func(const Args&... args) {std::cout << "only int\n";};

// true & false wrapping
template <typename... Args>
inline constexpr bool are_ints_v = std::conjunction_v<std::is_smave<Args,int>...>;

template <typename... Args, std::enable_if<are_ints_v<Args...>,bool> = true>
void func(const Args&... args) {std::cout << "only int\n";};

```
>참고  
[checking type of parameter pack ... - StackoverFlow](https://stackoverflow.com/questions/29671643/checking-type-of-parameter-pack-using-enable-if)  
[type trait to check that all types ... - stackoverFlow](https://stackoverflow.com/questions/29603364/type-trait-to-check-that-all-types-in-a-parameter-pack-are-copy-constructible)

### Warning
#### common mistake
```cpp
// Declare two function templates that differ only in their default template arguments.
// This does not work because the declarations are treated as redeclarations of the same function template.
// Default template arguments are not accounted for in function template equivalence.

/* WRONG */    
struct T {
    enum { int_t, float_t } type;
    template <typename Integer, typename = std::enable_if_t<std::is_integral_v<Integer>>>
    T(Integer) : type(int_t) {}

    template <typename Floating,typename = std::enable_if_t<std::is_floating_point_v<Floating>>>
    T(Floating) : type(float_t) {} // error: treated as redefinition
};

/* RIGHT */    
struct T {
    enum { int_t, float_t } type;
    template <typename Integer, std::enable_if_t<std::is_integral_v<Integer>, bool> = true>
    T(Integer) : type(int_t) {}

    template <typename Floating, std::enable_if_t<std::is_floating_point_v<Floating>, bool> = true>
    T(Floating) : type(float_t) {} // OK
};
```
https://en.cppreference.com/w/cpp/types/enable_if

#### Issue
``` cpp
// case 1 Fail! but I don't know why
template <size_t Va, size_t Vb, size_t Max = std::max(Va,Vb)> 
using is_big = std::enable_if_t< 25 <= Max || Va * Vb == 0, bool>;

template <size_t Va, size_t Vb, size_t Max = std::max(Va, Vb)>
using is_small = std::enable_if_t < Max < 25 && Va * Vb != 0, bool>;

// // case 2 Fail!
// template <size_t Va, size_t Vb>
// using is_big = std::enable_if_t< 25 <= std::max(Va, Vb) || Va * Vb == 0, bool>;

// template <size_t Va, size_t Vb>
// using is_small = std::enable_if_t < std::max(Va, Vb) < 25 && Va * Vb != 0, bool>;

// // case 3 Work fine!
// template <size_t Va, size_t Vb>
// using is_big = std::enable_if_t< 25 <= Va || 25 <= Vb || Va*Vb == 0 , bool>;

// template <size_t Va, size_t Vb>
// using is_small = std::enable_if_t< Va < 25 && Vb < 25 && Va*Vb != 0 , bool>;

template <size_t Va>
class A {};

template <size_t Vb>
class B {
public:
	template <size_t Va, is_big<Va, Vb> = true> 
	void func(const A<Va> a) {
		std::cout << "big!\n";
	}

	template <size_t Va, is_small<Va, Vb> = true>
	void func(A<Va>) {
		std::cout << "small!\n";
	}
};

int main (void){
	A<25> a1;
	A<15> a2;
	A<0> a3;

	B<15> b;
	b.func(a1);
	b.func(a2);
	b.func(a3);
}

```

