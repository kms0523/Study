# Ring
## 정의
집합 $R$과 두 이항연산 $+:R \times R \rightarrow R$, $\cdot : R \times R \rightarrow R$이 있을 때, `환(ring)` $(R,+,\cdot)$이란 다음을 만족하는 대수 구조이다.

$$ \begin{gathered} (R,+) \text{ is an Abelian group} \\ (R,\cdot) \text { is a monoid } \\ \cdot \text { is distributive w.r.t. } + \end{gathered} $$
     
> Reference  
> [wiki](https://en.wikipedia.org/wiki/Ring_(mathematics)#Definition)

### 명제1
환 $R$이 있다고 하자.

이 때, 다음을 증명하여라.

$$\forall x \in R, \quad 0_Rx =0_R$$

**Proof**

$$ 0_Rx  = (0_R + 0_R)x = 0_Rx + 0_Rx \quad \land \quad 0_Rx = 0_Rx + 0_R \\ \therefore 0_Rx = 0_R \quad {_\blacksquare} $$

### 명제2

환 $(R,+,\cdot)$이 있을 때, $x,y \in R$에 대해 $(xy)^{-1}=x^{-1}y$을 증명하여라.

**proof**

$$ (x + x^{-1})y = xy + x^{-1}y = 0_R \\ \therefore (xy)^{-1} = x^{-1}y $$

