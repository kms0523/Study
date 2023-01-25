# Partial Order
## 정의
집합 $A$와 관계 $R \in A \times A$ 있을 떄, $A$의 `부분순서(partial order)` $\le(\sim_ R)$는 다음을 만족하는 $R$이다.

$$ \begin{array}{cl} \forall x \in A, \quad x \le x &\text{ (reflexive)} \\ x \le y \land y \le z \implies x \le z &\text{ (transitive)} \\  x\le y \land y \le x \implies x = y &\text{ (antisymmetric)} \end{array} $$

### 참고
reflexive 성질은 $A$의 모든 원소에 대해서 만족해야 한다.

하지만 transitive와 antisymmetric 성질은 비교 가능한 원소들간에만 만족하면 된다.