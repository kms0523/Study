# Convergence
topological space $X$가 있다고 하자.

$s(n)$이 $X$위의 sequence일 때, $s(n)$이 $x \in X$에 `수렴(convergence)`한다는 말은 다음과 동치이다.
$$ \exist N \in \N \quad s.t. \quad N \le n \Rightarrow \forall \mathcal N_x, \quad  s(n) \in \mathcal N_x$$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds exercise p.26

### 명제1
metric space $M$이 있을 떄, 다음을 증명하여라.
$$\text{metric space convegence definition } \Leftrightarrow \text{topological space convegence definition} $$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds exercise 2.12

# Continuity
topological space $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

이 때, 다음을 만족하는 $f$를 `연속(continuous)`이라고 한다.
$$ \text{preimage of every open subset is open}$$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds p.26

### 명제1
Topological space $X,Y$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ \text{Every constant map } f : X \rightarrow Y \text{ is continous} $$

**Proof**

$f(X) = y \in Y$라고 하자.
 
openset $S \subset Y$가 있을 때, 다음이 성립한다.
$$ \text{preimg}(S) = \begin{cases} \empty & y \notin S \\ X & y \in S \end{cases} $$

이 때, $\empty, X$ 모두 openset임으로 continuity의 정의에 의해 $f$는 연속함수이다. $\quad {_\blacksquare}$

### 명제2
Topological space $X$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ \text{Identity map } I_X : X \rightarrow X \text{ is continous} $$

**Proof**

Identity map의 정의에 의해 자명하게 open set의 preimage 또한 open set이다.

따라서, $f$는 연속함수이다. $\quad{_\blacksquare}$

### 명제3

> Refrernce  
> [Mathematics](https://math.stackexchange.com/questions/1826827/topology-show-restriction-of-continuous-function-is-continuous-and-restriction)

### 명제5(Local Criterion for Continuity)
topological space $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ f \text{ is continous} \Leftrightarrow \forall x \in X, \quad \exist \mathcal N_x \quad s.t. \quad f|_{\mathcal N_x} \text{ is continous} $$

**Proof**

[$\Rightarrow$]  
$x \in X$에 대해서, $\mathcal N_x = X$로 두면 자명하다. $\quad {_\blacksquare}$

[$\Leftarrow$]  
open set $U \subset Y$라 하자. 

$x \in \text{preimg}(U)$라 하면, $f|_{\mathcal N_x}$는 continous함으로 다음이 성립한다.
$$ \text{img}(\mathcal N_x) \text { is an open set on Y} $$

$U$와 $\text{img}(\mathcal N_x)$가 모두 $Y$에서 open set임으로 topology의 성질에 의해 다음이 성립한다.
$$ U \cap \text{img}(\mathcal N_x) \text { is an open set on Y} $$

$f|_{\mathcal N_x}$는 continous함으로 다음이 성립한다.
$$ \begin{aligned} & \text{preimg}(U \cap \text{img}(\mathcal N_x)) \text { is an open set on X} \\ \Leftrightarrow \enspace & \text{preimg}(U) \cap \mathcal N_x \text { is an open set on X} \end{aligned}  $$

즉, $\forall x \in \text{preimg}(U)$에 대해 $\text{preimg}(U)$에 포함되는 $x$의 neighborhood가 존재한다.

따라서, neighborhood의 성질에 의해 다음이 성립한다.
$$ \text{preimg}(U) \text{ is an open set on X} $$

따라서, continuity의 정의에 의해 $f$는 $X$에서 continous이다. $\quad {_\blacksquare}$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds Proposition 2.19