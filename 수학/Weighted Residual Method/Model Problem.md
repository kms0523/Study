# 1
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} + u -1 = 0 \quad \text{in} \enspace \Omega := [0,1] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 1 \enspace \land \enspace u'(1) = 1 \} $$

## Weak formulation
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,u) = l(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } B : \mathcal W \times \mathcal U_W \rightarrow \R \quad s.t. \quad (w,u) \mapsto \int_\Omega \frac{dw}{dx}\frac{du}{dx} - w(u-1) \thinspace dV \\ l : \mathcal W \rightarrow \R \quad s.t. \quad w \mapsto w(1) \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 1 \} \\ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace w(0) = 0 \} \end{gathered} $$

$\mathcal U_W$는 $\mathcal U_s$에서 regularity를 약화시키고, natural BC가 equation에 impose 되어 있음으로 natural BC 조건을 배제한 공간이다.

$\mathcal W$는 $C^\infty_c(\Omega)$에서 natural BC를 식에 impose 시키기 위해서 natural BC에서는 0이 되지 않게 조건을 완화한 공간이다.

## Ritz method
test function space $\mathcal W$는 $n$차원 vector space $\mathcal W_h$로 축소하고 solution function space $\mathcal U_W$는 $n$차원 affine space $\mathcal U_{W_h}$로 축소한다.

$\mathcal U_{W_h}$의 associated vector space $\mathcal U_{L_h}$의 기저는 $\mu = \{ \mu_1, \cdots, \mu_n \}$이고 $\phi \in \mathcal U_W$ 일 때, Bodunov-Galerkin method를 적용하면 식(12)는 다음과 같이 간단해진다.
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(\mu_i, \phi + a_j \mu_j) = l(\mu_i) \quad i = 1, \cdots, n $$

이 때, $n=1, \phi = 1$로 두고 $\mu_1 = x - 2$이라하면 다음이 성립한다.
$$ u \in \mathcal U_{W_h} \Rightarrow u = \phi + a_1u_1 $$

$$ \text{find } a \in \R \quad s.t. \quad \int_\Omega \frac{d}{dx}(\phi + a_1u_1)\frac{du_1}{dx} \thinspace dV + u_1(0) = 0 $$


$$ \text{find } a \in \R \quad s.t. \quad a_1\int_\Omega \frac{du_1}{dx}\frac{du_1}{dx} \thinspace dV = - u_1(0) - \frac{d\phi}{dx} $$

이 때, 주의할 점은 $\mathcal U_{L_h}$는 $\partial\Omega_E$에서 homogeneous인 함수를 모아 놓은 vector space이다. 즉, 이 문제에서는 $u(2) = 1$을 만족하는 함수를 모아 놓은 vector space임으로 

## FEM method
$$ u \in \mathcal U_{W_h} \Rightarrow u = b_1n_1 + b_2n_2 $$