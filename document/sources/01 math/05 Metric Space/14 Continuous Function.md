# Continuous Function
## 정의
Metric space $M_1,M_2$가 있다고 하자.

$X$가 $M_1$의 open set일 때, 함수 $f : X \rightarrow M_2$가  `연속 함수(continuous function)`이라는 말은 다음과 동치이다.

$$ \forall x \in M_1, \quad f \text{ is continuous at } x $$

> Reference  
> {cite}`hubbard` Chapter 1.5

### 명제1
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

### 명제2
함수 $f$가 다음과 같이 주어졌다고 하자.

$$ f: \R^2 \rightarrow  \R \st x \mapsto x_1+x_2 $$

이 떄, 다음을 증명하여라.

$$ f \text{ is continuous} $$

**Proof**

$\R^2$의 임의의 element를 $x$라 하자.

$t \in \R^2$에 대해서, 다음이 성립한다.

$$ \begin{aligned} |f(x) - f(t)| &= |x_1 + x_2-(t_1+t_2)| \\&\le |x_1-t_1| + |x_2-t_2| \\&\le \sqrt{2}\sqrt{(x_1-t_1)^2 + (x_2-t_2)^2} \\&= \sqrt{2}\norm{x-t} \end{aligned} $$

따라서, 다음이 성립한다.

$$  \norm{x-t} < \delta \implies |f(x) - f(t)| < \sqrt{2}\delta $$

이 떄, $\delta$를 다음과 같이 정의하자

$$ \delta := \frac{\epsilon}{\sqrt{2}} $$

그러면 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \norm{x-t} < \delta \implies |f(x) - f(t)| < \epsilon $$

$f$는 임의의 점 $x$에서 continuous함으로 다음이 성립한다.

$$ f \text{ is continuous} \qed $$

### 명제3
함수 $f$가 다음과 같이 주어졌다고 하자.

$$ f: \R^2 \rightarrow  \R \st x \mapsto x_1x_2 $$

이 떄, 다음을 증명하여라.

$$ f \text{ is continuous} $$

**Proof**

$\R^2$의 임의의 element를 $x$라 하자.

$t \in \R^2$가 있을 떄, 다음이 성립한다.

$$ \begin{aligned} |f(x)-f(t)| &= |x_1x_2-t_1t_2| \\&= |(x_1-t_1)(x_2-t_2)+t_2(x_1-t_1)+t_1(x_2-t_2)| \\&\le |(x_1-t_1)(x_2-t_2)|+|t_2(x_1-t_1)|+|t_1(x_2-t_2)| \end{aligned} $$


보조명제3.1-3에 의해 다음이 성립한다.

$$  \norm{x-t} < \delta \implies |f(x) - f(t)| < \frac{\delta^2}{2} + (|t_1|+|t_2|)\delta $$

이 떄, $\delta$를 다음과 같이 정의하자.

$$ \delta := \min\left( \sqrt{\epsilon}, \frac{\epsilon}{2(|t_1| + |t_2|)} \right) $$

그러면 다음이 성립한다.

$$ \forall \epsilon \in \R^+, \quad \norm{x-t} < \delta \implies |f(x) - f(t)| < \epsilon $$


$f$는 임의의 점 $x$에서 continuous함으로 다음이 성립한다.

$$ f \text{ is continuous} \qed $$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/2136639/show-that-the-function-fx-y-xy-is-continuous)

#### 보조명제3.1
다음을 증명하여라.

$$ \norm{x-t} < \delta \implies|x_1-t_1| < \delta $$

**Proof**

$$ \begin{aligned} & (x_1-t_1)^2 < (x_1-t_1)^2 + (x_2-t_2)^2 < \delta^2 \\ \implies& |x_1-t_1| < \delta \qed  \end{aligned}  $$

#### 보조명제3.2
다음을 증명하여라.

$$ \norm{x-t} < \delta \implies|x_2-t_2| < \delta $$

**Proof**

$$ \begin{aligned} & (x_2-t_2)^2 < (x_1-t_1)^2 + (x_2-t_2)^2 < \delta^2 \\ \implies& |x_2-t_2| < \delta \qed  \end{aligned}  $$

#### 보조명제3.3
다음을 증명하여라.

$$ \norm{x-t} < \delta \implies|x_1-t_1||x_2-t_2| < \frac{\delta^2}{2} $$

**Proof**

$$ \begin{aligned} & 2\sqrt{(x_1-t_1)^2(x_2-t_2)^2} < (x_1-t_1)^2 + (x_2-t_2)^2 < \delta^2 \\ \implies& |x_1-t_1||x_2-t_2|< \frac{\delta^2}{2} \qed  \end{aligned}  $$