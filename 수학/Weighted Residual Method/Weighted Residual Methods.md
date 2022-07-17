# 들어가며
[note] (M. J. Zahr) 3.Weighted residual methods를 정리하였다.

# Strong formulation
`계수(order)`가 $m$인 `편미분방정식(partial differential equation; PDE)`이 다음과 같이 주어졌다고 하자.
$$ \begin{equation} \text{find } u \in \mathcal U  \quad s.t. \quad \mathcal P(u) + f(\mathbf x) = 0 \quad \text{in }  \Omega \subset \R^d \end{equation} $$

$\mathcal P : C^m(\Omega) \rightarrow C^0(\Omega)$는 계수가 $m$인 `미분 연산자(differential operator)`이며 $\mathcal U$는 `solution funtion space`이며 다음과 같이 정의된다.
$$ \mathcal U := \{ u \in C^m(\Omega) \enspace | \enspace u \text{ satisfies boundary condition on } \partial\Omega \} $$


이 때, `경계조건(boundary condition; BC)`은 $\partial\Omega_E \subset \partial\Omega$따라 essential BC와 $\partial\Omega_N \subset \partial\Omega$따라 natural BC가 주어져있으며 $\partial\Omega = \partial\Omega_E \cup \partial\Omega_N$ 이다.

식(1)을 PDE의 `strong formulation`이라 하는데 이는 strong formulation의 해가 $\Omega$의 모든 점에서 PDE를 만족시켜야하며 $m$번 미분 가능해야된다는 엄격한 `정규성(regularity)`을 만족시켜야하기 때문이다.

