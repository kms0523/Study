# 들어가며

[note] (M. J. Zahr) 3.Weighted residual methods를 기반으로 정리하였다.

# Strong formulation
`경계값 문제(boudnary value problem)`가 다음과 같이 주어졌다고 하자.  
$$ \begin{equation} \text{find } u \in \mathcal U \quad s.t. \quad \mathcal P(u) + f(\mathbf x) = 0 \quad \text{in } \Omega \subset \R^d \end{equation} $$

$$ \text{Where, } \mathcal U := \{ u \in C^m(\Omega) \enspace | \enspace u \text{ satisfies boundary condition on } \partial\Omega \} $$

이 때, $\mathcal P : C^m(\Omega) \rightarrow C^0(\Omega)$는 `계수(order)`가 $m$인 `미분 연산자(differential operator)`이며 $\mathcal U$는 `solution funtion space`이다.

`경계조건(boundary condition; BC)`은 $\partial\Omega_E \subset \partial\Omega$따라 essential BC와 $\partial\Omega_N \subset \partial\Omega$따라 natural BC가 주어져있으며 $\partial\Omega = \partial\Omega_E \cup \partial\Omega_N$ 이다.

식(1)을 PDE의 `strong formulation`이라 하는데 이는 strong formulation의 해가 $\Omega$의 모든 점에서 PDE를 만족시켜야하며 $m$번 미분 가능해야된다는 엄격한 `정규성(regularity)`을 만족시켜야하기 때문이다.

> 참고  
> [Function space - Wiki](https://en.wikipedia.org/wiki/Function_space#Functional_analysis)

# Weighted residual formulation
식(1)의 weighted residual formulation은 다음과 같이 주어진다.  
$$ \begin{equation} \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in  \mathcal W, \quad \int_\Omega w r \thinspace dV = 0 \end{equation} $$

$$ \text{Where, } C^\infty_c(\Omega) \subseteq \mathcal W, \quad  r(\mathbf x) = \mathcal P(u) + f(\mathbf x) $$

이 떄, $\mathcal W$는 `테스트 함수공간(test function space)`, $w$는 `테스트 함수(test function)`, $r$은 `residual`이라한다.

이를 weighted residual formulation이라고 부르는 이유는 식(2)가 residual의 가중평균이 0이 되는 것과 같은 형태를 가지고 있기 때문이다. 

그렇다고 식(2)의 해가 $r = 0$을 만족하는게 아니라 가중평균만 $0$으로 보낸다고 오해하면 안된다. 식(2)는 식(1)과 동치이며 이는 `변분법(variation calculus)`의 기본 보조정리에 의해 증명된다.

일반적으로 weighted residual formulation은 functional $B_r,l_r$을 이용해 다음과 같이 간단하게 나타낼 수 있다.

$$ \begin{equation} \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in \mathcal W, \quad B_r(w,u) = l_r(w) \end{equation} $$

$$ \text{Where, } B_r(w,u) :=  \int_\Omega \mathcal wP(u) \thinspace dV, \quad l_r(w) := -\int_\Omega wf \thinspace dV $$

이 때, $B_r$은 첫번째 원소에 대해서 linear map이며, $l_r$은 linear map이다.

만약, $\mathcal P$가 linear operator라면, $B_r$은 bilinear map이 된다.

## Dimensional Reduction
무한차원 함수공간인 $\mathcal W$에 있는 모든 함수에 대해 식(3)를 만족하는 $u$를 무한차원 함수공간인 $\mathcal U$에서 찾는 일은 너무 어렵다.

따라서 test function space와 solution function space를 각 각 유한차원 함수 공간으로 축소하여 문제를 단순화해보자.

먼저 test function space를 $\mathcal{W}_h := \text{span}(\{ w_1, \cdots, w_n \})$로 축소하면 식(3)은 다음과 같이 간단해 진다.
$$ \begin{equation} \begin{aligned} & \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in \mathcal W_h, \quad B_r(w,u) = l_r(w) \\ \Leftrightarrow \enspace & \text{find } u \in \mathcal U \quad s.t. \quad \forall c_i \in \R, \quad c_i B_r(w_i,u) = c_il_r(w_i) \\ \Leftrightarrow \enspace & \text{find } u \in \mathcal U \quad s.t. \quad B_r(w_i,u) = l_r(w_i), \enspace i = 1, \cdots, n \end{aligned} \end{equation} $$

다음으로, solution function space를 $\mathcal U_h := \text{span}(\{ \mu_1, \cdots, \mu_k \})$로 축소하면 식(4)는 다음과 같이 간단해 진다.
$$ \begin{equation} \begin{aligned} & \text{find } u \in \mathcal U_h \quad s.t. \quad B_r(w_i,u) = l_r(w_i), \enspace i = 1, \cdots, n \\ \Leftrightarrow \enspace & \text{find } \mathbf a \in \R^k \quad s.t. \quad B_r(w_i,a_j \mu_j) = l_r(w_i), \enspace i = 1, \cdots, n \end{aligned} \end{equation} $$

이 때, 주의할 점은 탐색하는 공간을 축소하였기 때문에 식(5)는 더 이상 식(1)과 동치가 아니다. 즉, $\mathcal W_h$공간 안에서 weighted residual formulation을 만족하는 해도 식(1)의 solution이 아니며 strong formulation의 approximated solution이 된다. 또한 boundary value problem이기 때문에, 축소된 solution space $\mathcal U_h$안에 BC를 만족하는 해가 반드시 존재해야한다. 

만약, $\mathcal P$가 linear operator면 $B_r$은 bilinear map이 되며 식(5)는 다음과 같이 단순해 진다.
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B_r(w_i, \mu_j) a_j = l_r(w_i), \enspace i = 1, \cdots, n  $$

이를 행렬 형태로 나타내면 다음과 같다.
$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) \\ \vdots \\ l(w_n) \end{bmatrix} $$

