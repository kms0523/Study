Weak formulation은 Weighted residumal formulation에서 integration part 혹은 divergence theorem을 통해 solution function에 있는 미분항을 test function으로 옮겨 solution function space의 regularity를 약화시키고, 문제에 주어진 natural BC를 식에 포함시킴으로 써 solution function space가 더이상 natural BC를 만족시킬 필요 없게 만듬으로써 더 많은 공간을 solution space로 포함 시킬 수 있게 해준다.

Weak formulation을 다음 예제를 통해 구체적으로 알아보자.

# Strong formulation

`경계값 문제(boudnary value problem)`가 $\Omega := [0,L] \subset \R$위에서 다음과 같이 주어졌다고 해보자.  
$$ \begin{equation} \text{find } u \in \mathcal U \quad s.t. \quad -\frac{d}{dx}(a\frac{du}{dx}) + cu -f = 0 \end{equation} $$

$$ \text{Where, } \mathcal U := \left\{ u \in C^2(\Omega) \enspace \bigg| \enspace u(0) = u_0 \land \left( a\frac{du}{dx} \right)_{x=L} = Q_L \right\} $$

이 때, 함수 $a,c,f : \Omega \rightarrow \R$와 $u_0, Q_L \in \R$은 주어졌다고 하자.

# Weighted residual formulation
식(1)의 weighted residual formulation은 다음과 같다.  
$$ \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in \mathcal W, \quad \int_\Omega -w\frac{d}{dx}(a\frac{du}{dx}) \thinspace dV + \int_\Omega wcu \thinspace dV = \int_\Omega wf \thinspace dV $$

$$ \text{Where, } C^\infty_c(\Omega) \subseteq \mathcal W $$

# Weak formulation
Weighted residual formulation의 왼쪽 첫번째 항에 부분적분법을 적용하면 다음과 같다.  
$$ \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in \mathcal W, \quad \int_\Omega a\frac{dw}{dx}\frac{du}{dx} + wcu \thinspace dV = wa\frac{du}{dx} \bigg|_{x = 0}^L + \int_\Omega wf \thinspace dV $$

Natural BC를 적용하면 다음과 같다.  
$$ \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in \mathcal W, \quad \int_\Omega a\frac{dw}{dx}\frac{du}{dx} + wcu \thinspace dV = w(L)Q_L - wa\frac{du}{dx} \bigg|_{x = 0} + \int_\Omega wf \thinspace dV  $$

여기서 주목할 점은, $\forall w \in \mathcal W$에서 $w(L)$이 항상 0으로 가면 natural BC를 적용할 수 없게 된다. 따라서, 다음이 성립해야 한다.
$$\exist w \in \mathcal W \quad s.t. \quad w(L) \neq 0$$

부분 적분법에 의해 미분항이 $w$로 옮겨갔음으로 solution을 $C^2(\Omega)$가 아닌 $C^1(\Omega)$에서 찾을 수 있다. 

또한, natural BC를 포함함으로써 natural BC가 약하게 적용되어 있음으로, solution function space에서 강하게 natural BC를 적용할 필요가 없다. (약하게 적용 => 예제 참고)

Solution function space의 요구조건을 완화해서 $\mathcal U$를 확장하면 다음과 같다.
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad \int_\Omega a\frac{dw}{dx}\frac{du}{dx} + wcu \thinspace dV = w(L)Q_L - wa\frac{du}{dx} \bigg|_{x = 0} + \int_\Omega wf \thinspace dV \end{equation}$$

$$ \text{Where, } \mathcal U_W := \left\{ u \in C^1(\Omega) \enspace \bigg| \enspace u(0) = u_0 \right\} $$

$\mathcal U_W$는 $\mathcal U$보다 더 약한 regularity를 요구하기 때문에 식(3)이 식(2)보다 더 일반적인 형태이다. weak formulation이라고 불리는 이유는 바로 solution space의 regularity 요구사항을 약화시켰기 때문이다. $u \notin C^2(\Omega)$이면 strong formulation이 정의조차 되지 않기 때문에 식(3)는 더이상 strong formulation과 동치가 아니다.

Weak formulation은 functional $B_W,l_W$을 이용해 다음과 같이 간단하게 나타낼 수 있다.

