# Weak Formulation
Weak formulation은 WRF에서 integration part 혹은 divergence theorem을 통해 solution function에 있는 미분항을 test function으로 옮겨 solution function space의 regularity를 약화시키고, 문제에 주어진 natural BC를 식에 포함시킴으로 써 solution function space가 더이상 natural BC를 만족시킬 필요 없게 만듬으로써 더 많은 공간을 solution space로 포함 시킬 수 있게 해준다.

Weak formulation을 다음 예제를 통해 구체적으로 알아보자.

## Strong formulation

BVP가 $\Omega := [0,L] \subset \R$위에서 다음과 같이 주어졌다고 해보자.  

$$ \text{find } u \in \mathcal U \quad s.t. \quad -\frac{d}{dx}(a\frac{du}{dx}) + cu -f = 0 $$

$$ \text{Where, } \mathcal U := \Set{ u \in C^2(\Omega) | u \text{ satisfy BC} } $$


이 떄, BC는 다음과 같다.
$$ u(0) = u_0 \\ \left( a\frac{du}{dx} \right)_{x=L} = Q_L $$

함수 $a,c,f : \Omega \rightarrow \R$와 $u_0, Q_L \in \R$은 주어졌다고 하자.

## Weighted residual formulation
주어진 BVP의 WRF은 다음과 같다.  

$$ \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in C^\infty_c(\Omega), \quad \int_\Omega -w\frac{d}{dx}(a\frac{du}{dx}) \thinspace dV + \int_\Omega wcu \thinspace dV = \int_\Omega wf \thinspace dV $$

## Weak formulation
Weighted residual formulation의 왼쪽 첫번째 항에 부분적분법을 적용하면 다음과 같다.  

$$ \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in C^\infty_c(\Omega), \quad \int_\Omega a\frac{dw}{dx}\frac{du}{dx} + wcu \thinspace dV = wa\frac{du}{dx} \bigg|_{x = 0}^L + \int_\Omega wf \thinspace dV $$

Natural BC를 적용하면 다음과 같다.  

$$ \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in C^\infty_c(\Omega), \quad \int_\Omega a\frac{dw}{dx}\frac{du}{dx} + wcu \thinspace dV = w(L)Q_L - wa\frac{du}{dx} \bigg|_{x = 0} + \int_\Omega wf \thinspace dV  $$

### Test function space relaxation
Test funtion space를 살펴보자.

$\forall w \in C^\infty_c(\Omega)$에서 $w(L)$이 항상 0으로 감으로 natural BC를 적용할 수 없게 된다.

따라서, natural BC를 equation에 적용하기 위해서 natrual BC에서는 0이 아니고 essential BC에서만 0이 되게 test function space를 $\mathcal{W}$ 확장시켜줘야 한다. 

$$ \mathcal{W} := \Set{w \in C^\infty(\Omega) | w = 0 \text{ on } \partial\Omega_E} $$

확장된 후에도, 여전히 $C^\infty_c(\Omega) \subseteq \mathcal{W}$임으로 strong formulation과 동치이다.

### Solution function space relaxation
Solution function space를 살펴보자.

부분 적분법에 의해 미분항이 $w$로 옮겨갔음으로 solution을 $C^2(\Omega)$가 아닌 $C^1(\Omega)$에서 찾을 수 있다. 

또한, weak formulation에 natural BC가 적용되어 있음으로 solution function space에서 natural BC와 관련된 요구조건도 완화할 수 있다.

따라서, Solution function space의 요구조건을 완화해서 $\mathcal U$를 확장한 $\mathcal{U}_W$는 다음과 같다.

$$ \mathcal U_W := \Set{u \in C^1(\Omega) | u \text{ satisfies essential BC}} $$

### Weak form
Test function space와 solution function space를 relaxation하여 얻은 weak form은 다음과 같다.

$$ \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad \int_\Omega a\frac{dw}{dx}\frac{du}{dx} + wcu \thinspace dV = w(L)Q_L - wa\frac{du}{dx} \bigg|_{x = 0} + \int_\Omega wf \thinspace dV$$

