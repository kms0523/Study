# Dual space
벡터공간 $V/\Bbb F$이 있을 때, $V$의 `쌍대공간(dual space)` $V^*$는 다음과 같이 정의된다.
$$ V^* := \{f: V \rightarrow \mathbb F \enspace | \enspace f \in L(V,\mathbb F) \}$$

$\Bbb F$위의 임의의 벡터공간의 원소를 $\mathbb F$로 보내는 함수를 `범함수(functional)`라고 하며, 선형변환인 functional을 모은 집합이 $V^*$임으로 $v^* \in V^*$를 `linear functional`이라고 한다.

### 명제1
벡터공간 $V/\Bbb F$이 있을 때, $V^*$에 다음과 같이 정의된 연산에 의해 $\Bbb F$위의 벡터공간이 됨을 증명하여라.
$$ \begin{aligned} + := & V^* \times V^* \rightarrow V^* \quad s.t. \quad \varphi + \psi \mapsto (\varphi + \psi) \\ & \text{satisfying } (\varphi + \psi)(x) = \varphi(x) + \psi(x) \\ \cdot := & \mathbb F \times V^* \rightarrow V^* \quad s.t. \quad a \cdot \psi \mapsto (a\psi) \\ & \text{satisfying } (a\psi)(x) = a\psi(x) \end{aligned}  $$

**Proof**

[기본 연산 법칙]  
연산의 정의로부터 교환법칙 분배법칙등이 $F-$가군의 성질들이 전부 성립한다. $\quad {_\blacksquare}$

[연산에 닫힘]  
$v^1, v^2 \in V^*$, $a \in \Bbb F$라 하자.

$v_1,v_2 \in V$, $b \in \mathbb{F}$가 있을 때 다음이 성립한다.
$$ \begin{aligned} (av^1 + v^2)(bv_1 + v_2) &= av^1(bv_1 + v_2) + v^2(bv_1 + v_2) \\ &= abv^1(v_1) + bv^2(v_1) + av^1(v_2) + v^2(v_2) \\ &= b(av^1+v^2)(v_1) + (av^1+v^2)(v_2) \end{aligned}  $$

따라서, $av^1 + v^2 \in V^*$임으로 연산에 닫혀있다. $\quad {_\blacksquare}$

[$+$연산 항등원의 존재성]  
다음과 같이 정의된 함수를 생각해보자.
$$ 0^V : V \rightarrow \mathbb F \quad s.t. \quad v \mapsto 0_F $$

쉽게 $0^V$가 linear map임을 보일 수 있다. 따라서 $0^V \in V^*$이고 $0^V$는 $+$에 대해 항등원이다.


[$+$연산 역원의 존재성]  
상수곱이 정의되어 있음으로 환의 명제2에 의해 역원이 존재한다. $\quad {_\blacksquare}$

# Dual set
벡터공간 $V/\Bbb F$와 기저 $\beta$가 있을 때, 다음과 같이 정의된 집합을 $\beta$의 `쌍대 집합(dual set)` $\beta^*$이라 한다.
$$ \beta^i : V \rightarrow \Bbb F \quad s.t. \quad v \mapsto ([v]_\beta)_i \quad \text{by} \quad \beta^i(\beta_j) = \delta^i_j $$

### 명제0
벡터공간 $V/\Bbb F$와 기저 $\beta$가 있을 때, $\beta$의 dual set $\beta^*$가 유일하게 존재함을 증명하여라.

**Proof**

$v \in V$일 때, $\beta^i : V \rightarrow \mathbb F$가 다음을 만족하는 함수들이라 하자.
$$ v = \beta^i(v)\beta_i $$

$\beta_i$가 $V$의 기저임으로, 계수인 $\beta^i(v)$가 모든 $v$에 대해서 유일하게 존재한다는 것을 알고 있다.

정의역의 모든 원소에 대해 유일하게 값이 정의되어 있음으로 함수 $\beta^i$는 존재하고 잘 정의된다.



### 명제1
벡터공간 $V/\Bbb F$와 기저 $\beta$가 있을 때, $\beta$의 dual set $\beta^*$이 선형 독립임을 증명하여라.

**Proof**

$\beta^*$의 원소중 임의로 $n$개의 원소를 선택해 $\beta^i \enspace i=1, \cdots, n$라 하자.

$a_i \in \mathbb F \enspace i=1, \cdots, n$가 있을 때, $a_i \beta^i = 0_F$라 하자. 

$a_i \beta^i \in V^*$임으로, $a_i \beta^i : V \rightarrow \mathbb F \quad s.t. \quad v \mapsto 0_F$ 이다.

