`계수(order)`가 $m$인 `편미분방정식(partial differential equation; PDE)`이 다음과 같이 주어졌다고 하자.

$$ \begin{equation} \text{find } u \in \mathcal U \subset C^m(\Omega) \quad s.t. \quad \mathcal P[u] = 0 \quad \text{in} \quad \Omega \end{equation} $$

이 때, $\Omega \subset \R^d$이고 $\mathcal P(q)$는 PDE를 나타내는 $q$의 공간에 대한 미분항이 포함된 미분 연산자이며 $q(\mathbf x)$는 종속 변수이다.

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