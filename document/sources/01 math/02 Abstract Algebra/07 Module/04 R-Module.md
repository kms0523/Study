# R-Module
## 정의
Abelian group $A$와 ring $R$이 있다고 하자.

$R$이 commutative ring일 때, $A$와 $R$ 그리고 action of $R$ on $A$ $\cdot$이 주어진 대수구조를 `R-가군(R-module)`이라고 한다. 

### 명제1
Abelian group $A$와 commutative ring $R$이 있다고 하자.

이 때, $_RA$나 $A_R$이 주어졌을 떄, 다음을 증명하여라.

$$ \exist A_R \text{ or } _RA \st {_RA} = A_R $$

**Proof**

먼저, left action of $R$ on $A$ $\cdot_L$이 주어져 $_RA$가 주어졌다고 하자.

이 떄, $\cdot_R$을 다음과 같이 정의하자.

$$ \begin{gathered} \forall x \in A, \quad \forall r \in R, \quad r \cdot_L x = x \cdot_R r \\ \cdot_R \text{ is right action of } R \text{ on } A \end{gathered}  $$

그러면 $\forall r_1,r_2 \in R, \quad \forall m_1,m_2 \in M,$ 다음이 성립한다.

$$ \begin{aligned} (r_1 + r_2) \cdot_L m_1 &= r_1 \cdot_L m_1 + r_2 \cdot_L m_1 \\&= m_1 \cdot_R r_1 + m_1 \cdot_R r_2 \\&= m_1 \cdot_R (r_1 + r_2) \\ r_1 \cdot_L (m_1 + m_2) &= r_1 \cdot_L m_1 + r_1 \cdot_L m_2 \\&= m_1 \cdot_R r_1 + m_2 \cdot_R r_1 \\&= (m_1 + m_2)\cdot_R r_2 \\ (r_1 \cdot r_2)\cdot_Lm_1 &= r_1 \cdot_L (r_2 \cdot_L m_1) \\&= r_1 \cdot_L (m_1 \cdot_R r_2) \\&= (m_1 \cdot_R r_2) \cdot_R r_1 \\&= m_1 \cdot_R (r_2 \cdot r_1) \\&= m_1 \cdot_r (r_1 \cdot r_2) \\ 1_R \cdot_L m_1 &= m_1 \cdot_R 1_R  \end{aligned} $$

즉, $\cdot_L$과 $\cdot_R$이 같은 값을 갖음으로 두 action은 동일하다.

따라서 $\cdot_R$을 갖는 right module을 $A_R$이라 하면 다음이 성립한다.

$$ _RA = A_R $$

똑같이, right action of $R$ on $A$ $\cdot_R$이 주어져 $A_R$이 주어져있을 떄도, 동일한 과정을 거쳐서 다음을 증명할 수 있다.

$$ _RA = A_R \qed $$

> Reference  
> [math.stackexchange1](https://math.stackexchange.com/questions/773402/modules-over-commutative-rings)  
> [math.stackexchange2](https://math.stackexchange.com/questions/2203324/when-ring-is-commutative-prove-that-left-and-right-modules-coincide)


#### 참고1
left action이 주어져도 left action과 동일한 right action을 정의할 수 있으며, 그 반대도 마찬가지임으로 left, right action의 구분이 무의미하다.

따라서, left module과 right module의 구분이 무의미해진다.

#### 참고2
commutative ring이 아니더라도 다른 성질들은 성립하지만 $(r_1 \cdot r_2)\cdot_Lm_1 = m_1 \cdot_r (r_1 \cdot r_2)$은 오직 commutative ring일 때만 성립한다.

따라서, commutative ring일 때만 left module과 right module의 구분이 무의미해진다.