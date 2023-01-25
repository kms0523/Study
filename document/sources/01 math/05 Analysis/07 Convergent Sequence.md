# Convergent Sequence
## 정의
$\R$위의 sequence $s$가 있다고 하자.

$s$가 $x \in \R$에 수렴한다는 말은 다음과 같다.

$$ \forall \epsilon \in \R^+, \quad \exist N \in \N \st N \le n \implies |s(n) - x| < \epsilon $$

### 명제1
$\R$위의 sequence $s$가 다음과 같이 주어졌다고 하자.

$$ s(n) = \frac{1}{n} $$

이 떄, 다음을 증명하여라.

$$ \lim_{n\rightarrow\infty}s(n) = 0 $$

**Proof**

임의의 $\epsilon\in\R^+$가 있다고 하자.

$\epsilon/2 \in \R^+$임으로 Archimedean property에 의해 다음이 성립한다.

$$ \exist N \in \N \st \frac{1}{N} < \frac{\epsilon}{2} $$

위를 만족하는 $N$에 대해 다음이 성립한다.

$$ \forall n > N, \quad |s(n)-0| = \frac{1}{n} < \frac{1}{N} < \frac{\epsilon}{2} < \epsilon $$

임의의 $\epsilon$에 대해서 위가 성립함으로, 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \exist N \in \N \st \forall n > N, \quad |s(n)| < \epsilon $$

따라서 convergece의 정의에 의해 다음이 성립한다.

$$ \lim_{n\rightarrow\infty}s(n) = 0 \qed $$

### 명제2
$\R$위의 sequence $s$가 다음과 같이 주어졌다고 하자.

$$ s(n) = 1+(-1)^n $$

이 떄, 다음을 증명하여라.

$$ s(n) \text{ is diverge} $$

**Proof**

$s(n)$의 정의에 의해 다음이 성립한다.

$$ \forall n\in \N, \quad |s(n) - s(n+1)| = 2 $$

따라서, 임의의 $n\in\N, \enspace x\in\R$에 대해서 다음이 성립한다.

$$ \begin{aligned} |s(n) - s(n+1)| &= |s(n) - x + x - s(n+1)| \\&\le |s(n) - x| + |x - s(n+1)| \\&= |s(n) - x| + |s(n+1) -x| \\ 2 &\le |s(n) - x| + |s(n+1) -x| \end{aligned} $$

이 때, 다음을 가정하자.

$$ s(n) \text{ is converge } $$

그러면 다음이 성립한다.

$$ \exist x \in \R \st \forall \epsilon \in \R^+, \quad \exist N \in \N \st N \le n \implies |s(n) - x| < \epsilon $$

따라서, $\epsilon_1 < 1$에 대해서 다음이 성립한다.

$$ \exist N_1 \st N_1 \le n \implies |s(n) - x| < \epsilon_1 $$

그러면 다음이 성립한다.

$$ N_1 \le n \implies |s(n) - x | + |s(n+1)-x| < 2\epsilon_1 < 2 $$

이는 $s(n)$의 정의에 의해 유도된 성질에 모순됨으로 proof by contradiction에 의해 다음이 성립한다.

$$ s(n) \text{ is diverge} \qed $$

### 명제3
$\R$위의 convergent sequence $s$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ \lim_{n\rightarrow\infty} s(n) \text{ is unique} $$

**Proof**

$\lim_{n\rightarrow\infty} s(n) = x_1,x_2$라고 하자.

임의의 $\epsilon\in\R^+$에 대해 $\epsilon/2 \in \R^+$임으로 convergent sequence의 정의에 의해 다음이 성립한다.

$$ \exist N_1,N_2 \in \N \st \begin{gathered} N_1 \le n \implies |s(n) - x_1| < \frac{\epsilon}{2} \\ N_2 \le n \implies |s(n) - x_2| < \frac{\epsilon}{2} \end{gathered}  $$

그러면 다음이 성립한다.

$$ \max(N_1,N_2) \le n \implies |x_1-x_2| < |x_1 - s(n)| + |x_2 - s(n)| < \epsilon $$

임의의 $\epsilon\in\R^+$에 대해 위가 성립함으로, 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad |x_1-x_2| < \epsilon $$

따라서, $\R$의 성질에 의해 다음이 성립한다.

$$ x_1 = x_2 \qed $$


