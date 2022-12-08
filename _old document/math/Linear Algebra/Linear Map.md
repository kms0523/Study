# Linear Map
vector space $V,W / \mathbb F$와 함수 $\Phi:V \rightarrow W$가 있다고 하자.

 `선형 변환(linear transformation)` 혹은 `선형 사상(linear map)`은 다음을 만족하는 $\Phi$이다.

$$ v_1,v_2 \in V, a \in F \Rightarrow \Phi(av_1+v_2)=a\Phi(v_1)+\Phi(v_2)$$  

### 참고1
linear map은 vector space의 연산 및 관계를 보존하는 함수로 `vector space homomorphism`이다.

### 참고2
$f : V \rightarrow W$인 모든 linear map들을 모은 집합을 $L(V; W)$라 표기한다.

### 참고3
$f : V \rightarrow V$인 linear map을 `endomorphism`이라 하며 endomorphism을 모은 집합을 $\text{End}(V)$라 표기한다.

> Reference  
> [Wiki - Endomorphism](https://en.wikipedia.org/wiki/Endomorphism)

### 참고4
$W = \mathbb F$이면 `linear form`이라고 한다.

### 참고5
vector space $V / \mathbb F$와 $T \in \text{End}(V)$가 있다고 하자.

$W \le V$에 대해서 $T|_W \in \text{End}(W)$이면 $W$를 $T-$invariant라고 한다.

### 명제1
vector spaces $V,W / \mathbb F$가 있을 때, 다음과 같은 연산이 주어졌다고 하자.
$$ \begin{aligned} + : & L(V,W) \times L(V,W) \rightarrow L(V,W) \quad s.t. \quad T_1 + T_2 \mapsto (T_1 + T_2) \\ & \text {satisfying} \quad (T_1 + T_2)(v) = T_1(v) + T_2 (v) \\ \cdot : & \mathbb F \times L(V,W) \rightarrow L(V,W) \quad s.t. \quad a \cdot T \mapsto (aT) \\ & \text {satisfying} \quad (aT)(v) = aT(v) \end{aligned}  $$

이 때, 다음을 증명하여라.
$$ L(V;W) \text{ is a vector space} $$

**Proof**

[기본 연산 법칙]  
vector space의 부분집합과 연산을 그대로 사용하기 때문에 교환법칙 분배법칙등 $F-$가군의 성질들이 전부 성립한다. 

[연산에 닫힘]  
$T_1, T_2 \in L(V,W)$, $a \in \Bbb F$라 하자.

$v_1,v_2 \in V$, $b \in \mathbb{F}$가 있을 때 다음이 성립한다.
$$ \begin{aligned} (aT_1 + T_2)(bv_1 + v_2) &= aT_1(bv_1 + v_2) + T_2(bv_1 + v_2) \\ &= abT_1(v_1) + bT_2(v_1) + aT_1(v_2) + T_2(v_2) \\ &= b(aT_1+T_2)(v_1) + (aT_1+T_2)(v_2) \end{aligned}  $$

따라서, $aT_1 + T_2 \in L(V,W)$임으로 연산에 닫혀있다. $\quad {_\blacksquare}$

[$+$연산 항등원의 존재성]  
함수가 다음과 같이 정의되어 있다고 하자.
$$ T_0 : V \rightarrow W \quad s.t. \quad v \mapsto 0_W $$

자명하게 $T_0 \in L(V,W)$이고 $T_0$는 $+$에 대해 항등원이다.

[$+$연산 역원의 존재성]  
상수곱이 정의되어 있음으로 환의 명제2에 의해 역원이 존재한다. 

### 명제2
$n,m$ 차원 vector spaces $V,W / \mathbb F$다고 하자.

$V,W$의 기저를 각 각 $\beta, \gamma$라 할 때, 함수 $f^j_i$를 다음과 같이 정의하자.
$$f^j_i : V \rightarrow W \quad s.t. \quad \beta_k \mapsto \delta^j_k \gamma_i $$

이 떄, 다음을 증명하여라.
$$ \{ f^j_i \} \text{ is a basis of } L(V;W) $$

**Proof**

[$\text{span}(\{ f_i^j \}) = L(V;W)$]  
-[$\text{span}(\{ f_i^j \}) \subseteq L(V;W)$]  
$c \in \mathbb F, \enspace v_1 = a^i\beta_i, \enspace v_2 = b^i \beta_i \in V$가 있을 때, 다음이 성립한다.
$$ \begin{aligned} f_i^j(cv_1 + v_2) &= (ca^k + b^k)f_i^j(\beta_k) \\ &= (ca^k + b^k) \delta^j_k \gamma_i \\ &= (ca^j + b^j)\gamma_i \\ &= cf_i^j(v_1) + f_i^j(v_2) \end{aligned} $$

따라서, $f_i^j \in L(V;W)$임으로 $\text{span}(\{ f_i^j \}) \subseteq L(V;W)$이다.

-[$L(V;W) \subseteq \text{span}(\{ f_i^j \})$]  
$T \in L(V;W)$가 있을 때, $v_1 = a^i\beta_i \in V, \enspace T(v_1) = b^i \gamma_i \in W$라 하자.

$f = c^i_jf^j_i \in \text{span}(\{ f_i^j \})$라 하면 다음이 성립한다.
$$ c^i_jf_i^j(v_1) = a^kc^i_jf_i^j(\beta_k) = a^k c^i_j \delta^j_k \gamma_i  = a^j c^i_j\gamma_i $$

따라서, $c^i_j$를 $a^jc^i_j = b^i$를 만족하게 결정하면 $T \in \text{span}(\{ f_i^j \})$이다.

[$\{ f_i^j \}$ are linearly independent]  
$c^i_jf_i^j = 0_{L(V;W)}$라 하자.

$v = a^i\beta_i \in V$에 대해 다음이 성립한다.
$$ c^i_jf_i^j(v) = c^i_j a^j \gamma_i = 0_W $$

임의의 $a^j$에 대해 항상 위 식이 성립해야 함으로 다음이 성립한다.
$$ c^{ij} = 0 $$

따라서, $\{ f_i^j \}$는 선형 독립이다.

#### 따름정리
다음을 증명하여라.
$$ \dim(L(V;W)) = mn $$

#### 참고
$f^j_i$는 $V$와 $W$의 기저 선택에 의존한다.

### 명제3
vector spaces $V,W,Z/ \mathbb F$와 $T_1 \in L(V;W), T_2\in L(W;Z)$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ T_2 \circ T_1 \in L(V;Z) $$

**Proof**  

$v_1,v_2 \in V$과 $a \in F$가 있을 때, 다음이 성립한다.
$$ \begin{aligned} (T_2 \circ T_1)(av_1 + v_2) & = T_2(T_1(av_1 +v_2)) \\ & = T_2(aT_1(v_1) +T_1(v_2)) \\ & = aT_2(T_1(v_1)) + T_2(T_1(v_2)) \\ & = a(T_2 \circ T_1)(v_1) + (T_2 \circ T_1)(v_2) \end{aligned} $$

따라서, $T_2 \circ T_1 \in L(V;Z)$이다. $\quad {_\blacksquare}$



# Kernel
유한 차원 vector space $V,W / \mathbb F$와 $T \in L(V,W)$가 있을 때, 다음과 같이 정의된 집합을 $T$의 kernel이라고 한다.
$$ \ker(T) := \{ v \in V \enspace | \enspace T(v) = 0_W \} $$

### 명제1
유한 차원 vector space $V,W / \mathbb F$과 $T \in L(V,W)$가 있을 때, 다음을 증명하여라.
$$ \ker(T) \le V $$

**Proof**

[기본 연산 법칙]  
vector space의 부분집합과 연산을 그대로 사용하기 때문에 교환법칙 분배법칙등 $F-$가군의 성질들이 전부 성립한다. 

[연산에 닫힘]  
$v_1, v_2 \in \ker(T)$, $a \in \Bbb F$가 있을 때, $T(av_1 + v_2) = aT(v_1) + T(v_2) = 0_W$임으로 $av_1 + v_2 \in \ker(T)$이고 연산에 닫혀있다.

[항등원의 존재성]  
명제1에 의해 항등원이 존재한다. 

[역원의 존재성]  
상수곱이 정의되어 있음으로 환의 명제2에 의해 역원이 존재한다. 

따라서 $\ker(T)$는 $V$의 부분벡터공간이다. $\quad {_\blacksquare}$

### 명제2
유한 차원 vector space $V,W / \mathbb F$과 $T \in L(V,W)$가 있을 때, 다음을 증명하여라.
$$ \ker(T) = \{ 0_V \} \Leftrightarrow T \text{ is injective} $$

**Proof1**

group monomorphism의 명제에 의해 성립한다.

**Proof2**

[$\Rightarrow$]  
$v_1, v_2 \in V$일 때, 다음이 성립한다.
$$ \begin{aligned} & T(v_1) = T(v_2) \\ \Rightarrow \enspace & T(v_1) - T(v_2) = T(v_2) - T(v_2) \\ \Rightarrow \enspace & T(v_1 - v_2) = 0_W \\ \Rightarrow \enspace & v_1 - v_2 = 0_V \\ \Rightarrow \enspace & v_1 = v_2 \end{aligned} $$

[$\Leftarrow$]  
$T(0_V) = T(0_F 0_V) = 0_F T(0_V) = 0_W$이고 $T$가 단사함수임으로 $\ker(T) = \{ 0_V \}$이다. $\quad {_\blacksquare}$

# Image
유한 차원 vector space $V,W / \mathbb F$와 $T \in L(V,W)$가 있을 때, 다음과 같이 정의된 집합을 $T$의 image이라고 한다.
$$ \text{img}(T) := \{ T(v) \in W \enspace | \enspace v \in V \} $$

$\text{img}(T)$는 $T(V)$로 쓰기도 한다.

### 명제1
유한 차원 vector space $V,W/F$과 $T \in L(V,W)$가 있을 때, 다음을 증명하여라.
$$\mathrm{img}(T) \le W$$

**Proof**

[기본 연산 법칙]  
vector space의 부분집합과 연산을 그대로 사용하기 때문에 교환법칙 분배법칙등 $F-$가군의 성질들이 전부 성립한다. 

[연산에 닫힘]  
$w_1, w_2 \in \mathrm{img}(T)$, $a \in \Bbb F$가 있을 때, $\exist v_1,v_2 \quad s.t \quad w_1 = T(v_1), w_2 = T(v_2)$이다. 따라서 $aw_1 + w_2 = aT(v_1) + T(v_2) = T(av_1 + v_2)  \in \mathrm{img}(T)$임으로 연산에 닫혀있다.

[항등원의 존재성]  
$$ T(0_V) = T(0_F 0_V) = 0_F T(0_V) = 0_W $$

[역원의 존재성]  
scalar multiplication이 정의되어 있음으로 환의 명제2에 의해 역원이 존재한다. 

따라서 $\mathrm{img}(T)$는 $W$의 부분벡터공간이다. $\quad {_\blacksquare}$

# Dimension Theorem
벡터공간 $V,W / \mathbb F$와, $T \in L(V; W)$가 있을 때 다음을 증명하여라.
$$ \dim(V) = \text{nullity}(T) + \text{rank}(T) $$

**Proof1**

추상대수학에서 1st homorphism theorem을 통해 군 $G,H$와 group homomorphism인 $f : G \rightarrow H$가 있을 때, $G / \ker(f) \cong \text{img}(f)$임을 보였다. 이를 벡터공간으로 확장하면 다음과 같다.

벡터공간 $V,W / \mathbb F$와, $T \in L(V,W)$가 있을 때, $V / \ker(T) \cong \text{img}(T)$이다. 이를 통해 $\dim(V / \ker(T)) = \dim(\text{img}(T))$이고 정리하면 $\dim(V) = \text{nullity}(T) + \text{rank}(T)$이다.

**Proof2**

$V$의 기저를 $\beta$라 하고, $\ker(T)$의 기저를 $\beta_0$라고 하자. 그러면 $T(\beta - \beta_0)$는 $\text{img}(T)$의 기저가 됨으로 $\text{rank}(T) = \dim(V) - \text{nullity}(T)$가 된다.

### 명제1
유한 차원 vector space $V,W / \mathbb F$과 $T \in L(V; W)$가 있을 때, 다음을 증명하여라.
$$ \dim(V) = \dim(W) \land \ker(T) = \{ 0_V \} \Rightarrow T \text{ is bijective} $$

**Proof**

[injective]  
Kernel의 명제2에 의해 $T$는 injective이다.

[surjective]  
가정과 Dimension Theorem에 의해 다음이 성립한다.
$$ \dim(W) = \dim(V) = \text{nullity}(T) + \text{rank}(T) = \text{rank}(T) = \dim(\text{img}(T)) $$

$\text{img}(T) \le W$이고 $\dim(\text{img}(T)) = \dim(W)$임으로 차원의 명제1에 의해 $\text{img}(T) = W$이다. $\quad {_\blacksquare}$

# Determinant of an Linear Map
vector space $V/ \mathbb F$와 $T \in \text{End}(V)$가 있을 때, $T$의 determinat를 다음과 같이 정의한다.
$$ \det(T) : \text{End}(V) \rightarrow \mathbb F \quad s.t. \quad T \mapsto \det(\frak m_\beta^\beta(T)) \text { for any basis } \beta $$

### 명제1
vector space $V/ \mathbb F$와 $T \in \text{End}(V)$가 있을 때 다음을 증명하여라
$$\det(T) \text{ is well-defined}$$

**Proof**

well-defined 되기 위해서는 기저의 선택에 관계없이 일정함을 보이면 된다.

$V$의 두 기저를 $\beta,\gamma$라 하면 다음이 성립한다.
$$ \frak m^\gamma_\gamma(T) \sim  \frak m^\beta_\beta(T)$$

similar한 두 행렬의 성질에 의해 다음이 성립한다.
$$ \det(\frak m^\gamma_\gamma(T)) = \det(\frak m^\beta_\beta(T)) \quad {_\blacksquare} $$

# Trace of an Linear Map
vector space $V/ \mathbb F$와 $T \in \text{End}(V)$가 있을 때, $T$의 trace를 다음과 같이 정의한다.

$$ \mathrm{tr}(T) : \text{End}(V) \rightarrow \mathbb F \quad s.t. \quad T \mapsto \mathrm{tr}(\frak m_\beta^\beta(T)) \text { for any basis } \beta $$

### 명제1
vector space $V/ \mathbb F$와 $T \in \text{End}(V)$가 있을 때, 다음을 증명하여라
$$\text{tr}(T) \text{ is well-defined}$$

**Proof**

well-defined 되기 위해서는 기저의 선택에 관계없이 일정함을 보이면 된다.

$V$의 두 기저를 $\beta,\gamma$라 하면 다음이 성립한다.
$$ \frak m^\gamma_\gamma(T) \sim  \frak m^\beta_\beta(T)$$

similar한 두 행렬의 성질에 의해 다음이 성립한다.
$$ \mathrm{tr}(\frak m^\gamma_\gamma(T)) = \mathrm{tr}(\frak m^\beta_\beta(T)) \quad {_\blacksquare} $$

# Characteristic Polynomial of an Linear Map
vector space $V/\mathbb F$와 $T \in \text{End}(V)$가 있을 때, $T$의 특성다항식은 다음과 같이 정의된다.
$$ \varphi_T(t) = \det(T - tid) $$

특성다항식의 근이 고유값이 된다.

> Reference  
> [Mathmatics - Coefficients of the characteristic polynomial](https://math.stackexchange.com/questions/2115713/coefficient-of-characteristic-polynomial-as-sum-of-principal-minors)  
> [Note] (UCSC) The Characteristic Polynomial