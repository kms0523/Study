# 들어가며

[note] (M. J. Zahr) 3.Weighted residual methods를 정리하였다.

# Strong formulation

`계수(order)`가 $m$인 `편미분방정식(partial differential equation; PDE)`이 다음과 같이 주어졌다고 하자.  
$$ \begin{equation} \text{find } u \in \mathcal U \quad s.t. \quad \mathcal P(u) + f(\mathbf x) = 0 \quad \text{in } \Omega \subset \R^d \end{equation} $$

$\mathcal P : C^m(\Omega) \rightarrow C^0(\Omega)$는 계수가 $m$인 `미분 연산자(differential operator)`이며 $\mathcal U$는 `solution funtion space`이며 다음과 같이 정의된다.  
$$ \mathcal U := \{ u \in C^m(\Omega) \enspace | \enspace u \text{ satisfies boundary condition on } \partial\Omega \} $$

이 때, `경계조건(boundary condition; BC)`은 $\partial\Omega_E \subset \partial\Omega$따라 essential BC와 $\partial\Omega_N \subset \partial\Omega$따라 natural BC가 주어져있으며 $\partial\Omega = \partial\Omega_E \cup \partial\Omega_N$ 이다.

식(1)을 PDE의 `strong formulation`이라 하는데 이는 strong formulation의 해가 $\Omega$의 모든 점에서 PDE를 만족시켜야하며 $m$번 미분 가능해야된다는 엄격한 `정규성(regularity)`을 만족시켜야하기 때문이다.

