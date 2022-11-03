# Neighborhood
Topological space $X$가 있다고 하자.

$p \in X$일 때, $p$의 `neighborhood` $\mathcal N_p$는 $p$를 포함하는 $X$의 open set이다.
$$ p \in \mathcal N_p \in \mathcal T_X $$

더 일반적으로, $S \subseteq X$일 때, $S$의 neighborhood $\mathcal N_S$는 $S$를 포함하는 $X$의 open set이다.
$$ S \subseteq \mathcal N_S \in \mathcal T_X $$

### 참고1
distance의 개념 없이 정의된 open set을 사용함으로써, "nearness"의 개념 또한 distance의 개념 없이 정의할 수 있다.

### 참고2
현재 정의로는 $\mathcal N$은 항상 open set이지만,  open set을 포함하는 임의의 subset으로 정의를 확장할 수 있다.

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds p.20

### 명제1
topological space $X$가 있다고 하자.

$S \subseteq X$가 있을 때, 다음을 증명하여라.
$$ S \text { is an open set on } X \Leftrightarrow \forall x \in S, \enspace \exist \mathcal N_x \quad s.t. \quad \mathcal N_x \subseteq S $$

**Proof**

[$\Rightarrow$]  
$S$가 open set임으로 $\mathcal N_x = S$로 두면 항상 성립한다.

[$\Leftarrow$]  
$\forall x \in X$에 대해, $x \in \mathcal N_x$임으로 다음이 성립한다.
$$ S = \bigcup_{\forall x \in S} \mathcal N_x $$

이 때, 임의의 $x \in S$에 대해서 $\mathcal N_x \in \mathcal T_X$이고, Topology는 union에 닫혀 있음으로 다음이 성립한다.
$$ \bigcup_{\forall x \in S} \mathcal N_x \in \mathcal T_X \Rightarrow S \in \mathcal T_X $$

따라서, $S$는 $X$의 open set이다. $\quad {_\blacksquare}$

### 명제2
Topological space $X$가 있다고 하자.

$a,b \in X$라 할 때, 다음을 증명하여라.
$$ a,b \text{ may not have a disjoint neighborhood} $$

**Proof**

$X$가 다음과 같이 주어졌다고 하자.
$$ X = \{ 1,2,3 \}, \enspace \mathcal{T}_X = \{ \empty, \{ 1 \}, \{ 1,2 \}, \{ 1,2,3 \} \} $$

$1,2$의 경우 $2$를 포함하는 모든 open set이 $1$도 포함함으로 $1$과 $2$는 disjoint neighborhood를 갖을 수 없다. $\quad\tiny\blacksquare$