이제 중요한 것은 $\mathcal W_h$와 $\mathcal U_h$를 어떻게 결정하는지이다.

## Petrov-Galerkin method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_n \}$를 독립적으로 정의하는 방법을 `Petrov-Galerkin method`라고 한다.

결론적으로 Petrov-Galerkin method는 독립적으로 정의된 $\mathcal W_h$공간에서 weighted residual method를 만족하는 $u$를 $\mathcal U_h$ 공간에서 찾는 방법이다.

## Bubnov-Galerkin method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ \mu_1, \cdots, \mu_n \}$를 동일하게 정의하는 방법을 `Bubnov-Galerkin method`라고 한다.  
$$ w_i = \mu_i $$

식(5)에 Bubnov-Galerkin method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.
$$ \text{find } \mathbf a \in \mathcal \R^n \quad s.t. \quad \int_\Omega \mu_ir \thinspace dV = 0  $$

$$ \text{Where, } r = \mathcal P(a_j\mu_j) + f(\mathbf x) $$

즉, $r$이 모든 $\mu_i$와 내적이 0이 되게 하는 $\mathbf a$를 찾는 것임으로, 이렇게 찾은 solution $u$는 $r$을 solution function space에 orthogonal하게 만드는 solution이다.

## Least square method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 다음과 같이 정의된 값을 쓰는 방법을 `least square method`라고 한다.  
$$ w_i = \frac{\partial r}{\partial a_i}, \quad (i = 1, \cdots, n)$$

식(5)에 least square method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.
$$ \begin{aligned} & \text{find } \mathbf a \in \R^k \quad s.t. \quad \int_{\Omega_i} \frac{\partial r}{\partial a_i} r \thinspace dV = 0 \quad \forall i \in (1, \cdots, n) \\ \Leftrightarrow \enspace & \text{find } \mathbf a \in \R^k \quad s.t. \quad \frac{\partial}{\partial a_i} \int_{\Omega_i} r^2 \thinspace dV = 0 \quad \forall i \in (1, \cdots, n)\end{aligned} $$  

$$ \text{Where, } r = \mathcal P(a_j\mu_j) + f(\mathbf x) $$

즉, residual 제곱의 합이 최소가 되게 하는 $\mathbf a$을 찾는 것임으로 least square method라고 한다.

## Point collocation method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 Dirac-delta 함수를 사용하는 방법을 `point collocation method`라고 한다.  
$$ w_i = \delta(\mathbf x - \mathbf x_i) $$

식(5)에 point collocation method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.
$$ \text{find } \mathbf a \in \R^k \quad s.t. \quad \mathcal r(\mathbf x_i) = 0, \quad i = 1, \cdots, n $$

$$ \text{Where, } r = \mathcal P(a_j\mu_j) + f(\mathbf x) $$

Dirac-delta 함수의 성질에 의해 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 solution은 collocation node로 불리는 $\mathbf x_i$점에서 residual을 0으로 만드는 즉, strong formulation을 만족시키는 solution이다.

## Subdomain collocation method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 계단 함수를 사용하는 방법을 `subdomain collocation method`라고 한다.  
$$ w_i = \begin{cases} 1 & \text{if } \mathbf x_i \in \Omega_i \\ 0 & \text{else} \end{cases}$$

식(5)에 subdomain collocation method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.
$$ \text{find } \mathbf a \in \R^k \quad s.t. \int_{\Omega_i} r \thinspace dV = 0, \quad i = 1, \cdots, n $$

$$ \text{Where, } r = \mathcal P(a_j\mu_j) + f(\mathbf x) $$

계단 함수의 성질에 의해 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 solution은 $\Omega_i$에서 residaul의 평균을 0으로 만드는 solution이다.

---

식(5)는 $k$개의 미지수가 있음으로 이를 대수적으로 풀기 위해서는 $k$개의 독립적인 방정식이 필요하고 $k = n$이여야한다.

