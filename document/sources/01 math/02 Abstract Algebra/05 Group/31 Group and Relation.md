# Group and Relation
## Observation
Group $(\Z,+_\Z)$와 $\Z$위의 relation $R$을 다음과 같이 정의하자.

$$ R := \Set{(x,y) \in \Z^2 \mid x-y \text{ is even}} $$

그러면 $R$은 $\Z$위의 equivalence relation이다.

이 때, $\Z/R = \Set{[0],[1]}$을 생각해보자.

$\Z/R$위의 binary operation을 $\Z$의 binary operation을 가지고 정의한다면 다음이 자연스러울 것이다.

$$ [x],[y] \in \Z/R, \enspace [x]+[y] = [x+y] $$

조합가능한 4가지의 연산을 시도해보면 이 binary operation이 잘 정의된다는것을 쉽게 알 수 있다.

또한 identity element와 inverse element가 존재해서, group structure을 가지고 있다는 것 또한 알 수 있다.

그렇다면 group위에 임의의 equivalence relation을 주더라도 quotient set이 group structure을 가질까?

다음 예시를 생각해 보자.

Group $(M_{2\times2}(\R),+)$와 $M$위의 relation $R$을 다음과 같이 정의하자.

$$ R:= \Set{(x,y) \in M^2 \mid \exist p \in M \st x = pyp^{-1}} $$

그러면 $R$은 $M$위의 equivalence relation이다.

 $M/R$에 위와 같은 방식으로 $M$의 binary operaton을 가지고 $M/R$의 binary operation을 정의한다고 했을 때, 이번에도 group structure을 가지고 있는지 확인해보자.

 [well defined]  
 $A= \begin{bmatrix} 1 & 0 \\ 0 & 0 \end{bmatrix}, B=\begin{bmatrix} 0 & 0 \\ 0 & 1 \end{bmatrix}, P=\begin{bmatrix} 1 & 1 \\ 0 & 1 \end{bmatrix}, T=\begin{bmatrix} 2 & 1 \\ 1 & 1 \end{bmatrix}$라고 했을 때, $A' = PAP^{-1} = \begin{bmatrix} 1 & -1 \\ 0 & 0 \end{bmatrix}, B' = PBP^{-1} = \begin{bmatrix} -1 & 2 \\ -1 & 2 \end{bmatrix}$라고 하자.

그러면 $[A]+[B] = [A+B]$이고 $[A']+[B'] = [A'+B']$라고 했을 때, $[A+B]=[A'+B']$이여야 한다.

하지만 $A+B = \begin{bmatrix} 1 & 0 \\ 0 & 1 \end{bmatrix}$이고 $A'+B' = \begin{bmatrix} 0 & 1 \\ -1 & 2 \end{bmatrix}$임으로 $[A+B]\neq[A'+B']$이다.

즉, binary operation이 잘 정의되지 않음으로 group 또한 아니다.

이와 같이 어떤 경우에는 group structure을 갖는 반면 어떤 경우에는 그렇지 않음을 알 수 있다.

이 이면에 어떤 구조가 숨어있어서 이렇게 되는것인지 알아보기 위해 추상화를 해보자.

## Abstraction
Group $G$와 $G$위의 equivalence relation $R$이 있다고 하자.

$G/R$위의 binary operation을 다음과 같이 정의하자.

$$ [x],[y] \in G/R, \enspace [x]*[y] = [x*y] $$

이 떄, $G/R$의 binary operation이 잘 정의된다는 의미가 무엇인지 살펴보자.

$G/R$의 binary operation이 잘 정의되기 위해서는 $x \sim x'$, $y \sim y'$일 때 다음이 성립해야 한다.

$$ [x]*[y] = [x']*[y'] \iff [x*y] = [x'*y'] \iff (x*y,x'*y') \in R $$

이 결과를 통해서 $G^2$을 componentwise한 연산이 주어진 group으로 봤을 때, $R$이 $G^2$의 subgroup이면 위가 만족함을 알 수 있다. 즉, $G/R$위의 연산이 잘 정의 될 충분조건을 찾은것이다.

$$ R \le G^2 \implies * \text{ is well defined} $$

이 떄, $R \le G^2$이 필요조건인지 확인해서 필요충분조건임을 알 수 있다.(명제1)

연산이 잘 정의되기 위한 필요충분조건을 알았음으로 다음이 성립한다.

$$ R \le G^2 \iff * \text{ is well defined} $$


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

## Relation and Subgroup
다시 observation으로 돌아가보자.

$\Z$의 subgroup $2\Z$를 다음과 같이 정의하자.

$$ 2\Z := \Set{2x \mid x \in \Z} $$

그러면 observation에 있던 $R$을 다음과 같이 표현할 수 있다.

$$ R := \Set{(x,y) \in \Z^2 \mid x-y \in 2\Z} $$

위와 같이 subgroup으로 정의된 relation은 equivalence relation이 된다.(명제1)

그러면 위의 명제를 subgroup의 언어로 바꿔보자.





### 명제1
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

이 떄, $G$위의 relation $R$을 다음과 같이 정의하자.

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

