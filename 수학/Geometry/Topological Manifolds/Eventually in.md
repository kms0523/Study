# Eventually in
Topological space $X$와 $X$의 subset $U$가 있다고 하자.

$X$위의 sequence $s$가 다음을 만족할 떄, $s$를 `eventually in` $U$라고 한다.
$$ \text{for all } i \text{ but finitely many values of } i, \quad s(i) \in U$$

> Reference
> [Book] (Lee) Introduction to Topological Manifolds p.36

### 참고
다음을 만족하는 sequence $s$를 eventually in $U$라고 한다.
$$ \exist N \in \N \st N \le n \implies s(n) \in U $$

> Reference
> [math.stackexchange](https://math.stackexchange.com/questions/2849974/sequences-eventually-and-frequently-in-a-set)

### 명제1
First countable space $X$와 $X$의 subset $U$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ x \in \Int(U) \iff \text{every sequence in } X \text{ convergeing to } x \text{ is eventually in } U $$

**Proof**

[$\implies$]
$x$로 수렴하는 $X$위의 sequence $s(n)$이 있다고 하자.

$s(n)$이 $x$로 수렴함으로, 수렴의 정의에 의해 다음이 성립한다.
$$ \forall\mathcal{N_x}, \quad \exist N \in \N \st N \le n \implies s(n) \in \mathcal{N_x} $$

이 떄, 전제에 의해 $x \in \Int(U)$이고 $\Int(U) \in \Set{\mathcal{N_x}}$임으로 다음이 성립한다.
$$ \exist N \in \N \st N \le n \implies s(n) \in \Int(U) $$

그리고 $\Int(U) \subseteq U$임으로, 다음이 성립한다.
$$ \exist N \in \N \st N \le n \implies s(n) \in U $$

따라서, $s(n)$은 eventually in $U$이다. $\qed$

[$\impliedby$]
$x \notin \Int(U)$라고 가정하자.

$X$가 first countable space임으로 다음이 성립한다.
$$ \forall x \in X, \quad \exist\text{nested neighborhood basis } \mathcal{B_x}(n) $$

$X$위의 sequence $s(n)$을 다음과 같이 정의하자.
$$ s(n) := \text{one of a point in } \mathcal{B_x}(n) - U$$

그러면 보조명제1.1에 의해 $\mathcal{B_x}(n) - U \neq \empty$임으로 $s(n)$은 잘 정의된다.

또한, 보조명제1.2에 의해 $s(n)$은 $x$로 수렴함으로 전제에 의해 eventually in $U$이다.

하지만$s(n)$의 정의상 $s(n) \in U^c$임으로, 이는 모순이다.

따라서 proof by contradiction에 의해 다음이 성립한다.
$$ x \in \Int(U) \qed $$

> Refernece
> [math.stackexchange](https://math.stackexchange.com/questions/1876224/x-first-countable-a-subseteq-x-x-in-x-then-x-in-textint-a-leftrig)

#### 보조명제 1.1
다음을 증명하여라.
$$ \mathcal{B_x}(n) - U \neq \empty $$

**Proof**

Interior의 성질에 의해 다음이 성립한다.
$$ x \notin \Int(U) \iff \nexists\mathcal{N_x} \st \mathcal{N_x} \subseteq U $$

$\mathcal{B_x}(n)$은 nested neighborhood basis임으로 다음이 성립한다.
$$ \begin{aligned} &\forall n \in \N, \quad \mathcal{B_x}(n) \in \Set{\mathcal{N_x}} \\ \implies& \forall n \in \N, \quad \mathcal{B_x}(n) - U \neq \empty \end{aligned} $$

#### 보조명제1.2
다음을 증명하여라.
$$ \lim_{i\rightarrow\infty} s(i) = x $$

**Proof**

$\mathcal{B_x}(n)$가 nested neighborhood basis임으로 임의의 $\mathcal{N_x}$가 주어졌을 떄, 다음이 성립한다.
$$ \exist j \in \N \st \mathcal{B_x}(j) \subseteq \mathcal{N_x} $$

$s(n)$의 정의에 의해  다음이 성립한다.
$$ \begin{aligned} &s(n) \in \mathcal{B_x}(n) \cap U^c \\\implies& s(n) \in \mathcal{B_x}(n) \land s(n) \in U^c \\\implies& s(n) \in \mathcal{B_x}(n) \end{aligned}  $$

$\mathcal{B_x}(n)$가 nested neighborhood basis임으로 $j \le n$에 대해 다음이 성립한다.
$$ \begin{aligned} & \mathcal{B_x}(n) \subseteq \mathcal{B_x}(j) \\\implies& s(n) \in \mathcal{B_x}(j) \\\implies& s(n) \in \mathcal{N_x}  \end{aligned} $$

따라서, convergence의 정의에 의해 $s(n)$은 $x$에 수렴한다.$\qed$














-