# Ring Action
Ring $R$의 semi-group $S$가 있다고 하자.

## Left Action
$R$의 $S$위의 왼쪽 작용(left action of $R$ on $S$) $\cdot$는 다음 조건들을 만족시키는 함수이다.

$$ \cdot : R \times S \rightarrow S \st \begin{array}{l} \forall r_1,r_2 \in R, \quad \forall s \in S, \quad  (r_1 +_R r_2)\cdot s = r_1\cdot s *_S r_2\cdot s \\ \forall r \in R, \quad \forall s_1,s_2 \in S, \quad  r\cdot (s_1 *_S s_2) = r\cdot s_1 *_S r \cdot s_2 \\  \forall r_1,r_2 \in R, \quad \forall s \in S, \quad (r_1 \cdot_R r_2)\cdot s = r_1\cdot (r_2 \cdot s) \\ \forall s \in S, \quad 1_R \cdot s = s \end{array} $$

## Right Action
$R$의 $S$위의 오른쪽 작용(right action of $R$ on $S$) $\cdot$는 다음 조건들을 만족시키는 함수이다.

$$ \cdot : S \times R \rightarrow S \st \begin{array}{l} \forall r_1,r_2 \in R, \quad \forall s \in S, \quad  s \cdot (r_1 +_R r_2) = s\cdot r_1 *_S s\cdot r_2 \\ \forall r \in R, \quad \forall s_1,s_2 \in S, \quad (s_1 *_S s_2) \cdot r = s_1 \cdot r *_S s_2 \cdot r \\ \forall r_1,r_2 \in R, \quad \forall s \in S, \quad s \cdot (r_1 \cdot_R r_2) = (s \cdot r_1) \cdot r_2 \\ \forall s \in S, \quad s \cdot 1_R = s \end{array} $$