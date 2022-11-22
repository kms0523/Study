# First Countable
Topological space $X$가 있다고 하자.

$X$가 다음을 만족할 때, $X$가 `first countable`하다고 한다.
$$ \forall x \in X, \quad \exist\text{ countable neighborhood basis} $$

### 명제1
다음을 증명하여라.
$$ \text{Every metric space is first countable.} $$

**Proof**

Metric space $M$이 있다고 하자.

$x \in M$이 있을 때, collection $\mathcal{B_x}$를 다음과 같이 정의하자.
$$ \mathcal{B_x} := \{ B_M(x,1/r) \enspace|\enspace r \in \N \} $$

Metric space에서 open ball은 open set임으로 $\mathcal{B_x}$의 원소는 $\mathcal{N_x}$이다.

Neighborhood의 정의에 의해 임의의 $\mathcal{N_x}$에 대해서 다음이 성립한다.
$$ \exist\epsilon \in \R^+ \quad s.t \quad B_M(x,\epsilon) \subseteq \mathcal{N_x} $$

자연수의 성질에 의해 다음이 성립한다.
$$ \exist r \quad s.t. \quad B_M(x,1/r) \subseteq B_M(x,\epsilon) $$

따라서, 다음이 성립한다.
$$ \exist B \in \mathcal{B_x} \quad s.t. \quad B \subseteq \mathcal{N_x} $$

Neighborhood basis의 정의에 의해 $\mathcal{B_x}$ neighborhood basis이며, 정의에 의해 countable하다.

따라서, $\forall x\in M$마다 countable neighborhood basis가 존재함으로 first countable의 정의에 의해 $M$은 first countable하다. $\quad\tiny\blacksquare$

