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

따라서, 위 식은 적분형 운동방정식과 동일하며 이를 미분형 운동방정식이라 한다.$\quad\tiny\blacksquare$

#### 따름명제1.1
연속체 $\Omega$가 정적 평형상태에 있다고 하자.

$\rho u, \sigma$가 충분히 매끄럽다고 할 때, 다음을 증명하여라.
$$ \begin{aligned} & \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho f_b \thinspace dV = 0 \\ \Leftrightarrow \enspace & \mathrm{div}(\boldsymbol\sigma) + \rho  f_b = 0 \end{aligned}  $$

**Proof**

명제1과 동일한 방법으로 증명할 수 있다. $\quad\tiny\blacksquare$


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

### 참고1(Principle of Virtual Displacement)
Weak formulation의 test function $w$를 `가상 변위(virtual displacement)` $\delta$로 보면 다음이 성립한다.
$$ \text{find} \enspace d \in (\mathcal D_W)^3 \quad s.t. \quad \forall \delta \in \mathcal W^3, \quad \int_{\Omega} \sigma(d) : \text{grad}(\delta) \thinspace  dV = \int_{\partial\Omega} t \cdot  \delta \thinspace dS + \int _{\Omega} \rho f_b \cdot \delta \thinspace dV $$

$$ \begin{aligned} \text{Where, } \mathcal{D}_W &:= \{ d_i \in C^1(\Omega) \enspace | \enspace d_i \text{ satisfies boundary condition on } \partial\Omega_E \}  \\ \mathcal W &:= \{ \delta_i \in C^\infty(\Omega) \enspace | \enspace \forall  x \in \partial\Omega_E, \quad \delta_i( x) = 0 \} \end{aligned} $$

이 떄, $\delta(\delta  d)$를 변형률로써 해석하면, 좌측항은 물리적으로 `내부 가상 일(internal virtual work)`, 우측항은 `외부 가상 일(external virtual work)`로 볼 수 있기 때문에 가상 일 원리라고 한다.

> Reference  
> [Book] (Bathe) Finite Element Procedures p.156

### 명제1
$\sigma, w$가 충분히 매끄러울 때, 다음을 증명하여라.
$$ \int_{\Omega} \text{div}(\sigma) \cdot w \thinspace dV = \int _{\partial\Omega} t \cdot  w dS - \int_{\Omega} \sigma : \text{grad}(w) dV$$

**Proof**

Divergence theorem에 의해 다음이 성립한다.
$$ \begin{aligned} \int_{\Omega} \text{div}(\sigma) \cdot w \thinspace dV &=  \int_{\Omega} \mathrm{div}(w^T \sigma) - \sigma : \text{grad}(w) \thinspace dV \\&= \int _{\partial\Omega} w^T \sigma n dS - \int_{\Omega} \sigma : \text{grad}(w) dV \\&= \int _{\partial\Omega} t \cdot  w dS - \int_{\Omega} \sigma : \text{grad}(w) dV \end{aligned} $$