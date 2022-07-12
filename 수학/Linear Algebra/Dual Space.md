# Dual space
벡터공간 $V/\Bbb F$이 있을 때, $V$의 `쌍대공간(dual space)` $V^*$는 다음과 같이 정의된다.
$$ V^* := \{f: V \rightarrow \mathbb F \enspace | \enspace f \in L(V,\mathbb F) \}$$

$\Bbb F$위의 임의의 벡터공간의 원소를 $\mathbb F$로 보내는 함수를 `범함수(functional)`라고 하며, 선형변환인 functional을 모은 집합이 $V^*$임으로 $v^* \in V^*$를 `linear functional`이라고 한다.

$V^*$는 다음과 같이 정의된 연산에 의해 $\Bbb F$위의 벡터공간이 된다.
$$ + := V^* \times V^* \rightarrow V^* \quad s.t. \quad (\varphi, \psi) \mapsto \varphi + \psi \\ \text{satisfying } (\varphi + \psi)(x) = \varphi(x) + \psi(x) \\ \cdot := \mathbb F \times V^* \rightarrow V^* \quad s.t. \quad (a, \psi) \mapsto a\psi \\ \text{satisfying } (a\psi)(x) = a(\psi(x)) $$
$$ \text{Where, } \varphi, \psi \in V^*, x \in V, a \in \mathbb F  $$

## Dual set
벡터공간 $V/\Bbb F$와 기저 $\beta$가 있을 때, 다음과 같이 정의된 집합을 $\beta$의 `쌍대 집합(dual set)` $\beta^*$이라 한다.
$$ \beta^*_i : V \rightarrow \Bbb F \quad s.t. \quad v \mapsto ([v]_\beta)_i \quad \text{by} \quad \beta^*_i(\beta_j) = \delta_{ij} $$

### 명제1
벡터공간 $V/\Bbb F$와 기저 $\beta$가 있을 때, $\beta$의 dual set $\beta^*$이 선형 독립임을 증명하여라.

**Proof**

$\beta^*$의 원소중 임의로 $n$개의 원소를 선택해 $\beta^*_i \enspace i=1, \cdots, n$라 하자.

$a_i \in \mathbb F \enspace i=1, \cdots, n$가 있을 때, $a_i \beta_i^* = 0_F$라 하자. 

$a_i \beta_i^* \in V^*$임으로, $a_i \beta_i^* : V \rightarrow \mathbb F \quad s.t. \quad v \mapsto 0_F$ 이다.

따라서, $\beta_j \enspace j = 1, \cdots, n$에 대해 다음이 성립한다.
$$ a_i \beta_i^*(\beta_j) = a_j = 0 $$

결론적으로, $a_i = 0 \enspace \forall i$일 때만 $a_i \beta_i^* = 0_F$을 만족함으로 $\beta_i^* \enspace i=1, \cdots, n$는 선형독립이다. 그리고 $\beta_i^*$는 $\beta^*$에서 유한개를 임의로 선택한 것이므로 $\beta^*$는 성형독립이다.  $\quad {_\blacksquare}$

### 명제2
$n$차원 벡터공간 $V/\Bbb F$와 기저 $\beta$가 있을 때, $\beta$의 dual set $\beta^*$이 $V^*$의 기저임을 증명하여라.

**Proof**

명제1에의해 선형독립임이 증명되었음으로, $\text{span}(\beta^*) = V^*$만 확인하면 된다.

[$\text{span}(\beta^*) \subseteq V^*$]  
$v_1,v_2 \in V$일 때, $\forall i$에 대해서

$$ \begin{aligned} \beta_i^*(av_1 + v_2) &= \beta_i^*(ab_j\beta_j + c_j\beta_j) \\ &= \beta_i^*((ab_j+c_j)\beta_j) \\ &= ab_i + c_i \\ &= a \beta_i^*(v_1) + \beta_i^*(v_2) \end{aligned} $$
$$ \therefore \beta^* \subset V^*  $$

따라서 생성의 명제1번에 의해 $\text{span}(\beta^*) \subseteq V^*$이다. $\quad {_\blacksquare}$

[$V^* \subseteq \text{span}(\beta^*)$]  
$v^* \in V^*, v \in V$