> 참고  
> [Function space - Wiki](https://en.wikipedia.org/wiki/Function_space#Functional_analysis)

# Weighted residual formulation

식(1)의 weighted residual formulation은 다음과 같이 주어진다.  
$$ \begin{equation} \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in C^\infty_c(\Omega), \quad \int_\Omega w r \thinspace dV = 0 \end{equation} $$

$$ \text{Where, } r(\mathbf x) = \mathcal P(u) + f(\mathbf x) $$

이 떄, $w$는 `테스트 함수(test function)`, $r$은 `residual` 이라한다.

식(2)는 식(1)과 동치이며 이는 `변분법(variation calculus)`의 기본 보조정리에 의해 증명된다.

### Fundamental Lemma of variation calculus

$\Omega \subset \R^d$와 $G \in C^0(\Omega)$가 있다고 할 때 다음을 증명하여라.  
$$ G=0 \quad \text{on } \Omega \Leftrightarrow \forall w \in C^\infty_c(\Omega), \quad \int_\Omega w G \thinspace dV = 0 $$

**Proof**

[$\Rightarrow$]  
$G=0$이면 $\forall w \in C^\infty_c(\Omega), \quad \int_\Omega w G \thinspace dV = 0$는 자명하게 참이다. $\quad {_\blacksquare}$

[$\Leftarrow$]  
$C^\infty_c(\Omega)$는 $L^2(\Omega)$에서 `조밀(dense)`하기 때문에 $G \in L^2(\Omega) \subset C^0(\Omega)$에 수렴하는 함수의 수열 $G_n \in C^\infty_c(\Omega)$이 존재한다.

따라서 다음이 만족한다.  
$$ \lim_{n \rightarrow \infty} \int_\Omega G(x)G_n(x) \thinspace dx = \int_\Omega | G(x) |^2 \thinspace dx = 0.$$

$\int_\Omega | G(x) |^2 \thinspace dx = 0$임으로 $G=0 \quad \text{on } \Omega$이다. $\quad {_\blacksquare}$

> 참고  
> [alternative-proof-of-fundamental-lemma-of-variational-calculus - Mathematics](https://math.stackexchange.com/questions/1792102/alternative-proof-of-fundamental-lemma-of-variational-calculus)

# Weighted residual method

Weighted residual method는 weighted residual formulation의 test function space를 유한차원 함수공간 $\mathcal W_h$로 축소하여 $\mathcal W_h$에서 Weighted residual formulation을 만족하는 해 중에서 solution function space를 유한 차원 함수공간으로 축소한 $\mathcal U_h$안에 들어 있는 해를 찾는 방법이다.

먼저, test function space을 $C^\infty_c(\Omega)$에서 $C^\infty(\Omega)$로 확장하자. $C^\infty_c(\Omega) < C^\infty(\Omega)$이기 때문에 함수공간을 바꾸어도 strong formulation과 동치이다.

자명하게 무한차원 함수공간인 $C^\infty(\Omega)$에 있는 모든 함수에 대해 식(2)를 적용하는 것은 불가능하다. 따라서 test function space을 $n$차 부분 함수공간인 $\mathcal{W}_h < C^\infty(\Omega)$으로 축소하여 문제를 단순화하자.

$\mathcal W_h$의 기저 함수를 $\{ w_1, \cdots, w_n \}$이라 하면 식(2)는 다음과 같이 간단해 진다.  
$$ \begin{equation} \begin{aligned} & \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in \mathcal W_h, \quad \int_\Omega w r \thinspace dV = 0 \ \Leftrightarrow \enspace & \text{find } u \in \mathcal U \quad s.t. \quad \forall c_i \in \R, \quad \int_\Omega c_iw_i r \thinspace dV = 0, \enspace i = 1, \cdots, n \ \Leftrightarrow \enspace & \text{find } u \in \mathcal U \quad s.t. \quad \int_\Omega w_i r \thinspace dV = 0, \enspace i = 1, \cdots, n \end{aligned} \end{equation} $$

test function space가 $\mathcal W_h$로 축소됨에 따라 축소된 residual formulation은 더이상 strong formulation과 동치가 아니다. 즉, $\mathcal W_h$공간 안에서 residual formulation을 만족하는 해도 $r=0$을 만족시키는 strong formulation의 solution이 아니며 strong formulation의 approximated solution이 된다.

test function space을 $n$차원 함수공간으로 축소함으로써 $n$개의 `기저함수(basis function)`에 대해서만 확인하면 되는 문제로 단순화 하였지만 아직 무한차원 함수공간인 $\cal U$를 탐색해야 되는 어려움이 남아있다. 이 어려움을 해결하기 위해 이번에는 solution function space를 유한차원 함수공간인 $\cal U_h < U$로 축소하자.

여기서 주의해야할 점은 BC을 만족시켜야 하기 때문에 일반적으로 $\mathcal U$는 vector space가 아니다.  
예를 들어 $\partial\Omega$에서 0이 아닌 BC $g$가 주어졌다고 해보자.  
$$ u = g \neq 0 \quad \text{on } \partial\Omega $$

그러면 $u_1, u_2 \in \mathcal{U}$에 대해서 다음이 성립한다.  
$$ (u_1 + u_2)(\mathbf x) = u_1(\mathbf x) + u_2(\mathbf x) = 2g(\mathbf x) \Rightarrow u_1 + u_2 \notin \mathcal{U} \quad \mathbf x \in \partial\Omega $$

즉 $\mathcal{U}$는 덧셈에 대해 닫혀있지 않기 때문에 vector space가 될 수 없다. 따라서 $\mathcal{U}$는 다음과 같은 affine space가 된다.  
$$ \mathcal{U} = \phi + \mathcal{U}_L $$

$$ \text{Where, } \phi \in \mathcal U \text{ and} \ \mathcal{U}_L:= \{ u \in C^m(\Omega) \thinspace | \thinspace u \text{ satisfies homogeneous BCs on } \partial\Omega \} $$

따라서 affine space인 solution function space를 축소한 $\mathcal U_h$는 다음과 같다.  
$$ \mathcal U_h := \phi + \mathcal U_{L_h} $$

$$ \text{Where, } \mathcal U_{L_h} < \mathcal U_L \quad \land \quad \dim(\mathcal U_{L_h}) = k $$

$\mathcal{U}_ {L_h}$의 기저함수를 $\{ u_1, \cdots, u_k \}$이라 하면 다음이 성립한다.  
$$ u \in \mathcal{U}_ {h} \Rightarrow u = \phi + a_iu_i $$

$$ \text{Where, } a_i \in \R $$

따라서, 식(3)은 다음과 같이 더욱 간단해진다.  
$$ \begin{equation} \begin{aligned} & \text{find } u \in \mathcal U_h \ \quad s.t. \quad \int_\Omega w_i r \thinspace dV = 0 \quad i = 1, \cdots, n \ \Leftrightarrow \enspace & \text{find } \mathbf a \in \R^k \quad s.t. \quad \int_\Omega w_i r \thinspace dV = 0 \quad i = 1, \cdots, n \end{aligned} \end{equation} $$

$$ \text{Where, } r = \mathcal P(\phi + a_ju_j) + f(\mathbf x)$$

위의 식(4)가 test function space와 solution function space를 축소하여 얻은 단순화된 weighted residual formulation이다. 식(4)는 $k$개의 미지수가 있음으로 이를 대수적으로 풀기 위해서는 $k$개의 독립적인 방정식이 필요하고 $k \le n$이여야한다.

만약, $\mathcal P$가 선형 연산자 즉, 선형 PDE라면 식(4)는 다음과 같이 단순해 진다.  
$$ \begin{equation} \text{find } \mathbf a \in \R^k \quad s.t. \quad \bf K a = f \end{equation} $$

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
$$ \begin{equation} \text{find } \mathbf a \in \R^k \quad s.t. \quad \int_\Omega u_i r \thinspace dV = 0, \quad i = 1, \cdots, n \end{equation} $$

만약 선형 PDE일 경우 다음과 같이 간단해 진다.  
$$ \text{find } \mathbf a \in \R^k \quad s.t. \quad \bf K a = f $$

$$ \text{Where, } K_{ij} = \int_\Omega u_i \mathcal P(u_j) \thinspace dV , \quad f_i = -\int_\Omega w_i (\mathcal P(\phi) + f(x)) $$

결론적으로 Bubnov-Galerkin method는 $\mathcal U_h$공간에서 weighted residual method를 만족하는 $u$를 $\mathcal U_h$ 공간에서 찾는 방법이다.

식(6)을 보면 $r$과 모든 $u_i$의 내적이 0이 되는 $\mathbf a$를 찾는 것임으로, 이렇게 찾은 $r$은 solution function space에 orthogonal하다.

## Point collocation method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 Dirac-delta 함수를 사용하는 방법을 `point collocation method`라고 한다.  
$$ w_i = \delta(\mathbf x - \mathbf x_i) $$

단순화된 residual formulation에 point collocation method을 적용하면 다음과 같다.  
$$ \text{find } \mathbf a \in \R^k \quad s.t. \quad \mathcal r(\mathbf x_i) = 0, \quad i = 1, \cdots, n $$

결론적으로 point collocation method는 Dirac-delta 함수를 기저로 갖는 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 $u$를 $\mathcal U_h$에서 찾는 방법이다.

이 때, Dirac-delta 함수의 성질에 의해 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 solution은 collocation node로 불리는 $\mathbf x_i$점에서 residual을 0으로 만드는 즉, strong formulation을 만족시키는 solution이다.

### 참고

Dirac delta function은 $L^2$인가?  
$L^2$공간과 $C^\infty$의 포함관계는 어떻게 되는가?  
[note] (M. J. zahr) 5.Variational formulation of elliptic PDEs 공부

## Subdomain collocation method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 계단 함수를 사용하는 방법을 `subdomain collocation method`라고 한다.  
$$ w_i = \begin{cases} 1 & \text{if } \mathbf x_i \in \Omega_i \ 0 & \text{else} \end{cases}$$

단순화된 residual formulation에 subdomain collocation method을 적용하면 다음과 같다.  
$$ \text{find } \mathbf a \in \R^k \quad s.t. \int_{\Omega_i} r \thinspace dV = 0, \quad i = 1, \cdots, n $$

결론적으로 subdomain collocation method는 계단 함수를 기저로 갖는 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 $u$를 $\mathcal U_h$에서 찾는 방법이다.

이 때, 계단 함수의 성질에 의해 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 solution은 $\Omega_i$에서 residaul의 평균을 0으로 만드는 solution이다.

## Least square method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 다음과 같이 정의된 값을 쓰는 방법을 `least square method`라고 한다.  
$$ w_i = \frac{\partial r}{\partial a_i}, \quad (i = 1, \cdots, n)$$

단순화된 residual formulation에 least square method을 적용하면 다음과 같다.  
$$ \begin{aligned} & \text{find } \mathbf a \in \R^k \quad s.t. \quad \int_{\Omega_i} \frac{\partial r}{\partial a_i} r \thinspace dV = 0 \quad \forall i \in (1, \cdots, n) \ \Leftrightarrow \enspace & \text{find } \mathbf a \in \R^k \quad s.t. \quad \frac{\partial}{\partial a_i} \int_{\Omega_i} r^2 \thinspace dV = 0 \quad \forall i \in (1, \cdots, n)\end{aligned} $$  
$$ $$

결론적으로 least square method는 residual의 계수에 대한 미분을 기저로 갖는 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 $u$중에 $\mathcal U_h$공간안에 있는 해를 찾는 방법이다.

이 때, $w_i$의 정의에 의해 residual 제곱의 합이 최소가 되는 값을 찾기 때문에 least square method라고 한다.

# Weak formulation

Weak formulation은 integration part 혹은 divergence theorem을 통해 solution function $u$에 있는 미분항을 test function $w$으로 옮겨 solution space의 regularity를 약화시키고, 문제에 주어진 natural BC를 식에 포함시킴으로 써 solution space가 더이상 natural BC를 만족시킬 필요 없게 만든다.

Weak formulation을 다음 예제를 통해 구체적으로 알아보자.

PDE가 다음과 같이 주어졌다고 해보자.  
$$ \begin{equation} \text{find } u \in \mathcal U_s \quad s.t. \quad -\frac{d}{dx}(a\frac{du}{dx}) + cu = f \quad \text{in } \Omega := (0,L) \subset \R \end{equation} $$

$$ \text{Where, } \mathcal U_s := \left\{ u \in C^2(\Omega) \enspace \bigg| \enspace u(0) = u_0 \land \left( a\frac{du}{dx} \right)_{x=L} = Q_L \right\} $$

이 때, 함수 $a,c,f : \Omega \rightarrow \R$와 $u_0, Q_L \in \R$은 주어졌다고 하자.

식(7)의 weighted residual form은 다음과 같다.  
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty_c(\Omega), \quad \int_\Omega w \left( -\frac{d}{dx}(a\frac{du}{dx}) + cu - f \right) \thinspace dx = 0 $$

부분적분법을 적용하면 다음과 같다.  
$$ \begin{equation} \begin{gathered} \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty_c(\Omega)\ \int_\Omega \left( -\frac{dw}{dx}(a\frac{du}{dx}) + w(cu - f) \right) \thinspace dx - wa\frac{du}{dx} \bigg]_0^L = 0 \end{gathered} \end{equation} $$

BC를 적용하면 다음과 같다.  
$$ \begin{gathered} \text{find } u \in \mathcal U_s \quad s.t. \quad \forall w \in C^\infty_c(\Omega)\ \int_\Omega \left( -\frac{dw}{dx}(a\frac{du}{dx}) + w(cu - f) \right) \thinspace dx + wa\frac{du}{dx} \bigg]_0 - w(L)Q_L = 0 \end{gathered} $$

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

