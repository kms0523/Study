# Tensor Products
두 벡터공간 $V,W / \mathbb F$이 있을 때, $V$와 $W$의 `텐서 곱(tensor product)` $V \otimes W$는 아래와 같은 보편 성질을 갖는 bilinear map  $B \in L^2(V,W; V \otimes W)$과 함께 정의된 벡터공간이다. 

임의의 벡터공간 $X / \mathbb F$가 있을 때, 
$$ H \in L^2(V,W;X) \Rightarrow \exist! T \in L(V \otimes W;X) \quad s.t. \quad H = T \circ B  $$

### 명제1
두 벡터공간 $V,W / \mathbb F$이 있을 때, $V \otimes W$가 존재함을 증명하여라.

**Proof**

집합 $Z$에 대해서 함수 $B$를 다음과 같이 정의하자.
$$ B:V \times W \rightarrow Z \quad s.t. \quad (v,w) \mapsto \phi(v,w)  $$
$$ \text{satsifying } \phi(v,w) \in L^2(V^*,W^*; \mathbb F) \quad s.t. \quad (v^*,w^*) \mapsto v^*(v)w^*(w) $$

임의의 벡터공간 $X / \mathbb F$와 $H \in L^2(V,W;X)$가 있을 때, $V,W$의 기저 $\beta,\gamma$에 대해 다음과 같이 동작하는 linear map $T$를 정의하자.
$$T \in L(Z;X) \quad s.t. \quad \phi(\beta_i,\gamma_j) \mapsto H(\beta_i,\gamma_j)$$

위의 정의에 의해 $T$는 유일하게 존재하며, $\phi(\beta_i,\gamma_j)$에서 $H = T \circ B$임을 알 수 있다. 또한 보조명제2에 의해 $Z = L^2(V^*, W^*, \mathbb F)$임으로 벡터공간이며 보조명제3에 의해 $\phi(\beta_i,\gamma_j)$가 $Z$의 기저임으로 결론적으로 모든 $Z$에서 $H = T \circ B$이다.

여기서 $Z = V \otimes W$로 두면, 위의 정의한 $B$는 $B\in L^2(V,W; V\otimes W)$이고, $V \otimes W = L^2(V^*,W^*,\mathbb F)$임으로 벡터공간이며 위와 같이 정의된 $T$에 의해서 보편성질을 만족한다. 따라서 $V \otimes W$는 최소한 한개 이상 존재한다. $\quad {_\blacksquare}$

#### 보조명제1
집합 $Z$에 대해서 함수 $B$를 다음과 같이 정의하자.
$$ B:V \times W \rightarrow Z \quad s.t. \quad (v,w) \mapsto \phi(v,w)  $$
$$ \text{satsifying } \phi(v,w) \in L^2(V^*,W^*; \mathbb F) \quad s.t. \quad (v^*,w^*) \mapsto v^*(v)w^*(w) $$

이 때, 다음을 증명하여라.
$$ B \in L^2(V,W; Z) $$

**Proof**

$a \in \mathbb F, \enspace v_1,v_2 \in V, \enspace w \in W$가 있을 때, $v^* \in V^*, \enspace w^* \in W^*$에 대해 다음이 성립한다.
$$ \begin{aligned} (\phi(av_1,v_2,w))(v^*,w^*) &= v^*(av_1+v_2)w^*(w) \\ &= av^*(v_1)w^*(w) + v^*(v_2)w^*(w) \\ &= a(\phi(v_1,w))(v^*,w^*) + \phi(v_2,w)(v^*,w^*) \end{aligned}  $$ 

위와 비슷하게 $\phi$는 두번째 항에 대해서도 linear map임을 보일 수 있다. $\quad {_\blacksquare}$

#### 보조명제2
집합 $Z$에 대해서 함수 $B$를 다음과 같이 정의하자.
$$ B:V \times W \rightarrow Z \quad s.t. \quad (v,w) \mapsto \phi(v,w)  $$
$$ \text{satsifying } \phi(v,w) \in L^2(V^*,W^*; \mathbb F) \quad s.t. \quad (v^*,w^*) \mapsto v^*(v)w^*(w) $$