만약 $u_j$의 $m$계 도함수가 0이라면 $B(w_i,u_j) = 0$이 되고 행렬은 0으로만 이루어진 열을 갖는 singular matrix가 된다. 이는 기저 함수 $u_j$가 해를 근사하는데에 어떠한 기여도 하지 않는다는 것을 의미하며, 그로인해 $u_j$의 계수 $a_j$가 어떤 값을 갖더라도 같은 근사가 됨을 의미한다.

---



---








# Model Problem1
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d}{dx} \bigg( e^x \frac{du}{dx} \bigg) - \sin x  = 0 \quad \text{in} \enspace \Omega := [0,\pi / 2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 1 \enspace \land \enspace u'(\pi / 2) = 0 \} $$

exact solution은 $u = \frac{1}{2}(1 + e^{-x}(\cos x - \sin x))$이다.

> 참고  
> [note] (M. J. Zahr) 3.Weighted residual methods Exaxmple 3.2

## Weighted residual formulation
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = l(w)  $$

$$ \begin{gathered} \text{Where, } B(w,u) := \int_\Omega w e^x \bigg( \frac{du}{dx} + \frac{d^2u}{dx^2} \bigg) \thinspace dV \\ l(w) := \int_\Omega w\sin x\thinspace dV \end{gathered} $$

Boundary condition은 solution space를 통해 강하게 부여된다.

### Weighted residual method
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i, \phi + a_j\mu_j) = l(w_i) \enspace i = 1, \cdots, n $$

$$ \begin{gathered} \text{Where, } w_i \in C^\infty(\Omega), \quad \phi \in \mathcal U_s , \\ \mu_i \in \{ \mu \in C^2(\Omega) \enspace | \enspace u(0) = u'(\pi / 2) = 0 \} \end{gathered}  $$

$B$가 bi-linear 임으로
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,\mu_j) a_j = l(w_i) - B(w_i, \phi) \enspace i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) - B(w_1, \phi) \\ \vdots \\ l(w_n) - B(w_n, \phi) \end{bmatrix} $$

#### Galerkin method
$n=2$이고 $\phi = 1, \enspace \mu_1 = x^2 - \pi x, \enspace \mu_2 = x^3 - \frac{3\pi^2}{4}x$라 하자.

## Weak form
$$ \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = l(w) $$

$$ \begin{gathered} \text{Where, } B(w,u) := - e^x w \frac{du}{dx} \bigg |_{x = 0} - \int_\Omega e^x\frac{dw}{dx}\frac{du}{dx} \thinspace dV \\ l(w) := \int_\Omega w\sin x\thinspace dV \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 1 \} \end{gathered} $$

Boundary condition 중 natural BC는 weak form에 반영됨으로써 약하게 부여된다.

### method1
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i, \phi + a_j\mu_j) = l(w_i) \enspace i = 1, \cdots, n $$

$$ \begin{gathered} \text{Where, } w_i \in C^\infty(\Omega), \quad \phi \in \mathcal U_W , \\ \mu_i \in \{ \mu \in C^1(\Omega) \enspace | \enspace u(0) = 0 \} \end{gathered}  $$

essential BC를 만족하는 $\phi$와 $\Omega_E$에서 homogeneous를 만족하는 $\mu_i$로 solution space를 구성한다.

$B$가 bi-linear 임으로
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,\mu_j) a_j = l(w_i) - B(w_i, \phi) \enspace i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) - B(w_1, \phi) \\ \vdots \\ l(w_n) - B(w_n, \phi) \end{bmatrix} $$

#### Galerkin Method
$n=2, \enspace \phi=1, \enspace \mu_i = x^i$라 하자.

### method2
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad \hat{B}(w_i, \phi + a_j\mu_j) = l(w_i) \enspace i = 1, \cdots, n $$

$$ \begin{gathered} \text{Where, } \hat{B}(w,u) := - \int_\Omega e^x\frac{dw}{dx}\frac{du}{dx} \thinspace dV \\ w_i \in \{ w \in C^\infty(\Omega) \enspace | \enspace w(0) = 0 \}, \\ \phi \in \mathcal U_W , \\ \mu_i \in \{ \mu \in C^1(\Omega) \enspace | \enspace u(0) = 0 \} \end{gathered}  $$

$w_i$를 $\Omega_E$에서 0이 되게 결정함으로써, 식을 간단하게 할 수 있다.






# Model Problem2
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d}{dx} \bigg( e^x \frac{du}{dx} \bigg) - \sin x  = 0 \quad \text{in} \enspace \Omega := [0,\pi / 2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 1 \enspace \land \enspace u'(\pi / 2) = 1 \} $$

exact solution은 $u = \frac{1}{2}( e^{-x}( 2 + \cos x - \sin x) - 2)$이다.

> 참고  
> [note] (M. J. Zahr) 3.Weighted residual methods Exaxmple 3.2

## Weighted residual formulation
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = l(w)  $$

$$ \begin{gathered} \text{Where, } B(w,u) := \int_\Omega w e^x \bigg( \frac{du}{dx} + \frac{d^2u}{dx^2} \bigg) \thinspace dV \\ l(w) := \int_\Omega w\sin x\thinspace dV \end{gathered} $$

Boundary condition은 solution space를 통해 강하게 부여된다.

### Weighted residual method
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i, \phi + a_j\mu_j) = l(w_i) \enspace i = 1, \cdots, n $$

