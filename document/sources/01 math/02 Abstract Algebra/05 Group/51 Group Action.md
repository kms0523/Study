# Group Action
Group $G$와 set $X$가 있다고 하자.

## Left Group Action
$G$의 $X$위의 왼쪽 군 작용(left group action of $G$ on $S$) $\cdot$는 다음 조건들을 만족시키는 함수다.

$$ \cdot : G \times X \rightarrow X \st \begin{array}{ll} \text{compatability} &  \forall g_1,g_2 \in G, \quad \forall x \in X, \quad g_1 \cdot (g_2 \cdot s) = (g_1 g_2) \cdot x \\ \text{identity} & \forall x \in X, \quad e_G \cdot x = x \end{array} $$

### 참고1
$G$의 $X$위의 왼쪽 군 작용이 정의되어 있는 경우 "$G$가 $X$에 왼쪽에서 작용한다"라고 얘기하고 $G \curvearrowright X$로 표기한다.

### 참고2
작용을 받는 set $X$를 $G$-set이라고 한다.

### 명제1
Group $G$와 set $X$가 있다고 하자.

$G \curvearrowright X$일 때 다음을 증명하여라.

$$ \forall g \in G, \enspace \sigma_g : X \rightarrow X \st x \mapsto g \cdot x \text{ is bijective} $$

**Proof**

[injective]  
$X$의 임의의 element를 $x,y$라고 하면 다음이 성립한다.

$$ \begin{aligned} & \sigma_g(x) = \sigma_g(y) \\\implies& g\cdot x = g \cdot y \\\implies& g^{-1} \cdot g\cdot x = g^{-1} \cdot g \cdot y \\\implies& x = y \qed \end{aligned} $$

[surjective]  
$X$의 임의의 element를 $x$라고 하자.

$g^{-1}\cdot x \in X$이고 $\sigma_g(g^{-1}x) = g \cdot g^{-1}\cdot x = x$ 임으로 다음이 성립한다.

$$ \exist y \in X \st \sigma_g(y) = x \qed $$

## Right Group Action
$G$의 $S$위의 오른쪽 군 작용(right group action of $G$ on $S$) $+$는 다음 조건들을 만족시키는 binary operation이다.

$$ + : S \times R \rightarrow S \st \begin{array}{ll} \text{compatability}& \forall g_1,g_2 \in G, \quad \forall s \in S, \quad s + (g_1 + g_2) = (s + g_1) + g_2 \\ \text{identity}& \forall s \in S, \quad s + 0_R = s \end{array} $$

> Referemce  
> [wiki](https://en.wikipedia.org/wiki/Group_action)