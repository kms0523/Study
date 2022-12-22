# Dispacement based FE Formulation


## Dispalcement based Momentum Equations
Dispaclement를 $d$라 할 떄, infinitesimal strain tensor $\epsilon(d)$은 다음과 같다.

$$ \epsilon(d) = \epsilon_{ij}(d)e_{ij} = \frac{1}{2} \bigg( \frac{\partial d_i}{\partial x_j} + \frac{\partial d_j}{\partial x_i} \bigg)e_{ij} $$

Linear elastic material의 변형이 작다고 가정하면 linear stiffness tensor $C$에 대해 다음이 성립한다.

$$ \sigma(d) = C:\epsilon $$

위 관계식을 momentume equations에 대입하면 displacement based momentum equations를 얻을 수 있다.

## Dispacement based Weak Formulation

### Equilibrium State
Boundary value problem(BVP)이 다음과 같이 주어졌다고 하자.

$$ \text{find} \enspace d \in \mathcal D^3 \quad s.t. \quad \text{div}(\sigma(d)) + \rho f_b = 0 $$


$$ \text{Where, } \mathcal{D} := \{ d_i \in C^2(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega \}  $$

BVP의 Weighted residual form은 다음과 같다.

$$ \text{find} \enspace d \in \mathcal D^3 \quad s.t. \quad \forall w \in (C^\infty_c)^3, \quad \int_{\Omega} \text{div}(\sigma(d)) \cdot w \thinspace dV + \int_{\Omega} \rho f_b \cdot w \thinspace dV = 0 $$

> Q. test vector function과 내적한 식의 해가 연립방정식의 해와 동일한가?

명제1에 의해 다음이 성립한다.

$$ \int_{\Omega} \text{div}(\sigma) \cdot w \thinspace dV = \int _{\partial\Omega} t \cdot  w dS - \int_{\Omega} \sigma : \text{grad}(w) dV$$


---

명제1과 적절한 regularity relaxation에 의해 유도된 Weak form은 다음과 같다.

$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall w \in \mathcal W^3, \quad \int_{\Omega} \sigma(d) : \text{grad}(w) dV = \int_{\partial\Omega} t \cdot  w dS + \int _{\Omega} \rho f_b \cdot w dV $$


$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ w \in C^\infty(\Omega) \enspace | \enspace \forall  x \in \partial\Omega_E, \quad w( x) = 0 \} \end{aligned}  $$

#### 참고1(Principle of Virtual Displacement)
Weak formulation의 test function $w$를 `가상 변위(virtual displacement)` $\delta$로 보면 다음이 성립한다.

$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall \delta \in \mathcal W^3, \quad \int_{\Omega} \sigma(d) : \text{grad}(\delta) \thinspace  dV = \int_{\partial\Omega} t \cdot  \delta \thinspace dS + \int _{\Omega} \rho f_b \cdot \delta \thinspace dV $$


$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ \delta_i \in C^\infty(\Omega) \enspace | \enspace \forall  x \in \partial\Omega_E, \quad \delta_i( x) = 0 \} \end{aligned} $$

이 떄, $\delta(\delta  d)$를 변형률로써 해석하면, 좌측항은 물리적으로 `내부 가상 일(internal virtual work)`, 우측항은 `외부 가상 일(external virtual work)`로 볼 수 있기 때문에 가상 일 원리라고 한다.

> Reference  
> {cite}`bathe`p.156

#### 명제1
$\sigma, w$가 충분히 매끄러울 때, 다음을 증명하여라.

$$ \int_{\Omega} \text{div}(\sigma) \cdot w \thinspace dV = \int _{\partial\Omega} t \cdot  w dS - \int_{\Omega} \sigma : \text{grad}(w) dV$$

**Proof**

Divergence theorem에 의해 다음이 성립한다.

$$ \begin{aligned} \int_{\Omega} \text{div}(\sigma) \cdot w \thinspace dV &=  \int_{\Omega} \mathrm{div}(w^T \sigma) - \sigma : \text{grad}(w) \thinspace dV \\&= \int _{\partial\Omega} w^T \sigma n dS - \int_{\Omega} \sigma : \text{grad}(w) dV \\&= \int _{\partial\Omega} t \cdot  w dS - \int_{\Omega} \sigma : \text{grad}(w) dV \end{aligned} $$

## Equilibrium State
FE formulation은 물리적으로 essential BC에 대응되는 natural BC가 존재한다는 관측에서부터 시작한다.

다시 말해, 지지조건으로 displacement가 결정된 essential BC에는 지지력이 발생하게 되고, 이 지지력을 지지조건 대신에 부여해도 같은 해를 얻을 수 있다는 것이다. 

