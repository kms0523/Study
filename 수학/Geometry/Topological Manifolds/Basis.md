# Basis
Topological space $X$가 있다고 하자.

$X$의 subset collection $\mathcal{B}$가 다음을 만족할 때, $\mathcal{B}$를 topology $\mathcal{T_X}$의 basis라고 한다.
1. Every element of $\mathcal{B}$ is an open subset of $X$
2. Every open subset of $X$ is the union of some collection of elements of $\mathcal{B}$

### 참고
$X$의 open set $\empty$는 $\mathcal{B}$의 empty collection의 union이다.

### 명제1(Basis criterion)
Topological sapce $X$와 $X$의 basis $\mathcal{B}$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ U \text{ is an open set of } X \iff \forall x \in U, \quad  \exist B \in \mathcal{B} \quad s.t. \quad x \in B \subseteq U $$

 **Proof**
[$\implies$]  
전제에 의해 $U$가 open set임으로 basis의 성질에 의해 어떤 $B_i \in \mathcal{B}, \enspace(i = 1,\cdots,k)$에 대해 다음이 성립한다.
$$ U = \bigcup_{i=1}^k B_i $$

따라서 $\forall x \in U$에 대해 다음이 성립한다.
$$ \exist j \in [1,k] \quad s.t. \quad x \in B_j \subseteq U $$

[$\impliedby$]  
전제에 의해, 다음이 성립한다.
$$ U = \bigcup_{x \in U}B_x $$

이 떄, $B_x$는 $X$의 open set임으로 open set의 성질에 의해 다음이 성립한다.
$$ U \text{ is an open set of } X \qed $$

### 명제2
Metric topology $M$이 있다고 하자.

이 떄, 다음을 증명하여라.
$$ \text{Collection of open ball in } M \text{ is a basis for } M $$

**Proof**

Open ball의 성질에 의해 다음이 성립한다.
1. $$ \text{open ball in } M \text{ is an open set of } M $$
2. $$ \text{Every open set of } M \text{ is an union of collection of some open balls } $$

따라서, basis의 정의를 만족함으로 $M$의 collection of open ball은 $M$의 basis이다. $\qed$

### 명제3
Euclidean topology $\R^n$이 있다고 하자.

Open square $S_{\R^n}(x,l)$를 다음과 같이 정의하자.
$$ S_{\R^n}(x,l) := \{y \in \R^n \enspace | \enspace |x_i - y_i| < l/2\}  $$

$S_{\R^n}(x,l)$의 collection $\mathcal{B}$를 다음과 같이 정의하자.
$$ \mathcal{B} := \{ S_{\R^n}(x,l) \enspace | \enspace x \in \R^n \enspace\land\enspace l \in \R^+ \} $$

이 떄, 다음을 증명하여라.
$$ \mathcal{B} \text{ is basis for } \R^n $$

**Proof**

[$S_{\R^n}(x,l)$ is open set]  
$S_{\R^n}(x,l) \in \mathcal{B}$가 있다고 하자.

$\forall y \in S_{\R^n}(x,l)$에 대해 open ball $B_{\R^n}(y,\epsilon)$을 고려해보자.

$\forall z \in B_{\R^n}(y,\epsilon)$에 대해 다음이 성립한다.
$$ \begin{aligned} |x_i - z_i | &= |x_i - y_i + y_i - z_i| \\&< |x_i - y_i| + |y_i - z_i| \\&< |x_i-y_i| + \epsilon  \end{aligned} $$

이 떄, $\epsilon \in \R^+$을 다음과 같이 정의하자.
$$ \epsilon = \frac{s}{2} - |x_i - y_i| $$

그러면 $\forall z \in B_{\R^n}(y,\epsilon)$에 대해 다음이 성립한다.
$$ |x_i - z_i| < \frac{s}{2} $$

따라서 다음이 성립한다.
$$ B_{\R^n}(y,\epsilon) \subseteq S_{\R^n}(x,l) $$

이를 정리하면 다음과 같다.
$$ \forall y \in S_{\R^n}(x,l), \quad \exist \epsilon \quad s.t. \quad B_{\R^n}(y,\epsilon) \subseteq S_{\R^n}(x,l) $$

따라서, Neighborhood의 성질에 의해 $S_{\R^n}(x,l)$는 $\R^n$의 open set이다.$\qed$

[Every open set is union of some collection of $S_{\R^n}(x,l)$]  
보조명제3.1에 의해 open ball은 open square collection의 union이다.

그리고 metric space에서 모든 open set은 어떤 open ball collection의 union이다.

따라서, Euclidean space에서 모든 open set은 어떤 open square collection의 union이다. $\qed$

#### 보조명제3.1
다음을 증명하여라.
$$ \text{Open ball is union of some collection of open square}  $$

**Proof**

