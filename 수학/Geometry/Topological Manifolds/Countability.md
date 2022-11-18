# First Countable
Topological space $X$가 있다고 하자.

$X$가 다음을 만족할 때, $X$가 `first countable`하다고 한다.
$$ \forall x \in X, \quad \exist\text{ countable neighborhood basis} $$

### 명제1
다음을 증명하여라.
$$ \text{Every metric space is first countable.} $$

**Proof**

Metric space $M$이 있다고 하자.

$x \in M$이 있을 때, collection $\mathcal{B_x}$를 다음과 같이 정의하자.
$$ \mathcal{B_x} := \{ B_M(x,1/r) \enspace|\enspace r \in \N \} $$

Metric space에서 open ball은 open set임으로 $\mathcal{B_x}$의 원소는 $\mathcal{N_x}$이다.

Neighborhood의 정의에 의해 임의의 $\mathcal{N_x}$에 대해서 다음이 성립한다.
$$ \exist\epsilon \in \R^+ \quad s.t \quad B_M(x,\epsilon) \subseteq \mathcal{N_x} $$

자연수의 성질에 의해 다음이 성립한다.
$$ \exist r \quad s.t. \quad B_M(x,1/r) \subseteq B_M(x,\epsilon) $$

따라서, 다음이 성립한다.
$$ \exist B \in \mathcal{B_x} \quad s.t. \quad B \subseteq \mathcal{N_x} $$

Neighborhood basis의 정의에 의해 $\mathcal{B_x}$ neighborhood basis이며, 정의에 의해 countable하다.

따라서, $\forall x\in M$마다 countable neighborhood basis가 존재함으로 first countable의 정의에 의해 $M$은 first countable하다. $\quad\tiny\blacksquare$

> Reference  
> [Proofwiki](https://proofwiki.org/wiki/Metric_Space_is_First-Countable)

### 명제2
First countable space $X$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ \forall x \in X, \quad \exist\text{ a nested neighborhood basis at } x $$

**Proof**

$x \in X$가 있다고 하자.

$X$가 first countable space이기 때문에 $x$에서 $X$의 countable neighborhood basis를 $\mathcal{B_x} = \{ B_N|N\in\N \}$라 하자.

이 떄, $\mathcal{N_x}$의 sequence $s(n)$을 다음과 같이 정의하자.
$$ s(n) := \bigcap_{i=1}^n B_i $$

$s(n)$의 정의에 의해 다음이 성립한다.
$$ s(n+1) \subseteq s(n) $$

$\mathcal{B_x}$가 neighborhood basis이기 때문에 다음이 성립한다.
$$ \forall \mathcal{N_x}, \quad \exist i \in \N \quad s.t. \quad B_i \subseteq \mathcal{N_x} $$

따라서, 다음이 성립한다.
$$ \forall \mathcal{N_x}, \quad \exist i \in \N \quad s.t. \quad s(i) \subseteq \mathcal{N_x} $$

그래서 nested neighborhood basis의 정의에 의해 $s(n)$은 nested neighborhood basis이다. $\quad\tiny\blacksquare$

### 명제3
First countable space $X$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$  \exist\text{ sequence } s \text{ on } U \st \text{ converge to } x \iff x \in \bar{U} $$

**Proof**
[$\implies$]
convergence의 성질에 의해 성립한다.

[$\impliedby$]
$X$가 first countable space임으로 다음이 성립한다.
$$ \exist\text{ countable neighborhood basis }\mathcal{B_x} $$

$\mathcal{(B_x)_i} \in \mathcal{B_x}$가 있을 떄, open set의 성질에 의해 $N \in \N$에 대해, 다음이 성립한다.
$$ \bigcap_{i=1}^N \mathcal{(B_x)_i} \in \Set{\mathcal{N_x}}  $$

또한, $x \in \bar{U}$임으로 다음이 성립한다.
$$ \forall\mathcal{N_x}, \quad \mathcal{N_x} \cap U \neq \empty $$

따라서, $(\bigcap_{i=1}^N \mathcal{(B_x)_i}) \cap U \neq \empty$임으로 $U$위의 sequence $s(n)$을 다음과 같이 정의하자.
$$ s(n) := \text{one of a point in } \bigg(\bigcap_{i=1}^n \mathcal{(B_x)_i}\bigg) \cap U$$

이 떄, $\mathcal{B_x}$가 neighborhood basis임으로 다음을 만족한다.
$$ \forall\mathcal{N_x}, \quad \exist j \in \N \st \mathcal{(B_x)_j} \subseteq \mathcal{N_x} $$

따라서, 임의의 $\mathcal{N_x}$가 주어졌을 떄, $j \le n$으로 두면 다음이 성립한다
$$ \begin{aligned} s(n) &\in \bigg(\bigcap_{i=1}^n \mathcal{(B_x)_i}\bigg) \cap U \\& \in \mathcal{(B_x)_j} \\& \in \mathcal{N_x} \end{aligned}  $$

그럼으로, convergence의 정의에 의해 $s(n)$은 $x$에 수렴한다.$\qed$

> Reference
> [proofwiki](https://proofwiki.org/wiki/Sequence_Lemma)


