# Closed set
Topological space $X$가 있다고 하자.

다음을 만족하는 $X$의 subset $U$를 $X$의 closed set이라고 한다.
$$ X-U \text{ is open set on } X $$

### 명제1
Topological space $X$가 있다고 하자.

다음을 증명하여라.
$$ \text{finite union of closed set is closed set} $$

**Proof**

$X$의 모든 closed set의 집합을 $U$라 하자.

집합 연산의 성질에 의해 다음이 성립한다.
$$ X - \bigcup_{i=1}^N U_i = \bigcap_{i=1}^N (X - U_i) $$

이 떄, $U_i$는 closed set임으로 $X - U_i$는 open set이 된다.

open set의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} & \bigcap_{i=1}^N (X - U_i) \text{ is an open set.} \\ \Rightarrow\enspace& X - \bigcup_{i=1}^N U_i \text{ is an open set.} \end{aligned}  $$

따라서 closed set의 정의에 의해 다음이 성립한다.
$$ \bigcup_{i=1}^N U_i \text{ is an closed set.} \quad\tiny\blacksquare $$

### 명제1
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, 다음을 증명하여라.
$$ \forall x \in X - A, \quad \exist\mathcal{N}_x \quad s.t. \quad \mathcal{N_x} \subseteq X - A \Rightarrow A \text{ is closed set on } X $$

**Proof**

$\forall x \in X - A$마다 $X-A$에 포함되는 $\mathcal{N_x}$가 존재함으로 $X - A$는 open set이다.

따라서 closed set의 정의에 의해 $A$는 $X$위의 closed set이다.

