# Real Number
## 정의
다음과 같이 정의된 집합 $\R$을 `실수(real number)`라고 한다.

$$ \R := \text{ordered complete field which contains } \Q \text{ as a subfield} $$

> Reference
> {cite}`abbott` p.14

### 참고(axiom of completeness)
$\R$이 complete field임으로 다음이 성립한다.

$$ \text{Every nonempty subset of } \R \text{ that is bounded above has a supremum} $$

이를 `axiom of completeness`라고 한다.

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

$$ \forall x \in \R \quad \exist n \in \N \st n \le x \le n+1 $$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/3601551/every-real-number-lies-between-n-and-n1)