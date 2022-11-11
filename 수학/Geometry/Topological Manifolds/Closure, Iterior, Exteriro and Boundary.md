# Closure
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, $X$에서 $U$의 closure $\bar{U}$는 다음과 같이 정의된다.
$$ \bar{U} := \bigcap\Set{A \subseteq X | U \subseteq A \land A\text{ is closed set of } X} $$

### 명제1
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ \bar{U} \text{ is closed set of } X $$

**Proof**

Closed set의 성질에 의해 다음이 성립한다.
$$ \text{infinite intersection of closed set is closed set} $$

따라서, closed set의 intersection인 closure은 closed set이다. $\quad\tiny\blacksquare$

#### 참고
정의에 의해 closure은 $U$를 포함한 가장 작은 $X$의 closed set이다.

# Interior
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, $X$에서 $U$의 interior $\text{int}(U)$는 다음과 같이 정의된다.
$$ \text{int}(U) := \bigcup\Set{A \subseteq X | A \subseteq U \land A \text{ is open set of } X} $$

### 명제1
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ \text{int}(U) \text{ is open set of } X $$

**Proof**

open set의 성질에 의해 다음이 성립한다.
$$ \text{infinite union of open set is open set} $$

따라서, open set의 union인 iterior은 open set이다. $\quad\tiny\blacksquare$

#### 참고
정의에 의해 iterior은 $U$에 포함된 가장 큰 $X$의 open set이다.

### 명제2
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ x \in \text{int}(U) \iff \exist\mathcal{N_x} \subseteq U $$

**Proof**

[$\implies$]
$\text{int}(U)$의 정의에 $x$를 포함하고 $U$에 subset인 $X$의 open set이 존재한다.

따라서, neighborhood의 정의에 의해 다음이 성립한다.
$$ \exist\mathcal{N_x} \subseteq U $$

[$\impliedby$]
$U$에 포함되는 $\mathcal{N_x}$가 존재하기 때문에 다음이 성립한다.
$$ \exist \text{open set } A \quad s.t. \quad x \in A \subseteq U $$

$\text{int}(U)$는 $U$에 포함된 모든 open set의 union임으로 다음이 성립한다.
$$ y \in A \implies y \in \text{int}(U) $$

따라서 다음이 성립한다.
$$ x \in \text{int}(U) \quad\tiny\blacksquare $$

### 명제3
Topological space $X$가 있다고 하자.

$X$의 open set $U$가 있을 때, 다음을 증명하여라.
$$ U = \text{int}(U) $$

**Proof**

Collection $C$를 다음과 같이 정의하자.
$$ C := \Set{A \subseteq X | A \subseteq U \land A \text{ is open set of } X} $$

$U$가 $X$의 open set이기 때문에 다음을 만족한다.
$$ U \in C$$

따라서, 다음이 성립한다.
$$ \begin{aligned} \text{int}(U) &= \bigcup_{A \in C} A \\&= U \quad\tiny\blacksquare \end{aligned} $$

# Exteriror
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, $X$에서 $U$의 `exterior` $\text{ext}(U)$는 다음과 같이 정의된다.
$$ \text{ext}(U) := X - \bar{U} $$

### 명제1
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ \text{ext}(U) \text{ is an open set of } X $$

**Proof**

closure의 성질에 의해 $\bar{U}$가 $X$의 closed set이다.

따라서, closed set의 정의에 의해 $X-\bar{U}$는 $X$의 open set임으로 다음이 성립한다. 
$$ \text{ext}(U) \text{ is an open set of } X \quad\tiny\blacksquare $$


### 명제2
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ x \in \text{ext}(U) \iff \exist\mathcal{N_x} \subseteq X -U $$

**Proof**

[$\implies$]
명제1에 의해 $\text{ext}(U)$는 open set임으로 다음이 성립한다.
$$ \text{int}(\text{ext}(U)) = \text{ext}(U) $$

따라서, interior의 성질에 의해 다음이 성립한다.
$$ x \in \text{ext}(U) \implies \exist\mathcal{N_x} \subseteq \text{ext}(U) $$

$\text{ext}(U)$의 정의와 $U \subseteq \bar{U}$임으로 다음이 성립한다.
$$ \begin{aligned} x \in \text{ext}(U) &\implies \exist\mathcal{N_x} \subseteq \text{ext}(U) \\&\implies \exist\mathcal{N_x} \subseteq X - \bar{U} \\&\implies \exist\mathcal{N_x} \subseteq X - U \end{aligned} $$

[$\impliedby$]
$x \in X-U$가 있다고 하자.

$X - U$에 포함되는 $\mathcal{N_x}$가 존재하기 때문에 다음이 성립한다.
$$ \exist \text{open set } A \quad s.t. \quad x \in A \subseteq X-U $$

Q. $A \subseteq X-U \implies A \subseteq X-\bar{U}$?

$U \subseteq \bar{U}$임으로 다음이 성립한다.
$$ A \subseteq X-\bar{U} $$





# Boundary
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, $X$에서 $U$의 `boundary` $\partial U$는 다음과 같이 정의된다.
$$ \partial U := X - (\text{int}(U) \cup \text{ext}(U)) $$



