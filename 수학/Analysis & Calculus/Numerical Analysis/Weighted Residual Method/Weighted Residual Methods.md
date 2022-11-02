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

$$ \text{Where, } B_r(w,u) :=  \int_\Omega w\mathcal P(u) \thinspace dV, \quad l_r(w) := -\int_\Omega wf \thinspace dV $$

이 때, $B_r$은 첫번째 원소에 대해서 linear map이며, $l_r$은 linear map이다.

만약, $\mathcal P$가 linear operator라면, $B_r$은 bilinear map이 된다.

## Dimensional Reduction
무한차원 함수공간인 $\mathcal W$에 있는 모든 함수에 대해 식(3)를 만족하는 $u$를 무한차원 함수공간인 $\mathcal U$에서 찾는 일은 너무 어렵다.

따라서 test function space와 solution function space를 각 각 유한차원 함수 공간으로 축소하여 문제를 단순화해보자.

먼저 test function space를 $\mathcal{W}_h := \text{span}(\{ w_1, \cdots, w_n \})$로 축소하면 식(3)은 다음과 같이 간단해 진다.
$$ \begin{equation} \begin{aligned} & \text{find } u \in \mathcal U \quad s.t. \quad \forall w \in \mathcal W_h, \quad B_r(w,u) = l_r(w) \\ \Leftrightarrow \enspace & \text{find } u \in \mathcal U \quad s.t. \quad \forall c_i \in \R, \quad c_i B_r(w_i,u) = c_il_r(w_i) \\ \Leftrightarrow \enspace & \text{find } u \in \mathcal U \quad s.t. \quad B_r(w_i,u) = l_r(w_i), \enspace i = 1, \cdots, n \end{aligned} \end{equation} $$

Test function space을 $\mathcal W_h$로 축소함으로써 $n$개의 `기저함수(basis function)`에 대해서만 확인하면 되는 문제로 단순화 하였지만 아직 무한차원 함수공간인 $\cal U$를 탐색해야 되는 어려움이 남아있다. 

이 어려움을 해결하기 위해 이번에는 solution function space를 유한차원 함수공간인 $\cal U_h < U$로 축소하자.

이 떄, 명제2에 따라 $\mathcal U_h := \phi + \text{span}(\{ u_1, \cdots, u_k \})$로 축소하면 식(4)는 다음과 같이 간단해진다.
$$ \begin{equation} \begin{aligned} & \text{find } u \in \mathcal U_h \quad s.t. \quad B_r(w_i,u) = l_r(w_i), \enspace (i = 1,\cdots,n) \\ \Leftrightarrow \enspace & \text{find } \mathbf a \in \R^k \quad s.t. \quad B_r(w_i,\phi + a_j \mu_j) = l_r(w_i), \quad (i = 1,\cdots,n, \enspace j = 1,\cdots,k) \end{aligned} \end{equation} $$

이 때, 주의할 점은 탐색하는 공간을 축소하였기 때문에 식(5)는 더 이상 식(1)과 동치가 아니다.

즉, $\mathcal W_h$공간 안에서 weighted residual formulation을 만족하는 해도 식(1)의 solution이 아니며 strong formulation의 approximated solution이 된다. 

만약, $\mathcal P$가 linear operator면 $B_r$은 bilinear map이 되며 식(5)는 다음과 같이 단순해 진다.
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B_r(w_i, u_j) a_j = l_r(w_i) - B_r(w_i,\phi), \enspace i = 1, \cdots, n  $$

이를 행렬 형태로 나타내면 다음과 같다.

$$ \begin{bmatrix} B(w_1,u_1) & \cdots & B(w_1,u_n) \\ \vdots & \ddots & \vdots \\ B(w_n,u_1) & \cdots & B(w_n,u_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) - B(w_1, \phi) \\ \vdots \\ l(w_n) - B(w_n, \phi) \end{bmatrix} $$

만약 $u_j$의 $m$계 도함수가 0이라면 $B(w_i,u_j) = 0$이 되고 행렬은 0으로만 이루어진 열을 갖는 singular matrix가 된다. 이는 기저 함수 $u_j$가 해를 근사하는데에 어떠한 기여도 하지 않는다는 것을 의미하며, 그로인해 $u_j$의 계수 $a_j$가 어떤 값을 갖더라도 같은 근사가 됨을 의미한다.

이제 중요한 것은 $\mathcal W_h$와 $\mathcal U_h$를 어떻게 설정하는지이다.

### 명제1
$\mathcal{U}$가 다음과 같은 affine space임을 증명하여라.
$$ \mathcal{U} = \phi + \mathcal{U}_L $$

$$ \text{Where, } \phi \in \mathcal U, \ \mathcal{U}_L:= \{ u \in C^m(\Omega) \enspace | \enspace u = 0 \text{ on } \partial\Omega \} $$

**Proof**

$\partial\Omega$에서 0이 아닌 BC $g$가 주어졌다고 가정하자.
$$ u = g \neq 0 \quad \text{on } \partial\Omega $$

