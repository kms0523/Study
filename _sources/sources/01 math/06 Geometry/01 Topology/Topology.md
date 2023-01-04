# Topology
## 정의
집합 $X$가 있다고 하자.

$X$ 위의 `위상(topology)` $\mathcal T$란, 다음 성질을 만족하는 $X$의 부분집합의 집합이다.
1. $$ \empty, X \in \mathcal T $$
2. $$ U_i \in \mathcal T, \enspace i=1, \cdots,n \Rightarrow \bigcap_{i=1}^n U_i \in \mathcal T $$
3. $$ \bigcup_{U \in \mathcal T} U \in \mathcal T $$

### 명제1(Metric Topology)
Metric space $M$이 있다고 하자.

$M$의 모든 open set의 집합을 $\mathcal T$라 할 때, 다음을 증명하여라.

$$ \mathcal T \text{ is a topology on } M $$

**Proof**

Metric space의 open set의 성질에 의해 다음을 만족한다.
1. $$\empty, M \in \mathcal T$$
2. $$ U_i \in \mathcal T, \enspace i=1, \cdots,n \Rightarrow \bigcap_{i=1}^n U_i \in \mathcal T $$
3. $$ \bigcup_{U \in \mathcal T} U \in \mathcal T $$

따라서, $\mathcal T$는 $M$의 topology이다.

#### 참고
Metric sapce $M$의 모든 open set의 집합을 `metric topology`라고 한다.

특히, $M$이 Euclidean metric space일 경우 `Euclidean topology`라고 한다.