> 참고  
[Function space - Wiki](https://en.wikipedia.org/wiki/Function_space#Functional_analysis)

# Weighted residual formulation
식(1)의 weighted residual formulation은 다음과 같이 주어진다.
$$ \begin{equation} \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in C^\infty_c(\Omega), \quad \int_\Omega w r \thinspace dV = 0  \end{equation} $$
$$ \text{Where, } r(\mathbf x) = \mathcal P(u) + f(\mathbf x) $$

이 떄, $w$는 `테스트 함수(test function)`, $r$은 `residual` 이라한다.

식(2)는 식(1)과 동치이며 이는 `변분법(variation calculus)`의 기본 보조정리에 의해 증명된다.

### Fundamental Lemma of variation calculus
$\Omega \subset \R^d$와 $G \in C^0(\Omega)$가 있다고 할 때 다음을 증명하여라.
$$ G=0 \quad \text{on } \Omega \Leftrightarrow \forall w \in C^\infty_c(\Omega), \quad  \int_\Omega w G \thinspace dV = 0 $$

**Proof**

[$\Rightarrow$]  
$G=0$이면 $\forall w \in C^\infty_c(\Omega), \quad  \int_\Omega w G \thinspace dV = 0$는 자명하게 참이다. $\quad {_\blacksquare}$

[$\Leftarrow$]  
$C^\infty_c(\Omega)$는 $L^2(\Omega)$에서 `조밀(dense)`하기 때문에 $G \in L^2(\Omega) \subset C^0(\Omega)$에 수렴하는 함수의 수열 $G_n \in C^\infty_c(\Omega)$이 존재한다.

따라서 다음이 만족한다.
$$ \lim_{n \rightarrow \infty} \int_\Omega G(x)G_n(x) \thinspace dx = \int_\Omega | G(x) |^2 \thinspace dx = 0.$$

$\int_\Omega | G(x) |^2 \thinspace dx = 0$임으로 $G=0 \quad \text{on } \Omega$이다. $\quad {_\blacksquare}$

# Weighted residual method
Weighted residual method는 weighted residual formulation의 test function space를 유한차원 함수공간 $\mathcal W_h$ 축소하여 $\mathcal W_h$에서 Weighted residual formulation을 만족하는 해 중에서 solution function space를 유한 차원 함수공간으로 축소한 $\mathcal U_h$안에 들어 있는 해를 찾는 방법이다.

먼저, test function space을 $C^\infty_c(\Omega)$에서 $C^\infty(\Omega)$로 확장하자. $C^\infty_c(\Omega) < C^\infty(\Omega)$이기 때문에 함수공간을 바꾸어도 strong formulation과 동치이다.

자명하게 무한차원 함수공간인 $C^\infty(\Omega)$에 있는 모든 함수에 대해 식(2)를 적용하는 것은 불가능하다. 따라서 test function space을 $n$차 부분 함수공간인 $\mathcal{W}_h < C^\infty(\Omega)$으로 축소하여 문제를 단순화하자.

$\mathcal W_h$의 기저 함수를 $\{ w_1, \cdots, w_n \}$이라 하면 식(2)는 다음과 같이 간단해 진다.
$$ \begin{equation} \begin{aligned} & \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in \mathcal W_h, \quad \int_\Omega w r \thinspace dV = 0 \\ \Leftrightarrow \enspace & \text{find } u \in \mathcal U \quad s.t. \quad \forall c_i \in \R, \quad \int_\Omega c_iw_i r \thinspace dV = 0, \enspace i \in (1, \cdots, n) \\ \Leftrightarrow \enspace & \text{find } u \in \mathcal U \quad s.t. \quad  \int_\Omega w_i r \thinspace dV = 0, \enspace i \in (1, \cdots, n)  \end{aligned} \end{equation} $$

test function space가 $\mathcal W_h$로 축소됨에 따라 축소된 residual formulation은 더이상 strong formulation과 동치가 아니다. 즉, $\mathcal W_h$공간 안에서 residual formulation을 만족하는 해도 $r=0$을 만족시키는 실제 해가 아니며 실제 해의 근사가 되게 된다.

test function space을 $n$차원 함수공간으로 축소함으로써 $n$개의 `기저함수(basis function)`에 대해서만 확인하면 되는 문제로 단순화 하였지만 아직 무한차원 함수공간인 $\cal U$를 탐색해야 되는 어려움이 남아있다. 이 어려움을 해결하기 위해 이번에는 solution function space를 유한차원 함수공간인 $\cal U_h < U$로 축소하자.

여기서 주의해야할 점은 BC을 만족시켜야 하기 때문에 일반적으로 $\mathcal U$는 vector space가 아니다.
예를 들어 $\partial\Omega$에서 0이 아닌 BC $g$가 주어졌다고 해보자.
$$ u = g \neq 0 \quad \text{on } \partial\Omega  $$

그러면 $u_1, u_2 \in \mathcal{U}$에 대해서 다음이 성립한다.
$$ (u_1 + u_2)(\mathbf x) = u_1(\mathbf x) + u_2(\mathbf x) = 2g(\mathbf x) \Rightarrow u_1 + u_2 \notin \mathcal{U} \quad \mathbf x \in \partial\Omega $$

즉 $\mathcal{U}$는 덧셈에 대해 닫혀있지 않기 때문에 vector space가 될 수 없다. 따라서 $\mathcal{U}$는 다음과 같은 affine space가 된다.
$$ \mathcal{U} = \phi + \mathcal{U}_L $$
$$ \text{Where, } \phi \in \mathcal U \text{ and} \\ \mathcal{U}_L:= \{ u \in C^m(\Omega) \thinspace | \thinspace u \text{ satisfies homogeneous BCs on } \partial\Omega \} $$

따라서 affine space인 solution function space를 축소한 $\mathcal U_h$는 다음과 같다.
$$ \mathcal U_h := \phi + \mathcal U_{L_h} $$
$$ \text{Where, } \mathcal U_{L_h} < \mathcal U_L \quad \land \quad \dim(\mathcal U_{L_h}) = k $$

$\mathcal{U}_{L_h}$의 기저함수를 $\{ u_1, \cdots, u_k \}$이라 하면 다음이 성립한다.
$$ u \in \mathcal{U}_{h} \Rightarrow u = \phi + a_iu_i $$
$$ \text{Where, } a_i \in \R $$

따라서, 식(3)은 다음과 같이 더욱 간단해진다.
$$ \begin{equation} \begin{aligned} & \text{find } u \in \mathcal U_h \ \quad s.t. \quad \int_\Omega w_i r \thinspace dV = 0 \quad \forall i \in  (1, \cdots, n) \\ \Leftrightarrow \enspace & \text{find } \mathbf a \in \R^k \quad s.t. \quad \int_\Omega w_i r \thinspace dV = 0 \quad \forall i \in  (1, \cdots, n) \end{aligned} \end{equation} $$
$$ \text{Where, } r = \mathcal P(\phi + a_ju_j) + f(x)$$

위의 식(4)가 test function space와 solution function space를 축소하여 얻은 단순화된 residual formulation이다. 식(4)는 $k$개의 미지수가 있음으로 이를 대수적으로 풀기 위해서는 $k$개의 독립적인 방정식이 필요하고  $k \le n$이여야한다.

만약, $\mathcal P$가 선형 연산자 즉, 선형 PDE라면 식(4)는 다음과 같이 단순해 진다.
$$ \begin{equation} \text{find } \mathbf a \in \R^k \quad s.t. \quad  \bf K a = f  \end{equation} $$
$$ \text{Where, } K_{ij} = \int_\Omega w_i \mathcal P(u_j) \thinspace dV , \quad f_i = -\int_\Omega w_i (\mathcal P(\phi) + f(x)) $$

임의의 solution function space의 기저함수 $u_j$가 0이 아닌 $m$계 도함수을 갖는다면 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$가 선형독립임으로 $\bf K$는 가역행렬이다.

만약 $u_j$의 $m$계 도함수가 0이라면 $\mathcal P(u_j) = 0$이 되고 $\bf K$는 0으로만 이루어진 행을 갖는 singular matrix가 된다. 이는 기저 함수 $u_j$가 해를 근사하는데에 어떠한 기여도 하지 않는다는 것을 의미하며, 그로인해 $u_j$의 계수 $a_j$가 어떤 값을 갖더라도 같은 근사가 됨을 의미한다.

## Petrov-Galerkin method
축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하는 방법을 `Petrov-Galerkin method`라고 한다.

결론적으로 Petrov-Galerkin method는 독립적으로 정의된 $\mathcal W_h$공간에서 weighted residual method를 만족하는 $u$를 $\mathcal U_h$ 공간에서 찾는 방법이다.

## Bubnov-Galerkin method
축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 동일하게 정의하는 방법을 `Bubnov-Galerkin method`라고 한다.
$$ w_i = u_i $$

단순화된 residual formulation에 Bubnov-Galerkin method을 적용하면 다음과 같다.
$$ \text{find } \mathbf a \in \R^k \quad s.t. \quad \int_\Omega u_i r \thinspace dV = 0 \quad \forall i \in  (1, \cdots, n)$$

만약 선형 PDE일 경우 다음과 같이 간단해 진다.
$$ \text{find } \mathbf a \in \R^k \quad s.t. \quad \bf K a = f $$
$$ \text{Where, } K_{ij} = \int_\Omega u_i \mathcal P(u_j) \thinspace dV , \quad f_i = -\int_\Omega w_i (\mathcal P(\phi) + f(x)) $$

결론적으로 Bubnov-Galerkin method는 $\mathcal U_h$공간에서 weighted residual method를 만족하는 $u$를 $\mathcal U_h$ 공간에서 찾는 방법이다.

$r$은 orthogonal하다.

## Point collocation method
축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 Dirac-delta 함수를 사용하는 방법을 `point collocation method`라고 한다.
$$ w_i = \delta(\mathbf x - \mathbf x_i) $$

단순화된 residual formulation에 Point Collocation method을 적용하면 다음과 같다.
$$ \text{find } \mathbf a \in \R^k \quad s.t. \quad \mathcal r(\mathbf x_i) = 0 \quad \forall i \in  (1, \cdots, n)$$

결론적으로 point collocation method는 Dirac-delta 함수를 기저로 갖는 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 $u$를 $\mathcal U_h$에서 찾는 방법이다. 

이 때, Dirac-delta 함수의 성질에 의해 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 solution은 collocation node로 불리는 $\mathbf x_i$점에서 residual을 0으로 만드는 즉, strong formulation을 만족시키는 solution이다.

### 참고
Dirac delta function은 $L^2$인가?  
$L^2$공간과 $C^\infty$의 포함관계는 어떻게 되는가?  
[note] (M. J. zahr) 5.Variational formulation of elliptic PDEs 공부

## Subdomain collocation nmethod
축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 계단 함수를 사용하는 방법을 `subdomain collocation method`라고 한다.
$$ w_i = \begin{cases} 1 & \text{if } \mathbf x_i \in \Omega_i \\ 0 & \text{else} \end{cases}$$

단순화된 residual formulation에 subdomain collocation method을 적용하면 다음과 같다.
$$ \text{find } \mathbf a \in \R^k \quad s.t. \int_{\Omega_i} r \thinspace dV = 0 \quad \forall i \in  (1, \cdots, n)$$

결론적으로 subdomain collocation method는 계단 함수를 기저로 갖는 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 $u$를 $\mathcal U_h$에서 찾는 방법이다. 

이 때, 계단 함수의 성질에 의해 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 solution은 $\Omega_i$에서 residaul의 평균을 0으로 만드는 solution이다.

## Least square Method
축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 다음과 같이 정의된 값을 쓰는 방법을 `least square method`라고 한다.
$$ w_i = \frac{\partial r}{\partial a_i}, \quad (i = 1, \cdots, n)$$

단순화된 residual formulation에 least square method을 적용하면 다음과 같다.
$$ \begin{aligned} & \text{find } \mathbf a \in \R^k \quad s.t. \quad \int_{\Omega_i} \frac{\partial r}{\partial a_i} r \thinspace dV = 0 \quad \forall i \in  (1, \cdots, n) \\ \Leftrightarrow \enspace & \text{find } \mathbf a \in \R^k \quad s.t. \quad \frac{\partial}{\partial a_i} \int_{\Omega_i} r^2 \thinspace dV = 0 \quad \forall i \in  (1, \cdots, n)\end{aligned} $$
$$ $$

결론적으로 least square method는 residual의 계수에 대한 미분을 기저로 갖는 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 $u$중에 $\mathcal U_h$공간안에 있는 해를 찾는 방법이다. 

이 때, $w_i$의 정의에 의해 residual 제곱의 합이 최소가 되는 값을 찾기 때문에 least square method라고 한다.

# Weak formulation
Weak formulation은 integration part 혹은 divergence theorem을 통해 solution function $u$에 있는 미분항을 test function $w$으로 옮겨 solution space의 regularity를 약화시키고, 문제에 주어진 natural BC를 식에 포함시킴으로 써 solution space가 더이상 natural BC를 만족시킬 필요 없게 만든다.

Weak formulation을 다음 예제를 통해 구체적으로 알아보자.
$$ \begin{equation} \text{find } u \in \mathcal U_s \quad s.t. \quad  -\frac{d}{dx}(a\frac{du}{dx}) + cu = f \quad \text{in } \Omega := (0,L) \subset \R \end{equation} $$

BC는 다음과 같이 주어진다.
$$ \begin{aligned} u(0) &= u_0 \\ \left( a\frac{du}{dx} \right)_{x=L} &= Q_L \end{aligned}  $$

따라서 solution space는 다음과 같다.
$$ \mathcal U_s := \left\{ u \in C^2(\Omega) \enspace \bigg| \enspace u(0) = u_0 \land \left( a\frac{du}{dx} \right)_{x=L} = Q_L \right\} $$

식(6)의 weighted residual form은 다음과 같다.
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty_c(\Omega), \quad \int_\Omega w \left( -\frac{d}{dx}(a\frac{du}{dx}) + cu - f \right) \thinspace dx = 0  $$

부분적분법을 적용하면 다음과 같다.
$$ \begin{equation} \begin{gathered} \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty_c(\Omega)\\ \int_\Omega  \left( -\frac{dw}{dx}(a\frac{du}{dx}) + w(cu - f) \right) \thinspace dx - wa\frac{du}{dx} \bigg]_0^L = 0 \end{gathered} \end{equation}  $$

