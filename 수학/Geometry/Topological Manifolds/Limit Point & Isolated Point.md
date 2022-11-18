# Limit Point
Topological space $X$와 $X$의 subset $U$가 있다고 하자.

$x \in X$가 다음을 만족할 경우, $x$를 $U$의 `limit point`라고 한다.
$$ \forall \mathcal{N_x}, \quad \mathcal{N_x} \text{ contians a point of } U \text{ other than } x $$

### 참고1
$x \in X$이기 때문에 $x$는 $U$에 원소일수도 있고 아닐 수도 있다.

### 참고2
limit points는 `accumulation points` 또는 `cluster points`라고 부르기도 한다.

### 명제1
Topological space $X$와 $X$의 subset $U$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ U \text{ is closed} \iff U \text{ contains all of its limit points} $$

**Proof**
[$\implies$]
$x \in X$가 $U$의 limit point라고 할 때, 다음을 가정하자.
$$ x \notin U $$

$U$가 $X$의 closed set이고 $x \notin U$임으로, 다음이 성립한다.
$$ X-U \text{ is open set of } X \land x \in X-U $$

이 때, $x$가 $U$의 limit point임으로 다음이 성립한다.
$$ U \cap (X-U) \text{ contains a point of } U \text{ other than }x $$

이는 모순임으로, proof by contradiction에 의해 $x \in U$이다.

[$\impliedby$]
다음을 가정하자.
$$ X-U \text{ is not a open set of } X $$

그러면 다음이 성립한다.
$$ \begin{aligned} & \exist x \in X-U \st \forall\mathcal{N_x}, \quad \mathcal{N_x} \nsubseteq X-U \\\iff& \exist x \in X-U \st \forall\mathcal{N_x}, \quad \mathcal{N_x} \cap U \neq \empty \end{aligned} $$

이 떄, $x \in X-U$임으로 다음이 성립한다.
$$ \begin{aligned} & \forall\mathcal{N_x}, \quad \mathcal{N_x} \cap U \text{ contains a point of } U \text{ other than } x \\\iff& x \text{ is a limit point of } U  \end{aligned} $$

하지만 이는, $U$의 모든 limit point가 $U$에 포함된다는 전제에 모순이 된다.

따라서, proof by contradiction에 의해 다음이 성립한다.
$$ X-U \text{ is an open set of } X $$

그럼으로 $U$는 $X$의 closed set이다. $\qed$

> Reference
> [math.stackexchange](https://math.stackexchange.com/questions/162018/accumulation-points-cluster-points-closed-sets?rq=1)

# Isolated Point
Topological space $X$와 $X$의 subset $U$가 있다고 하자.

$x \in U$가 다음을 만족할 경우, $x$를 $U$의 `isolated point`라고 한다.
$$ \exist\mathcal{N_x} \st U \cap \mathcal{N_x} = \{x\} $$

### 명제1
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을떄, 다음을 증명하여라.
$$ x \in U \implies x \text{ is limit point or isolated point of } U $$

**Proof**

임의의 $\mathcal{N_x}$에 대해 다음이 성립한다.
$$ x \in \mathcal{N_x} $$

따라서, $\mathcal{N_x}$에 $x$외의 $U$의 원소가 없는 경우 isolated point가 되며 원소가 있는 경우, limit point가 된다.$\qed$