$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B_W(w,u) = l_W(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } B_W(w,u) :=  \int_\Omega a\frac{dw}{dx}\frac{du}{dx} + wcu \thinspace dV \\ \quad l_W(w) := w(L)Q_L - wa\frac{du}{dx} \bigg|_{x = 0} + \int_\Omega wf \thinspace dV \end{gathered} $$

이 때, linear PDE임으로 $B_W$은 bilinear map이며, $l_W$은 linear map이다.

여기서 주의할 점은 $l_W$에 있는 $\frac{du}{dx}$가 포함된 항은 boundary에서의 값으로 approximate 해야되는 solution이 아니라 주어진 값이며, 이 주어진 값을 만족하도록 solution을 approximate 해야되는 것이다. 

> Q. $w$가 natural BC에서 0이되는 녀석이라면?

## Dimensional Reduction
무한차원 함수공간인 $\mathcal W$에 있는 모든 함수에 대해 식(4)를 만족하는 $u$를 무한차원 함수공간인 $\mathcal U_W$에서 찾는 일은 너무 어렵다.

따라서 test function space와 solution function space를 각 각 유한차원 함수 공간으로 축소하여 문제를 단순화해보자.

Weighted Residual formulation을 dimensional reduction했을 때와 동일한 과정을 거치면 식(4)는 다음과 같이 식이 간단해 진다.
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B_W(w_i, \mu_j) a_j = l_W(w_i), \enspace i = 1, \cdots, n  $$

