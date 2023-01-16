# Continuous
## 정의
Metric space $M_1,M_2$와 함수 $f : M_1 \rightarrow M_2$가 있다고 하자.

$x_0 \in M_1$에서 $f$가 `연속(continuous)`이라는 말은 다음과 동치이다.

$$ \lim_{x \rightarrow x_0} f(x) = f(x_0) $$

> Reference  
> {cite}`hubbard` Chapter 1.5

### 참고1
연속의 정의를 풀어 쓰면 다음과 같다.

$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad x \in  B_\delta(x_0) \implies f(x) \in B_\epsilon(f(x_0)) $$

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

$$ \forall \epsilon >0, \quad \exist \delta \quad s.t. \quad |\mathbf x - \mathbf x_0| < \delta \implies |\mathbf {f(x) - f(x_0)}| < \epsilon$$

이 때, $s \in S$가 $\mathbf x_0$에 수렴하는 수열임으로 다음이 성립한다.

$$ \exist N \quad s.t. \quad N < n \implies |s(n) - \mathbf x_0| < \delta $$

즉, 이러한 $N$에 대해서는 다음이 성립한다.

$$ N < n \implies |(\mathbf f \circ s)(n)) - \mathbf{f(x_0)}| < \epsilon $$

따라서, $(\mathbf f\circ s)(n)$은 $\mathbf{f(x_0)}$로 수렴하는 수열이다. $\quad {_\blacksquare}$

[$\impliedby$]  
다음과 같이 가정하자.

$$\forall s \in S, \quad \lim_{n \rightarrow \infty} (\mathbf f \circ s)(n) = \mathbf f(\mathbf x_0) \implies \lim_{\mathbf x \rightarrow \mathbf x_0} \mathbf f(\mathbf x) \neq \mathbf f(\mathbf x_0)$$

그러면 다음이 성립한다.

$$ \forall \delta, \quad \exist \epsilon \quad s.t. \quad |\mathbf x - \mathbf x_0| < \delta \text{ but } \epsilon \le |\mathbf {f(x) - f(x_0)}|   $$

이 때, $s \in S$가 $\mathbf x_0$에 수렴하는 수열임으로 다음이 성립한다.

$$ \exist N \quad s.t. \quad N < n \implies |s(n) - \mathbf x_0| < \delta $$

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