$$ \begin{gathered} \text{Where, } w_i \in C^\infty(\Omega), \quad \phi \in \mathcal U_s , \\ \mu_i \in \{ \mu \in C^2(\Omega) \enspace | \enspace u(0) = u'(\pi / 2) = 0 \} \end{gathered}  $$

$B$가 bi-linear 임으로
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,\mu_j) a_j = l(w_i) - B(w_i, \phi) \enspace i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) - B(w_1, \phi) \\ \vdots \\ l(w_n) - B(w_n, \phi) \end{bmatrix} $$

#### Galerkin method
$n=2$이고 $\phi = 1, \enspace \mu_1 = x^2 - \pi x, \enspace \mu_2 = x^3 - \frac{3\pi^2}{4}x$라 하자.

## Weak form
$$ \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = l(w) $$

$$ \begin{gathered} \text{Where, } B(w,u) := - e^x w \frac{du}{dx} \bigg |_{x = 0} - \int_\Omega e^x\frac{dw}{dx}\frac{du}{dx} \thinspace dV \\ l(w) := \int_\Omega w\sin x\thinspace dV \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 1 \} \end{gathered} $$

Boundary condition 중 natural BC는 weak form에 반영됨으로써 약하게 부여된다.

### method1
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i, \phi + a_j\mu_j) = l(w_i) \enspace i = 1, \cdots, n $$

$$ \begin{gathered} \text{Where, } w_i \in C^\infty(\Omega), \quad \phi \in \mathcal U_W , \\ \mu_i \in \{ \mu \in C^1(\Omega) \enspace | \enspace u(0) = 0 \} \end{gathered}  $$

$B$가 bi-linear 임으로
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,\mu_j) a_j = l(w_i) - B(w_i, \phi) \enspace i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) - B(w_1, \phi) \\ \vdots \\ l(w_n) - B(w_n, \phi) \end{bmatrix} $$

#### Galerkin Method
$n=2, \enspace \phi=1, \enspace \mu_i = x^i$라 하자.

# Model Problem3
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} = 0 \quad \text{in} \enspace \Omega := [0,2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u'(0) = 1 \enspace \land \enspace u(2) = 1 \} $$

exact solution은 $u = x - 1$이다.

> 참고  
> [book] (Kelly) An Introduction to the FEM chapter 2.3.1

## Weak formulation1
$$ \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = l(w) $$

$$ \begin{gathered} \text{Where, } \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(2) = 1 \} \\ B(w,u) := \int_\Omega \frac{dw}{dx}\frac{du}{dx} \thinspace dV, \quad  l(w) := w\frac{du}{dx} \bigg |^{2}_{x=0} \end{gathered} $$

### method3
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,  a_j\mu_j) = l(w_i) \enspace i = 1, \cdots, n $$

$B$가 bi-linear 임으로
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,\mu_j) a_j = l(w_i) \enspace i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) \\ \vdots \\ l(w_n) \end{bmatrix} $$

#### Galerkin Method1
$n = 2, \enspace \mu_i = x^{i-1}$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} u'(2) - 1 \\ 2u'(2) \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 + 2a_2 = 1 $$

#### Galerkin Method2
$n = 2, \enspace \mu_i = (x - 2)^{i-1}$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} - 2 \\ 2 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 = 1 $$

#### Galerkin Method3
$n=2, \mu_1 = 1, \mu_2 = x + 3$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} u'(2) - 1 \\ 5u'(2) - 3 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 + 5a_2 = 1 $$

## Weak formulation2
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,v) = l(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(2) = 1 \} \\ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace w(2) = 0 \} \\ B(w,u) := \int_\Omega \frac{du}{dx}\frac{dw}{dx} \thinspace dV, \quad l(w) := -w(0) \end{gathered} $$

### Ritz method
$B$가 bilinear 임으로
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(\mu_i,  \mu_j) a_j = l(\mu_i) \quad i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(\mu_1,\mu_1) & \cdots & B(\mu_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(\mu_n,\mu_1) & \cdots & B(\mu_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(\mu_1) \\ \vdots \\ l(\mu_n) \end{bmatrix} $$


#### approx1
$n=2, \mu_1 = 1, \mu_2 = x$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} -1 \\ 0 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 + 2a_2 = 1 $$

`이게 뭔가 이상하다!`

#### approx2
$\mu_1 = 1, \mu_2 = x - 2$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} -1 \\ 2 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 + 5a_2 = 1 $$

