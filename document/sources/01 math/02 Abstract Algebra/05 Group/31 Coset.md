# Coset
## Left & Right Coset
Group $G$와 $G$의 non empty subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $a$라고 할 때, $a$가 속하는 $H$의 `좌잉여류(left coset)` $aH$는 다음과 같이 정의된 집합이다.

$$ aH = \Set{ah \mid h \in H} $$

그리고 $a$가 속하는 $H$의 `우잉여류(left coset)` $Ha$는 다음과 같이 정의된 집합이다.

$$ Ha = \Set{ha \mid h \in H} $$

### 명제1
Group $G$와 $G$의 non empty subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $g$, $H$의 임의의 element를 $h$라고 할 때, 다음을 증명하여라.

$$ gH = (gh)H $$

**Proof**

[$gH \subseteq (gh)H$]  
$gH$의 임의의 element를 $g\bar{h}$라고 하면 다음이 성립한다.

$$ g\bar{h} = ghh^{-1}\bar{h} \in (gh)H \qed $$ 

[$(gh)H \subseteq gH$]  
$(gh)H$의 임의의 element를 $gh\bar{h}$라고 하면 다음이 성립한다.

$$ gh\bar{h} \in gH \qed $$


### 명제2
Group $G$와 $G$의 non empty subgroup $H$가 있다고 하자.

그리고 $G$위의 relation $R_1,R_2$을 다음과 같이 정의하자.

$$ \begin{gathered} R_1 := \Set{(x,y) \in G^2 \mid xH = yH } \\ R_2 := \Set{(x,y) \in G^2 \mid y^{-1}x \in H } \\ R_3 := \Set{(x,y) \in G^2 \mid x^{-1}y \in H } \end{gathered} $$

이 때, 다음을 증명하여라.

$$ R_1 = R_2 = R_3 $$

**Proof**

$G^2$의 임의의 element를 $(x,y)$라고 하자.

[$R_1 = R_2$]  
$R_1=R_2$는 다음 명제와 동치이다.

$$ xH=yH \iff y^{-1}x \in H $$

-[$\implies$]  
$xH$의 임의의 element를 $xh$라고 하자.

그러면 전제에 의해 다음이 성립한다.

$$ \begin{aligned} & \exist \bar{h} \in H \st xh = y\bar{h} \\\implies& \exist\bar{h} \in H \st x = y\bar{h}h^{-1} \end{aligned} $$

이 떄, $\bar{h}h^{-1} \in H$임으로 다음이 성립한다.

$$ y^{-1}x = \bar{h}h^{-1} \in H \qed $$

-[$\impliedby$]  

전제에 의해 다음이 성립한다.

$$ \exist h \in H \st x = yh \implies \exist h \in H \st y = xh^{-1} $$

--[$xH \subseteq yH$]  
$xH$의 임의의 element를 $xh_2$라고 하면 $hh_2 \in H$임으로 다음이 성립한다.

$$ xh_2 = yhh_2 \in yH \qed $$

--[$yH \subseteq xH$]  
$yH$의 임의의 element를 $yh_2$라고 하면 $h^{-1}h_2 \in H$ 임으로 다음이 성립한다.

$$ yh_2 = xh^{-1}h_2 \in xH \qed $$

[$R_2 = R_3$]  
$H$는 subgroup임으로 $y^{-1}x \in H$이면 inverse element인 $x^{-1}y$는 $H$의 element이다. $\qed$

#### 참고1
$R$의 정의를 right coset을 가지고 하면 다음 결과를 얻을 수 있다.

$$ \begin{gathered} &\Set{(x,y) \in G^2 \mid Hx = Hy } \\ =& \Set{(x,y) \in G^2 \mid xy^{-1} \in H } \\ =& \Set{(x,y) \in G^2 \mid yx^{-1} \in H } \end{gathered} $$

### 명제3
Group $G$와 $G$의 non empty subgroup $H$가 있다고 하자.

