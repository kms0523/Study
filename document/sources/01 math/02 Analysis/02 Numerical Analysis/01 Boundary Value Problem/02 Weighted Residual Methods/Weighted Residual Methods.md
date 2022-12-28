# Weighted Residual Methods


. 


## Functional Form

만약, $\mathcal P$가 linear operator면 $B_r$은 bilinear map이 되며 식(5)는 다음과 같이 단순해 진다.

$$ \text{find } \mathbf a \in \R^n \st B_r(w_i, u_j) a_j = l_r(w_i) - B_r(w_i,\phi), \enspace i = 1, \cdots, n  $$

이를 행렬 형태로 나타내면 다음과 같다.

$$ \begin{bmatrix} B(w_1,u_1) & \cdots & B(w_1,u_n) \\ \vdots & \ddots & \vdots \\ B(w_n,u_1) & \cdots & B(w_n,u_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) - B(w_1, \phi) \\ \vdots \\ l(w_n) - B(w_n, \phi) \end{bmatrix} $$

만약 $u_j$의 $m$계 도함수가 0이라면 $B(w_i,u_j) = 0$이 되고 행렬은 0으로만 이루어진 열을 갖는 singular matrix가 된다. 이는 기저 함수 $u_j$가 해를 근사하는데에 어떠한 기여도 하지 않는다는 것을 의미하며, 그로인해 $u_j$의 계수 $a_j$가 어떤 값을 갖더라도 같은 근사가 됨을 의미한다.

이제 중요한 것은 $\mathcal W_h$와 $\mathcal U_h$를 어떻게 설정하는지이다.