$$ \begin{aligned} v^*(v) & = a_i v^*(\beta_i) \\ &= a_i b_i \\ &= \delta_{ij} a_j b_i \\ &= \beta^*_i(\beta_j)a_jb_i \\ &= b_i\beta^*_i(v) \\ & \in \text{span}(\beta^*) \quad {_\blacksquare} \end{aligned} $$

### 명제3
$n$차원 벡터공간 $V/\Bbb F$와 기저 $\beta$, dual space $V^*$와 $\beta$의 dual basis $\beta^*$가 있을 때 다음을 증명하여라.

$$ v^* \in V^* \Rightarrow [v^*]_\beta^1 = ([v^*]_{\beta^*}) ^T $$

이 떄, $1$은 $\R$의 기저이다.

**Proof**

$v^* = a_i(\beta^*)_i$라 하자.
$$ v^*(\beta_j) = a_j \Rightarrow [v^*]_\beta^1 = \begin{bmatrix} a_1 & \cdots & a_n \end{bmatrix} \quad {_\blacksquare} $$

## covector
유한차원 벡터공간 $V/\Bbb F$가 있을 때, 기저를 $\beta, \gamma$, dual basis를 $\beta^*, \gamma^*$라 하자. 기저가 $\beta^*$ 에서 $\gamma^*$로 변할 때 좌표변환행렬과 $\beta$에서 $\gamma$로 변할 때 기저변환행렬과의 관계가 어떻게 되는지 알아보자.

$v^* \in V^*$면 $v^* : V \rightarrow \Bbb F$임으로 $v^* = v^* \circ Id_V$이다. 따라서 다음이 성립한다.
$$ [v^*]^1_\beta = [v^*]^1_\gamma[Id_V]^\gamma_\beta $$

Dual space의 명제 2번에 의해 다음과 같이 정리할 수 있다.
$$ \begin{aligned} & ([v^*]_\beta)^T = ([v^*]_\gamma)^T [Id_V]^\gamma_\beta \\ \Rightarrow \enspace & [v^*]_\beta = ([Id_V]^\gamma_\beta)^T [v^*]_\gamma \\ \Rightarrow \enspace & [v^*]_{\gamma^*} = ([Id_V]_\gamma^\beta)^T[v^*]_{\beta^*} \end{aligned} $$

이를 통해 기저가 $\beta^*$ 에서 $\gamma^*$로 변할 때 좌표변환행렬과 기저가 $\beta$에서 $\gamma$로 변할 때 나타나는 기저변환행렬이 동일함을 알 수 있다. 즉, 기저가 $\beta$에서 $\gamma$로 바뀔 때 기저가 변하는 방식과 dual basis에서
좌표가 변하는 방식이 동일하다. 따라서 $v^* \in V^*$를 `covector`라고 한다. 

### 정리
유한차원 벡터공간 $V/\Bbb F$가 있을 때, 기저를 $\beta, \gamma$, dual basis를 $\beta^*, \gamma^*$라 하자. $v \in V, v^* \in V^*$에 대해서 다음이 성립한다.

$$ \begin{array}{l l} \beta \rightarrow \gamma & \gamma = P^T\beta \\ \beta \rightarrow \gamma & [v]_{\gamma} = P^{-1} [v]_{\beta}\\ \beta^* \rightarrow \gamma^* & \gamma^* = P^{-1} \beta^* \\ \beta^* \rightarrow \gamma^* & [v^*]_{\gamma^*} = P^T [v^*]_{\beta^*} \end{array} $$
$$ \text{Where, } P = [Id_V]^\beta_\gamma  $$

