# Group and Relation
## Observation
Group $(\Z,+_\Z)$와 $\Z$위의 equivalence relation $R$이 다음과 같이 주어졌다고 해보자.

$$ R := \Set{(x,y) \in \Z^2 \mid x-y \text{ is even}} $$

이 때, $\Z/R = \Set{[0],[1]}$을 생각해보자.

$\Z/R$위의 binary operation을 $\Z$의 binary operation을 가지고 정의한다면 다음이 자연스러울 것이다.

$$ [x],[y] \in \Z/R, \enspace [x]+[y] = [x+y] $$

이 때, equivalent class에 representative를 어떤걸로 골라주더라도 위에 정의한 binary operation이 잘 정의되는 것 처럼 보인다. 또한 identity element와 inverse element가 존재해서, group structure을 가지고 있는 것 처럼 보인다.

그렇다면 다음과 같은 질문이 떠오르게 된다.
1. group위에 임의의 equivalence relation이 주어졌을 때, quotient set이 group structure을 가지는가?

이 질문의 답은 '아니다'이며 Example1과 같은 반례가 존재한다.

어떤 경우에는 group structure을 갖는 반면 어떤 경우에는 그렇지 않는데 이면에 어떤 구조가 숨어있어서 이렇게 되는것인지 알아보기 위해 추상화를 해보자.

### Example1
Group $(M_{2\times2}(\R),+)$와 $M$위의 relation $R$을 다음과 같이 정의하자.

$$ R:= \Set{(x,y) \in M^2 \mid \exist p \in M \st x = pyp^{-1}} $$

그러면 $R$은 $M$위의 equivalence relation이다.

 $M/R$에 위와 같은 방식으로 $M$의 binary operaton을 가지고 $M/R$의 binary operation을 정의한다고 했을 때, 이번에도 group structure을 가지고 있는지 확인해보자.

 [well defined]  
 $A= \begin{bmatrix} 1 & 0 \\ 0 & 0 \end{bmatrix}, B=\begin{bmatrix} 0 & 0 \\ 0 & 1 \end{bmatrix}, P=\begin{bmatrix} 1 & 1 \\ 0 & 1 \end{bmatrix}, T=\begin{bmatrix} 2 & 1 \\ 1 & 1 \end{bmatrix}$라고 했을 때, $A' = PAP^{-1} = \begin{bmatrix} 1 & -1 \\ 0 & 0 \end{bmatrix}, B' = PBP^{-1} = \begin{bmatrix} -1 & 2 \\ -1 & 2 \end{bmatrix}$라고 하자.

그러면 $[A]+[B] = [A+B]$이고 $[A']+[B'] = [A'+B']$라고 했을 때, $[A+B]=[A'+B']$이여야 한다.

하지만 $A+B = \begin{bmatrix} 1 & 0 \\ 0 & 1 \end{bmatrix}$이고 $A'+B' = \begin{bmatrix} 0 & 1 \\ -1 & 2 \end{bmatrix}$임으로 $[A+B]\neq[A'+B']$이다.

즉, binary operation이 잘 정의되지 않음으로 group 또한 아니다.

## Abstraction1
위의 관찰을 Group $G$와 $G$위의 equivalence relation $R$이 있는 경우로 추상화 한 뒤 언제 group structure을 갖는지 확인해보자.

먼저, group structure을 갖기 위해서는 연산이 잘 정의되어 있어야 한다.

$G/R$위의 binary operation을 다음과 같이 정의하자.

$$ [x],[y] \in G/R, \enspace [x]*[y] = [x*y] $$

이 떄, $G/R$의 binary operation이 잘 정의된다는 의미가 무엇인지 살펴보자.

$G/R$의 binary operation이 잘 정의되기 위해서는 $x \sim x'$, $y \sim y'$일 때 다음이 성립해야 한다.

$$ [x]*[y] = [x']*[y'] \iff [x*y] = [x'*y'] \iff (x*y,x'*y') \in R $$

이 결과를 통해서 $G^2$을 componentwise한 연산이 주어진 group으로 봤을 때, $R$이 $G^2$의 subgroup이면 위가 만족함을 알 수 있다. 즉, $G/R$위의 연산이 잘 정의 될 충분조건을 찾은것이다.

$$ R \le G^2 \implies * \text{ is well defined} $$

