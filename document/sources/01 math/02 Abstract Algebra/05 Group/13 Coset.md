# Coset
## Left Coset
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $a$라고 할 때, $a$가 속하는 $H$의 `좌잉여류(left coset)` $aH$는 다음과 같이 정의된 집합이다.

$$ aH = \Set{a*h | h \in H} $$

그리고 $G/H$는 다음과 같이 정의된 집합이다.

$$ G/H = \Set{aH | a \in G} $$

즉, 모든 left coset의 집합이다.

> Reference  
> [2!=2 blog](https://chocobear.tistory.com/127)

### 명제1
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $g_1,g_2$라고 할 때, 다음을 증명하여라.

$$ g_1(g_2H) = (g_1g_2)H $$

**Proof**

Left coset의 정의에 의해 $g_1(g_2H) = \Set{g_1x | x \in g_2H}$이고 $g_2H = \Set{g_2h | h\in H}$임으로 다음이 성립한다.

$$ g_1(g_2H) = \Set{g_1g_2h | h\in H} = (g_1g_2)H \qed $$

### 명제2
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $g_1,g_2$라고 할 때, 다음을 증명하여라.

$$ g_1H \cap g_2H \neq \empty \implies g_1H = g_2H $$

**Proof**

$g_1H \cap g_2H$의 임의의 element를 $x$라고 하면 다음이 성립한다.

$$ x = g_1h_1 = g_2h_2 \implies g_1 = g_2h_2h_1^{-1} $$

이 떄, $H$가 group임으로 다음이 성립한다.

$$ g_1H = \Set{g_1h | h\in H} = \Set{g_2h_2h_1^{-1}h | h \in H} = \Set{g_2h' | h' \in H} = g_2H \qed $$

#### 참고
따라서, $g_1H, g_2H$는 완전히 같거나$(g_1H = g_2H)$ 완전히 다른$(g_1H\cap g_2H = \empty)$ set이다.

### 명제3
Group $G$와 $G$의 subgroup $H$가 있을 때, relation $R \subseteq G \times G$를 다음과 같이 정의하자.

$$ R := \Set{g_1 \times g_2 \in G \times G | g_1H = g_2H} $$

이 떄, 다음을 증명하여라.

$$ R \text{ is an equivalence relation} $$

**Proof**

$G$의 임의의 elements를 $g_1,g_2,g_3$라고 하자.

[reflexive]  
$g_1H = g_1H$임으로 $g_1 \sim_R g_1$이다. $\qed$

[symmetric]  
$g_1H = g_2H$이면 $g_2H = g_1H$임으로 $g_1 \sim_R g_2 \implies g_2 \sim_R g_1$이다. $\qed$

[transitive]  
$g_1H = g_2H$이고 $g_2H = g_3H$이면 $g_1H = g_3H$임으로 $\begin{gathered} g_1 \sim_R g_2 \\ g_2 \sim_R g_3 \end{gathered} \implies g_1 \sim_R g_3$이다. $\qed$

### 예제
정의에 의해 다음이 성립한다.

$$ \Z / n\Z = \Set{x +n\Z | x \in \Z} $$

이 때, $\Z$의 임의의 elements를 $x_1,x_2$라고 하면 division algorithm에 의해 $x_{1,2} = p_{1,2}n +q_{1,2}$임으로 다음이 성립한다.

$$ \begin{aligned} x_{1,2} + n\Z &= \Set{x_{1,2} + h | h\in n\Z} \\&= \Set{p_{1,2}n + q_{1,2} + h | h \in n\Z} \\&= \Set{q_{1,2} + h' | h' \in n\Z} \end{aligned}  $$

따라서, $q_1=q_2$인 경우 다음이 성립한다.

$$ x_1 + n\Z = x_2 + n\Z $$

이 떄, $0 \le q \le n-1$임으로 $n\Z$에 의한 coset중 서로 다른 coset은 $n$개 밖에 없다.

따라서 다음이 성립한다.

$$ \Z / n\Z = \Set{n\Z, 1+n\Z, \cdots, (n-1)+n\Z} $$

#### 참고
coset $i + n\Z$를 $[i]_n$이라고 표기하면 다음과 같다.

$$ \Z / n\Z = \Set{[0]_n, \cdots, [n-1]_n} $$

이 때, $\Z / n\Z$에 $+$을 다음과 같이 정의해보자.

$$ [i]_n + [j]_n = [i+j]_n $$

그러면 $(\Z / n\Z,+)$는 group임을 알 수 있다.

> Reference  
> [wiki::Modular_arithmetic](https://en.wikipedia.org/wiki/Modular_arithmetic#Integers_modulo_n)  
> [wiki::Quotient_group](https://en.wikipedia.org/wiki/Quotient_group)

## Right Coset
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $a$라고 할 때, $a$가 속하는 $H$의 `우잉여류(left coset)` $Ha$는 다음과 같이 정의된 집합이다.

$$ Ha = \Set{ha | h \in H} $$