BC를 적용하면 다음과 같다.
$$ \begin{gathered} \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty_c(\Omega)\\ \int_\Omega  \left( -\frac{dw}{dx}(a\frac{du}{dx}) + w(cu - f) \right) \thinspace dx + wa\frac{du}{dx} \bigg]_0 - w(L)Q_L = 0 \end{gathered} $$

이 때, test function space가 $C^\infty_c(\Omega)$임으로 $\partial\Omega$에서 $w=0$이다. 이로인해 natural BC를 식에 적용하는것이 불가능하다. 따라서 test function space를 essential BC가 적용되는 $\partial\Omega_E$에서만 0이 되는 함수공간 $\mathcal W$로 확장한다.
$$ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace \forall \mathbf x \in \partial\Omega_E, \quad w(\mathbf x) = 0 \} $$

$C^\infty_c(\Omega) < \mathcal W$임으로 strong formulation과 동치관계를 유지하며 $\mathcal W$는 vector space다. $\mathcal W$는 현재 문제에서 다음과 같다.
$$ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace w(0) = 0 \} $$

결론적으로 weak formulation은 다음과 같다.
$$ \begin{equation} \begin{gathered} \text{find } u \in \mathcal U_w \quad s.t. \quad \forall w \in \mathcal W \\ \int_\Omega  \left( -\frac{dw}{dx}(a\frac{du}{dx}) + w(cu - f) \right) \thinspace dx - w(L)Q_L = 0 \end{gathered} \end{equation} $$
$$ \text{Where, } \mathcal U_w := \left\{ u \in C^2(\Omega) \enspace \bigg| \enspace u(0) = u_0 \right\} $$

