# Partial Derivatives
## 정의
open subset $U \subset \R^n$과 함수 $f : U \rightarrow \R$이 있다고 하자.

$\R^n$의 basis를 $\beta$라 할 떄, $a \in U$는 다음과 같이 표현된다.

$$ a = a^i\beta_i $$

$a$에서 $f$의 $i$번째 변수의 `편미분(partial derivatives)` $D_if(a)$은 다음과 같이 정의된다.

$$ \begin{aligned} D_if(a) &:= \lim_{h \rightarrow 0}\frac{f(a + h \beta_i) -f (a)}{h} \\&= \lim_{h \rightarrow 0} \frac{1}{h}(f(a^1, \cdots, a^i + h, \cdots, a^n) - f(a^1, \cdots, a^n))  \end{aligned} $$

위의 극한값이 존재할 경우 편미분은 그 극한값이 되며, 존재하지 않을 경우 편미분은 존재하지 않게 된다.

> Reference  
> {cite}`hubbard` chap 1.7

### 참고1
가장 널리 쓰이는 표기법은 다음과 같다.

$$ D_if = \frac{\partial f}{\partial x_i} $$

### 참고2
편미분은 다변수 함수를 일변수 함수처럼 보고 미분하는 방식이다. 다시 말해, 나머지 변수는 전부 상수로 간주하고 한 변수에 대해서 미분을 구하는 방식이다.

### 참고3
$D_i  f(a)$는 $a$에서 $e_i$방향으로 움직일 때, $f$가 어떻게 변하는지를 나타낸다.