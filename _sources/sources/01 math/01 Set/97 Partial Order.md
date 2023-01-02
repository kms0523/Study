# Partial Order
## 정의
집합 $A$와 관계 $R \in A \times A$ 있을 떄, $A$의 `부분순서(partial order)` $\le(\sim_ R)$는 다음을 만족하는 $R$이다.

$$ \begin{array}{lcc} \text{반사관계(reflexive relation)} & x \in A \implies (x,x) \in R & x \le x \\ \text{반대칭관계(anti-symmetric relation)} & (x,y) \in R \land (y,x) \in R \implies x = y & x \le y \land y \le x \implies x=y \\ \text{추이관계(transitive relation)} & (x,y) \in R \land (y,z) \in R \implies (x,z) \in R & x \le y \land y \le z \implies x \le z \\ \end{array} $$