# Linear Map
## 정의
vector space $V,W / \mathbb F$와 함수 $\Phi:V \rightarrow W$가 있다고 하자.

`선형 변환(linear transformation)` 혹은 `선형 사상(linear map)`은 `선형성(linearity)`을 보존하는 함수이다.

$$ \forall v_1,v_2 \in V, \forall a \in \F \implies \Phi(av_1+v_2)=a\Phi(v_1)+\Phi(v_2)$$  

### 참고1
linear map은 vector space의 연산 및 관계를 보존하는 함수로 `vector space homomorphism`이다.

### 참고2
$f : V \rightarrow W$인 모든 linear map들을 모은 집합을 $L(V; W)$라 표기한다.

### 참고3
$f : V \rightarrow V$인 linear map을 `endomorphism`이라 하며 endomorphism을 모은 집합을 $\End(V)$라 표기한다.

> Reference  
> [Wiki - Endomorphism](https://en.wikipedia.org/wiki/Endomorphism)

### 참고4
$W = \mathbb F$이면 `linear form`이라고 한다.

### 참고5
vector space $V / \mathbb F$와 $T \in \text{End}(V)$가 있다고 하자.

$W \le V$에 대해서 $T|_W \in \text{End}(W)$이면 $W$를 $T-$`invariant`라고 한다.

### 명제1
vector spaces $V,W / \mathbb F$가 있을 때, 다음과 같은 연산이 주어졌다고 하자.
$$ \begin{aligned} + : & L(V,W) \times L(V,W) \rightarrow L(V,W) \quad s.t. \quad T_1 + T_2 \mapsto (T_1 + T_2) \\ & \text {satisfying} \quad (T_1 + T_2)(v) = T_1(v) + T_2 (v) \\ \cdot : & \mathbb F \times L(V,W) \rightarrow L(V,W) \quad s.t. \quad a \cdot T \mapsto (aT) \\ & \text {satisfying} \quad (aT)(v) = aT(v) \end{aligned}  $$

이 때, 다음을 증명하여라.
$$ L(V;W) \text{ is a vector space} $$

**Proof**

[Abelian Group]  
-[closed]  
$L(V;W)$의 임의의 element를 $f,g$라고 하자.

$V$의 임의의 element를 $v_1,v_2$, $\F$의 임의의 element를 $c$라고할 때, 다음이 성립한다.

$$ \begin{aligned} (f+g)(v_1+cv_2) &= f(v_1+cv_2) + g(v_1+cv_2) \\&= f(v_1)+g(v_1) + c(f(v_2)+g(v_2)) \\&= (f+g)(v_1) + c(f+g)(v_2) \end{aligned}  $$

따라서, $f+g \in L(V;W)$이다. $\qed$

-[identity]  
$0_L \in L(V;W)$를 다음과 같이 정의하자.

$$ \forall v\in V, \enspace  0_L(v) = 0_W $$

$L(V;W)$의 임의의 element를 $f$, $V$의 임의의 element를 $v$라고 하면 다음이 성립한다.

$$ \begin{gathered} (f+0_L)(v) = f(v)+0_L(v) = f(v) \\ (0_L+f)(v) = 0_L(v)+f(v) = f(v) \end{gathered} \implies (f+0_L) = (0_L+f) = f $$

따라서, $0_L$은 $L(V;W)$의 identity element이다.$\qed$

-[inverse]  
$L(V;W)$의 임의의 element를 $f$라고 하자.

$-f \in L(V;W)$를 다음과 같이 정의하자.

$$ \forall v \in V, (-f)(v) = -f(v) $$

$V$의 임의의 element를 $v$라고 하면 다음이 성립한다.

$$ \begin{gathered} (f+(-f))(v) = f(v)+(-f)(v) = 0_W = 0_L(v) \\ ((-f)+f)(v) = (-f)(v) + f(v) = 0_W = 0_L(v) \end{gathered} \implies f+(-f) = (-f) + f = 0_L $$

따라서, $-f$는 $f$의 inverse element이다.$\qed$

-[commutative]  
$L(V;W)$의 임의의 element를 $f,g$라고 하자.

$V$의 임의의 element를 $v$라고 하면, $f(v),g(v)\in W$임으로 다음이 성립한다.

$$ (f+g)(v) = f(v) + g(v) = g(v) + f(v) = (g+f)(v) \qed $$

[Module]  
$L(V;W)$의 임의의 element를 $f,g$, $\F$의 임의의 element를 $r_1,r_2$라고 하자.

$V$의 임의의 element를 $v$라고 할 때, 주어진 action의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} (r_1(f+g))(v) &= r_1(f+g)(v) = r_1f(v) + r_1g(v) = (r_1f + r_1g)(v) \\ ((r_1+r_2)f)(v) &= (r_1+r_2)f(v) = r_1f(v) + r_2f(v) = (r_1f + r_2f)(v) \\ ((r_1r_2)f)(v) &= r_1r_2f(v) = r_1(r_2f)(v) = (r_1(r_2f))(v) \\ (1_\F f)(v) &= 1_\F f(v) = f(v) \end{aligned} $$

