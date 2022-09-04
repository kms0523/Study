# Matrix representation of a vector
$n$ 차원 vector space $V / \mathbb F$와 기저 $\beta$가 있다고 하자.

$v = a^i \beta_i \in V$의 $\beta$에 대한 `행렬표현(matrix representation)` $\frak m_\beta(v)$은 다음과 같이 정의된 함수이다.
$$ \frak m_\beta : V \rightarrow M_{n1}(\mathbb F) \quad s.t. \quad v \mapsto \begin{bmatrix} a^1 \\ \vdots \\ a^n \end{bmatrix} $$  

### 참고
$\frak m_\beta(v)$를 $v$의 `좌표(coordinate)`라고도 한다.


### 명제1
유한 차원 vector space $V/F$와 기저 $\beta$가 있을 때, $v \in V$에 대해 다음을 증명하여라.
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

[$m_\beta \in L(V; M_{n1}(\mathbb F))$]  
$v_1 = a^i\beta_i, \enspace v_2 = b^i\beta_i \in V, \enspace c \in \mathbb F$가 있을 때 다음이 성립한다.
$$ \frak m_\beta(cv_1 + v_2) = \begin{bmatrix} ca^1 + b_1 \\ \vdots \\ ca^n+ b_n \end{bmatrix} = c\begin{bmatrix} a^1 \\ \vdots \\ a^n \end{bmatrix} + \begin{bmatrix} b^1 \\ \vdots \\ b^n \end{bmatrix} = c \frak m_\beta(v_1) + \frak m_\beta(v_2) $$

따라서, $m_\beta \in L(V; M_{n1}(\mathbb F))$이다.

[$m_\beta$ is bijective]  
$\ker(m_\beta) = \{ 0_V \}$이고 $\dim(V) = \dim(M_{n1}(\mathbb F))$임으로 dimension theorem에 의해 $m_\beta$는 bijective이다.$\quad {_\blacksquare}$

# Matrix representation of an linear map
$n$차원, $m$차원 벡터공간 $V,W / \mathbb F$와 각각의 기저 $\beta, \gamma$ 그리고 $T \in L(V;W)$가 있다고 하자.

$v = a^i\beta_i \in V, \enspace T(v) = b^i \gamma_i$일 때, $T$는 다음과 같이 나타낼 수 있다.
$$ T= c^i_jf^j_i, \enspace i=1,\cdots,m, \enspace j=1, \cdots, n $$

$$ \text{Where, } f^j_i(\beta_k) = \delta^j_k \gamma_i \enspace \land \enspace b^i =c^i_ja^j$$

이 떄, $T$의 $\beta,\gamma$에 대한 `행렬표현(matrix representation)` $\frak m_\beta^\gamma(v)$은 다음과 같이 정의된 함수이다.
$$ \frak m_\beta^\gamma : L(V;W) \rightarrow M_{mn}(\mathbb F) \quad s.t. \quad T \mapsto \begin{bmatrix} c^1_1 & \cdots & c^1_n \\ \vdots & \ddots & \vdots \\ c^m_1 & \cdots & c^m_n \\ \end{bmatrix} $$  


### 참고1
$T$의 행렬 표현은 다음과 같이 나타낼 수 있다.
$$\frak m^\gamma_\beta(T) = \begin{bmatrix} \frak m_\gamma(T(\beta_1)) & \cdots & \frak m_\gamma(T(\beta_n)) \end{bmatrix}  $$

### 참고2
행렬 곱의 성질에 의해 다음이 성립한다.
$$ \frak m_\gamma(T(v)) = \frak m^\gamma_\beta(T) \frak m_\beta(v) $$

### 참고3
$k$차원 벡터공간 $Z/ \mathbb F$와 기저 $\gamma$ 그리고 $T_1 \in L(V;W), T_2 \in L(W;Z)$가 있을때, 선형변환의 성분표현 명제1과 행렬 곱의 성질에 의해 다음이 성립한다.
$$ \frak m^\gamma_\alpha(T_2 \circ T_1) = \frak m^\gamma_\beta(T_2) \frak m^\beta_\alpha(T_1) $$

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
차원이 각 각 $n,m$인 벡터 공간 $V,W/F$와 각각의 기저 $\beta, \gamma$가 있다고 하자. $\mathbb F^n,\mathbb F^m$의 기준 기저를 $\epsilon_n,\epsilon_m$라 하면 $f \in L(\mathbb F^n; \mathbb F^m), \enspace T \in L(V; W)$에 대해 다음이 성립함을 증명하여라.
$$ \frak t^{\epsilon_m}_{\epsilon_n}(f) = \frak t^\gamma_\beta(T) $$

