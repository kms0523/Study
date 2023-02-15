# Partial Order
## 정의
집합 $X$가 있다고 하자.

 관계 $R\in X \times X(\sim_R \equiv \le)$이 다음을 만족할 때, $\le$를 $X$의 `부분순서(partial order)`라고 한다.

$$ \begin{array}{cl} \forall x \in X, \quad x \le x &\text{ (reflexive)} \\ \forall x,y,z \in X, \quad x \le y \land y \le z \implies x \le z &\text{ (transitive)} \\ \forall x,y \in X, \quad  x\le y \land y \le x \implies x = y &\text{ (antisymmetric)} \end{array} $$

### 참고
reflexive 성질은 $X$의 모든 원소에 대해서 만족해야 한다.

하지만 transitive와 antisymmetric 성질은 비교 가능한 원소들간에만 만족하면 된다.