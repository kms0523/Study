# 연속
함수 $f$가 있을 때, $\lim_{x \rightarrow a} f(x) = f(a)$면 $f(x)$는 $x=a$에서 `연속(continuous)`이라고 한다.

연속의 정의는 다음 세가지를 요구한다.
1. $f(a)$가 정의되어 있어야 한다.
2. $\lim_{x \rightarrow a} f(x)$이 존재해야 한다.
3. $\lim_{x \rightarrow a} f(x) = f(a)$

만약 함수 $f$가 연속이라면 $x \rightarrow a$일 때, $f(x) \rightarrow f(a)$임으로 $x$가 조금 변화면 $f(x)$도 조금 변한다.

>참고  
[J. Stewart] Calculus 1.8


## 명제1
함수 $f$와 $g$가 있을 때, 다음을 증명하여라.
$$ \lim_{x \rightarrow a} f(x) = f(a) \land \lim_{x \rightarrow b} g(x) = a \Rightarrow \lim_{x \rightarrow b} f(g(x)) = f(a)$$

**Proof**

$\lim_{x \rightarrow a} f(x) = f(a)$임으로 $\forall \epsilon > 0$에 대해서 다음을 만족하는 $\delta_1$가 존재한다.
$$ \begin{equation} 0 < |x-a| < \delta_1 \Rightarrow |f(x) - f(a)| < \epsilon. \end{equation}  $$

이 때, 식(1)에 $x$ 대신 $g(x)$를 대입하면 $\lim_{g(x) \rightarrow a} f(g(x)) = f(a)$임으로 $\forall \epsilon > 0$에 대해서 다음을 만족하는 $\delta_1$가 존재한다.
$$ \begin{equation} 0 < |g(x)-a| < \delta_1 \Rightarrow |f(g(x)) - f(a)| < \epsilon. \end{equation}  $$

다음으로, $\lim_{x \rightarrow b} g(x) = a$임으로 $\forall \epsilon > 0$에 대해서 다음을 만족하는 $\delta_2$가 존재한다.
$$ \begin{equation} 0 < |x - b| < \delta_2 \Rightarrow |g(x) - a| < \epsilon. \end{equation}  $$

이 때, 식(3)의 $\epsilon = \delta_1$으로 두고 식(3)과 식(2)를 합하면 $\forall \epsilon > 0$에 대해서 다음을 만족하는 $\delta_2$가 존재한다.
$$ 0 < |x - b| < \delta_2 \Rightarrow |f(g(x)) - f(a)| < \epsilon. $$

따라서 $\lim_{x \rightarrow b} f(g(x))  = f(a)$이다. $\quad {_\blacksquare}$

### 따름명제
함수 $f$와 $g$가 있을 때, 다음을 증명하여라.
$$ \lim_{x \rightarrow a} f(x) = f(a) \land \lim_{x \rightarrow b} g(x) = a \Rightarrow \lim_{x \rightarrow b} f(g(x)) = f(\lim_{x \rightarrow b} g(x))$$

**Proof**

가정에 의해 $f(\lim_{x \rightarrow b} g(x)) = f(a)$이고 명제1에 의해 $a \Rightarrow \lim_{x \rightarrow b} f(g(x)) = f(a)$이다.