# Continuous at a Point
## 정의
Metric space $M_1,M_2$가 있다고 하자.

$X$가 $M_1$의 open set일 때, 함수 $f : X \rightarrow M_2$가 $x \in X$에서 `연속(continuous)`이라는 말은 다음과 동치이다.

$$ \forall t \in X, \forall \epsilon \in \R^+, \quad \exist \delta \in \R^+ \st d_1(x,t) < \delta \implies d_2(f(x),f(t)) < \epsilon $$

> Reference  
> {cite}`hubbard` Chapter 1.5

### 참고1
연속을 정의하기 위해서는 $f$가 $x$에서 정의되어 있음으로 함수의 수렴과는 정의상 약간의 차이가 있다.

함수의 수렴의 정의에서 $f$가 $x$에서 정의되지 않아도 동작하도록 하게 만드는 모든 장치들이 함수의 연속의 정의에서는 빠져있는것을 알 수 있다.

* limit point
* $0 < d <\delta$

### 참고2
연속의 정의를 Open ball을 이용해 표현하면 다음과 같다.

$$ \forall \epsilon \in \R^+, \quad \exist \delta \in \R^+ \st f (B_{M_1}(x,\delta)) \subseteq B_{M_2}(f(x),\epsilon) $$

혹은 다음과 같이 표현할 수 있다.

$$ \forall \epsilon \in \R^+, \quad \exist \delta \in \R^+ \st B_{M_1}(x,\delta) \subseteq \preimg(B_{M_2}(f(x),\epsilon)) $$


즉, $x \in X$에서 continuous하다는 말은 $f(x)$를 중심으로 하는 open ball $B$마다 $f$에 의해서 $B$에 포함되는 $x$를 중심으로 하는 open ball이 존재한다는 말이다.



### 참고2
연속의 정의는 다음 세가지를 요구한다.
1. $f(x_0)$가 정의되어 있어야 한다.
2. $\lim_{x \rightarrow x_0} f(x)$이 존재해야 한다.
3. $\lim_{x \rightarrow x_0} f(x) = f(x_0)$

> Reference  
> {cite}`stewart` Chapter 1.8   

### 참고3
함수 $f$가 $x_0$에서 연속이라면 $x \rightarrow x_0$일 때, $f(x) \rightarrow f(x_0)$임으로 $x$가 $x_0$ 근처에서 조금 변화면 $f$도 조금 변한다는 의미이다.

> Reference  
> {cite}`stewart` Chapter 1.8   

### 명제1
open subsset $X \subset \R^n$과 함수 $\mathbf f : X \rightarrow \R^m$이 있을 때,

$X$안의 수열 중, $\mathbf x_0$로 수렴하는 수열의 집합을 $S$로 정의하자.

$$ S := \{ s(n) : \N \rightarrow X \enspace | \enspace  \lim_{n \rightarrow \infty} \mathbf s(n) = \mathbf x_0 \}$$

이 때, 다음을 증명하여라.

$$ \lim_{\mathbf x \rightarrow \mathbf x_0} \mathbf f(\mathbf x) = \mathbf f(\mathbf x_0) \enspace \iff \enspace \forall s \in S, \quad \lim_{n \rightarrow \infty} (\mathbf f \circ s)(n) = \mathbf f(\mathbf x_0) $$

**Proof**

[$\implies$]  
$\mathbf f$가 $\mathbf x_0$에서 연속임으로, 다음이 성립한다.

$$ \forall \epsilon >0, \quad \exist \delta \st |\mathbf x - \mathbf x_0| < \delta \implies |\mathbf {f(x) - f(x_0)}| < \epsilon$$

이 때, $s \in S$가 $\mathbf x_0$에 수렴하는 수열임으로 다음이 성립한다.

$$ \exist N \st N < n \implies |s(n) - \mathbf x_0| < \delta $$

즉, 이러한 $N$에 대해서는 다음이 성립한다.

$$ N < n \implies |(\mathbf f \circ s)(n)) - \mathbf{f(x_0)}| < \epsilon $$

따라서, $(\mathbf f\circ s)(n)$은 $\mathbf{f(x_0)}$로 수렴하는 수열이다. $\quad {_\blacksquare}$

[$\impliedby$]  
다음과 같이 가정하자.

$$\forall s \in S, \quad \lim_{n \rightarrow \infty} (\mathbf f \circ s)(n) = \mathbf f(\mathbf x_0) \implies \lim_{\mathbf x \rightarrow \mathbf x_0} \mathbf f(\mathbf x) \neq \mathbf f(\mathbf x_0)$$

그러면 다음이 성립한다.

$$ \forall \delta, \quad \exist \epsilon \st |\mathbf x - \mathbf x_0| < \delta \text{ but } \epsilon \le |\mathbf {f(x) - f(x_0)}|   $$

이 때, $s \in S$가 $\mathbf x_0$에 수렴하는 수열임으로 다음이 성립한다.

$$ \exist N \st N < n \implies |s(n) - \mathbf x_0| < \delta $$

즉, 이러한 $N$에 대해서는 다음이 성립한다.

$$ N < n \implies \epsilon \le |(\mathbf f \circ s)(n)) - \mathbf{f(x_0)}|  $$

이는, $(\mathbf f\circ s)(n)$은 $\mathbf{f(x_0)}$로 수렴하는 수열이라는 가정에 모순됨으로 귀류법에의해 다음 명제는 참이다.

$$\forall s \in S, \quad \lim_{n \rightarrow \infty} (\mathbf f \circ s)(n) = \mathbf f(\mathbf x_0) \implies \lim_{\mathbf x \rightarrow \mathbf x_0} \mathbf f(\mathbf x) = \mathbf f(\mathbf x_0) \quad {_\blacksquare}$$

> Reference  
> {cite}`hubbard` Chapter 1.5

### 명제2
$f$와 $g$가 각각 $a$와 $b$에서 연속이라고 있다고 하자.

$$\lim_{x \rightarrow a} f(x) = f(a), \enspace \lim_{x \rightarrow b} g(x) = a$$

이 때, 다음을 증명하여라.

$$ \lim_{x \rightarrow b} (f \circ g)(x) = (f \circ g)(b)$$

**Proof**

함수의 극한의 명제에 의해 다음이 성립한다.

$$ \lim_{x \rightarrow b} (f \circ g)(x) = f(g(b)) = (f \circ g)(b)  \quad {_\blacksquare}$$

> Reference  
> {cite}`stewart` Chapter 1.8   

#### 따름명제2.1
다음을 증명하여라.

$$ \lim_{x \rightarrow b} f(g(x)) = f(\lim_{x \rightarrow b} g(x))$$

> Reference  
> {cite}`stewart` Chapter 1.8   