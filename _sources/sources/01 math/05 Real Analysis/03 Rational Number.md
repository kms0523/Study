# Rational Number
## 정의
다음과 같이 정의된 집합 $\Q$을 `유리수(rational number)`라고 한다.

$$ \Q := \Set{\frac{n}{m} | n \in \Z, \enspace m \in \Z-\Set{0}} $$

### 명제1
다음을 증명하여라.

$$ \Q \text{ has an archimedean property} $$

**Proof**

$x \in \Q$가 있다고 하자.

만약 $x \in \Q^-_0$면 모든 자연수가 $x$보다 큼으로 다음이 자명하게 성립한다.

$$ \forall x \in \Q^-_0, \quad \exist n \in \N \st x < n $$


다음으로 $x\in \Q^+$인 경우를 보자.

$\Q^+$의 정의에 의해  다음이 성립한다.

$$ \forall x \in \Q^+, \quad \exist n,m \in \N \st x = \frac{n}{m} $$

따라서, 다음이 성립한다.

$$ mx = n $$

$\forall n \in \N, \quad x \le nx$임으로 다음이 성립한다.

$$ x \le mx \implies x \le n $$

따라서, 다음이 성립한다.

$$ \forall x \in \Q^+, \quad x < n+1 $$

$n+1 \in \N$임으로 다음이 성립한다.

$$ \forall x \in \Q^+, \quad \exist n \in \N \st x < n $$

$\Q = \Q^-_0 \cup \Q^+$임으로 위의 결과를 종합하면 다음이 성립한다.

$$ \forall x \in \Q \implies \exist n \in \N \st x < n $$

### 명제2
다음을 증명하여라.

$$ \forall q \in \Q, \quad \exist z_1,z_2 \in \Z \st z_1 \le q \le z_2 $$

**Proof**

$q \in \Q$임으로, 일반성을 잃지 않고 다음이 성립한다고 할 수 있다.

$$ \exist n \in \Z, \enspace m \in \N \st q = \frac{n}{m} $$

이 떄, $\Z$의 성질에 의해 다음이 성립한다.

$$ \begin{aligned} &\exist z_1,z_2 \in \Z \st \begin{gathered} z_1m \le n \\ n \le z_2m \end{gathered}  \\ \iff& \exist z_1,z_2 \in \Z \st z_1 \le \frac{n}{m} \le z_2 \qed\end{aligned}  $$

### 명제3
$\Z$의 bounded above subset과 bounded below subset $U^q_a, U^q_b$를 다음과 같이 정의하자.

$$ \forall q \in \Q, \quad  \begin{gathered} U^q_b := \Set{ z \in \Z | q \le z} \\ U^q_a := \Set{ z \in \Z | z \le q} \end{gathered}  $$

이 떄, 다음을 증명하여라.

$$ \forall q \in \Q, \quad  \begin{gathered} U^q_b \text{ has an least element} \\ U^q_a \text{ has an greatest element} \end{gathered}  $$

**Proof**

명제2에 의해 다음이 성립한다.

$$ \forall q \in \Q, \quad \exist z_1,z_2 \in \Z \st z_1 \le q \le z_2 \implies \begin{gathered} z_1 \text{ is an lower bound of } U_b^q \\ z_1 \in U_a^q \\ z_2 \text{ is an upper bound of } U_a^q \\ z_1 \in U_b^q \end{gathered}  $$

따라서, 다음이 성립한다.

$$ \forall q \in \Q, \quad  \begin{gathered} U_b^q \text{ is an nonempty bounded below subset of } \Z \\ U_a^q \text{ is an nonempty bounded above subset of } \Z  \end{gathered}  $$

따라서, $\Z$의 성질에 의해 다음이 성립한다.

$$ \forall q \in \Q, \quad  \begin{gathered} U^q_b \text{ has an least element} \\ U^q_a \text{ has an greatest element} \end{gathered} \qed $$


### 명제5
다음을 증명하여라.

$$ \forall q \in \Q, \quad \exist! z \in \Z \st  0 \le q - z <1 $$

