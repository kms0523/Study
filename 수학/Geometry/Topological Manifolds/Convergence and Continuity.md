# Convergence
topological space $X$가 있다고 하자.

$s(n)$이 $X$위의 sequence일 때, $s(n)$이 $x \in X$에 `수렴(convergence)`한다는 말은 다음과 동치이다.
$$ \exist N \in \N \quad s.t. \quad N \le n \Rightarrow \forall \mathcal N_x, \quad  s(n) \in \mathcal N_x$$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds exercise p.26

### 명제1
metric space $M$이 있다고 하자.

$M$에서 다음을 증명하여라.
$$\text{metric space convegence definition } \Leftrightarrow \text{topological space convegence definition} $$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds exercise 2.12

# Continuity
topological space $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

이 때, 다음을 만족하는 $f$를 `연속(continuous)`이라고 한다.
$$ \text{preimage of every open subset is open}$$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds p.26


### 참고
metric space에서 $\epsilon-\delta$정의를 만족하는 continuous map들은 전부 위의 정의를 만족한다.

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds p.26

### 명제
topological space $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ f \text{ is continous on } X \Leftrightarrow \forall x \in X, \quad f \text{ is continous on } \mathcal N_x $$

**Proof**

[$\Rightarrow$]  
$x \in X$에 대해서, $\mathcal N_x = X$로 두면 자명하다. $\quad {_\blacksquare}$

[$\Leftarrow$]  
open set $U \subset Y$라 하자. 

$x \in \text{preimg}(U)$라 하면, $\mathcal N_x$에서 $f$는 continous함으로 다음이 성립한다.
$$ \text{img}(\mathcal N_x) \text { is an open set on Y} $$

$U$와 $\text{img}(\mathcal N_x)$가 모두 $Y$에서 open set임으로 topology의 성질에 의해 다음이 성립한다.
$$ U \cap \text{img}(\mathcal N_x) \text { is an open set on Y} $$

$\mathcal N_x$에서 $f$는 continous함으로 다음이 성립한다.
$$ \begin{aligned} & \text{preimg}(U \cap \text{img}(\mathcal N_x)) \text { is an open set on X} \\ \Leftrightarrow \enspace & \text{preimg}(U) \cap \mathcal N_x \text { is an open set on X} \end{aligned}  $$

즉, $\forall x \in \text{preimg}(U)$에 대해 $\text{preimg}(U)$에 포함되는 $x$의 neighborhood가 존재하며 neighborhood의 성질에 의해 
다음이 성립한다.
$$ \text{preimg}(U) \text{ is an open set on X} $$

따라서, continuous 정의에 의해 $f$는 $X$에서 continous이다. $\quad {_\blacksquare}$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds Proposition 2.19