이 떄, $R \le G^2$이 필요조건인지 확인해서 필요충분조건임을 알 수 있다.(명제1)

따라서, 연산이 잘 정의되기 위한 필요충분조건을 알게 되었다.

$$ R \le G^2 \iff * \text{ is well defined} $$

그러면 이 조건하에서 $G/R$이 group임을 확인할 수 있다. (명제2)

### 명제1
Group $G$와 $G$위의 equivalence relation $R$이 있다고 하자.

그리고 $G/R$위의 binary operation을 다음과 같이 정의하자.

$$ [x],[y] \in G/R, \enspace [x]*[y] = [x*y] $$

이 떄, 다음을 증명하여라.

$$ R \le G^2 \impliedby * \text{ is well defined} $$

**Proof**

$R \subseteq G^2$이기 때문에 연산에 닫혀있는지와 inverse element가 존재하는지 확인하면 된다.

[closed]  
$R$위의 임의의 elements를 $(x,x'),(y,y')$이라고 하자.

그러면 전제에 의해 다음이 성립한다.

$$ [x][y]=[x'][y'] \iff [xy][x'y'] \iff (xy,x'y')\in R \qed $$

[inverse]  
$R$위의 임의의 elements를 $(x,y)$라고 하자.

$R$의 reflexive property에 의해 다음이 성립한다.

$$(x^{-1},x^{-1}) \in R $$

연산에 닫혀 있음으로 다음이 성립한다.

$$ (e_G,x^{-1}y) \in R $$

$R$의 reflexive property 의해 다음도 성립한다.

$$ (y^{-1},y^{-1}) \in R $$

연산에 닫혀 있음으로 다음이 성립한다.

$$ (y^{-1},x^{-1}) \in R $$

$R$의 symmetric property에 의해 다음이 성립한다.

$$ (x^{-1}, y^{-1}) \in R \qed $$

### 명제2
Group $G$와 $G$위의 equivalence relation $R$이 있다고 하자.

그리고 $G/R$위의 binary operation을 다음과 같이 정의하자.

$$ [x],[y] \in G/R, \enspace [x]*[y] = [x*y] $$

이 떄, 다음을 증명하여라.

$$ * \text{ is well defined} \implies G/R\text{ is a group} $$

**Proof**

[closed]  
$G/R$의 임의의 elements를 $[x],[y]$라고 하자.

$xy \in G$임으로 다음이 성립한다.

$$ [x][y] = [xy] \in G/R \qed $$  

[identity]  
$G/R$의 임의의 elements를 $[x]$라고 하자.

이 떄, 다음이 성립한다.

$$ [x][e_G]= [x], \enspace [e_G][x]=[x] $$

따라서, $[e_G]$는 $G/R$의 identity element이다. $\qed$

[inverse]  
$G/R$의 임의의 elements를 $[x]$라고 하자.

이 떄, 다음이 성립한다.

$$ [x][x^{-1}]= [e_G], \enspace [x^{-1}][x]=[e_G] $$

따라서, $G/R$의 임의의 element마다 inverse element가 존재한다. $\qed$



## Observation2
Observation을 다시 한번 살펴보자.

$\Z$의 subgroup $2\Z$를 다음과 같이 정의하자.

$$ 2\Z := \Set{2x \mid x \in \Z} $$

그러면 observation에 있던 $R$을 다음과 같이 표현할 수 있다.

$$ R := \Set{(x,y) \in \Z^2 \mid x-y \in 2\Z} $$

즉, subgroup $2\Z$에 의해 주어진 equivalence relation이라는 조금 더 구체적인 관측을 한것이다.

그렇다면 group과 임의의 subgroup이 주어질 때, 위와 같은 방식으로 subgroup에 의해 정의된 relation은 항상 equivalence relation일까?라는 자연스러운 질문이 떠오른다.

그리고 이 질문의 대답은 명제1을 통해 subgroup을 통해 정의된 relation은 항상 equivalence relation임을 알 수 있다.

구체적으로 equivalence relation이 주어졌음으로 equivalence class 또한 구체적으로 서술할 수 있으며 이를 `우 잉여류(right coset)`이라고 한다.

이전에 관찰을 통해서 group의 quotient set이 group이 될 조건은 연산이 잘 정의되어야 된다는것을 알았다. 그렇다면 subgroup에 의해 정의된 equivalence relation이라는 셋팅에서 연산이 잘 정의 될 조건은 어떻게 표현되는지를 살펴보자.

