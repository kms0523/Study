# Weak Formulation
## Weighted Residual Formulation
Bar의 WRF은 다음과 같다.

$$ \text{find } u \in \mathcal{U} \st \forall w \in C^\infty_c(\Omega), \quad \int_\Omega \left( \frac{\partial}{\partial x}\left(EA\pdiff{u}{x}\right) + p(x) \right) w \thinspace dV = 0 $$

## Weak Formulation
Bar의 weak formulation은 다음과 같다.

$$ \text{find } u \in \mathcal{U_w} \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,u) = l(w) $$

$$ \begin{aligned} \text{Where, } B(w,u) &:= \int_\Omega \pdiff{w}{x}EA\pdiff{u}{x}\thinspace dV \\ l(w) &:= fw(L) + \int_\Omega pw \thinspace dV \end{aligned} $$

### Related Funtion Space
$$ \begin{gathered} \mathcal{W} := \Set{w \in C^\infty(\Omega) | w = 0 \text{ on } \partial\Omega_E} \\ \mathcal{U_w} := \Set{u \in C^1(\Omega) | u \text{ satisfies essential BC}} \end{gathered} $$

## Dimensional Reduced Weak Form
정의에 의해 $B$가 bilinear임으로 Bar의 dimensional reduction된 weak formulation은 다음과 같다.

$$ \text{find } x \in \R_b^n \st B_r(w_i,u_j) x^j = l_r(w_i), \enspace i = 1,\cdots,n $$

### Related function spaces
$$ \begin{gathered} \mathcal{W_f} := \span(\set{w_1,\cdots,w_n}) \\ \mathcal{U_f} := \span(\set{u_1,\cdots,u_n}) \subset C^1(\Omega))  \\ \R^n_b := \Set{a \in \R^n | a^iu_i \text{ satisfy essential BC}} \end{gathered} $$

### Matrix form
$$ \begin{bmatrix} B_r(w_1,u_1) & \cdots & B_r(w_1,u_n) \\ \vdots & \ddots & \vdots \\ B_r(w_n,u_1) & \cdots & B_r(w_n,u_n) \end{bmatrix} \begin{bmatrix} a^1 \\ \vdots \\ a^n \end{bmatrix} = \begin{bmatrix} l_r(w_1) \\ \vdots \\ l_r(w_n) \end{bmatrix} $$