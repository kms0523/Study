# Closure
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, $X$에서 $U$의 closure $\bar{U}$는 다음과 같이 정의된다.
$$ \bar{U} := \bigcap\Set{A \subseteq X | U \subseteq A \land A\text{ is a closed set of } X} $$

### 명제1
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ \bar{U} \text{ is a closed set of } X $$

**Proof**

Closed set의 성질에 의해 다음이 성립한다.
$$ \text{infinite intersection of closed set is closed set} $$

따라서, closed set의 intersection인 closure은 closed set이다. $\qed$

#### 참고
정의에 의해 closure은 $U$를 포함한 가장 작은 $X$의 closed set이다.

### 명제2
Topological space $X$와 $X$의 subset $U$가 있다고 하자.

$A$가 $X$의 open set일 떄, 다음을 증명하여라.
$$ A \subseteq X - U \iff A  \subseteq X - \bar{U} $$

**Proof**

[$\implies$]
$A \subseteq X-U$일 떄, $A \nsubseteq X - \bar{U}$라 가정하자.

그러면 다음이 성립한다.
$$ \exist x \in A \quad s.t. \quad x \notin X - \bar{U} $$

Closure의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} X - \bar{U} &= X - \bigcap\Set{B \subseteq X | U \subseteq B \land B \text{is closed set of } X} \\&= X \cap \bigcap\Set{B \subseteq X | U \subseteq B \land B \text{ is closed set of } X}^C \\&= X \cap \bigcup\Set{B \subseteq X | U \nsubseteq B \land B \text{ is open set of } X} \end{aligned} $$

따라서, $x \notin X-\bar{U}$면 다음이 성립한다.
$$ x \in U \lor (x \in X-U \land x \in \text{closed set of } X) $$

하지만 가정에 의해, $x$는 $X-U$에 속한 open set의 원소임으로 모순이 발생한다.

그럼으로 Proof by contradiction에 의해, 다음이 성립한다.
$$A \subseteq X-U \implies A \subseteq X - \bar{U}$$

[$\impliedby$]
$U \subseteq \bar{U}$임으로, 다음이 성립한다.
$$ \bar{U}^C \subseteq U^C $$

따라서, 다음이 성립한다.
$$ \begin{aligned} X - \bar{U} &= X \cap \bar{U}^C \\&\subseteq X \cap U^C \\&\subseteq X - U \end{aligned} $$

그럼으로, 다음이 성립한다.
$$ A \subseteq X-\bar{U} \implies A \subseteq X-U \qed $$

### 명제3
Topological space $X$가 있다고 하자.

$x \in X$와 $X$의 subset을 $U$가 있을 떄, 다음을 증명하여라.
$$ x \in \bar{U} \iff \forall \mathcal{N_x}, \quad \mathcal{N_x} \cap U \neq \empty $$

**Proof**

[$\implies$]
 다음을 가정하자.
$$ \exist \mathcal{N_x} \quad s.t. \quad \mathcal{N_x} \cap U = \empty $$

위의 가정를 만족하는 $\mathcal{N_x}$에 대해 다음이 성립한다.
$$ U \subseteq X-\mathcal{N_x} \land X - \mathcal{N_x} \text{ is closed set of }X $$

전제에 의해 $x \in \bar{U}$임으로, Closure 정의에 의해 다음이 성립한다.
$$ x \in X - \mathcal{N_x} $$

그러나, neighborhood의 정의에 의해 $x \in \mathcal{N_x}$임으로 모순이 발생한다.

따라서, proof by contradiction에 의해 다음이 성립한다.
$$ \forall \mathcal{N_x}, \quad \mathcal{N_x} \cap U \neq \empty \qed $$

[$\impliedby$]
Collection $C$를 다음과 같이 정의하자.
$$ C := \Set{A \subseteq X | U \subseteq A \land A \text{ is a closed set of } X} $$

이 떄, 다음을 가정하자.
$$ \exist A \in C \quad s.t. \quad x \notin A  $$

$A$가 closed set임으로 다음이 성립한다.
$$\begin{aligned} &X-A \text{ is an open set of } X \land x \in X-A \\\implies& X-A \in \Set{\mathcal{N_x}} \end{aligned} $$

전제에 의해 다음이 성립한다.
$$ (X-A) \cap U \neq \empty $$

이는 $U \subseteq A$라는 사실과 모순됨으로, proof by contradiction에 의해 다음이 성립한다.
$$ \forall A \in C, \quad  x \in A $$

따라서, closure의 정의에 의해 다음이 성립한다.
$$ x \in \bar{U} \qed $$

> Reference
> [northeastern.edu](https://web.northeastern.edu/suciu/MATH4565/MATH4565-fa21-handout2.pdf)

### 명제4
Topological space $X$가 있다고 하자.

$X$의 closed set $U$가 있을 때, 다음을 증명하여라.
$$ \bar{U} = U $$

**Proof**

Collection $C$를 다음과 같이 정의하자.
$$ C := \Set{A \subseteq X | U \subseteq A \land A \text{ is a closed set of } X} $$

$U$가 $X$의 closed set이기 때문에 다음을 만족한다.
$$ \forall S \in C, \quad U \subseteq S$$

따라서, 다음이 성립한다.
$$ \begin{aligned} \Ext(U) &= \bigcap_{A \in C} A \\&= U \qed \end{aligned} $$