따라서 essential BC를 대응되는 natrual BC로 바꾸면 다음이 성립한다.
$$ \partial\Omega = \partial\Omega_N $$

> Reference  
> {cite}`bathe`p.161  

Essential BC를 natural BC로 바꾸면 solution function space와 test function space의 restriction이 완화되며 BVP는 다음과 같아진다.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall w \in (C^\infty)^3, \quad \int_{\Omega} \sigma : \text{grad}(w) dV = \int _{\partial\Omega} t \cdot  w dS + \int _{\Omega} \rho f_b \cdot w dV $$

$$ \text{Where, } \mathcal{D}_W := \{ d_i \in C^1(\Omega) \} $$

$\Omega$를 서로 겹치지 않는 $N_E$개의 요소로 나눈 다음 각각의 요소 $\Omega_i \enspace i = 1, \cdots, N_E$ 에서 BVP를 만족한다고 하자.
$$ \text{find} \enspace d \in (\mathcal D_{W_i})^3 \quad s.t. \quad \forall w \in (C^\infty)^3, \quad \int_{\Omega_i} \sigma : \text{grad}(w) \thinspace dV = \int _{\partial\Omega_i} t \cdot  w \thinspace dS + \int_{\Omega_i} \rho f_b \cdot w \thinspace dV $$

$$ \text{Where, } \mathcal{D}_{W_i} := \{ d_i \in C^1(\Omega_i) \} $$

명제1에 의해 다음이 성립한다.
$$ \text{find} \enspace d \in (\mathcal D_{W_i})^3 \quad s.t. \quad \forall w \in (C^\infty)^3, \quad \int_{\Omega_i} C \epsilon_v \cdot \partial  w \thinspace dV = \int _{\partial\Omega_i} t \cdot  w \thinspace dS + \int_{\Omega_i} \rho f_b \cdot w \thinspace dV $$

Bodunov-Galerkin method를 사용하면 명제2에 의해 BVP가 다음과 같아진다.
$$ \text{find} \enspace \hat{d}_i \in \R^{3N_{N_i}} \quad s.t. \quad K_i\hat{d}_i = f_i \quad (i=1,\cdots,N_E) $$

Direct stiffness method를 사용하여 element equation을 global equation으로 assemble한다.
$$ \text{find} \enspace \hat{d} \in \R^{3N_N} \quad s.t. \quad K\hat{d} = f $$

### 명제1
다음을 증명하여라.
$$ \sigma : \text{grad}(w) = C\epsilon_v \cdot \partial  w $$

$$ \begin{aligned} \text{Where, } C &:= \text{elasticity matrix} \\  \epsilon_v &= \begin{bmatrix} \epsilon_{11} & \epsilon_{22} & \epsilon_{33} & 2\epsilon_{23} & 2\epsilon_{13} & 2\epsilon_{12} \end{bmatrix}^T \\ \partial &= \begin{bmatrix} \frac{\partial}{\partial x_1} & 0 & 0 \\ 0 & \frac{\partial}{\partial x_2} & 0 \\ 0 & 0 & \frac{\partial}{\partial x_3} \\ 0 & \frac{\partial}{\partial x_3} & \frac{\partial}{\partial x_2} \\ \frac{\partial}{\partial x_3} & 0 & \frac{\partial}{\partial x_1} \\ \frac{\partial}{\partial x_2} & \frac{\partial}{\partial x_1} & 0 \end{bmatrix} \\ w &= \begin{bmatrix} w_1 & w_2 & w_3 \end{bmatrix}^T \end{aligned} $$

**Proof**

$\sigma$의 symmetry에 의해 $i \neq j$일 때, 다음이 성립한다.
$$ \sigma_{ij}\frac{\partial w_i}{\partial x_j} + \sigma_{ji}\frac{\partial w_j}{\partial x_i} = \sigma_{ij} \bigg( \frac{\partial w_i}{\partial x_j} + \frac{\partial w_j}{\partial x_i} \bigg) \enspace \text{(not summation)} $$

따라서, 다음이 성립한다.
$$ \sigma : \text{grad}(w) = \sigma_v \cdot \partial w $$

$$ \text{Where, } \sigma_v = \begin{bmatrix} \sigma_{11} & \sigma_{22} & \sigma_{33} & \sigma_{23} & \sigma_{13} & \sigma_{12} \end{bmatrix}^T $$

이 때, 구성방정식에 의하여 다음이 성립한다.
$$ \sigma_v = C \epsilon_v $$

따라서, 다음이 성립한다. 
$$ \sigma : \text{grad}(w) = C\epsilon_v \cdot \partial  w \quad\tiny\blacksquare$$

