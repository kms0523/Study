# Convergent Sequence
## 정의
Metric space $M$과 $M$위의 sequnece $s$가 있다고 하자.

sequence가 $a$에 `수렴(convergence)`한다는 말은 다음과 동치이다.

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

즉, 수렴한다는 가정에 모순이 발생함으로 proof by contradiction에 의해 $s$는 $x$에 수렴한다.$\quad\tiny\blacksquare$

### 명제2
Metric space $M$이 있다고 하자. 

$M$위의 sequence $s$가 있을 때, 다음을 증명하여라.

$$ s \text{ can converge to at most one point in } M $$

**Proof**

$s$가 $x,y \in M$에 수렴한다고 하자.

 $\forall \epsilon \in \R^+$에 대해 어떤 $N \in \N$이 존재하여 다음이 성립한다.

$$ \begin{aligned} & 0 \le d(x,y) \le d(s(N),x) + d(s(N), y) \\ \Rightarrow \enspace &  0 \le d(x,y) \le 2\epsilon \end{aligned}  $$

보조명제2.1에 의해 $d(x,y) = 0$이고 따라서, $x = y$이다. $\quad\tiny\blacksquare$

#### 보조명제2.1
$\forall \epsilon \in \R^+$에 대해 다음이 성립한다고 하자.

$$ 0 \le d \le \epsilon $$

이 때, 다음을 증명하여라.

$$ d = 0 $$

**Proof**

$d \neq 0$라 가정하자.

가정에 의해 $0 < d$이고 그러면 $\epsilon < d/2$에서 조건 $0  \le d \le \epsilon$가 성립하지 않는 모순이 발생한다.

따라서, proof by contradiction에 의해 $d =0$이다. $\quad\tiny\blacksquare$

> Reference  
> {cite}`apstol` 4.2.