그러면 $u_1, u_2 \in \mathcal{U}$에 대해서 다음이 성립한다.  
$$ (u_1 + u_2)(\mathbf x) = u_1(\mathbf x) + u_2(\mathbf x) = 2g(\mathbf x) \Rightarrow u_1 + u_2 \notin \mathcal{U} \quad \mathbf x \in \partial\Omega $$

즉 $\mathcal{U}$는 덧셈에 대해 닫혀있지 않기 때문에 vector space가 될 수 없다. 

따라서, $\mathcal{U}$는 boundary에서 $0$을 만족하는 vector space와 BC를 만족하는 $\phi \in \mathcal U$의 합으로 나타낼 수 있다.
$$ \mathcal{U} = \phi + \mathcal{U}_L \quad\tiny\blacksquare $$

### 명제2
$\mathcal U$를 축소한 $\mathcal U_h$가 다음과 같음을 증명하여라. 
$$ \mathcal U_h := \phi + \mathcal U_{L_h} $$

$$ \text{Where, } \mathcal U_{L_h} = \text{span}(\{ u_1, \cdots, u_k \}) \le \mathcal U_L $$

**Proof**

명제1에 의해 $\mathcal{U}$는 다음과 같은 affine space가 된다.
$$ \mathcal{U} = \phi + \mathcal{U}_L $$

$$ \text{Where, } \phi \in \mathcal U, \ \mathcal{U}_L:= \{ u \in C^m(\Omega) \enspace | \enspace u = 0 \text{ on } \partial\Omega \} $$

따라서, $\mathcal U_L$을 finite dimension으로 축소하면 다음과 같다.
$$ \mathcal U_h := \phi + \mathcal U_{L_h} \quad\tiny\blacksquare $$


## Petrov-Galerkin method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_n \}$를 독립적으로 정의하는 방법을 `Petrov-Galerkin method`라고 한다.

결론적으로 Petrov-Galerkin method는 독립적으로 정의된 $\mathcal W_h$공간에서 weighted residual method를 만족하는 $u$를 $\mathcal U_h$ 공간에서 찾는 방법이다.

## Bubnov-Galerkin method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_n \}$를 동일하게 정의하는 방법을 `Bubnov-Galerkin method`라고 한다.  
$$ w_i = u_i $$

식(5)에 Bubnov-Galerkin method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.
$$ \text{find } \mathbf a \in \mathcal \R^n \quad s.t. \quad \int_\Omega u_ir \thinspace dV = 0  $$

$$ \text{Where, } r = \mathcal P(a_ju_j) + f(\mathbf x) $$

즉, $r$이 모든 $u_i$와 내적이 0이 되게 하는 $\mathbf a$를 찾는 것임으로, 이렇게 찾은 solution $u$는 $r$을 solution function space에 orthogonal하게 만드는 solution이다.

## Least square method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 다음과 같이 정의된 값을 쓰는 방법을 `least square method`라고 한다.  
$$ w_i = \frac{\partial r}{\partial a_i}, \quad (i = 1, \cdots, n)$$

식(5)에 least square method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.
$$ \begin{aligned} & \text{find } \mathbf a \in \R^k \quad s.t. \quad \int_{\Omega_i} \frac{\partial r}{\partial a_i} r \thinspace dV = 0 \quad \forall i \in (1, \cdots, n) \\ \Leftrightarrow \enspace & \text{find } \mathbf a \in \R^k \quad s.t. \quad \frac{\partial}{\partial a_i} \int_{\Omega_i} r^2 \thinspace dV = 0 \quad \forall i \in (1, \cdots, n)\end{aligned} $$  

$$ \text{Where, } r = \mathcal P(a_ju_j) + f(\mathbf x) $$

즉, residual 제곱의 합이 최소가 되게 하는 $\mathbf a$을 찾는 것임으로 least square method라고 한다.

## Point collocation method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 Dirac-delta 함수를 사용하는 방법을 `point collocation method`라고 한다.  
$$ w_i = \delta(\mathbf x - \mathbf x_i) $$

식(5)에 point collocation method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.
$$ \text{find } \mathbf a \in \R^k \quad s.t. \quad \mathcal r(\mathbf x_i) = 0, \quad i = 1, \cdots, n $$

$$ \text{Where, } r = \mathcal P(a_ju_j) + f(\mathbf x) $$

Dirac-delta 함수의 성질에 의해 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 solution은 collocation node로 불리는 $\mathbf x_i$점에서 residual을 0으로 만드는 즉, strong formulation을 만족시키는 solution이다.

## Subdomain collocation method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 계단 함수를 사용하는 방법을 `subdomain collocation method`라고 한다.  
$$ w_i = \begin{cases} 1 & \text{if } \mathbf x_i \in \Omega_i \\ 0 & \text{else} \end{cases}$$

식(5)에 subdomain collocation method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.
$$ \text{find } \mathbf a \in \R^k \quad s.t. \int_{\Omega_i} r \thinspace dV = 0, \quad i = 1, \cdots, n $$

$$ \text{Where, } r = \mathcal P(a_ju_j) + f(\mathbf x) $$

계단 함수의 성질에 의해 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 solution은 $\Omega_i$에서 residaul의 평균을 0으로 만드는 solution이다.