# BVP
Bar의 displacement based governing equation은 다음과 같다.

$$ \frac{\partial}{\partial x}\left(EA\frac{\partial u}{\partial x}\right) + p(x) = 0 $$

displacement based governing equation는 $u$의 2계 미분방정식임으로 이를 풀기 위해서는 두개의 `경계조건(boundary condition; BC)`이 필요하다.

## Model

다음과 같은 model을 고려해보자.

```{figure} _image/0201
```

그림에 나타난 model의 경계조건은 다음과 같다.

$$ \begin{aligned} x=0 \quad& u=0 \\ x=L \quad& \sigma_{xx}A = EA \frac{\partial u}{\partial x} = f \end{aligned} $$

이 때, Modeling domain을 $\Omega := [0,L] \subseteq \R$라고 하자.

## Strong Formualation
Bar에 대한 BVP의 strong formulation은 다음과 같다.

$$ \text{find } u \in \mathcal{U} \st \frac{\partial}{\partial x}\left(EA\frac{\partial u}{\partial x}\right) + p(x) = 0 $$

$$ \text{Where, } \mathcal U := \{ u \in C^2(\Omega) \enspace | \enspace u \text{ satisfies BC on } \partial\Omega \} $$

### Example
만약 $E$와 $A$가 상수값이라면 다음이 성립한다.

$$ \begin{aligned} & \frac{\partial}{\partial x}\left(EA\frac{\partial u}{\partial x}\right) + p(x) = 0 \\\implies& \frac{\partial u}{\partial x} = -\frac{1}{EA} \int p(x)\thinspace dx + c_1 \\\implies& u = -\frac{1}{EA} \int \left(\int p(x)\thinspace dx\right)\thinspace dx + c_1x + c_2 \end{aligned} $$

이 떄, model에 주어진 2개의 경계조건을 이용하여 $c_1,c_2$를 결정할 수 있다.

## Weighted Residual Formulation
Bar의 weighted residual formlation은 다음과 같다.
$$ \text{find } u \in \mathcal{U} \st \forall w \in C^\infty_0(\Omega), \quad \int_\Omega \left( \frac{\partial}{\partial x}\left(EA\frac{\partial u}{\partial x}\right) + p(x) \right) w \thinspace dV = 0 $$

## Weak Formulation
Bar의 weighted residual formlation의 첫번째 항에 부분적분법을 적용하면 다음과 같다.
$$ \text{find } u \in \mathcal{U} \st \forall w \in C^\infty_0(\Omega), \quad \int_\Omega \left( \frac{\partial}{\partial x}\left(EA\frac{\partial u}{\partial x}\right) + p(x) \right) w \thinspace dV = 0 $$

### 명제1

**Proof**

$$ \int_\Omega \left( \frac{\partial}{\partial x}\left(EA\frac{\partial u}{\partial x}\right) + p(x) \right) w \thinspace dV $$


Bar의 weak formulation은 다음과 같다.