$$ \begin{CD} V @>T>> W \\ @V{\frak t_\beta}VV @VV{t_\gamma}V \\ \mathbb F^n @>>f> \mathbb F^m  \end{CD} $$

**Proof**

$\frak t_\beta$은 vector space isomorphism임으로 다음이 성립한다.
$$ f = \frak t_\gamma \circ T \circ \frak t_\beta^{-1} $$

따라서, 명제2에 의해 다음이 성립한다.
$$ f^i_j = A^i_k T^k_l B^l_j $$

$$ \begin{aligned} \text{Where, } \frak t^{\epsilon_m}_{\epsilon_n}(f) &:= (f^1_1, \cdots, f^m_1, \cdots, f^1_n, \cdots, f^m_n) \\ \frak t^\gamma_\beta(T) &:= (T^1_1, \cdots, T^m_1, \cdots, T^1_n, \cdots, T^m_n) \\ \frak t^{\epsilon_m}_\gamma(\frak t_\gamma) &:= (A^1_1, \cdots, A^m_1, \cdots, A^1_m, \cdots, A^m_m) \\ \frak t^\beta_{\epsilon_n}(\frak t_\beta^{-1}) &:= (B^1_1, \cdots, B^n_1, \cdots, B^1_n, \cdots, B^n_n) \end{aligned} $$

이 때, $A^i_k$와 $B^l_j$는 다음과 같다.
$$ A^i_k = \frak t_{\epsilon_m}( \frak t_\gamma(\gamma_k))^i = \delta^i_k \\ B^l_j = \frak t_{\beta}( \frak t_\beta^{-1}(\epsilon_{n,j}))^l = \delta^l_j $$

따라서 다음이 성립한다.
$$ \begin{aligned} f^i_j &= A^i_k T^k_l B^l_j \\ &= \delta^i_k T^k_l \delta^l_j \\ &=T^i_j \quad {_\blacksquare} \end{aligned}  $$














---

# Matrix Representation


## Componentwise representation of a vector
$n$ 차원 vector space $V / \mathbb F$와 기저 $\beta$가 있다고 하자.

$v = a^i \beta_i \in V$의 $\beta$에 대한 `성분표현(componentwise representation)` $\frak t_\beta(v)$은 다음과 같이 정의된 함수이다.

$$ \frak t_\beta(v) : V \rightarrow \mathbb F^n \quad s.t. \quad v \mapsto (a^1, \cdots, a^n) $$  

$n-$tuple인 $\frak t_\beta(v)$를 `좌표(coordinate)`라고도 한다.

이 때, $\frak t_\beta(v)^i$는 tuple의 $i$번째 요소를 가르킴으로 $v$를 다음과 같이 표현 할 수도 있다.
$$ v= \frak t_\beta(v)^i \beta_i $$


### 명제1
유한 차원 벡터 공간 $V/F$와 기저 $\beta$가 있을 때, $v \in V$에 대해 다음을 증명하여라.
$$ \frak t_\beta(v) \text{ is well defined.} $$

**proof**

$v = a^i \beta_i = b^i \beta_i$라 하자.

$$ \begin{aligned} & (a^i -b^i) \beta_i = 0_V \\ \Rightarrow \enspace & a^i = b^i \end{aligned} $$

즉, $\frak t_\beta(v)$가 유일하게 결정됨으로, $\frak t_\beta$는 well defined다. $\quad {_\blacksquare}$

### 명제2
유한 차원 벡터 공간 $V/F$와 기저 $\beta$가 있을 때, $v \in V$에 대해 다음을 증명하여라.
$$ \frak t_\beta(v) \text{ is a vector space isomorphism} $$

