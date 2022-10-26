# Convergence
topological space $X$가 있다고 하자.

$s(n)$이 $X$위의 sequence일 때, $s(n)$이 $x \in X$에 `수렴(convergence)`한다는 말은 다음과 동치이다.
$$ \exist N \in \N \quad s.t. \quad \forall \mathcal N_x, \quad N \le n \Rightarrow s(n) \in \mathcal N_x$$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds p.26

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

이 때, $\empty, X$ 모두 openset임으로 continuity의 정의에 의해 $f$는 연속함수이다. $\quad\tiny\blacksquare$

### 명제2
Topological space $X$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ \text{Identity map } I_X : X \rightarrow X \text{ is continous} $$

**Proof**

Identity map의 정의에 의해 자명하게 open set의 preimage 또한 open set이다.

따라서, $f$는 연속함수이다. $\quad\tiny\blacksquare$

### 명제3
Topological space $X,Y$와 연속인 함수 $f: X\rightarrow Y$가 있다고 하자.

$S$가 $X$의 open set일 때, 다음을 증명하여라.
$$ f|_S \text{ is a continuous function} $$

**Proof**

Open set $U \subseteq Y$가 있을 때, $f$가 연속임으로 다음이 성립한다.
$$ f^{-1}(U) \text{ is open set on } X $$

$X$위의 open set과 $X$위의 부분집합의 교집합은 부분집합 위의 topology를 형성함으로 다음이 성립한다.
$$ f^{-1}(U) \cap S \text { is open set on } S $$

이 떄, $\text{preimg}(f|_S(U)) = f^{-1}(U) \cap S$임으로, open set의 preimage가 open이 된다.

따라서, $f|_S$는 continuous function이다. $\quad\tiny\blacksquare$ 

> Refrernce  
> [Mathematics](https://math.stackexchange.com/questions/1826827/topology-show-restriction-of-continuous-function-is-continuous-and-restriction)

### 명제4
Topological space $X,Y,Z$가 있다고 하자.

연속 함수 $f : X \rightarrow Y, g : Y \rightarrow Z$가 있을 떄, 다음을 증명하여라.
$$ g \circ f \text{ is a continuous function} $$

**Proof**

Open set $U \subseteq Z$가 있을 떄, $g$가 연속임으로 다음이 성립한다.
$$ g^{-1}(U) \text{ is a open set on Y} $$

또한 $f$가 연속임으로 다음이 성립한다.
$$ f^{-1}(g^{-1}(U)) \text{ is a open set on X} $$

이 떄, $\text{preimg}((g \circ f)(U)) = f^{-1}(g^{-1}(U))$임으로, open set의 preimage는 open set이 된다.

따라서, $g \circ f$는 continuous function이다. $\quad\tiny\blacksquare$

### 명제5(Local Criterion for Continuity)
Topological space $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ f \text{ is continous} \Leftrightarrow \forall x \in X, \quad \exist \mathcal N_x \quad s.t. \quad f|_{\mathcal N_x} \text{ is continous} $$

**Proof**

[$\Rightarrow$]  
$x \in X$에 대해서, $\mathcal N_x = X$로 두면 자명하다. $\quad\tiny\blacksquare$

[$\Leftarrow$]  
open set $U \subset Y$라 하자. 

$x \in \text{preimg}(U)$라 하면, $f|_{\mathcal N_x}$는 continous함으로 다음이 성립한다.
$$ \text{img}(\mathcal N_x) \text { is an open set on Y} $$

$U$와 $\text{img}(\mathcal N_x)$가 모두 $Y$에서 open set임으로 topology의 성질에 의해 다음이 성립한다.
$$ U \cap \text{img}(\mathcal N_x) \text { is an open set on Y} $$

$f|_{\mathcal N_x}$는 continous함으로 다음이 성립한다.
$$ \text{preimg}(U \cap \text{img}(\mathcal N_x)) \text { is an open set on X} $$

명제5.1에 의해 다음이 성립한다.
$$ \begin{aligned} & \text{preimg}(U \cap \text{img}(\mathcal N_x)) \text { is an open set on X} \\ \Leftrightarrow \enspace & \text{preimg}(U) \cap \mathcal N_x \text { is an open set on X} \end{aligned}  $$

즉, $\forall x \in \text{preimg}(U)$에 대해 $\text{preimg}(U)$에 포함되는 $x$의 neighborhood가 존재한다.

따라서, neighborhood의 성질에 의해 다음이 성립한다.
$$ \text{preimg}(U) \text{ is an open set on X} $$

따라서, continuity의 정의에 의해 $f$는 $X$에서 continous이다. $\quad\tiny\blacksquare$

#### 명제5.1
Topological space $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

$U,V \subset X$가 있을 때, 다음을 증명하여라.
$$ U \cap V = \text{preimg}(\text{img}(U) \cap \text{img}(V)) $$

**Proof**

[$U \cap V \subseteq \text{preimg}(\text{img}(U) \cap \text{img}(V))$]  
$x \in U \cap V$라 하면 다음이 성립한다.
$$\begin{aligned} & x \in U \enspace\land\enspace x \in V \\ \Rightarrow\enspace& f(x) \in \text{img}(U) \enspace \land \enspace f(x) \in \text{img}(V) \\ \Rightarrow\enspace& f(x) \in \text{img}(U) \cap \text{img}(V) \\ \Rightarrow\enspace& x \in \text{preimg}(\text{img}(U) \cap \text{img}(V)) \end{aligned} $$

[$\text{preimg}(\text{img}(U) \cap \text{img}(V)) \subseteq U \cap V$]  
$x \in \text{preimg}(\text{img}(U) \cap \text{img}(V))$라 하면 다음이 성립한다.
$$\begin{aligned} & f(x) \in \text{img}(U) \cap \text{img}(V) \\ \Rightarrow\enspace& f(x) \in \text{img}(U) \enspace \land \enspace f(x) \in \text{img}(V) \\ \Rightarrow\enspace& x \in U  \enspace \land \enspace x \in V \\ \Rightarrow\enspace& x \in U \cap V \quad\tiny\blacksquare \end{aligned} $$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds Proposition 2.19