#### 참고1
위 식이 weak formulation이라고 불리는 이유는 바로 test function space와 solution function space의 regularity 요구사항을 약화시켰기 때문이다. 

#### 참고2
$\mathcal U_W$는 $\mathcal U$보다 더 약한 regularity를 요구하기 때문에 strong formulation과 동치가 아니며 weak formulation이 보다 더 일반적인 형태이다. 

예를들어, weak formulation의 해가 $u \notin C^2(\Omega)$이면 strong formulation은 정의조차 되지 않는다.

> Reference  
> [Note - M. J. Zahr](https://mjzahr.github.io/content/ame40541/spr20/ch03-wres-solo.pdf)

#### 참고3
Solution function space에 natural BC를 적용할 경우 반드시 natural BC를 만족하는 해를 구하게 된다. 따라서 이를 강하게 natural BC를 적용하였다고 표현한다. 

하지만 weak formulation에서는 natural BC를 식에 적용하고 그 대신에 solution function space의 제약조건을 약화시켰기 때문에 약하게 적용되었다고 표현한다. 

#### 참고4
Weak formulation은 functional $B,l$을 이용해 다음과 같이 간단하게 나타낼 수 있다.

$$ \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,u) = l(w) $$

$$ \begin{gathered} \text{Where, } B(w,u) :=  \int_\Omega a\frac{dw}{dx}\frac{du}{dx} + wcu \thinspace dV + wa\frac{du}{dx} \bigg|_{x = 0} \\ \quad l(w) := w(L)Q_L + \int_\Omega wf \thinspace dV \end{gathered} $$

> Reference  
> [Note - M. J. Zahr](https://mjzahr.github.io/content/ame40541/spr20/ch03-wres-solo.pdf)

## Dimensional Reduction
무한차원 함수공간인 $\mathcal W$에 있는 모든 함수에 대해 weak formulation를 만족하는 $u$를 무한차원 함수공간인 $\mathcal U_W$에서 찾는 일은 너무 어렵다.

따라서 test function space와 solution function space를 각 각 유한차원 함수 공간으로 축소하여 문제를 단순화해보자.

Weighted Residual formulation을 dimensional reduction했을 때와 동일한 과정을 거치면, weak formulation는 다음과 같이 간단해 진다.

$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B_W(w_i, \phi + a_ju_j) = l_W(w_i), \enspace i = 1, \cdots, n , j=1,\cdots,k $$


$$ \begin{aligned} \text{Where, } &\phi \in \mathcal{U}_W \\ & u_j \text{ is basis of } \mathcal{U}_{W_L} := \{ u \in C^1(\Omega) \enspace | \enspace u = 0 \text{ on } \Omega_E \} \end{aligned}  $$

linear pde이기 때문에 이를 행렬 형태로 나타내면 다음과 같다.

$$ \begin{bmatrix} B_W(w_1,u_1) & \cdots & B_W(w_1,u_n) \\ \vdots & \ddots & \vdots \\ B_W(w_n,u_1) & \cdots & B_W(w_n,u_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l_W(w_1) - B(w_1, \phi) \\ \vdots \\ l_W(w_n) - B(w_n, \phi) \end{bmatrix} $$

이제 중요한 것은 $\mathcal W_h$와 $\mathcal U_h$를 어떻게 결정하는지이다.

> Reference  
> [Note - M. J. Zahr](https://mjzahr.github.io/content/ame40541/spr20/ch03-wres-solo.pdf)

### 참고
Dimensional reduction한 solution function space가 충분히 넓지 않은경우 weak formulation을 통해 구한 solution은 natural BC를 만족하지 않는다.

즉, 약하게 적영된 natural BC는 만족되지 않을 수도 있다.

그 예시는 model problem 4,8번을 통해 확인해 볼 수 있다.

## Petrov-Galerkin method
축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_n \}$를 독립적으로 정의하는 방법을 `Petrov-Galerkin method`라고 한다.

## Bubnov-Galerkin method
축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_n \}$를 동일하게 정의하는 방법을 `Bubnov-Galerkin method`라고 한다.  

$$ w_i = u_i $$
