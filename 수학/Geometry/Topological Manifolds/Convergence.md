# Convergence
topological space $X$가 있다고 하자.

$s(n)$이 $X$위의 sequence일 때, $s(n)$이 $x \in X$에 `수렴(convergence)`한다는 말은 다음과 동치이다.
$$ \exist N \in \N \quad s.t. \quad  N \le n \Rightarrow s(n) \in \forall\mathcal{N_x}$$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds p.26

### 참고1
$s(n)$이 $x$에 수렴한다는 말은, $s(n)$의 `극한(limit)`이 $x$라고도 한다.

### 참고2
$s(n)$이 $x$에 수렴한다는 다음과 같이 표기한다.
$$ s(n) \rightarrow x $$

또는 다음과 같이 표기한다.
$$ \lim_{i\rightarrow\infty} s(i) = x $$

### 명제1
metric space $M$이 있을 떄, 다음을 증명하여라.
$$\text{metric space convegence definition } \Leftrightarrow \text{topological space convegence definition} $$

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds exercise 2.12

### 명제2
Topological space $X$와 $a \in X$가 있다고 하자.

$X$위의 constant sequence $s=\{a,a,\cdots\}$가 있을 때, 다음을 증명하여라.
$$ s \text{ may not converge to } a $$

**Proof**

$X$가 다음과 같이 주어졌다고 하자.
$$ X = \{ 1,2,3 \}, \enspace \mathcal{T}_X = \{ \empty, \{ 1 \}, \{ 1,2 \}, \{ 1,2,3 \} \} $$

$X$위의 constant sequence $s = \{ 2,2,\cdots \}$가 있다고 하자.

$2 \in \forall\mathcal N_3$임으로 $s(n)$은 $3$에 수렴한다. $\qed$

### 명제3
Topological space $X$가 있다고 하자.

$X$위의 sequence $s$가 있을 때, 다음을 증명하여라.
$$ s \text{ may not converge to one point } $$

**Proof**

$X$가 다음과 같이 주어졌다고 하자.
$$ X = \{ 1,2,3 \}, \enspace \mathcal{T}_X = \{ \empty, \{ 1 \}, \{ 1,2 \}, \{ 1,2,3 \} \} $$

$X$위의 constant sequence $s = \{ 2,2,\cdots \}$가 있다고 하자.

$2 \in \forall\mathcal N_2$인 동시에 $2 \in \forall\mathcal N_3$임으로 $s(n)$은 $2,3$에 수렴한다. $\qed$

### 명제4
Trivial topology가 주어진 topological space $X$가 있다고 하자.

$X$위의 sequence $s$가 있을 때, 다음을 증명하여라.
$$ s \text{ is converge to every point on } X $$

**Proof**

$x \in X$라 하자.

$X$가 trivial topology를 갖음으로 다음이 성립한다.
$$ \mathcal N_x = X $$

$x$의 유일한 neighborhood가 $X$임으로, $s \in \mathcal N_x$이고 다음이 성립한다.
$$ s \text{ is converge to } x $$

임의의 $x \in X$에 대해 위가 성립함으로 $s$는 $X$위의 모든 점에 수렴한다. $\qed$

### 명제5
Topological space $X$와 $X$의 subset $U$가 있다고 하자.

$x \in X$가 있을 떄, 다음을 증명하여라.
$$  \exist\text{ sequence } s \text{ on } U \st \text{ converge to } x \implies x \in \bar{U} $$

**Proof**

$s$가 $x$에 converge함으로 어떤 $N \in \N$에 대해,  $s(N) \in U$가 다음을 만족한다.
$$ \begin{aligned} & \forall\mathcal{N_x}, \quad s(N) \in \mathcal{N_x} \\\implies& \forall\mathcal{N_x}, \quad U \cap \mathcal{N_x} \neq \empty \end{aligned} $$

Closure의 성질에 의해 다음이 성립한다.
$$ \forall\mathcal{N_x}, \quad U \cap \mathcal{N_x} \neq \empty \iff x \in \bar{U} \qed $$