## Weak formulation
$$ \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in C^\infty(\Omega), \quad B(w,u) = l(w) $$

$$ \begin{gathered} \text{Where, } \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(2) = 1 \} \\ B(w,u) := w\frac{du}{dx} \bigg |_{x=2} -\int_\Omega \frac{dw}{dx}\frac{du}{dx} \thinspace dV \\ l(w) := w(0) \end{gathered} $$

Boundary condition 중 natural BC는 weak form에 반영됨으로써 약하게 부여된다.

### method3
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,  a_j\mu_j) = l(w_i) \enspace i = 1, \cdots, n $$

$$ \begin{gathered} \text{Where, } w_i \in C^\infty(\Omega), \quad \phi \in \mathcal U_W , \\ \mu_i \in \{ \mu \in C^1(\Omega) \} \end{gathered}  $$

essential BC는 explicit하게 적용한다.
$$ a_i \mu_i|_{x=2} = 1 $$

$B$가 bi-linear 임으로
$$ \text{find } a \in \mathcal \R^n \quad s.t. \quad B(w_i,\mu_j) a_j = l(w_i) \enspace i = 1, \cdots, n $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(w_1,\mu_1) & \cdots & B(w_1,\mu_n) \\ \vdots & \ddots & \vdots \\ B(w_n,\mu_1) & \cdots & B(w_n,\mu_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) \\ \vdots \\ l(w_n) \end{bmatrix} $$