### 명제2(Bodunov-Galerkin method)
각각의 요소 $\Omega_i \enspace i = 1, \cdots, N_E$에서 BVP가 다음과 같이 주어졌다고 하자.
$$ \text{find} \enspace d \in (\mathcal D_{W_i})^3 \quad s.t. \quad \forall w \in (C^\infty)^3, \quad \int_{\Omega_i} C \epsilon_v \cdot \partial  w \thinspace dV = \int _{\partial\Omega_i} t \cdot  w \thinspace dS + \int_{\Omega_i} \rho f_b \cdot w \thinspace dV $$

$\Omega_i$는 $N_{N_i}$개의 node로 구성되어 있으며, $\Omega_i$에서 축소된 solution function space $\mathcal D_i$는 다음과 같다. 
$$ \mathcal D_i = \text{span}(\{ (h_i)_1,\cdots,(h_i)_{N_{N_i}} \})$$

$$ \text{Where, } h_i \text{ is a shape function.} $$

Bodunov-Galerkin method를 사용하고 solution function의 approximation을 다음과 같이 하자.
$$ \begin{aligned} d &= d(x_1)(h_i)_1 + \cdots + d(x_{N_{N_i}})(h_i)_{N_{N_i}} \\&= H_i\hat{d}_i \end{aligned} $$

$$ \begin{aligned} \text{Where, } H_i &= \begin{bmatrix} (h_i)_1 & 0 & 0 & \cdots & (h_i)_{N_{N_i}} & 0 & 0 \\ 0 & (h_i)_1 & 0 & \cdots & 0 & (h_i)_{N_{N_i}} & 0 \\ 0 & 0 & (h_i)_1  & \cdots & 0 & 0 & (h_i)_{N_{N_i}}  \\\end{bmatrix} \\ \hat{d}_i &= \begin{bmatrix} d(x_1)_1 & d(x_1)_2 & d(x_1)_3 & \cdots & d(x_{N_{N_i}})_1 & d(x_{N_{N_i}})_2 & d(x_{N_{N_i}})_3 \end{bmatrix}^T \end{aligned} $$

이 때, BVP가 다음과 같아 짐을 증명하여라.
$$ \text{find} \enspace \hat{d}_i \in \R^{3N_{N_i}} \quad s.t. \quad K_i\hat{d}_i = f_i $$

$$ \begin{aligned} \text{Where, } K_i &= \int_{\Omega_i} (B_i)^T C_i B_i \thinspace dV \\ f_i &= \int _{\partial\Omega_i}  (H_i)^T  t \thinspace dS + \int _{\Omega_i}  (H_i)^Tf_b \thinspace dV \\ B_i &= \partial H_i \end{aligned} $$

**Proof**

Bodunov-Galerkin method를 사용하면 solution function과 weight function을 다음과 같이 근사할 수 있다.
$$ d = H_i\hat{d}_i, \enspace w = H_i\hat{w} $$

그러면 다음이 성립한다.
$$ \epsilon_v = \partial d = \partial H_i\hat{d}_i = B_i\hat{d}_i $$

그러면 BVP는 다음과 같아진다.
$$ \def\arraystretch{2}\begin{darray}{lll} &\text{find} \enspace \hat{d}_i \in \R^{3N_{N_i}} \quad s.t. \quad \forall \hat{w} \in \R^{3N_{N_i}} & \int_{\Omega_i} C \epsilon_v \cdot B_i\hat{w} \thinspace dV = \int_{\partial\Omega_i} t \cdot H_i\hat{w} \thinspace dS + \int_{\Omega_i} \rho f_b \cdot H_i\hat{w} \thinspace dV \\ \implies& & \hat{w}^T \left( \int_{\Omega_i} B_i^TCB \thinspace dV \hat{d}_i  - \int_{\partial\Omega_i} (H_i)^T t \thinspace dS - \int_{\Omega_i} (H_i)^Tf_b \thinspace dV \right) = 0 \end{darray} $$

$\forall \hat{w} \in \R^{3N_{N_i}}$에 대해서 위 식이 성립함으로 BVP가 다음과 같이 간단해진다.
$$ \def\arraystretch{2}\begin{darray}{lll} &\text{find} \enspace \hat{d}_i \in \R^{3N_{N_i}} & \int_{\Omega_i}  B_i^TCB \thinspace dV \hat{d}_i = \int_{\partial\Omega_i} (H_i)^T t \thinspace dS + \int_{\Omega_i} (H_i)^Tf_b \thinspace dV \\ \implies&&  K_i \hat{d}_i = f_i \quad\tiny\blacksquare \end{darray} $$
