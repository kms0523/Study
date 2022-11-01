# Open Set
Topological space $(X,\mathcal T)$가 있다고 하자.

다음을 만족하는 $S \subset X$를 $X$의 `open subset` 또는 `open set`이라고 한다.
$$ S \in \mathcal T $$

### 참고
Topology의 정의를 보면 알 수 있듯이, $\mathcal T$가  open set 집합의 성질을 만족하도록 정의된 것을 알 수 있다. 따라서, $\mathcal T$는 open set의 집합이라 보고 $s \in \mathcal T$를 open set이라 정의 한다.

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds p.20

### 명제1
Topological space $X$가 있다고 하자.

$X$의 open set $U,V$가 있을 떄, 다음을 증명하여라.
$$ U \cap V \text{ is an open set on } U,V $$

**Proof**

Topology의 정의에 의해 다음이 성립한다.
$$ U \cap V \text{ is an open set on X} $$

Topological space의 성질에 의해 다음이 성립한다.
$$ \text{Every open set of X in } U,V \text{ is a topology on } U,V $$

따라서, $U \cap V$는 $X$의 open set이면서 동시에 $U,V$에 포함됨으로 다음이 성립한다.
$$ U \cap V \text{ is an open set on } U,V \quad\tiny\blacksquare $$

# Closed set
Topological space $X$가 있다고 하자.

다음을 만족하는 $U \subseteq X$를 $X$의 closed subset 또는 closed set이라고 한다.
$$ X-U \text{ is an open set} $$

### 명제1
Topological space $X$가 있다고 하자.

$a \in X$에 대해 다음을 증명하여라.
$$ \{a\} \text{ may not be a closed set} $$

**Proof**

$X$가 다음과 같이 주어졌다고 하자.
$$ X = \{ 1,2,3 \}, \enspace \mathcal{T}_X = \{ \empty, \{ 1 \}, \{ 1,2 \}, \{ 1,2,3 \} \} $$

$\{1\}$의 경우 $\{2,3\}$이 open set이 아님으로 closed set이 아니다.$\quad\tiny\blacksquare$