# Momentum Equation
연속체 $\Omega$가 있다고 하자.

$\Omega$에 Euler의 운동방정식과 Euler-Cauchy stress principle을 적용하면 다음과 같다.
$$ \int_{\partial\Omega} \boldsymbol{\sigma}\mathbf n \thinspace dS + \int_\Omega \rho \mathbf f_b \thinspace dV = \frac{d}{dt} \int_\Omega \rho\mathbf u \thinspace dV $$

이를 적분형 지배방정식이라 한다.

$\rho u$가 충분히 매끄러울 떄, Leibniz integral theorem을 적용하면 다음과 같다.
$$ \int_{\partial\Omega} \boldsymbol{\sigma}\mathbf n \thinspace dS + \int_\Omega \rho \mathbf f_b \thinspace dV = \int_\Omega \frac{\partial}{\partial t} (\rho\mathbf u) + \text{div}(\rho u \otimes u) \thinspace dV $$

$\boldsymbol{\sigma}$가 충분히 매끄러울 때, divergence theorem을 적용하면 다음과 같다.
$$ \int_{\Omega} \text{div} (\boldsymbol{\sigma}) +\rho \mathbf f_b \thinspace dV = \int_\Omega \frac{\partial}{\partial t} (\rho\mathbf u) + \text{div}(\rho u \otimes u) \thinspace dV $$

이 때, 임의의 $\Omega$에서 위식이 성립해야 함으로 다음이 성립한다.
$$ \mathrm{div}(\boldsymbol\sigma) + \rho \mathbf f_b = \frac{\partial}{\partial t}(\rho \mathbf u) + \mathrm{div}(\rho \mathbf{u \otimes u}) $$

이를 미분형 지배방정식이라 한다.

> Reference  
> 연속체 역학 정리.md

## Equilibrium State
연속체 $\Omega$가 있다고 하자.

$\Omega$가 정적 평형 상태에 있을 때, 적분형 지배방정식은 다음과 같다.
$$ \int_{\partial\Omega} \boldsymbol{\sigma}\mathbf n \thinspace dS + \int_\Omega \rho \mathbf f_b \thinspace dV = 0 $$

$\Omega$가 정적 평형 상태에 있을 때, 미분형 지배방정식은 다음과 같다.
$$ \text{div}(\boldsymbol\sigma) + \rho \mathbf f_b = 0 $$

# Dispalcement based Momentum Equation
Dispaclement를 $d$라 할 떄, infinitesimal strain tensor $\epsilon(d)$은 다음과 같다.
$$ \epsilon_{ij} := \frac{1}{2} \bigg( \frac{\partial d_i}{\partial x_j} + \frac{\partial d_j}{\partial x_i} \bigg) $$

Linear elastic material의 변형이 작다고 가정하면 linear stiffness tensor $C$에 대해 다음이 성립한다.
$$ \sigma(d) = C:\epsilon $$

$\sigma$가 충분히 매끄럽다고 할 때, 미분형 momentume equations에 constitutive equation을 대입하면 displacement based momentum equations를 얻을 수 있다.

# Dispacement based FE Formulation

## Equilibrium State
Displacement based momentum equations으로 서술되는 boundary value problem(BVP)이 다음과 같이 주어졌다고 하자.
$$ \text{find} \enspace d \in \mathcal D^3 \quad s.t. \quad \text{div}(\sigma(d)) + \rho f_b = 0 $$

