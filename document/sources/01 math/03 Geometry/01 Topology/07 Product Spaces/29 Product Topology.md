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
Set $\R^n$의 metric topology를 $\mathcal{T_M}$ product topology를 $\mathcal{T_P}$라할 때, 다음을 증명하여라.

$$ \mathcal{T_M} = \mathcal{T_P} $$

**Proof**

임의의 $x,y \in \R^n$에 대해, $\mathcal{T_P}$의 distance function이 다음과 같이 주어졌다고 하자.

$$ d_P(x,y) = \max_{i}{|x_i-y_i|} $$

[$\mathcal{T_M} \subseteq \mathcal{T_P}$]

$d_P$의 정의에 의해 다음이 성립한다.

$$ \exist m \in [1,n] \st d_P(x,y) = |x_m-y_m| $$

따라서, 다음이 성립한다.

$$ \begin{aligned} (d_P(x,y))^2 &= (x_m-y_m)^2 \\&\le \sum_{i=1}^n (x_i-y_i)^2 \\&= (d_M(x,y))^2 \end{aligned} $$

이 때, Distance function의 함수값은 항상 양수임으로 다음이 성립한다.

$$ d_P(x,y) \le d_M(x,y) $$

따라서, 다음이 성립한다.

$$ \begin{aligned} & \forall y \in B_M(x, \epsilon), \quad d_M(x,y) \le \epsilon \\\implies& \forall y \in B_M(x, \epsilon), \quad d_P(x,y) \le \epsilon \\\implies& \forall y \in B_M(x, \epsilon), \quad y \in B_P(x, \epsilon) \\\implies& B_M \subseteq B_P \end{aligned} $$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/2847214/topology-induced-by-eulidean-metric-is-the-same-as-product-topology)

### 예시
$\R$의 open set은 임의의 open interval이 된다.

따라서 $\R^2 = \R \times \R$의 product topology는 각각의 open interval을 두 변으로 하는 open rectangle 형태를 이룬다.

> Reference  
> {cite}`LeeTM`p.60
