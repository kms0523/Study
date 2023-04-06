# Matrix representation
## Vector
$n$ 차원 vector space $V / \mathbb F$와 기저 $\beta$가 있다고 하자.

$v = a^i \beta_i \in V$의 $\beta$에 대한 `행렬표현(matrix representation)` $\frak m_\beta(v)$은 다음과 같이 정의된 함수이다.

$$ \frak m_\beta : V \rightarrow M_{n1}(\mathbb F) \quad s.t. \quad v \mapsto \begin{bmatrix} a^1 \\ \vdots \\ a^n \end{bmatrix} $$  

### 명제1
$n$차원 vector space $V / \mathbb F$와 기저 $\beta$가 있을 때, $v \in V$에 대해 다음을 증명하여라.

$$ \frak m_\beta \text{ is well defined.} $$

**proof**

$v = a^i \beta_i = b^i \beta_i \in V$라 하면 다음이 성립한다.

$$ (a^i -b^i) \beta_i = 0_V $$

$\beta$는 linearly independent함으로 다음이 성립한다.

$$ a^i = b^i $$

즉, $\frak m_\beta(v)$가 유일하게 결정됨으로, $\frak m_\beta$는 well defined다. $\quad\tiny\blacksquare$

### 명제2
$n$차원 vector space $V/ \mathbb F$와 기저 $\beta$가 있다고 하자.

$v \in V$에 대해 다음을 증명하여라.

$$ \frak m_\beta \text{ is a vector space isomorphism} $$

**Proof**

[$m_\beta \in L(V; \mathbb M_{n1}(\mathbb F))$]  
$v_1 = a^i\beta_i, \enspace v_2 = b^i\beta_i \in V, \enspace c \in \mathbb F$가 있을 때 다음이 성립한다.


$$ \frak m_\beta(cv_1 + v_2) = \begin{bmatrix} ca^1 + b_1 \\ \vdots \\ ca^n+ b_n \end{bmatrix} = c\begin{bmatrix} a^1 \\ \vdots \\ a^n \end{bmatrix} + \begin{bmatrix} b^1 \\ \vdots \\ b^n \end{bmatrix} = c \frak m_\beta(v_1) + \frak m_\beta(v_2) $$

따라서, $m_\beta \in L(V; \mathbb M_{n1}(\mathbb F))$이다.

[$m_\beta$ is bijective]  
$\ker(m_\beta) = \{ 0_V \}$이고 $\dim(V) = \dim(\mathbb M_{n1}(\mathbb F))$임으로 dimension theorem에 의해 $m_\beta$는 bijective이다.$\quad\tiny\blacksquare$

## Linear Map
$n,m$차원 벡터공간 $V,W / \F$와 $T \in L(V;W)$가 있다고 하자.

$V,W$ 각각의 기저를 $\beta, \gamma$라고 할 때, $V$의 임의의 elemnt를 $v$와 $T(v)$를 다음과 같이 표현하자.

$$ v = a^i\beta_i, \enspace T(v) = b^j\gamma_j $$

이 떄, $T$는 linear map임으로 다음이 성립한다.

$$ \begin{aligned} T(v) &= T(a^i\beta_i) \\&= a^iT(\beta_i) \end{aligned} $$

이 떄 $T(\beta_i) = A^j_i\gamma_j$라고 하면 다음이 성립한다.

$$ T(v) = a^iA^j_i\gamma_j = b^j\gamma_j $$

이를 행렬 형태로 나타내면 다음과 같다.

$$ \begin{bmatrix} b^1 \\ \vdots \\ b^m \end{bmatrix} =  \begin{bmatrix} A^1_1 & \cdots & A^1_n \\ \vdots & \ddots & \vdots \\ A^m_1 & \cdots & A^m_n \\ \end{bmatrix} \begin{bmatrix} a^1 \\ \vdots \\ a^n \end{bmatrix} $$

따라서, $T$의 $\beta,\gamma$에 대한 `행렬표현(matrix representation)` $\frak m_\beta^\gamma$은 다음과 같이 정의된 함수이다.

$$ \frak m_\beta^\gamma : L(V;W) \rightarrow M_{mn}(\mathbb F) \quad s.t. \quad T \mapsto \begin{bmatrix} A^1_1 & \cdots & A^1_n \\ \vdots & \ddots & \vdots \\ A^m_1 & \cdots & A^m_n \\ \end{bmatrix} $$  

### 참고1
$L(V;W)$의 $\beta,\gamma$에 대한 basis를 $f^i_j, i=1,\cdots,n, j=1,\cdots,m$라고 하자.

