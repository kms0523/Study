# Derivatives
open subset $U \subset \R$과 함수 $f : U \rightarrow \R$이 있다고 하자.

$a \in U$에서 $f$의 `미분(derivatives)`은 다음과 같이 정의된다.
$$ f'(a) := \lim_{h \rightarrow 0} \frac{1}{h}(f(a + h) - f(a)) $$

위의 극한값이 존재할 경우 미분은 그 극한값이 되며, 존재하지 않을 경우 미분은 존재하지 않게 된다.

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.7

# Partial Derivatives
open subset $U \subset \R^n$과 함수 $f : U \rightarrow \R$이 있다고 하자.

$\R^n$의 basis를 $\beta$라 할 떄, $a \in U$는 다음과 같이 표현된다.
$$ a = a^i\beta_i $$

$a$에서 $f$의 $i$번째 변수의 `편미분(partial derivatives)` $D_if(a)$은 다음과 같이 정의된다.
$$ \begin{aligned} D_if(a) &:= \lim_{h \rightarrow 0}\frac{f(a + h \beta_i) -f (a)}{h} \\&= \lim_{h \rightarrow 0} \frac{1}{h}(f(a^1, \cdots, a^i + h, \cdots, a^n) - f(a^1, \cdots, a^n))  \end{aligned} $$

위의 극한값이 존재할 경우 편미분은 그 극한값이 되며, 존재하지 않을 경우 편미분은 존재하지 않게 된다.

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.7

### 참고1
가장 널리 쓰이는 표기법은 다음과 같다.
$$ D_if = \frac{\partial f}{\partial x_i} $$

### 참고2
편미분은 다변수 함수를 일변수 함수처럼 보고 미분하는 방식이다. 다시 말해, 나머지 변수는 전부 상수로 간주하고 한 변수에 대해서 미분을 구하는 방식이다.

### 참고3
$D_i  f(a)$는 $a$에서 $e_i$방향으로 움직일 때, $f$가 어떻게 변하는지를 나타낸다.

# Partial Derivatives of Vector-valued Function
open subset $U \subset \R^n$과 함수 $f^i:U \rightarrow \R \enspace i=1,\cdots,m$이 있다고 하자.

$\R^m$의 basis를 $\gamma$라 할 떄, $f : U \rightarrow \R^m$는 다음과 같이 표현된다.
$$ f = f^i\gamma_i $$

또한, $\R^n$의 basis를 $\beta$라 할 떄, $a \in U$는 다음과 같이 표현된다.
$$ a = a^i\beta_i $$

$a \in U$에서 $f$의 $i$번째 변수의 편미분은 다음과 같다.
$$ \begin{aligned} D_i f(a) &:= \lim_{h \rightarrow 0} \frac{1}{h}(f(a^1, \cdots, a^i + h, \cdots, a^n) - f(a^1, \cdots, a^n)) \\&= \Big( \lim_{h \rightarrow 0} \frac{1}{h} (f^j(a^1, \cdots, a^i + h, \cdots, a^n) - f^j(a^1, \cdots, a^n)) \Big)\gamma_j \\&= D_if^j\gamma_j \\&= \begin{bmatrix} D_if^1(a) \\ \vdots \\ D_if^m(a) \end{bmatrix} \end{aligned} $$ 

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.7

# Total Derivative
open subset $U \subset \R^n$과 함수 $\mathbf f : U \rightarrow \R^m$이 있다고 하자.

기존의 미분의 정의를 그대로 활용하여 $\mathbf f$의 미분을 정의한다면 다음과 같다.
$$ \bf f'(a) := \lim_{h \rightarrow 0} \frac{1}{h}(f(a + h) - f(a)) $$

하지만 이 정의는 문제가 있다. vector $\bf h$로 나눈다는것은 정의되지 않은 연산이다.

따라서, 미분의 정의를 다른 형태로 변형하여 이 문제를 해결해보자.

## Altenative form1
기존의 미분 정의를 다음과 같이 변경해보자.
$$ f'(a) := \lim_{h \rightarrow 0} \frac{1}{|h|}(f(a + h) - f(a)) $$

이 경우에는 다차원으로 확장하더라도 vector의 크기로 나누기 때문에 정의되지 않은 연산은 없다. 하지만 이 경우에는 $h \rightarrow 0$로 가면서 부호 문제가 발생한다.

### 예시
$f(x) = x^2$라 하자.

$f'(a)$를 계산하면 다음과 같다.
$$ f'(a) = \lim_{h \rightarrow 0} \frac{1}{|h|}(2ah + h^2) = \begin{cases} 2a & h>0 \\ -2a & h<0 \end{cases} $$

따라서, 극한값이 존재하지 않는 문제가 발생한다.

