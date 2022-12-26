# Product Topology
## 정의
Topological space $X_1, \cdots, X_n$이 있다고 하자.

Catesian product를 이용해 다음과 같은 집합을 정의하자.

$$ \prod_{i=1}^n X_i := X_1 \times\cdots\times X_n $$

이 때, 집합 $\prod_{i=1}^n X_i$의 부분집합 $\mathcal{B}$를 다음과 같이 정의하자.

$$ \mathcal{B} := \Set{\prod_{i=1}^n U_i | U_i \text{ is an open set of } X_i, i=1,\cdots,n} $$

$\mathcal{B}$에 의해 생성된 $\prod_{i=1}^n X_i$의 topology를 `product topology`라고 한다.

### 명제1
Topological space $X_1, \cdots, X_n$이 있다고 하자.

이 때, 집합 $\prod_{i=1}^n X_i$의 부분집합 $\mathcal{B}$를 다음과 같이 정의하자.

$$ \mathcal{B} := \Set{\prod_{i=1}^n U_i | U_i \text{ is an open set of } X_i, i=1,\cdots,n} $$

이 때, 다음을 증명하여라

$$\mathcal{B} \text{ is a basis for some topology on } \prod_{i=1}^n X_i $$

**Proof**

[$\bigcup\mathcal{B} = \prod_{i=1}^n X_i$]  
Topology의 성질에 의해 다음이 성립한다.

$$ \bigcup\mathcal{T_{X_i}} = X_i $$

따라서, $\mathcal{B}$의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} \bigcup\mathcal{B} &= \bigcup\Set{\prod_{i=1}^n U_i | U_i \text{ is an open set of } X_i, i=1,\cdots,n} \\&= \prod_{i=1}^n \left(\bigcup \Set{U_i | U_i \text{ is an open set of } X_i}\right) \\&= \prod_{i=1}^n \left(\bigcup\mathcal{T_{X_i}}\right) \\&= \prod_{i=1}^n X_i \qed \end{aligned} $$

[$B_1, B_2 \in \mathcal{B} \implies \forall x \in B_1 \cap B_2, \quad \exist B \in \mathcal{B} \quad s.t. \quad x \in B \subseteq B_1 \cap B_2 $]  
$B_1,B_2 \in \mathcal{B}$를 다음과 같이 정의하자.

$$ B_i := \prod_{j=1}^n U_j^i, i=1,2 $$

그러면 다음이 성립한다.

$$ \forall x\in B_1 \cap B_2, \quad x \in \prod_{i=1}^n (U^1_i \cap U^2_i) $$

$U^1_i, U^2_i, i=1\cdots,n$이 $X_i$의 open set임으로 open set의 성질에 의해 다음이 성립한다.

$$ U_i^1 \cap U_i^j \text{ is open set of } X_i, i=1,\cdots,n $$

따라서, $\mathcal{B}$의 정의에 의해 다음이 성립한다.

$$ \exist B \in \mathcal{B} \st B = \prod_{i=1}^n (U^1_i \cap U^2_i) $$

위의 결과를 종합하면 다음과 같다.

$$ B_1, B_2 \in \mathcal{B} \implies \forall x \in B_1 \cap B_2, \quad \exist B \in \mathcal{B} \quad s.t. \quad x \in B \subseteq B_1 \cap B_2 \qed $$

[결론]  
$\mathcal{B}$가 위의 두 성질을 만족함으로 basis의 성질에 의해, 다음이 성립한다. 

$$\mathcal{B} \text{ is a basis for some topology on } \prod_{i=1}^n X_i \qed $$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/1714574/basis-for-a-topology-that-we-will-call-the-product-topology)

### 명제2
Metric space $\R^n$의 Euclidean topology를 $\mathcal{T_E}$ product topology를 $\mathcal{T_P}$라할 때, 다음을 증명하여라.

$$ \mathcal{T_E} = \mathcal{T_P} $$

**Proof**

Basis의 성질에 의해, metric space의 open ball collection은 basis이다.

Euclidean topology와 product topology에 의한 open ball collcection을 각 각 $\mathcal{B_E}, \mathcal{B_P}$라고 하자.

[$\mathcal{T_P} \subseteq \mathcal{T_E}$]
임의의 $x \in \R^n$과 $x$를 포함하는 임의의 product topology의 open ball $B_p \in \mathcal{B_P}$가 있을 때, 보조명제2.1에 의해 다음이 성립한다.