따라서 주어진 action은 module의 scalar multiplication의 정의를 만족한다.

[결론]  
$\F$는 field 임으로 $L(V;W)$는 $\F-$module이고 vector space의 정의에 의해 다음이 성립한다.

$$ L(V;W) \text{ is a vector space} \qed $$

### 명제2
$n$차원 vector space $V/\F$와 vector space $W/\F$가 있다고 하자.

$L(V;W)$의 임의의 element를 $f,g$라고 하고 $V$의 basis를 $\beta$라 할 때, 다음을 증명하여라.

$$ f(\beta_i) = g(\beta_i), \enspace i=1,\cdots,n \iff f = g $$

**Proof**

[$\implies$]  
$V$의 임의의 element를 $v=a^i\beta_i$라고 하면 다음이 성립한다.

$$ f(v) = f(a^i\beta_i) = a^if(\beta_i) = a^ig(\beta_i) = g(a^i\beta_i) = g(v) \qed  $$

[$\impliedby$]  
자명하게 성립한다. $\qed$

### 명제3
$n,m$ 차원 vector spaces $V,W / \mathbb F$가 있다고 하자.

$V,W$의 기저를 각 각 $\beta, \gamma$라 할 때, 함수 $f^i_j, \enspace i=1,\cdots,m, j=1,\cdots,n$를 다음과 같이 정의하자.
$$f^i_j : V \rightarrow W \quad s.t. \quad a^k\beta_k \mapsto a^k\delta^i_k \gamma_j $$

이 떄, 다음을 증명하여라.
$$ \{ f^i_j \} \text{ is a basis of } L(V;W) $$

**Proof**

[$\text{span}(\{ f^i_j \}) = L(V;W)$]  
-[$\text{span}(\{ f^i_j \}) \subseteq L(V;W)$]  
$V$의 임의의 element를 $v_1 = a^i\beta_i, \enspace v_2 = b^i \beta_i$, $\F$의 임의의 element를 $c$라고 하자.

그러면, 임의의 $f^i_j$에 대해서 다음이 성립한다.
$$ \begin{aligned} f^i_j(cv_1 + v_2) &= (ca^k + b^k)f^i_j(\beta_k) \\ &= (ca^k + b^k) \delta^i_k \gamma_j \\ &= (ca^i + b^i)\gamma_j \\ &= cf^i_j(v_1) + f^i_j(v_2) \end{aligned} $$

따라서, 임의의 $f^i_j$ 는 $L(V;W)$의 element이고 $L(V;W)$는 vector space임으로 다음이 성립한다. 

$$ \span(\{ f^i_j \}) \subseteq L(V;W) \qed $$

-[$L(V;W) \subseteq \text{span}(\{ f^i_j \})$]  
$L(V;W)$의 임의의 element를 $f$라고 하자.

그러면 어떤 $a^i_j \in \F, i=1,\cdots,m, j=1,\cdots,n$에 대해서 다음을 만족한다.

$$ f(\beta_i) = a^j_i\gamma_j $$

이 때, $g \in \span(\Set{f^i_j})$를 다음과 같이 정의하자.

$$ g = a^j_if^i_j $$

그러면 다음이 성립한다.

$$ \begin{aligned} & g(\beta_k) = a^j_i\delta^i_k\gamma_j = a^j_k\gamma_j = f(\beta_k) \\ \implies& g = f \\ \implies& f \in \span(\Set{f^i_j}) \end{aligned} $$

따라서, 임의의 element $f$가 $\span(\Set{f^i_j})$에 포함됨으로 다음이 성립한다.

$$ L(V;W) \subseteq \text{span}(\{ f^i_j \}) \qed $$

[$\{ f^i_j \}$ are linearly independent]  
$c^j_if^i_j = 0_{L(V;W)}$라 하자.

