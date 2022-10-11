# Normal Operator
$n$차원 inner product vector space $V / \mathbb F$와 $T \in \text{End}(V)$가 있다고 하자.

이 때, $T$가 다음 성질을 만족할 경우 `normal operator`라고 한다.
$$ T \circ T^* = T^* \circ T $$

### 명제1
$n$차원 inner product vector space $V / \mathbb F$와 normal operator $T \in \text{End}(V)$가 있다고 하자.

$x \in V$에 대해 다음을 증명하여라.
$$ \lVert T(x) \rVert = \lVert T^*(x) \rVert $$

**Proof**

adjoint operator와 normal operator의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} \lVert T(x) \rVert^2 &= B(T(x), T(X)) \\&= B(x, T^*(T(x))) \\&= B(x, T(T^*(x))) \\&= B(T^*(x), T^*(x)) \\&= \lVert T^*(x) \rVert^2 \end{aligned} $$

### 명제2
$n$차원 inner product vector space $V / \mathbb F$와 normal operator $T \in \text{End}(V)$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ T(v) = \lambda v \Rightarrow T^*(v) = \overline \lambda v $$

**Proof**

명제1에 의해 다음이 성립한다.
$$ \begin{aligned} \lVert T^*(v) - \overline\lambda v \rVert &= \lVert (T^* - \overline\lambda id)(v) \rVert \\&= \lVert (T - \lambda id)^*(v) \rVert \\&= \lVert (T - \lambda id)(v) \rVert \\&= 0 \end{aligned} $$

따라서 norm의 성질에 의해 다음이 성립한다.
$$ \lVert T^*(v) - \overline\lambda v \rVert \Rightarrow T^*(v) = \overline\lambda v \quad {_\blacksquare} $$

### 명제3
$n$차원 inner product vector space $V / \mathbb F$와 normal operator $T \in \text{End}(V)$가 있다고 하자.

$\lambda_1 \neq \lambda_2$일 때, 다음을 증명하여라.
$$ T(v_1) = \lambda_1 v_1 \enspace \land \enspace T(v_2) = \lambda_2 v_2 \Rightarrow B(v_1,v_2) = 0 $$

**Proof**

명제2에 의해 다음이 성립한다.
$$ \begin{aligned} \lambda_1 B(v_1,v_2) &= B(\lambda_1v_1, v_2) \\&= B(T(v_1),v_2) \\&= B(v_1, T^*(v_2)) \\&= B(v_1, \overline\lambda_2v_2) \\&= \lambda_2 B(v_1,v_2) \end{aligned} $$

따라서, 다음이 성립한다.
$$ (\lambda_1 - \lambda_2)B(v_1,v_2) = 0 \Rightarrow B(v_1,v_2) = 0 \quad {_\blacksquare} $$

#### 참고
$T$가 normal operator이면 eigenvector끼리 수직한다.

### 명제4
$n$차원 inner product vector space $V / \mathbb F$와 normal operator $T \in \text{End}(V)$가 있다고 하자.

$c \in \mathbb F$에 대해 다음을 증명하여라.
$$ T-cid \text{ is a normal operator }  $$

**Proof**

Normal operator의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} (T-cid) \circ (T-cid)^* &= T \circ T^* - T^* - T + c^2 id \\&= T^*\circ T - T^* - T + c^2id \\&= (T-cid)^* \circ (T-cid) \end{aligned} $$

# Normal Matrix
$A \in M_{nn}(\mathbb F)$가 있다고 하자.

이 떄, $A$가 다음 성질을 만족할 경우 `normal matrix`라고 한다.
$$AA^* = A^*A$$