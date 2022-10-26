# Momentum Equations
연속체 $\Omega$가 있다고 하자.

$\Omega$에 Euler의 운동방정식과 Euler-Cauchy stress principle을 적용하면 다음과 같다.
$$ \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho f_b \thinspace dV = \frac{d}{dt} \int_\Omega \rho u \thinspace dV $$

이를 `적분형(integral form)` 운동방정식이라 한다.

## Equilibrium State
$\Omega$가 정적 평형 상태에 있을 때, 적분형 운동방정식은 다음과 같다.
$$ \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho  f_b \thinspace dV = 0 $$

### 명제1(Differential form)
연속체 $\Omega$가 있다고 하자.

$\rho u, \sigma$가 충분히 매끄럽다고 할 때, 다음을 증명하여라.
$$ \begin{aligned} & \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho f_b \thinspace dV = \frac{d}{dt} \int_\Omega \rho u \thinspace dV \\ \Leftrightarrow \enspace & \mathrm{div}(\boldsymbol\sigma) + \rho  f_b = \frac{\partial}{\partial t}(\rho  u) + \mathrm{div}(\rho  u \otimes u) \end{aligned}  $$

**Proof**

$\rho u$가 충분히 매끄러움으로, Integral form $\frac{d}{dt} \int_\Omega \rho u \thinspace dV$에 Leibniz integral theorem을 적용하면 다음과 같다.
$$ \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho  f_b \thinspace dV = \int_\Omega \frac{\partial}{\partial t} (\rho u) + \text{div}(\rho u \otimes u) \thinspace dV $$

이 때, $\sigma$도 충분히 매끄러움으로 $\int_{\partial\Omega} \sigma n \thinspace dS$에 divergence theorem을 적용하면 다음과 같다.
$$ \int_{\Omega} \text{div} (\sigma) +\rho  f_b \thinspace dV = \int_\Omega \frac{\partial}{\partial t} (\rho u) + \text{div}(\rho u \otimes u) \thinspace dV $$

위 식은 임의의 $\Omega$에서 성립해야 함으로 다음이 성립한다.
$$ \mathrm{div}(\boldsymbol\sigma) + \rho  f_b = \frac{\partial}{\partial t}(\rho  u) + \mathrm{div}(\rho  u \otimes u) $$

따라서, 위 식은 적분형 운동방정식과 동일하며 이를 미분형 운동방정식이라 한다.$\quad {_\blacksquare}$

#### 명제1.1
연속체 $\Omega$가 정적 평형상태에 있다고 하자.

$\rho u, \sigma$가 충분히 매끄럽다고 할 때, 다음을 증명하여라.
$$ \begin{aligned} & \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho f_b \thinspace dV = 0 \\ \Leftrightarrow \enspace & \mathrm{div}(\boldsymbol\sigma) + \rho  f_b = 0 \end{aligned}  $$

**Proof**

명제1과 동일한 방법으로 증명할 수 있다. $\quad {_\blacksquare}$


# Dispalcement based Momentum Equations
Dispaclement를 $d$라 할 떄, infinitesimal strain tensor $\epsilon(d)$은 다음과 같다.
$$ \epsilon(d) = \epsilon_{ij}(d)e_{ij} = \frac{1}{2} \bigg( \frac{\partial d_i}{\partial x_j} + \frac{\partial d_j}{\partial x_i} \bigg)e_{ij} $$

Linear elastic material의 변형이 작다고 가정하면 linear stiffness tensor $C$에 대해 다음이 성립한다.
$$ \sigma(d) = C:\epsilon $$

위 관계식을 momentume equations에 대입하면 displacement based momentum equations를 얻을 수 있다.

# Dispacement based Weak Formulation

## Equilibrium State
Boundary value problem(BVP)이 다음과 같이 주어졌다고 하자.
$$ \text{find} \enspace d \in \mathcal D^3 \quad s.t. \quad \text{div}(\sigma(d)) + \rho f_b = 0 $$

