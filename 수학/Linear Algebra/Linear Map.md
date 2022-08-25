# Linear Map
벡터 공간 $V,W/F$와 함수 $\Phi:V \rightarrow W$에 대해, `선형 변환(linear transformation)` 혹은 `선형 사상(linear map)`은 다음을 만족하는 $\Phi$이다.

$$ v_1,v_2 \in V, a \in F \Rightarrow \Phi(av_1+v_2)=a\Phi(v_1)+\Phi(v_2)$$  

만약, $W = \mathbb F$이면 `linear form`이라고 한다.

### 참고1
linear map은 벡터 공간의 연산 및 관계를 보존하는 함수로 `vector space homomorphism`이다.

### 참고2
$f : V \rightarrow W$인 모든 linear map들을 모은 집합을 $L(V; W)$라 표기한다.

### 참고3
$f : V \rightarrow V$인 linear map을 `endomorphism`이라 하며 endomorphism을 모은 집합을 $\text{End}(V)$라 표기한다.

> Reference  
> [Wiki - Endomorphism](https://en.wikipedia.org/wiki/Endomorphism)

### 명제1
유한 차원 벡터공간 $V,W,Z/F$와 $T_1 \in L(V,W), T_2\in L(W,Z)$가 있을 때 $T_2 \circ T_1 \in L(V,Z)$를 증명하여라.

**proof**  
$v_1,v_2 \in V$과 $a \in F$에 대해,

$$ \begin{aligned} (T_2 \circ T_1)(av_1 + v_2) & = T_2(T_1(av_1 +v_2)) \\ & = T_2(aT_1(v_1) +T_1(v_2)) \\ & = aT_2(T_1(v_1)) + T_2(T_1(v_2)) \\ & = a(T_2 \circ T_1)(v_1) + (T_2 \circ T_1)(v_2) \quad {_\blacksquare}  \end{aligned} $$

### 명제2
두 벡터공간 $V,W / \mathbb F$가 있을 때, $L(V; W)$에 다음과 같은 연산을 주면 $\mathbb F$위의 벡터공간임을 보여라.
$$ \begin{aligned} + : & L(V,W) \times L(V,W) \rightarrow L(V,W) \quad s.t. \quad T_1 + T_2 \mapsto (T_1 + T_2) \\ & \text {satisfying} \quad (T_1 + T_2)(v) = T_1(v) + T_2 (v) \\ \cdot : & \mathbb F \times L(V,W) \rightarrow L(V,W) \quad s.t. \quad a \cdot T \mapsto (aT) \\ & \text {satisfying} \quad (aT)(v) = aT(v) \end{aligned}  $$

**Proof**

[기본 연산 법칙]  
벡터 공간의 부분집합과 연산을 그대로 사용하기 때문에 교환법칙 분배법칙등 $F-$가군의 성질들이 전부 성립한다. 

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

### 명제3
각 각 차원이 $n,m$인 두 벡터공간 $V,W / \mathbb F$가 있을 때, 다음을 증명하여라.
$$ \dim(L(V;W)) = mn $$

**Proof**

$V,W$의 기저를 각 각 $\beta, \gamma$라 할 때, 함수 $f_{ij}$를 다음과 같이 정의하자.
$$f_{ij} : V \rightarrow W \quad s.t. \quad \beta_k \mapsto \begin{cases} 0 & \text{if} \enspace k \neq j \\ \gamma_i & \text{if} \enspace k = j \end{cases} \substack{}\enspace i=1, \cdots, m, \enspace j = 1, \cdots, n $$

[$f_{ij} \in L(V;W)$]  
$c \in \mathbb F, \enspace v_1 = a^i\beta_i, \enspace v_2 = b^i \beta_i \in V$가 있을 때, 다음이 성립한다.
$$ \begin{aligned} f_{ij}(cv_1 + v_2) = (ca^j + b^j)\gamma_i = cf_{ij}(v_1) + f_{ij}(v_2) \end{aligned} $$

[$f_{ij}$ are linearly independent]  
$c^{ij}f_{ij} = 0_{L(V;W)}$라 하자.

$v = a^i\beta_i \in V$에 대해 다음이 성립한다.
$$ c^{ij}f_{ij}(v) = c^{ij} a^j \gamma_i = 0_W $$

$v = \beta_1$인 경우 위 관계식에 의해 다음이 성립한다.
$$ c^{i1} \gamma_i = 0 $$

이 때, $\gamma$는 기저임으로, $c^{i1} = 0 \enspace i=1, \cdots , m$이다.

$v$가 다른 기저일 때도 같은 논리로 반복하면 다음이 성립함을 알 수 있다.
$$ c^{ij} = 0 $$

# Kernel
유한 차원 벡터 공간 $V,W / \mathbb F$와 $T \in L(V,W)$가 있을 때, 다음과 같이 정의된 집합을 $T$의 kernel이라고 한다.
$$ \ker(T) := \{ v \in V \enspace | \enspace T(v) = 0_W \} $$

### 명제1
유한 차원 벡터 공간 $V,W / \mathbb F$과 $T \in L(V,W)$가 있을 때, 다음을 증명하여라.
$$ \ker(T) \le V $$

**Proof**

[기본 연산 법칙]  
벡터 공간의 부분집합과 연산을 그대로 사용하기 때문에 교환법칙 분배법칙등 $F-$가군의 성질들이 전부 성립한다. 

[연산에 닫힘]  
$v_1, v_2 \in \ker(T)$, $a \in \Bbb F$가 있을 때, $T(av_1 + v_2) = aT(v_1) + T(v_2) = 0_W$임으로 $av_1 + v_2 \in \ker(T)$이고 연산에 닫혀있다.

[항등원의 존재성]  
명제1에 의해 항등원이 존재한다. 

[역원의 존재성]  
상수곱이 정의되어 있음으로 환의 명제2에 의해 역원이 존재한다. 

따라서 $\ker(T)$는 $V$의 부분벡터공간이다. $\quad {_\blacksquare}$

### 명제2
유한 차원 벡터 공간 $V,W / \mathbb F$과 $T \in L(V,W)$가 있을 때, 다음을 증명하여라.
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
유한 차원 벡터 공간 $V,W / \mathbb F$와 $T \in L(V,W)$가 있을 때, 다음과 같이 정의된 집합을 $T$의 image이라고 한다.
$$ \text{img}(T) := \{ T(v) \in W \enspace | \enspace v \in V \} $$

$\text{img}(T)$는 $T(V)$로 쓰기도 한다.

### 명제1
유한 차원 벡터 공간 $V,W/F$과 $T \in L(V,W)$가 있을 때, 다음을 증명하여라.
$$\mathrm{img}(T) \le W$$

**Proof**

[기본 연산 법칙]  
벡터 공간의 부분집합과 연산을 그대로 사용하기 때문에 교환법칙 분배법칙등 $F-$가군의 성질들이 전부 성립한다. 

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
유한 차원 벡터 공간 $V,W / \mathbb F$과 $T \in L(V; W)$가 있을 때, 다음을 증명하여라.
$$ \dim(V) = \dim(W) \land \ker(T) = \{ 0_V \} \Rightarrow T \text{ is bijective} $$

**Proof**

[injective]  
Kernel의 명제2에 의해 $T$는 injective이다.

[surjective]  
가정과 Dimension Theorem에 의해 다음이 성립한다.
$$ \dim(W) = \dim(V) = \text{nullity}(T) + \text{rank}(T) = \text{rank}(T) = \dim(\text{img}(T)) $$

$\text{img}(T) \le W$이고 $\dim(\text{img}(T)) = \dim(W)$임으로 차원의 명제1에 의해 $\text{img}(T) = W$이다. $\quad {_\blacksquare}$