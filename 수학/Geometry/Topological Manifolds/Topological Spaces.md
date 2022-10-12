# Topology
집합 $X$가 있다고 하자.

$X$ 위의 `위상(topology)` $\mathcal T$란, 다음 성질을 만족하는 $X$의 부분집합의 집합이다.
1. $$ \empty, X \in \mathcal T $$
2. $$ s_i \in \mathcal T, \enspace i=1, \cdots,n \Rightarrow \bigcap_{i=1}^n s_i \in \mathcal T $$
3. $$ \bigcup_{s \in \mathcal T} s \in \mathcal T $$

# Topological Spaces
집합 $X$와 $X$ 위의 위상 $\mathcal T$가 있을 때, $(X, \mathcal T)$를 `위상공간(topological space)`이라 한다.

### 참고
$x \in X$를 point라고 부른다.

### 명제
Topological space $X$가 있다고 하자.

$Y \in \mathcal T_X$이고 $\mathcal T_Y$를 다음과 같이 정의하자.
$$ \mathcal T_Y := \{ S \in \mathcal T_X \enspace | \enspace S \subset Y \} $$

이 떄, 다음을 증명하여라.
$$ (Y, \mathcal T_Y) \text{ is a topological space} $$

**Proof**

[$\empty \in \mathcal T_Y$]  
$\empty$는 모든 집합의 부분집합임으로 자명하다.

[$Y \in \mathcal T_Y$]  
모든 집합은 자기 자신을 부분집합으로 갖음으로 자명하다.

[finite intersection]  
$s_i \in \mathcal T_Y, \enspace i = 1, \cdots, n$이라 하자.

이 떄, 집합 $X$를 다음과 같이 정의하자.
$$ X = \bigcap_{i=1}^n s_i $$

$s_i \in \mathcal T_X, \enspace i = 1, \cdots, n$임으로 $\mathcal T_X$의 정의에 의해 다음이 성립한다.
$$ X \in \mathcal T_X $$

그리고 $s_i \subset Y, \enspace i = 1, \cdots, n$임으로 다음이 성립한다.
$$ X \subset Y $$

따라서 다음이 성립한다.
$$ X \in \mathcal T_Y  $$

[union]  
집합 $X$를 다음과 같이 정의하자.
$$ X = \bigcup_{s \in \mathcal T_Y} s $$

$s \in \mathcal T_y \Rightarrow s \in T_x$임으로 $\mathcal T_X$의 정의에 의해 다음이 성립한다.
$$ X \in \mathcal T_X $$

그리고 $s \in \mathcal T_y \Rightarrow s \subset Y$임으로 다음이 성립한다.
$$ X \subset Y $$

따라서 다음이 성립한다.
$$ X \in \mathcal T_Y  $$