# Model Problem4
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} + 1 = 0 \quad \text{in} \enspace \Omega := [0,2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 1 \enspace \land \enspace u'(2) = 1 \} $$

exact solution은 $u = 1 + 3x - 0.5x^2$이다.

> 참고  
> [book] (Kelly) An Introduction to the FEM chapter 2.3.2

## Weak formulation1
$$ \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = l(w) $$

$$ \begin{gathered} \text{Where, } \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 1 \} \\ B(w,u) := \int_\Omega \frac{dw}{dx}\frac{du}{dx} \thinspace dV, \quad  l(w) := \int_\Omega w \thinspace dV + w\frac{du}{dx} \bigg |^{2}_{x=0} \end{gathered} $$

### method3
$B$가 bi-linear 임으로
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,\mu_j) a_j = l(w_i) \enspace i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) \\ \vdots \\ l(w_n) \end{bmatrix} $$

#### Galerkin Method1
$n = 2, \enspace \mu_i = x^{i-1}$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 3 - u'(0) \\ 4 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 = 1 $$
$$ u_h = 2x +1 $$

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

## Weak formulation2
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,v) = l(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 1 \} \\ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace w(0) = 0 \} \\ B(w,u) := \int_\Omega \frac{du}{dx}\frac{dw}{dx} \thinspace dV, \quad l(w) := \int_\Omega w \thinspace dV + w(2) \end{gathered} $$

### Ritz method
$B$가 bilinear 임으로
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(\mu_i,  \mu_j) a_j = l(\mu_i) \quad i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(\mu_1,\mu_1) & \cdots & B(\mu_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(\mu_n,\mu_1) & \cdots & B(\mu_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(\mu_1) \\ \vdots \\ l(\mu_n) \end{bmatrix} $$

#### approx1
$n=2, \mu_1 = 1, \mu_2 = x$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 3 \\ 4 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 = 1 $$
$$ u_h = 2x + 1 $$

#### approx2
$\mu_1 = 1, \mu_2 = x - 2$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 3 \\ -2 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 - 2 a_2 = 1 $$
$$ u_h = -(x-2) - 1 = -x +1 $$

#### approx3
$\mu_1 = 1, \mu_2 = x - 1$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 3 \\ 1 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 - a_2 = 1 $$
$$ u_h = 1/2(x-1) + 3/2 = 1/2x +1 $$

## Weighted residual formulation
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad \int_\Omega w \bigg( \frac{d^2u}{dx^2} + 1 \bigg) \thinspace dV = 0 $$

## Weak formulation
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = l(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } B : C^\infty \times \mathcal U_W \rightarrow \R \quad s.t. \quad (w,u) \mapsto \int_\Omega \frac{dw}{dx}\frac{du}{dx} \thinspace dV + w\frac{du}{dx} \bigg |_{x=0} \\ l : C^\infty \rightarrow \R \quad s.t. \quad w \mapsto w(2) + \int_\Omega w \thinspace dV \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 1 \} \end{gathered} $$

$\mathcal U_W$는 $\mathcal U_s$에서 regularity를 약화시키고, natural BC가 equation에 impose 되어 있음으로 natural BC 조건을 배제한 공간이다.

### Ritz method
$u \approx a_i\mu_i$이고 Bodunov-Galerkin method를 적용하고 행렬식으로 나타내면
$$ \begin{bmatrix} B(\mu_1,\mu_1) & \cdots & B(\mu_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(\mu_n,\mu_1) & \cdots & B(\mu_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(\mu_1) \\ \vdots \\ l(\mu_n) \end{bmatrix} $$

#### approx1
$\mu_1 = 1, \mu_2 = x$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & 1 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 3 \\ 6 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 = 1 $$

결과가 $u_h = 3x + 1$인데, 이러면 natural BC를 만족하지 않음...












# Model Problem4
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{du}{dx} - 2xu = 0 \quad \text{in} \enspace \Omega := [0,2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 2 \} $$

exact solution은 $u = 2e^{x^2}$이다.

## Weighted residual formulation
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = 0  $$

$$ \begin{gathered} \text{Where, } B(w,u) := \int_\Omega w \bigg( \frac{du}{dx} -2xu \bigg) \thinspace dV \end{gathered} $$

Boundary condition은 solution space를 통해 강하게 부여된다.

### Weighted residual method
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i, \phi + a_j\mu_j) = l(w_i) \enspace i = 1, \cdots, n $$

$$ \begin{gathered} \text{Where, }  w_i \in C^\infty(\Omega), \quad \phi \in \mathcal U_s , \\ \mu_i \in \{ \mu \in C^2(\Omega) \enspace | \enspace u(0) = 0 \} \end{gathered}  $$

$B$가 bi-linear 임으로
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,\mu_j) a_j = - B(w_i, \phi) \enspace i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} - B(w_1, \phi) \\ \vdots \\ - B(w_n, \phi) \end{bmatrix} $$

#### Galerkin method
$n = 1$이고 $\phi = 2, \enspace \mu_1 = x$라 하자.

$u_h = 2 + 16/9x$

## Weak formulation
$$ \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = 0  $$