$T \in L(V;W)$가 있을 때, $\frak{m}^\gamma_\beta(T) = A$일 때, 다음이 성립한다.

$$ T = A^j_if^i_j $$

### 참고2
$f^i_j$는 $i$ coordinate를 $j$ coordinate로 보내주는 함수임으로, $A^j_i$는 $i$ coordinate를 $j$ coordinate로 변환할 때, 얼마나 scailing 해줄 것인지를 결정하는 값이다.

행렬 곱 형태를 다음과 같이 바꿔보자.

$$ \begin{bmatrix} b^1 \\ \vdots \\ b^m \end{bmatrix} = \begin{bmatrix} A^1_1 \\ \vdots \\ A^m_1 \end{bmatrix} a^1 + \cdots $$

$a^1$ 이라는 coordinate에 $A^j_1$만큼 scailing 해준 만큼 $b^j$ coordinate에 영향을 준다는 것이 잘 들어난다.

### 참고3
$T$의 행렬 표현은 다음과 같이 나타낼 수 있다.

$$\frak m^\gamma_\beta(T) = \begin{bmatrix} \frak m_\gamma(T(\beta_1)) & \cdots & \frak m_\gamma(T(\beta_n)) \end{bmatrix}  $$

따라서 $\frak m^\gamma_\beta(T) = A$라 할 때, 다음이 성립한다.

$$ T(\beta_i) = A^j_i \gamma_j $$

### 참고4
$b^j =A^j_ia^i$임으로 다음이 성립한다.

$$ \frak m_\gamma(T(v)) = \frak m^\gamma_\beta(T) \frak m_\beta(v) $$

### 참고5
함수 $f$를 다음과 같이 정의하자.

$$ f : M_{n1} \rightarrow M_{m1} \st x \mapsto Ax $$

그러면 다음과 같은 도식을 그릴 수 있다.

$$ \begin{CD} V @>T>> W \\ @V{\frak m_\beta}VV @VV{\frak m_\gamma}V \\ M_{n1} @>>f> M_{m1} \end{CD} $$

따라서, $f$는 3가지 선형변환의 합성으로 표현할 수 있다.

$$ f = \frak m_\gamma \circ T \circ \frak m_\beta^{-1} $$

$\epsilon^n, \epsilon^m$을 $M_{n1}$의 standarad basis라고 할 때, 명제3에 의해 다음이 성립한다.

$$\frak m^{\epsilon^m}_{\epsilon^n}(f) = \frak m^{\epsilon^m}_{\gamma}(\frak m_\gamma) \frak m^\gamma_\beta(T) \frak m^{\beta}_{\epsilon^n}(\frak m_\beta^{-1})$$

이 때, $\frak m^{\epsilon^m}_{\gamma}(\frak m_\gamma)$와 $\frak m^{\beta}_ {\epsilon^n}(\frak m_\beta^{-1})$는 다음과 같다.

$$ \frak m^{\epsilon^m}_{\gamma}(\frak m_\gamma) = \begin{bmatrix} \frak m_{\epsilon^m}(\frak m_\gamma(\gamma_1)) & \cdots & \frak m_{\epsilon^m}(\frak m_\gamma(\gamma_m)) \end{bmatrix}  = I_m \\ \frak m^{\beta}_{\epsilon^n}(\frak m_\beta^{-1}) = \begin{bmatrix} \frak m_{\beta}(\frak m_\beta^{-1}(\epsilon^n_1)) & \cdots & \frak m_{\beta}(\frak m_\beta^{-1}(\epsilon^n_n)) \end{bmatrix} = I_n $$

따라서 다음이 성립한다.

$$ \begin{aligned} \frak m^{\epsilon^m}_{\epsilon^n}(f) &= \frak m^{\epsilon^m}_{\gamma}(\frak m_\gamma) \frak m^\gamma_\beta(T) \frak m^{\beta}_{\epsilon^n}(\frak m_\beta^{-1}) \\ &= I_m \frak m^\gamma_\beta(T) I_n \\ &= \frak m^\gamma_\beta(T) \end{aligned}  $$

### 명제1
차원이 각 각 $n,m$인 벡터 공간 $V,W/ \mathbb F$와 각각의 기저 $\beta, \gamma$, $T \in L(V;W)$가 있을 때, 다음을 증명하여라.

$$ \frak m_\beta^\gamma(T) \text{ is well defined.} $$

**Proof**

vector의 matrix representation 명제1과 동일한 과정으로 증명이 가능하다.

### 명제2
차원이 각 각 $n,m$인 벡터 공간 $V,W/ \mathbb F$와 각각의 기저 $\beta, \gamma$, $T \in L(V;W)$가 있을 때, 다음을 증명하여라.

