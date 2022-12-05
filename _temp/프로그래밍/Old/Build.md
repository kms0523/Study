빌드(build)는 소스코드를 실행파일(executable file)로 만드는 과정이며 일반적으로 아래의 4단계로 구성된다.

1.  `전처리(preprocessing) 단계` : 소스코드를 주석, 공백문자, 전처리 토큰들로 분리하고 전처리기 지시문을 처리하여 해석 유닛을 생성하는 단계
2.  `컴파일(compile) 단계` : 해석 유닛들을 문법 분석하고 어셈블리 코드를 생성하는 단계
3.  `어셈블(assemble)단계` : 어셈블리 코드들을 실제 기계어로 이루어진 목적 코드(object file)로 변환하는 단계
4.  `링킹(linking) 단계` : 각각의 목적 코드들을 모아 하나의 실행 파일로 만들어주는 단계

그러나 정적 라이브러리를 생성하는 경우에는 링킹 과정이 필요하지 않다`(?)`.

위의 전처리 단계와 컴파일 단계는 모두 컴파일러 안에서 수행되며 [C++표준](http://eel.is/c++draft/lex.phases)에 따라 총 8개의 세부 단계들로 구성되어 있다. 1-6 세부 단계까지가 전처리 과정으로 볼 수 있고, 나머지 단계를 컴파일 과정으로 볼 수 있다.

# 전처리 단계

## Phase 1: 문자들 해석하기

소스 파일에 있는 문자들을 해석한다. 기본적으로 C++ 코드에서는 총 96개의 문자들로 이루어진 basic source character set이 있는데, 이들은 다음과 같이 구성되어 있다.

-   5 종류의 공백 문자들 (스페이스, 탭, 개행 문자 등등)
-   10 종류의 숫자들 (0 부터 9 까지)
-   52 종류의 알파벳 대소문자
-   29 종류의 특수 문자들 (\_, {, + 등등)

이 기본 문자 셋에 포함되어 있지 않은 다른 모든 문자들은 $\\backslash$u 를 통해 유니코드 값으로 치환되거나, 컴파일러에 의해서 따로 해석된다. (적어도 GCC 의 경우 유니코드를 지원하므로 따로 치환되는 것은 아닌 것 같다.)

## Phase 2: $\backslash$ 문자 해석하기

백슬래시 ($\\backslash$) 문자가 문장 맨 끝 부분에 위치해있다면, 해당 문장과 바로 다음에 오는 문장을 하나로 합치고 개행 문자는 삭제한다.

## Phase 3: 전처리 토큰들로 분리하기

소스 파일을 주석(comment), 공백 문자, 전처리 토큰(preprocessing token)들로 분리한다. 전처리 토큰은 C++에서 가장 기본적인 문법 요소로 컴파일러가 사용하는 컴파일러 토큰의 근간이 된다. [전처리 토큰](http://eel.is/c++draft/lex.pptoken)은 다음을 포함한다.

-   [헤더 이름](http://eel.is/c++draft/lex.header#nt:header-name)
-   [키워드](http://eel.is/c++draft/lex.key)
-   [식별자](http://eel.is/c++draft/lex.name#nt:identifier)
-   문자/문자열 리터럴
-   연산자들 (+, #) 등...

이 단계에서 raw string literal을 확인해서 만일 1~2단계를 거치면서 해당 문자열 안의 내용이 바뀌었다면 그 변경은 취소된다. 또한 주석은 모두 공백 문자 하나로 변경된다. 참고로 컴파일러가 전처리기 토큰을 인식할 때에는 가능한 가장 긴 전처리 토큰을 만드려고 한다. 이러한 규칙을 `maximal munch` 라고 한다.

예를 들어서 아래의 코드를 보자.

```
int a = bar+++++baz
int bar = 0xE+foo
```

첫번째 줄은 `(bar++) + (++baz)`를 의도한 것이겠지만, maximal munch 규칙에 따라 컴파일러가는 가장 긴 전처리 토큰을 구성하려고 하기 때문에 `bar++ ++ +baz`로 해석되어 컴파일 오류가 발생한다. 마찬가지로 두번째줄은 `(0xE) + (foo)`를 의도한 것이겠지만 컴파일러의 경우 `0xE+ foo`로 해석해 오류가 발생한다. 그 이유는 부동 소수점 리터럴의 경우 `0xE+10`와 같이 E를 통해서 지수를 지정할 수 있기 때문이다.

## Phase 4: 전처리기 실행 단계

전처리기를 실행하는 단계로 아래의 일들을 수행한다.

-   #include 에 지정된 파일의 내용을 복사
-   #define 에 정의된 매크로를 사용해서 코드를 치환
-   #if, #ifndef 와 같은 구문들을 실행해서 코드를 치환
-   #pragma 와 같은 컴파일러 명령문들을 해석

이때, #include로 복사된 헤더 파일은 다시 Phase 1-4 단계를 거치며 이 과정은 소스 파일에 더이상의 전처리기 지시문이 없을 때 까지 지속된다.

이 단계가 끝난 소스 파일을 `해석 유닛(translation unit, TU)`이라고 한다. [C++표준](https://eel.is/c++draft/lex.separate), [wiki](https://en.wikipedia.org/wiki/Translation_unit_(programming))

### #define

#define 전처리기 지시문의 형식은 다음과 같다.

```
#define identifier token-string
```

#define은 컴파일러에게 소스 파일에서 identifier가 나타날 때마다 token-string으로 대체 하도록 지시하는 역활을 한다. 물론 identifier가 주석이나 문자열에 사용될 경우에는 대체를 하지 않는다. 대체가 되는 경우는 identifier가 토큰으로 사용될 경우뿐이다.

identifier는 함수 형식처럼 사용될 수도 있다.

```
#define identifier(identifier, ..., identifier) token-string
```

하지만 identifier를 함수 형식처럼 사용할 경우 아래 예시와 같이 의도와 다르게 동작할 수 있어 사용에 주의를 기울여야 한다.

```
#define Multiply(x,y) x * y

void main(void)
{
  const auto val1 = Multiply(2,3); 
  const auto val2 = Multiply(2,3) / Multiply(2,3); 
  //val1 = 2 * 3  = 6
  //val2 = 2 * 3 / 2 * 3 = 9 
  //val2는 원래 1을 예상하고 작성했겠지만 의도와 다르게 동작하는 경우가 생길 수 있음.
}
```

## Phase 5: 실행 문자 셋으로 변경하기

모든 문자들은 이전의 소스 코드 문자 셋에서 `실행 문자 셋(execution character set)`의 문자들로 변경된다. 마찬가지로 이전의 escaped 된 문자들도 실행 문자 셋의 문자들로 변경된다.

## Phase 6: 인접한 문자열 합치기

이 단계에서 인접한 문자열들이 하나로 합쳐진다. 예를 들어서

```
std::cout << "abc"
             "def";
```

의 경우

```
std::cout << "abcdef";
```

로 된다.

여기까지가 바로 전처리기 과정이다.

# 컴파일 단계

컴파일의 대상은 TU이다. 즉, 소스 파일이다. 헤더 파일은 특정 소스 파일이 빌드되면서 #include 전처리기 지시문에 의해 그 내용이 포함 될 뿐이다.

## Phase 7: 해석

이 단계에서는 `해석유닛(translation unit, TU)`을 `문법 분석(syntax analysis)`하여 `어셈블리 코드를 생성(code generation)`한다.

### 문법 분석

문법 분석은 원본 언어의 문법을 이해하고 원본 언어를 `추상 문법 트리(abstract syntax tree, AST)`를 만드는 단계이다. 문법 분석 단계도 `토큰화(tokenizing)`와 `파싱(parsing)`이라는 두 단계로 나뉘어 진다. 이를 의사코드로 나타내면 다음과 같다.

```
function syntaxAnalyzer(originCode) 
{
  var tokens = tokenizer(originCode)
  var AST = parser(tokens)
  return AST
}
```

#### 토큰화

토큰화 또는 `어휘 분석(lexical analysis)`, `스캐닝(scanning)`으로 불리며 문법 분석의 첫 단계이다. 토큰화는 공백이나 주석은 무시하고 원본 언어의 문자들을 언어의 문법에 정의된 기본 요소(토큰)들로 분류하는 것이다. 토큰화 되면, 토큰들은 프로그램의 기본 원소가 되며, 컴파일러의 입력도 토큰 스트림이 된다. 이를 의사코드로 나타내면 다음과 같다.

```
function tokenizer(originCode) 
{
  var tokens = [] // logic
  return tokens
}
```

토큰들은 각각 특정 분류 또는 유형으로 나뉜다. `while`은 키워드, `count`는 식별자, `<=`는 연산자라는 식이다.

아래의 예제를 보자.

```
//originCode
while (count <= 100) 
{
  count++;
}

//tokenizer에 의한 token 출력
while
(
count
<=
100
)
{
count
++
;
}
```

#### 파싱

문법 분석의 마지막 단계는 파싱 단계다. 파서는 토큰화 결과로 나온 언어 기본 요소 스트림을 언어의 문법 규칙에 맞춰 텍스트와 문법 규칙 사이의 정확한 대응 관계를 결정하는 단계다. 문법 규칙이 계층적이기 때문에 파서가 생성하는 출력은 AST라고 불리는 트리 기반 데이터 구조로 기술된다. 이를 의사코드로 나타내면 다음과 같다.

```
function parser(tokens) 
{
  var AST = {} // logic
  return AST
}
```

그리고 이전 예제의 토큰 스트림으로 AST를 만들면 다음과 같다.

```
statement
└─ whileStatement
   ├─ while
   ├─ (
   ├─ expression
   │  └─ count <= 100
   ├─ )
   └─ statement
      ├─ {
      └─ statementSequence
         ├─ statement
         │  └─ count++
         └─ ;
```

### 코드 생성

코드 생성은 AST를 통해 프로그램의 의미(semantics)를 찾고 코드를 생성한다. 코드 생성도 `가상 코드 생성(virtual code generation)`과 `대상 코드 생성(target code generation)`의 두단계로 나뉘며 이를 의사코드로 표현하면 다음과 같다.

```
function codeGenerator(AST) 
{
  var virtualCode = virtualCodeGenerator(AST)
  var targetCode = targetCodeGenerator(virtualCode)
  return targetCode
}
```

#### 가상 코드 생성

코드 생성의 첫 단계는 가상 코드 생성이다. 코드 생성을 할 때는 데이터 번역과 명령 번역이라는 두 단계에 집중하는 데, 명령 번역을 위해 우선적으로 가상 코드를 생성하게 된다. 이를 의사코드로 나타내면 다음과 같다.

```
function virtualCodeGenerator(AST) 
{
  var virtualCode = {} // logic
  return virtualCode
}
```

가상 코드 생성에 대한 예제는 다음과 같다.

```
x + g(2, y, -z) * 5 

//AST
+
├─ x
└─ *
   ├─ g
   │  ├─ 2
   │  ├─ y
   │  └─ -
   │     └─ z
   └─ 5

//가상 코드
push x
push 2
push y
push z
neg
call g
push 5
call multiply
add
```

#### 대상 코드 생성

코드 생성의 마지막 단계는 대상 코드 생성이다. 대상 코드 생성기는 가상 코드를 기반으로 대상 코드를 생성하게 되며 의사코드는 다음과 같다.

```
function targetCodeGenerator(virtualCode) 
{
  var targetCode = '' // logic
  return targetCode
}
```

### 특징

한 가지 중요한 점은 컴파일러가 어셈블리 코드를 생성할 때에는 모든 TU들을 독립적으로 생성한다는 점이다.

따라서 TU1 과 TU2가 있을 때 TU1의 어셈블리는 딱 TU1 만을 보고 결정되지 다른 TU들은 보지 않는다는 것이다. 그렇다면 문제가 생길 수 있는데 ODR 규칙에 따르면 inline이 아닌 함수의 정의는 전체 TU들에 대해 유일해야 한다. 이 떄 아래와 같이 TU1 에서 TU2에 정의된 함수 SomeFunction 사용한다면 TU1의 코드 생성 단계에서는 함수를 호출 할 때 해당 함수가 어디 있는지 알아야 하는데 해당 함수는 TU2에 정의되어 있기 때문에 도무지 알 수 없는 문제가 발생한다.

```
// main.cpp TU 1
#include <test.h>
int main() { SomeFunction(); }

// test.h
int SomeFunction();  // 선언

// test.cpp TU 2
#include <test.h>
int SomeFunction() { return 0; }
```

이러한 문제는 실행 파일을 만들 때 링킹 단계에서 목적파일들을 재배치 시켜 우리가 정의하였던 함수들의 위치가 비로소 정해지게 함으로써 해결된다.

```
$ file b.o
b.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped
```

리눅스 상에서 file 프로그램을 사용하면, 해당 파일의 대략적인 정보를 알 수 있다. file 프로그램에 따르면 우리가 생성한 목적 파일은 일반적인 ELF 파일이다. 다만 나와 있듯이 `리틀 엔디안(LSB)` 형식의 `relocatable` 파일이다. 이 재배치 가능하다(relocatable)라는 의미는 이 ELF 파일을 특정 위치에 배치할 수 있다는 의미이다. 이로써 링킹 단계에서 이 생성된 목적파일들을 재배치 시켜서 정확한 위치에 자리잡게 한다.

TU1의 목적 코드를 objdump 라는 프로그램을 사용해서 그 어셈블리를 출력한 뒤 SomeFunction() 을 호출하는 부분을 보면 다음과 같다.

```
   8:    e8 00 00 00 00           callq  d <main+0xd>
```

원래는 e8 뒤에 현재 위치로 부터 얼마만큼 떨어져 있는 곳에 있는 함수를 실행할지 그 오프셋 값이 들어가 있어야 한다. 하지만 지금은 위와 같이 그냥 0 으로 채워져있다. 왜냐하면 컴파일 단계에서는 SomeFunction이 도대체 어디에 배치될 지 알 수 없기 때문에 링킹 과정이 이루어지기 전 까지 e8 뒤에 어떤 오프셋 값을 넣어야 하는지는 알 수 없다. 그래서 위 처럼 그냥 0 으로 채워놓게 된다.

만약에 TU2를 포함하지 않고 TU1만 가지고 실행파일을 생성하려고 한다면 링커에서 오류가 발생한다. 그리고 링킹 과정에서 SomeFunction을 찾을 수 없다면 해당 부분을 채울 수 없게 된다. 따라서 종종 보이는 함수를 찾을 수 없다 라는 오류가 컴파일러 단에서 발생하는 것이 아니라 링크 단에서 발생하는 이유도 같은 맥락이다.

물론 링커 입장에서 어셈블러가 생성한 명령이 정말로 e8 00 00 00 00 일 수 도 있기 때문에 목적 파일에는 링커에게 알려주기 위해서 이 부분을 이런 식으로 고쳐라 라는 정보를 남겨놓게 된다. 이 정보를 보기 위해서는 readelf 프로그램을 사용하면 된다.

```
$ readelf -r b.o

Relocation section '.rela.text' at offset 0x230 contains 1 entry:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
000000000009  000b00000004 R_X86_64_PLT32    0000000000000000 _Z12SomeFunctionv - 4

Relocation section '.rela.eh_frame' at offset 0x248 contains 1 entry:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
000000000020  000200000002 R_X86_64_PC32     0000000000000000 .text + 0
```

readelf 프로그램은 리눅스에서 ELF 파일 정보를 보기 좋게 출력해주는 프로그램이다. -r 옵션을 주게 되면 해당 파일의 `재배치 테이블(relocation table)` 정보를 출력하게 된다. 이 재배치 테이블 중 .rela.text에선 해당 목적 파일에서 링킹 시에 수정해야할 곳의 위치와 어떠한 식으로 수정해야 할 지에 대해서 설명되어 있다.

위 경우 오프셋 9의 위치에 (정확히 e8 바로 뒤에 00 00 00 00 부분을 의미 한다) \_Z12SomeFunctionv 심볼의 정보를 R\_X86\_64\_PLT32 방식으로 덮어 씌우라고 링커에게 알려준다.


## Phase 8: 인스턴스 유닛 생성

컴파일러는 생성된 TU를 분석해서 필요로 하는 템플릿 인스턴스들을 확인한다. 템플릿들의 정의 위치가 확인이 되면 해당 템플릿들의 인스턴스화가 진행이 되고 이를 통해서 `인스턴스 유닛(instantitaion unit)`이 생성된다.

이 단계를 마치게 되면 컴파일러는 비로소 목적 코드를 생성할 수 있고 이때 생성된 목적 코드는 마지막 단계인 링킹 단계를 위해서 링커로 전달된다.

# 링킹 단계
마지막으로 링킹 단계에서는 컴파일러가 생성한 목적 파일들과 외부 라이브러리 파일들을 모아서 실행 파일을 생성한다.

링크란 수많은 목적 코드들이 프로세스 메모리 가상 공간에 적재되었을 때 서로가 맞물릴 수 있도록 각각의 주소를 변경해주는 것을 의미한다.

이 링킹 과정이 끝나게 되면 사용하는 시스템에 따라서 각기 다른 형식으로 파일들을 생성하게 된다. 윈도우즈 계열의 시스템의 경우 `portable executable (PE)`이라 불리는 PE 형식으로 실행 파일을 생성하고, 리눅스 계열의 시스템의 경우 `executable and linkable format (ELF)`이라 불리는 ELF 형식으로 실행 파일을 생성한다.

이 두 실행 파일은 파일 형식이 다르기 때문에 같은 코드를 컴파일 하더라도 윈도우즈의 PE 파일을 리눅스에서 일반적으로 실행할 수 없고, 반대로 윈도우즈에서 리눅스의 ELF 파일을 실행할 수 없다.

링킹 과정에서 목적 코드들에 정의된 심볼들 (함수들이나 객체들)의 위치를 확정 시킨다. 이 때 C++에서 심볼들의 위치들을 정할 때 어떠한 방식으로 정할지 알려주는 키워들이 있는데 이를 `저장 방식 지정자 (storage class specifier)`라고 한다.

## 저장 방식 지정자 
[cpp reference](https://en.cppreference.com/w/cpp/language/storage_duration)에 따르면 C++에서 허용하는 저장 방식 지정자는 아래와 같이 총 4 가지가 있다.

* static
* thread_local
* extern
* mutable (이 지정자는 저장 기간과 링크 방식에 영향을 주지 않는다.)

이전에는 auto 와 register 지정자들도 있었는데 각각 C++11과 C++17에서 사라졌다. 이 키워드들을 통해 심볼들의 `저장 기간(Storage duration)`과 `링크 방식(Linkage)`이라는 두 가지 중요한 정보들을 지정할 수 있다.

### 저장 기간
프로그램에서의 모든 객체들의 경우 반드시 아래 넷 중에 한 가지 방식의 저장 기간을 가지게 된다.

#### 자동 (automatic) 저장 기간
여기에 해당하는 객체들은 보통 {} 안에 정의된 객체들로 코드 블록을 빠져나가게 되면 자동으로 소멸하게 된다. static, extern, thread_local로 지정된 객체들 이외의 모든 지역 객체들이 자동 저장 기간을 가지게 된다. 쉽게 말해 우리가 흔히 생각하는 지역 변수들이 여기에 해당된다.

```cpp
int func() 
{
  int a;            //자동 저장 기간
  SomeObject x;     //자동 저장 기간

  {
    std::string s;  //자동 저장 기간
  }
}
```

#### static 저장 기간
static 저장 기간에 해당하는 객체들은 프로그램이 시작할 때 할당 되고, 프로그램이 끝날 때 소멸되며 유일하게 존재한다. 예를 들어서 지역 변수의 경우 만일 여러 쓰레드에서 같은 함수를 실행한다면 같은 지역 변수의 복사본들이 여러 군데 존재하겠지만 static 객체들은 이 경우에도 유일하게 존재한다.

보통 함수 밖에 정의된 것들이나 (즉 namespace 단위에서 정의된 것들) static 혹은 extern 으로 정의된 객체들이 static 저장 기간을 가진다. 참고로 static 키워드와 static 저장 기간을 가진다는 것을 구분해야 한다. static 키워드가 붙은 객체들이 static 저장 기간을 가지는 것은 맞지만, 다른 방식으로 정의된 것들도 static 저장 기간을 가질 수 있다.

```cpp
int a;              // 전역 변수, static 저장 기간
namespace ss 
{
    int b;          // static 저장 기간
}

extern int a;       // static 저장 기간
int func() 
{
  static int x;     // static 저장 기간
}
```

#### 쓰레드 저장 기간
쓰레드(thread) 저장 기간에 해당하는 객체들은 쓰레드가 시작할 때 할당 되고, 쓰레드가 종료될 때 소멸되며 각 쓰레드들이 해당 객체들의 복사본들을 가진다. thread_local로 선언된 객체들이 이 쓰레드 저장 기간을 가질 수 있다.

```cpp
#include <iostream>
#include <thread>

thread_local int i = 0;

void g() { std::cout << i; }

void threadFunc(int init) {
  i = init;
  g();
}

int main() {
  std::thread t1(threadFunc, 1);
  std::thread t2(threadFunc, 2);
  std::thread t3(threadFunc, 3);

  t1.join();
  t2.join();
  t3.join();

  std::cout << i;   //main thread는 항상 0
}
```

예를 들어서 위 예제를 살펴보자. 몇 번 실행하다보면 1230, 2130, 3120등과 같은 결과를 볼 수 있다. 그 이유는 thread_local 로 정의된 i가 각 쓰레드에 유일하게 존재하기 때문이다. 마치 정의는 전역 변수인 것 처럼 되어 있지만, 실제로는 각 쓰레드에 하나씩 복사본이 존재하게 되고, 각 쓰레드 안에서 해당 i를 전역 변수인것마냥 참조할 수 있다.

#### 동적 저장 기간
동적(dynamic) 저장 기간의 경우 동적 할당 함수를 통해서 할당되고 해제되는 객체들을 의미 한다. 대표적으로 new와 delete로 정의되는 객체들 이다. 이러한 저장 방식은 나중에 링커에서 해당 변수나 함수들을 배치시에 어디에 배치할 지 중요한 정보로 사용된다.

### 링크 방식
앞선 저장 방식이 객체들에게만 해당되는 내용이였다면 링크 방식의 경우 C++의 모든 객체, 함수, 클래스, 템플릿, 이름 공간 등등을 지칭하는 이름들에 적용되는 내용이다. 이 링크 방식에 따라서 어떤 이름이 어디에서 사용될 수 있는지 지정할 수 있으며 C++에선 아래와 같은 링크 방식들을 제공한다. 

#### 링크 방식 없음 
블록 스코프 ({}) 안에 정의되어 있는 이름들이 이 경우에 해당한다. (extern 으로 지정되지 않는 이상) 링크 방식이 지정되지 않는(no linkage) 개체들의 경우에는 같은 스코프 안에서만 참조할 수 있다.

```cpp
{ int a = 3; }  //변수 a는 {} 안에 링크 방식이 없는 상태로 정의
a;              //scope 밖에서 a를 참조할 수 없어서 오류 
```

#### 내부 링크 방식 
static으로 정의된 함수, 변수, 템플릿 함수, 템플릿 변수들이 내부 링크 방식에 해당된다. `내부 링크 방식(internal linkage)`으로 정의된 것들은 같은 TU안에서만 참조 할 수 있다. 그 외에도 익명의 이름 공간에 정의된 함수나 변수들 모두 내부 링크 방식이 적용된다. 

```cpp
namespace 
{
int a;          // 내부 링크 방식
}
static int a;   // 이와 동일한 의미
```

#### 외부 링크 방식 
`외부 링크 방식(external linkage)`으로 정의된 개체들은 다른 TU에서도 참조 가능하다. 참고로 외부 링크 방식으로 정의된 개체들에 언어 링크 방식을 정의할 수 있어서, 다른 언어 (C 와 C++) 사이에서 함수를 공유하는 것이 가능하다.

앞서 링크 방식이 없는 경우나 내부 링크 방식을 개체들을 정의하는 경우를 제외하면 나머지 모두 외부 링크 방식으로 정의됨을 알 수 있다. 참고로, 블록 스코프 안에 정의된 변수를 외부 링크 방식으로 선언하고 싶다면 extern 키워드를 사용하면 된다.

언어 링크 방식을 선언하고 싶다면 아래와 같이 하면 된다.

``` cpp
extern "C" int func();  // C 및 C++ 에서 사용할 수 있는 함수



extern "C++" int func2();   // C++ 에서만 사용할 수 있는 함수
                            // 기본적으로 C++ 의 모든 함수들에 extern "C++" 이 숨어 있다고 보면 된다.
int func2();                // 위와 동일
```

## 이름 맹글링
앞서 C에서 C++의 함수를 사용하기 위해서는 extern "C" 로 언어 링크 방식을 명시해주어야 한다는 것을 보았다. 그 이유는, 목적파일 생성시 C컴파일러가 함수 이름을 변환하는 방식과 C++컴파일러가 함수 이름을 변환하는 방식이 다르기 때문이다.

일단 C의 경우 함수 이름 변환 자체가 이루어 지지 않는다. 만약에 아래와 같이 func이란 함수를 정의했다고 가정하자.

```cpp
int func(const char* s) {}
```

이를 C 컴파일러가 컴파일 하면 변환된 이름은 그냥 func 임을 알 수 있다.

```
$ nm a.out
0000000000000000 T func
```
참고로 nm 은 목적 파일에 정의되어 있는 심볼들을 모두 출력해주는 프로그램이다.

반면에 똑같은 소스코드를 C++ 컴파일러로 컴파일하게 되면 아래와 같이 함수의 이름이 바뀐것을 알 수 있다.

```
$ nm a.out
0000000000000000 T _Z4funcPKc
```

이와 같이 C++에서는 목적 코드 생성시에 컴파일러가 함수의 이름을 바꾸는 것을 볼 수 있다. 이를 `이름 맹글링(name mangling)`이라 하는데, 맹글링이라는 단어의 뜻이 원래 엉망진창으로 만들다 라는 의미다. 실제로 함수의 이름이 func에서 알아보기 힘든 버전으로 바뀌었다.

이렇게 이름 맹글링을 하는 이유는 C와 다르게 C++에서는 같은 이름의 함수를 정의할 수 있기 때문이다. C++의 경우 일단 함수의 오버로딩을 통해서 인자가 다른 같은 이름의 함수들을 정의할 수 있고 인자와 이름이 모두 똑같더라도 다른 이름 공간에 들어가 있다면 다른 함수로 취급된다. 따라서, 함수의 이름 자체만으로는 어떤 함수를 호출할 지 구분할 수 가 없게 된다.

이름 맹글링을 하게 되면 원래의 함수 이름에 이름 공간 정보와 함수의 인자 타입 정보들이 추가된다. 따라서 같은 이름의 함수일 지라도, 이름 맹글링을 거치고 다면 다른 이름의 함수로 바뀌기 때문에 링킹을 성공적으로 수행할 수 있다.

실제로 아래 함수들의 이름들은 모두 같지만

```cpp
int func(const char* s) {}
int func(int i) {}
int func(char c) {}

namespace n 
{
int func(const char* s) {}
int func(int i) {}
int func(char c) {}
}  // namespace n
```

맹글링 된 이름을 살펴보면 전부다 다른 이름으로 변환된 것을 볼 수 있다.

```
$ nm test.o
000000000000001d T _Z4funcc
000000000000000f T _Z4funci
0000000000000000 T _Z4funcPKc
000000000000004a T _ZN1n4funcEc
000000000000003c T _ZN1n4funcEi
000000000000002d T _ZN1n4funcEPKc
```

참고로 컴파일러마다 이름 맹글링을 하는 방식이 조금씩 다르기 때문에 A 컴파일러에서 생성한 목적 코드를 B 컴파일러가 링킹할 때 문제가 될 수 있다.

C에서 C++의 함수를 호출하기 위해서는 반드시 이름 맹글링이 되지 않는 함수 심볼을 생성해야 한다. 따라서 extern "C" 를 통해서 이 함수는 이름 맹글링을 하지 마! 라고 컴파일러에게 전달할 수 있다.


## 링킹

위 단계에서 아무런 문제가 없었더라면 이제 비로소 진짜 링킹을 수행할 수 있다. 링킹이란, 각각의 TU들에서 생성된 목적 코드들을 한데 모아서 하나의 실행 파일을 만들어내는 작업이다. 물론 단순히 목적 코드들을 이어 붙이는 작업만 하는 것은 아니다.

링킹 과정이 끝나기 전 까지 변수들과 함수, 그리고 데이터들의 위치를 확정시킬 수 없다. 따라서 TU들이 생성한 목적 코드들에게는 각각의 심볼들의 저장 방식과 링크 방식에 따라서 여기 여기에 배치했으면 좋겠다라는 희망 사항이 작성되어 있다.

예를 들어서 아래의 코드를 보자.

```
static int a = 3;
int b = 3;
static const int c = 3;
static int d;

int func() {}
static int func2() {}
```

이 코드에 정의된 심볼들의 희망 위치들은 아래와 같이 나타난다.

```
$ nm test.o
0000000000000004 D b
0000000000000000 T _Z4funcv
0000000000000000 d _ZL1a
0000000000000000 r _ZL1c
0000000000000000 b _ZL1d
000000000000000b t _ZL5func2v
```

nm 프로그램은 심볼들의 이름들 왼쪽에 어떠한 방식으로 링크시에 심볼을 배치할지에 대한 정보를 보여준다.

대문자 알파벳의 경우 해당 심볼은 외부 링크 방식으로 선언된 심볼이란 의미이다. 즉 해당 심볼은 다른 TU에서 접근할 수 있는 심볼이다. 반면에 소문자 알파벳의 경우 해당 심볼은 내부 링크 방식으로 선언된 심볼이란 의미이다. 따라서 해당 심볼은 이 TU 안에서만 접근이 가능하다.

위 대문자로 된 심볼들을 보면 b, func 을 볼 수 있는데 모두 외부 링크 방식임을 알 수 있다. 반면에 나머지 a, c, d, func2는 모두 static 이므로 내부 링크 방식이다.

그 다음에 알파벳 자체는 어떤 방식으로 해당 심볼들을 배치할 지 알려준다. [nm의 man 페이지](https://linux.die.net/man/1/nm)에서 전체 알파벳들에 대한 설명을 볼 수 있으며 그 중 일부는 다음과 같다.

-   B, b : 초기화 되지 않은 데이터 섹션 (BSS 섹션)
-   D, d : 초기화 된 데이터 섹션
-   T, t : 텍스트 (코드) 섹션
-   R, r : 읽기 전용 (read only) 섹션

맨 앞에 오는 정수값은 섹션의 시작으로부터 해당 심볼이 어디에 위치해 있는지 알려준다. 예를 들어서 func함수의 경우 텍스트 섹션 시작 부분에 있다는 의미 이고 (오프셋이 0 이니까), func2 의 경우 b 만큼 떨어진 부분에 위치해있다는 의미다.

실제로 objdump 로 코드를 살펴보면

```
objdump -S s.o 

s.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z4funcv>:
   0:    f3 0f 1e fa              endbr64 
   4:    55                       push   %rbp
   5:    48 89 e5                 mov    %rsp,%rbp
   8:    90                       nop
   9:    5d                       pop    %rbp
   a:    c3                       retq   

000000000000000b <_ZL5func2v>:
   b:    f3 0f 1e fa              endbr64 
   f:    55                       push   %rbp
  10:    48 89 e5                 mov    %rsp,%rbp
  13:    90                       nop
  14:    5d                       pop    %rbp
  15:    c3                       retq   
```

정확히 0xb 부분에 func2 가 자리하고 있음을 알 수 있습니다. 여기서 0x는 뒤에 오는 숫자가 16진수임을 말한다.

### 재배치

TU에서 생성된 목적 코드들은 링킹 과정 전까지 심볼들의 위치를 확정할 수 없기 때문에 추후에 심볼들의 위치가 확정이 되면 값을 바꿔야 할 부분들을 적어놓은 재배치 테이블 (Relocation Table)을 생성한다.

예를 들어서 아래와 같은 코드를 보자.

```
static int a = 3;
int b = 3;
static int c;

static int func2() {
  c += a + b;
  return c;
}

int func3() {
  b += c;
  return b;
}

int func() {
  a += func2();
  a += func3();
  return a;
}
```

objdump 에 -r 옵션을 주면 재배치가 필요한 부분들을 보여준다.

예를 들어서 func2 의 목적 코드가 어떤 식으로 생겼는지 살펴보자.

```
objdump -Sr s.o

s.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_ZL5func2v>:
static int a = 3;
int b = 3;
static int c;

static int func2() {
   0:    f3 0f 1e fa              endbr64 
   4:    55                       push   %rbp
   5:    48 89 e5                 mov    %rsp,%rbp
  c = a + b;
   8:    8b 15 00 00 00 00        mov    0x0(%rip),%edx        # e <_ZL5func2v+0xe>
            a: R_X86_64_PC32    .data-0x4
   e:    8b 05 00 00 00 00        mov    0x0(%rip),%eax        # 14 <_ZL5func2v+0x14>
            10: R_X86_64_PC32    b-0x4
  14:    01 d0                    add    %edx,%eax
  16:    89 05 00 00 00 00        mov    %eax,0x0(%rip)        # 1c <_ZL5func2v+0x1c>
            18: R_X86_64_PC32    .bss-0x4
  return c;
  1c:    8b 05 00 00 00 00        mov    0x0(%rip),%eax        # 22 <_ZL5func2v+0x22>
            1e: R_X86_64_PC32    .bss-0x4
}
  22:    5d                       pop    %rbp
  23:    c3                       retq   
```

내부 및 외부 링크 방식인 a, b, c 들은 데이터 섹션과 BSS 섹션의 위치가 확정되기 전까지 어디에 위치할 지 모르기 때문에 추후에 재배치 시켜야만 한다.

먼저, a 의 값을 읽어들이는 부분부터 보자.

```
  8:    8b 15 00 00 00 00        mov    0x0(%rip),%edx        # e <_ZL5func2v+0xe>
```

먼저 `0x0(%rip),%edx` 어셈블리는 C 코드로 바꿔서 생각했을 때 `%edx = *(int*)(%rip + 0x0)` 이라고 보면 된다. 즉 RIP 레지스터에다 0만큼 더한 주소값에 있는 데이터를 읽으라는 의미이다. 여기서 a 의 상대적 위치가 결정되지 않았기 때문에 일단 0으로 대체되어 있다.

만일 a 가 어디에 배치되는지 위치가 확정이 된다면,

```
$ readelf -r s.o
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
00000000000a  000300000002 R_X86_64_PC32     0000000000000000 .data - 4
```

위와 같이 해당 부분을 R\_X86\_64\_PC32의 형태로 재배치 하라고 써져 있다. (위 objdump 출력에도 나와있다.) 레퍼런스에 따르면 R\_X86\_64\_PC32은 해당 부분 4 바이트 영역을 S + A - P를 계산한 값으로 치환해라 라는 의미이다.

이 때 S, A, P 는 각각

-   S : 재배치 후에 해당 심볼의 실제 위치
-   P : 재배치 해야하는 부분의 위치
-   A : 더해지는 값으로, 재배치 테이블에서 그 값을 확인할 수 있다.

일단 readelf를 통해 확인했을 때 일단 A 의 값은 -4 임을 알 수 있다(Addend 부분). 나머지 부분은 링킹 후에 심볼들의 위치가 정해져야지 알 수 있다.

따라서 간단히 int main{} 만 있는 파일과 같이 링크해보도록 하자. nm 을 통해서 우리의 경우 a는 4010에 위치 되어 있는 것을 확인할 수 있다.

```
$ nm s
0000000000004010 d _ZL1a
```

따라서 S는 0x4010이 된다.

func2 는 1138 에 위치해있으므로 (마찬가지로 nm 을 통해서 확인 가능)

```
$ nm s
0000000000001138 t _ZL5func2v
```

P에서 A를 더한값이 재배치 해야 되는 부분 즉 func2의 위치인 0x1138이 되어야 함으로 P는 4를 더한 만큼인 0x1142가 된다. 따라서 P는 0x1142 이므로, S + A - P = 0x4010 - 0x4 - 0x1142 = 0x2ECA가 된다.

```
0000000000001138 <_ZL5func2v>:
static int a = 3;
int b = 3;
static int c;

static int func2() {
    1138:    f3 0f 1e fa              endbr64 
    113c:    55                       push   %rbp
    113d:    48 89 e5                 mov    %rsp,%rbp
  c = a + b;
    1140:    8b 15 ca 2e 00 00        mov    0x2eca(%rip),%edx        # 4010 <_ZL1a>
    1146:    8b 05 c8 2e 00 00        mov    0x2ec8(%rip),%eax        # 4014 <b>
    114c:    01 d0                    add    %edx,%eax
    114e:    89 05 c8 2e 00 00        mov    %eax,0x2ec8(%rip)        # 401c <_ZL1c>
  return c;
    1154:    8b 05 c2 2e 00 00        mov    0x2ec2(%rip),%eax        # 401c <_ZL1c>
}
    115a:    5d                       pop    %rbp
    115b:    c3                       retq   
```

실제로 해당 부분이 ca 2e 00 00 으로 바뀐 것을 확인할 수 있다. 리틀 엔디언임을 고려하면 해당 값이 0x2ECA 임을 알 수 있다. `0x2eca(%rip)`의 의미는 RIP 레지스터에서 0x2ECA만큼 떨어진 곳에서 4 바이트 만큼 읽어서 EDX 레지스터에 저장하라는 의미 이다. 해당 명령어를 실행할 때 RIP에는 다음에 실행할 명령어의 위치가 들어가 있으니,  0x1146 + 0x2ECA = 0x4010 에 위치한 곳의 4바이트를 읽어들인다. 즉 정확히 변수 a가 위치해있는 곳을 읽게 된다.

이번에는 func3를 보자.

```
  45:    48 89 e5                 mov    %rsp,%rbp
  a += func2();
  48:    e8 b3 ff ff ff           callq  0 <_ZL5func2v>
  4d:    8b 15 00 00 00 00        mov    0x0(%rip),%edx        # 53 <_Z4funcv+0x13>
            4f: R_X86_64_PC32    .data-0x4
  53:    01 d0                    add    %edx,%eax
  55:    89 05 00 00 00 00        mov    %eax,0x0(%rip)        # 5b <_Z4funcv+0x1b>
            57: R_X86_64_PC32    .data-0x4
  a += func3();
  5b:    e8 00 00 00 00           callq  60 <_Z4funcv+0x20>
            5c: R_X86_64_PLT32    _Z5func3v-0x4
  60:    8b 15 00 00 00 00        mov    0x0(%rip),%edx        # 66 <_Z4funcv+0x26>
            62: R_X86_64_PC32    .data-0x4
  66:    01 d0                    add    %edx,%eax
  68:    89 05 00 00 00 00        mov    %eax,0x0(%rip)        # 6e <_Z4funcv+0x2e>
            6a: R_X86_64_PC32    .data-0x4
  return a;
  6e:    8b 05 00 00 00 00        mov    0x0(%rip),%eax        # 74 <_Z4funcv+0x34>
            70: R_X86_64_PC32    .data-0x4
}
  74:    5d                       pop    %rbp
  75:    c3                       retq   
```

먼저 static 함수인 func2 를 호출하는 부분부터 보자.

```
a += func2();
  48:    e8 b3 ff ff ff           callq  0 <_ZL5func2v>
```

놀랍게도 이 부분의 경우 재배치가 지정되지 않고 실제 func2의 위치가 그대로 들어가 있음을 알 수 있다. 왜냐하면 이 callq의 경우 현재의 RIP에서 상대 위치를 받는데, 0xFFFFFFB3 가 2 의 보수 표현법으로 -0x4D 이므로, 정확히 주소값 0을 의미한다(0x4D - 0x4D = 0). 그리고 실제로 0번에 func2 함수가 위치하고 있다. 그 이유는 static 함수의 경우 내부 링크 방식이기 때문에 TU밖에서 참조될 일이 없기 때문이다. 이 때문에 컴파일 타임에 함수의 위치를 확정시킬 수 있다.

반면에 외부 링크 방식으로 된 일반적인 func3 함수를 호출하는 부분을 보자.

```
a += func3();
  5b:    e8 00 00 00 00           callq  60 <_Z4funcv+0x20>
            5c: R_X86_64_PLT32    _Z5func3v-0x4
```

이 경우 R\_X86\_64\_PLT32의 형태로 링크를 하고 있다. R\_X86\_64\_PLT32의 경우 `프로시져 링크 테이블(procedure linkage table)`을 사용한 링킹 방식으로 `동적 링크 방식(dynamic linking)`에서 사용된다. 하지만 동적 링크 방식을 사용하지 않았을 경우, 그냥 R\_X86\_64\_PC32 와 동일하다고 보면 된다. 이 예제에서는 실행 파일을 생성하기 위해 동적 링크 방식을 사용하지 않았으므로 그냥 R\_X86\_64\_PC32 와 같은 식으로 계산된다.

실제로 완성된 코드를 살펴보자면

```
    1194:    e8 c4 ff ff ff           callq  115d <_Z5func3v>
```

와 같이 되어 있는데, 00 00 00 00 부분이 현재의 RIP 로 부터 상대적 위치값으로 변경되어 있음을 알 수 있다.

### 링킹 방식
컴파일러가 여러 목적 파일들을 링킹하는 방식은 `정적 링킹(static linking)`과 `동적 링킹(dynamic linking)` 두 가지로 구분된다. 정적 링킹은 `정적 라이브러리(static library)`를 링킹하는 방식이고, 동적 링킹은 `동적 라이브러리(dynamic library)`, 다른 말로 `공유 라이브러리(shared library)`를 링킹하는 방식이다. 

이 두 라이브러리의 차이를 이해하기 위해서 먼저 정적 라이브러리가 뭔지 알아보자.

#### 정적 라이브러리
라이브러리란 프로그램이 동작하기 위해 필요한 외부 목적 코드들이다.예를 들어서 C++에서 iostream 헤더파일을 include 했다면, 이 프로그램이 실행하기 위해서는 iostream 라이브러리가 있어야 한다. 

이 때 정적 라이브러리는 우리가 필요로 하는 라이브러리가 링킹 후에 완성된 프로그램 안에 포함된다고 이해할 수 있다. 쉽게 말해 실행 파일 자체에 해당 라이브러리 코드가 딱 박혀서 있기 때문에 정적(static)이라고 하는 것이다. 예를 들어서 어떤 프로그램이 A라는 라이브러리와 B라는 라이브러리를 사용하고 있다면 프로그램의 어셈블리를 출력하였을 때 A와 B 라이브러리의 모든 코드들이 들어있게 된다.

어떻게 생각하면 당연한 일이다. 프로그램을 실행하기 위해선 당연히 해당 프로그램이 필요로 하는 코드들이 프로그램 안에 있어야 되기 때문이다. 정적 라이브러리가 어떻게 링크 되는지 GCC 컴파일러를 사용해서 간단한 정적 라이브러리를 만들어보면서 확인해보자.

##### 정적 라이브러리 만들기
예를 들어서 foo 라는 함수를 제공하는 foo.cc 파일과 bar 라는 함수를 제공하는 bar.cc 파일이 있다고 하자.

```cpp
// bar.h
void bar();
 
// bar.cc
void bar() {}
 
// foo.h
int foo();
 
// foo.cc
#include "bar.h"
int x = 1;

int foo() {
  bar();
  x++;
  return 1;
}
```

이 두 파일들을 각각 컴파일 하면 foo.o 와 bar.o 라는 목적 코드가 생성이 된다. 만일 이 두 함수를 제공하는 정적 라이브러리를 만들기 위해서는, 이 두 목적 파일들을 하나로 묶어주기만 하면 된다. 

```
$ ar crf libfoobar.a foo.o bar.o
```

다음 명령어를 통해 libfoobar.a 라는 정적 라이브러리 파일이 만들 수 있다. 리눅스에선 통상적으로 정적 라이브러리 파일은 .a 의 확장자를 가진다. 이 libfoobar.a 은 거창한 것이 아니고 그냥 foo.o의 내용과 bar.o의 내용을 하나로 합쳐놓은 것이다. 실제로 objdump 로 libfoobar.a 의 내용을 열어보면 foo.o와 bar.o가 하나로 합쳐진 파일인걸 알 수 있다. (마치 리눅스에서 tar 로 파일들을 합친 것과 비슷하다)

```
objdump -S libfoobar.a
In archive libfoobar.a:

foo.o:     file format elf64-x86-64

Disassembly of section .text:

0000000000000000 <_Z3foov>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	e8 00 00 00 00       	callq  d <_Z3foov+0xd>
   d:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 13 <_Z3foov+0x13>
  13:	83 c0 01             	add    $0x1,%eax
  16:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 1c <_Z3foov+0x1c>
  1c:	b8 01 00 00 00       	mov    $0x1,%eax
  21:	5d                   	pop    %rbp
  22:	c3                   	retq   

bar.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z3barv>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	90                   	nop
   9:	5d                   	pop    %rbp
   a:	c3                   	retq   
```

이 정적 라이브러리를 사용하는 방법은 간단하다.

예를 들어서 main.cc 라는 파일에서 foo 함수를 사용하고 싶다고 하자. 그렇다면 우리가 필요한 것은 foo 함수가 선언 되어 있는 헤더파일 하나 뿐이다.

```cpp
#include "foo.h"

int main() { foo(); }
```

통상적인 상황이라면 main 을 컴파일 하면서 실행파일을 생성할 때, foo.cc 코드와 bar.cc 코드를 같이 컴파일 해서 링킹해야 한다. 하지만 우리는 이미 foo.cc 와 bar.cc 가 이미 컴파일 되어 있는 libfoobar.a 라는 라이브러리가 있기 때문에 굳이 이들을 다시 컴파일 할 필요가 없다.

따라서 실행 파일을 생성 시에 링크만 해주면 된다.

```
$ g++ main.cc libfoobar.a -o main 
```

실제 main 의 내용을 objdump 로 살펴보면

```
objdump -S main
... (생략) ...
0000000000001129 <main>:
    1129:	f3 0f 1e fa          	endbr64 
    112d:	55                   	push   %rbp
    112e:	48 89 e5             	mov    %rsp,%rbp
    1131:	e8 07 00 00 00       	callq  113d <_Z3foov>
    1136:	b8 00 00 00 00       	mov    $0x0,%eax
    113b:	5d                   	pop    %rbp
    113c:	c3                   	retq   

000000000000113d <_Z3foov>:
    113d:	f3 0f 1e fa          	endbr64 
    1141:	55                   	push   %rbp
    1142:	48 89 e5             	mov    %rsp,%rbp
    1145:	e8 16 00 00 00       	callq  1160 <_Z3barv>
    114a:	8b 05 c0 2e 00 00    	mov    0x2ec0(%rip),%eax        # 4010 <x>
    1150:	83 c0 01             	add    $0x1,%eax
    1153:	89 05 b7 2e 00 00    	mov    %eax,0x2eb7(%rip)        # 4010 <x>
    1159:	b8 01 00 00 00       	mov    $0x1,%eax
    115e:	5d                   	pop    %rbp
    115f:	c3                   	retq   

0000000000001160 <_Z3barv>:
    1160:	f3 0f 1e fa          	endbr64 
    1164:	55                   	push   %rbp
    1165:	48 89 e5             	mov    %rsp,%rbp
    1168:	90                   	nop
    1169:	5d                   	pop    %rbp
    116a:	c3                   	retq   
    116b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
```

위 처럼 libfoobar.a의 내용이 그대로 포함되어 있는것을 볼 수 있다.

이렇게 정적 라이브러리는 링크 타임에 바인딩 된다.

#### 공유 라이브러리 (동적 라이브러리)
정적 라이브러리에는 프로그램 실행에 필요한 모든 코드가 들어가 있기 때문에 환경에 크게 관계 없이 프로그램을 실행 시킬 수 있다. 하지만 이 방식은 몇 가지 문제점들이 있다.

1. 표준 C 라이브러리인 libc 의 경우 많은 프로그램들이 필요로 한다. 그런데 libc 라이브러리에는 C 라이브러리의 모든 함수들의 구현이 들어가 있기 때문에 크기가 매우 크다(약 2MB). 따라서 libc를 프로그램에 정적으로 링크하게 된다면 모든 프로그램의 크기가 최소 2MB가 된다. 심지어 모든 프로그램들이 동일한 libc 라이브러리를 사용하고 있다고 해도 말이다.

2. 물론 요즘 세상에 2 MB 정도야 라고 생각할 수 있다. 하드 디스크는 용량이 크기 때문이다. 하지만 문제는 메모리다. 프로그램이 실행되면 프로그램이 메모리에 로드 되는데, 모든 프로그램들이 똑같은 libc 코드들을 메모리에 올린다면 엄청난 메모리 낭비다. 게다가 메모리는 하드 디스크 보다 훨씬 더 귀한 자원이다.

3. 예를 들어서 새 버전의 libc 나와서 이를 내 시스템에 적용시키고 싶다고 가정하자. 만일 프로그램들이 libc를 정적으로 링킹하고 있다면 이 프로그램들을 모두 다시 컴파일해야 한다.

4. 마지막 문제로 정적 라이브러리 전체를 링킹하면서 사용하지 않는 함수들 까지 전부다 프로그램에 포함된다. 이도 마찬가지로 용량 낭비를 유발한다.

컴퓨터 개발자들은 이러한 문제들을 해결하기 위해 획기적인 방법을 제시한다. 앞서 정적 라이브러리의 가장 큰 문제점은 "모든 프로그램들이 같은 라이브러리를 링킹 하더라도 정적으로 링킹할 경우 프로그램 내에 동일한 라이브러리 코드를 포함해야 한다" 였다. 그렇다면 "많은 프로그램 상에서 사용되는 라이브러리를 컴퓨터 메모리 상에 딱 하나 올려놓고 이를 사용하는 프로그램들이 해당 라이브러리를 공유 하면 어떨까?"는 생각이 바로 공유 라이브러리의 출발이다.

[그림]

공유 라이브러리를 사용할려면 서로 다른 프로그램이 같은 메모리를 공유할 수 있어야 하는데 각 프로세스들은 다른 프로세스들과 독립적이고 서로 접근할 수 없는 메모리를 갖고 있다. 이러한 문제는 페이지 테이블을 통해 해결한다.

[그림]

프로세스마다 코드의 크기가 다르기 때문에 공유 라이브러리가 각 프로세스의 가상 메모리에 놓이는 위치가 다르게 된다. 위 그림 처럼 프로세스 1 의 libc 는 0x1234 에, 프로세스 2 의 libc 는 0xABCD 에, 프로세스 3 의 libc 는 0x10 에 놓여 있다. 이 때 위의 그림처럼 각각의 프로세스에는 가상 메모리를 물리 메모리로 변환하는 고유의 페이지 테이블이 있다. 이를 통해 실제 물리 메모리에 libc 코드를 딱 한 군데만 올려 놓고 각 프로세스의 페이지 테이블 내용을 바꿔줌으로써 마치 프로세스 마다 고유의 위치에 libc 코드가 있는 것 처럼 사용할 수 있다. 

그렇다면 한가지 궁금증이 생긴다. "그냥 정적 라이브러리를 공유 라이브러리 처럼 쓰면 안되나?". 

앞서 말했듯이 공유 라이브러리의 경우 프로세스의 가상 메모리 안의 임의의 위치에 로드될 수 있어야 한다. 이런 방식이 가능할지 앞서 만들었던 libfoobar.a 에서의 foo 함수의 어셈블리 코드를 다시 보자.

```
000000000000113d <_Z3foov>:
    113d:	f3 0f 1e fa          	endbr64 
    1141:	55                   	push   %rbp
    1142:	48 89 e5             	mov    %rsp,%rbp
    1145:	e8 16 00 00 00       	callq  1160 <_Z3barv>
    114a:	8b 05 c0 2e 00 00    	mov    0x2ec0(%rip),%eax        # 4010 <x>
    1150:	83 c0 01             	add    $0x1,%eax
    1153:	89 05 b7 2e 00 00    	mov    %eax,0x2eb7(%rip)        # 4010 <x>
    1159:	b8 01 00 00 00       	mov    $0x1,%eax
    115e:	5d                   	pop    %rbp
    115f:	c3                   	retq  
```

위 처럼 x 의 값을 읽는 부분에서 실제 x 의 주소값으로 값이 대체된 것을 볼 수 있다. 다시 말해 정적 라이브러리는 외부 링크 방식을 가지는 심볼들을 호출하는 부분이 모두 해당 심볼들의 실제 주소값으로 대체되어 있다. 이 경우 해당 라이브러리 코드를 메모리 임의의 지점에 불러온다면 우리가 원하는 심볼들을 찾을 수 없게 된다.

따라서 공유 라이브러리의 경우 정적 라이브러리와 다른 방식으로 외부 링크 방식을 가지는 심볼들을 불러온다. 그 차이를 알기 위해 먼저 공유 라이브러리를 한 번 만들어보자.

##### 공유 라이브러리 만들기
공유 라이브러리는 컴파일러를 통해서 제작할 수 있다. 만약에 원래 하던 것 처럼 foo.cc 와 bar.cc 를 컴파일 해보자.

```
$ g++ -shared foo.o bar.o -o libfoobar.so
/usr/bin/ld: foo.o: relocation R_X86_64_PC32 against symbol `x' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: final link failed: bad value
collect2: error: ld returned 1 exit status
```

그렇다면 위와 같은 오류 메세지를 볼 수 있다. 오류 메세지를 그대로 해석해보면 x 심볼에 적용된 R_X86_64_PC32 방식은 공유 라이브러리를 만드는데 사용할 수 없다는 의미이다. 

한 번 objdump 로 x 심볼이 사용되는 foo.o 의 재배치 방식을 살펴보자.

```
 objdump -Sr foo.o

foo.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z3foov>:
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
   8:	e8 00 00 00 00       	callq  d <_Z3foov+0xd>
			9: R_X86_64_PLT32	_Z3barv-0x4
   d:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 13 <_Z3foov+0x13>
			f: R_X86_64_PC32	x-0x4
  13:	83 c0 01             	add    $0x1,%eax
  16:	89 05 00 00 00 00    	mov    %eax,0x0(%rip)        # 1c <_Z3foov+0x1c>
			18: R_X86_64_PC32	x-0x4
  1c:	b8 01 00 00 00       	mov    $0x1,%eax
  21:	5d                   	pop    %rbp
  22:	c3                   	retq   
  ```

실제로 x 심볼을 참조하는 부분에서 R_X86_64_PC32 방식을 사용하고 있는 것을 알 수 있다. 그렇다면 왜 R_X86_64_PC32 재배치 방식을 공유 라이브러리를 만드는데 사용할 수 없을까? 그 이유는 R_X86_64_PC32 방식을 계산할 때 S + A - P 를 사용하는데 공유 라이브러리의 경우 임의의 위치에 라이브러리가 위치할 수 있기 때문에 섹션의 위치를 특정할 수 없다. 따라서 S + A - P 의 값 자체를 계산할 수 가 없게 된다.

따라서 결국에는 foo.cc 와 bar.cc 를 다시 컴파일 해야 한다. 이 때 컴파일 시에 인자로 `위치와 무관한 코드 (position independent code,PIC)` 를 만들라는 의미의 -fpic 인자를 전달해야 한다.

```
$ g++ -c -fpic foo.cc
$ g++ -c -fpic bar.cc
$ g++ -shared foo.o bar.o -o libfoobar.so
```

이를통해 공유 라이브러리인 libfoobar.so 가 잘 생성된 것을 볼 수 있다. 참고로 리눅스에선 보통 공유 라이브러리의 확장자로 so (shared object)를 사용한다. 

그렇다면 libfoobar.so 한 번 간단한 프로그램에 링크해서 사용해 보자.

```cpp
#include "bar.h"
#include "foo.h"

int main() {
  bar();
  foo();
}
```

링크도 이전과 같이 하면 된다.

```
$ g++ main.cc libfoobar.so -g -o main

```

이때 main의 내용은 어떻게 생겼는지 objdump로 확인해보자.

```
objdump -S main

main:     file format elf64-x86-64

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 92 2f 00 00    	pushq  0x2f92(%rip)        # 3fb8 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 93 2f 00 00 	bnd jmpq *0x2f93(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop

Disassembly of section .plt.sec:

0000000000001060 <_Z3foov@plt>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	f2 ff 25 5d 2f 00 00 	bnd jmpq *0x2f5d(%rip)        # 3fc8 <_Z3foov>
    106b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001070 <_Z3barv@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 55 2f 00 00 	bnd jmpq *0x2f55(%rip)        # 3fd0 <_Z3barv>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001169 <main>:
int main() {
    1169:	f3 0f 1e fa          	endbr64 
    116d:	55                   	push   %rbp
    116e:	48 89 e5             	mov    %rsp,%rbp
  bar();
    1171:	e8 fa fe ff ff       	callq  1070 <_Z3barv@plt>
  foo();
    1176:	e8 e5 fe ff ff       	callq  1060 <_Z3foov@plt>
}
    117b:	b8 00 00 00 00       	mov    $0x0,%eax
    1180:	5d                   	pop    %rbp
    1181:	c3                   	retq   
    1182:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    1189:	00 00 00 
    118c:	0f 1f 40 00          	nopl   0x0(%rax)
```

참고로 위 코드는 전체 objdump로 출력된 부분에서 설명에서 필요한 부분만 잘라낸 것이다.

흥미롭게도, 이전에 정적으로 링크했을 경우와는 다르게 foo 나 bar 의 내용이 전혀 없음을 알 수 있다. foo 나 bar 의 내용이 없는데 그러면 main 은 foo 와 bar 함수를 어떻게 호출하고 있을까?

신기하게도

```
  bar();
    1171:	e8 fa fe ff ff       	callq  1070 <_Z3barv@plt>
  foo();
    1176:	e8 e5 fe ff ff       	callq  1060 <_Z3foov@plt>
```

위와 같이 foo 나 bar 을 직접 호출하는 대신에 (어차피 호출할 수 도 없다.), PLT 섹션에 있는 foo@plt 와 bar@plt 를 호출하고 있습니다. 그렇다면 이들은 어떻게 정의되어 있을까?

```
0000000000001060 <_Z3foov@plt>:
    1060:	f3 0f 1e fa          	endbr64 
    1064:	f2 ff 25 5d 2f 00 00 	bnd jmpq *0x2f5d(%rip)        # 3fc8 <_Z3foov>
    106b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000001070 <_Z3barv@plt>:
    1070:	f3 0f 1e fa          	endbr64 
    1074:	f2 ff 25 55 2f 00 00 	bnd jmpq *0x2f55(%rip)        # 3fd0 <_Z3barv>
    107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
```

`jmpq *0x2f5d(%rip)` 명령어에 의미는, "rip + 0x2f5d 위치에 써져 있는 주소값으로 점프해라"라는 의미이다. 위 경우 rip + 0x2f5d 가 0x3FC8 이므로 0x3FC8 의 위치에 무엇이 써져 있는지 살펴 보자. 이를 위해서 objdump 에 -s 를 주고 실행해보면 모든 섹션들의 데이터를 볼 수 있다.

```
$ objdump -s main
... (생략) ...
Contents of section .got:
 3fb0 a03d0000 00000000 00000000 00000000  .=..............
 3fc0 00000000 00000000 30100000 00000000  ........0.......
 3fd0 40100000 00000000 00000000 00000000  @...............
 3fe0 00000000 00000000 00000000 00000000  ................
 3ff0 00000000 00000000 00000000 00000000  ................
```

여기서 0x3FC8 부분에 무엇이 써져 있는지 보면 리틀 엔디안임을 감안해서 0x1030 임을 알 수 있다. 다시 말해 위 문장은 jmpq 0x1030 과 동일한 의미이다. 마찬가지로 bar 부분을 보면 0x3FD0 에 써져 있는 주소값으로 점프하라는 의미 인데, 해당 부분에는 0x1040 이 쓰여 있다. 따라서 main 에서 bar@plt 를 호출하게 되면 0x1040 으로 점프하게 된다.

그렇다면 0x1040 에는 뭐가 있을까?

```
0000000000001020 <.plt>:
    1020:	ff 35 92 2f 00 00    	pushq  0x2f92(%rip)        # 3fb8 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 93 2f 00 00 	bnd jmpq *0x2f93(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	pushq  $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmpq 1020 <.plt>
    103f:	90                   	nop
    1040:	f3 0f 1e fa          	endbr64 
    1044:	68 01 00 00 00       	pushq  $0x1
    1049:	f2 e9 d1 ff ff ff    	bnd jmpq 1020 <.plt>
    104f:	90                   	nop
```

0x1040 이후에 스택에 1을 푸시하고 PLT 맨 위로 점프한다. 그리고 다시 스택에 0x2f92(%rip)를 푸시하고, *0x2f93(%rip)로 점프한다. 

무슨 일이 일어나고 있는지 아래 그림을 보면서 이해해보자.

[그림]

가장 먼저 main 함수에서 공유 라이브러리 안에 있는 bar 함수를 호출한다. 만일 bar가 정적으로 링크된 라이브러리의 함수였다면 그냥 bar가 정의된 위치를 호출하면 된다. 하지만 공유 라이브러리의 경우 프로그램 어디에 위치 되었는지 알 수 없기 때문에 해당 함수를 직접 호출하는 것은 불가능하다.

따라서 어떤 방식을 취하게 되냐면 `global offset table (GOT)`라는 이름의 데이터 테이블을 프로그램 내부에 만든 다음에, 실제 함수들의 주소값을 이 테이블에 적어 놓는다. 그리고 우리가 함수를 호출하게 되면 해당 함수의 실제 위치를 이 테이블을 통해서 알아낸다.

예를 들어서 bar 함수가 GOT에 두 번째 위치에 (GOT[1]) 써져 있다고 가정 해보자. 그렇다면 그냥 call *GOT[1] 을 하게 되면 bar 함수를 호출할 수 있는 것이다. 하지만 프로그램을 처음 실행한 상태에서는 bar 함수가 어디에 위치할 지 알 수 없기 때문에 GOT[1]에 bar의 위치를 써 넣을 수 없다. 따라서 이를 위해서 처음에 GOT[1 에 bar의 실제 위치를 알아낸 후 해당 주소값을 GOT[1] 자리에 덮어 씌우는 함수를 쓴다.

이를 순서대로 정리해보자.

1. 먼저 main에서 bar을 호출 시켜주는 함수인 bar@plt를 호출한다.

2. bar@plt는 GOT에서 bar에 해당하는 엔트리인 GOT[1]로 점프한다.

3. bar가 처음 호출된 상황이므로 GOT[1]에는 bar 의 주소값이 들어 있지 않다. 따라서 `프로시져 링킹 테이블(procedure linkage table, PLT)`안에 정의된 bar 의 실제 위치를 찾는 루틴으로 점프한다. 참고로 PLT는 링크 타임 시에 위치를 알 수 없는 함수들의 위치를 찾아내주는 루틴들을 모아놓은 테이블이다.

4. bar의 GOT상의 위치는 1이므로, 스택에 1을 푸시한 뒤, 해당 심볼의 위치를 찾는 루틴으로 점프한다. 해당 루틴은 보통 PLT 맨 상단에 정의되어 있다.

5. 해당 루틴에선 곧바로 `동적 로더(dynamic loader)` 라이브러리 코드로 점프한다. 라이브러리에서 우리가 원하는 bar 함수가 어디에 정의되어 있는지 찾는다. 참고로 왜 3에서 5로 바로 점프할 수 없냐 궁금할 수 있는데 일단 동적 로더 자체도 공유 라이브러리이고 GOT의 위치를 전달해야 하기 때문이다.

6. 참고로 리눅스의 경우 ld.so 라는 이름의 동적 로더를 사용하고 있다. ld.so는 필요로 하는 심볼을 찾은 뒤 해당 GOT 위치를 업데이트 한다. 따라서 GOT[1]에는 이제 bar의 실제 주소값이 들어간다. 어떤 로더를 사용할지는 프로그램의 interop 섹션에 정의되어 있다.

7. 마지막으로 bar 함수로 점프합니다.

그렇다면 만약에 두 번째로 bar을 호출하게 된다면 어떻게 되는지 살펴보자.

이제는 GOT[1]안에 bar의 주소값이 들어 있기 때문에 복잡한 루틴 필요 없이 그냥 바로 bar을 호출할 수 있다.

이와 같이 함수가 실행 될 때 GOT 엔트리에 등록되는 방식을 `lazy binding` 이라고 한다.

Lazy binding의 장점은 만약에 bar가 프로그램 상에서 한 번도 호출되지 않았다면 bar 의 위치를 찾을 필요가 없다는 점이다. 동적 라이브러리에서 사용하는 함수의 위치를 찾는 작업은 결코 공짜가 아니기에 시간을 절약할 수 있다.

그 대신 lazy binding의 문제로는 해당 함수를 첫 번째로 실행하는 시점에서 많은 시간이 소요된다는 점이다. 따라서 프로그램이 실행 중에 뜨문 뜨문 렉이 걸리는 상황이 발생할 수 있다. 상황에 따라 프로그램 시작 시에 모든 동적으로 바인딩 되는 심볼들을 찾아버리는 것이 오히려 나을 수 도 있다.

따라서 프로그램에 따라서 ld로 하여금 lazy binding을 하지 않고 아예 프로그램 시작 시에 모든 심볼들을 GOT 에 등록하라고 설정할 수 도 있다. (예를 들어서 포토샵을 실행해보면 프로그램 시작 시 꽤 오래걸리는데 이게 대부분 공유 라이브러리에서 사용되는 함수들을 찾느라 걸리는 시간이다.)

##### 동적 링킹 방식의 재배치
마지막으로 동적 링킹되는 라이브러리에서 재배치가 어떤 식으로 이루어지는지 살펴보자. 

``` cpp
// foo.cc
#include "bar.h"
int x = 1;

int foo() {
  bar();
  x++;
  return 1;
}
```

위 코드를 컴파일 시에 아래와 같이 구성된다.

```
objdump -Sr foo.o

foo.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z3foov>:
#include "bar.h"
int x = 1;

int foo() {
   0:	f3 0f 1e fa          	endbr64 
   4:	55                   	push   %rbp
   5:	48 89 e5             	mov    %rsp,%rbp
  bar();
   8:	e8 00 00 00 00       	callq  d <_Z3foov+0xd>
			9: R_X86_64_PLT32	_Z3barv-0x4
  x ++;
   d:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 14 <_Z3foov+0x14>
			10: R_X86_64_REX_GOTPCRELX	x-0x4
  14:	8b 00                	mov    (%rax),%eax
  16:	8d 50 01             	lea    0x1(%rax),%edx
  19:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 20 <_Z3foov+0x20>
			1c: R_X86_64_REX_GOTPCRELX	x-0x4
  20:	89 10                	mov    %edx,(%rax)
  return 1;
  22:	b8 01 00 00 00       	mov    $0x1,%eax
}
  27:	5d                   	pop    %rbp
  28:	c3                   	retq   
```

먼저 bar 함수를 호출하는 부분부터 보자. R_X86_64_PLT32 방식으로 bar을 재배치 해야 한다고 명시하고 있다. R_X86_64_PLT32의 경우 재배치 주소 계산 방식이 L + A - P 이다. 여기서 A 와 P 는 기존과 동일하고 L 은 PLT의 주소값이다.

그 이유는 당연히도 bar을 직접 호출하는 것이 아니라 PLT에 등록되어 있는 bar을 호출해주는 루틴을 호출해야 하기 때문에 (bar@plt) PLT 섹션의 위치 기준으로 계산되어야 하기 때문이다.

그렇다면 전역 변수인 x는 어떨까? 이 경우 R_X86_64_REX_GOTPCRELX 형태의 재배치 방식을 사용하는데, 이 경우 계산하는 방식은 G + GOT + A - P 입니다. 여기서 G 는 GOT 안에서 해당 심볼 까지의 오프셋을 말하고, GOT 의 경우 GOT 테이블 자체의 오프셋을 의미합니다. 쉽게 말해서 G + GOT 가 프로그램 시작 부터 GOT 안에 정의 되어 있는 해당 심볼 까지의 오프셋이라 보면 된다.

변수의 경우 함수와는 다르게 PLT를 사용할 필요가 없다. 그냥 해당 변수를 GOT 안에 위치시키면 되기 때문이다. 따라서 위 처럼 R_X86_64_REX_GOTPCRELX 재배치 방식을 사용해서 GOT 안에 전역 변수를 정의하는 것을 알 수 있다. 

사실 여기 까지 다룬 재배치 방식 말고도 몇 가지 더 다른 재배치 방식들이 있다. 하지만 여기서 다룬 내용들을 모두 이해했다면 다른 방식들도 큰 무리 없이 이해하실 수 있을 것이며 이 부분에 대해서 더 공부하려면 [x86-64 ABI](https://uclibc.org/docs/psABI-x86_64.pdf) 를 참고하면 된다.

# 참고
[모두의 코드](https://modoocode.com/319)  
[st 블로그](https://st-lab.tistory.com/176?category=872072)  
[컴파일러 chodragon 블로그](https://chodragon9.github.io/blog/compiler-theory/#%EC%BB%B4%ED%8C%8C%EC%9D%BC%EB%9F%AC-%EA%B0%9C%EB%85%90)  
[Phase of translation 마소 문서](https://docs.microsoft.com/en-us/cpp/preprocessor/phases-of-translation?view=msvc-170)  
[C++ 표준 문서](http://eel.is/c++draft/lex.phases)