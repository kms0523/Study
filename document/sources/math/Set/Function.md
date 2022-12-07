# Function

## 정의
집합 $A,B$가 있다고 하자.

다음과 같이 정의된 관계 $f$를 `함수(function)`라고 한다.
$$ f := \{ (a,b) \in A \times B | a \in A \Rightarrow \exist ! b \in B \} \subseteq A \times B $$

이를 풀어서 설명하면 "$A$의 모든 원소에 대해 $B$에 속하는 원소가 유일하게 존재하고 그 순서쌍들을 원소로 갖는 $A \times B$의 부분집합"이다.

### 참고1
$f : A \rightarrow B$로 표현할 수 있다.

### 참고2
$(a,b) \in f$에서 $b$는 $a$에 의존하여 $f$에 의해 유일하게 결정된다.

따라서 $b$를 $f(a)$로 표기하기도 한다.


### 명제1

함수 $f$에 대해 다음을 증명하여라.

$$ f(\emptyset) = \empty $$

**proof**

$$f(\emptyset) = \{ f(x) | x \in \empty \} = \empty \quad {_ \blacksquare}$$

### 명제2
집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$A_1, A_2 \subseteq A$에 대해 다음을 증명하여라.
$$ A_1 \subseteq A_2 \Rightarrow f(A_1) \subseteq f(A_2) $$

**proof**

$$ \begin{aligned} & y \in f(A_1) \\ \Leftrightarrow\enspace& \exist x \in A_1 \quad s.t. \quad f(x) = y \\ \Rightarrow\enspace& x \in A_2 \quad (\because A_1 \subseteq A_2) \\ \Leftrightarrow\enspace& f(x) \in f(A_2) \\ \Rightarrow\enspace& y \in f(A_2) \quad\tiny\blacksquare \end{aligned} $$

### 명제3
집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$A_1, A_2 \subseteq A$에 대해 다음을 증명하여라.
$$ f(A_1) \subseteq f(A_2) \nRightarrow A_1 \subseteq A_2 $$

**proof**

$b \in B$에 대해서, $f$를 다음과 같이 정의하자.
$$ \forall a \in A, \quad  f(a) = b $$

이 떄, $A_1 \cap A_2 = \emptyset$라고 $f(A_1) \subseteq f(A_2)$지만 $A_1 \subseteq A_2$이다.

따라서 $f(A_1) \subseteq f(A_2) \nRightarrow A_1 \subseteq A_2$이다. $\quad\tiny\blacksquare$

### 명제4

집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$A_1, A_2 \subseteq A$에 대해 다음을 증명하여라.

$$ f(A_1 \cup A_2) = f(A_1) \cup f(A_2) $$

**proof**

$$ \begin{aligned} & x \in f(A_1 \cup A_2) \\ \Leftrightarrow\enspace& \exists a \in A_1 \cup A_2, \quad x = f(a) \\ \Leftrightarrow\enspace& \exist i \in {1,2}, \quad \exists a \in A_i, \quad x = f(a) \\ \Leftrightarrow\enspace& \exist i \in {1,2}, \quad x \in f(A_i) \\ \Leftrightarrow\enspace& x \in f(A_1) \cup f(A_2) \quad\tiny\blacksquare \end{aligned} $$