**Proof**

$U^q_a$를 다음과 같이 정의하자.

$$ \forall q \in \Q , \quad  U^q_a := \Set{ z \in \Z | z \le q } $$

명제4에 의해 다음이 성립한다.

$$\forall q \in \Q, \quad \exist u^q_M \in \Z \st \text{  greatest element of } U^q_a $$

$u^q_M$은 greatest element임으로 다음이 성립한다.

$$\forall q \in \Q, \quad \exist! u^q_M \in \Z \st \text{  greatest element of } U^q_a $$

다음으로 $u^q_M$이 $0 \le q - u^q_M <1$ 성질을 만족하는지 알아보자.

$\Q$의 정의에 의해 일반성을 잃지 않고 다음이 성립한다고 할 수 있다.

$$ \forall q \in \Q, \quad \exist!a\in\Z, \enspace \exist!b\in\N, \st q = \frac{a}{b}  $$

다음을 가정하자.

$$ q - u^q_M < 0 $$

그러면 다음이 성립한다.

$$ \frac{a}{b} - u^q_M < 0 \iff \frac{a}{b} < u^q_M $$

이는 $u^q_M\in U^q_a$에 모순임으로 proof by contradiction에 의해 다음이 성립한다.

$$ 0 \le q - u^q_M $$

다음으로, 다음을 가정하자.

$$ 1 \le q - u^q_M $$

그러면 다음이 성립한다.

$$ \begin{aligned} & 1 \le \frac{a}{b} - u^q_M \\ \iff& u^q_M+1 \le \frac{a}{b} \\\iff& u^q_M +1 \in U \end{aligned}  $$

하지만 이는 $u^q_M$이 greatest element라는 사실에 모순임으로 proof by contradiction에 의해 다음이 성립한다.

$$\forall q \in \Q, \quad \exist u^q_M \in \Z \st 0 \le q - u^q_M < 1 \qed $$

#### 따름명제5.1
다음을 증명하여라.

$$ \forall q \in \Q, \quad \exist! z \in \Z \st z \le q < z+1 $$

**Proof**

명제5에 의해 다음이 성립한다.

$$ \begin{aligned} & \forall q \in \Q, \quad \exist! z \in \Z \st  0 \le q - z <1 \\ \iff& \forall q \in \Q, \quad \exist! z \in \Z \st  z \le q < z+1 \qed \end{aligned}  $$


### 명제6(division theorem)
다음을 증명하여라

$$ \forall a \in \Z, \enspace \forall b \in \N, \quad \exist! q,r \in \Z \st \begin{gathered} a = qb + r \\ 0 \le r < b \end{gathered}  $$

**Proof**

Set $U$를 다음과 같이 정의하자.

$$ U:= \Set{ x \in \Z | x \le \frac{a}{b}} $$

그러면 명제4에 의해 다음이 성립한다.

$$ \exist u_M \in \Z \st \text{ greatest element of } U $$

$u_M$은 greatest element임으로 greatest element성질에 의해 다음이 성립한다.

$$ \exist! u_M \in \Z \st \text{ greatest element of } U $$

다음으로 $t \in \Q$를 다음과 같이 정의하자.

$$ t := \frac{a}{b} - u_M $$

그러면 다음이 성립한다.

$$ \begin{aligned} \frac{a}{b} &= u_M + t \\ a &= bu_M + bt \end{aligned} $$

$a,b,u_M \in \Z$임으로 $\Z$의 성질에 의해 다음이 성립한다.

$$ \exist!r \in \Z \st r= a - bu_M $$

또한, 명제5에 의해 다음이 성립한다.

$$ \begin{aligned} & 0 \le t < 1 \\\implies& 0 \le bt < b \\\implies& 0 \le r < b \end{aligned}  $$

따라서, 다음이 성립한다. 

$$ \forall a \in \Z, \enspace \forall b \in \N, \quad \exist! q,r \in \Z \st \begin{gathered} a = qb + r \\ 0 \le r < b \end{gathered} \qed  $$
