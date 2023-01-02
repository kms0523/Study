# Weak Formulation
## Weighted Residual Formulation
Bar의 weighted residual formlation은 다음과 같다.

$$ \text{find } u \in \mathcal{U} \st \forall w \in C^\infty_0(\Omega), \quad \int_\Omega \left( \frac{\partial}{\partial x}\left(EA\pdiff{u}{x}\right) + p(x) \right) w \thinspace dV = 0 $$

## Relaxation
Bar의 weighted residual formlation의 첫번째 항에 부분적분법을 적용하면 다음과 같다.

$$ \text{find } u \in \mathcal{U} \st \forall w \in C^\infty_0(\Omega), \quad EA\pdiff{u}{x}w\bigg|_{\partial\Omega} - \int_\Omega EA\pdiff{u}{x}\pdiff{w}{x}\thinspace dV + \int_\Omega p(x)w \thinspace dV = 0 $$

Natural BC를 적용하면 다음과 같다.

$$ \text{find } u \in \mathcal{U} \st \forall w \in C^\infty_0(\Omega), \quad \int_\Omega EA\pdiff{u}{x}\pdiff{w}{x}\thinspace dV = fw(L) -EA\pdiff{u}{x}w\bigg|_{x = 0} + \int_\Omega p(x)w \thinspace dV $$

Natural BC가 적용되기 위해서 test function space를 $\mathcal{W}$로 확장한다.

$$ \mathcal{W} := \Set{w \in C^\infty(\Omega) | w = 0 \text{ on } \partial\Omega_E} $$

그리고 부분적분법에 의해서 미분항이 test function으로옮겨가고 natural BC가 문제에 적용되어 있음으로 solution function space 또한 $\mathcal U_W$로 확장한다.

$$ \mathcal U_W := \Set{u \in C^1(\Omega) | u \text{ satisfies essential BC}} $$


## Weak Form
확장된 function space를 적용하면 다음과 같다.

$$ \text{find } u \in \mathcal{U}_W \st \forall w \in \mathcal{W}, \quad \int_\Omega EA\pdiff{u}{x}\pdiff{w}{x}\thinspace dV = fw(L) -EA\pdiff{u}{x}w\bigg|_{x = 0} + \int_\Omega p(x)w \thinspace dV $$

이 때, test function space가 $\partial\Omega_E$에서 항상 $0$임으로 최종 weak formulation은 다음과 같다.

$$ \text{find } u \in \mathcal{U}_W \st \forall w \in \mathcal{W}, \quad \int_\Omega EA\pdiff{u}{x}\pdiff{w}{x}\thinspace dV = fw(L) + \int_\Omega p(x)w \thinspace dV $$
