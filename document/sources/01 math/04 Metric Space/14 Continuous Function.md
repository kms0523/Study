# Continuous Function
## 정의
Metric space $M_1,M_2$가 있다고 하자.

$X$가 $M_1$의 open set일 때, 함수 $f : X \rightarrow M_2$가  `연속 함수(continuous function)`이라는 말은 다음과 동치이다.

$$ \forall x \in M_1, \quad f \text{ is continuous at } x $$

> Reference  
> {cite}`hubbard` Chapter 1.5

### 명제
Metric space $M_1,M_2$가 있다고 하자.

$X$가 $M_1$의 open set이고 함수 $f : X \rightarrow M_2$가  있을 때, 다음을 증명하여라

$$ f \text{ is a continuous function } \iff \text{preimage of every open subset is open} $$

**Proof**

[$\implies$]  
$M_2$의 임의의 open set을 $V$라 하면, open set의 성질에 의해 다음이 성립한다.

$$ \forall x \in \preimg(V), \quad \exist r \in \R^+ \st B_{M_2}(f(x),r) \subseteq V $$

그러면 전제에 의해 다음이 성립한다.

$$ \begin{aligned} & \forall x \in \preimg(V), \quad \exist\delta \in \R^+ \st B_{M_1}(x,\delta) \subseteq \preimg(B_{M_2}(y,r)) \subseteq \preimg(V) \\ \implies& \preimg(V) \text{ is an open set of } M_1 \qed  \end{aligned}  $$

[$\impliedby$]  
$M_1$의 임의의 원소를 $x$라고 하자.

그러면 open ball의 성질에 의해 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad B_{M_2}(f(x),\epsilon) \text{ is an open set of } M_2 $$

이 때, 전제에 의해 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \preimg(B_{M_2}(f(x),\epsilon)) \text{ is an open set of } M_1 $$

따라서, open set의 성질에 의해 다음이 성립한다.

$$ \forall p \in \preimg(B_{M_2}(f(x), \epsilon)), \quad \exist\delta \in \R^+ \st B_{M_1}(p,\delta) \subseteq \preimg(B_{M_2}(f(x), \epsilon)) $$

이 때, $x \in \preimg(B_{M_2}(f(x),\epsilon))$임으로 다음이 성립한다.

$$ \begin{aligned} & \forall \epsilon \in \R^+, \quad \exist\delta \in \R^+ \st  B_{M_1}(x,\delta) \subseteq \preimg(B_{M_2}(f(x),\epsilon)) \\ \iff& f \text{ is continuous at } x \end{aligned} $$

$M_1$의 임의의 원소에서 $f$가 연속임으로 다음이 성립한다.

$$ f \text{ is continous function } \qed $$

> Reference  
> {cite}`LeeTM` p.399