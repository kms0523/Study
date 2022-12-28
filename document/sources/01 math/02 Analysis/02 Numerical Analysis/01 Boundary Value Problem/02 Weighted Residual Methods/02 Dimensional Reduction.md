# Dimensional Reduction
무한차원 함수공간인 $C^\infty_c(\Omega)$에 있는 모든 함수에 대해 WRF를 만족하는 $u$를 무한차원 함수공간인 $\mathcal U$에서 찾는 일은 너무 어렵다.

따라서 test function space와 solution function space를 각 각 유한차원 함수 공간으로 축소하여 dimensional reduction된 WRF를 살펴보자.

## Test Function Space Reduction
유한차원 함수 공간 $\mathcal{W_f}$를 다음과 같이 정의하자.

$$ \mathcal{W_f} := \span(\set{w_1,\cdots,w_n}) $$

$\mathcal{W_f}$의 subspace $\mathcal{W_c}$를 다음과 같이 정의하자.

$$ \mathcal{W_c} := \Set{w \in \mathcal{W_f}| w =0 \text{ on } \partial\Omega } $$

그리고 $\R^n_c \subseteq \R^n$을 다음과 같이 정의하자.

$$ \R^n_c := \Set{x \in \R^n | x^iw_i = 0 \text{ on } \partial\Omega} $$

Test function space를 $\mathcal{W}_c$로 축소하면 weighted residual formulation은 다음과 같이 간단해 진다.

$$ \begin{aligned} & \text{find } u \in \mathcal U \st \forall w \in \mathcal W_c, \quad B_r(w,u) = l_r(w) \\ \iff \enspace & \text{find } u \in \mathcal U \st \forall x \in \R^n_c, \quad x^i B_r(w_i,u) = x^il_r(w_i)\end{aligned} $$

$\forall x \in \R^n_c$에서 성립해야 됨으로, 결론적으로 다음이 성립하면 된다.

$$ \text{find } u \in \mathcal U \st B_r(w_i,u) = l_r(w_i), \enspace i = 1, \cdots, n $$

Test function space을 $\mathcal W_c$로 축소함으로써 $n$개의 `기저함수(basis function)`에 대해서만 확인하면 되는 문제로 단순화 하였지만 아직 무한차원 함수공간인 $\cal U$를 탐색해야 되는 어려움이 남아있다. 

이를 해결하기 위해 solution function space도 축소해보자.

## Solution Function Space Reduction
유한차원 함수 공간 $\mathcal{U_f}$를 다음과 같이 정의하자.

$$ \mathcal{U_f} := \span(\set{u_1,\cdots,u_n}) $$

$\mathcal{U_f}$의 subset $\mathcal{U_{b}}$를 다음과 같이 정의하자.

$$ \mathcal{U_b} := \Set{ u\in\mathcal{U_f}| u \text{ satisfies BC}} $$

그러면 $\mathcal{U_b}$의 정의에 의해 다음이 성립한다.

$$ \mathcal{U_b} \subseteq \mathcal{U} $$

이 때, $\mathcal{U}$를 $\mathcal{U_b}$로 축소하자. 

### Restriction
$\R^n_b \subseteq \R^n$을 다음과 같이 정의하자

$$ \R^n_b := \Set{x \in \R^n | x^iu_i \text{ satisfy BC}} $$

그러면 weighted residual formulation은 다음과 같이 간단해 진다.

$$ \begin{aligned} & \text{find } u \in \mathcal U_b \st B_r(w_i,u) = l_r(w_i), \enspace i = 1,\cdots,n \\ \iff \enspace & \text{find } x \in \R_b^n \st B_r(w_i,a_j u_j) = l_r(w_i), \enspace i = 1,\cdots,n \end{aligned} $$

### Affine space
$\mathcal{U_f}$의 subspace $\mathcal{U_0}$를 다음과 같이 정의하자.

$$ \mathcal{U_0} := \Set{ u\in\mathcal{U_f}| u=0 \text{ on } \partial\Omega} $$

$\phi \in \mathcal{U_b}$라 할 때, 다음이 성립한다.

$$ \forall u \in \mathcal{U_b}, \quad \exist u_0 \in \mathcal{U_0} \st u = \phi + \mathcal{u_0} $$

$\mathcal{U_0}$의 basis를 $\Set{u^0_i}$라고 하면 weighted residual formulation은 다음과 같이 간단해 진다.

$$ \begin{aligned} & \text{find } u \in \mathcal U_b \st B_r(w_i,u) = l_r(w_i), \enspace i = 1,\cdots,n \\ \iff \enspace & \text{find } x \in \R^n \st B_r(w_i,\phi + x^ju^0_j) = l_r(w_i), \enspace i = 1,\cdots,n \end{aligned} $$

> Reference  
> [Note - M. J. Zahr](https://mjzahr.github.io/content/ame40541/spr20/ch03-wres-solo.pdf)

## Final form
따라서, weighted residual formulation의 최종 형태는 다음과 같다.

$$ \text{find } x \in \R^n \st B_r(w_i,\phi + x^ju^0_j) = l_r(w_i), \enspace i = 1,\cdots,n $$

## 참고
주의할 점은 탐색하는 function space를 축소하였기 때문에 dimensional reduction된 WRF는 더이상 strong formulation과 동치가 아니다.

따라서, $\mathcal W_c$공간 안에서 dimensional reduction된 WRF를 만족하는 해도 strong formulation의 solution이 아닐 수 있다.

dimensional reduction된 WRF의 해는 strong formulation의 approximated solution이다