$$ \exist B_E \in \mathcal{B_E} \st x \in B_E \subseteq B_P $$

그러면, Basis의 성질에 의해 다음이 성립한다.

$$ \mathcal{T_P} \subseteq \mathcal{T_E} \qed $$

[$\mathcal{T_E} \subseteq \mathcal{T_P}$]  
임의의 $x \in \R^n$과 $x$를 포함하는 임의의 open ball $B_E \in \mathcal{B_E}$가 있을 때, 보조명제2.2에 의해 다음이 성립한다.

$$ \exist B_P \in \mathcal{B_P} \st x \in B_P \subseteq B_E $$

그러면, Basis의 성질에 의해 다음이 성립한다.

$$ \mathcal{T_E} \subseteq \mathcal{T_P} \qed $$


> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/2847214/topology-induced-by-eulidean-metric-is-the-same-as-product-topology)  

#### 보조명제2.1
다음을 증명하여라.

$$ \exist B_E \in \mathcal{B_E} \st x \in B_E \subseteq B_P $$

**Proof**

임의의 $x,y \in \R^n$에 대해, $\mathcal{T_P}$의 distance function이 다음과 같이 주어졌다고 하자.

$$ d_P(x,y) = \max_{i}{|x_i-y_i|} $$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/755586/product-topology-and-standard-euclidean-topology-over-mathbbrn-are-equival)

$d_P$의 정의에 의해 다음이 성립한다.

$$ \exist m \in [1,n] \st d_P(x,y) = |x_m-y_m| $$

Distance function의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} (d_P(x,y))^2 &= (x_m-y_m)^2 \\&\le \sum_{i=1}^n (x_i-y_i)^2 \\&= (d_E(x,y))^2 \end{aligned} $$

이 때, Distance function의 함수값은 항상 양수임으로 다음이 성립한다.

$$ d_P(x,y) \le d_E(x,y) $$

따라서, 다음이 성립한다.

$$ \begin{aligned} & \forall y \in B_E(x, \epsilon), \quad d_E(x,y) \le \epsilon \\\implies& \forall y \in B_E(x, \epsilon), \quad d_P(x,y) \le \epsilon \\\implies& \forall y \in B_E(x, \epsilon), \quad y \in B_P(x, \epsilon) \\\implies& B_E \subseteq B_P \end{aligned} $$

따라서, 다음이 성립한다.

$$ \exist B_E \in \mathcal{B_E} \st x \in B_E \subseteq B_P \qed $$

#### 보조명제 2.2
다음을 증명하여라.

$$ \exist B_P \in \mathcal{B_P} \st x \in B_P \subseteq B_E $$

**Proof**

임의의 $x,y \in \R^n$에 대해, $\mathcal{T_P}$의 distance function이 다음과 같이 주어졌다고 하자.

$$ d_P(x,y) = \max_{i}{|x_i-y_i|} $$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/755586/product-topology-and-standard-euclidean-topology-over-mathbbrn-are-equival)

$d_P$의 정의에 의해 다음이 성립한다.

$$ \exist m \in [1,n] \st d_P(x,y) = |x_m-y_m| $$

Distance function의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} (d_E(x,y))^2 &= \sum_{i=1}^n (x_i-y_i)^2 \\&\le n(x_m-y_m)^2 \\&= n(d_P(x,y))^2 \end{aligned} $$

이 떄, distance function의 함수값은 항상 양수임으로 다음이 성립한다.

$$ d_E(x,y) \le \sqrt{n}d_P(x,y) $$

따라서, 다음이 성립한다.

$$ \begin{aligned} & \forall y \in B_P(x, \frac{\epsilon}{\sqrt{n}}), \quad d_P(x,y) \le \frac{\epsilon}{\sqrt{n}} \\\implies& \forall y \in B_P(x, \frac{\epsilon}{\sqrt{n}}), \quad d_E(x,y) \le \epsilon \\\implies& \forall y \in B_P(x, \frac{\epsilon}{\sqrt{n}}), \quad y \in B_E(x, \epsilon) \\\implies& B_P \subseteq B_E \end{aligned} $$

따라서, 다음이 성립한다.

$$ \exist B_P \in \mathcal{B_P} \st x \in B_P \subseteq B_E \qed $$


### 예시
$\R$의 open set은 임의의 open interval이 된다.

따라서 $\R^2 = \R \times \R$의 product topology는 각각의 open interval을 두 변으로 하는 open rectangle 형태를 이룬다.

> Reference  
> {cite}`LeeTM`p.60
