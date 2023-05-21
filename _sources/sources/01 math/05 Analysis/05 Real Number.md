# Real Number
## 정의
다음과 같이 정의된 집합 $\R$을 `실수(real number)`라고 한다.
 
$$ \R := \text{ordered complete field which contains } \Q \text{ as a subfield} $$

> Reference  
> {cite}`abbott` p.14

### 참고1(axiom of completeness)
$\R$이 complete field임으로 다음이 성립한다.

$$ \text{Every nonempty subset of } \R \text{ that is bounded above has a supremum} $$

이 떄, 의문점은 이러한 $\R$이 실제로 존재하냐? 라는 점이고 이러한 $\R$의 존재성을 axiom으로써 받아들인다. 이를 `axiom of completeness`라고 한다.

### 참고2
$x \in \R$은 $\R$의 어떤 bounded above subset의 supremum이라고 볼 수 있다.

### 명제1
$\R$의 subset $X$가 있다고 하자.

$x \in X$가 있을 떄, 다음을 증명하여라.

$$ x = \sup(X) \iff \forall \epsilon \in \R^+, \quad \exist y \in X \st x-\epsilon < y \le x $$

**Proof**

[$\implies$]  
전제에 의해 $x$가 $X$의 supremum임으로, supremum의 정의에 의해 다음이 성립한다.

$$ \forall y \in X, \quad y \le x $$

$\forall \epsilon \in \R^+. \quad 0 \le \epsilon$임으로 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad x-\epsilon < x $$

따라서, supremum의 정의에 의해 다음이 성립한다.

$$ x-\epsilon \text{ is not an upper bound of } X $$

그럼으로 다음이 성립한다.

$$ \exist y \in X \st x-\epsilon < y $$

따라서, 위의 결과를 종합하면 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist y \in X \st x-\epsilon < y \le x \qed $$

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
다음을 증명하여라.

$$ \R \text{ has an archimedean property} $$

**Proof**

집합 $S$를 다음과 같이 정의하자.

$$ \forall x \in \R, \quad  S := \Set{n \in \N | n \le x} $$

집합 $S$가 공집합일 경우, $x < 1$임으로 $n=1$로 두면 자명하게 성립한다.

다음으로 집합 $S$가 공집합이 아닌 경우를 보자.

$S$는 $\R$의 nonempty bounded above subset임으로 다음이 성립한다.

$$ \exist\sup(S) \in \R $$

명제1에 의해 다음이 성립한다.

$$ \begin{aligned} & \forall \epsilon \in \R^+, \quad \exist y \in S \st \sup(S)-\epsilon < y \le \sup(S) \\\implies& \exist y \in S \st \sup(S) - 1 < y \le \sup(S) \\\iff& \exist y \in S \st \sup(S) < y+1 \le \sup(S)+1 \end{aligned}  $$

$S$는 $\N$의 subset임으로 다음이 성립한다.

$$ \begin{aligned} & \exist y \in \N \st \sup(S) < y+1 \\ \implies& \exist y \in \N  \st  \forall s \in S, \quad s < y+1 \\ \implies& \exist y \in \N \st y+1 \notin S \\\iff& \exist y \in \N \st x < y+1 \end{aligned}  $$

따라서, 다음이 성립한다.

$$ \forall x \in \R,\quad  \exist n \in \N \st x < n \qed $$

#### 따름명제3.1
$\R$의 부분집합 $U$를 다음과 같이 정의하자.

$$ U := \Set{\frac{1}{n}|n \in \N} $$

이 때, 다음을 증명하여라.

$$ \begin{gathered} \sup(U) = 1 \\ \inf(U) = 0 \end{gathered} $$

**Proof**

[sup]  
자연수의 성질에 의해 다음이 성립한다.

$$ \forall n \in \N, \quad 1 \le n \iff \forall n \in \N, \quad \frac{1}{n} \le 1  $$

$U$의 upper bound의 집합을 $S$라고 할 때, 다음이 성립한다.

$$ 1 \in S $$

또한, $1 \in U$임으로 다음이 성립한다.

$$ 1 \text{ is greatest element of } U $$

따라서, supremum의 성질에 의해 다음이 성립한다.

$$ \sup(U) = 1 \qed $$

[inf]  
자연수의 성질에 의해 다음이 성립한다.

