# Coset
## Left Coset
Group $G$와 $G$의 non empty subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $a$라고 할 때, $a$가 속하는 $H$의 `좌잉여류(left coset)` $aH$는 다음과 같이 정의된 집합이다.

$$ aH = \Set{a*h | h \in H} $$

그리고 $G/H$는 다음과 같이 정의된 집합이다.

$$ G/H = \Set{aH | a \in G} $$

즉, 모든 left coset의 집합이다.

> Reference  
> [2!=2 blog](https://chocobear.tistory.com/127)

### 명제1
Group $G$와 $G$의 non empty subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $g_1,g_2$라고 할 때, 다음을 증명하여라.

$$ g_1(g_2H) = (g_1g_2)H $$

**Proof**

Left coset의 정의에 의해 $g_1(g_2H) = \Set{g_1x | x \in g_2H}$이고 $g_2H = \Set{g_2h | h\in H}$임으로 다음이 성립한다.

$$ g_1(g_2H) = \Set{g_1g_2h | h\in H} = (g_1g_2)H \qed $$

### 명제2
Groupg $G$와 $G$의 non empty subsgroup $H$가 있다고 하자.

$G$의 임의의 element를 $g$라고 할 때, 다음을 증명하여라.

$$ gH \neq \empty $$

**Proof**

$H$가 group임으로 $e_G \in H$이다. 따라서, 다음이 성립한다.

$$ g \in gH \implies gH \neq \empty \qed $$

### 명제3
Group $G$와 $G$의 non empty subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $g_1,g_2$라고 할 때, 다음을 증명하여라.

$$ g_1H \cap g_2H \neq \empty \implies g_1H = g_2H $$

**Proof**

$g_1H \cap g_2H$의 임의의 element를 $x$라고 하면 다음이 성립한다.

$$ x = g_1h_1 = g_2h_2 \implies g_1 = g_2h_2h_1^{-1} $$

이 떄, $H$가 group임으로 다음이 성립한다.

$$ g_1H = \Set{g_1h | h\in H} = \Set{g_2h_2h_1^{-1}h | h \in H} = \Set{g_2h' | h' \in H} = g_2H \qed $$

### 명제3
#### Motivation
명제2와 명제3을 통해 coset이 equivalence class의 성질과 같다는 것을 알 수 있다.

그렇다면, 어떤 equivalence relation을 줘야 coset을 equivalence class로 얻을 수 있을지 생각해보자.

#### Statement
Group $G$와 $G$의 non empty subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $g$라고 할 때, 다음을 증명하여라.       

$$ R := \Set{g_1 \times g_2 \in G \times G | g_1H = g_2H} \implies gH = [g]_R $$

**Proof**

[equivalence class]
$G$의 임의의 elements를 $g_1,g_2,g_3$라고 하자.

-[reflexive]  
$g_1H = g_1H$임으로 $g_1 \sim_R g_1$이다. $\qed$

-[symmetric]  
$g_1H = g_2H$이면 $g_2H = g_1H$임으로 $g_1 \sim_R g_2 \implies g_2 \sim_R g_1$이다. $\qed$

-[transitive]  
$g_1H = g_2H$이고 $g_2H = g_3H$이면 $g_1H = g_3H$임으로 $\begin{gathered} g_1 \sim_R g_2 \\ g_2 \sim_R g_3 \end{gathered} \implies g_1 \sim_R g_3$이다. $\qed$


[$gH \subseteq [g]_R$]  
$gH$의 임의의 element를 $gh$라고 하면 다음이 성립한다.

$$ \begin{aligned} &(gh)H = \Set{ghh'|h' \in H} = \Set{g\tilde{h}|\tilde{h} \in H} = gH \\\implies& g \sim gh \\\implies& gh \in [g]_R \qed \end{aligned} $$

[$[g]_R \subseteq gH$]  
$[g]_R$의 임의의 element를 $x$라고 하자.

$gH = xH$이고 $g \in gH$이기 때문에 다음이 성립한다.

$$ \exist h \in H \st g = xh \implies x = gh^{-1} \implies x \in gH \qed $$

#### 따름 명제
다음을 증명하여라.

$$ \begin{aligned} & R := \Set{g_1 \times g_2 \in G \times G | g_1H = g_2H} \\\iff& R := \Set{g_1 \times g_2 \in G \times G | g_2 = g_1h \text{ for some } h \in H} \\\iff& R := \Set{g_1 \times g_2 \in G \times G | g_1^{-1}g_2 = h \text{ for some } h \in H} \\\iff& R := \Set{g_1 \times g_2 \in G \times G | g_1 = g_2h \text{ for some } h \in H} \\\iff& R := \Set{g_1 \times g_2 \in G \times G | g_2^{-1}g_1 = h \text{ for some } h \in H} \end{aligned}  $$

**Proof**

$g_1H=g_2H$라고 하면 $g_1 \in g_1H, g_2 \in g_2H$ 다음이 성립한다.

$$ \exist h_1,h_2 \st \begin{gathered} g_1h_1 = g_2 \\ g_2 h_2 = g_1 \end{gathered} \implies \begin{gathered} h_1 = g_1^{-1}g_2 \\ h_2 = g_2^{-1}g_1 \end{gathered}  $$

이번에 $g_2 = g_1h$라고 하면 다음이 성립한다.

$$ g_2H = (g_1h)H = \Set{g_1hh'|h' \in H} = \Set{g_1\tilde{h}|\tilde{h} \in H} = g_1H $$

#### 참고
left coset은 equivalent class임으로 $G/H$는 equivalence class들의 모임인 quotient set이 되고 이는 partition이다. 

따라서, $G/H$는 $G$의 partition이다.

### 명제4
Group $G$와 subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $g$라고 할 때, 다음을 증명하여라.

$$ |gH| = |H| $$

**Proof**

함수 $f$를 다음과 같이 정의하자.

$$ f : gH \rightarrow H \st gh \mapsto h $$

이 떄, $f$가 bijective함을 보여서 $|gH| = |H|$임을 증명하자.

[injective]  
$gH$의 임의의 두 elements를 $gh_1,gh_2$라고 하면 다음이 성립한다.

$$ f(gh_1)=f(gh_2) \implies h_1 = h_2 \implies gh_1 = gh_2 \qed $$

[surjective]  
$H$의 임의의 element를 $h$라고 하면 다음이 성립한다.

$$ \exist gh \in gH \st f(gh) = h \qed $$

### 명제5(Lagrange's Theorem)
Finite group $G$가 있을 떄, 다음을 증명하여라.

$$ H \le G \implies |H| \mid |G| $$

**Proof**

$G/H$는 $G$의 partition임으로 다음이 성립한다.

$$ \begin{aligned} & G = \bigcup G/H = \bigcup \Set{gH | g \in G} = \bigcup_{i=1}^n g_iH \\\implies& |G| = \sum_{i=1}^n |g_iH| = n|H| \\\implies& |H| \mid |G| \qed \end{aligned} $$

#### 참고
1. $G$의 element가 $n$개가 있다는 말은 아니다. 서로 다른 coset의 수가 $n$개가 있다는 의미이다.

#### 따름명제
Finite group $G$가 있을 때, 다음을 증명하여라.

$$ |G| = \text{prime number} \implies G \text{ is a cyclic group} $$

**Proof**

$G - \Set{e_G}$의 임의의 element를 $g$라고 하자.

$\braket{g}$는 $G$의 subgroup임으로 다음이 성립한다.

$$ |\braket{g}| \mid |G| \implies |\braket{g}| = |G| \implies \braket{g} = G \qed $$

##### 참고
finite group이면서 cyclic group이 아닌 경우는 여러개의 element로 생성되는 경우이다.

예를 들어 finite cyclic group $\braket{x} = \Set{e,x},\braket{y} = \Set{e,y,y^2,y^3}$가 있다고 하자. 이 떄, $\gcd(o(x),o(y)) \neq 1$임으로 $\braket{x}\times\braket{y}$는 finite group이지만 cyclic group이 아니다.

예를 들어 각 generator로 구성된 $(x,y)$로는 $(x,y^2)$와 같은 $\braket{x}\times\braket{y}$의 element를 generate 할 수 없다.


### 예제1
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

또한 함수 $f : G \rightarrow \Z/n\Z \st g \mapsto \Set{g}$는 group homorphism임을 알 수 있다.

> Reference  
> [wiki::Modular_arithmetic](https://en.wikipedia.org/wiki/Modular_arithmetic#Integers_modulo_n)  
> [wiki::Quotient_group](https://en.wikipedia.org/wiki/Quotient_group)

### 예제2
정의에 의해 다음이 성립한다.

$$ G/\Set{e_G} = \Set{g\Set{e_G} | g \in G} = \Set{\Set{g} | g \in G} $$

이 때, $*$을 다음과 같이 정의하자.

$$ \Set{g_1} * \Set{g_2} = \Set{g_1 * g_2} $$

그러면 $(G/\Set{e_G},*)$는 group임을 알 수 있다.

또한 함수 $f : G \rightarrow G/\set{e_G} \st g \mapsto \Set{g}$는 group isomorphism임을 알 수 있다.

## Right Coset
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $a$라고 할 때, $a$가 속하는 $H$의 `우잉여류(left coset)` $Ha$는 다음과 같이 정의된 집합이다.

$$ Ha = \Set{ha | h \in H} $$