$G/R$의 binary operation이 잘 정의되기 위해서는 $G$의 임의의 element를 $x,y$가 있고 $x \sim x'$, $y \sim y'$인 임의의 $x',y' \in G$에 대해서 다음이 성립해야 한다.

$$ \begin{aligned} Hx*Hy = Hx'*Hy' &\iff Hxy = Hx'y' \\&\iff xy \sim x'y' \\&\iff xy(x'y')^{-1} \in H \\&\iff xy(y')^{-1}x^{-1}x(x')^{-1} \in H \\&\iff xy(y')^{-1}x^{-1} \in H \end{aligned} $$

$y \sim y'$인 임의의 $y'$이란 말은 $y'$이 $Hy$의 임의의 element라는 의미이고 따라서, $H$의 임의의 element를 $h$라고 할 떄, 다음이 성립해야한다.

$$ xhx^{-1} \in H $$

즉, binary operation이 잘 정의되기 위한 충분조건은 다음과 같다.

$$ \forall x \in G, \enspace \forall h \in H, \enspace xhx^{-1} \in H  \implies * \text{ is well defined} $$

이 떄, 필요조건인지 확인해서 필요충분조건임을 알 수 있다.(명제3)

따라서, 연산이 잘 정의되기 위한 필요충분조건을 알게 되었다.

$$ \forall x \in G, \enspace \forall h \in H, \enspace xhx^{-1} \in H  \iff * \text{ is well defined} $$

그리고 Observation1의 관찰의 결과로 group이 되기 위한 필요충분조건임도 알고 있다.

$$ \forall x \in G, \enspace \forall h \in H, \enspace xhx^{-1} \in H  \iff G/R \text{ is a group} $$

참고로 $H$에 의해 정의된 $R$이라는 것을 명시적으로 나타내기 위해서 $G/R$대신에 $G/H$라고 표기한다.

### Example1
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

### Example2
정의에 의해 다음이 성립한다.

$$ G/\Set{e_G} = \Set{g\Set{e_G} \mid g \in G} = \Set{\Set{g} \mid g \in G} $$

이 때, $*$을 다음과 같이 정의하자.

$$ \Set{g_1} * \Set{g_2} = \Set{g_1 * g_2} $$

그러면 $(G/\Set{e_G},*)$는 group임을 알 수 있다.

또한 함수 $f : G \rightarrow G/\set{e_G} \st g \mapsto \Set{g}$는 group isomorphism임을 알 수 있다.

### Right Coset
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

그리고 $G$위의 relation $R$을 다음과 같이 정의하자.

$$ R:=\Set{(x,y)\in G^2 \mid xy^{-1} \in H} $$

$G$의 임의의 element를 $x$라고 할 때, $[x]$는 다음과 같다.

$$ \begin{aligned} [x] &= \Set{y \in G \mid x \sim y} \\&= \Set{ y \in G | xy^{-1} \in H} \end{aligned} $$

이는 명제1에 의해 다음과 같다.

$$ [x] = \Set{ hx | h \in H} $$

이 때, $[x]$를 $Hx$로 표기하며, $H$의 element에 $x$가 오른쪽에 연산된 형태의 집합임으로 $Hx$를 `우 잉여류(right coset)`이라고 한다.

#### 성질
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 elements를 $x,y$ $H$의 임의의 elements를 $h$라고 할 떄, 다음이 성립한다.

1. $H(xy)= (Hx)y$ (명제2)
2. $Hh = H$ (명제3)
3. $Hx = H \iff x \in H$ (명제4)
4. $Hx = Hy \iff xy^{-1} \in H$ (명제5)


#### 명제1
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $x$라고 할 떄, 다음을 증명하여라.

$$ \Set{ y \in G | xy^{-1} \in H} = \Set{ hx | h \in H} $$

**Proof**

$S_1 = \Set{ y \in G | xy^{-1} \in H}, \enspace S_2 = \Set{ hx | h \in H}$라고 하자.

[$S_1 \subseteq S_2$]  
$S_1$의 임의의 element를 $y$라고 하면 다음이 성립한다.

$$ \exist h \in H \st xy^{-1} = h \implies y = h^{-1}x \implies y \in S_2 \qed $$

[$S_2 \subseteq S_1$]  
$S_2$의 임의의 element를 $hx$라고 하면 다음이 성립한다.

$$ x(hx)^{-1} = h^{-1} \in H \implies hx \in S_1 \qed $$

#### 명제2
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 elements를 $x,y$라고 할 떄, 다음을 증명하여라.

$$H(xy)= (Hx)y$$

**Proof**

Right coset의 정의에 의해 다음이 성립한다.

$$ H(xy) = \Set{hxy|h \in H} = \Set{ty | t \in Hx} = (Hx)y \qed $$

#### 명제3
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$H$의 임의의 element를 $h$라고 할 떄, 다음을 증명하여라.

$$Hh = H$$

**Proof**

[$Hh \subseteq H$]  
$Hh$의 임의의 element를 $h'h$라고 하면, $H$가 subgroup이기 때문에 $h'h\in H$이다. $\qed$

[$H \subseteq Hh$]
$H$의 임의의 element를 $h'$라고 하자.

$h'h^{-1} \in H$임으로 $h' = h'h^{-1}h\in Hh$이다. $\qed$

#### 명제4
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 element를 $x$라고 할 떄, 다음을 증명하여라.

$$Hx = H \iff x \in H$$

**Proof**

[$\implies$]  
$Hx$의 임의의 element를 $hx$라고 하자.

그러면 전제에 의해 다음이 성립한다.

$$ \exist h' \in H \st hx = h' \implies x = h^{-1}h' \in H \qed $$

[$\impliedby$]  
명제2에 의해 자명하다. $\qed$

#### 명제5
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 elements를 $x,y$라고 할 떄, 다음을 증명하여라.

$$Hx = Hy \iff xy^{-1} \in H$$

**Proof**

[$\implies$]  
$Hx$의 임의의 element를 $hx$라고 하자.

그러면 전제에 의해 다음이 성립한다.

$$ \exist h' \in H \st hx = h'y \implies xy^{-1}=h^{-1}h' \in H \qed$$

[$\impliedby$]  
전제에 의해 다음이 성립한다.

$$ \exist h \in H \st xy^{-1} = h \implies x=hy $$

따라서, 다음이 성립한다.

$$ Hx = Hhy = Hy \qed $$

#### 명제6
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

#### 명제7(Lagrange's Theorem)
Finite group $G$가 있을 떄, 다음을 증명하여라.

$$ H \le G \implies |H| \mid |G| $$

**Proof**

$G/H$는 $G$의 partition임으로 다음이 성립한다.

$$ \begin{aligned} & G = \bigcup G/H = \bigcup \Set{gH \mid g \in G} = \bigcup_{i=1}^n g_iH \\\implies& |G| = \sum_{i=1}^n |g_iH| = n|H| \\\implies& |H| \mid |G| \qed \end{aligned} $$

##### 따름명제
Finite group $G$가 있을 때, 다음을 증명하여라.

$$ |G| = \text{prime number} \implies G \text{ is a cyclic group} $$

**Proof**

$G - \Set{e_G}$의 임의의 element를 $g$라고 하자.

$\braket{g}$는 $G$의 subgroup임으로 다음이 성립한다.

$$ |\braket{g}| \mid |G| \implies |\braket{g}| = |G| \implies \braket{g} = G \qed $$

###### 참고
finite group이면서 cyclic group이 아닌 경우는 여러개의 element로 생성되는 경우이다.

예를 들어 finite cyclic group $\braket{x} = \Set{e,x},\braket{y} = \Set{e,y,y^2,y^3}$가 있다고 하자. 그러면 $\braket{x}\times\braket{y}$는 finite group이지만 $\gcd(o(x),o(y)) \neq 1$임으로 cyclic group은 아니다.

예를 들어 각 generator로 구성된 $(x,y)$로는 $(x,y^2)$와 같은 $\braket{x}\times\braket{y}$의 element를 generate 할 수 없다.

### 명제1
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

그리고 $G$위의 relation $R$을 다음과 같이 정의하자.

$$ R:=\Set{(x,y)\in G^2 \mid xy^{-1} \in H} $$

이 떄, 다음을 증명하여라.

$$ R \text{ is an equivalence relation} $$

**Proof**

[reflexive]  
$G$의 임의의 element를 $x$라고 하자.

이 떄, $H$가 subgroup임으로 다음이 성립한다.

$$ xx^{-1} = e_G \in H \implies x \sim x \qed $$

[symmetric]  
$x \sim y$라고 하자.

이 때,  $H$가 subgroup임으로 다음이 성립한다.

$$ xy^{-1} \in H \implies yx^{-1} \in H \implies y \sim x \qed $$

[transitive]  
$x \sim y, y \sim z$라고 하자.

이 떄, $H$가 subgroup임으로 다음이 성립한다.

$$ xy^{-1},yz^{-1} \in H \implies xy^{-1}yz^{-1} = xz^{-1} \in H \implies x \sim z \qed $$  

### 명제2
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ \forall h \in H, \enspace \exist y,y' \in G \st y(y')^{-1} =h $$