$$ \text{Where, } \mathcal{D} := \{ d_i \in C^2(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega \}  $$

BVP의 Weighted residual form은 다음과 같다.
$$ \text{find} \enspace d \in \mathcal D^3 \quad s.t. \quad \forall w \in (C^\infty_c)^3, \quad \int_{\Omega} \text{div}(\sigma(d)) \cdot w \thinspace dV + \int_{\Omega} \rho f_b \cdot w \thinspace dV = 0 $$

> Q. test vector function과 내적한 식의 해가 연립방정식의 해와 동일한가?

Weak form을 유도하기 위해, divergence theorem을 적용하면 다음과 같다.
$$ \begin{aligned} & \int_{\Omega} \text{div}(\sigma) \cdot w \thinspace dV + \int_{\Omega} \rho f_b \cdot w \thinspace dV = 0 \\ \Rightarrow \enspace & \int_{\Omega} \mathrm{div}(w^T \sigma) - \sigma : \text{grad}(w)  + \rho f_b \cdot w dV = 0. \\ \Rightarrow \enspace & \int_{\Omega} \sigma : \text{grad}(w) dV = \int _{\partial\Omega} w^T \sigma n dS + \int _{\Omega} \rho f_b \cdot w dV \\ \Rightarrow \enspace & \int_{\Omega} \sigma : \text{grad}(w) dV = \int _{\partial\Omega} t \cdot \mathbf w dS + \int _{\Omega} \rho f_b \cdot w dV \end{aligned} $$

따라서 결론적으로 유도된 weak formulation은 다음과 같다.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall w \in \mathcal W^3, \quad \int_{\Omega} \sigma(d) : \text{grad}(w) dV = \int_{\partial\Omega} t \cdot \mathbf w dS + \int _{\Omega} \rho f_b \cdot w dV $$

$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ w \in C^\infty(\Omega) \enspace | \enspace \forall \mathbf x \in \partial\Omega_E, \quad w(\mathbf x) = 0 \ \end{aligned}  $$

이 때, 물리적으로 essentail BC에 대응되는 natural BC가 존재한다. 다시 말해, 지지조건으로 displacement가 결정된 essential BC에는 지지력이 발생하게 되고, 이 지지력을 지지조건 대신에 부여해도 같은 해를 얻을 수 있다. 따라서 essential BC를 적절한 natrual BC로 바꿀 수 있게 된다. 

현재는 결정되지 않았지만, 나중에 계산을 통해 결정할 natural BC들이 주어졌다고 가정하면 위 논리에 따라 다음과 같이 둘 수 있다.
$$ \partial\Omega = \partial\Omega_N $$

따라서, BVP는 다음과 같아진다.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall w \in (C^\infty)^3, \quad \int_{\Omega} \sigma(d) : \text{grad}(w) dV = \int _{\partial\Omega} t \cdot \mathbf w dS + \int _{\Omega} \rho f_b \cdot w dV $$
$$ \text{Where, } \mathcal{D}_W := \{ d_i \in C^1(\Omega) \} $$

> Reference  
> [Book] (Bathe) Finite Element Procedures p.161


이 때, $\boldsymbol\sigma : \text{grad}(\mathbf w)$항은 $\boldsymbol{\sigma}$의 symmetry에 의해 다음과 같이 표현할 수 있다.
$$ \boldsymbol\sigma : \text{grad}(\mathbf w) = \boldsymbol\sigma_v \cdot \delta \mathbf w $$
$$ \text{Where, } \boldsymbol\sigma_v = \begin{bmatrix} \sigma_{11} \\ \sigma_{22} \\ \sigma_{33} \\ \sigma_{23} \\ \sigma_{13} \\ \sigma_{12} \end{bmatrix}, \enspace \delta \mathbf w = \begin{bmatrix} \frac{\partial w_1}{\partial x_1} \\ \frac{\partial w_2}{\partial x_2} \\ \frac{\partial w_3}{\partial x_3} \\ \frac{\partial w_2}{\partial x_3} + \frac{\partial w_3}{\partial x_2}  \\ \frac{\partial w_1}{\partial x_3} + \frac{\partial w_3}{\partial x_1} \\ \frac{\partial w_1}{\partial x_2} + \frac{\partial w_2}{\partial x_1} \end{bmatrix} $$


### 참고1(Principle of Virtual Displacement)
BVP의 weak formulation이 다음과 같이 주어졌다고 하자.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall w \in \mathcal W^3, \quad \int_{\Omega} \sigma(d) : \text{grad}(w) dV = \int_{\partial\Omega} t \cdot \mathbf w dS + \int _{\Omega} \rho f_b \cdot w dV $$

$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ w \in C^\infty(\Omega) \enspace | \enspace \forall \mathbf x \in \partial\Omega_E, \quad w(\mathbf x) = 0 \ \end{aligned}  $$

이 때, $w$를 `가상 변위(virtual displacement)` $\delta d$로 보면 다음이 성립한다.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall \delta d \in \mathcal W^3, \quad \int_{\Omega} \sigma(d) : \text{grad}(\delta d) \thinspace  dV = \int_{\partial\Omega} t \cdot \mathbf \delta d \thinspace dS + \int _{\Omega} \rho f_b \cdot \delta d \thinspace dV $$

이 떄, $\delta(\delta \mathbf d)$를 변형률로써 해석하면, 좌측항은 물리적으로 `내부 가상 일(internal virtual work)`, 우측항은 `외부 가상 일(external virtual work)`로 볼 수 있기 때문에 가상 일 원리라고 한다.

> Reference  
> [Book] (Bathe) Finite Element Procedures p.156

# 지배 방정식의 수치 방정식
## 정적 평형 방정식


### Bodunov-Galerkin method
weak formulation을 수치적으로 풀기 위해 Bodunov-Galerkin method를 사용한다. Solution function space의 기저 함수로 shape function을 사용하면 solution과 weight vector를 각 각 $\mathbf d = \mathbf{N\hat{d}}, \mathbf w = \mathbf{N} \boldsymbol{\delta}$ 표현할 수 있고 문제가 다음과 같이 간단해진다.
$$ \begin{equation} \text{find} \enspace \hat {\mathbf d} \in \R^{3n} \quad s.t. \quad \forall \boldsymbol \delta \in \R^{3n}, \quad \int_{\Omega} \boldsymbol\sigma_v \cdot \mathbf B \boldsymbol \delta dV = \int _{\partial\Omega} \mathbf t \cdot \mathbf{N} \boldsymbol{\delta} dS + \int _{\Omega} \mathbf f \cdot \mathbf{N} \boldsymbol{\delta} dV \end{equation} $$

위 식을 다음과 같이 정리할 수 있다.
$$ \begin{aligned} & \int_{\Omega} \boldsymbol\sigma_v \cdot \mathbf B \boldsymbol \delta dV = \int _{\partial\Omega} \mathbf t \cdot \mathbf{N} \boldsymbol{\delta} dS + \int _{\Omega} \mathbf f \cdot \mathbf{N} \boldsymbol{\delta} dS \\ \Leftrightarrow \enspace &  \boldsymbol \delta^T \left( \int_{\Omega} \mathbf B^T \boldsymbol\sigma_v \thinspace dV  - \int _{\partial\Omega} \mathbf N^T \mathbf t \thinspace dS - \int _{\Omega} \mathbf N^T \mathbf f \thinspace dV \right) = 0 \end{aligned} $$

임의의 $\boldsymbol \delta$에 대해서 위 식이 성립해야 됨으로 문제가 다음과 같이 간단해진다.
$$ \text{find} \enspace \hat {\mathbf d} \in \R^{3n} \quad s.t. \quad K( \hat {\mathbf d}) = \mathbf f  $$
$$ \text{Where, } K( \hat {\mathbf d}) = \int_{\Omega} \mathbf B^T \boldsymbol\sigma_v \thinspace dV, \enspace \mathbf f = \int _{\partial\Omega} \mathbf N^T \mathbf t \thinspace dS + \int _{\Omega} \mathbf N^T \mathbf f \thinspace dV $$



# Infinitesimal Deformation Assumption
고체의 constitutive equation과 strain-displacement 관계식을 이용하면 다음과 같다.
$$ \boldsymbol\sigma_v = \mathbf C \mathbf \partial \mathbf d, \quad \delta \mathbf w = \mathbf \partial \mathbf w  $$

결론적으로 유도된 weak formulation은 다음과 같다.
$$ \begin{equation} \text{find} \enspace \mathbf d \in (\mathcal D_W)^3 \quad s.t. \quad \forall \mathbf w \in \mathcal W^3, \quad \int_{\Omega} \mathbf C \mathbf \partial \mathbf d \cdot \mathbf \partial \mathbf w dV = \int _{\partial\Omega} \mathbf t \cdot \mathbf w dS + \int _{\Omega} \mathbf {f \cdot w} dV \end{equation} $$
$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ w \in C^\infty(\Omega) \enspace | \enspace \forall \mathbf x \in \partial\Omega_E, \quad w(\mathbf x) = 0 \ \end{aligned}  $$

weak formulation을 수치적으로 풀기 위해 Bodunov-Galerkin method를 사용한다. Solution function space의 기저 함수로 shape function을 사용하면 solution과 weight vector를 각 각 $\mathbf d = \mathbf{N\hat{d}}, \mathbf w = \mathbf{N} \boldsymbol{\delta}$ 표현할 수 있고 문제가 다음과 같이 간단해진다.
$$ \begin{equation} \text{find} \enspace \hat {\mathbf d} \in \R^{3n} \quad s.t. \quad \forall \boldsymbol \delta \in \R^{3n}, \quad \int_{\Omega} \mathbf C \mathbf B \hat {\mathbf d} \cdot \mathbf B \boldsymbol \delta dV = \int _{\partial\Omega} \mathbf t \cdot \mathbf{N} \boldsymbol{\delta} dS + \int _{\Omega} \mathbf f \cdot \mathbf{N} \boldsymbol{\delta} dV \end{equation} $$

위 식을 다음과 같이 정리할 수 있다.
$$ \begin{aligned} & \int_{\Omega} \mathbf C \mathbf B \hat {\mathbf d} \cdot \mathbf B \boldsymbol \delta dV = \int _{\partial\Omega} \mathbf t \cdot \mathbf{N} \boldsymbol{\delta} dS + \int _{\Omega} \mathbf f \cdot \mathbf{N} \\ \Leftrightarrow \enspace &  \boldsymbol \delta^T \left( \left( \int_{\Omega} \mathbf B^T \mathbf C \mathbf B \thinspace dV \right) \hat {\mathbf d} - \int _{\partial\Omega} \mathbf N^T \mathbf t \thinspace dS - \int _{\Omega} \mathbf N^T \mathbf f \thinspace dV \right) = 0 \end{aligned} $$

임의의 $\boldsymbol \delta$에 대해서 위 식이 성립해야 됨으로 문제가 다음과 같이 간단해진다.
$$ \text{find} \enspace \hat {\mathbf d} \in \R^{3n} \quad s.t. \quad \mathbf K \hat {\mathbf d} = \mathbf f  $$
$$ \text{Where, } \mathbf K = \int_{\Omega} \mathbf B^T \mathbf C \mathbf B \thinspace dV, \enspace \mathbf f = \int _{\partial\Omega} \mathbf N^T \mathbf t \thinspace dS + \int _{\Omega} \mathbf N^T \mathbf f \thinspace dV $$

이 방법은 `가상 일 원리(principle of virtual work)`라고도 한다. $\bf w$를 `가상 변위(virtual displacement)` $\delta \mathbf d$로 보면 식(2)는 다음과 같다.
$$ \text{find} \enspace \mathbf d \in (\mathcal D_W)^3 \quad s.t. \quad \forall \mathbf \delta \mathbf d \in \mathcal W^3, \quad \int_{\Omega} \boldsymbol\sigma \cdot \delta \boldsymbol{\epsilon} dV = \int _{\partial\Omega} \mathbf t \cdot \delta \mathbf d dS + \int _{\Omega} \mathbf f \cdot \delta \mathbf d dV $$

좌측항은 물리적으로 `내부 가상 일(internal virtual work)`, 우측항은 `외부 가상 일(external virtual work)`로 볼 수 있기 때문에 가상 일 원리라고 한다.


---



결론적으로 유도된 weak formulation은 다음과 같다.
$$ \begin{equation} \text{find} \enspace \mathbf d \in (\mathcal D_W)^3 \quad s.t. \quad \forall \mathbf w \in \mathcal W^3, \quad \int_{\Omega} \boldsymbol\sigma_v \cdot \delta \mathbf w dV = \int _{\partial\Omega} \mathbf t \cdot \mathbf w dS + \int _{\Omega} \mathbf {f \cdot w} dV \end{equation} $$
$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ w \in C^\infty(\Omega) \enspace | \enspace \forall \mathbf x \in \partial\Omega_E, \quad w(\mathbf x) = 0 \ \end{aligned}  $$

