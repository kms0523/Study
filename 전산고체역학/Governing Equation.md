# 연속체의 지배 방정식
## 운동 상태
운동하는 연속체에 Euler의 운동방정식과 Euler-Cauchy stress principle을 적용하면 다음과 같다.
$$ \int_{\partial\Omega} \boldsymbol{\sigma}\mathbf n \thinspace dS + \int_\Omega \rho \mathbf f_b \thinspace dV = \frac{d}{dt} \int_\Omega \rho\mathbf u \thinspace dV $$

$\boldsymbol{\sigma}$가 충분히 매끄러울 때, divergence theorem과 Reynolds transport theorem을 적용하여 유도한 미분형 지배방정식은 다음과 같다.
$$ \text{find} \enspace \mathbf d \in \mathcal D^3 \quad s.t. \quad \mathrm{div}(\boldsymbol\sigma) + \rho \mathbf f_b = \frac{\partial}{\partial t}(\rho \mathbf u) + \mathrm{div}(\rho \mathbf{u \otimes u}) $$
$$ \text{Where, } \mathcal{D} := \{ d_i \in C^2(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega\}  $$

## 정적 평형 상태
정적 평형 상태의 연속체에 Euler의 운동방정식과 Euler-Cauchy stress principle을 적용하면 다음과 같다.
$$ \int_{\partial\Omega} \boldsymbol{\sigma}\mathbf n \thinspace dS + \int_\Omega \rho \mathbf f_b \thinspace dV = 0 $$

여기서, $\mathbf f_b$는 단위 질량당 체적력을 의미한다.

$\boldsymbol{\sigma}$가 충분히 매끄러울 때, divergence theorem을 적용하여 유도한 미분형 지배방정식은 다음과 같다.
$$ \text{find} \enspace \mathbf d \in \mathcal D^3 \quad s.t. \quad \mathrm{div}(\boldsymbol\sigma) + \rho \mathbf f_b = 0 $$
$$ \text{Where, } \mathcal{D} := \{ d_i \in C^2(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega\}  $$

> Reference  
> 연속체 역학 정리.md

# 지배 방정식의 수치 방정식
## 평형 방정식
### Weak formulation
3개의 평형방정식의 주어진 식(1)을 equivalent한 weak formulation으로 바꾸기 위해 test vector function $\mathbf w$와 내적한뒤 다음과 같은 과정을 거친다.
$$ \begin{equation} \begin{gathered} \int_{\Omega} ( \mathrm{div}(\boldsymbol\sigma) + \mathbf {f ) \cdot w} dV  = 0. \\\\ \int_{\Omega} \mathrm{div}(\boldsymbol\sigma  \mathbf {w}) - \boldsymbol\sigma : \boldsymbol{\epsilon}  + \mathbf {f \cdot w} dV  = 0. \\\\ \int_{\Omega} \boldsymbol\sigma : \text{grad}(\mathbf w) dV = \int _{\partial\Omega} \boldsymbol\sigma  \mathbf {w \cdot n} dS + \int _{\Omega} \mathbf {f \cdot w} dV \\\\ \int_{\Omega} \boldsymbol\sigma : \text{grad}(\mathbf w) dV = \int _{\partial\Omega} \mathbf t \cdot \mathbf w dS + \int _{\Omega} \mathbf {f \cdot w} dV \end{gathered} \end{equation} $$

> Q. test vector function과 내적한 식의 해가 연립방정식의 해와 동일한가?

이 때, $\boldsymbol\sigma : \text{grad}(\mathbf w)$항은 $\boldsymbol{\sigma}$의 symmetry에 의해 다음과 같이 표현할 수 있다.
$$ \boldsymbol\sigma : \text{grad}(\mathbf w) = \boldsymbol\sigma_v \cdot \delta \mathbf w $$
$$ \text{Where, } \boldsymbol\sigma_v = \begin{bmatrix} \sigma_{11} \\ \sigma_{22} \\ \sigma_{33} \\ \sigma_{23} \\ \sigma_{13} \\ \sigma_{12} \end{bmatrix}, \enspace \delta \mathbf w = \begin{bmatrix} \frac{\partial w_1}{\partial x_1} \\ \frac{\partial w_2}{\partial x_2} \\ \frac{\partial w_3}{\partial x_3} \\ \frac{\partial w_2}{\partial x_3} + \frac{\partial w_3}{\partial x_2}  \\ \frac{\partial w_1}{\partial x_3} + \frac{\partial w_3}{\partial x_1} \\ \frac{\partial w_1}{\partial x_2} + \frac{\partial w_2}{\partial x_1} \end{bmatrix} $$

결론적으로 유도된 weak formulation은 다음과 같다.
$$ \begin{equation} \text{find} \enspace \mathbf d \in (\mathcal D_W)^3 \quad s.t. \quad \forall \mathbf w \in \mathcal W^3, \quad \int_{\Omega} \boldsymbol\sigma_v \cdot \delta \mathbf w dV = \int _{\partial\Omega} \mathbf t \cdot \mathbf w dS + \int _{\Omega} \mathbf {f \cdot w} dV \end{equation} $$
$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ w \in C^\infty(\Omega) \enspace | \enspace \forall \mathbf x \in \partial\Omega_E, \quad w(\mathbf x) = 0 \ \end{aligned}  $$

#### 참고
이 방법은 `가상 일 원리(principle of virtual work)`라고도 한다. $\bf w$를 `가상 변위(virtual displacement)` $\delta \mathbf d$로 보면 식(2)는 다음과 같다.
$$ \text{find} \enspace \mathbf d \in (\mathcal D_W)^3 \quad s.t. \quad \forall \mathbf \delta \mathbf d \in \mathcal W^3, \quad \int_{\Omega} \boldsymbol\sigma_v \cdot \delta(\delta \mathbf d) dV = \int _{\partial\Omega} \mathbf t \cdot \delta \mathbf d dS + \int _{\Omega} \mathbf f \cdot \delta \mathbf d dV $$

이 떄, $\delta(\delta \mathbf d)$를 변형률로써 해석하면, 좌측항은 물리적으로 `내부 가상 일(internal virtual work)`, 우측항은 `외부 가상 일(external virtual work)`로 볼 수 있기 때문에 가상 일 원리라고 한다.

> Reference  
> [note] (Abaqus) Equilibrium and virtual work  
> Weighted Residual Methods.md  

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