$$ \begin{gathered} \text{Where, } \mathcal U_W := \{ u \in C^0(\Omega) \enspace | \enspace u(0) = 2 \} \\ B(w,u) := wu \Big|_0^2 - \int_\Omega \bigg( \frac{dw}{dx} -2xw \bigg) u \thinspace dV \end{gathered} $$

Boundary condition은 solution space를 통해 강하게 부여된다.

### Weak method
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i, \phi + a_j\mu_j) = 0, \enspace i = 1, \cdots, n $$

$$ \begin{gathered} \text{Where, } w_i \in C^\infty(\Omega), \quad \phi \in \mathcal U_W , \\ \mu_i \in \{ \mu \in C^0(\Omega) \enspace | \enspace u(0) = 0 \} \end{gathered}  $$

$B$가 bi-linear 임으로
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,\mu_j) a_j = - B(w_i, \phi) \enspace i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} - B(w_1, \phi) \\ \vdots \\ - B(w_n, \phi) \end{bmatrix} $$

#### Galerkin method
$n = 1$이고 $\phi = 2, \enspace \mu_1 = x$라 하자.

$a_1 = 16/9$




















































# Model Problem2
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} = 0 \quad \text{in} \enspace \Omega := [0,2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 0\enspace \land \enspace u(2) = 1 \} $$

exact solution은 $u=\frac{1}{2}x$이다.

## Weighted residual formulation
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad \int_\Omega w\frac{d^2u}{dx^2} \thinspace dV = 0 $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 0 \enspace \land \enspace u(2) = 1 \} $$

## Weak formulation1
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = 0 \end{equation} $$

$$ \begin{gathered} \text{Where, } B : C^\infty \times \mathcal U_W \rightarrow \R \quad s.t. \quad (w,u) \mapsto \int_\Omega \frac{du}{dx}\frac{dw}{dx} \thinspace dV - w\frac{du}{dx} \bigg |^{2}_{x=1}  \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 0 \enspace \land \enspace u(2) = 1 \} \end{gathered} $$

$\mathcal U_W$는 $\mathcal U_s$에서 regularity를 약화시키고, natural BC가 equation에 impose 되어 있음으로 natural BC 조건을 배제한 공간이다.

### Ritz method
$u \approx a_i\mu_i$이고 Bodunov-Galerkin method를 적용하면 
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(\mu_i, a_j \mu_j) = l(\mu_i) \quad i = 1, \cdots, n $$

$B$가 bilinear 임으로
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(\mu_i,  \mu_j) a_j = l(\mu_i) \quad i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(\mu_1,\mu_1) & \cdots & B(\mu_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(\mu_n,\mu_1) & \cdots & B(\mu_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(\mu_1) \\ \vdots \\ l(\mu_n) \end{bmatrix} $$


#### approx1
$\mu_1 = 1, \mu_2 = x$라 하자.

essential BC를 적용하면 다음과 같다.
$$ a_1 + 2a_2 = 1 $$

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & -1 \\ 0 & 0 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} -1 \\ 0 \end{bmatrix} $$

#### approx2
$\mu_1 = 1, \mu_2 = x + 3$라 하자.

essential BC를 적용하면 다음과 같다.
$$ a_1 + 5a_2 = 1 $$

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & -1 \\ 0 & -3 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} -1 \\ -3 \end{bmatrix} $$


# Model Problem3
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} + u - x = 0 \quad \text{in} \enspace \Omega := [0,2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 0 \enspace \land \enspace u(2) = 5 \} $$

exact solution은 $u = \frac{3}{\sin 2}\sin  x + x$이다.

## Weighted residual formulation
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad \int_\Omega w \bigg( \frac{d^2u}{dx^2} + u - x \bigg) \thinspace dV = 0 $$

## Weak formulation1
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = l(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } B : C^\infty \times \mathcal U_W \rightarrow \R \quad s.t. \quad (w,u) \mapsto \int_\Omega wu -\frac{dw}{dx}\frac{du}{dx} \thinspace dV + w\frac{du}{dx} \bigg |^{2}_{x=0} \\ l : \mathcal W \rightarrow \R \quad s.t. \quad w \mapsto \int wx \thinspace dV \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 0 \enspace \land \enspace u(2) = 5 \} \end{gathered} $$

$\mathcal U_W$는 $\mathcal U_s$에서 regularity를 약화시킨 공간이다.

### Ritz method
$u \approx a_i\mu_i$이고 Bodunov-Galerkin method를 적용한걸 행렬식으로 나타내면
$$ \begin{bmatrix} B(\mu_1,\mu_1) & \cdots & B(\mu_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(\mu_n,\mu_1) & \cdots & B(\mu_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(\mu_1) \\ \vdots \\ l(\mu_n) \end{bmatrix} $$

#### approx1
$\mu_1 = x, \mu_2 = x^2$라 하자.

essential BC를 적용하면 다음과 같다.
$$ 2a_1 + 4a_2 = 5 $$

행렬식은 다음과 같다.
$$ \begin{bmatrix} -4/3 & -8 \\ -4 & -104/15 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 8/3 \\ 4 \end{bmatrix} $$

## Weak formulation2
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,u) = 0 \end{equation} $$

$$ \begin{gathered} \text{Where, } B : C^\infty \times \mathcal U_W \rightarrow \R \quad s.t. \quad (w,u) \mapsto \int_\Omega \frac{du}{dx}\frac{dw}{dx} + w(u-x) \thinspace dV  \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 0 \enspace \land \enspace u(2) = 5 \} \\ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace w(0) = 0 \enspace \land \enspace w(2) = 0 \} \end{gathered} $$

