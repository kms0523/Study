# Continuous
open subsset $X \subset \R^n$과 함수 $\mathbf f : X \rightarrow \R^m$이 있다고 하자.

$\mathbf x_0 \in X$에서 $f$가 `연속(continuous)`이라는 말은 다음과 동치이다.
$$ \lim_{\mathbf x \rightarrow \mathbf x_0} \mathbf f(\mathbf x) = \mathbf f(\mathbf x_0) $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach Chapter 1.5

### 참고1
연속의 정의는 다음 세가지를 요구한다.
1. $f(\mathbf x_0)$가 정의되어 있어야 한다.
2. $\lim_{x \rightarrow \mathbf x_0} f(x)$이 존재해야 한다.
3. $\lim_{x \rightarrow \mathbf x_0} f(x) = f(\mathbf x_0)$

> Reference  
> [Book] (J. Stewart) Calculus Chapter 1.8   

### 참고2
함수 $\mathbf f$가 $\mathbf x_0$에서 연속이라면 $\mathbf x \rightarrow \mathbf x_0$일 때, $\mathbf f(\mathbf x) \rightarrow \mathbf f(\mathbf x_0)$임으로 $\mathbf x$가 $\mathbf x_0$ 근처에서 조금 변화면 $\mathbf f$도 조금 변한다는 의미이다.

> Reference  
> [Book] (J. Stewart) Calculus Chapter 1.8   

### 명제1
open subsset $X \subset \R^n$과 함수 $\mathbf f : X \rightarrow \R^m$이 있다고 하자.

$X$안의 수열 중, $\mathbf x_0$로 수렴하는 수열의 집합을 $S$라 할 때,
$$ S := \{ i \mapsto \mathbf x_i \in X \enspace | \enspace \lim_{i \rightarrow \infty} \mathbf x_i = \mathbf x_0 \},$$

다음을 증명하여라.
$$ \lim_{\mathbf x \rightarrow \mathbf x_0} \mathbf f(\mathbf x) = \mathbf f(\mathbf x_0) \enspace \Leftrightarrow \enspace\forall s \in S, \quad \lim_{i \rightarrow \infty} \mathbf f(s) = \mathbf f(\mathbf x_0) $$

**Proof**

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach Chapter 1.5

# Continuous Functions
open subsset $X \subset \R^n$과 함수 $\mathbf f : X \rightarrow \R^m$이 있다고 하자.

$f$가 `연속 함수(continuous function)`라는 말은 다음과 동치이다.
$$ \forall \mathbf x \in X, \quad f \text { is continuous at } \mathbf x $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach Chapter 1.5

### 명제1
연속 함수 $f$와 $g$가 있다고 하자.

$\lim_{x \rightarrow a} f(x) = f(a)$이고 $\lim_{x \rightarrow b} g(x) = a$ 일 때, 다음을 증명하여라.
$$ \lim_{x \rightarrow b} f(g(x)) = f(a)$$

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

> Reference  
> [Book] (J. Stewart) Calculus Chapter 1.8   

#### 따름명제
다음을 증명하여라.
$$ \lim_{x \rightarrow b} f(g(x)) = f(\lim_{x \rightarrow b} g(x))$$

> Reference  
> [Book] (J. Stewart) Calculus Chapter 1.8   


