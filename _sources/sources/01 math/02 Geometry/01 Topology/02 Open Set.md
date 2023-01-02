# Open Set

## 정의
Topological space $(X,\mathcal T)$가 있다고 하자.

다음을 만족하는 $S \subset X$를 $X$의 `open subset` 또는 `open set`이라고 한다.

$$ S \in \mathcal T $$

### 참고
Topology의 정의를 보면 알 수 있듯이, $\mathcal T$가 metric space에  open set 집합의 성질을 만족하도록 정의된 것을 알 수 있다. 따라서, $\mathcal T$는 open set의 집합이라 보고 $s \in \mathcal T$를 open set이라 정의 한다.

> Referece  
> {cite}`LeeTM` p.20

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

$\mathcal T_Y$가 topology의 조건을 전부 만족함으로, $\mathcal T_Y$는 topology이다. $\qed$