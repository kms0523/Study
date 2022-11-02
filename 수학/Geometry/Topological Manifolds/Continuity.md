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

$U$가 $X$의 open set일 때, 다음을 증명하여라.
$$ f|_{U \times f(U)} \text{ is a continuous function} $$

**Proof**

$V$가 $Y$의 open set이라고 하자.

$Y$의 subspace $f(U)$에 대해 다음이 성립한다.
$$ f(U) \cap V \text{ is open set on } f(U) $$

$f$가 연속임으로 다음이 성립한다.
$$ \text{preimg}_f(V) \text{ is open set on } X $$

$X$의 subspace $U$가 있을 떄, open set의 성질에 의해 다음이 성립한다.
$$ \text{preimg}_f(V) \cap U \text { is open set on } U $$

이 때, $\text{preimg}_{f|_U}(f(U) \cap V) =  \text{preimg}_f(V) \cap U$이다.

따라서, $f|_U$에 의해 $f(U)$위의 임의의 open set의 preimg가 $U$위의 open set이 됨으로, $f|_U$는 continuous function이다. $\quad\tiny\blacksquare$ 

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

보조명제5.1에 의해 다음이 성립한다.
$$ \begin{aligned} & \text{preimg}(U \cap \text{img}(\mathcal N_x)) \text { is an open set on X} \\ \Leftrightarrow \enspace & \text{preimg}(U) \cap \mathcal N_x \text { is an open set on X} \end{aligned}  $$

즉, $\forall x \in \text{preimg}(U)$에 대해 $\text{preimg}(U)$에 포함되는 $x$의 neighborhood가 존재한다.

따라서, neighborhood의 성질에 의해 다음이 성립한다.
$$ \text{preimg}(U) \text{ is an open set on X} $$

따라서, continuity의 정의에 의해 $f$는 $X$에서 continous이다. $\quad\tiny\blacksquare$

#### 보조명제5.1
Topological space $X,Y$와 함수 $f : X \rightarrow Y$가 있다고 하자.

$V_1,V_2 \subset Y$가 있을 때, 다음을 증명하여라.
$$ \text{preimg}(V_1) \cap \text{preimg}(V_2) = \text{preimg}(V_1 \cap V_2) $$

**Proof**

[$\text{preimg}(V_1) \cap \text{preimg}(V_2) \subseteq \text{preimg}(V_1 \cap V_2)$]  
$x \in \text{preimg}(V_1) \cap \text{preimg}(V_2)$라 하면 다음이 성립한다.
$$\begin{aligned} & x \in \text{preimg}(V_1) \enspace\land\enspace x \in \text{preimg}(V_2) \\ \Rightarrow\enspace& f(x) \in V_1 \enspace\land\enspace f(x) \in V_2 \\ \Rightarrow\enspace& f(x) \in V_1 \cap V_2 \\ \Rightarrow\enspace& x \in \text{preimg}(V_1 \cap V_2) \end{aligned} $$

[$\text{preimg}(V_1 \cap V_2) \subseteq \text{preimg}(V_1) \cap \text{preimg}(V_2)$]  
$x \in \text{preimg}(V_1 \cap V_2)$라 하면 다음이 성립한다.
$$\begin{aligned} & f(x) \in V_1 \cap V_2 \\ \Rightarrow\enspace& f(x) \in V_1 \enspace \land \enspace f(x) \in V_2 \\ \Rightarrow\enspace& x \in \text{preimg}(V_1) \enspace\land\enspace x \in \text{preimg}(V_2) \\ \Rightarrow\enspace& x \in \text{preimg}(V_1) \cap \text{preimg}(V_2) \quad\tiny\blacksquare \end{aligned} $$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds Proposition 2.19