$\mathcal U_W$는 $\mathcal U_s$에서 regularity를 약화시킨 공간이다.

### Ritz method
$u \approx a_i\mu_i$이고 Bodunov-Galerkin method를 적용하면 
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(\mu_i, a_j \mu_j) = l(\mu_i) \quad i = 1, \cdots, n $$

$B$가 bilinear 임으로
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(\mu_i,  \mu_j) a_j = l(\mu_i) \quad i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(\mu_1,\mu_1) & \cdots & B(\mu_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(\mu_n,\mu_1) & \cdots & B(\mu_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(\mu_1) \\ \vdots \\ l(\mu_n) \end{bmatrix} $$

#### approx1
$\mu_1 = x, \mu_2 = x^2$라 하자.

essential BC를 적용하면 다음과 같다.
$$ 2a_1 + 4a_2 = 5 $$

행렬식은 다음과 같다.
$$ \begin{bmatrix} 2 &  16/3 \\ 4 & 196/15 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \end{bmatrix} $$


# Model Problem4
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} - u - x = 0 \quad \text{in} \enspace \Omega := [0,1] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 0 \enspace \land \enspace u(1) = 0 \} $$

exact solution은 $u = x - \frac{\sinh x}{\sinh 1}$이다.

> 참고  
> [book] (Kelly) An Introduction to the FEM chapter1

## Weighted residual formulation
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad \int_\Omega w \bigg( \frac{d^2u}{dx^2} - u - x \bigg) \thinspace dV = 0 $$

## Weak formulation1
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = l(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } B : C^\infty \times \mathcal U_W \rightarrow \R \quad s.t. \quad (w,u) \mapsto \int_\Omega - wu -\frac{dw}{dx}\frac{du}{dx} \thinspace dV + w\frac{du}{dx} \bigg |^{2}_{x=0} \\ l : \mathcal W \rightarrow \R \quad s.t. \quad w \mapsto \int wx \thinspace dV \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 0 \enspace \land \enspace u(2) = 5 \} \end{gathered} $$

$\mathcal U_W$는 $\mathcal U_s$에서 regularity를 약화시킨 공간이다.

### Ritz method
$u \approx a_i\mu_i$이고 Bodunov-Galerkin method를 적용한걸 행렬식으로 나타내면
$$ \begin{bmatrix} B(\mu_1,\mu_1) & \cdots & B(\mu_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(\mu_n,\mu_1) & \cdots & B(\mu_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(\mu_1) \\ \vdots \\ l(\mu_n) \end{bmatrix} $$

#### approx1
$\mu_1 = x, \mu_2 = x^2$라 하자.

essential BC를 적용하면 다음과 같다.
$$ 2a_1 + 4a_2 = 5 $$

행렬식은 다음과 같다.
$$ \begin{bmatrix} -4/3 & -8 \\ -4 & -104/15 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 8/3 \\ 4 \end{bmatrix} $$

## Weak formulation2
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,u) = 0 \end{equation} $$

$$ \begin{gathered} \text{Where, } B : C^\infty \times \mathcal U_W \rightarrow \R \quad s.t. \quad (w,u) \mapsto \int_\Omega \frac{du}{dx}\frac{dw}{dx} + w(u-x) \thinspace dV  \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 0 \enspace \land \enspace u(2) = 5 \} \\ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace w(0) = 0 \enspace \land \enspace w(2) = 0 \} \end{gathered} $$

$\mathcal U_W$는 $\mathcal U_s$에서 regularity를 약화시킨 공간이다.

### Ritz method
$u \approx a_i\mu_i$이고 Bodunov-Galerkin method를 적용하면 
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(\mu_i, a_j \mu_j) = l(\mu_i) \quad i = 1, \cdots, n $$