[$t_\beta \in L(V; \mathbb F^n)$]  
$v_1 = a^i\beta_i, \enspace v_2 = b^i\beta_i \in V, \enspace c \in \mathbb F$가 있을 때 다음이 성립한다.
$$ \begin{aligned} \frak t_\beta(cv_1 + v_2) &= (ca_1 + b_1, \cdots, ca_n + b_n) \\ &= c(a_1, \cdots, a_n) + (b_1, \cdots, b_n) \\&= c \frak t_\beta(v_1) + \frak t_\beta(v_2) \end{aligned} $$

[$t_\beta$ is bijective]  
$\ker(t_\beta) = \{ 0_V \}$이고 $\dim(V) = \dim(\mathbb F^n)$임으로 dimension theorem에 의해 $t_\beta$는 bijective이다.$\quad {_\blacksquare}$

#### 참고
즉, $\frak t_\beta$는 vector를 $n-$tuple로 mapping하는 vector space isomorphism이다.


## Extend of tuple s
$T_1, T_2 \in \mathbb F^n$가 있을 때, tuple의 확장을 다음과 같이 정의한다.
$$ T_1 \sqcup T_2 := ((T_1)_1, \cdots, (T_1)_n, (T_2)_1, \cdots, (T_2)_n ) $$

그리고 $T_1, \cdots T_n \in \mathbb F^n$이 있을 때, 여러 tuple의 확장은 다음과 같이 표현한다.
$$ \bigsqcup_{i=1}^nT_i := T_1 \sqcup \cdots \sqcup T_n $$

## 선형변환의 성분표현
$n$차원, $m$차원 벡터공간 $V,W / \mathbb F$와 각각의 기저 $\beta, \gamma$ 그리고 $T \in L(V;W)$가 있다고 하자.

$v = a^i\beta_i \in V, \enspace T(v) = b^i \gamma_i \in W$에 대해서 다음이 성립한다.
$$ \begin{aligned} & \frak t_\gamma(T(v)) = a^i \frak t_\gamma(T(\beta_i)) \\ \Rightarrow \enspace & (b^1, \cdots, b^m) = a^1(T^1_1, \cdots, T^m_1) + \cdots a^n(T^1_n, \cdots, T^m_n) \\ \Rightarrow \enspace & b^i = T^i_j a^j \end{aligned} $$

$$ \text{Where, } \frak t_\gamma(T(\beta_i)) = ( T^1_i, \cdots, T^m_i ) $$

따라서, $T^i_j$로 이루어진 tuple을 $\beta,\gamma$에 대한 $T$의 성분표현으로 두는 것이 자연스러운 선택임으로 $\frak t_\beta^\gamma(T)$을 다음과 같이 정의한다.
$$\frak t_\beta^\gamma(T) : L(V;W) \rightarrow  \mathbb F^{mn} \quad \\s.t. \quad T \mapsto (T^1_1, \cdots, T^m_1, \cdots, T^1_n, \cdots, T^m_n) = \bigsqcup_{i=1}^n t_\gamma(T(\beta_i)) $$

$$ \text{Where, } T^i_j = \frak t_\gamma(T(\beta_j))^i $$

이 때, $T^i_j$는 $\frak t_\gamma (T(\beta_j))$의 $i$번째 원소로 $\beta_j$가 $T$에 의해서 어떻게 mapping 되는지를 나타낸다고 볼 수 있다.

위의 정의에서 알 수 있듯이, 선형변환의 성분표현은 기저선택에 의존한다.

### 명제1
차원이 각 각 $n,m$인 벡터 공간 $V,W/F$와 각각의 기저 $\beta, \gamma$, $T \in L(V;W)$가 있을 때, 다음을 증명하여라.
$$ \frak t_\beta^\gamma(T) \text{ is a vectorspace isomorphism} $$

**proof**   

[$\frak t_\beta^\gamma \in L(L(V; W); \mathbb F^{mn})$]  
$a \in \mathbb F, \enspace T_1,T_2 \in L(V; W)$에 대해,
$$ \begin{aligned} \frak t_\beta^\gamma(aT_1 + T_2) &= \bigsqcup_{i=1}^n \frak t_\gamma((aT_1 + T_2)(\beta_i)) \\ &= a \bigsqcup_{i=1}^n \frak t_\gamma(T_1(\beta_i)) + \bigsqcup_{i=1}^n \frak t_\gamma(T_2(\beta_i)) \\ &= a \frak t_\beta^\gamma(T_1) + \frak t_\beta^\gamma(T_2) \end{aligned}  $$