**Proof**

$H$의 임의의 element를 $h$ $G$의 임의의 element $y'$이라고 하자.

이 떄, $y=hy'$이라고 두면 $y\in G$이고 다음이 성립한다.

$$ y(y')^{-1} = hy'(y')^{-1} = h \qed $$


### 명제3
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

그리고 $G$위의 relation $R$을 다음과 같이 정의하자.

$$ R:=\Set{(x,y)\in G^2 \mid xy^{-1} \in H} $$

$G/R$위의 binary operation을 다음과 같이 정의하자.

$$ Hx, Hy \in G/R, \enspace Hx*Hy = Hxy $$

이 떄, 다음을 증명하여라.

$$ \forall x \in G, \enspace \forall h \in H, \enspace xhx^{-1} \in H  \impliedby * \text{ is well defined} $$

**Proof**

$G$의 임의의 element를 $x$ $H$의 임의의 element를 $y$라고 하자.

그러면 $Hy = H$임으로 다음이 성립한다.

$$ \begin{aligned} \begin{gathered} HxHy = Hxy \\ HxHy = HxH = Hx \end{gathered} &\implies Hxy = Hx \\&\implies Hxyx^{-1} = H \\&\implies xyx^{-1} \in H \qed \end{aligned} $$

## Observation3
Observation2을 다시 한번 살펴보자.

$R$을 다음과 같이 표현할 수 있다.

$$ R := \Set{(x,y) \in \Z^2 \mid -x+y \in 2\Z} $$

이를 바탕으로 observation2에서 한 작업들을 그대로 하면 group $G$와 subgorup $H$가 있을 떄, $G$위의 equivalence relation $R$을 다음과 같이 정의할 수 있음을 알 수 있다.

$$ R := \Set{(x,y) \in G^2 \mid y^{-1}x \in H} $$

그리고 $R$을 가지고 equivalence class를 따져보면 `좌 잉여류(left coset)`을 얻을 수 있다.

그리고 이 setting에서 $G/R$에 연산이 잘 정의될 필요충분조건을 찾아보면 동일함을 알 수 있다.

$$ \forall x \in G, \enspace \forall h \in H, \enspace xhx^{-1} \in H  \iff * \text{ is well defined} $$

그리고 Observation1의 관찰의 결과로 group이 되기 위한 필요충분조건임도 알고 있다.

$$ \forall x \in G, \enspace \forall h \in H, \enspace xhx^{-1} \in H  \iff G/R \text{ is a group} $$

### Left Coset
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

그리고 $G$위의 relation $R$을 다음과 같이 정의하자.

$$ R:=\Set{(x,y)\in G^2 \mid xy^{-1} \in H} $$

$G$의 임의의 element를 $x$라고 할 때, $[x]$는 다음과 같다.

$$ \begin{aligned} [x] &= \Set{y \in G \mid x \sim y} \\&= \Set{ y \in G | y^{-1}x \in H} \end{aligned} $$

이는 다음과 같다.

$$ [x] = \Set{ xh | h \in H} $$

이 때, $[x]$를 $xH$로 표기하며, $H$의 element에 $x$가 왼쪽에서 연산된 형태의 집합임으로 $xH$를 `좌 잉여류(left coset)`이라고 한다.

#### 성질
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

$G$의 임의의 elements를 $x,y$ $H$의 임의의 elements를 $h$라고 할 떄, 다음이 성립한다.

1. $(xy)H= x(yH)$ 
2. $hH = H$ 
3. $xH = H \iff x \in H$ 
4. $xH = yH \iff y^{-1}x \in H$ 


