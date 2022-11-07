# Basis
Topological space $X$가 있다고 하자.

$X$의 subset collection $\mathcal{B}$가 다음을 만족할 때, $\mathcal{B}$를 $X$의 topology의 basis라고 한다.
1. Every element of $\mathcal{B}$ is an open subset of $X$
2. Every open subset of $X$ is the union of some collection of elements of $\mathcal{B}$

### 참고
$X$의 open set $\empty$는 $\mathcal{B}$의 empty collection의 union이다.

### 명제1(Basis criterion)
$X$가 topological space이고 $\mathcal{B}$가 $X$의 basis라고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ U \text{ is open } \iff \forall x \in U, \quad  \exist B \in \mathcal{B} \quad s.t. \quad x \in B \subseteq U $$

**Proof**

[$\implies$]  
$U$가 open set임으로 어떤 $B_i \in \mathcal{B}, \enspace(i = 1,\cdots,k)$의 성질에 의해 다음이 성립한다.
$$ U = \bigcup_{i=1}^k B_i $$

따라서 $\forall x \in U$에 대해 다음이 성립한다.
$$ \exist j \in [1,k] \quad s.t. \quad x \in B_j \subseteq U $$

[$\impliedby$]  
가정에 의해, $\forall x \in U$에 대해 다음이 성립한다.
$$ \exist B_x \quad s.t. \quad x \in B_x \subseteq U $$

따라서 다음이 성립한다.
$$ U = \bigcup_{x \in U}B_x $$

이 떄, $B_x$는 $X$의 open set임으로 open set의 성질에 의해 다음이 성립한다.
$$ U \text{ is an open set of } X \quad\tiny\blacksquare $$

### 명제2
Metric topology $M$이 있다고 하자.

이 떄, 다음을 증명하여라.
$$ \text{Collection of open ball in } M \text{ is a basis for } M $$

**Proof**

Open ball의 성질에 의해 다음이 성립한다.
1. $$ \text{open ball in } M \text{ is an open set of } M $$
2. $$ \text{Every open set of } M \text{ is an union of collection of some open balls } $$

따라서, basis의 정의를 만족함으로 $M$의 collection of open ball은 $M$의 basis이다. $\quad\tiny\blacksquare$