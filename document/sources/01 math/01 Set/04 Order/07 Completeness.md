# Completeness
## 정의
POSET $X$가 있다고 하자.

$X$의 임의의 nonempty bounded above subset $U$가 supremum을 갖을 경우 $X$를 `complete` 하다고 한다.

> Reference  
> [wiki](https://en.wikipedia.org/wiki/Completeness_(order_theory))


### 명제1
Complete POSET $X$가 있다고 하자.

$X$의 bounded below subset $U$가 있을 때, 다음을 증명하여라.

$$ \exist! \inf(U) $$

**Proof**

Set $Y$를 다음과 같이 정의하자.

$$ Y := \Set{x \in X | x \text{ is a lower bound of } U} $$

$U$가 bounded below임으로 다음이 성립한다.

$$ Y \text{ is nonempty} $$

$Y$의 정의에 의해 다음이 성립한다.

$$ \forall u \in U, \quad u \text{ is an upper bound of } Y \implies Y \text{ is bounded above subset of } X $$

$X$의 completeness에 의해 다음이 성립한다.

$$ \exist \sup(Y) $$

그러면 supremum의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} & \forall u \in U, \quad \sup(Y) \le u \\ \implies& \sup(Y)\text{ is lower bound of } U \\ \implies& \sup(Y) \in Y \end{aligned} $$

따라서, supremum의 성질에 의해 다음이 성립한다.

$$ \sup(Y) \text{ is an greatest element of Y} $$

그러면 infimum의 정의에 의해 다음이 성립한다.

$$ \inf(X) = \sup(Y) $$

$\sup(Y)$가 유일하게 존재함으로 $\inf(X)$도 유일하게 존재한다. $\qed$

> Reference  
> {cite}`abbott` Exercise 1.3.3

#### 참고
따라서, Supremum 대신 infimum을 갖는다고 정의해도 동일하다.