> 참고  
> [Dual Space - 피그티의 기초물리 블로그](https://elementary-physics.tistory.com/16)  
> [note] (upenn) The Dual Space  

# Vectorspace bilinear map
벡터공간 $V,W,X / \mathbb F$이 있을 때, 다음과 같이 정의된 함수 $B$가 있다고 하자.
$$ B : V \times W \rightarrow X $$

모든 $w \in W$에 대해서 함수 $B_w : V \rightarrow X \quad s.t. \quad v \mapsto B(v,w)$가 linear map이고 동시에 모든 $v \in V$에 대해서 함수 $B_v : W \rightarrow X \quad s.t. \quad w \mapsto B(v,w)$가 linear map일 때, $B$를 `vectorspace bilinear map`이라고 한다.

만약 $X = \mathbb F$일 경우에는 `vectorspace bilinear form`이라고 한다.

> 참고  
> [Bilinear map - Wiki](https://en.wikipedia.org/wiki/Bilinear_map)

## Non-degeneracy
벡터공간 $V,W,X / \mathbb F$과 bilinear map $T \in B(V,W,X)$가 있을 때, 다음 성질을 만족하는 경우를 `Non-degeneracy` bilinear map이라고 한다.
$$ \begin{aligned} & v \in V - \{ 0_V \} \Rightarrow \exist w \in W \quad s.t. \quad B(v,w) \neq 0_X \\ \land \enspace & w \in W - \{ 0_w \} \Rightarrow \exist v \in W \quad s.t. \quad B(v,w) \neq 0_X \end{aligned} $$

$$ \begin{aligned} & \forall w \in W, \quad  B(v,w) = 0_X \Leftrightarrow v = 0_V \\ \land \enspace & \forall v \in V, \quad  B(v,w) = 0_X \Leftrightarrow w = 0_W \end{aligned} $$

### 명제1
벡터공간 $V/ \mathbb F$과 non-degenerate bilinear form $T \in B(V,V,\mathbb F)$가 있고 $v \in V$가 있을 때, 다음과 같은 함수를 정의하자.
$$ f_v : V \rightarrow \mathbb F \quad s.t. \quad w \mapsto B(v,w) $$

이 때, 다음과 같이 정의된 함수 $\varphi$가 vector space isomorphism임을 보여라.
$$ \varphi : V \rightarrow V^* \quad s.t. \quad v \mapsto f_v $$

**Proof**

[$\varphi$ is linear map]  
$v_1,v_2 \in V, \enspace a \in F$라 하자.
$$ \varphi(av_1 + v_2) = f_{av_1 + v_2} = B(av_1+v_2, \cdot) = aB(v_1, \cdot)+B(v_2, \cdot) = a\varphi(v_1) + \varphi(v_2) \quad {_\blacksquare} $$

[$\varphi$ is injective]  
$v_1,v_2 \in V$라 하자.
$$ \begin{aligned} & \varphi(v_1) = \varphi(v_2) \\ \Rightarrow \enspace & f_{v_1} = f_{v_2} \\ \Rightarrow \enspace & B(v_1, \cdot) = B(v_2, \cdot) \\ \Rightarrow \enspace & B(v_1 - v_2, \cdot) = 0_F \\ \Rightarrow \enspace & v_1 - v_2 = 0_V \\ \Rightarrow \enspace & v_1 = v_2 \quad {_\blacksquare}


    
\end{aligned} $$


> 참고  
> [note] (Garrett) Duals, naturality, bilinear forms


> 참고  
> [inner-product-in-dual-space - Mathematics](https://math.stackexchange.com/questions/3486532/inner-product-in-dual-space)  
> [what-is-the-difference-between-a-dual-vector-and-a-reciprocal-vector - Pysics](https://physics.stackexchange.com/questions/509334/what-is-the-difference-between-a-dual-vector-and-a-reciprocal-vector)  
> reciprocal vector, covariant components, metric tensor in euclidean space  
> [피그티 기초 물리 네이버](https://m.blog.naver.com/PostView.naver?blogId=defxgenh&logNo=50191387615&navType=by)  
> [피그티 기초 물리 tistory](https://elementary-physics.tistory.com/155)  



> [Dual Space - Wiki](https://en.wikipedia.org/wiki/Dual_space)  
> [Covariance and Contravarient - Wiki](https://en.wikipedia.org/wiki/Covariance_and_contravariance_of_vectors)  
> [dual basis - Mathmatics](https://math.stackexchange.com/questions/1286100/how-do-i-find-a-dual-basis-given-the-following-basis)  
> [linear form - Wiki](https://en.wikipedia.org/wiki/Linear_form#Basis_of_the_dual_space)    
> [What is a covector and what is it used for? - Mathmatics](https://math.stackexchange.com/questions/240491/what-is-a-covector-and-what-is-it-used-for)  