> Reference  
> [Proofwiki](https://proofwiki.org/wiki/Metric_Space_is_First-Countable)

### 명제2
First countable space $X$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ \forall x \in X, \quad \exist\text{ a nested neighborhood basis at } x $$

**Proof**

$x \in X$가 있다고 하자.

$X$가 first countable space이기 때문에 $x$에서 $X$의 countable neighborhood basis를 $\mathcal{B_x} = \{ B_N|N\in\N \}$라 하자.

이 떄, sequence $\mathcal{B_x}(n)$을 다음과 같이 정의하자.
$$ \mathcal{B_x}(n) := \bigcap_{i=1}^n B_i $$

$\mathcal{B_x}(n)$의 정의에 의해 다음이 성립한다.
$$ \mathcal{B_x}(n+1) \subseteq \mathcal{B_x}(n) $$

$\mathcal{B_x}$가 neighborhood basis이기 때문에 다음이 성립한다.
$$ \forall \mathcal{N_x}, \quad \exist i \in \N \quad s.t. \quad B_i \subseteq \mathcal{N_x} $$

따라서, 다음이 성립한다.
$$ \forall \mathcal{N_x}, \quad \exist i \in \N \quad s.t. \quad \mathcal{B_x}(i) \subseteq \mathcal{N_x} $$

Nested neighborhood basis의 정의에 의해 $\mathcal{B_x}(n)$은 nested neighborhood basis이다. $\qed$

### 명제3
First countable space $X$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$  \exist\text{ sequence } s \text{ on } U \st \text{ converge to } x \iff x \in \bar{U} $$

**Proof**
[$\implies$]
convergence의 성질에 의해 성립한다.

[$\impliedby$]
$X$가 first countable space임으로 명제2에 의해 다음이 성립한다.
$$ \exist\text{nested neighborhood basis } \mathcal{B_x}(n) $$

$U$위의 sequence $s(n)$을 다음과 같이 정의하자.
$$ s(n) := \text{one of a point in } \mathcal{B_x}(n) \cap U$$

보조명제 3.1에 의해 $\mathcal{B_x}(n) \cap U \neq \empty$임으로, 위의 수열은 잘 정의된다.

$\mathcal{B_x}(n)$가 nested neighborhood basis임으로 임의의 $\mathcal{N_x}$가 주어졌을 떄, 다음이 성립한다.
$$ \exist j \in \N \st \mathcal{B_x}(j) \subseteq \mathcal{N_x} $$

$s(n)$의 정의에 의해  다음이 성립한다.
$$ \begin{aligned} &s(n) \in \mathcal{B_x}(n) \cap U \\\implies& s(n) \in \mathcal{B_x}(n) \land s(n) \in U \\\implies& s(n) \in \mathcal{B_x}(n) \end{aligned}  $$

$\mathcal{B_x}(n)$가 nested neighborhood basis임으로 $j \le n$에 대해 다음이 성립한다.
$$ \begin{aligned} & \mathcal{B_x}(n) \subseteq \mathcal{B_x}(j) \\\implies& s(n) \in \mathcal{B_x}(j) \\\implies& s(n) \in \mathcal{N_x}  \end{aligned} $$

따라서, convergence의 정의에 의해 $s(n)$은 $x$에 수렴한다.$\qed$


#### 보조명제 3.1
다음을 증명하여라.
$$ \mathcal{B_x}(n) \cap U \neq \empty $$


**Proof**

$x \in \bar{U}$임으로 다음이 성립한다.
$$ \forall\mathcal{N_x}, \quad \mathcal{N_x} \cap U \neq \empty $$

$\mathcal{B_x}(n) \in \Set{\mathcal{N_x}}$임으로 다음이 성립한다.
$$ \forall n \in \N, \quad \mathcal{B_x}(n) \cap U \neq \empty \qed $$

> Reference
> [proofwiki](https://proofwiki.org/wiki/Sequence_Lemma)

### 명제4
First countable space $X$와 $X$의 subset $U$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ U \text{ is closed set of } X \iff \begin{gathered} U\text{ contains every limit of} \\ \text{every convergent sequence of points in } U \end{gathered}  $$

**Proof**

[$\implies$]
$x \in X$가 있을 떄, $x$로 수렴하는 $U$위의 convergent sequence $s(n)$이 있다고 하자.
$$ \lim_{i\rightarrow\infty}s(i)=x $$

Convergence의 정의에 의해 다음이 성립한다.
$$ \forall\mathcal{N_x}, \quad \exist N \in \N \st N \le n \implies s(n) \in \mathcal{N_x} $$

따라서, $N \le n$에 대해서 다음이 성립한다.
$$ s(n) \in U \cap \mathcal{N_x} $$

이 떄, 다음을 가정하자.
$$ x \notin U $$

전제에 의해 $U = \bar{U}$임으로, closure의 성질에 의해 다음이 성립한다.
$$ x \notin U \iff \exist\mathcal{N_x} \st \mathcal{N_x} \cap U = \empty $$

이는 $\forall\mathcal{N_x}$에 대해 $N \le n$일 떄, $s(n) \in U \cap \mathcal{N_x}$이라는 사실에 모순된다.

따라서, proof by contradiction에 의해 다음이 성립한다.
$$ x \in U $$

[$\impliedby$]
다음을 가정하자.
$$ U \text{ is not a closed set of } X $$

그러면 $X-U$가 open set이 아님으로, open set의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} & \exist x \in X-U \st \forall\mathcal{N_x}, \quad \mathcal{N_x} \nsubseteq X-U \\\iff& \exist x \in X-U \st \forall\mathcal{N_x}, \quad \mathcal{N_x} \cap U \neq \empty \end{aligned} $$

위를 만족하는 $x \in X-U$에 대해서, $X$가 first countable space임으로 다음이 성립한다.
$$ \exist\text{nested neighborhood basis } \mathcal{B_x}(n) $$

$U$위의 sequence $s(n)$을 다음과 같이 정의하자.
$$ s(n) = \text{one of a point in } \mathcal{B_x}(n) \cap U $$

보조명제4.1에 의해 $\mathcal{B_x}(n) \cap U \neq \empty$임으로 $s(n)$은 정의 될 수 있다.

보조명제4.2에 의해 $\lim_{i\rightarrow\infty} s(i) = x$임으로 전제에 의해, $x \in U$이다.

하지만 이는 $x \in X-U$라는 사실에 모순된다.

따라서, proof by contradiction에 의해 다음이 성립한다.
$$ U \text{ is a closed set of } X \qed $$

> Reference
> [math.stackexchange](https://math.stackexchange.com/questions/3002079/what-is-the-proof-that-first-countable-is-sufficient-to-say-that-sequentially-cl)


#### 보조명제4.1
다음을 증명하여라.
$$\mathcal{B_x}(n) \cap U \neq \empty$$

**Proof**

Nested neighborhood basis의 성질에 의해 다음이 성립한다.
$$ \forall n \in \N, \quad \mathcal{B_x}(n) \in \Set{\mathcal{N_x}} $$

따라서, $x$의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} & \forall\mathcal{N_x}, \quad \mathcal{N_x} \cap U \neq \empty \\\iff& \forall n \in \N, \quad \mathcal{B_x}(n) \cap U \neq \empty \qed \end{aligned} $$

#### 보조명제4.2
다음을 증명하여라.
$$ \lim_{i\rightarrow\infty} s(i) = x $$

**Proof**

$\mathcal{B_x}(n)$가 nested neighborhood basis임으로 임의의 $\mathcal{N_x}$가 주어졌을 떄, 다음이 성립한다.
$$ \exist j \in \N \st \mathcal{B_x}(j) \subseteq \mathcal{N_x} $$

$s(n)$의 정의에 의해  다음이 성립한다.
$$ \begin{aligned} &s(n) \in \mathcal{B_x}(n) \cap U \\\implies& s(n) \in \mathcal{B_x}(n) \land s(n) \in U \\\implies& s(n) \in \mathcal{B_x}(n) \end{aligned}  $$

$\mathcal{B_x}(n)$가 nested neighborhood basis임으로 $j \le n$에 대해 다음이 성립한다.
$$ \begin{aligned} & \mathcal{B_x}(n) \subseteq \mathcal{B_x}(j) \\\implies& s(n) \in \mathcal{B_x}(j) \\\implies& s(n) \in \mathcal{N_x}  \end{aligned} $$

따라서, convergence의 정의에 의해 $s(n)$은 $x$에 수렴한다.$\qed$

#### 참고1
$U$가 다음을 만족할 때, $U$를 sequentially closed set이라고 한다.
$$ U\text{ contains every limit of every convergent sequence of points in } U $$

> Reference
> [math.stackexchange](https://math.stackexchange.com/questions/1912653/a-subset-of-a-topological-space-is-closed-iff-it-contains-all-its-limit-points)

#### 참고2
$X$가 first countable space가 아니더라도 closed set은 sequentially closed set이지만 그 역은 성립하지 않는다.

> Reference
> [math.stackexchange](https://math.stackexchange.com/questions/2940442/why-closed-implies-sequentially-closed-but-not-the-converse)




-
