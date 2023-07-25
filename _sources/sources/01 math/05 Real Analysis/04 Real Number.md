# Real Number
## 정의
다음과 같이 정의된 집합 $\R$을 `실수(real number)`라고 한다.

$$ \R := \text{ordered complete field which contains } \Q \text{ as a subfield} $$

> Reference  
> {cite}`abbott` p.14

### 참고(axiom of completeness)
$\R$이 complete field임으로 다음이 성립한다.

$$ \text{Every nonempty subset of } \R \text{ that is bounded above has a supremum} $$

이 떄, 의문점은 이러한 $\R$이 실제로 존재하냐? 라는 점이고 이러한 $\R$의 존재성을 axiom으로써 받아들인다. 이를 `axiom of completeness`라고 한다.

### 명제1
$\R$의 subset $X$가 있다고 하자.

$x$가 $X$의 upper bound 일 때, 다음을 증명하여라.

$$ x = \sup(X) \iff \forall \epsilon \in \R^+, \quad \exist y \in X \st x-\epsilon < y $$

**Proof**

[$\implies$]  
다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad x-\epsilon < x $$

따라서, supremum의 정의에 의해 다음이 성립한다.

$$ x-\epsilon \text{ is not an upper bound of } X $$

그럼으로 다음이 성립한다.

$$ \exist y \in X \st x-\epsilon < y \qed $$

[$\impliedby$]  
다음을 가정하자.

$$ x \neq \sup(X) $$

그러면 다음이 성립한다.

$$ \exist \text{upper bound } y \st y < x $$

$\epsilon_0 \in \R$을 다음과 같이 정의하자.

$$ \epsilon_0 = x-y \in \R^+ $$

이 떄, 전제에 의해 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad x - \epsilon \text{ is not an upper bound of } X $$

따라서, 다음이 성립한다.

$$ x - \epsilon_0 = y \text{ is not an upper bound of } X $$

이는 모순임으로 proof by contradiction에 의해 다음이 성립한다.

$$ x = \sup(X) \qed $$

> Reference  
> {cite}`abbott` Lemma 1.3.7.

### 명제2(Nested Interval Property)
$\R$의 subset인 closed interval $I_n := [a_n, b_n]$이 다음을 만족한다고 하자.

$$ \forall n \in \N, \quad  I_{n+1} \subseteq I_n  $$

이 때, 다음을 증명하여라.

$$ \bigcap_{n=1}^{\infty} I_n \neq \empty $$

**Proof**

Set $A$를 다음과 같이 정의하자.

$$ A := \Set{a_n | n \in \N} $$

$A$의 정의에 의해 다음이 성립한다.

$$ \begin{gathered} A \text{ is bounded above} \\ A \subset \R \end{gathered} $$

따라서 axiom of completeness에 의해 다음이 성립한다.

$$ \exist \sup(A) $$

Supremum은 upper bound임으로 다음이 성립한다.

$$ \forall n \in \N, \quad a_n \le \sup(A) $$

다음으로, $A$의 정의에 의해 다음이 성립한다.

$$ \forall n \in N, \quad b_n \text{ is an upper bound of } A $$

따라서, supremum의 정의에 의해 다음이 성립한다.

$$ \forall n \in N, \quad \sup(A) \le b_n $$

이를 종합하면 다음이 성립한다.

$$ \forall n \in N, \quad  a_n \le \sup(A) \le b_n $$

따라서, 다음이 성립한다.

$$ \sup(A) \in \bigcap_{n=1}^{\infty} I_n \implies \bigcap_{n=1}^{\infty} I_n \neq \empty \qed $$

> Reference  
> {cite}`abbott` Theorem 1.4.1

### 명제3
다음을 증명하여라

$$ \forall x \in \R^+ \quad \exist n \in \N \st n-1 < x \le n $$

**Proof**

Set $S_x$를 다음과 같이 정의하자.

$$ \forall x \in \R^+, \quad  S_x:= \Set{n \in \N | x \le n} $$

$\N$은 well-orderd set이고 $S_x$는 $\N$의 subset임으로 다음이 성립한다.

$$ \forall x \in \R^+, \quad \exist m_x \in S_x \st \text{least element of } S_x $$

따라서, 다음이 성립한다.