> Reference  
> [블로그](https://mathphysics.tistory.com/711)

### 명제5

집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$A_1, A_2 \subseteq A$에 대해 다음을 증명하여라.

$$ f(A_1 \cap A_2) \subseteq f(A_1) \cap f(A_2). $$

**proof**

$$ \begin{aligned} & \forall i \in \{1,2\}, \quad A_1 \cap A_2 \subseteq A_i \\ \Rightarrow\enspace& \forall i \in \{ 1,2 \}, \quad f(A_1 \cap A_2) \subseteq f(A_i) \quad (\because \text{proposition2}) \\ \Leftrightarrow\enspace& f(A_1 \cap A_2) \subseteq \left( f(A_1) \cap f(A_2) \right) \quad\tiny\blacksquare \end{aligned} $$

### 명제6

집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$A_1, A_2 \subseteq A$에 대해 다음을 증명하여라.

$$ f(A_1) \cap f(A_2) \not \subseteq f(A_1 \cap A_2). $$

**proof**

함수를 $\forall a \in A ,\quad f(a) = b \in B$로 정의하고 $A_1 \cap A_2 = \emptyset$라고 하자.

$$ f(A_1) \cap f(A_2) = \{ b \}, \\ f(A_1 \cap A_2) = \emptyset \quad (\because \text{proposition1}) \quad\tiny\blacksquare $$

## 정의역과 공역
집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

이 때, 집합 $A$를 `정의역(domain)`이라고 하고 집합 $B$를 `공역(codomain)`이라고 한다.

## Image
집합 $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

$U \subseteq X$가 있을 때, $f$에 의한 $U$의 `상(image)` $\img(U)$는 다음과 같이 정의된 집합이다.

$$ \img(U) := \Set{f(x) \in Y | x \in U} $$

## Preimage
집합 $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

$V \subseteq Y$가 있을 때, $f$에 의한 $V$의 `원상(preimage)` $\preimg(V)$는 다음과 같이 정의된 집합이다.

$$ \preimg(V) := \Set{x \in X | f(x) \in V} $$

### 명제1
집합 $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

$V_1,V_2 \subset Y$가 있을 때, 다음을 증명하여라.

$$ \preimg(V_1) \cap \preimg(V_2) = \preimg(V_1 \cap V_2) $$

**Proof**

[$\preimg(V_1) \cap \preimg(V_2) \subseteq \preimg(V_1 \cap V_2)$]  
$x \in \preimg(V_1) \cap \preimg(V_2)$라 하면 다음이 성립한다.

$$\begin{aligned} & x \in \preimg(V_1) \enspace\land\enspace x \in \preimg(V_2) \\ \implies& f(x) \in V_1 \enspace\land\enspace f(x) \in V_2 \\ \implies& f(x) \in V_1 \cap V_2 \\ \implies& x \in \preimg(V_1 \cap V_2) \end{aligned} $$

[$\preimg(V_1 \cap V_2) \subseteq \preimg(V_1) \cap \preimg(V_2)$]  
$x \in \preimg(V_1 \cap V_2)$라 하면 다음이 성립한다.

$$\begin{aligned} & f(x) \in V_1 \cap V_2 \\ \implies& f(x) \in V_1 \enspace \land \enspace f(x) \in V_2 \\ \implies& x \in \preimg(V_1) \enspace\land\enspace x \in \preimg(V_2) \\ \implies& x \in \preimg(V_1) \cap \preimg(V_2) \qed \end{aligned} $$


## Restirction
집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$U \subseteq A$가 있을 때, 함수 $f$의 $S$로의 `정의역 제한(domain restiriction)` $f|_U$는 다음과 같이 정의된 관계이다.
$$ f|_U := \{ (x,y) \in f \enspace | \enspace x \in U \} $$

$V \subseteq B$가 있을 때, 함수 $f$의 $S$와 $V$로의 `정의역과 공역 제한(domain and codomain restriction)` $f|_{U \times V}$는 다음과 같이 정의된 관계다.
$$ f|_{U \times V} = \{ (x,y) \in f \enspace | \enspace x \in U  \enspace\land\enspace y \in V\} $$



## 공집합 함수

집합 $A,B$와 함수 $f : A \rightarrow B$가 있을 때, $A = \empty$인 경우를 생각해보자.

$A = \empty$면 $A \times B = \empty$임으로 $A \times B$의 유일한 부분집합은 $\empty$임으로 $f$는 $\empty$일 수 밖에 없다. 

이 때, $A = \empty$ 임으로 $\forall a \in A$가 거짓이고, 가정이 거짓인 명제(공허하게 참인 명제)는 항상 참임으로 $f = \empty$는 함수의 정의를 만족한다.

아무런 대응 관계를 갖지 않지만 함수의 공리를 만족하는 함수를 `공집함 함수(empty function)`라고 한다.

> Reference  
> [Wiki - 공허하게 참인 명제](https://ko.wikipedia.org/wiki/%EA%B3%B5%EC%A7%91%ED%95%A9)  
> [블로그 - 가정이 거짓이면 항상 명제가 참인 이유(집합론)](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=infinity7076&logNo=221328533139)  
> [블로그 - 가정이 거짓이면 항상 명제가 참인 이유(논리학)](https://hoohaha.tistory.com/71)

## 역상
집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$f$의 `역상(inverse image)` $f^{-1}(B)$은 다음과 같이 정의된 집합이다.

$$ f^{-1}(B) := \{ x \in A | f(x) \in B \} $$

### 명제1

집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$B_1, B_2 \subseteq B$에 대해 다음을 증명하여라.

$$ f^{-1}(B_1 \cup B_2) = f^{-1}(B_1) \cup f^{-1}(B_2) $$

**proof**

$$ \begin{aligned} & x \in f^{-1}(B_1 \cup B_2) \\ \Leftrightarrow\enspace& f(x) \in B_1 \cup B_2 \\ \Leftrightarrow\enspace& \exist i \in \{ 1,2 \}, \quad f(x) \in B_i \\ \Leftrightarrow\enspace& \exist i \in \{ 1,2 \}, \quad x \in f^{-1}(B_i) \\ \Leftrightarrow\enspace& x \in f^{-1}(B_1) \cup f^{-1}(B_2) \quad\tiny\blacksquare \end{aligned} $$

### 명제2

집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$B_1, B_2 \subseteq B$에 대해 다음을 증명하여라.

$$ f^{-1}(B_1 \cap B_2) = f^{-1}(B_1) \cap f^{-1}(B_2). $$

**proof**

$$ \begin{aligned} & x \in f^{-1}(B_1 \cap B_2) \\ \Leftrightarrow\enspace& f(x) \in B_1 \cap B_2 \\ \Leftrightarrow\enspace& \forall i \in \{ 1,2 \}, \quad f(x) \in B_i \\ \Leftrightarrow\enspace& \forall i \in \{ 1,2 \}, \quad x \in f^{-1}(B_i) \\ \Leftrightarrow\enspace& x \in f^{-1}(B_1) \cap f^{-1}(B_2) \quad\tiny\blacksquare \end{aligned} $$

### 명제3

집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$A_1 \subseteq A$에 대해 다음을 증명하여라.

$$ A_1 \subseteq f^{-1}(f(A_1)) $$

**proof**

$$ \begin{aligned} & x \in A_1 \\ \Rightarrow \enspace & f(x) \in f(A_1) & \quad & (\because f(A_1) := { f(x) | x \in A_1 }) \\ \Rightarrow \enspace & x \in f^{-1}(f(A_1)) & \quad & (\because f^{-1}(f(A_1)) := { x \in A | f(x) \in f(A_1) }) \quad\tiny\blacksquare \end{aligned} $$

#### 참고
단사함수가 아니기 때문에 함수를 거치면 커진다.

> Reference  
> [kocw 충북대 집합론](http://www.kocw.net/home/cview.do?cid=e9e1a11119248726)

### 명제4

집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$B_1 \subseteq B$에 대해 다음을 증명하여라.

$$ f(f^{-1}(B_1)) \subseteq B_1 $$

**proof**

$$ \begin{aligned} & y \in f(f^{-1}(B_1)) \\ \Rightarrow \enspace & \exist x \in f^{-1}(B_1), \quad y = f(x) & \quad & (\because f(f^{-1}(B_1)) := { f(x) | x \in f^{-1}(B_1) }) \\ \Rightarrow \enspace & \exist f(x) \in B_1 & \quad & (\because f^{-1}(B_1) := { x | f(x) \in B_1 })\ \Rightarrow \enspace & y \in B_1 \quad\tiny\blacksquare \end{aligned} $$

#### 참고

전사함수가 아니기 때문에 함수를 거치면 작아진다.

## 함수의 합성

집합 $A,B,C$와 함수 $f : A \rightarrow B, g : B \rightarrow C$가 있을 때, 다음과 같이 정의된 집합 $g \circ f$를 함수의 `합성(composition)`이라고 한다.

$$ {g \circ f} := \{ (x,z) \in A \times C | x \in A, \quad z = g(f(x)) \} \subseteq A \times C $$

즉, $(g \circ f)(x) = g(f(x))$이다.

## 단사 함수
집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

`단사 함수(injective function)` 혹은 `일대일 함수(one-to-one function)`은 다음을 만족하는 함수이다.

$$ x_1,x_2 \in A, \quad f(x_1) = f(x_2) \Rightarrow x_1 = x_2 $$

이의 대우 명제는 다음과 같다.

$$ x_1,x_2 \in A, \quad x_1 \neq x_2 \Rightarrow f(x_1) \neq f(x_2) $$

### 명제1

집합 $A,B$와 함수 $f : A \rightarrow B$가 있을 때 다음을 증명하여라.

$$ f \text{ is injective} \Leftrightarrow \exist g : B \rightarrow A, \quad g \circ f = id_A $$

**proof**

[$\Rightarrow$]  
임의의 $x_0 \in A$에 대해 함수 $g$를 다음과 같이 정의하자.  
$$ b\in B, \quad g(b) = \begin{cases} x & \text{if} \enspace b \in f(A), \quad b =f(x) \\ x_0 & \text{if} \enspace b \notin f(A) \end{cases} $$

이 때, $f$는 단사함수임으로 함수 $f$에 의해 $f(x)$로 가는 $x$가 유일하기 때문에 함수 $g$는 잘 정의된다(well defined). 그리고 $\forall a \in A, \quad (g \circ f)(x) = id_A(x) = x$ 임으로 $g \circ f = id_A$ 이다. $\quad\tiny\blacksquare$

[$\Leftarrow$]  
$x_1, x_2 \in A$에 대해  
$$ \begin{aligned} & f(x_1) = f(x_2) \\ \Rightarrow \enspace & g(f(x_1)) = g(f(x_2)) & \quad & (\because g \text{is function}) \\ \Rightarrow \enspace & x_1 = x_2 & \quad & (\because g \circ f = id_A) \quad {_ \blacksquare} \end{aligned} $$

### 명제2

집합 $A,B,C$와 함수 $f : A \rightarrow B, g : B \rightarrow C$가 있을 때 다음을 증명하여라.

$$ g \circ f : A \rightarrow C, \quad g \circ f \text{ is injective} \Rightarrow f \text{ is injective} $$

**proof**  
$x_1,x_2 \in A$에 대해

$$ \begin{aligned} & f(x_1) = f(x_2)\\ \Rightarrow \enspace & g(f(x_1)) = g(f(x_2)) & \quad & (\because g \text { is function}) \\ \Rightarrow \enspace & x_1 = x_2 & \quad & (\because g \circ f \text{ is injective} ) \quad\tiny\blacksquare \end{aligned} $$

### 명제3
집합 $A,B,C$와 함수 $f : A \rightarrow B, g : B \rightarrow C$가 있을 때 다음을 증명하여라.

$$ f,g \text{ is injective} \Rightarrow g \circ f : A \rightarrow C \text{ is injective} $$

**proof**  
$x_1,x_2 \in A$에 대해

$$ \begin{aligned} & g(f(x_1)) = g(f(x_2))\\ \Rightarrow \enspace & f(x_1) = f(x_2) & \quad & (\because g \text { is injective}) \\ \Rightarrow \enspace & x_1 = x_2 & \quad & (\because f \text{ is injective} ) \quad\tiny\blacksquare \end{aligned} $$

### 명제4
집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

Subset $U \subseteq A$가 있을 때, 다음을 증명하여라.
$$ f \text{ is injective} \Rightarrow f|_U \text{ is injective} $$

**Proof**

$x_1,x_2 \in U$라고 하자.

$f$가 injective임으로 다음이 성립한다.
$$ \begin{aligned} & f|_U(x_1) = f|_U(x_2) \\\Rightarrow\enspace& f(x_1) = f(x_2) \\\Rightarrow\enspace& x_1 = x_2 \quad\tiny\blacksquare \end{aligned}   $$

## 전사 함수

집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

`전사 함수(surjective function)` 혹은 `위로의 함수(onto function)`은 다음을 만족하는 함수이다.

$$ \forall y \in B, \quad \exist x \in A, \quad f(x)=y $$

즉, 다음과 같이 표현할 수 있다.

$$ \text{img}(f) = f(A)) = B $$

### 명제1

집합 $A,B$와 함수 $f : A \rightarrow B$가 있을 때 다음을 증명하여라.

$$ f \text{ is surjective} \Leftrightarrow \exist g : B \rightarrow A, \quad f \circ g = id_B $$

**proof**

[$\Rightarrow$]  
$f$가 전사 함수이기 때문에

$$ \forall y \in B, \quad \exist x \in A, \quad y=f(x) $$

이 때, 임의의 $y$에 대해 $x$의 존재성은 보장되지만 유일성은 보장되지 않기 때문에 많은 $x$들중 하나를 선택해야 된다. 이를 위해서 $x$들 중 하나를 선택할 수 있다는 선택공리(axiom of choice, AC)를 받아들인다.

각각의 $y$에 대해 선택된 $x$를 $x'$이라고 하고 함수 $g$를 다음과 같이 정의하자.

$$ g(y) = x' $$

위의 $f$가 전사함수라는 점과 AC를 통해 $y$에 따른 $x$의 존재성과 유일성이 보장됨으로 함수 $g$는 잘 정의된다. 그리고 $\forall y \in B, \quad (f \circ g)(y) = id_B(y) = y$ 임으로 $g \circ f = id_B$ 이다. $\quad\tiny\blacksquare$

[$\Leftarrow$]  
$$ \begin{aligned} & y \in B \\ \Rightarrow \enspace & f(g(y)) = y \quad (\because f \circ g = id_B) \\ \Rightarrow \enspace & \exist x \in A, \quad x = g(y), \quad y = f(x) \quad\tiny\blacksquare \end{aligned} $$

> Reference  
> [나무위키 - 선택공리](https://namu.wiki/w/%EC%84%A0%ED%83%9D%EA%B3%B5%EB%A6%AC)

### 명제2

집합 $A,B,C$와 함수 $f : A \rightarrow B, g : B \rightarrow C$가 있을 때 다음을 증명하여라.

$$ g \circ f : A \rightarrow C, \quad g \circ f \text{ is surjective} \Rightarrow g \text{ is surjective} $$

**proof**

$$ \begin{aligned} & z \in C \\ \Rightarrow \enspace & \exist x \in A, \quad g(f(x)) = z \\ \Rightarrow \enspace & \exist y \in B, \quad y = f(x), \quad z = g(y) \quad\tiny\blacksquare \end{aligned} $$

### 명제3

집합 $A,B,C$와 함수 $f : A \rightarrow B, g : B \rightarrow C$가 있을 때 다음을 증명하여라.

$$ f,g \text{ is surjective} \Rightarrow g \circ f : A \rightarrow C \text{ is surjective} $$

**proof**

$$ \begin{aligned} & z \in C \\ \Rightarrow \enspace & \exist y \in B, \quad z = g(y) \quad (\because g \text{ is surjective}) \\ \Rightarrow \enspace & \exist x \in A, \quad y = f(x) \quad (\because f \text{ is surjective}) \\ \Rightarrow \enspace & \exist x \in A, \quad z = g(f(x)) \quad\tiny\blacksquare \end{aligned} $$

## 전단사 함수

집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

`전단사 함수(bijective function)` 혹은 `일대일 대응(one-to-one correspondence)`은 단사이면서 동시에 전사인 함수이다. 다시 말해 일대일 함수이면서 동시에 위로의 함수이다.

### 명제1
집합 $A,B,C$와 함수 $f : A \rightarrow B, g : B \rightarrow C$가 있을 때 다음을 증명하여라.
$$ f,g \text{ is bijective} \Rightarrow g \circ f : A \rightarrow C \text{ is bijective} $$

**proof**

$f,g$는 전사 함수임으로 전사 함수의 명제 3번에 의해서 $g \circ f$는 전사함수이다.

동시에 $f,g$는 단사 함수임으로 단사 함수의 명제 3번에 의해서 $g \circ f$는 단사함수이다.

따라서 $g \circ f$는 전단사 함수이다. $\quad\tiny\blacksquare$

### 명제2
집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

$S \subseteq A$가 있을 때, 다음을 증명하여라.
$$ f \text{ is bijective} \Rightarrow f|_{S \times f(S)} \text{ is bijective} $$

**Proof**

injective function의 성질에 의해 $f$가 injective임으로 $f|_{S \times f(S)}$ 또한 injective이다.

그리고 codomain이 $f(S)$로 restriction 됐음으로 자명하게 $f|_{S \times f(S)}$는 surjective이다.

따라서 $f|_{S \times f(S)}$는 bijective이다. $\quad\tiny\blacksquare$

## 역함수

집합 $A,B$와 bijective map $f : A \rightarrow B$가 있다고 하자.

`역함수(inverse function)` $f^{-1} : B \rightarrow A$은 다음과 같이 정의된다.

$$ S_{f^{-1}} := \{ (y,x) \in B \times A | y = f(x) \} \subseteq B \times A $$

전사 함수이기 때문에 임의의 $y \in B$에 대해 반드시 $f(x)=y$를 만족하는 $x$가 존재하며 동시에 단사 함수이기 때문에 이런 관계를 만족하는 $x$는 유일함으로 함수의 정의를 만족시킬 수 있다.

### 명제1

집합 $A,B$와 함수 $f : A \rightarrow B$가 있을 때 다음을 증명하여라.

$$ f \text{ is bijective} \Rightarrow \exist! f^{-1} $$

**proof**

$f$ 전사 함수이기 때문에 임의의 $y \in B$에 대해 반드시 $f(x)=y$를 만족하는 $x$가 존재한다.

동시에 단사 함수이기 때문에 이런 관계를 만족하는 $x$는 유일하다.

즉 임의의 $y$에 대해서 $x$가 유일하게 존재함으로 함수의 정의를 만족시키는 $f^{-1}$는 유일하게 존재한다. $\quad\tiny\blacksquare$

### 명제2

집합 $A,B$와 함수 $f : A \rightarrow B$가 있을 때 다음을 증명하여라.

$$ f \text{ is bijective} \Rightarrow f^{-1} \text{ is bijective}. $$

**proof**

$f^{-1}$의 정의에 의해 $f^{-1} \circ f = id_A$임으로 전사 함수 명제2에 의해 $f^{-1}$은 전사 함수임을 알 수 있다.

동시에 $f^{-1}$의 정의에 의해 $f \circ f^{-1} = id_B$임으로 단사 함수 명제2에 의해 $f^{-1}$는 단사함수임을 알 수 있다.

따라서 $f^{-1}$는 전단사함수이다. $\quad\tiny\blacksquare$

### 명제3
집합 $X,Y$와 bijective 함수 $f: X \rightarrow Y$가 있다고 하자.

subset $U \subseteq X$가 있을 때, 다음을 증명하여라.
$$ (f|_{U \times f(U)})^{-1} = f^{-1}|_{f(U) \times U} $$

**Proof**

$y \in f(U)$라 하면 다음이 성립한다.
$$ (f|_{U \times f(U)})^{-1}(y) = f^{-1}(y) $$

또한 다음도 성립한다.
$$ f^{-1}|_{f(U) \times U} (y) = f^{-1}(y) $$


> Reference  
> [Proof Wiki](https://proofwiki.org/wiki/Restriction_of_Inverse_is_Inverse_of_Restriction)