# Linearly Independet Set
## 정의
Vector space $V/\F$와 $V$의 finite subset $S$가 있다고 하자.

$S$가 다음을 만족할경우 `선형 독립 집합(linearly independent set)`라고 한다.

$i=1,\cdots,n$에 대해, $a_i \in F, v_i \in S$ 일 때

$$ \sum_{k=1}^{n}a_k v_k = 0_V \implies \forall a_k=0_\F $$ 

$0_V \equiv e_{(V,+)}, 0_\F \equiv e_{(\F,+)}$이다.

### 참고1
linearly independent set이 아닌 집합을 `선형 종속 집합(linear dependent set)`이라고 한다.

### 참고2
선형 종속 집합 $S = \{ v_1, \cdots , v_n \} \subseteq V$가 있다면 다음을 만족한다.

$$\exist \{ a_1, \cdots a_n \} \quad s.t. \quad \sum_{k=1}^{n}a_k v_k = 0_V \land \{ a_1, \cdots a_n \}  \neq \{ 0_F, \cdots, 0_F \} $$

이 때, $a_1 \neq 0_F$이라고 가정하면 다음 관계식이 성립한다.
$$  v_1 = - a_1^{-1}\sum_{k=2}^{n} a_k v_k $$

즉, $v_1$은 $S$에 속하는 다른 원소들의 선형결합으로 표현이 가능하다.

### 참고3
$v \in V- \{0_V\}$에 대해 $\beta=\{v\}$면 $\beta$는 선형 독립 집합이다.