weak formulation에 natural BC가 포함되어 있기 때문에 solution space를 더이상 natural BC를 만족하는 공간으로 제한할 필요가 없으며 $\mathcal U_s \subset \mathcal U_w$이다.

현재까지 충분한 regularity를 solution function space와 test function space에 부여한채로 strong form에서부터 weighted residual form, weak form을 유도하였기 때문에 현재 정규성 조건에서는 strong, weighted residual, weak formulation이 전부 동치이다.

하지만 식(8)을 보면 알 수 있듯이, weak formulation에서는 이러한 regularity를 약화시킬 수 있다. 즉, solution을 $C^2(\Omega)$가 아닌 $C^1(\Omega)$에서 찾을 수 있다는 것이다. 이렇게 regularity가 약화된 weak formulation은 다음과 같다.
$$ \begin{equation} \begin{gathered} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W \\ \int_\Omega  \left( -\frac{dw}{dx}(a\frac{du}{dx}) + w(cu - f) \right) \thinspace dx - w(L)Q_L = 0 \end{gathered} \end{equation} $$
$$ \text{Where, } \mathcal U_W := \left\{ u \in C^1(\Omega) \enspace \bigg| \enspace u(0) = u_0 \right\} $$

식(9)는 식(8)보다 더 약한 regularity를 요구하기 때문에 더 일반적인 형태이다. weak formulation이라고 불리는 이유는 바로 solution space의 regularity 요구사항을 약화시켰기 때문이다. $u \notin C^2(\Omega)$이면 strong formulation이 정의조차 되지 않기 때문에 식(9)는 더이상 strong formulation과 동치가 아니다.