$$ \begin{gathered} m_x \in \N \\  x \le m_x \end{gathered}  $$

또한 $m_x$는 $S_x$의 least element임으로 보조명제3.1에 의해 다음이 성립한다.

$$ m_x - 1 < x $$

위의 결과를 종합하면 다음이 성립한다.

$$ \forall x \in \R^+, \quad \exist m_x \in \N \st m_x - 1 < x \le m_x \qed $$

#### 보조명제3.1
다음을 증명하여라.

$$ m_x - 1 < x $$

**Proof**

다음을 가정하자.

$$ x \le m_x-1 $$

이 떄, $m_x$는 $S_x$의 least element임으로 다음이 성립한다.

$$ \begin{aligned} m_x - 1 \notin S_x \iff m_x-1 < x \end{aligned}  $$

이는 가정에 모순됨으로 proof by contradiction에 의해 다음이 성립한다.

$$ m_x - 1 < x \qed $$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/3601551/every-real-number-lies-between-n-and-n1)

#### 따름명제3.2
다음을 증명하여라.

$$ \forall x \in \R^+, \quad \exist n \in \N \st x \le n < x+1 $$

**Proof**

명제3에 의해 다음이 성립한다.

$$ \forall x \in \R^+ \quad \exist n \in \N \st n-1 < x \le n $$

부등식에 $1$을 더하면 다음이 성립한다.

$$ n < x+1 \le n+1 $$

위 결과를 종합하면 다음이 성립한다.

$$ \forall x \in \R^+, \quad \exist n \in \N \st x \le n < x+1 \qed $$

### 명제4
다음을 증명하여라.

$$ \R \text{ has an archimedean property} $$

**Proof**

$x \in \R$가 있다고 하자.

만약 $x \in \R^-_0$면 모든 자연수가 $x$보다 큼으로 다음이 자명하게 성립한다.

$$ \forall x \in \R^-_0, \quad \exist n \in \N \st x < n $$

다음으로 $x\in \R^+$인 경우를 보자.

명제3에 의해 다음이 성립한다.

$$ \forall x \in \R^+, \quad  \exist n \in \N \st n-1 < x \le n $$

$\forall n \in \N, \quad n < n+1$임으로 다음이 성립한다.

$$ \forall x \in \R^+, \quad  \exist n \in \N \st x < n+1 $$

$\R = \R^-_0 \cup \R^+$임으로 위의 결과를 종합하면 다음이 성립한다.

$$ \forall x \in \R \implies \exist n \in \N \st x < n \qed $$

### 명제5
다음을 증명하여라.

$$ \forall x_{1,2} \in \R \st x_1 < x_2, \quad \exist r \in \Q \st x_1 < r < x_2 $$

**Proof**

$x_2 - x_1 \in \R$임으로 archimedean property에 의해 다음이 성립한다.

$$ \exist n \in \N \st \frac{1}{n} < x_2 - x_1 $$

따라서, 위를 만족하는 $n$에 대해 다음이 성립한다.

$$ \begin{aligned} \frac{1}{n} &< x_2 - x_1 \\ 1 &< n(x_2 - x_1) \\ nx_1+1 &< nx_2  \end{aligned} $$

또한, $nx_1\in\R$임으로 명제3에 의해 다음이 성립한다.

$$ \exist m \in \N \st m-1 \le x_1n < m $$

따라서, 위를 만족하는 $n,m$에 대해서 다음이 성립한다.

$$ \begin{aligned} m-1 &\le x_1n \\ m &\le x_1n +1 \\ m &< nx_2 \end{aligned} $$

위 결과를 정리하면 다음이 성립한다.

$$ \begin{aligned} & \forall x_{1,2} \in \R \st x_1 < x_2, \quad \exist n,m \in \N \st nx_1 < m < nx_2 \\ \iff& \forall x_{1,2} \in \R \st x_1 < x_2, \quad \exist n,m \in \N \st x_1 < \frac{m}{n} < x_2  \end{aligned} $$

### 명제6
다음을 증명하여라.

$$ \forall q \in \Q, \quad \exist n \in \Z \st n \le q < n+1 $$

> Reference  
> [proofwiki](https://proofwiki.org/wiki/Real_Number_lies_between_Unique_Pair_of_Consecutive_Integers)