> Reference  
> [Note - M. J. Zahr](https://mjzahr.github.io/content/ame40541/spr20/ch03-wres-solo.pdf)

#### 명제1
다음을 증명하여라.

$$\mathcal{U_b} \text{ is not a vector space }$$

**Proof**

$\partial\Omega$에서 0이 아닌 BC $g$가 주어졌다고 가정하자.

$$ u = g \neq 0 \quad \text{on } \partial\Omega $$

그러면 $u_1, u_2 \in \mathcal{U_b}$가 있을 때, $\forall x \in \partial\Omega$에서 다음이 성립한다.  

$$ (u_1 + u_2)(x) = u_1(x) + u_2(x) = 2g(x) $$

따라서, 다음이 성립한다. 

$$ u_1 + u_2 \notin \mathcal{U_b} $$

즉 $\mathcal{U_b}$는 덧셈에 대해 닫혀있지 않기 때문에 vector space가 될 수 없다. 


#### 명제2
다음을 증명하여라.

$$ \forall u \in \mathcal{U_b}, \quad \exist u_0 \in \mathcal{U_0} \st u = \phi + \mathcal{u_0} $$

**Proof**

$\mathcal{U}$는 boundary에서 $0$을 만족하는 vector space와 BC를 만족하는 $\phi \in \mathcal U$의 합으로 나타낼 수 있다.
$$ \mathcal{U} = \phi + \mathcal{U}_L \quad\tiny\blacksquare $$

> Reference  
> [Note - M. J. Zahr](https://mjzahr.github.io/content/ame40541/spr20/ch03-wres-solo.pdf)

### 명제2
$\mathcal U$를 축소한 $\mathcal U_h$가 다음과 같음을 증명하여라. 

$$ \mathcal U_h := \phi + \mathcal U_{L_h} $$

$$ \text{Where, } \mathcal U_{L_h} = \span(\{ u_1, \cdots, u_k \}) \le \mathcal U_L $$

**Proof**

명제1에 의해 $\mathcal{U}$는 다음과 같은 affine space가 된다.

$$ \mathcal{U} = \phi + \mathcal{U}_L $$

$$ \text{Where, } \phi \in \mathcal U, \ \mathcal{U}_L:= \{ u \in C^m(\Omega) \enspace | \enspace u = 0 \text{ on } \partial\Omega \} $$

따라서, $\mathcal U_L$을 finite dimension으로 축소하면 다음과 같다.
$$ \mathcal U_h := \phi + \mathcal U_{L_h} \quad\tiny\blacksquare $$

> Reference  
> [Note - M. J. Zahr](https://mjzahr.github.io/content/ame40541/spr20/ch03-wres-solo.pdf)

## Petrov-Galerkin method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_n \}$를 독립적으로 정의하는 방법을 `Petrov-Galerkin method`라고 한다.

결론적으로 Petrov-Galerkin method는 독립적으로 정의된 $\mathcal W_h$공간에서 weighted residual method를 만족하는 $u$를 $\mathcal U_h$ 공간에서 찾는 방법이다.

## Bubnov-Galerkin method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_n \}$를 동일하게 정의하는 방법을 `Bubnov-Galerkin method`라고 한다.  

$$ w_i = u_i $$

식(5)에 Bubnov-Galerkin method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.

$$ \text{find } \mathbf a \in \mathcal \R^n \st \int_\Omega u_ir \thinspace dV = 0  $$

$$ \text{Where, } r = \mathcal P(a_ju_j) + f(\mathbf x) $$

즉, $r$이 모든 $u_i$와 내적이 0이 되게 하는 $\mathbf a$를 찾는 것임으로, 이렇게 찾은 solution $u$는 $r$을 solution function space에 orthogonal하게 만드는 solution이다.

## Least square method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 다음과 같이 정의된 값을 쓰는 방법을 `least square method`라고 한다.  

$$ w_i = \frac{\partial r}{\partial a_i}, \quad (i = 1, \cdots, n)$$

식(5)에 least square method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.

$$ \begin{aligned} & \text{find } \mathbf a \in \R^k \st \int_{\Omega_i} \frac{\partial r}{\partial a_i} r \thinspace dV = 0 \quad \forall i \in (1, \cdots, n) \\ \iff \enspace & \text{find } \mathbf a \in \R^k \st \frac{\partial}{\partial a_i} \int_{\Omega_i} r^2 \thinspace dV = 0 \quad \forall i \in (1, \cdots, n)\end{aligned} $$  

$$ \text{Where, } r = \mathcal P(a_ju_j) + f(\mathbf x) $$

즉, residual 제곱의 합이 최소가 되게 하는 $\mathbf a$을 찾는 것임으로 least square method라고 한다.

## Point collocation method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 Dirac-delta 함수를 사용하는 방법을 `point collocation method`라고 한다.  

$$ w_i = \delta(\mathbf x - \mathbf x_i) $$

식(5)에 point collocation method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.

$$ \text{find } \mathbf a \in \R^k \st \mathcal r(\mathbf x_i) = 0, \quad i = 1, \cdots, n $$

$$ \text{Where, } r = \mathcal P(a_ju_j) + f(\mathbf x) $$

Dirac-delta 함수의 성질에 의해 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 solution은 collocation node로 불리는 $\mathbf x_i$점에서 residual을 0으로 만드는 즉, strong formulation을 만족시키는 solution이다.

## Subdomain collocation method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_k \}$를 독립적으로 정의하되 $\mathcal W_h$의 기저함수로 계단 함수를 사용하는 방법을 `subdomain collocation method`라고 한다.  

$$ w_i = \begin{cases} 1 & \text{if } \mathbf x_i \in \Omega_i \\ 0 & \text{else} \end{cases}$$

식(5)에 subdomain collocation method를 적용하고 functional을 풀어서 다시 정리하면 다음과 같다.

$$ \text{find } \mathbf a \in \R^k \quad s.t. \int_{\Omega_i} r \thinspace dV = 0, \quad i = 1, \cdots, n $$

$$ \text{Where, } r = \mathcal P(a_ju_j) + f(\mathbf x) $$

계단 함수의 성질에 의해 $\mathcal W_h$공간에서 weighted residual formulation을 만족하는 solution은 $\Omega_i$에서 residaul의 평균을 0으로 만드는 solution이다.