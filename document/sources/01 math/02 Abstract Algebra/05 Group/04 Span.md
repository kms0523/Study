# Span
## 정의
Group $G$와 $G$의 subset $H$가 있다고 하자.

이 떄, 집합 $S$를 다음과 같이 정의하자.

$$ S := \{ W | H \subseteq W \land W \le G \} $$

이 떄, $H$에 의한 `생성(span)`은 다음과 같이 정의된 집합이다.

$$ \span(H) := \bigcap S $$

### 참고
$\span(H)$는 $H$를 포함하는 $G$의 최소 subgroup이며 이를 $H$에 의해 생성된 subgroup이라고도 한다.

### 명제1
Group $G$와 $G$의 subset $H$가 있을 떄,다음을 증명하여라.

$$ \span(H) \le G $$

**Proof**  

[closed under binary operation]   
$\span(H)$의 정의에 의해 $\forall a,b \in \span(H)$에 대해 다음이 성립한다.

$$ \forall W \in S, \quad a,b \in W $$

이 떄, $W$는 subgroup임으로 다음이 성립한다.

$$ \forall W \in S,\quad a*b \in W $$

따라서, $\span(H)$의 정의에 의해 다음이 성립한다.

$$ a*b \in \span(H) $$

따라서, closed의 정의에 의해 다음이 성립한다.

$$ \span(H) \text{ is closed under } * \qed $$

[inverse element existence]    
$\span(H)$의 정의에 의해 $\forall a \in \span(H)$에 대해 다음이 성립한다.

$$ \forall W \in S, \quad a \in W $$

이 떄, $W$는 subgroup임으로 다음이 성립한다.

$$ \forall W \in S,\quad \exist a^{-1} \in W $$

따라서, $\span(H)$의 정의에 의해 다음이 성립한다.

$$ \exist a^{-1} \in \span(H) \qed $$

[결론]
따라서, subgroup의 성질에의해 다음이 성립한다.

$$ \span(H) \le G \qed $$


### 명제2
아벨 군 $(G,+)$가 있을 때, $x \in G$에 대해 $span(\{ x \}) = \{ nx | n \in \Z \}$을 증명하여라.

이 때, $nx = \begin{cases} \underbrace{x + \cdots + x}_{n} & 0 < n \\ 0_G & n= 0 \\ \underbrace{ x^{-1} + \cdots + x^{-1} } _ {|n|} & n < 0 \end{cases}$ 를 의미한다.

**Proof**  

[$\{ nx | n \in \Z \}$ is group ]  
$\{ nx | n \in \Z \}$은 $+$ 연산에 닫혀있고 임의의 $mx$의 역원은 $-mx$임으로 역원도 가지고 있다. $\quad {_\blacksquare}$

[ $\{ nx|n \in \Z\}$ is smallest ]  
$H := \{ W | \{x\} \subseteq W \land W \le G \}$과 $W \in H$에 대해, $\{ nx|n \in \Z\}$는 연산에 닫혀있고 항등원과 각 원소의 역원이 존재할 최소 집합임으로, $\{ nx|n \in \Z\} \in W$이다. $\quad {_\blacksquare}$

#### 따름명제
아벨 군 $(G,+)$과 $x,y \in G$에 대해 $span( \{ x,y\})=\{nx + my | n,m \in \Z \}$을 증명하여라. 

**proof**

명제 2와 동일하게 증명 가능하다.