$$ \forall n \in \N, \quad 0 \le 1 \iff \forall n \in \N, \quad 0 \le \frac{1}{n} $$

$U$의 lower bound의 집합을 $S$라고 할 떄, 다음이 성립한다.

$$ 0 \in S $$

이 때, 다음을 가정하자.

$$ 0 \text{ is not greatest element of } S $$

그러면 다음이 성립한다.

$$ \exist s \in S \st 0 < s  $$

$\R$의 archimedean property에 의해 다음이 성립한다.

$$ \exist n \in \N, \quad \st \frac{1}{n} < s $$

이는 $s \in S$라는 사실에 모순임으로 proof by contradiction에 의해 다음이 성립한다.

$$ 0 \text{ is greatest element of } S $$

따라서 infimum의 정의에 의해 다음이 성립한다.

$$ \inf(U) = 0 \qed $$

#### 따름명제3.2
$\R$의 subset $X$가 있다고 하자.

$x \in X$가 있을 떄, 다음을 증명하여라.

$$ x = \sup(X) \iff \forall n \in \N, \quad \exist y \in X \st x- \frac{1}{n}< y \le x $$

**Proof**

[$\implies$] 
명제1에 의해 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist y \in X \st x-\epsilon < y \le x $$

$\forall n \in \N, \frac{1}{n} \in \R^+$임으로 다음이 성립한다.

$$ \forall n \in \N, \quad \exist y \in X \st x- \frac{1}{n}< y \le x \qed $$

[$\impliedby$]  
$\R$의 archimedean property에 의해 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist n \in \N \st x -\epsilon  < x- \frac{1}{n} $$

전제에 의해 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist n \in \N, \enspace \exist y \in X \st x- \epsilon < x - \frac{1}{n} < y \le x $$

따라서, 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist y \in X \st x-\epsilon < y \le x $$

그럼으로 명제1에 의해 다음이 성립한다.

$$ x = \sup(X) \qed $$

##### 참고
명제1은 supremum을 확인하기 위해서 uncountable한 $\R^+$의 모든 원소에 대해 확인해야됐다.

하지만 따름명제3.2에 의해 countable한 $\N$의 모든 원소에 대해 확인하면 supremum인지 확인할 수 있다.

#### 따름명제3.3
다음을 증명하여라.

$$ \forall x \in \R, \quad \exist n \in \N \st -n < x < n $$

**Proof**

명제3에 의해 다음이 성립한다.

$$ \forall x \in \R, \quad \exist n \in \N \st |x| < n $$

따라서 다음이 성립한다.

$$ \forall x \in \R, \quad \exist n \in \N \st -n < x < n \qed $$

### 명제4
$\Z$의 bounded above subset과 bounded below subset $U^q_a, U^q_b$를 다음과 같이 정의하자.

$$ \forall x \in \R, \quad  \begin{gathered} U^x_b := \Set{ z \in \Z | x \le z} \\ U^x_a := \Set{ z \in \Z | z \le x} \end{gathered}  $$

이 떄, 다음을 증명하여라.

$$ \forall x \in \R, \quad  \begin{gathered} U^x_b \text{ has an least element} \\ U^x_a \text{ has an greatest element} \end{gathered}  $$

**Proof**

따름명제3.3에 의해 다음이 성립한다.

$$ \forall x \in \R, \quad \exist n \in \N \st -n < x < n \implies \begin{gathered} -n \text{ is an lower bound of } U_b^x \\ -n \in U_a^x \\ n \text{ is an upper bound of } U_a^x \\ n \in U_b^x \end{gathered}  $$

따라서, 다음이 성립한다.

$$ \forall x \in \R, \quad  \begin{gathered} U_b^x \text{ is an nonempty bounded below subset of } \Z \\ U_a^x \text{ is an nonempty bounded above subset of } \Z  \end{gathered}  $$

따라서, $\Z$의 성질에 의해 다음이 성립한다.

$$ \forall x \in \R, \quad  \begin{gathered} U^x_b \text{ has an least element} \\ U^x_a \text{ has an greatest element} \end{gathered} \qed $$

### 명제5
다음을 증명하여라.

$$ \forall x \in \R, \quad \exist! z \in \Z \st  z \le x < z+1 $$

