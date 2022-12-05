# Hausdorff Space
Topological Space $X$가 있다고 하자.

다음을 만족하는 $X$를 `Hausdorff space`라고 한다.
$$ \text{disjoint } x,y \in X \implies \exist \text{ disjoint } \mathcal{N_x},\mathcal N_y $$

### 명제1
다음을 증명하여라.
$$ \text{Every metric spaces are Hausdorff space} $$

**Proof**

Metric space $M$이 있다고 하자.

Metric space의 neighborhood의 성질에 의해 다음이 성립한다.
$$ \text{disjoint } x,y \in M \implies \exist \text{ disjoint } \mathcal{N_x},\mathcal N_y $$

따라서, $M$은 Hausdorff space이다. $\qed$

### 명제2
다음을 증명하여라.
$$ \text{Every subspace of a Hausdorff space is a Hausdorff space} $$

**Proof**

$X$가 Hausdroff space라고 하자.

$U$가 $X$의 subspace이고 $x,y \in U$라 하면, $X$가 Hausdroff space이기 때문에 다음이 성립한다.
$$ \exist \text{ disjoint } \mathcal{N_x}, \mathcal N_y \text{ on } X $$

$U$가 $X$의 subspace임으로 다음이 성립한다.
$$ \mathcal{N_x} \cap U \text{ and } \mathcal N_y \cap U \text{ are open set and disjoint in } U $$

그럼으로 다음이 성립한다.
$$ \exist \text{ disjoint } \mathcal N^U_x, \mathcal N^U_y \text{ on } U $$

따라서 Hausdorff space의 정의에 의해 $U$는 Hausdorff space이다.$\qed$

> Reference  
> [Book] (Lee) Introduction to Topological Manifolds p.32  
> [Stackexchange - math](https://math.stackexchange.com/questions/3442811/topology-hausdorff-space-and-the-subspace-topology)  

### 명제3
Topological space $X$가 있다고 하자.

$x \in X$에 대해 continuous function $f_x : X \rightarrow \R$이 존재해서 $f(x) = 0$일 때, 다음을 증명하여라.
$$ X \text{ is a Hausdorff space} $$

**Proof**

$x,y \in X$라고 하자.

전제에 의해 $f_x$는 bijective임으로 다음이 성립한다.
$$ f_x(y) = r \neq 0 $$

이 때, $\R$은 Hausdorff space임으로 다음이 성립한다.
$$ \exist \text{ disjoint } \mathcal N_0, \mathcal N_r \text{ on } \R $$

$f_x$가 continuous function임으로 다음이 성립한다.
$$ \preimg(\mathcal N_0) \text{ and } \preimg(\mathcal N_r) \text{ are open set on } X $$

또한 $0 \in \mathcal{N_0}$임으로 $x \in \preimg(\mathcal{N_0})$이고, $r \in \mathcal{N_r}$임으로 $y \in \preimg(\mathcal{N_r})$이다.

이 때, 다음이 성립한다.
$$ \begin{aligned} \preimg(\mathcal N_0) \cap \preimg(\mathcal N_r) &=  \preimg(\mathcal N_0 \cap \mathcal N_r) \\&= \preimg(\empty) \\&= \empty \end{aligned} $$

$\mathcal{N_x} = \preimg(\mathcal N_0), \mathcal N_y = \preimg(\mathcal N_r)$라고 하면 다음이 성립한다.
$$ \exist \text{ disjoint } \mathcal{N_x}, \mathcal N_y \text{ on } X $$

따라서, $X$는 Hausdorff space이다.$\qed$

> Reference  
> [Stackexchnage - Math](https://math.stackexchange.com/questions/678138/let-x-be-a-topological-space-suppose-forall-p-in-x-exists-f-in-cx?rq=1)

### 명제4
$X$가 Hausdorff space라고 하자.

이 떄, 다음을 증명하여라.
$$ \text{one point set on } X \text{ is closed} $$

**Proof**

$x \in X$라 하자.

$X$가 Hausdorff space이기 때문에 $\forall y \in X - \Set{x}$에 대해 다음이 성립한다.
$$ \exist \text{ disjoint } \mathcal{N_x},\mathcal{N_y} \text{ on } X $$

$\mathcal{N_{x,y}}$가 disjoint neighborhood임으로, $\mathcal{N_y} \subseteq X-\Set{x}$이다.

따라서, open set의 성질에 의해 다음이 성립한다.
$$ \forall y \in X-\Set{x}, \quad \exist \mathcal{N_y} \st \mathcal{N_y} \subseteq X-\Set{x} \iff X-\Set{x} \text{ is an open set} $$

따라서, closed set의 정의에 의해 $\Set{x}$는 $X$의 closed set이다. $\qed$

### 명제5
$X$가 Hausdorff space라고 하자.

이 떄, 다음을 증명하여라.
$$ \text{Every finite subset of } X \text{ is closed} $$

**Proof**

$x \in X$라 하자.

명제4에 의해 $\{x\}$는 closed set이다.

closed set의 성질에 의해 다음이 성립한다.
$$ \text{finite union of closed sets are closed.} $$

이 떄, $X$의 finite subset은 단일 원소 집합의 finite union으로 구성되어 있음으로 closed이다. $\qed$

### 명제6
Hausdorff space $X$가 있다고 하자. 

$X$위의 sequence $s$가 있을 때, 다음을 증명하여라.
$$ s \text{ can converge to at most one point in } X $$

**Proof**

$x,y \in X$가 있고 $\lim_{i\rightarrow\infty}s(i) = x$ 이고 $ \lim_{i\rightarrow\infty}s(i) = y$라고 하자. 

이 때, 다음을 가정하자.
$$ x \neq y $$

수렴에 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \forall \mathcal{N_x} \in \Set{\mathcal{N_x}}, \quad  \exist N_x \st N_x \le n \implies s(n) \in \mathcal{N_x} \\ \forall \mathcal{N_y} \in \Set{\mathcal{N_y}}, \quad  \exist N_y \st N_y \le n \implies s(n) \in \mathcal{N_y} \end{aligned} $$

$N = \max(N_x,N_y)$라 하면 모든 $\mathcal{N_x},\mathcal N_y$에 대해 $N \le n$이면 다음이 성립한다.
$$ s(n) \in \mathcal{N_x} \cap \mathcal N_y $$

하지만 이는 $X$가 Hausdorff space임으로 $ \exist \text{ disjoint } \mathcal{N_x},\mathcal{N_y} \text{ on } X $라는 사실에 모순된다.

따라서,proof by contradiction에 의해 $x=y$이다. $\qed$

### 명제7
Finite set $X$가 있을 떄, 다음을 증명하여라.
$$ \text{Hausdorff topology on } X \text{ is a discrete topology} $$

**Proof**

$X$가 Hausdorff space라고 하자.

$X$의 subset $U$에 대해 $|X - U| = N$이고 $x_i \in X - U$라 하자.

$X$가 finite set이기 때문에 다음이 성립한다.
$$ U = X - \bigcup_{i=1}^N \{x_i\} $$

$X$가 Hausdorff space임으로 명제4에 의해 $\{x_i\}$는 $X$의 closed set이고 closed set의 성질에 의해 다음이 성립한다.
$$ \bigcup_{i=1}^N \{x_i\} \text{ is closed set on } X $$

따라서, closed set의 성질에 의해 $U$는 $X$의 open set이다.

임의의 subset $U$가 open set임으로 $X$는 discrete topology를 갖는다. $\qed$



> Reference  
> [Stackexchange math](https://math.stackexchange.com/questions/1567152/a-finite-hausdorff-space-is-discrete)