따라서, $\beta_j \enspace j = 1, \cdots, n$에 대해 다음이 성립한다.
$$ a_i \beta^i(\beta_j) = a_j = 0 $$

결론적으로, $a_i = 0 \enspace \forall i$일 때만 $a_i \beta^i = 0_F$을 만족함으로 $\beta^i \enspace i=1, \cdots, n$는 선형독립이다. 그리고 $\beta^i$는 $\beta^*$에서 유한개를 임의로 선택한 것이므로 $\beta^*$는 성형독립이다.  $\quad {_\blacksquare}$

### 명제2
$n$차원 벡터공간 $V/\Bbb F$와 기저 $\beta$가 있을 때, $\beta$의 dual set $\beta^*$이 $V^*$의 기저임을 증명하여라.

**Proof**

명제1에의해 선형독립임이 증명되었음으로, $\text{span}(\beta^*) = V^*$만 확인하면 된다.

[$\text{span}(\beta^*) \subseteq V^*$]  
$v_1,v_2 \in V$일 때, $\forall i$에 대해서

$$ \begin{aligned} \beta^i(av_1 + v_2) &= \beta^i(ab_j\beta_j + c_j\beta_j) \\ &= \beta^i((ab_j+c_j)\beta_j) \\ &= ab_i + c_i \\ &= a \beta^i(v_1) + \beta^i(v_2) \end{aligned} $$
$$ \therefore \beta^* \subset V^*  $$

따라서 선형대수 생성의 명제1번에 의해 $\text{span}(\beta^*) \subseteq V^*$이다. $\quad {_\blacksquare}$

[$V^* \subseteq \text{span}(\beta^*)$]  
$v^* \in V^*, v \in V$

$$ \begin{aligned} v^*(v) & = a_i v^*(\beta_i) \\ &= a_i b_i \\ &= \delta_{ij} a_j b_i \\ &= \beta^i(\beta_j)a_jb_i \\ &= b_i\beta^i(v) \\ & \in \text{span}(\beta^*) \quad {_\blacksquare} \end{aligned} $$

### 명제3
$n$차원 벡터공간 $V/\Bbb F$와 기저 $\beta$, dual space $V^*$와 $\beta$의 dual basis $\beta^*$가 있을 때 다음을 증명하여라.

$$ v^* \in V^* \Rightarrow [v^*]_\beta^1 = ([v^*]_{\beta^*}) ^T $$

이 떄, $1$은 $\R$의 기저이다.

**Proof**

$v^* = a_i\beta^i$라 하자.
$$ v^*(\beta_j) = a_j \Rightarrow [v^*]_\beta^1 = \begin{bmatrix} a_1 & \cdots & a_n \end{bmatrix} \quad {_\blacksquare} $$

# covector
유한차원 벡터공간 $V/\Bbb F$가 있을 때, 기저를 $\beta, \gamma$, dual basis를 $\beta^*, \gamma^*$라 하자. 기저가 $\beta^*$ 에서 $\gamma^*$로 변할 때 좌표변환행렬과 $\beta$에서 $\gamma$로 변할 때 기저변환행렬과의 관계가 어떻게 되는지 알아보자.

$v^* \in V^*$면 $v^* : V \rightarrow \Bbb F$임으로 $v^* = v^* \circ Id_V$이다. 따라서 다음이 성립한다.
$$ [v^*]^1_\beta = [v^*]^1_\gamma[Id_V]^\gamma_\beta $$

Dual space의 명제 2번에 의해 다음과 같이 정리할 수 있다.
$$ \begin{aligned} & ([v^*]_\beta)^T = ([v^*]_\gamma)^T [Id_V]^\gamma_\beta \\ \Rightarrow \enspace & [v^*]_\beta = ([Id_V]^\gamma_\beta)^T [v^*]_\gamma \\ \Rightarrow \enspace & [v^*]_{\gamma^*} = ([Id_V]_\gamma^\beta)^T[v^*]_{\beta^*} \end{aligned} $$

이를 통해 기저가 $\beta^*$ 에서 $\gamma^*$로 변할 때 좌표변환행렬과 기저가 $\beta$에서 $\gamma$로 변할 때 나타나는 기저변환행렬이 동일함을 알 수 있다. 즉, 기저가 $\beta$에서 $\gamma$로 바뀔 때 기저가 변하는 방식과 dual basis에서
좌표가 변하는 방식이 동일하다. 따라서 $v^* \in V^*$를 `covector`라고 한다. 

