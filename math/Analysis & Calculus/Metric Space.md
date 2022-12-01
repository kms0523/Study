# Metric Space
집합 $M$과 함수 $d : M \times M \rightarrow \R$이 있다고 하자.

$x,y,z \in M$에 대해, $d$가 다음 성질들을 만족할 때,
1. $$ d(x,x) = 0 $$
2. $$ d(x,y) > 0 \text{ if } x \neq y $$ 
3. $$ d(x,y) = d(y,x) $$
4. $$ d(x,y) \le d(x,z) + d(z,y) $$

집합 $M$에 함수 $d$가 주어진 구조인 $(M,d)$를 `metric space`라고 한다.

### 참고1
$x \in M$을 point, $d$를 metric of the space라고 부른다.

### 참고2
$M = \R^n$이고 $d(x,y) = |x-y|$로 주어진 metric space를 $n$ 차원 `Euclidean metric space`라고 한다.

$n$ 차원 Euclidean metric space를 간단하게 $\R^n$으로 표기한다.

> Reference  
> [Book] (Apostol)  Mathematical analysis Chap 3.13

# Metric Subspace
metric space $(M,d)$가 있다고 하자.

$S \subseteq M$일 때, $d$의 정의역과 치역이 $S$로 restriction된 함수 $d_s$를 다음과 같이 정의하자.
$$d_S := d |_S^S : S \times S \rightarrow \R \quad s.t. \quad (s_1,s_2) \mapsto d(s_1,s_2) $$

이 때, $(S,d_s)$는 metric space이며 이를 `metric subspace`라 한다.

> Reference  
> [Book] (Apostol)  Mathematical analysis p.61 

### 참고
$S$가 $M$의 metric subspace라는 것을 간단하게 다음과 같이 표기한다.
$$ S \le M $$


# Limit of Functions
metric spaces $(M_1,d_1),$ $(M_2,d_2)$와 함수 $f : M_1 \rightarrow M_2$가 있다고 하자.

$x_0 \in M_1$에서 함수 $f$의 극한값이 $L \in M_2$이란 말은 다음과 동치이다.
$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad 0 < d_1(x, x_0) < \delta \Rightarrow d_2(f(x), L) < \epsilon $$

이를 간단하게 다음과 같이 표기한다.
$$ \lim_{x \rightarrow x_0} f(x) = L $$

> Reference  
> [Book] (Lee) Introduction to Topological Manifolds Appendix B

### 참고
open ball을 이용해서 극한의 정의를 표현하면 다음과 같다.
$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad x \in  B_\delta(x_0) \Rightarrow f(x) \in B_\epsilon(L) $$

# Continuous
metric spaces $(M_1,d_1),$ $(M_2,d_2)$와 함수 $f : M_1 \rightarrow M_2$가 있다고 하자.

$x_0 \in M_1$에서 함수 $f$가 `연속(conitnous)`하다는 말은 다음과 동치이다.
$$ \lim_{x \rightarrow x_0} f(x) = f(x_0) $$

> Reference  
> [Book] (Lee) Introduction to Topological Manifolds Appendix B

### 참고
연속의 정의를 풀어 쓰면 다음과 같다.
$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad 0 < d_1(x, x_0) < \delta \Rightarrow d_2(f(x), f(x_0)) < \epsilon. $$

이를 open ball을 이용해 표현하면 다음과 같다.
$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad x \in  B_\delta(x_0) \Rightarrow f(x) \in B_\epsilon(f(x_0)) $$

# Continuous Functions
metric spaces $(M_1,d_1),$ $(M_2,d_2)$와 함수 $f : M_1 \rightarrow M_2$가 있다고 하자.

$f$가 `연속함수(conitnous funtion)`이란 말은 다음과 동치이다.
$$ \forall x \in M_1, \quad f \text { is continuous at } x $$

> Reference  
> [Book] (Lee) Introduction to Topological Manifolds Appendix B

### 명제
metric spaces $(M_1,d_1),$ $(M_2,d_2)$와 surjective 함수 $f : M_1 \rightarrow M_2$가 있다고 하자.

이 때, 다음을 증명하여라
$$ f \text{ is continuous } \Leftrightarrow \text{preimage of every open subset is open} $$

**Proof**

[$\Rightarrow$]  
$f$가 continuous하고 $U \subseteq M_2$가 open subset이라 하자.

$x \in \text{preimg}(U)$면 $U$가 open set임으로 다음이 성립한다.
$$ \exist r > 0  \quad s.t. \quad B_r(f(x)) \subseteq U $$

이 때, $f$가 $x$에서 continuous임으로 다음이 성립한다.
$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad y \in  B_\delta(x) \Rightarrow f(y) \in B_\epsilon(f(x)) $$

즉, $\exist \delta \quad s.t. \quad y \in  B_\delta(x) \Rightarrow f(y) \in U$ 임으로 다음이 성립한다.
$$ \exist \delta \quad s.t. \quad B_\delta(x) \subseteq \text{preimg}(U) $$

따라서, $\text{preimg}(U)$는 open set이다. $\quad {_\blacksquare}$

[$\Leftarrow$]  
$U \subseteq M_2$가 open subset이라 하자.

$f(x) \in U$에 대해 다음이 성립한다.
$$ \exist r > 0 \quad s.t. \quad B_r(f(x)) \subseteq U $$

그러면 가정에 의해, $\text{preimg}(B_r(f(x)))$는 open set임으로 다음이 성립한다.
$$ \exist \delta > 0 \quad s.t. \quad B_\delta(x) \subseteq \text{preimg}(B_r(f(x))) $$

즉, 다음이 성립한다.
$$ y \in B_\delta(x) \Rightarrow f(y) \in B_r(f(x)) $$

이를 조합하면 다음이 성립힌다.
$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad y \in B_\delta(x) \Rightarrow f(y) \in B_\epsilon(f(x)) $$

즉, $f$는 임의의 $x$에서 연속임으로, $f$는 continous function이다. $\quad {_\blacksquare}$ 

> Reference  
> [Book] (Lee) Introduction to Topological Manifolds Appendix B