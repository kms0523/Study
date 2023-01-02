# Power Set
## 정의
집합 $S$가 있다고 하자.

$S$의 `멱집합(power set)` $P(S)$는 다음과 같이 정의된 집합이다.

$$ P(S) := \Set{A | A \subseteq S} $$

즉, $P(S)$는 $S$의 모든 부분 집합들로 구성된 집합으로 집합들의 collection이다.

### 명제1
집합 $A$가 있다고 하자.

$\norm{A} = n$일 때, 다음을 증명하여라.

$$ \norm{P(A)} = 2^n$$

**proof**

$m \leq n$일 때, $m$개의 원소를 갖는 부분집합의 개수는 $_nC_m$이다.

따라서 모든 부분집합의 개수는

$$ \sum _{i=1}^n {_n C _i} = 2^n \qed $$
