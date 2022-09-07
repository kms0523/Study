# Adjoint of a Matrix
$A \in M_{mn}(\mathbb F)$가 있다고 하자. $A$의 `adjoint` $A^*$는 다음과 같이 정의된 행렬이다.
$$ A^* \in M_{nm}(\mathbb F) \quad s.t. \quad A^*_{ij} = \overline{A_{ji}} $$

### 참고
$\mathbb F = \R$이면, adjoint는 단순히 transpose가 되며, $A = A^*$인 경우를  $A$가 symmetric하다고 한다.

만약, $\mathbb F = \R$이면, $A = A^*$인 경우를  $A$를 Hermitian이라고 한다.

# Adjoint of a Linear Operator
$n$차원 inner product space $V / \mathbb F$와 $T \in \text{End}(V)$가 있다고 하자.

$x,y \in V$에 대해서 다음을 만족하는 $T^* \in \text{End}(V)$를 $T$의 `adjoint operator`라 한다.
$$B(T(x),y) = B(x, T^*(y))$$

### 명제1
$n$차원 inner product space $V / \mathbb F$와 $T \in \text{End}(V)$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ \exist! T^* $$

**Proof**

[Existence]  
$y \in V$가 있다고 하자.

linear fuctinal $f_y$를 다음과 같이 정의하자.
$$ f_y \in V^* \quad s.t. \quad x \mapsto B(T(x),y) $$

$\beta$를 $V$의 orthonormal basis라 할 때, Rieze representation theorem에 의해서 다음이 성립한다.
$$ v_{f_y} = f_y(\beta_i)\beta_i \in V \quad s.t. \quad f_y(x) = B(x, v_{f_y})$$

이 떄, 함수 $T^*$를 다음과 같이 정의하자.
$$ T^* : V \rightarrow V  \quad s.t. \quad y \mapsto v_{f_y} $$

$x,y_1,y_2 \in V, \enspace c \in \mathbb F$가 있을 때, $T^*$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} B(x, T^*(y_1 + cy_2)) &= B( x, v_{f_{y_1 + cy_2}}) \\&= f_{y_1 + cy_2}(x) \\&= B(T(x), y_1 +cy_2) \\&= B(T(x),y_1) + \overline c B(T(x),y_2) \\&= B(x, v_{f_{y_1}}) + B(x, cv_{f_{y_2}}) \\&= B(x, T^*(y_1) + cT^*(y_2)) \end{aligned} $$

즉, $T^*(y_1 + cy_2) = T^*(y_1) + cT^*(y_2)$이다.

다음과 같이 정의된 $T^* \in \text{End}(V)$이고 $B(T(x),y) = B(x, T^*(y))$를 만족함으로, adjoint operator가 적어도 하나 이상 존재한다. $\quad {_\blacksquare}$

