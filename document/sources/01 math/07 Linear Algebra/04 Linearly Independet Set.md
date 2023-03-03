# Linearly Independet Set
## 정의
Vector space $V/\F$와 $V$의 subset $S$가 있다고 하자.

$S$의 임의의 $n$개의 element를 $v_1, \cdots, v_n$이라고 하자.

이 떄, 다음을 항상 만족할 경우 $S$를 `선형 독립 집합(linearly independent set)`라고 한다.

$$ \sum_{k=1}^{n}a_k v_k = 0_V \implies \forall a_k=0_\F $$ 

### 참고
linear independent set이 되기 위해서는 항상 조건을 만족해야 됨으로 set에서 선택가능한 모든 조합이 linear independent해야 한다.


### 참고1
linearly independent set이 아닌 집합을 `선형 종속 집합(linear dependent set)`이라고 한다.

### 참고2
선형 종속 집합 $S \subseteq V$가 있다면 다음을 만족한다.

$$\exist a_i \in \F,v_i \in S \quad s.t. \quad \sum_{k=1}^{n}a_k v_k = 0_V \land \exist a_i  \neq 0_\F $$

이 때, $a_1 \neq 0_\F$이라고 가정하면 다음 관계식이 성립한다.
$$  v_1 = - \frac{1}{a_1}\sum_{k=2}^{n} a_k v_k $$

즉, $v_1$은 $S$에 속하는 다른 원소들의 선형결합으로 표현이 가능하다.

### 참고3
$v \in V- \{0_V\}$에 대해 $\beta=\{v\}$면 $\beta$는 선형 독립 집합이다.

### 명제
Vector space $V/\F$와 $V$의 linearly independent set $S$가 있다고 하자.

$v \in V - \span(S)$일 때, 다음을 증명하여라.

$$ S \cup \Set{v} \text{ is an linearly independent set} $$

**Proof**

$S$의 임의의 $n$개의 element를 $s_1,\cdots,s_n$이라 하자.

$a_1v + a_2s_1 + \cdots + a_{n+1}s_{n} = 0_V$일 때, 다음을 가정하자.

$$ a_1 \neq 0_\F $$

그러면 다음이 성립한다.

$$ v = -\left(\frac{a_2}{a_1}s_1 + \cdots + \frac{a_{n+1}}{a_{1}}s_n \right) $$

하지만 이는 $v \in V-\span(S)$라는 전제에 모순됨으로, proof by contradiction에 의해 다음이 성립한다

$$ a_1 = 0_\F $$

그러면 $S$가 linearly independent set임으로 다음이 성립한다.

$$ a_2 = \cdots = a_{n+1} = 0_\F $$

따라서, linearly independet set의 정의에 따라 다음이 성립한다.

$$ S \cup \Set{v} \text{ is an linearly independent set} \qed $$
