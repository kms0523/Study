# Left Module
## 정의
Abelian group $A$와 ring $R$이 있다고 하자.

`왼쪽 가군(left module)` $_RA$는 $A$와 $R$ 그리고 left action of $R$ on $A$ $\cdot$이 주어진 algebraic structure이다.

### 명제1
Left module $_RA$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ \forall x \in M, \quad  0_Rx =0_M $$

**Proof**

Ring의 성질에 의해 다음이 성립한다.

$$ \forall x\in M, \quad 0_Rx = (0_R + 0_R)x $$

Left action의 성질에 의해 다음이 성립한다. 

$$ (0_R + 0_R)x = 0_Rx + 0_Rx $$

또한, monoid의 성질에 의해 다음이 성립한다.

$$ \forall x\in M, \quad 0_Rx = 0_Rx + 0_M $$

위의 결과를 종합하면 다음이 성립한다.

$$ \forall x\in M, \quad 0_Rx + 0_Rx = 0_Rx + 0_M $$

Group의 성질에 의해 다음이 성립한다.

$$ \forall x\in M, \quad 0_Rx =0_M \qed $$

### 명제2
Left module $_RA$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ \forall x \in M, \quad x^{-1} = -x $$

**Proof**

Left action의 성질에 의해 다음이 성립한다. 

$$ \forall x \in M, \quad \begin{gathered} -x + x = (-1_R + 1_R)x = 0_Rx \\ x + (-x) = (1_R + -1_R)x = 0_Rx  \end{gathered}  $$

명제1에의해 다음이 성립한다.

$$ \forall x \in M, \quad \begin{gathered} -x + x = 0_M \\ x + (-x) = 0_M  \end{gathered}  $$

따라서, inverse element의 정에의해 다음이 성립한다.

$$ \forall x \in M, \quad x^{-1} = -x \qed $$