**Proof**

$U_x$를 다음과 같이 정의하자.

$$ \forall x \in \R , \quad  U_x := \Set{ z \in \Z | z \le x } $$

명제4에 의해 다음이 성립한다.

$$\forall x \in \R, \quad \exist! u^x_M \in \Z \st \text{  greatest element of } U_x $$

$u^x_M$은 greatest element임으로 다음이 성립한다.

$$ \begin{gathered} u^x_M \in U_x \iff u^x_M \le x \\ u^x_M +1 \notin U_x \iff x < u^x_M +1 \end{gathered} $$

이를 종합하면 다음이 성립한다.

$$\forall x \in \R, \quad \exist u^x_M \in \Z \st u^x_M \le x < u^x_M + 1 \qed $$

#### 따름명제5.1
다음을 증명하여라.

$$ \forall x \in \R, \quad \exist! z \in \Z \st x < z \le x+1 $$

**Proof**

명제5에 의해 다음이 성립한다.

$$ \begin{aligned} & \forall x \in \R, \quad \exist! z \in \Z \st \begin{gathered} z \le x < z+1 \\ z +1 \le x+1 < z+2 \end{gathered} \\ \implies& \forall x \in \R, \quad \exist! z \in \Z \st x < z+1 \le x+1 \qed \end{aligned}   $$

### 명제6
다음을 증명하여라.

$$ \forall x_{1,2} \in \R \st x_1 < x_2, \quad \exist q \in \Q \st x_1 < q < x_2 $$

**Proof**

$x_2 - x_1 \in \R$임으로 archimedean property에 의해 다음이 성립한다.

$$ \exist n \in \N \st \frac{1}{n} < x_2 - x_1 $$

따라서, 위를 만족하는 $n$에 대해 다음이 성립한다.

$$ \begin{aligned} \frac{1}{n} &< x_2 - x_1 \\ 1 &< n(x_2 - x_1) \\ nx_1+1 &< nx_2  \end{aligned} $$

또한, $nx_1\in\R$임으로 따름명제5.1에 의해 다음이 성립한다.

$$ \exist! m \in \Z \st nx_1 < m \le nx_1 + 1$$

따라서, 다음이 성립한다.

$$ \exist! m \in \Z \st nx_1 < m < nx_2 $$

위 결과를 정리하면 다음이 성립한다.

$$ \begin{aligned} & \forall x_{1,2} \in \R \st x_1 < x_2, \quad \exist n \in \N, \enspace m \in \Z \st nx_1 < m < nx_2 \\ \iff& \forall x_{1,2} \in \R \st x_1 < x_2, \quad \exist n \in \N ,\enspace m \in \Z \st x_1 < \frac{m}{n} < x_2 \qed  \end{aligned} $$

#### 참고
분모는 실수의 completeness 공리로부터 증명되었고 분자는 자연수의 well ordering 공리와 completeness 공리로부터 증명되었다.

#### 따름명제6.1
다음을 증명하여라.

$$ \forall x_{1,2} \in \R \st x_1 < x_2, \quad \exist r \in \R \st x_1 < r < x_2 $$

**Proof**

명제6에 의해 다음이 성립한다.

$$ \forall x_{1,2} \in \R \st x_1 < x_2, \quad \exist q \in \Q \st x_1 < q < x_2 $$

$q \in \R$임으로 다음이 성립한다.

$$ \forall x_{1,2} \in \R \st x_1 < x_2, \quad \exist r \in \R \st x_1 < r < x_2 \qed $$


### 명제7
$x_1,x_2 \in \R$이 있다고 하자.

이 때, 다음을 증명하여라.

$$ \forall \epsilon \in \R^+, \quad |x_1-x_2| < \epsilon \implies x_1 = x_2 $$

**Proof**

다음을 가정하자.

$$ x_1 \neq x_2 $$

그러면 다음이 성립한다.

$$ \exist d \in \R^+ \st |x_1 - x_2| = d $$

이 때, $d/2 \in \R^+$임으로 전제에 의해 다음이 성립한다.

$$ |x_1-x_2| < \frac{d}{2} $$

이는 $|x_1-x_2|=d$라는 사실에 모순임으로 proof by contradiction에 의해 다음이 성립한다.

$$ x_1 = x_2 \qed $$