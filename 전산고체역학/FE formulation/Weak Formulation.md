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

또한, weak formulation에 natural BC가 적용되어 있음으로 solution function space에서 natural BC 요구조건을 완화할 수 있다.

따라서, Solution function space의 요구조건을 완화해서 $\mathcal U$를 확장하면 다음과 같다.
$$ \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad \int_\Omega a\frac{dw}{dx}\frac{du}{dx} + wcu \thinspace dV = w(L)Q_L - wa\frac{du}{dx} \bigg|_{x = 0} + \int_\Omega wf \thinspace dV$$

$$ \text{Where, } \mathcal U_W := \left\{ u \in C^1(\Omega) \enspace \bigg| \enspace u(0) = u_0 \right\} $$

위 식이 Weak formulation이라고 불리는 이유는 바로 solution space의 regularity 요구사항을 약화시켰기 때문이다. 

$\mathcal U_W$는 $\mathcal U$보다 더 약한 regularity를 요구하기 때문에 strong formulation과 동치가 아니며 weak formulation이 보다 더 일반적인 형태이다. 예를들어, weak formulation의 해가 $u \notin C^2(\Omega)$이면 strong formulation은 정의조차 되지 않는다.


### 참고1
Solution function space에 natural BC를 적용할 경우 반드시 natural BC를 만족하는 해를 구하게 된다. 따라서 이를 강하게 natural BC를 적용하였다고 표현한다. 하지만 weak formulation에서는 natural BC를 식에 적용하고 그 대신에 solution function space의 제약조건을 약화시켰기 때문에 약하게 적용되었다고 표현한다. 

실제로, solution function space가 충분히 넓지 않은경우 weak formulation을 통해 구한 solution은 natural BC를 만족하지 않으며 그 예시는 model problem 4,8번을 통해 확인해 볼 수 있다.

### 참고2
Weak formulation은 functional $B,l$을 이용해 다음과 같이 간단하게 나타낼 수 있다.

$$ \begin{equation} \text{find } u \in \mathcal U_W \quad s.t. \quad \forall w \in \mathcal W, \quad B(w,u) = l(w) \end{equation} $$

$$ \begin{gathered} \text{Where, } B(w,u) :=  \int_\Omega a\frac{dw}{dx}\frac{du}{dx} + wcu \thinspace dV + wa\frac{du}{dx} \bigg|_{x = 0} \\ \quad l(w) := w(L)Q_L + \int_\Omega wf \thinspace dV \end{gathered} $$


## Dimensional Reduction
무한차원 함수공간인 $\mathcal W$에 있는 모든 함수에 대해 weak formulation를 만족하는 $u$를 무한차원 함수공간인 $\mathcal U_W$에서 찾는 일은 너무 어렵다.

따라서 test function space와 solution function space를 각 각 유한차원 함수 공간으로 축소하여 문제를 단순화해보자.

Weighted Residual formulation을 dimensional reduction했을 때와 동일한 과정을 거치면, weak formulation는 다음과 같이 간단해 진다.
$$ \text{find } \mathbf a \in \R^n \quad s.t. \quad B_W(w_i, \phi + a_ju_j) = l_W(w_i), \enspace i = 1, \cdots, n  $$

linear pde이기 때문에 이를 행렬 형태로 나타내면 다음과 같다.
$$ \begin{bmatrix} B_W(w_1,u_1) & \cdots & B_W(w_1,u_n) \\ \vdots & \ddots & \vdots \\ B_W(w_n,u_1) & \cdots & B_W(w_n,u_n) \end{bmatrix} \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} = \begin{bmatrix} l_W(w_1) - B(w_1, \phi) \\ \vdots \\ l_W(w_n) - B(w_n, \phi) \end{bmatrix} $$

이제 중요한 것은 $\mathcal W_h$와 $\mathcal U_h$를 어떻게 결정하는지이다.

## Petrov-Galerkin method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_n \}$를 독립적으로 정의하는 방법을 `Petrov-Galerkin method`라고 한다.

## Bubnov-Galerkin method

축소된 선형공간 $\mathcal W_h, \mathcal U_h$의 기저함수 $\{ w_1, \cdots, w_n \}, \{ u_1, \cdots, u_n \}$를 동일하게 정의하는 방법을 `Bubnov-Galerkin method`라고 한다.  
$$ w_i = u_i $$