그리고 $G$위의 relation $R$을 다음과 같이 정의하자.

$$ R:= \Set{(x,y) \in G^2 \mid xH = yH } $$

이 때, 다음을 증명하여라.

$$ R \text{ is an equivalence realation} $$

**Proof**

[reflexive]  

[symmetric]  

[transivity]   

#### 참고1
$R$의 정의를 right coset을 가지고 해도 equivalence relation임을 보일 수 있다.

$$ R:= \Set{(x,y) \in G^2 \mid Hx = Hy } \text{ is an equivalence relation} $$

### 명제4
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

그리고 $G$위의 relation $R$을 다음과 같이 정의하자.

$$ R := \Set{(x,y) \in G^2 \mid  xH = yH} $$

$G$의 임의의 element를 $x$라고 할 때, 다음을 증명하여라.

$$ [x]_R = xH $$

**Proof**

[$[x]_R \subseteq xH$]  
$[x]_R$의 임의의 element를 $y$라고 하면 다음이 성립한다.

$$ \forall h \in H, \enspace \exist \bar{h} \in H \st x\bar{h} = yh $$

이 때, 항상 $h,\bar{h} \in H$임으로 항상 $\bar{h}h^{-1}\in H$이고 따라서, 다음이 성립한다.

$$ y = x\bar{h}h^{-1} \in xH \qed $$

[$xH \subseteq [x]_R$]  
$xH$의 임의의 element를 $xh$라고 하면 다음이 성립한다.

$$ (xh)H = xH \implies xh \in [x]_R \qed $$

#### 참고1
$[x]_R = xH$를 증명하기 위해서 다음과 같이 풀어 써본다고 해보자.

$$ \Set{y \in G \mid xH = yH} = \Set{y \in G \mid \forall h \in H, \exist \bar{h} \in H \st xh = y\bar{h}} $$

우측 set은 $H$의 속하는 모든 $h$에 대해서 $xh = y\bar{h}$를 만족하는 어떤 $\bar{h}\in H$가 존재하는 $y\in G$의 모임이다.

이렇게 조건을 풀어 씀으로써 $\Set{xh \mid h \in H}$와 같아짐을 보이는 것은 어려워 보인다.

즉, 이런식으로 조건을 풀어 씀으로써 증명을 하려고 하니 증명이 어렵고 복잡해지는 것같다.

그런데 궁금한점은 이렇게 조건을 풀어써서 $[x]_R = xH$를 얻어내기 어렵다면 처음에 어떻게 $[x]_R = xH$임을 알아 낼 수 있는 건지 의아하다.

#### 참고2
$R:=\Set{(x,y)\in G^2 \mid  y^{-1}x \in H}$일 때, $[x]_R = xH$를 증명하기 위해서 다음과 같이 풀어 써본다고 해보자.

$$ \Set{y \in G \mid y^{-1}x \in H} = \Set{y \in G \mid \exist h \in H \st \enspace x = yh} $$

우측 set은 $x = yh$를 만족하는 어떤 $h\in H$가 존재하는 $y\in G$의 모임이다.




---

$$ \begin{aligned} [x]_R &= \Set{ y \in G \mid x \sim y} \\&= \Set{y \in G \mid xH = yH} \\&= \Set{y \in G \mid y^{-1}x \in H}  \\&= \Set{y \in G \mid \forall h \in H, \enspace y = xh^{-1} } \\&= \Set{xh^{-1} \mid h \in H} \\&= \Set{x\bar{h} \mid \bar{h} \in H} \\&= xH \qed \end{aligned}  $$

#### 보조명제
$S_1 := \Set{y \in G \mid y^{-1}x \in H}, S_2 := \Set{y \in G \mid \forall h \in H, \enspace y = xh^{-1} }$

다음을 증명하여라.

$$ S_1 = S_2 $$

#### 참고1
$\Set{y \in G \mid \forall h \in H, \enspace y = xh^{-1} }$는 $G$의 element중 $H$의 임의의 element를 $h$라고 할 때, $xh^{-1}$ 형태로 나타낼 수 있는 모든 element를 모은 set이다.