$$ \text{Where, } \mathcal{D} := \{ d_i \in C^2(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega \}  $$

BVP의 Weighted residual form은 다음과 같다.
$$ \text{find} \enspace d \in \mathcal D^3 \quad s.t. \quad \forall w \in (C^\infty_c)^3, \quad \int_{\Omega} \text{div}(\sigma(d)) \cdot w \thinspace dV + \int_{\Omega} \rho f_b \cdot w \thinspace dV = 0 $$

> Q. test vector function과 내적한 식의 해가 연립방정식의 해와 동일한가?

명제1과 적절한 regularity relaxation에 의해 유도된 Weak form은 다음과 같다.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall w \in \mathcal W^3, \quad \int_{\Omega} \sigma(d) : \text{grad}(w) dV = \int_{\partial\Omega} t \cdot  w dS + \int _{\Omega} \rho f_b \cdot w dV $$

$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ w \in C^\infty(\Omega) \enspace | \enspace \forall  x \in \partial\Omega_E, \quad w( x) = 0 \} \end{aligned}  $$

> Reference  
> [Book] (Bathe) Finite Element Procedures p.161

### 명제1
$\sigma, w$가 충분히 매끄러울 때, 다음을 증명하여라.
$$ \int_{\Omega} \text{div}(\sigma) \cdot w \thinspace dV = \int _{\partial\Omega} t \cdot  w dS - \int_{\Omega} \sigma : \text{grad}(w) dV$$

**Proof**

Divergence theorem에 의해 다음이 성립한다.
$$ \begin{aligned} \int_{\Omega} \text{div}(\sigma) \cdot w \thinspace dV &=  \int_{\Omega} \mathrm{div}(w^T \sigma) - \sigma : \text{grad}(w) \thinspace dV \\&= \int _{\partial\Omega} w^T \sigma n dS - \int_{\Omega} \sigma : \text{grad}(w) dV \\&= \int _{\partial\Omega} t \cdot  w dS - \int_{\Omega} \sigma : \text{grad}(w) dV \end{aligned} $$


### 참고1(Principle of Virtual Displacement)
Weak formulation의 test function $w$를 `가상 변위(virtual displacement)` $\delta d$로 보면 다음이 성립한다.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall \delta d \in \mathcal W^3, \quad \int_{\Omega} \sigma(d) : \text{grad}(\delta d) \thinspace  dV = \int_{\partial\Omega} t \cdot  \delta d \thinspace dS + \int _{\Omega} \rho f_b \cdot \delta d \thinspace dV $$

$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ \delta d_i \in C^\infty(\Omega) \enspace | \enspace \forall  x \in \partial\Omega_E, \quad \delta d_i( x) = 0 \} \end{aligned}  $$


이 떄, $\delta(\delta  d)$를 변형률로써 해석하면, 좌측항은 물리적으로 `내부 가상 일(internal virtual work)`, 우측항은 `외부 가상 일(external virtual work)`로 볼 수 있기 때문에 가상 일 원리라고 한다.

> Reference  
> [Book] (Bathe) Finite Element Procedures p.156

# Dispacement based FE Formulation
FE formulation은 물리적으로 essential BC에 대응되는 natural BC가 존재한다는 관측에서부터 시작한다.

다시 말해, 지지조건으로 displacement가 결정된 essential BC에는 지지력이 발생하게 되고, 이 지지력을 지지조건 대신에 부여해도 같은 해를 얻을 수 있다는 것이다. 

따라서 essential BC를 대응되는 natrual BC로 바꾸면 다음이 성립한다.
$$ \partial\Omega = \partial\Omega_N $$

## Equilibrium State
Essential BC를 natural BC로 바꾸면 solution function space와 test function space의 restriction이 완화되며 BVP는 다음과 같아진다.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall w \in (C^\infty)^3, \quad \int_{\Omega} \sigma : \text{grad}(w) dV = \int _{\partial\Omega} t \cdot  w dS + \int _{\Omega} \rho f_b \cdot w dV $$

$$ \text{Where, } \mathcal{D}_W := \{ d_i \in C^1(\Omega) \} $$

$\Omega$를 서로 겹치지 않는 $N_E$개의 요소로 나누면 다음과 같다,
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall w \in (C^\infty)^3, \quad \sum_{i=1}^{N_E}\int_{\Omega_i} \sigma : \text{grad}(w) \thinspace dV = \sum_{i=1}^{N_E}\int _{\partial\Omega_i} t \cdot  w \thinspace dS +\sum_{i=1}^{N_E} \int_{\Omega_i} \rho f_b \cdot w \thinspace dV $$

명제1에 의해 다음이 성립한다.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall w \in (C^\infty)^3, \quad \sum_{i=1}^{N_E}\int_{\Omega_i} \sigma_v \cdot \delta w \thinspace dV = \sum_{i=1}^{N_E}\int _{\partial\Omega_i} t \cdot  w \thinspace dS +\sum_{i=1}^{N_E} \int_{\Omega_i} \rho f_b \cdot w \thinspace dV $$

