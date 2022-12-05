# Summary of the govering equations

## The nonlinear theory

### The basic kinematics
$S^2 := \{ t \in \R^3 \enspace | \enspace \Vert t \Vert = 1 \}$를 `단위 구(unit sphere)`, $T_tS^2 := \{ w \in \R^3 \enspace | \enspace t \cdot w = 0 \}$을 $t \in S^2$에서의 `접평면(tangent space)`라 하자.

shell의 configuration sppce를 $\mathcal C$라 하면, 다음과 같이 정의된다.
$$ \mathcal C := \{ \Phi := (\varphi, t) : \mathcal A \rightarrow \R^3 \times S^2 \} $$

이 때, $\mathcal A \subset \R^2$은 compact이며, boundary $\partial \mathcal A$를 갖는다. 이 때, $\partial_\varphi \mathcal A \subset \partial \mathcal A$는 displacement가 $\partial_t \mathcal A \subset \partial \mathcal A$는 rotation이 주어진 boudnary이다.

임의의 shell의 configuration을 $\mathcal S$라 할 때, $\mathcal S$가 다음과 같이 정의된다고 가정하자.
$$ \mathcal S := \{ x \in \R^3 \enspace | \enspace x = \varphi + \xi t \text{ where } (\varphi,t) \in \mathcal C \text { and } \xi \in [h^-, h^+] \} $$

이 때, shell의 두께는 $h = h^+ - h^-$로 주어지고, $\varphi : \mathcal A \rightarrow \R^3$은 shell의 mid-surface를 정의하며, $t : \mathcal A \rightarrow S^2$이다.

### Momentum balance equations
local momentum equation은 stress resultant와 stress가 couple된 형태로 나타난다.
$$ \frac{1}{j} \frac{\partial jn^\alpha}{\partial \xi^\alpha} + n = \rho \frac{\partial^2 \varphi}{\partial t^2}  $$

$$ \frac{1}{j} \frac{\partial jm^\alpha}{\partial \xi^\alpha} - l + m = I_\rho + t $$