$x \in \R^n, \enspace r \in \R^+$이 있을 떄, $B_{\R^n}(x,r)$이 있다고 하자.

$\forall y \in B_{\R^n}(x,r)$에 $S_{\R^n}(y,l)$를 고려해보자.

$\forall z \in S_{\R^n}(y,l)$에 대해 다음이 성립한다.
$$ \begin{aligned} |x - z| &= |x - y + y - z| \\&< |x - y| + |y - z| \\&< |x - y| + \frac{\sqrt{2}}{2}l \end{aligned} $$

이 떄, $l = \sqrt{2}(r - |x - y|)$로 두면 다음이 성립한다.
$$ |x - z| < r $$

$\forall z \in S_{\R^n}(y,l)$에 대해 $|x - z| < r$임으로 다음이 성립한다.
$$ S_{\R^n}(y,l) \le B_{\R^n}(x,r) $$

$\forall y \in B_{\R^n}(x,r)$에서 $S_{\R^n}(y,l_y) \le B_{\R^n}(x,r)$를 만족하는 $l_y$이 존재함으로 다음이 성립한다.
$$ B_{\R^n}(x,r) = \bigcup_{\mathclap{y \in B_{\R^n}(x,r)}}  S_{\R^n}(y,l_y) \qed $$

### 명제4
Topological space $X,Y$와 함수 $f:X \rightarrow Y$가 있다고 하자.

$Y$의 basis를 $\mathcal{B}$라 할 때, 다음을 증명하여라.
$$ f \text{ is continuous} \iff \forall B \in \mathcal{B}, \quad \preimg(B) \text{ is open set of } X $$

**Proof**

[$\implies$]  
$\forall B \in \mathcal{B}$에 대해서, $B$가 $Y$의 open set임으로 conitnuous function의 정의에 의해 $\preimg(B)$는 $X$의 open set이다.$\qed$

[$\impliedby$]  
$V$가 $Y$의 open set이라고 하자.

Basis criterion에 의해 다음이 성립한다.
$$ \forall y \in V, \quad \exist B_y \in \mathcal{B} \quad s.t. \quad y \in B_y \subseteq V $$

따라서, 다음이 성립한다.
$$ \preimg(\Set{y}) \subseteq \preimg(B_y) \subseteq \preimg(V) $$

$\forall x \in \preimg(V)$에 대해, $\Set{x} = \preimg(\Set{y})$를 만족하는 $y \in V$가 존재함으로 다음이 성립한다.
$$ \forall x \in \preimg(V), \quad x \in \preimg(B_y) \subseteq \preimg(V) $$

이 떄, 전제에 의해서 $\preimg(B_y)$는 open set임으로 $\preimg(B_y) = \mathcal{N_x}$로 두면  다음이 성립한다.
$$ \forall x \in \preimg(V), \quad \exist \mathcal{N_x} \quad s.t. \quad \mathcal{N_x} \subseteq \preimg(V) $$

따라서, open set의 성질에 의해 다음이 성립한다.
$$ \preimg(V) \text{ is an open set of } X$$

그럼으로, continuous function의 정의에 의해 다음이 성립한다.
$$ f \text{ is an continuous function.} $$

### 명제5(Topology from a basis)
Set $X$와 $X$의 subset의 collection $\mathcal{B}$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ \begin{array}{} & \mathcal{B} \text{ is a basis for some topology on } X & \iff & \begin{aligned} 1.& \bigcup_{B \in \mathcal{B}} B = X \\ 2. & B_1, B_2 \in \mathcal{B} \enspace\land\enspace x \in B_1 \cap B_2 \\& \implies \exist B \in \mathcal{B} \quad s.t. \quad x \in B \subseteq B_1 \cap B_2 \end{aligned} \end{array} $$

**Proof**

[$\implies$]  
-[1]  
$X$는 $X$의 가장 큰 open set이기 때문에 basis의 성질에 의해 다음이 성립한다.
$$ \bigcup_{B \in \mathcal{B}} B = X \qed $$

-[2]  
$B_{1,2} \in \mathcal{B}$가 있다고 하자.

$B_{1,2}$는 $X$의 open set임으로 다음이 성립한다.
$$ B_1 \cap B_2 \text{ is an open set of } X $$

$B_1 \cap B_2$가 open set임으로 basis의 성질에 의해 다음이 성립한다.
$$ \exist\text{index set } I \st B_1 \cap B_2 = \bigcup_{i\in I} B_i $$

따라서, $\forall x \in B_1 \cap B_2$에 대해 다음이 성립한다.
$$ \exist j \in I \st x \in B_j \subseteq B_1 \cap B_2 \qed $$

[$\impliedby$]  
$\mathcal{T_X}$가 $\mathcal{B}$의 원소를 0을 포함한 임의의 개수를 뽑아 union한 집합의 collection이라고 하자.

