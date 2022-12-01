# Continuous
Metric space $M_1,M_2$와 함수 $f : M_1 \rightarrow M_2$가 있다고 하자.

$x_0 \in M_1$에서 $f$가 `연속(continuous)`이라는 말은 다음과 동치이다.
$$ \lim_{x \rightarrow x_0} f(x) = f(x_0) $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach Chapter 1.5

### 참고1
연속의 정의를 풀어 쓰면 다음과 같다.
$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad x \in  B_\delta(x_0) \Rightarrow f(x) \in B_\epsilon(f(x_0)) $$

### 참고2
연속의 정의는 다음 세가지를 요구한다.
1. $f(x_0)$가 정의되어 있어야 한다.
2. $\lim_{x \rightarrow x_0} f(x)$이 존재해야 한다.
3. $\lim_{x \rightarrow x_0} f(x) = f(x_0)$

> Reference  
> [Book] (J. Stewart) Calculus Chapter 1.8   

### 참고3
함수 $f$가 $x_0$에서 연속이라면 $x \rightarrow x_0$일 때, $f(x) \rightarrow f(x_0)$임으로 $x$가 $x_0$ 근처에서 조금 변화면 $f$도 조금 변한다는 의미이다.

> Reference  
> [Book] (J. Stewart) Calculus Chapter 1.8   

### 명제1
open subsset $X \subset \R^n$과 함수 $\mathbf f : X \rightarrow \R^m$이 있을 때,

$X$안의 수열 중, $\mathbf x_0$로 수렴하는 수열의 집합을 $S$로 정의하자.
$$ S := \{ s(n) : \N \rightarrow X \enspace | \enspace  \lim_{n \rightarrow \infty} \mathbf s(n) = \mathbf x_0 \}$$

이 때, 다음을 증명하여라.
$$ \lim_{\mathbf x \rightarrow \mathbf x_0} \mathbf f(\mathbf x) = \mathbf f(\mathbf x_0) \enspace \Leftrightarrow \enspace \forall s \in S, \quad \lim_{n \rightarrow \infty} (\mathbf f \circ s)(n) = \mathbf f(\mathbf x_0) $$

**Proof**

[$\Rightarrow$]  
$\mathbf f$가 $\mathbf x_0$에서 연속임으로, 다음이 성립한다.
$$ \forall \epsilon >0, \quad \exist \delta \quad s.t. \quad |\mathbf x - \mathbf x_0| < \delta \Rightarrow |\mathbf {f(x) - f(x_0)}| < \epsilon$$

이 때, $s \in S$가 $\mathbf x_0$에 수렴하는 수열임으로 다음이 성립한다.
$$ \exist N \quad s.t. \quad N < n \Rightarrow |s(n) - \mathbf x_0| < \delta $$

즉, 이러한 $N$에 대해서는 다음이 성립한다.
$$ N < n \Rightarrow |(\mathbf f \circ s)(n)) - \mathbf{f(x_0)}| < \epsilon $$

따라서, $(\mathbf f\circ s)(n)$은 $\mathbf{f(x_0)}$로 수렴하는 수열이다. $\quad {_\blacksquare}$

[$\Leftarrow$]  
다음과 같이 가정하자.
$$\forall s \in S, \quad \lim_{n \rightarrow \infty} (\mathbf f \circ s)(n) = \mathbf f(\mathbf x_0) \Rightarrow \lim_{\mathbf x \rightarrow \mathbf x_0} \mathbf f(\mathbf x) \neq \mathbf f(\mathbf x_0)$$

그러면 다음이 성립한다.
$$ \forall \delta, \quad \exist \epsilon \quad s.t. \quad |\mathbf x - \mathbf x_0| < \delta \text{ but } \epsilon \le |\mathbf {f(x) - f(x_0)}|   $$

이 때, $s \in S$가 $\mathbf x_0$에 수렴하는 수열임으로 다음이 성립한다.
$$ \exist N \quad s.t. \quad N < n \Rightarrow |s(n) - \mathbf x_0| < \delta $$

즉, 이러한 $N$에 대해서는 다음이 성립한다.
$$ N < n \Rightarrow \epsilon \le |(\mathbf f \circ s)(n)) - \mathbf{f(x_0)}|  $$

