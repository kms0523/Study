# Open Set
Topological space $(X,\mathcal T)$가 있다고 하자.

다음을 만족하는 $S \subset X$를 $X$의 `open subset` 또는 `open set`이라고 한다.
$$ S \in \mathcal T $$

### 참고
Topology의 정의를 보면 알 수 있듯이, $\mathcal T$가 metric space에  open set 집합의 성질을 만족하도록 정의된 것을 알 수 있다. 따라서, $\mathcal T$는 open set의 집합이라 보고 $s \in \mathcal T$를 open set이라 정의 한다.

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds p.20

### 명제1
Topological space $X$가 있다고 하자.

$X$의 open set $U,V$가 있을 떄, 다음을 증명하여라.
$$ U \cap V \text{ is an open set on } U,V $$

**Proof**

Topology의 정의에 의해 다음이 성립한다.
$$ U \cap V \text{ is an open set on X} $$

$U,V$를 각 각 $X$의 subspace라고 하면 다음이 성립한다.
$$ \text{Every open set of X in } U,V \text{ is an open set on } U,V $$

이 떄, $U \cap V$는 $X$의 open set이면서 동시에 $U,V$에 포함됨으로 다음이 성립한다.
$$ U \cap V \text{ is an open set on } U,V \quad\tiny\blacksquare $$