이를 행렬 형태로 나타내면 다음과 같다.
$$ \begin{bmatrix} B_W(w_1,\mu_1) & \cdots & B_W(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B_W(w_n,\mu_1) & \cdots & B_W(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l_W(w_1) \\ \vdots \\ l_W(w_n) \end{bmatrix} $$

이 때, 주의할 점은 boundary value problem이기 때문에, 축소된 solution space $\mathcal U_h$안에 Essential BC를 만족하는 해가 반드시 존재해야한다.

이제 중요한 것은 $\mathcal W_h$와 $\mathcal U_h$를 어떻게 결정하는지이다.

## Petrov-Galerkin method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_n \}$를 독립적으로 정의하는 방법을 `Petrov-Galerkin method`라고 한다.

## Bubnov-Galerkin method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ \mu_1, \cdots, \mu_n \}$를 동일하게 정의하는 방법을 `Bubnov-Galerkin method`라고 한다.  
$$ w_i = \mu_i $$

# Model Problem 1
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} = 0 \quad \text{in} \enspace \Omega := [0,2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u'(0) = 1 \enspace \land \enspace u(2) = 1 \} $$

exact solution은 $u = x - 1$이다.

> 참고  
> [book] (Kelly) An Introduction to the FEM chapter 2.3.1

## Weak formulation
$$ \begin{bmatrix} B_W(w_1,\mu_1) & \cdots & B_W(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B_W(w_n,\mu_1) & \cdots & B_W(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l_W(w_1) \\ \vdots \\ l_W(w_n) \end{bmatrix} $$

$$ \begin{gathered} \text{Where, } B(w,u) := \int_\Omega \frac{dw}{dx}\frac{du}{dx} \thinspace dV, \quad  l(w) := w\frac{du}{dx} \bigg |^{2}_{x=0} \end{gathered} $$

#### approximation 1
$u_h =a_i\mu_i$라 하자.

$n = 2, \enspace \mu_i = w_i = x^{i-1}$이면 행렬 방정식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} u'(2) - 1 \\ 2u'(2) \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 + 2a_2 = 1 $$


$$ u_h = x - 1 $$

#### approximation2
$u_h =a_i\mu_i$라 하자.

$n = 2, \enspace \mu_i = x^{i-1}, w_i = x^i$이면 행렬 방정식은 다음과 같다.
$$ \begin{bmatrix} 0 & 2 \\ 0 & 4 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 2u'(2) \\ 4u'(2) \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 + 2a_2 = 1 $$

이 경우에는, test funtion space가 natural BC가 적용된 boundary에서 전부 0이 된다. 즉, natrual BC가 반영되지 않아 natural BC로부터 유의미한 식이 유도되지 않게 된다. 따라서 미지수를 구하기 위한 식이 부족하다.

natural BC가 반영되도록, $w_i = (x + 1)^i$로 바꾸면 행렬 방정식은 다음과 같다.
$$ \begin{bmatrix} 0 & 2 \\ 0 & 8 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 3u'(2) - 1 \\ 9u'(2) - 1 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 + 2a_2 = 1 $$

$$ u_h = x - 1 $$

# Model Problem2
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} + 1 = 0 \quad \text{in} \enspace \Omega := [0,2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 1 \enspace \land \enspace u'(2) = 1 \} $$

exact solution은 $u = 1 + 3x - 0.5x^2$이다.

> 참고  
> [book] (Kelly) An Introduction to the FEM chapter 2.3.2

## Weak formulation
$$ \begin{bmatrix} B_W(w_1,\mu_1) & \cdots & B_W(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B_W(w_n,\mu_1) & \cdots & B_W(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l_W(w_1) \\ \vdots \\ l_W(w_n) \end{bmatrix} $$

$$ \begin{gathered} \text{Where, } B(w,u) := \int_\Omega \frac{dw}{dx}\frac{du}{dx} \thinspace dV, \quad  l(w) := \int_\Omega w \thinspace dV + w\frac{du}{dx} \bigg |^{2}_{x=0} \end{gathered} $$

#### approximation1
$n = 2, \enspace \mu_i = w_i = x^{i-1}$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 3 - u'(0) \\ 4 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 = 1 $$
$$ u_h = 2x +1 $$

#### approximation2
$n = 2, \enspace \mu_i = x^{i-1}, \enspace w_i =x^i$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 2 \\ 0 & 4 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 4 \\ 20/3 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 = 1 $$

> Q. 언제 무의미한 식이 나오는가?  
> $u'(0)$도 변수로 봐야 한다!  
> BC도 포함한다.


#### Galerkin Method2
$n = 2, \enspace \mu_i = (x - 2)^{i-1}$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 3 - u'(0) \\ -2 +2u'(0) \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 - 2a_2 = 1 $$

$$ u_h = 2(x-2) + 5 = 2x + 1 $$

#### approx3
$n = 2, \enspace \mu_i = (x - 1)^{i-1}$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 3 - u'(0) \\ 1 + u'(0) \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 - a_2 = 1 $$

$$ u_h = 2(x-1) + 3 = 2x + 1 $$

# Model Problem3
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} -2\frac{du}{dx} + u - 1 = 0 \quad \text{in} \enspace \Omega := [0,1] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 1 \enspace \land \enspace u'(1) = 2 \} $$

exact solution은 $u = 1 + xe^{x-1}$이다.

> 참고  
> [book] (Kelly) An Introduction to the FEM chapter 2.3.1

## Weak formulation
$$ \begin{bmatrix} B_W(w_1,\mu_1) & \cdots & B_W(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B_W(w_n,\mu_1) & \cdots & B_W(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l_W(w_1) \\ \vdots \\ l_W(w_n) \end{bmatrix} $$

$$ \begin{gathered} \text{Where, } B(w,u) := \int_\Omega \frac{dw}{dx}\frac{du}{dx} + 2w\frac{du}{dx} -uw \thinspace dV, \quad  l(w) := w\frac{du}{dx} \bigg |^{1}_{x=0} - \int_\Omega w \thinspace dV \end{gathered} $$

test function space와 solution function space에 따라 다른 approximated solution이 나온다.
























# Ritz method
Ritz method는 weak formulation을 기반으로한 수치기법이다. Ritz method에서도 weight residual method에서 했던 방법과 동일하게 무한차원 test function space와 solution function space를 유한차원으로 축소한다.

먼저, test function space는 다음과 같이 축소한다.  
$$\mathcal W_h < \mathcal W$$

다음으로, solution function space 다음과 같이 축소한다.  
$$ \mathcal{U}_ h = \varphi + \mathcal{U}_{L_h} $$

$$ \begin{gathered} \text{Where, } \varphi \in \mathcal{U}_ W, \quad \mathcal{U}_ {L_h} < \mathcal{U}_ L \ \mathcal{U}_ L := \{ u \in C^r(\Omega) \enspace | \enspace u \text { satisfies homogeneous BC on } \partial\Omega_E \} \end{gathered} $$

이 때, 유한차원 function space $\mathcal{W}_ h, \mathcal{U}_ {L_h}$의 기저함수를 각각 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$라 하자.

Ritz method에서는 Bubnov-Galerkin method를 사용한다.  
$$ w_i = u_i $$

식(10)에 Ritz method를 적용하면 다음과 같다.  
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(u_i,\varphi + a_ju_j) = l(u_i) \quad \forall i \in \{ 1, \cdots, n \} $$

$B$가 bilinear이고 $l$이 linear인 경우 다음과 같이 간단해진다.  
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad \mathbf {Ka = f} $$

$$ \text{Where, } K_{ij} = B(u_i,u_j), \quad f_i = l(u_i) - B(u_i, \varphi) \quad \forall i \in \{ 1, \cdots, n \} $$


> 참고  
> [블로그](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=mykepzzang&logNo=221114379052)

---


이 때, test function space가 $C^\infty_c(\Omega)$임으로 $\partial\Omega$에서 $w=0$이다. 이로인해 natural BC를 식에 적용하는것이 불가능하다. 따라서 test function space를 essential BC가 적용되는 $\partial\Omega_E$에서만 0이 되는 함수공간 $\mathcal W$로 확장한다.  
$$ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace \forall \mathbf x \in \partial\Omega_E, \quad w(\mathbf x) = 0 \} $$

$C^\infty_c(\Omega) < \mathcal W$임으로 strong formulation과 동치관계를 유지하며 $\mathcal W$는 vector space다. $\mathcal W$는 현재 문제에서 다음과 같다.  
$$ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace w(0) = 0 \} $$

결론적으로 weak formulation은 다음과 같다.  
$$ \begin{equation} \begin{gathered} \text{find } u \in \mathcal U_w \quad s.t. \quad \forall w \in \mathcal W \ \int_\Omega \left( -\frac{dw}{dx}(a\frac{du}{dx}) + w(cu - f) \right) \thinspace dx - w(L)Q_L = 0 \end{gathered} \end{equation} $$

$$ \text{Where, } \mathcal U_w := \left\{ u \in C^2(\Omega) \enspace \bigg| \enspace u(0) = u_0 \right\} $$

weak formulation에 natural BC가 포함되어 있기 때문에 solution space를 더이상 natural BC를 만족하는 공간으로 제한할 필요가 없으며 $\mathcal U_s \subset \mathcal U_w$이다.

현재까지 충분한 regularity를 solution function space와 test function space에 부여한채로 strong form에서부터 weighted residual form, weak form을 유도하였기 때문에 현재 정규성 조건에서는 strong, weighted residual, weak formulation이 전부 동치이다.

하지만 식(9)을 보면 알 수 있듯이, weak formulation에서는 이러한 regularity를 약화시킬 수 있다. 즉, solution을 $C^2(\Omega)$가 아닌 $C^1(\Omega)$에서 찾을 수 있다는 것이다. 이렇게 regularity가 약화된 weak formulation은 다음과 같다.  
$$ \begin{equation} \begin{gathered} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W \ \int_\Omega \left( -\frac{dw}{dx}(a\frac{du}{dx}) + w(cu - f) \right) \thinspace dx - w(L)Q_L = 0 \end{gathered} \end{equation} $$

$$ \text{Where, } \mathcal U_W := \left\{ u \in C^1(\Omega) \enspace \bigg| \enspace u(0) = u_0 \right\} $$

식(10)는 식(9)보다 더 약한 regularity를 요구하기 때문에 더 일반적인 형태이다. weak formulation이라고 불리는 이유는 바로 solution space의 regularity 요구사항을 약화시켰기 때문이다. $u \notin C^2(\Omega)$이면 strong formulation이 정의조차 되지 않기 때문에 식(10)는 더이상 strong formulation과 동치가 아니다.

일반적으로 weak formulation은 functional $B,l$을 이용해 다음과 같이 간단하게 나타낼 수 있다.

$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,u) = l(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } B: \mathcal W \times \mathcal U_W \rightarrow \R \quad s.t. \quad (w,u) \mapsto  \int_\Omega -\frac{dw}{dx} \Big( a\frac{du}{dx} \Big) + wcu  \thinspace dx \\ \quad l: \mathcal W \rightarrow \R \quad s.t. \quad w \mapsto \int_\Omega wf \thinspace dx + w(L)Q_L \end{gathered} $$

이 떄, $\mathcal U_W$는 affine space이고 $\mathcal W$는 vector space이다.

linear PDE의 경우 식(11)을 bilinear form for linear PDEs라고 한다.