이 때, 다음을 증명하여라.
$$ Z = L^2(V^*, W^*, \mathbb F) $$

**Proof**

$\beta,\gamma$를 각 각 $V,W$의 기저라고 하자.

[$L^2(V^*, W^*, \mathbb F) \subseteq Z$]  
$v^* = a_i\beta^i \in V^*, \enspace w^* = b_i\gamma^i \in W^*$가 있을 때, $f \in L^2(V^*, W^*; \mathbb F)$에 대해 다음이 성립한다.
$$ \begin{aligned} & f(v^*,w^*) = a_ib_jf(\beta^i,\gamma^j) \\ \Rightarrow \enspace & \exist v = c^i\beta_i \in V, \enspace w = d^i\gamma_i \in W \quad s.t. \quad c^id^j = f(\beta^i, \gamma^j) \\ \Rightarrow \enspace & f = \phi(v,w) \in Z \end{aligned}  $$

[$Z \subseteq L^2(V^*, W^*, \mathbb F)$]  
$v = a^i\beta_i, \enspace w = b^i\gamma_i$가 있을 때, $\phi(v,w) \in Z$ 대해 다음이 성립한다.
$$ \begin{aligned} & \phi(v,w) = a^ib^j \phi(\beta_i,\gamma_j) \\ \Rightarrow \enspace & \exist f \in L^2(V^*, W^*, \mathbb F) \quad s.t. \quad a^ib^j = f(\beta^i, \gamma^j) \\ \Rightarrow \enspace & \phi(v,w) = f \in L^2(V^*, W^*, \mathbb F) \quad {_\blacksquare} \end{aligned}  $$

#### 보조명제3
집합 $Z$에 대해서 함수 $B$를 다음과 같이 정의하자.
$$ B:V \times W \rightarrow Z \quad s.t. \quad (v,w) \mapsto \phi(v,w)  $$
$$ \text{satsifying } \phi(v,w) \in L^2(V^*,W^*; \mathbb F) \quad s.t. \quad (v^*,w^*) \mapsto v^*(v)w^*(w) $$

$\beta,\gamma$를 각 각 $V,W$의 기저라고 할 때, $\phi(\beta_i,\gamma_j)$가 $Z$의 기저임을 증명하여라.

**Proof**

[linearly independent]  
$v^* = a_i\beta^i \in V^*, \enspace w^* = b_i \gamma^i \in W^*$라 할 때, 다음이 성립한다.
$$ \begin{aligned} & c_{ij}\phi(\beta_i,\gamma_j) = 0_Z \\ \Rightarrow \enspace & \left( c_{ij}\phi(\beta_i,\gamma_j) \right)(v^*, w^*) = 0_{\mathbb F} \\ \Rightarrow \enspace & c_{ij}a_ib_j  = 0 \end{aligned} $$

이 떄, 임의의 모든 $a_i, b_j$에 대해서 만족해야 함으로 $c_ij =0$이다. $\quad {_\blacksquare}$