Bodunov-Galerkin method를 사용하면 명제2에 의해 BVP가 다음과 같아진다.



### 명제1
다음을 증명하여라.
$$ \sigma : \text{grad}(w) = \sigma_v \cdot \delta  w $$

$$ \text{Where, } \sigma_v = \begin{bmatrix} \sigma_{11} \\ \sigma_{22} \\ \sigma_{33} \\ \sigma_{23} \\ \sigma_{13} \\ \sigma_{12} \end{bmatrix}, \enspace \delta  w = \begin{bmatrix} \frac{\partial w_1}{\partial x_1} \\ \frac{\partial w_2}{\partial x_2} \\ \frac{\partial w_3}{\partial x_3} \\ \frac{\partial w_2}{\partial x_3} + \frac{\partial w_3}{\partial x_2}  \\ \frac{\partial w_1}{\partial x_3} + \frac{\partial w_3}{\partial x_1} \\ \frac{\partial w_1}{\partial x_2} + \frac{\partial w_2}{\partial x_1} \end{bmatrix} $$

**Proof**

$\sigma$의 symmetry에 의해 $i \neq j$일 때, 다음이 성립한다.
$$ \sigma_{ij}\frac{\partial w_i}{\partial x_j} + \sigma_{ji}\frac{\partial w_j}{\partial x_i} = \sigma_{ij} \bigg( \frac{\partial w_i}{\partial x_j} + \frac{\partial w_j}{\partial x_i} \bigg) \enspace \text{(not summation)} $$

따라서, 직접 계산해보면 두 식이 동일함을 알 수 있다.$\quad\tiny\blacksquare$ 

### 명제2(Bodunov-Galerkin method)
BVP이 다음과 같이 주어졌다고 하자.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall w \in (C^\infty)^3, \quad \sum_{i=1}^{N_E}\int_{\Omega_i} \sigma_v \cdot \delta w \thinspace dV = \sum_{i=1}^{N_E}\int _{\partial\Omega_i} t \cdot  w \thinspace dS +\sum_{i=1}^{N_E} \int_{\Omega_i} \rho f_b \cdot w \thinspace dV $$

$$ \text{Where, } \mathcal{D}_W := \{ d_i \in C^1(\Omega) \} $$


Bodunov-Galerkin method를 사용한다. Solution function space의 기저 함수로 shape function을 사용하면 solution과 weight vector를 각 각 $d =  N \hat{d},  w =  N \boldsymbol{\delta}$ 표현할 수 있고 문제가 다음과 같이 간단해진다.




### Bodunov-Galerkin method
weak formulation을 수치적으로 풀기 위해 Bodunov-Galerkin method를 사용한다. Solution function space의 기저 함수로 shape function을 사용하면 solution과 weight vector를 각 각 $d =  N \hat{d},  w =  N \boldsymbol{\delta}$ 표현할 수 있고 문제가 다음과 같이 간단해진다.
$$ \text{find} \enspace \hat { d} \in \R^{3n} \quad s.t. \quad \forall \boldsymbol \delta \in \R^{3n}, \quad \int_{\Omega} \boldsymbol\sigma_v \cdot  B \boldsymbol \delta dV = \int _{\partial\Omega}  t \cdot  N \boldsymbol{\delta} dS + \int _{\Omega}  f \cdot  N \boldsymbol{\delta} dV $$

위 식을 다음과 같이 정리할 수 있다.
$$ \begin{aligned} & \int_{\Omega} \sigma_v \cdot  B  \delta dV = \int _{\partial\Omega}  t \cdot  N {\delta} dS + \int _{\Omega}  f \cdot  N {\delta} dS \\ \Leftrightarrow \enspace &   \delta^T \left( \int_{\Omega}  B^T \sigma_v \thinspace dV  - \int _{\partial\Omega}  n^T  t \thinspace dS - \int _{\Omega}  n^T  f \thinspace dV \right) = 0 \end{aligned} $$

임의의 $\boldsymbol \delta$에 대해서 위 식이 성립해야 됨으로 문제가 다음과 같이 간단해진다.
$$ \text{find} \enspace \hat { d} \in \R^{3n} \quad s.t. \quad K( \hat { d}) =  f  $$
$$ \text{Where, } K( \hat { d}) = \int_{\Omega}  B^T \boldsymbol\sigma_v \thinspace dV, \enspace  f = \int _{\partial\Omega}  n^T  t \thinspace dS + \int _{\Omega}  n^T  f \thinspace dV $$