### 명제1
유한차원 벡터공간 $V/\Bbb F$가 있을 때, 기저를 $\beta, \gamma$, dual basis를 $\beta^*, \gamma^*$라 하자. $v \in V, v^* \in V^*$에 대해서 다음이 성립한다.

$$ \begin{array}{l l} \beta \rightarrow \gamma & \gamma = P^T\beta \\ \beta \rightarrow \gamma & [v]_{\gamma} = P^{-1} [v]_{\beta}\\ \beta^* \rightarrow \gamma^* & \gamma^* = P^{-1} \beta^* \\ \beta^* \rightarrow \gamma^* & [v^*]_{\gamma^*} = P^T [v^*]_{\beta^*} \end{array} $$
$$ \text{Where, } P = [Id_V]^\beta_\gamma  $$

> 참고  
> [Dual Space - 피그티의 기초물리 블로그](https://elementary-physics.tistory.com/16)  
> [note] (upenn) The Dual Space  

# Vectorspace bilinear map
벡터공간 $V,W,X / \mathbb F$이 있을 때, 다음과 같이 정의된 함수 $T$가 있다고 하자.
$$ T : V \times W \rightarrow X $$

모든 $w \in W$에 대해서 함수 $T_w : V \rightarrow X \quad s.t. \quad v \mapsto T(v,w)$가 linear map이고 동시에 모든 $v \in V$에 대해서 함수 $T_v : W \rightarrow X \quad s.t. \quad w \mapsto T(v,w)$가 linear map일 때, $T$를 `vectorspace bilinear map`이라고 한다.

만약 $X = \mathbb F$일 경우에는 `vectorspace bilinear form`이라고 한다.

이 때, $V,W$의 원소를 인자로 받아 $X$의 원소로 mapping 시키는 모든 bilinear map의 집합을 $L^2(V,W,X)$라 한다.



> 참고  
> [Bilinear map - Wiki](https://en.wikipedia.org/wiki/Bilinear_map)


### 명제1
벡터공간 $V,W,X / \mathbb F$이 있을 때, $L^2(V,W,X)$는 다음과 같이 정의된 연산이 있을 때, $\mathbb F$위의 벡터공간임을 보여라.
$$ \begin{aligned} + := & L^2(V,W,X) \times L^2(V,W,X) \rightarrow L^2(V,W,X) \quad s.t. \quad (\varphi, \psi) \mapsto \varphi + \psi \\ & \text{satisfying } (\varphi + \psi)(v,w) = \varphi(v,w) + \psi(v,w) \\ \cdot := & \mathbb F \times L^2(V,W,X) \rightarrow L^2(V,W,X) \quad s.t. \quad (a, \psi) \mapsto a \psi \\ & \text{satisfying } (a\psi)(v,w) = a\psi(v,w) \end{aligned}  $$

### 명제2
$n$차원 벡터공간 $V/ \mathbb F$과 bilinear form $T \in L^2(V,V,\mathbb F)$가 있고 $v \in V$가 있을 때, 다음 함수를 정의하자.
$$ T(v, \cdot) : V \rightarrow \mathbb F \quad s.t. \quad w \mapsto T(v,w) $$

$\beta$를 $V$의 기저라 할 때, 다음을 증명하여라.
$$ v = a^i \beta_i \Rightarrow T(v,\cdot) = a_j\beta^j $$
$$ \text{where, } a_j = a^iT(\beta_i,\beta_j) $$

**Proof**

$w = b^k \beta_k \in V$라 하면 다음이 성립한다.
$$ \begin{equation} T(v,\cdot)(w) = T(v,w) = a^ib^kT(\beta_i,\beta_k) \end{equation} $$

식(1)의 dummy index $k$를 $j$로 바꿔주면 다음과 같다.
$$ \begin{equation} T(v,\cdot)(w) = T(v,w) = a^ib^jT(\beta_i,\beta_j) \end{equation} $$

$T(v,\cdot) \in V^*$임으로 $T(v, \cdot) = a_j \beta^j$이고 다음이 성립한다.
$$ \begin{equation} T(v,\cdot)(w) = a_jb^k \beta^j(\beta_k) = a_j b^k \delta^j_k = a_jb^j \end{equation} $$

식(2)와 식(3)을 비교함으로써 다음 관계식을 얻을 수 있다.
$$ a_j = a^iT(\beta_i,\beta_j) $$

> 참고  
> [피그티 기초 물리 네이버](https://m.blog.naver.com/PostView.naver?blogId=defxgenh&logNo=50191387615)  
> [피그티 기초 물리 tistory](https://elementary-physics.tistory.com/155)  

#### 따름명제
$$ T(\beta_i, \cdot) = T(\beta_i,\beta_j)\beta^j $$




## Non-degeneracy
벡터공간 $V,W,X / \mathbb F$과 $T \in L^2(V,W,X)$가 있을 때, 다음 성질을 만족하는 경우를 `Non-degenerate` bilinear map이라고 한다.
$$ \begin{aligned} & v \in V - \{ 0_V \} \Rightarrow \exist w \in W \quad s.t. \quad T(v,w) \neq 0_X \\ \land \enspace & w \in W - \{ 0_w \} \Rightarrow \exist v \in W \quad s.t. \quad T(v,w) \neq 0_X \end{aligned} $$

혹은
$$ \begin{aligned} & \forall w \in W, \quad  T(v,w) = 0_X \Leftrightarrow v = 0_V \\ \land \enspace & \forall v \in V, \quad  T(v,w) = 0_X \Leftrightarrow w = 0_W \end{aligned} $$

> 참고  
> [note] (Garrett) Duals, naturality, bilinear forms

### 명제1
벡터공간 $V/ \mathbb F$과 non-degenerate bilinear form $T \in B(V,V,\mathbb F)$가 있고 $v \in V$가 있을 때, 다음과 같은 함수를 정의하자.
$$ T(v, \cdot) : V \rightarrow \mathbb F \quad s.t. \quad w \mapsto T(v,w) $$

이 때, 다음과 같이 정의된 함수 $\varphi$가 vector space isomorphism임을 보여라.
$$ \varphi : V \rightarrow V^* \quad s.t. \quad v \mapsto T(v, \cdot) $$

**Proof**

[$\varphi$ is linear map]  
$v_1,v_2 \in V, \enspace a \in F$라 하자.
$$ \varphi(av_1 + v_2) = T(av_1+v_2, \cdot) = aT(v_1, \cdot)+T(v_2, \cdot) = a\varphi(v_1) + \varphi(v_2)  $$

[$\varphi$ is bijective]  
$T$가 non-degenerate bilinear form임으로 $T(v,\cdot) = 0^V \Leftrightarrow v = 0_V$이다. 따라서 $\ker(\varphi) = \{ 0_V \}$이다.

$\ker(\varphi) = \{ 0_V \}$이고 $\dim(V) = \dim(V^*)$임으로 선형대수 Dimension Theorem의 명제1에 의해 $\varphi$는 bijective이다. $\quad {_\blacksquare}$

> 참고  
> [note] (Garrett) Duals, naturality, bilinear forms

#### 따름명제
$V$의 기저를 $\beta$라 했을 때 다음을 증명하여라.
$$ [\varphi]^{\beta^*}_{\beta} = T_{ij} $$
$$ \text{Where, } T_{ij} = T(\beta_i, \beta_j) $$


### 명제2
벡터공간 $V/ \mathbb F$과 non-degenerate bilinear form $T \in B(V,V,\mathbb F)$가 있고 $v \in V$가 있을 때, 다음과 같은 함수를 정의하자.
$$ T(v, \cdot) : V \rightarrow \mathbb F \quad s.t. \quad w \mapsto T(v,w) $$
$$ \varphi : V \rightarrow V^* \quad s.t. \quad v \mapsto T(v, \cdot) $$
$$ H : V^* \times V^* \rightarrow \mathbb F \quad s.t. \quad (v^1,v^2) \mapsto B(\varphi^{-1}(v^1), \varphi^{-1}(v^2)) $$

다음을 증명하여라.
$$ H \in B(V^*,V^*, \mathbb F) $$

> 참고  
> [inner-product-in-dual-space - Mathematics](https://math.stackexchange.com/questions/3486532/inner-product-in-dual-space)  
---


> [what-is-the-difference-between-a-dual-vector-and-a-reciprocal-vector - Pysics](https://physics.stackexchange.com/questions/509334/what-is-the-difference-between-a-dual-vector-and-a-reciprocal-vector)  
> reciprocal vector, covariant components, metric tensor in euclidean space  





> [Dual Space - Wiki](https://en.wikipedia.org/wiki/Dual_space)  
> [Covariance and Contravarient - Wiki](https://en.wikipedia.org/wiki/Covariance_and_contravariance_of_vectors)  
> [dual basis - Mathmatics](https://math.stackexchange.com/questions/1286100/how-do-i-find-a-dual-basis-given-the-following-basis)  
> [linear form - Wiki](https://en.wikipedia.org/wiki/Linear_form#Basis_of_the_dual_space)    
> [What is a covector and what is it used for? - Mathmatics](https://math.stackexchange.com/questions/240491/what-is-a-covector-and-what-is-it-used-for)  