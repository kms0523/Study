# Locally Euclidean
## 정의
Topological space $X$가 있다고 하자.

이 때, $X$가 다음을 만족할 경우, $X$가 `locally Euclidean` of dimension $n$이라고 한다.

$$ \forall x \in X, \quad \exist\mathcal{N_x} \in \Set{\mathcal{N_x}} \st \text{homeomorphic to an open subset of } \R^n $$

### 명제1
Topological space $X$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ X \text{ is locally Euclidean of dimension } n \iff \forall x \in X, \quad \exist\mathcal{N_x} \in \Set{\mathcal{N_x}} \st \text{homeomorphic to an open ball of } \R^n $$

**Proof**

[$\implies$]  
전제에 의해 다음이 성립한다.

$$ \forall x \in X, \quad \exist \mathcal{N_x} \in \Set{\mathcal{N_x}}, V \in \mathcal{T}_{\R^n} \st \mathcal{N_x} \text{ and } V \text{ are homeomorphic } $$

$\mathcal{N_x}$와 $V$ 사이의 homeomorphism을 $\phi: \mathcal{N_x} \rightarrow V$라 하자.

이 떄, $V$가 $\R^n$의 open set임으로 다음이 성립한다.

$$ \exist r \st B_{\R^n}(\phi(x),r) \subseteq V $$

위를 만족하는 open ball을 $B$라고 할 때, 보조명제1.1에 의해 다음이 성립한다.

$$ \preimg(B) \in \Set{\mathcal{N_x}} $$

따라서, $\preimg(B)$는 $X$의 open set임으로 homeomorphism의 성질에 의해 다음이 성립한다.

$$ \phi|_{\preimg(B) \times B} \text{ is a homeomorphism} $$

따라서 이를 정리하면 다음과 같다.

$$ \forall x \in X, \quad \exist\mathcal{N_x} \in \Set{\mathcal{N_x}} \st \text{homeomorphic to an open ball of } \R^n \qed $$

[$\impliedby$]  
open ball은 open set임으로 locally Euclidean의 정의에 의해 다음이 성립한다.

$$ X \text{ is locally Euclidean of dimension } n \qed $$

#### 보조명제1.1
다음을 증명하여라.

$$ \preimg(B) \in \Set{\mathcal{N_x}} $$

**Proof**

$B$는 $\R^n$의 open set임으로 subspace의 정의에 의해 다음이 성립한다.

$$ B \text{ is open set of } V $$

$\phi$가 continuous 함으로 다음이 성립한다.

$$ \text{Preimage of every open set of } V \text{ is open set of } \mathcal{N_x} $$

따라서, 다음이 성립한다.

$$ \preimg(B) \text{ is open set of } \mathcal{N_x} $$

$\mathcal{N_x}$는 $X$의 open set임으로 subspace의 성질에 의해 다음이 성립한다.

$$ \preimg(B) \text{ is open set of } X $$

따라서, Neighborhood의 정의에 의해 다음이 성립한다.

$$ \preimg(B) \in \Set{\mathcal{N_x}} \qed $$

### 명제2
Topological space $X$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ X \text{ is locally Euclidean of dimension } n \iff \forall x \in X, \quad \exist\mathcal{N_x} \in \Set{\mathcal{N_x}} \st \text{homeomorphic to } \R^n $$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/1072741/is-an-open-n-ball-homeomorphic-to-mathbbrn)