[bijective]  
$\ker(\frak t_\beta^\gamma(T)) = \{ 0_{L(V;W)} \}$이고 $\dim(L(V;W)) = \dim(\mathbb F^{mn})$임으로 dimension theorem에 의해 $\frak t_\beta^\gamma(T)$는 bijective이다. $\quad {_\blacksquare}$

### 명제2
차원이 각 각 $n,m,k$인 벡터공간 $V,W,Z/F$와 각 각의 기저 $\alpha,\beta,\gamma$ 그리고 $T_1 \in L(V;W), T_2 \in L(W;Z)$가 있을때, 다음을 증명하여라.
$$ C^i_j = B^i_l A^l_j $$

$$ \begin{aligned} \text{Where, } \frak t^\beta_\alpha(T_1) &:= (A^1_1, \cdots, A^m_1, \cdots, A^1_n, \cdots, A^m_n) \\ \frak t_\beta^\gamma(T_2) &:= (B^1_1, \cdots, B^k_1, \cdots, B^1_m, \cdots, B^k_m) \\ \frak t^\gamma_\alpha(T_2 \circ T_1) &:= (C_1^1, \cdots, C^k_1, \cdots, C^1_n, \cdots, C^k_n) \end{aligned} $$

**proof**

$$ \begin{aligned} C^i_j &= \frak t_\gamma((T_2 \circ T_1) (\alpha_j))^i \\ &= \frak t_\beta(T_1(\alpha_j))^l \frak t_\gamma(T_2(\beta_l))^i \\ &= A^l_j B^i_l \quad {_\blacksquare} \end{aligned} $$

### 명제3
차원이 각 각 $n,m$인 벡터 공간 $V,W/F$와 각각의 기저 $\beta, \gamma$가 있다고 하자. $\mathbb F^n,\mathbb F^m$의 기준 기저를 $\epsilon_n,\epsilon_m$라 하면 $f \in L(\mathbb F^n; \mathbb F^m), \enspace T \in L(V; W)$에 대해 다음이 성립함을 증명하여라.
$$ \frak t^{\epsilon_m}_{\epsilon_n}(f) = \frak t^\gamma_\beta(T) $$

$$ \begin{CD} V @>T>> W \\ @V{\frak t_\beta}VV @VV{t_\gamma}V \\ \mathbb F^n @>>f> \mathbb F^m  \end{CD} $$

**Proof**

$\frak t_\beta$은 vector space isomorphism임으로 다음이 성립한다.
$$ f = \frak t_\gamma \circ T \circ \frak t_\beta^{-1} $$

따라서, 명제2에 의해 다음이 성립한다.
$$ f^i_j = A^i_k T^k_l B^l_j $$

$$ \begin{aligned} \text{Where, } \frak t^{\epsilon_m}_{\epsilon_n}(f) &:= (f^1_1, \cdots, f^m_1, \cdots, f^1_n, \cdots, f^m_n) \\ \frak t^\gamma_\beta(T) &:= (T^1_1, \cdots, T^m_1, \cdots, T^1_n, \cdots, T^m_n) \\ \frak t^{\epsilon_m}_\gamma(\frak t_\gamma) &:= (A^1_1, \cdots, A^m_1, \cdots, A^1_m, \cdots, A^m_m) \\ \frak t^\beta_{\epsilon_n}(\frak t_\beta^{-1}) &:= (B^1_1, \cdots, B^n_1, \cdots, B^1_n, \cdots, B^n_n) \end{aligned} $$

이 때, $A^i_k$와 $B^l_j$는 다음과 같다.
$$ A^i_k = \frak t_{\epsilon_m}( \frak t_\gamma(\gamma_k))^i = \delta^i_k \\ B^l_j = \frak t_{\beta}( \frak t_\beta^{-1}(\epsilon_{n,j}))^l = \delta^l_j $$

따라서 다음이 성립한다.
$$ \begin{aligned} f^i_j &= A^i_k T^k_l B^l_j \\ &= \delta^i_k T^k_l \delta^l_j \\ &=T^i_j \quad {_\blacksquare} \end{aligned}  $$

