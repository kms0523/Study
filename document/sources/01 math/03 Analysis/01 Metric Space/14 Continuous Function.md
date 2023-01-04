# Continuous Function
open subsset $X \subset \R^n$과 함수 $\mathbf f : X \rightarrow \R^m$이 있다고 하자.

$f$가 `연속 함수(continuous function)`라는 말은 다음과 동치이다.

$$ \forall \mathbf x \in X, \quad f \text { is continuous at } \mathbf x $$

> Reference  
> {cite}`hubbard` Chapter 1.5

### 명제
metric spaces $(M_1,d_1),$ $(M_2,d_2)$와 함수 $f : M_1 \rightarrow M_2$가 있다고 하자.

이 때, 다음을 증명하여라

$$ f \text{ is a continuous function } \iff \text{preimage of every open subset is open} $$

**Proof**

[$\implies$]  
$U$가 $M_2$의 open set이라 하자.

$x \in \preimg(U)$면 $U$가 open set임으로 다음이 성립한다.

$$ \exist r \in \R^+  \st B_{M_2}(f(x),r) \subseteq U $$

이 때, $f$가 continuous임으로 다음이 성립한다.

$$ \forall \epsilon > 0, \quad \exist\delta \st y \in  B_{M_1}(x,\delta) \implies f(y) \in B_{M_2}(f(x),\epsilon) $$

따라서, 위를 만족하는 $\delta$에 대해 다음이 성립한다.

$$ \forall y \in  B_{M_1}(x,\delta), \quad f(y) \in U $$

그럼으로, 다음이 성립한다.

$$  B_{M_1}(x,\delta) \subseteq \preimg(U) $$

임의의 $x$에서 $\preimg(U)$에 속하는 ball이 존재함으로, open set의 성질에 의해 다음이 성립한다.

$$\preimg(U) \text{ is open set of } M_1 \qed $$

[$\impliedby$]  
$x_0 \in M_1$이라 하자.

open ball의 정의에 의해 다음이 성립한다.

$$ \forall \epsilon \in \R^+,\quad  B_{M_2}(f(x_0),\epsilon) \text{ is an open set of } M_2$$

그러면 가정에 의해, 다음이 성립한다.

$$\preimg(B_{M_2}(f(x_0), \epsilon)) \text{ is an open set of } M_1$$

따라서, open set의 성질에 의해 다음이 성립한다.

$$ \forall x \in \preimg(B_{M_2}(f(x_0), \epsilon)), \quad \exist\delta \in \R^+ \st B_{M_1}(x,\delta) \subseteq \preimg(B_{M_2}(f(x_0), \epsilon)) $$

이 떄, $x_0 \in \preimg(B_{M_2}(f(x_0), \epsilon))$ 임으로 다음이 성립한다.

$$ \exist\delta \in \R^+ \st \forall x \in B_{M_1}(x_0,\delta), \quad f(x) \in B_{M_2}(f(x_0),\epsilon) $$

이를 조합하면 다음이 성립힌다.

$$ \forall \epsilon \in \R^+, \quad \exist \delta \in \R^+ \st x \in B_{M_1}(x_0,\delta) \implies f(x) \in B_{M_2}(f(x_0),\epsilon) $$

따라서, continous의 정의에 의해 다음이 성립한다.

$$ f \text{ is continous at } x_0 $$

$x_0$는 $M_1$의 임의의 원소임으로 continuous function의 정의에 의해 다음이 성립한다.

$$ f \text{ is continous function } \qed $$

> Reference  
> {cite}`LeeTM` p.399