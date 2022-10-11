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
$v \in V$에 대해 $f_v$와 $g_v$를 다음과 같이 정의하자.
$$ \begin{gathered} f_v : V \rightarrow \mathbb F \quad s.t. \quad x \mapsto B(x,v) \\ g_v : V \rightarrow \mathbb F \quad s.t. \quad x \mapsto B(T(x),v) \end{gathered}  $$

Riesz representation theorem에 의해서 다음이 성립한다.
$$ \exist! v_{g_v} \in V \quad s.t. \quad g_v = f_{v_{g_v}}$$

이 떄, 함수 $T^*$를 다음과 같이 정의하자.
$$ T^* : V \rightarrow V  \quad s.t. \quad v \mapsto v_{g_v} $$

$x,y_1,y_2 \in V, \enspace c \in \mathbb F$가 있을 때, $T^*$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} B(x, T^*(y_1 + cy_2)) &= B( x, v_{f_{y_1 + cy_2}}) \\&= f_{y_1 + cy_2}(x) \\&= B(T(x), y_1 +cy_2) \\&= B(T(x),y_1) + \overline c B(T(x),y_2) \\&= B(x, v_{f_{y_1}}) + B(x, cv_{f_{y_2}}) \\&= B(x, T^*(y_1) + cT^*(y_2)) \end{aligned} $$

즉, $T^*(y_1 + cy_2) = T^*(y_1) + cT^*(y_2)$이다.

다음과 같이 정의된 $T^* \in \text{End}(V)$이고 $B(T(x),y) = B(x, T^*(y))$를 만족함으로, adjoint operator가 적어도 하나 이상 존재한다. $\quad {_\blacksquare}$

[Uniquness]  
$T \in \text{End}(V)$의 adjoint operator가 $T^*_1, T^*_2$라 하자.

$\forall x,y \in V$에 대해 다음이 성립한다.
$$ \begin{aligned} & B(T(x),y) = B(x, T^*_1(y)) = B(x, T^*_2(y)) \\ \Rightarrow & \enspace B(x, T^*_1(y) - T^*_2(y)) = 0_\mathbb F \\ \Rightarrow & T^*_1(y) - T^*_2(y) = 0_V \end{aligned} $$

즉, 모든 $y \in V$에 대해서 $T^*_1(y) = T^*_2(y)$임으로, $T^*_1 = T^*_2$이고 adjoint operator는 unique하다. $\quad {_\blacksquare}$

### 명제2
$n$차원 inner product space $V / \mathbb F$와 $T \in \text{End}(V)$가 있다고 하자.

$\beta$를 $V$의 orthonormal basis라 할 때, 다음을 증명하여라.
$$ \frak m_\beta^\beta(T^*) = \frak m_\beta^\beta(T)^* $$

**Proof**

$\beta$가 orthonormal basis임으로 다음이 성립한다.
$$ \begin{aligned} T(\beta_j) &= B(T(\beta_j),\beta_i)\beta_i, \\ T^*(\beta_j) &= B(T^*(\beta_j),\beta_i)\beta_i \\&= \overline{B(\beta_i, T^*(\beta_j))}\beta_i \\&= \overline{B(T(\beta_i), \beta_j)}\beta_i \end{aligned}  $$

따라서, 다음이 성립한다.
$$ \begin{aligned} \frak m_\beta^\beta(T^*) &= \begin{bmatrix} \frak m_\beta(T^*(\beta_1)) & \cdots & \frak m_\beta(T^*(\beta_n)) \end{bmatrix} \\ &= \begin{bmatrix} \overline{B(T(\beta_1), \beta_1)} & \cdots &\overline{B(T(\beta_1), \beta_n)} \\ \vdots & & \vdots \\ \overline{B(T(\beta_n), \beta_1)} & \cdots &\overline{B(T(\beta_n), \beta_n)} \end{bmatrix} \\ &= \begin{bmatrix} B(T(\beta_1), \beta_1) & \cdots &B(T(\beta_n), \beta_1) \\ \vdots & & \vdots \\ B(T(\beta_1), \beta_n) & \cdots &B(T(\beta_n), \beta_n) \end{bmatrix}^* \\ &= \frak m_\beta^\beta(T)^* \end{aligned}  $$

#### 따름명제
$A \in M_{nn}(\mathbb F)$가 있을 때, 다음을 증명하여라.
$$ (L_A)^* = L_{A^*} $$

#### 참고
matrix representation이 adjoint matrix 형태로 나타나기 때문에 adjoint operator라고 표현한다.