$V$의 임의의 element를 $v = a^i\beta_i$라고 하면 다음이 성립한다.

$$ c^j_if^i_j(v) = c^i_j a^j \gamma_i = 0_W $$

임의의 $a^j$에 대해 항상 위 식이 성립해야 함으로 다음이 성립한다.

$$ c^{ij} = 0 $$

따라서, 다음이 성립한다.

$$ \{ f^i_j \}  \text{ are linearly independent} \qed $$

#### 따름정리
다음을 증명하여라.

$$ \dim(L(V;W)) = mn $$

**Proof**

$f^i_j, \enspace i=1,\cdots,m, j=1,\cdots,n$가 basis임으로 다음이 성립한다.

$$ \dim(L(V;W)) = mn \qed $$

#### 참고
$f^j_i$는 $V$와 $W$의 기저 선택에 의존한다.

### 명제4
vector spaces $V,W,Z/ \mathbb F$와 $T_1 \in L(V;W), T_2\in L(W;Z)$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ T_2 \circ T_1 \in L(V;Z) $$

**Proof**  

$v_1,v_2 \in V$과 $a \in F$가 있을 때, 다음이 성립한다.
$$ \begin{aligned} (T_2 \circ T_1)(av_1 + v_2) & = T_2(T_1(av_1 +v_2)) \\ & = T_2(aT_1(v_1) +T_1(v_2)) \\ & = aT_2(T_1(v_1)) + T_2(T_1(v_2)) \\ & = a(T_2 \circ T_1)(v_1) + (T_2 \circ T_1)(v_2) \end{aligned} $$

따라서, $T_2 \circ T_1 \in L(V;Z)$이다. $\quad {_\blacksquare}$

### 명제5
vector space $V,W/\F$가 있다고 하자.

$L(V;W)$의 임의의 element를 $f$라고 할 때, 다음을 증명하여라.

$$ f(0_V) = 0_W $$

**Proof**

$V$의 임의의 element를 $v$라고 하면 다음이 성립한다.

$$ f(v) = f(v+0_V) = f(v) + f(0_V) \implies f(0_V) = 0_W \qed $$



# Kernel
## 정의
Vector space $V,W / \mathbb F$와 $T \in L(V,W)$가 있을 때, 다음과 같이 정의된 집합을 $T$의 kernel이라고 한다.
$$ \ker(T) := \{ v \in V \enspace | \enspace T(v) = 0_W \} $$

### 명제1
유한 차원 vector space $V,W / \mathbb F$과 $T \in L(V,W)$가 있을 때, 다음을 증명하여라.

$$ \ker(T) \text{ is a subspace of } V $$

**Proof**

[Abelian Group]  
-[closed]  
$\ker(T)$의 임의의 element를 $v_1,v_2$라고 하자.

$T$가 linear map임으로 다음이 성립한다.

$$ T(v_1+v_2) = T(v_1) + T(v_2) = 0_W $$

따라서 $v_1 + v_2 \in \ker(T)$이고 그럼으로 $\ker(T)$는 $+$에 닫혀있다. $\qed$

-[identity]  
$T(0_V) = 0_W$임으로 $0_V \in \ker(T)$이고 $\ker(T)$의 모든 element는 $V$의 element임으로 다음이 성립한다.

$$ 0_V \text{ is an identity of } \ker(T) \qed $$

-[inverse]  
$\ker(T)$의 임의의 element를 $v$라고 하자.

$v \in V$임으로 inverse element는 $-v \in V$이고 다음이 성립한다.

$$ T(-v) = - T(v) = 0_W $$

따라서 $-v \in \ker(T)$임으로 $\ker(T)$는 inverse element를 갖는다. $\qed$

-[commutative]  
$\ker(T)$의 임의의 element를 $v_1,v_2$라고 하자.

$v_1,v_2 \in V$임으로 다음이 성립한다.

$$ v_1 + v_2 = v_2 + v_1 \qed $$

[Mouule]
$V$의 scalar multiplication을 그대로 사용함으로 module의 성질을 전부 만족하고 따라서 $\ker(T) = \F-\text{module}$이고 다음이 성립한다.

$$ \ker(T) \text{ is a vector space } \implies \ker(T) \text{ is a subspace of } V \qed  $$

### 명제2
유한 차원 vector space $V,W / \mathbb F$과 $T \in L(V,W)$가 있을 때, 다음을 증명하여라.
$$ \ker(T) = \{ 0_V \} \iff T \text{ is injective} $$

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