# Infinitesimal Deformation Assumption
고체의 constitutive equation과 strain-displacement 관계식을 이용하면 다음과 같다.
$$ \boldsymbol\sigma_v =  C  \partial  d, \quad \delta  w =  \partial  w  $$

결론적으로 유도된 weak formulation은 다음과 같다.
$$ \begin{equation} \text{find} \enspace  d \in (\mathcal D_W)^3 \quad s.t. \quad \forall  w \in \mathcal W^3, \quad \int_{\Omega}  C  \partial  d \cdot  \partial  w dV = \int _{\partial\Omega}  t \cdot  w dS + \int _{\Omega}  {f \cdot w} dV \end{equation} $$
$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ w \in C^\infty(\Omega) \enspace | \enspace \forall  x \in \partial\Omega_E, \quad w( x) = 0 \ \end{aligned}  $$

weak formulation을 수치적으로 풀기 위해 Bodunov-Galerkin method를 사용한다. Solution function space의 기저 함수로 shape function을 사용하면 solution과 weight vector를 각 각 $ d =  N\hat{d}},  w =  N} \boldsymbol{\delta}$ 표현할 수 있고 문제가 다음과 같이 간단해진다.
$$ \begin{equation} \text{find} \enspace \hat { d} \in \R^{3n} \quad s.t. \quad \forall \boldsymbol \delta \in \R^{3n}, \quad \int_{\Omega}  C  B \hat { d} \cdot  B \boldsymbol \delta dV = \int _{\partial\Omega}  t \cdot  N} \boldsymbol{\delta} dS + \int _{\Omega}  f \cdot  N} \boldsymbol{\delta} dV \end{equation} $$

위 식을 다음과 같이 정리할 수 있다.
$$ \begin{aligned} & \int_{\Omega}  C  B \hat { d} \cdot  B \boldsymbol \delta dV = \int _{\partial\Omega}  t \cdot  N} \boldsymbol{\delta} dS + \int _{\Omega}  f \cdot  N} \\ \Leftrightarrow \enspace &  \boldsymbol \delta^T \left( \left( \int_{\Omega}  B^T  C  B \thinspace dV \right) \hat { d} - \int _{\partial\Omega}  n^T  t \thinspace dS - \int _{\Omega}  n^T  f \thinspace dV \right) = 0 \end{aligned} $$

임의의 $\boldsymbol \delta$에 대해서 위 식이 성립해야 됨으로 문제가 다음과 같이 간단해진다.
$$ \text{find} \enspace \hat { d} \in \R^{3n} \quad s.t. \quad  K \hat { d} =  f  $$
$$ \text{Where, }  K = \int_{\Omega}  B^T  C  B \thinspace dV, \enspace  f = \int _{\partial\Omega}  n^T  t \thinspace dS + \int _{\Omega}  n^T  f \thinspace dV $$

이 방법은 `가상 일 원리(principle of virtual work)`라고도 한다. $\bf w$를 `가상 변위(virtual displacement)` $\delta  d$로 보면 식(2)는 다음과 같다.
$$ \text{find} \enspace  d \in (\mathcal D_W)^3 \quad s.t. \quad \forall  \delta  d \in \mathcal W^3, \quad \int_{\Omega} \boldsymbol\sigma \cdot \delta \boldsymbol{\epsilon} dV = \int _{\partial\Omega}  t \cdot \delta  d dS + \int _{\Omega}  f \cdot \delta  d dV $$

좌측항은 물리적으로 `내부 가상 일(internal virtual work)`, 우측항은 `외부 가상 일(external virtual work)`로 볼 수 있기 때문에 가상 일 원리라고 한다.


---



결론적으로 유도된 weak formulation은 다음과 같다.
$$ \begin{equation} \text{find} \enspace  d \in (\mathcal D_W)^3 \quad s.t. \quad \forall  w \in \mathcal W^3, \quad \int_{\Omega} \boldsymbol\sigma_v \cdot \delta  w dV = \int _{\partial\Omega}  t \cdot  w dS + \int _{\Omega}  {f \cdot w} dV \end{equation} $$
$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ w \in C^\infty(\Omega) \enspace | \enspace \forall  x \in \partial\Omega_E, \quad w( x) = 0 \ \end{aligned}  $$

