# Derivatives
open subset $U \subset \R$과 함수 $f : U \rightarrow \R$이 있다고 하자.

$a \in U$에서 $f$의 `미분(derivatives)`은 다음과 같이 정의된다.
$$ f'(a) := \lim_{h \rightarrow 0} \frac{1}{h}(f(a + h) - f(a)) $$

위의 극한값이 존재할 경우 미분은 그 극한값이 되며, 존재하지 않을 경우 미분은 존재하지 않게 된다.

# Partial Derivatives
open subset $U \subset \R^n$과 함수 $f : U \rightarrow \R$이 있다고 하자.

$\mathbf a \in U$에서 $f$의 $i$번째 변수의 `편미분(partial derivatives)`은 다음과 같다.
$$ D_if(\mathbf a) := \lim_{h \rightarrow 0} \frac{1}{h}(f(a_1, \cdots, a_i + h, \cdots, a_n) - f(a_1, \cdots, a_n)) $$

위의 극한값이 존재할 경우 편미분은 그 극한값이 되며, 존재하지 않을 경우 편미분은 존재하지 않게 된다.

### 참고
가장 널리 쓰이는 표기법은 다음과 같다.
$$ D_if = \frac{\partial f}{\partial x_i} $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.7

# Partial Derivatives of Vector-valued Function
open subset $U \subset \R^n$과 함수 $\mathbf f : U \rightarrow \R^m$이 있다고 하자.

$\mathbf a \in U$에서 $f$의 $i$번째 변수의 편미분은 다음과 같다.
$$ D_i \mathbf f(\mathbf a) := \lim_{h \rightarrow 0} \frac{1}{h}(\mathbf f(a_1, \cdots, a_i + h, \cdots, a_n) - \mathbf f(a_1, \cdots, a_n)) = \begin{bmatrix} D_if_1(\mathbf a) \\ \vdots \\ D_if_m(\mathbf a) \end{bmatrix} $$ 

# Derivatives of Vector-valued Functions
open subset $U \subset \R^n$과 함수 $\mathbf f : U \rightarrow \R^m$이 있다고 하자.

기존의 미분의 정의를 그대로 활용하면 다음과 같이 정의할 수 있다.
$$ \bf f'(a) := \lim_{h \rightarrow 0} \frac{1}{h}(f(a + h) - f(a)) $$

하지만 이 정의는 문제가 있다. vector $\bf h$로 나눈다는것은 정의되지 않은 연산이다.

따라서, 미분의 정의를 다른 형태로 변형하여 이 문제를 해결해보자.

## Altenative form1
기존의 미분의 정의 다음과 같이 변경해보자.
$$ f'(a) := \lim_{h \rightarrow 0} \frac{1}{|h|}(f(a + h) - f(a)) $$

이 경우에는 다차원으로 확장하더라도 vector의 크기로 나누기 때문에 정의되지 않은 연산은 없다. 하지만 이 경우에는 $h \rightarrow 0$로 가면서 부호 문제가 발생한다.

(예시)

## Alternative form2
미분의 정의로부터 다음과 같은 형태를 유도할 수 있다.
$$ \lim_{h \rightarrow 0} \frac{1}{h} \Big( f(a + h) - f(a) - f'(a)h \Big) = 0 $$

### 참고1
$f(a + h) - f(a)$항은 $\Delta f$를 나타내고, $f'(a)h$항은 $\Delta f$를 선형근사한 값으로 볼 수 있다.

### 참고2
위의 식이 성립하기 위해서는 $\Delta f$와 선형근사인 $f'(a)h$사이의 차이가 $h \rightarrow 0$일 때, 선형보다 작아야 한다.

#### 예시
linear map $L,D$가 있다고 하자.

$L$은 $\Delta f - L(h) = c_1h, \enspace c_1 \in \R - \{ 0 \}$로 차이가 선형이고 $D$는 $\Delta f - D(h) = c_2h^2, \enspace c_2 \in \R - \{ 0 \}$로 차이가 선형보다 작다고 하면 다음이 성립한다.
$$ \begin{gathered} \lim_{h \rightarrow 0} \frac{1}{h} \Big( f(a + h) - f(a) - L(h) \Big) = \lim_{h \rightarrow 0}\frac{c_1h}{h} = c_1 \neq 0 \\ \lim_{h \rightarrow 0} \frac{1}{h} \Big( f(a + h) - f(a) - D(h) \Big) = \lim_{h \rightarrow 0}\frac{c_2 h^2}{h} = 0 \end{gathered} $$

### 참고3
위 형태는 다음과 같이 변형할 수 있다.
$$ \lim_{h \rightarrow 0} \frac{1}{|h|} \Big( f(a + h) - f(a) - f'(a)h \Big) = 0 $$