# Topology
집합 $X$가 있다고 하자.

$X$ 위의 `위상(topology)` $\mathcal T$란, 다음 성질을 만족하는 $X$의 부분집합의 집합이다.
1. $$ \empty, X \in \mathcal T $$
2. $$ s_i \in \mathcal T, \enspace i=1, \cdots,n \Rightarrow \bigcap_{i=1}^n s_i \in \mathcal T $$
3. $$ \bigcup_{s \in \mathcal T} s \in \mathcal T $$

### 명제1(Metric Topology)
Metric space $M$이 있다고 하자.

$M$의 모든 open set의 집합을 $\mathcal T$라 할 때, 다음을 증명하여라.
$$ \mathcal T \text{ is a topology on } M $$

**Proof**

Metric space의 open set의 성질에 의해 다음을 만족한다.
1. $$\empty, M \in \mathcal T$$
2. $$ s_i \in \mathcal T, \enspace i=1, \cdots,n \Rightarrow \bigcap_{i=1}^n s_i \in \mathcal T $$
3. $$ \bigcup_{s \in \mathcal T} s \in \mathcal T $$

따라서, $\mathcal T$는 $M$의 topology이다.

#### 참고
Metric sapce $M$의 모든 open set의 집합을 `metric topology`라고 한다.

특히, $M$이 Euclidean metric space일 경우 `Euclidean topology`라고 한다.

# Topological Space
집합 $X$와 $X$ 위의 위상 $\mathcal T$가 있을 때, $(X, \mathcal T)$를 `위상공간(topological space)`이라 한다.

### 참고
$x \in X$를 point라고 부른다.

### 명제1
Topological space $X$가 있다고 하자.

$Y$가 $X$의 open set일 떄, $\mathcal T_Y$를 다음과 같이 정의하자.
$$ \mathcal T_Y := \{ S \subseteq Y \enspace | \enspace S \subseteq Y \enspace\land\enspace S \in \mathcal T_X \} $$

이 떄, 다음을 증명하여라.
$$ \mathcal T_Y \text{ is a topology on } Y $$

**Proof**

[$\empty \in \mathcal T_Y$]  
$\empty$는 모든 집합의 부분집합임으로 자명하다.

[$Y \in \mathcal T_Y$]  
모든 집합은 자기 자신을 부분집합으로 갖음으로 자명하다. 

[finite intersection]  
$s_i \in \mathcal T_Y, \enspace i = 1, \cdots, n$이라 하자.

이 떄, 집합 $S$를 다음과 같이 정의하자.
$$ S = \bigcap_{i=1}^n s_i $$

$s_i \in \mathcal T_X, \enspace i = 1, \cdots, n$이고 $\mathcal T_X$는 topology임으로 다음이 성립한다.
$$ S \in \mathcal T_X $$

그리고 $\mathcal T_Y$의 정의에 의해 $s_i \subset Y, \enspace i = 1, \cdots, n$임으로 다음이 성립한다.
$$ S \subset Y $$

따라서 $\mathcal T_Y$의 정의에 의해 다음이 성립한다.
$$ S \in \mathcal T_Y$$

[infinite intersection]  
집합 $S$를 다음과 같이 정의하자.
$$ S = \bigcup_{s \in \mathcal T_Y} s $$

$s \in \mathcal T_Y \Rightarrow s \in T_X$이고 $\mathcal T_X$는 topology임으로 다음이 성립한다.
$$ S \in \mathcal T_X $$

그리고 $s \in \mathcal T_Y \Rightarrow s \subset Y$임으로 다음이 성립한다.
$$ S \subset Y $$

따라서 $\mathcal T_Y$의 정의에 의해 다음이 성립한다.
$$ S \in \mathcal T_Y $$

$\mathcal T_Y$가 topology의 조건을 전부 만족함으로, $\mathcal T_Y$는 topology이다. $\quad\tiny\blacksquare$

### 명제2
Topological space $X$가 있다고 하자.

subset $S \subseteq X$가 있을 떄, $\mathcal T_S$를 다음과 같이 정의하자.
$$ \mathcal T_S := \{ U \subseteq S \enspace | \enspace U = S \cap V, \enspace V \in \mathcal T_X \} $$

이 떄, 다음을 증명하여라.
$$ \mathcal T_S \text{ is a topology on } S $$

**Proof**

[$\empty \in \mathcal T_S$]  
$V = \empty$로 두면, $S \cap V = \empty$임으로 자명하다.

[$S \in \mathcal T_S$]  
$V = X$로 두면, $S \cap V = S$임으로 자명하다. 

[finite intersection]  
$U_i = (S \cap V_i) \in \mathcal T_S, \enspace i = 1, \cdots, n$이라 하자.

이 떄, 집합 $W$를 다음과 같이 정의하자.
$$ W := \bigcap_{i=1}^n s_i  $$

$V_i \in \mathcal T_X$이고 $\mathcal T_X$는 topology임으로 다음이 성립한다.
$$ \begin{aligned} W &= \bigcap_{i=1}^n s_i \\&= \bigcap_{i=1}^n (S \cap V_i) \\&= S \cap (\bigcap_{i=1}^n V_i) \\&= S \cap \hat V \in \mathcal T_S \end{aligned}  $$

[infinite intersection]  
집합 $W$를 다음과 같이 정의하자.
$$ W := \bigcup_{U \in \mathcal T_S} U $$

$V_i \in \mathcal T_X$이고 $\mathcal T_X$는 topology임으로 다음이 성립한다.
$$ \begin{aligned} W &= \bigcup_{i=1}^n s_i \\&= \bigcup_{i=1}^n (S \cap V_i) \\&= S \cap (\bigcup_{i=1}^n V_i) \\&= S \cap \hat V \in \mathcal T_S \end{aligned}  $$

$\mathcal T_S$가 topology의 조건을 전부 만족함으로, $\mathcal T_S$는 topology이다. $\quad\tiny\blacksquare$
