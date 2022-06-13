# Strong formulation
`계수(order)`가 $m$인 `편미분방정식(partial differential equation; PDE)`이 다음과 같이 주어졌다고 하자.
$$ \begin{equation} \text{find } u \in \mathcal U \subset C^m(\Omega) \quad s.t. \quad \mathcal P[u] = 0 \quad \text{in }  \Omega \end{equation} $$

$\Omega \subset \R^d$이고 $\mathcal P : C^m(\Omega) \rightarrow C^0(\Omega)$는 계수가 $m$인 `미분 연산자(differential operator)`이며 $\mathcal U$는 `해 공간(solution space)`이며 다음과 같이 정의된다.
$$ \mathcal U := \{ u \in C^m(\Omega) \enspace | \enspace u \text{ satisfies boundary condition on } \partial\Omega \} $$

식(1)은 $\partial\Omega_E \subset \partial\Omega$따라 essential BC와 $\partial\Omega_N \subset \partial\Omega$따라 natural BC가 주어져있으며 $\partial\Omega = \partial\Omega_E \cup \partial\Omega_N$ 이다.

식(1)을 PDE의 `strong formulation`이라 하는데 이는 strong formulation의 해는 $\Omega$의 모든 점에서 PDE를 만족시켜야하며 $m$번 미분 가능해야된다는 엄격한 `정규성(regularity)`을 만족시켜야하기 때문이다.

여기서 주목할만한 점은 BC을 만족시켜야 하기 때문에 일반적으로 $\mathcal U$는 선형 공간이 아니다.
예를 들어 $\partial\Omega$에서 0이 아닌 BC $g$가 주어졌다고 해보자.
$$ u = g \neq 0 \quad \text{on } \partial\Omega  $$

그러면 $u_1, u_2 \in \mathcal{U}$에 대해서 다음이 성립한다.
$$ (u_1 + u_2)(x) = u_1(x) + u_2(x) = 2g(x) \Rightarrow u_1 + u_2 \notin \mathcal{U} \quad x \in \partial\Omega $$

즉 $\mathcal{U}$는 덧셈에 대해 닫혀있지 않기 때문에 선형공간이 될 수 없다.

# Weighted residual formulation
식(1)의 weighted residual formulation은 다음과 같이 주어진다.
$$ \begin{equation} \text{find } u \in \mathcal U \subset C^m(\Omega) \quad s.t. \quad \forall w \in C^\infty_c(\Omega), \quad \int_\Omega w\mathcal P[u] \thinspace dV = 0  \end{equation} $$

이 떄, $w$는 `테스트 함수(test function)`라한다.

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

# weighted residual methods
식(2)로 부터 weighted residual method 수치기법을 유도해보자.

먼저, 문제를 단순하게 하기 위해 테스트 함수 공간을 $C^\infty_c(\Omega)$에서 $C^\infty(\Omega)$로 확장하자. $C^\infty_c(\Omega) \subset C^\infty(\Omega)$이기 때문에 테스트 함수 공간을 바꾸어도 strong formulation과 동치이다.

자명하게 $C^\infty(\Omega)$공간에 있는 모든 함수에 대해 수치적으로 식(2)를 계산하는 것은 불가능하다. 따라서 테스트 함수 공간을 $n$차원 부분공간인 $\mathcal{W} \subset C^\infty(\Omega)$으로 축소하여 문제를 단순화해보자.

테스트 함수 공간이 $\mathcal W$로 축소됨에 따라 residual formulation은 더이상 strong formulation과 동치가 아니며, 근사값이 되게 된다.

$\cal W$의 기저 함수를 $\{ w_1, \cdots, w_n \}$이라 하면 식(2)는 다음과 같이 간단해 진다.
$$ \begin{equation} \text{find } u \in \mathcal U \subset C^m(\Omega) \quad s.t. \quad \int_\Omega w_i\mathcal P[u] \thinspace dV = 0 \quad (i = 1, \cdots, n)  \end{equation} $$

테스트 함수 공간을 $n$차원 공간으로 근사함으로써 $n$개의 기저 함수에 대해서만 확인하면 되는 문제로 단순화 하였지만 아직 무한차원 함수공간인 $\cal U$를 탐색해야 되는 어려움이 남아있다.



---

PDE를 나타내는 $q$의 공간에 대한 미분항이 포함된 미분 연산자이며 $q(\mathbf x)$는 종속 변수이다.

$q$를 직접 구하기 어렵기 때문에 $q$의 근사해인 $q_h$를 구해보자. 근사해를 식(1)에 대입하면 다음과 같다.

$$ \begin{equation} \mathcal L(q_h) + f = r \quad \text{in} \quad \Omega \end{equation} $$

이 떄, $r(\mathbf x)$은 `잔여항(residual)`이다.

만약, $r=0$이면 $q_h$는 PDE를 만족하는 엄밀해가 된다. 따라서 $r=0$을 만족하는 $q_h$가 가장 좋은 근사해이다. 

$$ \text{find } q_h \quad s.t. \quad r = 0 $$

하지만 이는 식(1)을 직접 푸는 것과 똑같은 일이 된다. 즉, 매우 어렵다. 따라서 잔여항의 가중평균이 0이 되는 $q_h$를 찾는 문제로 문제를 단순화 시켜보자.

$$ \text{find } q_h \quad s.t. \quad \int_\Omega rw \thinspace d\Omega = 0 $$

이 때, $w(\mathbf x)$는 임의의 가중함수이다. 

PDE의 엄밀해를 대입해보면 PDE 엄밀해 또한 단순화된 문제의 해임을 알수있다. 따라서 단순화된 문제의 해는 엄밀해를 포함하고 있다.

## 참고
[Function space - Wiki](https://en.wikipedia.org/wiki/Function_space#Functional_analysis  )