#### 참고2


#### 참고2
$R$은 subgroup $H$에 의해서 유도된 관계이기 때문에 $R$에 의한 quotient set을 다음과 같이 표기한다.

$$ G/H := G/R = \Set{aH \mid a \in G} $$

즉, 모든 left coset의 집합이다.

> Reference  
> [2!=2 blog](https://chocobear.tistory.com/127)

### 명제1
Group $G$와 $G$의 non empty subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $g_1,g_2$라고 할 때, 다음을 증명하여라.

$$ g_1(g_2H) = (g_1g_2)H $$

**Proof**

Left coset의 정의에 의해 $g_1(g_2H) = \Set{g_1x \mid x \in g_2H}$이고 $g_2H = \Set{g_2h \mid h\in H}$임으로 다음이 성립한다.

$$ g_1(g_2H) = \Set{g_1g_2h \mid h\in H} = (g_1g_2)H \qed $$

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

$$ g_1H = \Set{g_1h \mid h\in H} = \Set{g_2h_2h_1^{-1}h \mid h \in H} = \Set{g_2h' \mid h' \in H} = g_2H \qed $$

### 명제3
#### Motivation
명제2와 명제3을 통해 coset이 equivalence class의 성질과 같다는 것을 알 수 있다.

그렇다면, 어떤 equivalence relation을 줘야 coset을 equivalence class로 얻을 수 있을지 생각해보자.

#### Statement
Group $G$와 $G$의 non empty subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $g$라고 할 때, 다음을 증명하여라.       

$$ R := \Set{g_1 \times g_2 \in G \times G \mid g_1H = g_2H} \implies gH = [g]_R $$

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

$$ \begin{aligned} & R := \Set{g_1 \times g_2 \in G \times G \mid g_1H = g_2H} \\\iff& R := \Set{g_1 \times g_2 \in G \times G \mid g_2 = g_1h \text{ for some } h \in H} \\\iff& R := \Set{g_1 \times g_2 \in G \times G \mid g_1^{-1}g_2 = h \text{ for some } h \in H} \\\iff& R := \Set{g_1 \times g_2 \in G \times G \mid g_1 = g_2h \text{ for some } h \in H} \\\iff& R := \Set{g_1 \times g_2 \in G \times G \mid g_2^{-1}g_1 = h \text{ for some } h \in H} \end{aligned}  $$

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

$$ \begin{aligned} & G = \bigcup G/H = \bigcup \Set{gH \mid g \in G} = \bigcup_{i=1}^n g_iH \\\implies& |G| = \sum_{i=1}^n |g_iH| = n|H| \\\implies& |H| \mid |G| \qed \end{aligned} $$

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

$$ \Z / n\Z = \Set{x +n\Z \mid x \in \Z} $$

이 때, $\Z$의 임의의 elements를 $x_1,x_2$라고 하면 division algorithm에 의해 $x_{1,2} = p_{1,2}n +q_{1,2}$임으로 다음이 성립한다.

$$ \begin{aligned} x_{1,2} + n\Z &= \Set{x_{1,2} + h \mid h\in n\Z} \\&= \Set{p_{1,2}n + q_{1,2} + h \mid h \in n\Z} \\&= \Set{q_{1,2} + h' \mid h' \in n\Z} \end{aligned}  $$

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

$$ G/\Set{e_G} = \Set{g\Set{e_G} \mid g \in G} = \Set{\Set{g} \mid g \in G} $$

이 때, $*$을 다음과 같이 정의하자.

$$ \Set{g_1} * \Set{g_2} = \Set{g_1 * g_2} $$

그러면 $(G/\Set{e_G},*)$는 group임을 알 수 있다.

또한 함수 $f : G \rightarrow G/\set{e_G} \st g \mapsto \Set{g}$는 group isomorphism임을 알 수 있다.