## Alternative form2
기존의 미분 정의로부터 다음 형태를 유도할 수 있다.
$$ \lim_{h \rightarrow 0} \frac{1}{h} \Big( f(a + h) - f(a) - f'(a)h \Big) = 0 $$

다차원으로 확장할 때 나타나는 문제를 방지하기 위해 다음과 같이 변형한다.
$$ \lim_{h \rightarrow 0} \frac{1}{|h|} \Big( f(a + h) - f(a) - f'(a)h \Big) = 0 $$

다음으로, 위의 식을 만족하는 $f'(a)$를 $f$의 $a$에서의 derivative라고 정의하면 Alternative form1과 다르게 부호 문제가 발생하지 않는다.

### 참고1
$f(a + h) - f(a)$항은 $\Delta f$를 나타내고, $f'(a)h$항은 $\Delta f$를 선형근사한 값으로 볼 수 있다.

### 참고2
위의 식이 성립하기 위해서는 $\Delta f$와 선형근사인 $f'(a)h$사이의 차이가 $h \rightarrow 0$일 때, 선형보다 작아야 한다.

#### 예시
linear map $L,D$가 있다고 하자.

$L$은 $\Delta f - L(h) = c_1h, \enspace c_1 \in \R - \{ 0 \}$로 차이가 선형이고 $D$는 $\Delta f - D(h) = c_2h^2, \enspace c_2 \in \R - \{ 0 \}$로 차이가 선형보다 작다고 하면 다음이 성립한다.
$$ \begin{gathered} \lim_{h \rightarrow 0} \frac{1}{h} \Big( f(a + h) - f(a) - L(h) \Big) = \lim_{h \rightarrow 0}\frac{c_1h}{h} = c_1 \neq 0 \\ \lim_{h \rightarrow 0} \frac{1}{h} \Big( f(a + h) - f(a) - D(h) \Big) = \lim_{h \rightarrow 0}\frac{c_2 h^2}{h} = 0 \end{gathered} $$

## Definition using Alternative Form2
open subset $U \subset \R^n$과 함수 $f : U \rightarrow \R^m$이 있다고 하자.

$a \in U$와 다음과 같이 정의된 linear map $L$이 있다고 하자.
$$ L : \R^n \rightarrow \R^m \st v \mapsto Av $$

이 떄, $L$이 다음을 만족할 경우, $L$을 $a$에서 $f$의  `total derivative`라고 한다.
$$ \lim_{h \rightarrow 0} \frac{1}{|h|}(f(a + h) - f(a) - L(h)) = 0 $$

이런 $L$이 존재하는 경우, $f$가 $a$에서 `미분가능(differentiable)`하다고 한다.

### 명제
open subset $U \subset \R^n$과 함수 $\mathbf f : U \rightarrow \R^m$이 있다고 하자.

$\mathbf a \in U$에서 $\bf f$가 미분가능할 때, 다음을 증명하여라.
$$ L : \R^n \rightarrow \R^m \st v \mapsto Av $$

$$ \text{Where, } A = \begin{bmatrix} D_1f_1(\mathbf a) & \cdots & D_nf_1(\mathbf a) \\ \vdots & & \vdots \\ D_1f_m(\mathbf a) & \cdots & D_nf_m(\mathbf a) \end{bmatrix}$$

**Proof**

$\mathbf h = t \mathbf e_i$라 하면 정의에 의해 다음이 성립한다.
$$ \begin{aligned} & \bf \lim_{\mathit t \mathbf e_i \rightarrow 0} \frac{1}{| \mathit t \mathbf e_i|}(f(a + \mathit t \mathbf e_i) - f(a) - \mathit L(\mathit t \mathbf e_i)) = 0 \\ \Rightarrow \enspace & \bf \lim_{ \mathit t \mathbf e_i \rightarrow 0} \frac{1}{ \mathit t}(f(a + \mathit t \mathbf e_i) - f(a) - \mathit t \mathit L(\mathbf e_i)) = 0 \\ \Rightarrow \enspace & D_i \mathbf f(\mathbf a) = \mathit L(\mathbf e_i) \end{aligned} $$

이를 행렬 형태로 나타내면 다음과 같다.
$$ L(\mathbf e_i) = A_{*i} = \begin{bmatrix} D_if_1(\mathbf a) \\ \vdots \\ D_if_m(\mathbf a) \end{bmatrix} $$

따라서 다음이 성립한다.
$$ A = \begin{bmatrix} A_{*1} & \cdots & A_{*n} \end{bmatrix} = \begin{bmatrix} D_1f_1(\mathbf a) & \cdots & D_nf_1(\mathbf a) \\ \vdots & & \vdots \\ D_1f_m(\mathbf a) & \cdots & D_nf_m(\mathbf a) \end{bmatrix} \quad {_\blacksquare} $$

#### 참고1
행렬$A$를 $\mathbf f$의 `Jacobian matrix`라고 부르며 $J_f$로 표기한다.
$$ \mathbf{Jf(a)} = \begin{bmatrix} D_1f_1(\mathbf a) & \cdots & D_nf_1(\mathbf a) \\ \vdots & & \vdots \\ D_1f_m(\mathbf a) & \cdots & D_nf_m(\mathbf a) \end{bmatrix}$$

#### 참고2
$L = \mathbf{Jf}$이려면 $\mathbf f$가 differtiable해야 한다.

### 참고
derivative의 의미는 함수 $\mathbf f$에 대한 best linear approximation이다.

따라서 위 정의는 $\mathbf f$의 domain과 codomain이 Euclidean space일때 만 성립하는 것이 아니라, 임의의 vector space에 대해서도 성립한다.

domain과 codomain이 Euclidean space가 아닌 vector space인 경우에도 vector space isomorphism을 이용하여 Euclidean space에서 Jacobian matrix를 구하는 형태로 derivatve를 계산할 수 있지만, 이 방법이 최선의 선택이 아닌 경우도 있다.

#### 예시
함수 $\mathbf f$가 다음과 같이 정의되었다고 하자.
$$\mathbf f : M_{nn} \rightarrow M_{nn} \quad s.t. \quad A \mapsto A^2 $$

Jacobian을 이용하지 않고 미분의 정의를 통해 $\mathbf f'(A)$을 구해보자.
$$ \begin{aligned} & \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{|H|}(f(A + H) - f(A) - \mathit L(H)) = 0_{M_{nn}} \\ \Rightarrow \enspace & \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{|H|}(AH + HA + H^2 - \mathit L(H)) = 0_{M_{nn}} \end{aligned} $$

$\mathbf f$가 $A$에서 미분가능하기 위해서는 위의 식이 만족되어야 함으로 $|H|$로 나눠주면 $0_{M_{nn}}$이 되지 않는 선형 항들을 제거하기 위해 linear map $L(H)$를 다음과 같이 정의하자.
$$ L : M_{nn} \rightarrow M_{nn} \quad s.t. \quad H \mapsto AH + HA $$

$L$에 의해 다음이 만족된다.
$$ \begin{aligned} \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{|H|}(AH + HA + H^2 - \mathit L(H)) &= \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{|H|}H^2 \\ &= \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{|H|}H^2 \\ &< \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{|H|}|H||H| \\ &= 0_{M_{nn}} \end{aligned} $$

따라서, $\mathbf f$는 $A$에서 미분가능하며 그때 $\mathbf f'(A)$는 다음과 같다.
$$ \mathbf  f'(A) : M_{nn} \rightarrow M_{nn} \quad s.t. \quad H \mapsto AH + HA $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach p.132

# Directional Derivative
open subset $U \subset \R^n$과 함수 $\mathbf f : U \rightarrow \R^m$이 있다고 하자.

$\bf f$의 $\bf a$에서 $\bf v$방향으로의 `directional derivative`는 다음과 같이 정의된다.
$$ D_\mathbf v \mathbf f(\mathbf a) := \lim_{h \rightarrow 0}\frac{ \mathbf f(\mathbf a + h \mathbf v) - \mathbf f (\mathbf a)}{h} $$

### 명제
open subset $U \subset \R^n$과 함수 $\mathbf f : U \rightarrow \R^m$이 있다고 하자.

$\mathbf a \in U$에서 $\mathbf f$가 differentiable일 때 다음을 증명하여라.
$$ \exist D_\mathbf v \mathbf f(\mathbf a) \enspace \land \enspace D_\mathbf v \mathbf f(\mathbf a) = \mathbf{Jf(a)v} $$

**Proof**

$\mathbf f$가 differentiable 함으로 다음이 성립한다.
$$ \begin{aligned} & \lim_{h \rightarrow 0}\frac{ \mathbf f(\mathbf a + h \mathbf v) - \mathbf f (\mathbf a) - L(h \mathbf v)}{|h\mathbf v|} = 0 \\ \Rightarrow \enspace & \lim_{h \rightarrow 0}\frac{ \mathbf f(\mathbf a + h \mathbf v) - \mathbf f (\mathbf a) - L(h \mathbf v)}{h|\mathbf v|} = 0 \\ \Rightarrow \enspace & \lim_{h \rightarrow 0}\frac{ \mathbf f(\mathbf a + h \mathbf v) - \mathbf f (\mathbf a) - L(h \mathbf v)}{h} = 0 \\ \Rightarrow \enspace & \lim_{h \rightarrow 0}\frac{ \mathbf f(\mathbf a + h \mathbf v) - \mathbf f (\mathbf a)}{h} = L(\mathbf v) \\ \Rightarrow \enspace & D_\mathbf v \mathbf f(\mathbf a) = \mathbf{Jf(a)}\mathbf v \end{aligned} $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach Proposition 1.7.14.