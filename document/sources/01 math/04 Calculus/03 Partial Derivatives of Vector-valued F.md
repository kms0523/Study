# Partial Derivatives of Vector-valued Function
## 정의
open subset $U \subset \R^n$과 함수 $f^i:U \rightarrow \R \enspace i=1,\cdots,m$이 있다고 하자.

$f : U \rightarrow \R^m$는 다음과 같이 표현된다.

$$ f = f^i\epsilon^m_i $$

또한, $\R^n$의 basis를 $\beta$라 할 떄, $a \in U$는 다음과 같이 표현된다.

$$ a = a^i\beta_i $$

$a \in U$에서 $f$의 $i$번째 변수의 편미분 $D_i^{f(a)} \in \R^m$은 다음과 같이 정의된다.

$$ \begin{aligned} D_i^{f(a)} &:= \lim_{h \rightarrow 0}\frac{1}{h}(f(a + h \beta_i) -f (a)) \\&=\lim_{h \rightarrow 0} \frac{1}{h}(f(a^1, \cdots, a^i + h, \cdots, a^n) - f(a^1, \cdots, a^n)) \\&= \Big( \lim_{h \rightarrow 0} \frac{1}{h} (f^j(a^1, \cdots, a^i + h, \cdots, a^n) - f^j(a^1, \cdots, a^n)) \Big)\epsilon^m_j \\&= D_i^{f^j(a)}\epsilon^m_j \end{aligned} $$ 

따라서, 행렬표현은 다음과 같다.

$$ \mathfrak{m}(D_i^{f(a)}) = \begin{bmatrix} D_i^{f^1}(a)\\\vdots\\D_i^{f^m}(a) \end{bmatrix} $$

> Reference  
> {cite}`hubbard` chap 1.7