이는, $(\mathbf f\circ s)(n)$은 $\mathbf{f(x_0)}$로 수렴하는 수열이라는 가정에 모순됨으로 귀류법에의해 다음 명제는 참이다.
$$\forall s \in S, \quad \lim_{n \rightarrow \infty} (\mathbf f \circ s)(n) = \mathbf f(\mathbf x_0) \Rightarrow \lim_{\mathbf x \rightarrow \mathbf x_0} \mathbf f(\mathbf x) = \mathbf f(\mathbf x_0) \quad {_\blacksquare}$$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach Chapter 1.5

### 명제2
$f$와 $g$가 각각 $a$와 $b$에서 연속이라고 있다고 하자.
$$\lim_{x \rightarrow a} f(x) = f(a), \enspace \lim_{x \rightarrow b} g(x) = a$$

이 때, 다음을 증명하여라.
$$ \lim_{x \rightarrow b} (f \circ g)(x) = (f \circ g)(b)$$

**Proof**

함수의 극한의 명제에 의해 다음이 성립한다.
$$ \lim_{x \rightarrow b} (f \circ g)(x) = f(g(b)) = (f \circ g)(b)  \quad {_\blacksquare}$$

> Reference  
> [Book] (J. Stewart) Calculus Chapter 1.8   

#### 따름명제
다음을 증명하여라.
$$ \lim_{x \rightarrow b} f(g(x)) = f(\lim_{x \rightarrow b} g(x))$$

> Reference  
> [Book] (J. Stewart) Calculus Chapter 1.8   


# Continuous Functions
open subsset $X \subset \R^n$과 함수 $\mathbf f : X \rightarrow \R^m$이 있다고 하자.

$f$가 `연속 함수(continuous function)`라는 말은 다음과 동치이다.
$$ \forall \mathbf x \in X, \quad f \text { is continuous at } \mathbf x $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach Chapter 1.5

### 명제
metric spaces $(M_1,d_1),$ $(M_2,d_2)$와 surjective 함수 $f : M_1 \rightarrow M_2$가 있다고 하자.

이 때, 다음을 증명하여라
$$ f \text{ is continuous } \Leftrightarrow \text{preimage of every open subset is open} $$

**Proof**

[$\Rightarrow$]  
$U \subseteq M_2$가 openset이라 하자.

$x \in \text{preimg}(U)$면 $U$가 open set임으로 다음이 성립한다.
$$ \exist r > 0  \quad s.t. \quad B_r(f(x)) \subseteq U $$

이 때, $f$가 continuous임으로 다음이 성립한다.
$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad y \in  B_\delta(x) \Rightarrow f(y) \in B_\epsilon(f(x)) $$

즉, $\exist \delta \quad s.t. \quad y \in  B_\delta(x) \Rightarrow f(y) \in U$ 임으로 다음이 성립한다.
$$ \exist \delta \quad s.t. \quad B_\delta(x) \subseteq \text{preimg}(U) $$

임의의 $x$에서 $\text{preimg}(U)$에 속하는 ball이 존재함으로, $\text{preimg}(U)$는 open set이다. $\quad {_\blacksquare}$

[$\Leftarrow$]  
$U \subseteq M_2$가 open subset이라 하자.

$U$가 open set임으로 $f(x) \in U$에 대해 다음이 성립한다.
$$ \exist \epsilon \in \R^+ \quad s.t. \quad B_\epsilon(f(x)) \subseteq U $$

그러면 가정에 의해, $\text{preimg}(B_r(f(x)))$는 open set임으로 다음이 성립한다.
$$ \exist \delta \in \R^+ \quad s.t. \quad B_\delta(x) \subseteq \text{preimg}(B_\epsilon(f(x))) $$

즉, 다음이 성립한다.
$$ y \in B_\delta(x) \Rightarrow f(y) \in B_\epsilon(f(x)) $$

이를 조합하면 다음이 성립힌다.
$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad y \in B_\delta(x) \Rightarrow f(y) \in B_\epsilon(f(x)) $$

즉, $f$는 임의의 $x$에서 연속임으로, $f$는 continous function이다. $\quad {_\blacksquare}$ 

> Reference  
> [Book] (Lee) Introduction to Topological Manifolds p.399

