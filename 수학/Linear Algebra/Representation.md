# Matrix representation of a vector
$n$ 차원 vector space $V / \mathbb F$와 기저 $\beta$가 있다고 하자.

$v = a^i \beta_i \in V$의 $\beta$에 대한 `행렬표현(matrix representation)` $\frak m_\beta(v)$은 다음과 같이 정의된 함수이다.
$$ \frak m_\beta : V \rightarrow M_{n1}(\mathbb F) \quad s.t. \quad v \mapsto \begin{bmatrix} a^1 \\ \vdots \\ a^n \end{bmatrix} $$  

### 참고1
$\frak m_\beta(v)$를 $v$의 `좌표(coordinate)`라고도 한다.

### 참고2
편의성을 위해 $M_{n1}(\mathbb F)$를 $\mathbb F^n$으로 표기한다.

### 명제1
$n$차원 vector space $V / \mathbb F$와 기저 $\beta$가 있을 때, $v \in V$에 대해 다음을 증명하여라.
$$ \frak m_\beta(v) \text{ is well defined.} $$

**proof**

$v = a^i \beta_i = b^i \beta_i \in V$라 하면 다음이 성립한다.
$$ (a^i -b^i) \beta_i = 0_V $$

$\beta$는 linearly independent함으로 다음이 성립한다.
$$ a^i = b^i $$

즉, $\frak m_\beta(v)$가 유일하게 결정됨으로, $\frak m_\beta$는 well defined다. $\quad {_\blacksquare}$

### 명제2
$n$차원 vector space $V/ \mathbb F$와 기저 $\beta$가 있다고 하자.

$v \in V$에 대해 다음을 증명하여라.
$$ \frak m_\beta(v) \text{ is a vector space isomorphism} $$

**Proof**

[$m_\beta \in L(V; \mathbb F^n)$]  
$v_1 = a^i\beta_i, \enspace v_2 = b^i\beta_i \in V, \enspace c \in \mathbb F$가 있을 때 다음이 성립한다.
$$ \frak m_\beta(cv_1 + v_2) = \begin{bmatrix} ca^1 + b_1 \\ \vdots \\ ca^n+ b_n \end{bmatrix} = c\begin{bmatrix} a^1 \\ \vdots \\ a^n \end{bmatrix} + \begin{bmatrix} b^1 \\ \vdots \\ b^n \end{bmatrix} = c \frak m_\beta(v_1) + \frak m_\beta(v_2) $$

따라서, $m_\beta \in L(V; \mathbb F^n)$이다.

[$m_\beta$ is bijective]  
$\ker(m_\beta) = \{ 0_V \}$이고 $\dim(V) = \dim(\mathbb F^n)$임으로 dimension theorem에 의해 $m_\beta$는 bijective이다.$\quad {_\blacksquare}$

# Matrix representation of an linear map
$n$차원, $m$차원 벡터공간 $V,W / \mathbb F$와 각각의 기저 $\beta, \gamma$ 그리고 $T \in L(V;W)$가 있다고 하자.

$v = a^i\beta_i \in V, \enspace T(v) = b^i \gamma_i$일 때, $T$는 다음과 같이 나타낼 수 있다.
$$ T= c^i_jf^j_i, \enspace i=1,\cdots,m, \enspace j=1, \cdots, n $$

$$ \text{Where, } f^j_i(\beta_k) = \delta^j_k \gamma_i, \enspace b^i =c^i_ja^j $$

이 떄, $T$의 $\beta,\gamma$에 대한 `행렬표현(matrix representation)` $\frak m_\beta^\gamma(v)$은 다음과 같이 정의된 함수이다.
$$ \frak m_\beta^\gamma : L(V;W) \rightarrow M_{mn}(\mathbb F) \quad s.t. \quad T \mapsto \begin{bmatrix} c^1_1 & \cdots & c^1_n \\ \vdots & \ddots & \vdots \\ c^m_1 & \cdots & c^m_n \\ \end{bmatrix} $$  

### 참고1
$T$의 행렬 표현은 다음과 같이 나타낼 수 있다.
$$\frak m^\gamma_\beta(T) = \begin{bmatrix} \frak m_\gamma(T(\beta_1)) & \cdots & \frak m_\gamma(T(\beta_n)) \end{bmatrix}  $$

따라서 $\frak m^\gamma_\beta(T) = A$라 할 때, 다음이 성립한다.
$$ T(\beta_i) = A^j_i \gamma_j $$

### 참고2
$b^i =c^i_ja^j$임으로 행렬 곱의 성질에 의해 다음이 성립한다.
$$ \frak m_\gamma(T(v)) = \frak m^\gamma_\beta(T) \frak m_\beta(v) $$

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

$T_1 = a^i_jf^j_i \in L(V;W), \enspace T_2 = b^i_jg^j_i \in L(W;Z), \enspace T_2 \circ T_1 = c^i_jh^j_i$가 있을때, 다음을 증명하여라.
$$ \frak m^\gamma_\alpha(T_2 \circ T_1) = \frak m^\gamma_\beta(T_2) \frak m^\beta_\alpha(T_1) $$


**proof**

$T_2 \circ T_1(\alpha_k) = c^i_jh^j_i(\alpha_k)$임으로 다음이 성립한다.
$$ c^i_jh^j_i(\alpha_k) = c^i_j \delta^j_k \gamma_i = c^i_k \gamma_i $$

동시에, $T_2 \circ T_1(\alpha_k) = T_2 (T_1(\alpha_k))$임으로 다음이 성립한다.
$$ a^i_j b^k_l g^l_k(f^j_i(\alpha_m)) = a^i_j b^k_l \delta ^j_m g^l_k (\beta_i) = a^i_m b^k_l \delta^l_i \gamma_k = a^l_m b^k_l \gamma_k =  b^i_j a^j_k \gamma_i $$