$B$가 bilinear 임으로
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(\mu_i,  \mu_j) a_j = l(\mu_i) \quad i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(\mu_1,\mu_1) & \cdots & B(\mu_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(\mu_n,\mu_1) & \cdots & B(\mu_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(\mu_1) \\ \vdots \\ l(\mu_n) \end{bmatrix} $$

#### approx1
$\mu_1 = x, \mu_2 = x^2$라 하자.

essential BC를 적용하면 다음과 같다.
$$ 2a_1 + 4a_2 = 5 $$

행렬식은 다음과 같다.
$$ \begin{bmatrix} 2 &  16/3 \\ 4 & 196/15 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \end{bmatrix} $$

























---

test function space를 $\mathcal W_h$로 축소하면 식(3)은 다음과 같이 간단해 진다.  
$$ \begin{equation} \begin{aligned} & \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in \mathcal W_h, \quad B_r(w,u) = l_r(w) \\ \Leftrightarrow \enspace & \text{find } u \in \mathcal U \quad s.t. \quad \forall c_i \in \R, \quad c_i B_r(w_i,u) = c_il_r(w_i) \\ \Leftrightarrow \enspace & \text{find } u \in \mathcal U \quad s.t. \quad B_r(w_i,u) = l_r(w_i), \enspace i = 1, \cdots, n \end{aligned} \end{equation} $$

test function space가 $\mathcal W_h$로 축소됨에 따라서 식(4)는 더이상 strong formulation과 동치가 아니다. 

즉, $\mathcal W_h$공간 안에서 weighted residual formulation을 만족하는 해도 식(1)의 solution이 아니며 strong formulation의 approximated solution이 된다.

test function space을 $\mathcal W_h$로 축소함으로써 $n$개의 `기저함수(basis function)`에 대해서만 확인하면 되는 문제로 단순화 하였지만 아직 무한차원 함수공간인 $\cal U$를 탐색해야 되는 어려움이 남아있다. 이 어려움을 해결하기 위해 이번에는 solution function space를 유한차원 함수공간인 $\cal U_h < U$로 축소하자.

여기서 주의해야할 점은 BC을 만족시켜야 하기 때문에 일반적으로 $\mathcal U$는 vector space가 아니다.  
예를 들어 $\partial\Omega$에서 0이 아닌 BC $g$가 주어졌다고 해보자.  
$$ u = g \neq 0 \quad \text{on } \partial\Omega $$

그러면 $u_1, u_2 \in \mathcal{U}$에 대해서 다음이 성립한다.  
$$ (u_1 + u_2)(\mathbf x) = u_1(\mathbf x) + u_2(\mathbf x) = 2g(\mathbf x) \Rightarrow u_1 + u_2 \notin \mathcal{U} \quad \mathbf x \in \partial\Omega $$

즉 $\mathcal{U}$는 덧셈에 대해 닫혀있지 않기 때문에 vector space가 될 수 없다. 

따라서 $\mathcal{U}$는 다음과 같은 affine space가 된다.  
$$ \mathcal{U} = \phi + \mathcal{U}_L $$

$$ \text{Where, } \phi \in \mathcal U, \ \mathcal{U}_L:= \{ u \in C^m(\Omega) \enspace | \enspace u = 0 \text{ on } \partial\Omega \} $$

$\mathcal U$를 축소한 $\mathcal U_h$는 다음과 같다.  
$$ \mathcal U_h := \phi + \mathcal U_{L_h} $$

$$ \text{Where, } \mathcal U_{L_h} = \text{span}(\{ \mu_1, \cdots, \mu_k \}) \le \mathcal U_L $$

따라서 다음이 성립한다.  
$$ u \in \mathcal{U}_ {h} \Rightarrow u = \phi + a_i\mu_i $$

$$ \text{Where, } a_i \in \R $$

따라서, 식(4)은 다음과 같이 더욱 간단해진다.
$$ \begin{equation} \begin{aligned} & \text{find } u \in \mathcal U_h \quad s.t. \quad B_r(w_i,u) = l_r(w_i), \enspace i = 1, \cdots, n \\ \Leftrightarrow \enspace & \text{find } \mathbf a \in \R^k \quad s.t. \quad B_r(w_i,\phi + a_j \mu_j) = l_r(w_i), \enspace i = 1, \cdots, n \end{aligned} \end{equation} $$

식(5)는 $k$개의 미지수가 있음으로 이를 대수적으로 풀기 위해서는 $k$개의 독립적인 방정식이 필요하고 $k = n$이여야한다.

만약, $\mathcal P$가 linear operator면 $B_r$은 bilinear map이 되며 식(5)는 다음과 같이 단순해 진다.
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B_r(w_i, \mu_j) a_j = l_r(w_i) - B_r(w_i,\phi), \enspace i = 1, \cdots, n  $$

이를 행렬 형태로 나타내면 다음과 같다.

$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) - B(w_1, \phi) \\ \vdots \\ l(w_n) - B(w_n, \phi) \end{bmatrix} $$

만약 $u_j$의 $m$계 도함수가 0이라면 $B(w_i,u_j) = 0$이 되고 행렬은 0으로만 이루어진 열을 갖는 singular matrix가 된다. 이는 기저 함수 $u_j$가 해를 근사하는데에 어떠한 기여도 하지 않는다는 것을 의미하며, 그로인해 $u_j$의 계수 $a_j$가 어떤 값을 갖더라도 같은 근사가 됨을 의미한다.

이제 중요한 것은 $\mathcal W_h$와 $\mathcal U_h$를 어떻게 설정하는지이다.

---
