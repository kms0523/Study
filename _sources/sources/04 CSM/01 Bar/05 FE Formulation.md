# FE Formulation
## Finite Elements
$\Omega$의 subset collection $\Omega_E$를 다음과 같이 정의하자.

$$ \Omega_E := \Set{\Omega_i\subseteq\Omega | i \in [1,N_E]} $$

$\Omega_E$는 $\Omega$를 근사하기 위한 collection이다.

$$ \Omega \approx \bigcup \Omega_E $$

이 때, $\Omega_i \in \Omega_E$를 `요소(element)`라고 부르며 element는 다음 성질을 만족한다.

$$ \forall \Omega_i \in \Omega_E, \quad \Omega_i \neq \empty \\ \forall \Omega_j,\Omega_k \in \Omega_E, \quad \Omega_j \neq \Omega_k \implies \Omega_j \cap \Omega_k = \empty $$

### 참고
$\Omega = \bigcup\Omega_E$를 만족하면, $\Omega_E$는 $\Omega$의 `분할(partition)`이 된다.

## Weak Formulation on FEs
$\forall \Omega_i \in \Omega_E$에서 1D bar의 governing equation에 대한 weak formulation은 다음과 같다.

$$ \text{find } u \in \mathcal{U}_W \st \forall w \in \mathcal{W}, \quad \sum_{i=1}^{N_E}\int_{\Omega_i} EA\pdiff{u}{x}\pdiff{w}{x}\thinspace dV = fw(L) + \sum_{i=1}^{N_E}\int_{\Omega_i} p(x)w \thinspace dV $$

### Bodunov-Galerkin method




$$ \mathcal U_W := \Set{u \in C^1(\Omega) | u \text{ satisfies essential BC}} $$

$$ \mathcal{W} := \Set{w \in C^\infty(\Omega) | w = 0 \text{ on } \partial\Omega_E} $$