$$ \frak m_\beta^\gamma(T) \text{ is a vectorspace isomorphism} $$

**proof**   

vector의 matrix representation 명제2와 동일한 과정으로 증명이 가능하다.

### 명제3
차원이 각 각 $n,m,k$인 벡터공간 $V,W,Z/ \mathbb F$와 각 각의 기저 $\alpha,\beta,\gamma$가 있다고 하자.

$T_1 \in L(V;W), \enspace T_2 \in L(W;Z)$가 있을때, 다음을 증명하여라.

$$ \frak m^\gamma_\alpha(T_2 \circ T_1) = \frak m^\gamma_\beta(T_2) \frak m^\beta_\alpha(T_1) $$


**proof**

$V$의 임의의 element를 $v$라고 할 때, $v,T_1(v), (T_2\circ T_1)(v)$를 다음과 같이 표현하자.

$$ \begin{aligned} v &= a^i\alpha_i \\ T_1(v) &= b^j\beta_j \\ (T_2\circ T_1)(v) &= c^k\gamma_k \end{aligned} $$

$\frak{m}_\alpha^\beta(T_1) = A, \frak{m}_\beta^\gamma(T_2) =B, \frak{m}_\alpha^\gamma(T_2 \circ T_1) = C$라고 하면 다음이 성립한다.

$$ \begin{aligned} T_1(v) &\implies b^j = A^j_ia^i \\ T_2(T_1(v)) &\implies c^k = B^k_j b^j \implies c^k = B^k_jA^j_i a^i \\ (T_2\circ T_1)(v) &\implies c^k = C^k_ia^i  \end{aligned} $$

따라서, 다음이 성립한다.

$$ C^k_i = B^k_jA^j_i $$

행렬의 곱의 성질에 의해 다음이 성립한다.

$$ \frak m^\gamma_\alpha(T_2 \circ T_1) = \frak m^\gamma_\beta(T_2) \frak m^\beta_\alpha(T_1) $$

### 명제4


### 명제5
$n$ 차원 vector space $V / \mathbb F$와 $U,W \le V$ 그리고 $T \in \text{End}(V)$가 있다고 하자.

이 때, $V = U \oplus W$이고 $U,W$가 $T$ invariant일 때 $V,U,W$ 각각의 기저 $\alpha, \beta, \gamma$에 대해 다음을 증명하여라.

$$ \frak m_\alpha^\alpha(T) = \begin{bmatrix} \begin{array}{c | c} \frak m_\beta^\beta(T|_U) & 0 \\ \hline  0 & \frak m_\gamma^\gamma(T|_W) \end{array} \end{bmatrix} $$

**Proof**

$\dim(U) =k$라고 하자.

$V = U \oplus W$임으로 다음이 성립한다.

$$ \alpha = \beta \cup \gamma = \{ \beta_1, \cdots, \beta_k, \gamma_1, \cdots, \gamma_{n-k} \} $$ 

이 떄, $U,W$가 $T$ invariant임으로 다음이 성립한다.

$$ \begin{aligned} \frak m_\alpha^\alpha(T) &= \begin{bmatrix} \frak m_\alpha (T(\beta_1)) & \cdots & \frak m_\alpha (T(\beta_k)) & \frak m_\alpha (T(\gamma_1)) & \cdots & \frak m_\alpha (T(\gamma_{n-k})) \end{bmatrix} \\&= \begin{bmatrix} \frak m_\beta (T(\beta_1)) & \cdots & \frak m_\beta (T(\beta_k)) & \frak m_\beta (T(\gamma_1)) & \cdots & \frak m_\beta (T(\gamma_{n-k})) \\ \frak m_\gamma (T(\beta_1)) & \cdots & \frak m_\gamma (T(\beta_k)) & \frak m_\gamma (T(\gamma_1)) & \cdots & \frak m_\gamma (T(\gamma_{n-k})) \end{bmatrix} \\&= \begin{bmatrix} \frak m_\beta^\beta (T) & \frak m_\gamma^\beta (T) \\ \frak m_\beta^\gamma (T) & \frak m_\gamma^\gamma (T) \end{bmatrix} \\&= \begin{bmatrix} \frak m_\beta^\beta (T|_U) & 0 \\ 0 & \frak m_\gamma^\gamma (T|_W) \end{bmatrix} \\&= \begin{bmatrix} \begin{array}{c | c} \frak m_\beta^\beta(T|_U) & 0 \\ \hline  0 & \frak m_\gamma^\gamma(T|_W) \end{array} \end{bmatrix} \quad\tiny\blacksquare \end{aligned} $$