일반적으로 weak formulation은 functional $B,l$을 이용해 다음과 같이 간단하게 나타낼 수 있다.

$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,u) = l(w) \end{equation}  $$
$$ \begin{gathered} \text{Where, } B: \mathcal W \times \mathcal U_W \rightarrow \R, \quad l: \mathcal W \rightarrow \R \\ \mathcal U_W := \left\{ u \in C^r(\Omega) \enspace \big| \enspace u \text{ satisfies essential BCs on } \partial\Omega_E\right\} \\ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace w(\mathbf x) = 0 \text{ for } \mathbf x \in \partial\Omega_E \} \end{gathered} $$

이 떄, $\mathcal U_W$는 affine space이고 $\mathcal W$는 vector space이다.

linear PDE의 경우 식(10)을 bilinear form for linear PDEs라고 하며 식(9)를 bilinear form으로 나타내면 다음과 같다.
$$ B(w,u) := \int_\Omega  \left( -\frac{dw}{dx}(a\frac{du}{dx}) + wcu \right) \thinspace dx, \quad l(w) := \int_\Omega  wf \thinspace dx + w(L)Q_L  $$

# Ritz method
Ritz method는 weak formulation을 기반으로한 수치기법이다. Ritz method에서도 weight residual method에서 했던 방법과 동일하게 무한차원 test function space와 solution function space를 유한차원으로 축소한다.

먼저, test function space는 다음과 같이 축소한다.
$$\mathcal W_h < \mathcal W$$

다음으로, solution function space 다음과 같이 축소한다.
$$ \mathcal{U}_h = \varphi + \mathcal{U}_{L_h} $$
$$ \begin{gathered} \text{Where, } \varphi \in \mathcal{U}_W, \quad  \mathcal{U}_{L_h} < \mathcal{U}_L \\ \mathcal{U}_L := \{ u \in C^r(\Omega) \enspace | \enspace u \text { satisfies homogeneous BC on } \partial\Omega_E \} \end{gathered} $$

이 때, 유한차원 function space $\mathcal{W}_h, \mathcal{U}_{L_h}$의 기저함수를 각각 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$라 하자.

Ritz method에서는 Bubnov-Galerkin method를 사용한다.
$$ w_i = u_i $$

식(10)에 Ritz method를 적용하면 다음과 같다.
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(u_i,\varphi + a_ju_j) = l(u_i) \quad \forall i \in \{ 1, \cdots, n \} $$

$B$가 bilinear이고 $l$이 linear인 경우 다음과 같이 간단해진다.
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad \mathbf {Ka = f} $$
$$ \text{Where, } K_{ij} = B(u_i,u_j), \quad f_i = l(u_i) - B(u_i, \varphi) \quad \forall i \in \{ 1, \cdots, n \} $$