#### Galerkin Method
$n = 2, \enspace \mu_i = (x + 1)^{i-1}$라 하자.

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & -1 \\ 0 & 1 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} -1 \\ 1 \end{bmatrix} $$

essential BC를 적용하면 다음과 같다.
$$ a_1 + 2a_2 = 1 $$

#### approx2
$\mu_1 = 1, \mu_2 = x + 3$라 하자.

essential BC를 적용하면 다음과 같다.
$$ a_1 + 5a_2 = 1 $$

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & -1 \\ 0 & -3 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} -1 \\ -3 \end{bmatrix} $$

## Weak formulation2
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,v) = l(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } B : \mathcal W \times \mathcal U_W \rightarrow \R \quad s.t. \quad (w,u) \mapsto \int_\Omega \frac{du}{dx}\frac{dw}{dx} \thinspace dV \\ l : \mathcal W \rightarrow \R \quad s.t. \quad w \mapsto -w(0) \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(2) = 1 \} \\ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace w(2) = 0 \} \end{gathered} $$

$\mathcal U_W$는 $\mathcal U_s$에서 regularity를 약화시키고, natural BC가 equation에 impose 되어 있음으로 natural BC 조건을 배제한 공간이다.

$\mathcal W$는 $C^\infty_c(\Omega)$에서 natural BC를 식에 impose 시키기 위해서 natural BC에서는 0이 되지 않게 조건을 완화한 공간이다.

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
$$ \begin{bmatrix} 0 & 0 \\ 0 & 2 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} -1 \\ 0 \end{bmatrix} $$

이게 뭔가 이상하다!

#### approx2
$\mu_1 = 1, \mu_2 = x + 3$라 하자.

essential BC를 적용하면 다음과 같다.
$$ a_1 + 5a_2 = 1 $$

행렬식은 다음과 같다.
$$ \begin{bmatrix} 0 & -1 \\ 0 & -3 \end{bmatrix} \begin{bmatrix} a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} -1 \\ -3 \end{bmatrix} $$

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
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} + 1 = 0 \quad \text{in} \enspace \Omega := [0,2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 1 \enspace \land \enspace u'(2) = 1 \} $$

exact solution은 $u = 1 + 3x - 0.5x^2$이다.

> 참고  
> [book] (Kelly) An Introduction to the FEM chapter 2.3.2

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