보조명제5.1에 의해 $\mathcal{T_X}$는 $X$의 topology이다.

이 떄, $\mathcal{T}_X$의 정의에 의해 $\mathcal{B}$의 원소는 $\mathcal{T}_X$의 원소이며, $\mathcal{T}_X$의 원소는 $\mathcal{B}$의 어떤 원소들의 union이다.

따라서, basis의 정의에 의해 $\mathcal{B}$는 $\mathcal{T}_X$의 basis이다. $\qed$

#### 보조명제5.1
다음을 증명하여라.
$$ \mathcal{T}_X \text{ is topology of } X  $$

**Proof**

-[$\empty \in \mathcal{T}_X$]  
$\mathcal{B}$에서 0개의 원소를 뽑아 union하면 $\empty$가 됨으로 $\empty \in \mathcal{T}_X$이다.

-[$X \in \mathcal{T}_X$]  
$\mathcal{B}$의 모든 원소를 뽑아 union하면 1번 성질에 의해 $X$가 됨으로 $X \in \mathcal{T}_X$이다.

-[finite intersection]  
$U_i \in \mathcal T_X, \enspace i = 1, \cdots, n$이라 하자.

$\forall j \in \N$에 대해 $B_j \in \mathcal{B}$라 하고 임의의 index set을 $I$라 할 떄, $\mathcal{T_X}$의 정의에 의해 다음이 성립한다.
$$ \exist I_i \st U_i = \bigcup_{j \in I_i} B_j $$

그러면 다음이 성립한다.
$$ \forall x \in U_i, \quad \exist j \in \N \st x \in B_j \subseteq U_i $$

이 떄, 집합 $U$를 다음과 같이 정의하자.
$$ U = \bigcap_{i=1}^n U_i $$

그러면, 다음이 성립한다.
$$ \begin{aligned} x \in U \implies& x \in U_1 \land \cdots \land x \in U_n \\\implies& \exist j_1 \in \N \st x \in B_{j_1} \subseteq U_1 \land\cdots \\&\land \exist j_n \in \N \st x \in B_{j_n} \subseteq U_n \\\implies& x \in \bigcap_{k=1}^n B_{j_k} \subseteq U \end{aligned} $$

이 떄, $\mathcal{B}$의 2번 성질에 의해 다음이 성립한다.
$$  \exist B_x \in \mathcal{B} \quad s.t. \quad x \in B_x \subseteq \bigcap_{k=1}^n B_{j_k} \subseteq U $$

따라서, 다음이 성립한다.
$$ U = \bigcup_{x \in U}B_x $$

이 때, $\mathcal{T}_X$의 정의에 의해 $\mathcal{B}$의 원소들의 union은 $\mathcal{T}_X$의 원소임으로 다음이 성립한다.
$$ U \in \mathcal{T}_X \qed$$

-[infinite union]  
집합 $U$를 다음과 같이 정의하자.
$$ U = \bigcup_{\mathclap{U_i \in \mathcal{T}_X}} U_i $$

$U_i$는 $\mathcal{B}$의 어떤 원소들의 union임으로 $U$는 $\mathcal{B}$의 어떤 원소들의 union으로 귀결된다.

이 때, $\mathcal{T}_X$의 정의에 의해 $\mathcal{B}$의 원소들의 union을 포함함으로 다음이 성립한다.
$$ U \in \mathcal{T}_X $$

> Reference
> [Book] (Lee) Introduction to Topological Manifolds p.35

# Neighborhood Basis
Topological space $X$가 있다고 하자.

$x \in X$가 있을 때, 다음을 만족하는 $\mathcal{N_x}$의 collection $\mathcal{B_x}$를 $x$에서 $X$의 `neighborhood basis`라고 한다.
$$ \forall \mathcal{N_x} \in \Set{\mathcal{N_x}}, \quad \exist B\in\mathcal{B_x} \quad s.t. \quad B \subseteq \mathcal{N_x}  $$

### 참고
Neighborhood basis를 `local basis`라고도 부른다.

> Reference  
> [Proofwiki](https://proofwiki.org/wiki/Definition:Local_Basis)

# Nested Neighborhood Basis
Topological space $X$가 있다고 하자.

$x \in X$가 있을 때, 다음을 만족하는 sequence $\mathcal{B}(n)$을 $x$에서 `nested neighborhood basis`라고 한다.
$$ \mathcal{B_x}(i+1) \subseteq \mathcal{B_x}(i) \enspace\land\enspace \forall \mathcal{N_x}\in \Set{\mathcal{N_x}}, \quad \exist j \in \N \quad s.t. \quad \mathcal{B_x}(j)\subseteq \mathcal{N_x}$$

$$ \text{Where, } \mathcal{B_x}(i) = \mathcal{N_x^{i}} \in \Set{\mathcal{N_x}} $$










-