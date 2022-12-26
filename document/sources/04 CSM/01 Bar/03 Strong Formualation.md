# Strong Formualation
Bar에 대한 BVP의 strong formulation은 다음과 같다.

$$ \text{find } u \in \mathcal{U} \st \frac{\partial}{\partial x}\left(EA\frac{\partial u}{\partial x}\right) + p(x) = 0 $$

$$ \text{Where, } \mathcal U := \{ u \in C^2(\Omega) \enspace | \enspace u \text{ satisfies BC on } \partial\Omega \} $$

## Example
만약 $E$와 $A$가 상수값이라면 다음이 성립한다.

$$ \begin{aligned} & \frac{\partial}{\partial x}\left(EA\frac{\partial u}{\partial x}\right) + p(x) = 0 \\\implies& \frac{\partial u}{\partial x} = -\frac{1}{EA} \int p(x)\thinspace dx + c_1 \\\implies& u = -\frac{1}{EA} \int \left(\int p(x)\thinspace dx\right)\thinspace dx + c_1x + c_2 \end{aligned} $$

이 떄, 문제에 주어진 2개의 경계조건을 이용하여 $c_1,c_2$를 결정할 수 있다.