

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




# Model Problem5
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d^2u}{dx^2} + u -1 = 0 \quad \text{in} \enspace \Omega := [0,1] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 1 \enspace \land \enspace u'(1) = 1 \} $$

## Weak formulation
$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,u) = l(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } B : \mathcal W \times \mathcal U_W \rightarrow \R \quad s.t. \quad (w,u) \mapsto \int_\Omega \frac{dw}{dx}\frac{du}{dx} - w(u-1) \thinspace dV \\ l : \mathcal W \rightarrow \R \quad s.t. \quad w \mapsto w(1) \\ \mathcal U_W := \{ u \in C^1(\Omega) \enspace | \enspace u(0) = 1 \} \\ \mathcal W := \{ w \in C^\infty(\Omega) \enspace | \enspace w(0) = 0 \} \end{gathered} $$

$\mathcal U_W$는 $\mathcal U_s$에서 regularity를 약화시키고, natural BC가 equation에 impose 되어 있음으로 natural BC 조건을 배제한 공간이다.

$\mathcal W$는 $C^\infty_c(\Omega)$에서 natural BC를 식에 impose 시키기 위해서 natural BC에서는 0이 되지 않게 조건을 완화한 공간이다.

## Ritz method
test function space $\mathcal W$는 $n$차원 vector space $\mathcal W_h$로 축소하고 solution function space $\mathcal U_W$는 $n$차원 affine space $\mathcal U_{W_h}$로 축소한다.

$\mathcal U_{W_h}$의 associated vector space $\mathcal U_{L_h}$의 기저는 $\mu = \{ \mu_1, \cdots, \mu_n \}$이고 $\phi \in \mathcal U_W$ 일 때, Bodunov-Galerkin method를 적용하면 식(12)는 다음과 같이 간단해진다.
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B(\mu_i, \phi + a_j \mu_j) = l(\mu_i) \quad i = 1, \cdots, n $$

이 때, $n=1, \phi = 1$로 두고 $\mu_1 = x - 2$이라하면 다음이 성립한다.
$$ u \in \mathcal U_{W_h} \Rightarrow u = \phi + a_1u_1 $$

$$ \text{find } a \in \R \quad s.t. \quad \int_\Omega \frac{d}{dx}(\phi + a_1u_1)\frac{du_1}{dx} \thinspace dV + u_1(0) = 0 $$


$$ \text{find } a \in \R \quad s.t. \quad a_1\int_\Omega \frac{du_1}{dx}\frac{du_1}{dx} \thinspace dV = - u_1(0) - \frac{d\phi}{dx} $$

이 때, 주의할 점은 $\mathcal U_{L_h}$는 $\partial\Omega_E$에서 homogeneous인 함수를 모아 놓은 vector space이다. 즉, 이 문제에서는 $u(2) = 1$을 만족하는 함수를 모아 놓은 vector space임으로 

## FEM method
$$ u \in \mathcal U_{W_h} \Rightarrow u = b_1n_1 + b_2n_2 $$




# Model Problem7
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

# Model Problem8
$$ \text{find } u \in \mathcal U_s \quad s.t. \quad \frac{d}{dx} \bigg( e^x \frac{du}{dx} \bigg) - \sin x  = 0 \quad \text{in} \enspace \Omega := [0,\pi / 2] \subset \R $$

$$ \text{Where, } \mathcal U_s := \{ u \in C^2(\Omega) \enspace | \enspace u(0) = 1 \enspace \land \enspace u'(\pi / 2) = 0 \} $$

exact solution은 $u = \frac{1}{2}(1 + e^{-x}(\cos x - \sin x))$이다.

> 참고  
> [note] (M. J. Zahr) 3.Weighted residual methods Exaxmple 3.2

## Weighted residual formulation
$$ \text{find } a \in \R^k \quad s.t. \quad B(w_i,\phi + a_ju_j) = l(w_i) $$

$$ \begin{aligned} \text{Where, } & i = 1,\cdots,n, \enspace j = 1,\cdots,k \\& \phi \in \mathcal{U}_s \\& u_i \in \{ u \in C^2(\Omega) \enspace | \enspace u=0 \text{ on } \partial\Omega_E, \enspace u'=0 \text{ on } \partial\Omega_N \} \\& B(w,u) := \int_\Omega w e^x \bigg( \frac{du}{dx} + \frac{d^2u}{dx^2} \bigg) \thinspace dV \\& l(w) := \int_\Omega w\sin{x} \thinspace dV \end{aligned} $$

## Weak formulation
$$ \text{find } a \in \R^k \quad s.t. \quad B(w_i,\phi + a_ju_j) = 0 $$

$$ \begin{aligned} \text{Where, } & i = 1,\cdots,n, \enspace j = 1,\cdots,k \\& \exist w_i \quad s.t. \quad w(\pi/2) \neq 0 \\& \phi \in \{ u \in C^1(\Omega) \enspace | \enspace u \text{ staisfy essential BC } \} \\& u_i \in \{ u \in C^1(\Omega) \enspace | \enspace u=0 \text{ on } \partial\Omega_E \} \\& B(w,u) := - e^x w \frac{du}{dx} \bigg |_{x = 0} - \int_\Omega e^x\frac{dw}{dx}\frac{du}{dx} \thinspace dV \\& l(w) := \int_\Omega w\sin{x} \thinspace dV \end{aligned} $$

## Matrix form
$B$가 bi-linear 임으로
$$ \text{find } a \in \mathcal \R^k \quad s.t. \quad a_jB(w_i,u_j) = l(w_i) - B(w_i, \phi) $$

행렬식으로 나타내면
$$ \begin{bmatrix} B(w_1,u_1) & \cdots & B(w_1,u_n) \\ \vdots & \ddots & \vdots \\ B(w_n,u_1) & \cdots & B(w_n,u_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l(w_1) - B(w_1, \phi) \\ \vdots \\ l(w_n) - B(w_n, \phi) \end{bmatrix} $$

## 참고
* WF의 경우 $\phi = 1, n=2, u_i = x^i$로 두면 natural BC를 만족하지 않는다.

# Model Problem9
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

