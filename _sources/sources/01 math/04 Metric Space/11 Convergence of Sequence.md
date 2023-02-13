# Convergence of Sequence
## 정의
Metric space $M$과 $M$위의 sequnece $s$가 있다고 하자.

$s$가 $a \in M$에 `수렴(convergence)`한다는 말은 다음과 동치이다.

$$ \forall \epsilon \in \R^+, \quad \exist N \in \N \quad s.t. \quad \forall n > N, \quad d(s(n), a) < \epsilon $$

### 참고
open ball을 이용해서 표현하면 다음과 같다.

$$ \forall \epsilon \in \R^+, \quad \exist N \in \N \quad s.t. \quad \forall n > N, \quad s(n) \in B_M(a, \epsilon) $$

### 명제1
Metric space $M$와 $x \in M$이 있다고 하자.

constnat sequence $s = \{ x,\cdots,x \}$가 있을 때, 다음을 증명하여라.

$$ s \text{ is converge to } x $$

**Proof**

$s$가 $y \in M - \{x\}$에 수렴한다고 가정하자.

그러면 다음이 성립한다.

$$ d(x,y) = r > 0 $$

이 떄, $s$가 $y$에 수렴함으로, 수렴의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} & \forall \epsilon \in \R^+, \quad d(s(n),y) < \epsilon \\ \Rightarrow\enspace& d(x,y) < \epsilon \end{aligned} $$

하지만 $\epsilon < r$일 경우, 수렴의 정의를 만족할 수 없게 된다. 

즉, 수렴한다는 가정에 모순이 발생함으로 proof by contradiction에 의해 $s$는 $x$에 수렴한다.$\qed$

### 명제2
Metric space $M$이 있다고 하자. 

$M$위의 sequence $s$가 있을 때, 다음을 증명하여라.

$$ s \text{ can converge to at most one point in } M $$

**Proof**

$s$가 $x,y \in M$에 수렴한다고 하자.

 $\forall \epsilon \in \R^+$에 대해 어떤 $N \in \N$이 존재하여 다음이 성립한다.

$$ \begin{aligned} & 0 \le d(x,y) \le d(s(N),x) + d(s(N), y) \\ \Rightarrow \enspace &  0 \le d(x,y) \le 2\epsilon \end{aligned}  $$

보조명제2.1에 의해 $d(x,y) = 0$이고 따라서, $x = y$이다. $\qed$

#### 보조명제2.1
$\forall \epsilon \in \R^+$에 대해 다음이 성립한다고 하자.

$$ 0 \le d \le \epsilon $$

이 때, 다음을 증명하여라.

$$ d = 0 $$

**Proof**

$d \neq 0$라 가정하자.

가정에 의해 $0 < d$이고 그러면 $\epsilon < d/2$에서 조건 $0  \le d \le \epsilon$가 성립하지 않는 모순이 발생한다.

따라서, proof by contradiction에 의해 $d =0$이다. $\qed$

> Reference  
> {cite}`apostol` Theorem4.2.

### 명제3
Metric space $M$와 $x\in M$이 있다고 하자.

$M$위의 sequnece $s$가 있다고 할 때, 다음을 증명하여라.

$$ s \text{ converge to } x \implies s \text{ is bounded sequnece} $$

**Proof**

$\epsilon_0 \in \R^+$가 있다고 하자.

전제에 의해 다음이 성립한다.

$$ \exist N_0 \in \N \st \forall n \ge N_0, \quad s(n) \in B_M(x, \epsilon_0) $$

이 때, $r$을 다음과 같이 정의하자.

$$ r := \max(d(x,s(1)), \cdots, d(x,s(N_0-1)),\epsilon_0) $$

그러면 다음이 성립한다.

$$ \forall n \in \N, \quad s(n) \in B_M(x,r) \qed $$

> Reference  
> {cite}`apostol` Theorem4.3.


### 명제4
Metric space $M$과 $M$의 subset $U$가 있다고 하자.

$x \in M$이 있을 때, 다음을 증명하여라.

$$ x \text{ is an adherent point of } U \iff \exist\text{squence } s \text{ on } U \st \lim_{n\rightarrow\infty}s(n) = x $$

**Proof**

[$\implies$]  
$x$가 $U$의 adherent point임으로 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad B(x,\epsilon) \cap U \neq \empty $$

따라서, 다음이 성립한다.

$$ \forall n \in \N, \quad \exist s_n \in U \st d(s_n,x) \le \frac{1}{n} $$

이 떄, $U$위의 sequence $s$를 다음과 같이 정의하자.

$$ s(i) = s_i $$

Rationale number는 dense in real임으로 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist N \in \N \st \frac{1}{N} \le \epsilon $$

따라서, 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist N \in \N \st  \forall n \ge N, \quad d(s(n),x) < \epsilon \qed $$

[$\impliedby$]
Convergent sequece의 정의에 의해 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist N \in \N \st  \forall n \ge N, \quad d(s(n),x) < \epsilon $$

따라서, 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad  B(x,\epsilon) \cap U \neq \empty \implies \forall \mathcal{N_x} \in \Set{\mathcal{N_x}}, \quad \mathcal{N_x} \cap U \neq \empty $$

Adherent point의 정의에 의해 다음이 성립한다.

$$ x \text{ is an adherent point of } U \qed $$

> Reference  
> {cite}`apostol` Theorem4.4.

### 명제5
Metric space $M$과 $M$위의 sequence $s$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ s \text{ is converges to } x \in M \iff \text{every subsequence of } s \text{ converges to } x $$

**Proof**

[$\implies$]  
$s$가 convergent sequence임으로 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist N \in \N \st  \forall n \ge N, \quad d(s(n),x) < \epsilon $$

$s$의 임의의 subsequence를 $s(k(n))$이라할 때, 다음이 성립한다.

$$ \forall N \in \N, \quad \exist M \in \N \st \forall n \ge M, \quad N \le k(n) $$

따라서, 이를 종합하면 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist M \in \N \st  \forall n \ge M, \quad d(s(k(n)),x) < \epsilon $$

그럼으로 다음이 성립한다. 

$$ \text{every subsequence of } s \text{ converges to } x \qed $$

[$\impliedby$]  
$s$는 $s$의 subsequence 중에 하나임으로 자명하게 성립한다. $\qed$

### 명제6
Metric space $M$과 $M$위의 sequence $s$가 있다고 하자.

$x \in M$일 떄, 다음을 증명하여라.

$$ s \text{ is converges to } x \iff \forall N_x \in \mathcal{N_x}, \quad \exist N \in \N \st N \le n \implies s(n) \in N_x $$

**Proof**

[$\implies$]  
$\mathcal{N_x}$의 임의의 element를 $N_x$라 하자.

$N_x$는 $x$를 포함하는 open set임으로 다음이 성립한다.

$$ \exist r \in \R^+ \st B_M(x,r) \subseteq N_x $$

$s$는 $x$의 coverge 함으로 다음이 성립한다.

$$ \exist N \in \N \st N \le n \implies s(n) \in B_M(x,r)  $$

임의의 $N_x$에서 위를 만족함으로 다음이 성립한다.

$$ \forall N_x \in \mathcal{N_x}, \quad \exist N \in \N \st N \le n \implies s(n) \in N_x \qed $$

[$\impliedby$]  
$x$를 중점으로 하는 open ball은 $x$를 포함하는 open set임으로 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad B_M(x,\epsilon) \in \mathcal{N_x} $$

따라서, 전제에 의해 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist N\in \N \st N \le n \implies s(n) \in B_M(x,\epsilon) \qed $$