두 식을 비교하면 다음이 성립한다.
$$ c^i_j = b^i_ka^k_j $$

따라서, 행렬의 곱의 성질에 의해 다음이 성립한다.
$$ \frak m^\gamma_\alpha(T_2 \circ T_1) = \frak m^\gamma_\beta(T_2) \frak m^\beta_\alpha(T_1) $$

### 명제4
차원이 각 각 $n,m$인 vector space $V,W/ \mathbb F$와 각각의 기저 $\beta, \gamma$가 있다고 하자. $\mathbb F^n,\mathbb F^m$의 기준 기저를 $\epsilon^n,\epsilon^m$라 하면 $f \in L(\mathbb F^n; \mathbb F^m), \enspace T \in L(V; W)$에 대해 다음이 성립함을 증명하여라.
$$ \frak m^{\epsilon^m}_{\epsilon^n}(f) = \frak m^\gamma_\beta(T) $$

$$ \begin{CD} V @>T>> W \\ @V{\frak m_\beta}VV @VV{\frak m_\gamma}V \\ \mathbb F^n @>>f> \mathbb F^m  \end{CD} $$

**Proof**

$\frak m_\beta$은 vector space isomorphism임으로 다음이 성립한다.
$$ f = \frak m_\gamma \circ T \circ \frak m_\beta^{-1} $$

명제3에 의해 다음이 성립한다.
$$\frak m^{\epsilon^m}_{\epsilon^n}(f) = \frak m^{\epsilon^m}_{\gamma}(\frak m_\gamma) \frak m^\gamma_\beta(T) \frak m^{\beta}_{\epsilon^n}(\frak m_\beta^{-1})$$

이 때, $\frak m^{\epsilon^m}_{\gamma}(\frak m_\gamma)$와 $\frak m^{\beta}_ {\epsilon^n}(\frak m_\beta^{-1})$는 다음과 같다.
$$ \frak m^{\epsilon^m}_{\gamma}(\frak m_\gamma) = \begin{bmatrix} \frak m_{\epsilon^m}(\frak m_\gamma(\gamma_1)) & \cdots & \frak m_{\epsilon^m}(\frak m_\gamma(\gamma_m)) \end{bmatrix}  = I_m \\ \frak m^{\beta}_{\epsilon^n}(\frak m_\beta^{-1}) = \begin{bmatrix} \frak m_{\beta}(\frak m_\beta^{-1}(\epsilon^n_1)) & \cdots & \frak m_{\beta}(\frak m_\beta^{-1}(\epsilon^n_n)) \end{bmatrix} = I_n $$

따라서 다음이 성립한다.
$$ \begin{aligned} \frak m^{\epsilon^m}_{\epsilon^n}(f) &= \frak m^{\epsilon^m}_{\gamma}(\frak m_\gamma) \frak m^\gamma_\beta(T) \frak m^{\beta}_{\epsilon^n}(\frak m_\beta^{-1}) \\ &= I_m \frak m^\gamma_\beta(T) I_n \\ &= \frak m^\gamma_\beta(T) \quad {_\blacksquare} \end{aligned}  $$

### 명제5
$n$ 차원 vector space $V / \mathbb F$와 $U,W \le V$ 그리고 $T \in \text{End}(V)$가 있다고 하자.

이 때, $V = U \oplus W$이고 $U,W$가 $T$ invariant일 때 $V,U,W$ 각각의 기저 $\alpha, \beta, \gamma$에 대해 다음을 증명하여라.
$$ \frak m_\alpha^\alpha(T) = \begin{bmatrix} \begin{array}{c | c} \frak m_\beta^\beta(T|_U) & 0 \\ \hline  0 & \frak m_\gamma^\gamma(T|_W) \end{array} \end{bmatrix} $$

**Proof**

$\dim(U) =k$라고 하자.

$V = U \oplus W$임으로 다음이 성립한다.
$$ \alpha = \beta \cup \gamma = \{ \beta_1, \cdots, \beta_k, \gamma_1, \cdots, \gamma_{n-k} \} $$ 

이 떄, $U,W$가 $T$ invariant임으로 다음이 성립한다.
$$ \begin{aligned} \frak m_\alpha^\alpha(T) &= \begin{bmatrix} \frak m_\alpha (T(\beta_1)) & \cdots & \frak m_\alpha (T(\beta_k)) & \frak m_\alpha (T(\gamma_1)) & \frak m_\alpha (T(\gamma_{n-k})) \end{bmatrix} \\ &= \begin{bmatrix} \frak m_\beta (T(\beta_1)) & \cdots & \frak m_\beta (T(\beta_k)) & \frak m_\beta (T(\gamma_1)) & \frak m_\beta (T(\gamma_{n-k})) \\ \frak m_\gamma (T(\beta_1)) & \cdots & \frak m_\gamma (T(\beta_k)) & \frak m_\gamma (T(\gamma_1)) & \frak m_\gamma (T(\gamma_{n-k})) \end{bmatrix} \\ &= \begin{bmatrix} \frak m_\beta^\beta (T|_U) & \frak m_\beta^\beta (T|_W) \\ \frak m_\gamma^\gamma (T|_U) & \frak m_\gamma^\gamma (T|_W) \end{bmatrix} \\ &= \begin{bmatrix} \begin{array}{c | c} \frak m_\beta^\beta(T|_U) & 0 \\ \hline  0 & \frak m_\gamma^\gamma(T|_W) \end{array} \end{bmatrix} \quad {_\blacksquare} \end{aligned} $$