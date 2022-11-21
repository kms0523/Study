# Interior
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, $X$에서 $U$의 interior $\Int(U)$는 다음과 같이 정의된다.
$$ \Int(U) := \bigcup\Set{A \subseteq X | A \subseteq U \land A \text{ is open set of } X} $$

### 명제1
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ \Int(U) \text{ is open set of } X $$
ㅋ
**Proof**

open set의 성질에 의해 다음이 성립한다.
$$ \text{infinite union of open set is open set} $$

따라서, open set의 union인 iterior은 open set이다. $\qed$

#### 참고
정의에 의해 iterior은 $U$에 포함된 가장 큰 $X$의 open set이다.

### 명제2
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ x \in \Int(U) \iff \exist\mathcal{N_x} \quad s.t. \quad \mathcal{N_x} \subseteq U $$

**Proof**

[$\implies$]
$\Int(U)$의 정의에 $x$를 포함하고 $U$에 subset인 $X$의 open set이 존재한다.

따라서, neighborhood의 정의에 의해 다음이 성립한다.
$$ \exist\mathcal{N_x} \subseteq U $$

[$\impliedby$]
$U$에 포함되는 $\mathcal{N_x}$가 존재하기 때문에 다음이 성립한다.
$$ \exist \text{open set } A \quad s.t. \quad x \in A \subseteq U $$

$\Int(U)$는 $U$에 포함된 모든 open set의 union임으로 다음이 성립한다.
$$ y \in A \implies y \in \Int(U) $$

따라서 다음이 성립한다.
$$ x \in \Int(U) \qed $$

#### 따름명제 2.1
다음을 증명하여라.
$$ x \notin \Int(U) \iff \nexists\mathcal{N_x} \quad s.t. \quad \mathcal{N_x} \subseteq U $$

### 명제3
Topological space $X$가 있다고 하자.

$X$의 open set $U$가 있을 때, 다음을 증명하여라.
$$ U = \Int(U) $$

**Proof**

Collection $C$를 다음과 같이 정의하자.
$$ C := \Set{A \subseteq X | A \subseteq U \land A \text{ is open set of } X} $$

$U$가 $X$의 open set이기 때문에 다음을 만족한다.
$$ U \in C$$

따라서, 다음이 성립한다.
$$ \begin{aligned} \Int(U) &= \bigcup_{A \in C} A \\&= U \qed \end{aligned} $$

### 명제4
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, 다음을 증명하여라.
$$ x \in X-U \implies x \notin \Int(U) $$

**Proof**

Interior의 정의에 의해, 다음이 성립한다.
$$ \Int(U) \subseteq U $$

따라서, 다음이 성립한다.
$$ \begin{aligned} x &\in X-U  \\& \in X-\Int(U) \\\implies x & \notin \Int(U) \qed \end{aligned} $$
