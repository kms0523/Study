# Injective Function
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

이 때, $f$는 단사함수임으로 함수 $f$에 의해 $f(x)$로 가는 $x$가 유일하기 때문에 함수 $g$는 잘 정의된다(well defined). 그리고 $\forall a \in A, \quad (g \circ f)(x) = id_A(x) = x$ 임으로 $g \circ f = id_A$ 이다. $\qed$

[$\Leftarrow$]  
$x_1, x_2 \in A$에 대해  

$$ \begin{aligned} & f(x_1) = f(x_2) \\ \Rightarrow \enspace & g(f(x_1)) = g(f(x_2)) & \quad & (\because g \text{is function}) \\ \Rightarrow \enspace & x_1 = x_2 & \quad & (\because g \circ f = id_A) \qed \end{aligned} $$

### 명제2

집합 $A,B,C$와 함수 $f : A \rightarrow B, g : B \rightarrow C$가 있을 때 다음을 증명하여라.


$$ g \circ f : A \rightarrow C, \quad g \circ f \text{ is injective} \Rightarrow f \text{ is injective} $$

**proof**  
$x_1,x_2 \in A$에 대해


$$ \begin{aligned} & f(x_1) = f(x_2)\\ \Rightarrow \enspace & g(f(x_1)) = g(f(x_2)) & \quad & (\because g \text { is function}) \\ \Rightarrow \enspace & x_1 = x_2 & \quad & (\because g \circ f \text{ is injective} ) \qed \end{aligned} $$

### 명제3
집합 $A,B,C$와 함수 $f : A \rightarrow B, g : B \rightarrow C$가 있을 때 다음을 증명하여라.


$$ f,g \text{ is injective} \Rightarrow g \circ f : A \rightarrow C \text{ is injective} $$

**proof**  
$x_1,x_2 \in A$에 대해


$$ \begin{aligned} & g(f(x_1)) = g(f(x_2))\\ \Rightarrow \enspace & f(x_1) = f(x_2) & \quad & (\because g \text { is injective}) \\ \Rightarrow \enspace & x_1 = x_2 & \quad & (\because f \text{ is injective} ) \qed \end{aligned} $$

### 명제4
집합 $A,B$와 함수 $f : A \rightarrow B$가 있다고 하자.

Subset $U \subseteq A$가 있을 때, 다음을 증명하여라.

$$ f \text{ is injective} \Rightarrow f|_U \text{ is injective} $$

**Proof**

$x_1,x_2 \in U$라고 하자.

$f$가 injective임으로 다음이 성립한다.

$$ \begin{aligned} & f|_U(x_1) = f|_U(x_2) \\\Rightarrow\enspace& f(x_1) = f(x_2) \\\Rightarrow\enspace& x_1 = x_2 \qed \end{aligned}   $$

### 명제1

집합 $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

$f$가 injective fnction일 떄, $X_1 \subseteq X$에 대해 다음을 증명하여라.

$$ X_1 = \preimg(f(X_1)) $$