[$\text{Span}(\{ \phi(\beta_i, \gamma_j)\}) = Z$]   
 -[$\text{Span}(\{ \phi(\beta_i, \gamma_j)\}) \subseteq Z$]  
 $c^{ij}\phi(\beta_i,\gamma_j) \in \text{Span}(\{ \phi(\beta_i, \gamma_j)\})$라 할 때, 다음이 성립한다.
 $$ \begin{aligned} & \exist a^i,b^j \in \mathbb F \quad s.t. \quad a^ib^j = c^{ij} \\ \Rightarrow \enspace & c^{ij}\phi(\beta_i,\gamma_j) = \phi(a^i\beta_i, b^j\gamma_j) \in Z \quad {_\blacksquare} \end{aligned}  $$

 -[$Z \subseteq \text{Span}(\{ \phi(\beta_i, \gamma_j)\})$]  
 $v = a^i\beta_i, \enspace w = b^i\gamma_i$가 있을 때, $\phi(v,w) \in Z$ 대해 다음이 성립한다.
 $$ \phi(v,w) = a^ib^j\phi(\beta_i,\gamma_j) \in \text{Span}(\{ \phi(\beta_i, \gamma_j)\} \quad {_\blacksquare} $$

### 명제2
두 벡터공간 $V,W / \mathbb F$이 있을 때, $L(V^*,W),L(V,W^*),L^2(V,W; \mathbb F)$도 $V \otimes W$임을 증명하여라.

### 명제3
두 벡터공간 $V,W / \mathbb F$이 있을 때, $(V \otimes W, \phi)_1, (V \otimes W, \phi)_2$를 두개의 $V \otimes W$라고 하자. 이 때, 다음과 같이 정의된 vector space isomorphism $T$가 유일하게 존재함을 증명하여라
$$ T \in L( (V \otimes W)_1, (V \otimes W)_2) \quad s.t. \quad \phi_2 = T \circ \phi_1  $$

**Proof**

Tensor product의 정의에서 $V \otimes W = (V \otimes W)_1, \enspace B = \phi_1$라 두고, $X = (V \otimes W)_2, \enspace H = \phi_2$라하면 Tensor product의 정의에 의해, 다음이 성립한다.
$$ \exist! T \in L( (V \otimes W)_1; (V \otimes W)_2) \quad s.t. \quad \phi_2 = T \circ \phi_1 $$

이번에는 반대로 역할을 바꿔 Tensor product의 정의에서 $V \otimes W = (V \otimes W)_2, \enspace B = \phi_2$라 두고, $X = (V \otimes W)_1, \enspace H = \phi_1$라하면 Tensor product의 정의에 의해, 다음이 성립한다.
$$ \exist! S \in L( (V \otimes W)_2; (V \otimes W)_1) \quad s.t. \quad \phi_1 = S \circ \phi_2 $$

이 때, 위의 관계식에 의해 다음이 성립힌다.
$$ S \circ T \circ \phi_1 = S \circ \phi_2 = \phi_1 $$

이번에는 Tensor product의 정의에서 $V \otimes W = (V \otimes W)_1, \enspace B = \phi_1$라 두고, $X = (V \otimes W)_1, \enspace H = \phi_1$라하면 Tensor product의 정의에 의해, 다음이 성립한다.
$$ \exist! R \in L( (V \otimes W)_1) \quad s.t. \quad \phi_1 = R \circ \phi_1 $$

$S,T$는 모두 linear map임으로 $S \circ T$는 linear map이고 따라서 $S \circ T$와 $id_{L((V\otimes W)_1)}$ 모두 $R$의 역활을 할 수 있다. 이 떄, $R$은 유일함으로 $S \circ T = id_{L((V\otimes W)_1)}$이다. 동일한 논리로 $T \circ S = id_{L((V\otimes W)_2)}$이다.

$T$와 $S$는 역함수 관계임으로 $T$는 vector space isomorphism이다. 그리고 $T$는 Tensor product의 정의에 의해 유일하게 존재한다. $\quad {_\blacksquare}$

> 참고  
> [note] (Kamnitzer) Tensor products

# Tensor
As multilinear maps  
using tnesor products

> 참고  
> [Tensor - Wiki](https://en.wikipedia.org/wiki/Tensor)  
> [피그티 기초 물리 tistory](https://elementary-physics.tistory.com/155)  
[텐서 - 나무위키](https://namu.wiki/w/%ED%85%90%EC%84%9C)  
[What are the Differences Between a Matrix and a Tensor? - StackExchange](https://math.stackexchange.com/questions/412423/what-are-the-differences-between-a-matrix-and-a-tensor)  
[텐서 - 전파거북이 블로그](https://ghebook.blogspot.com/2011/06/tensor.html)


## Tensor Product
벡터 공간 $V,W/\mathbb{F}$가 있을 때, 두 벡터공간의 tensor product $V \otimes W$는 모든 bilinear map $h : V \times W \rightarrow Z$에 대해 $h = \tilde{h} \circ \otimes$를 만족하는 유일한 선형변환 $\tilde{h} : V \otimes W \rightarrow Z$이 존재하도록 하는 bilinear map $\otimes:V \times W \rightarrow V \otimes W$이 주어진 벡터공간이다.

> 참고  
> [Universal property - Wiki](https://en.wikipedia.org/wiki/Universal_property)  
> [Tensor Proudct - Wiki](https://en.wikipedia.org/wiki/Tensor_product#Universal_property)  
> [tensor-products-universal-property-and-a-particular-identification - Mathematics](https://math.stackexchange.com/questions/2674549/tensor-products-universal-property-and-a-particular-identification)  
> [proof-of-universal-mapping-property-for-tensor-product-of-vector-spaces - Mathematics](https://math.stackexchange.com/questions/2713003/proof-of-universal-mapping-property-for-tensor-product-of-vector-spaces)  
> [change-of-basis-of-tensors - Mathmatics](https://math.stackexchange.com/questions/3451369/change-of-basis-of-tensors)


# Dyad
$\bf u,v,w$를 벡터라고 하자.
$$ \bf (u \otimes v) \cdot w = u(v \cdot w) $$

위의 관계식을 만족하는 $\bf u \otimes v$를 `dyad`라고 한다. 이 때, $\otimes$를 `텐서곱(tensor product)`이라 한다.

### 명제1
dyad는 선형변환임을 증명하여라.

### 명제2
dyad는 교환법칙이 성립하지 않음을 증명하여라.

### 명제3
$\bf u,v,w,x$를 벡터라고 할 때 다음을 증명하여라.
$$ (\bf (u \otimes v) \cdot w) \otimes x = (u \otimes v) \cdot (w \otimes x) $$

### 명제4
$\bf u,v,w,x$를 벡터라고 할 때 다음을 증명하여라.
$$ \bf (u \otimes v)\cdot(w \otimes x) = (v \cdot w)(u \otimes x) $$

### 명제5
$\bf u,v,w$를 벡터라고 할 때 다음을 증명하여라.
$$ \bf u \cdot (v \otimes w) = (u \cdot v) w $$


# Cartesian Tensor

### 명제1
$\bf I$가 Cartesian Tensor의 Identity tensor라 할 때, 다음을 증명하여라.

$$ \mathbf I = \mathbf e_i \mathbf e_i $$

**Proof**

$\mathbf I = \mathbf e_i \mathbf e_i$라 가정하고 $\bf u$를 임의의 벡터라 하자.

$$ \mathbf{I \cdot u} = u_j (\mathbf e_i \otimes \mathbf e_i) \cdot \mathbf e_j = u_j \delta_{ij} \mathbf e_i = u_i \mathbf e_i \quad {_\blacksquare} $$

### 명제2
$\bf A$가 Cartesian Tensor라 할 때, 다음을 증명하여라.
$$ A_{ij} = (\mathbf A \cdot \mathbf e_j) \cdot \mathbf e_i $$

**Proof**

$$ \mathbf A \cdot \mathbf e_j \cdot \mathbf e_i = A_{kl}((\mathbf e_k \otimes \mathbf e_l) \cdot \mathbf e_j) \cdot \mathbf e_i = A_{kl} \delta_{lj} \delta_{ki} = A_{ij} \quad {_\blacksquare} $$

### 명제3
$\bf A$가 Cartesian Tensor, $\bf x$가 벡터라고 할 때 다음을 증명하여라.
$$ \frac{\partial \mathbf x^T \bf Ax}{\partial \mathbf x} = (\mathbf A^T + \bf A )x  $$

**Proof**  


# Isotropic Tensor
[Isotropic Tensor](https://farside.ph.utexas.edu/teaching/336L/Fluid/node252.html)  
[2nd order isotropic tensor](https://www.weizmann.ac.il/chembiophys/bouchbinder/sites/chemphys.bouchbinder/files/uploads/Courses/2019/TA2-IndexGymnastics.pdf)  
[4th order isotropic tensor](https://math.stackexchange.com/questions/3589647/general-form-of-an-isotropic-fourth-rank-tensor)  