### 명제3
$n$차원 inner product space $V / \mathbb F$와 $T \in \text{End}(V)$가 있다고 하자.

이 때, 다음을 증명하여라.
$$B(T^*(x),y) = B(x, T(y))$$

**Proof**

$$\begin{aligned} B(T^*(x),y) &= \overline{B(y, T^*(x))} \\ &= \overline{B(T(y), x)} \\&= B(x, T(y)) \quad {_\blacksquare} \end{aligned} $$

### 명제4
$n$차원 inner product space $V / \mathbb F$와 $T \in \text{End}(V)$가 있다고 하자.

이 때, 다음을 증명하여라.
$$(T_1 \circ T_2)^* = T^*_2 \circ T^*_1$$

**Proof**

$\forall x,y \in V$에 대해 다음이 성립한다. 
$$ \begin{aligned} B(x, (T_1\circ T_2)^*(y)) &= B((T_1\circ T_2)(x), y) \\&= B(T_2(x), T_1^*(y)) \\&= B(x, T_2^*(T_1^*(y))) \\&= B(x, (T_2^* \circ T_1^*)(y)) \end{aligned} $$

따라서 $(T_1 \circ T_2)^* = T^*_2 \circ T^*_1$이다. $\quad {_\blacksquare}$

### 명제5
$n$차원 inner product space $V / \mathbb F$와 $T \in \text{End}(V)$가 있다고 하자.

이 때, 다음을 증명하여라.
$$(T^*)^* = T$$

**Proof**

$\forall x,y \in V$에 대해 다음이 성립한다. 
$$ B(x, (T^*)^*(y)) = B(T^*(x), y) = B(x, T(y)) $$

따라서 $(T^*)^* = T$이다. $\quad {_\blacksquare}$

### 명제6
$n$차원 inner product space $V / \mathbb F$가 있다고 하자.

이 때, 다음을 증명하여라.
$$(id_V)^* = id_V$$

**Proof**

$\forall x,y \in V$에 대해 다음이 성립한다. 
$$ B(x, (id_V)^*(y)) = B(id_V(x), y) = B(x, id_V(y)) $$

따라서 $(id_V)^* = id_V$이다. $\quad {_\blacksquare}$

### 명제7
$n$차원 inner product space $V / \mathbb F$와 $T \in \text{End}(V)$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ \lambda \text{ is an eigenvalue of } T \Rightarrow \overline\lambda \text{ is an eigenvalue of } T^* $$

**Proof**

$\beta$가 $V$의 orthonormal baiss이고 $\lambda$가 $T$의 eigenvalue 임으로 다음이 성립한다.
$$ \begin{aligned} & \det(T - \lambda id) = 0 \\ \Rightarrow \enspace & \det(\frak m_\beta^\beta(T - \lambda id)) = 0 \\ \Rightarrow \enspace & \det(\frak m_\beta^\beta(T) - \lambda I) = 0 \\ \Rightarrow \enspace & \det(\frak m_\beta^\beta(T)^* - \overline\lambda I) = 0 \\ \Rightarrow \enspace & \det(\frak m_\beta^\beta(T^*) - \overline\lambda I) = 0 \\ \Rightarrow \enspace & \det(\frak m_\beta^\beta(T^*- \overline\lambda id)) = 0 \\ \Rightarrow \enspace & \det(T^*- \overline\lambda id) = 0 \quad {_\blacksquare} \end{aligned} $$

#### 참고
$T$의 eigen vector를 $v$라 할 떄, $v$는 $T^*$의 eigen vector가 아니다.

**Proof**

$A \in M_{22}(\R)$이 다음과 같이 정의되었다고 하자.
$$ A := \begin{bmatrix} 1 & 1 \\ 0 & 1  \end{bmatrix} $$

eigen vector를 계산해보면 $v = \begin{bmatrix} 0 \\ 1 \end{bmatrix}$임을 알 수 있다.

$L_A$의 adjoint operator를 $L_{A^*}$라 하면 다음이 성립한다.
$$ A^* := \begin{bmatrix} 1 & 0 \\ 1 & 1 \end{bmatrix} $$

eigen vector를 계산해보면 $w = \begin{bmatrix} 1 \\ 0 \end{bmatrix}$임을 알 수 있다.

따라서, $T$의 eigen vector $v$는 $T^*$의 eigen vector가 아니다.

### 계산연습
$V : \{ ax+b \}, B(f,g) = \int_{-1}^1 fg \thinspace dx, T(f) = 3f + f'$

이 떄, $T^*(4-2x) =?$

1) adjoint operator의 성질 이용

2) orthonormality를 이용한 표현법을 이용