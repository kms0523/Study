# Right Module
## 정의
Abelian group $A$와 ring $R$이 있다고 하자.

`오른쪽 가군(right module)` $A_R$은 $A$와 $R$ 그리고 right action of $R$ on $A$ $\cdot$이 주어진 대수구조이다.

### 명제1
Right module $_RA$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ \forall x \in M, \quad  x0_R =0_M $$

**Proof**

Ring의 성질에 의해 다음이 성립한다.

$$ \forall x\in M, \quad x0_R = x(0_R + 0_R) $$

Right action의 성질에 의해 다음이 성립한다. 

$$ x(0_R + 0_R) = x0_R + x0_R $$

또한, monoid의 성질에 의해 다음이 성립한다.

$$ \forall x\in M, \quad x0_R = x0_R + 0_M $$

위의 결과를 종합하면 다음이 성립한다.

$$ \forall x\in M, \quad x0_R + x0_R = x0_R + 0_M $$

Group의 성질에 의해 다음이 성립한다.

$$ \forall x\in M, \quad x0_R =0_M \qed $$

### 명제2
Right module $_RA$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ \forall x \in M, \quad x^{-1} = -x $$

**Proof**

Right action의 성질에 의해 다음이 성립한다. 

$$ \forall x \in M, \quad \begin{gathered} -x + x = x(-1_R + 1_R) = x0_R \\ x + (-x) = x(1_R + -1_R) = x0_R  \end{gathered}  $$

명제1에의해 다음이 성립한다.

$$ \forall x \in M, \quad \begin{gathered} -x + x = 0_M \\ x + (-x) = 0_M  \end{gathered}  $$

따라서, inverse element의 정에의해 다음이 성립한다.

$$ \forall x \in M, \quad x^{-1} = -x \qed $$