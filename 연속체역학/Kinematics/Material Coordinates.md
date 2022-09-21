# Material Coordinates
운동하는 연속체 한 점의 위치가 시간 $t$에 대한 벡터 함수 $\mathbf p$로 주어진다고 하자.
$$ \mathbf x = \mathbf p(t) $$

연속체의 운동을 표현하기 위해 위의 표현법을 사용해서 연속체를 이루는 모든 점들의 위치를 나타내면 다음과 같다.
$$ \mathbf x_i = \mathbf p_i(t), \quad i=1, \cdots, N, \cdots $$

하지만 연속체 내부에는 무한한 점이 포함되어 있기 때문에 점마다 번호를 부여하는 방법은 한계가 있다. 따라서 이러한 한계를 극복하기 위해 기준 시간 $t_0$때 위치를 가지고 연속체의 한 점을 표현하는 `물질좌표(material coordinates)` $\bm X$를 도입한다.
$$ X^i = p^i(\bm X,t_0) $$

물질좌표는 연속체의 특정 한 점을 표현하는 방법이며, 물질좌표를 이용해서 연속체를 이루는 모든 점들의 위치를 나타내면 다음과 같다.
$$ \begin{equation} \mathbf x = \mathbf p(\bm X,t) \quad \text{with} \quad \bm X = \mathbf p(\bm X, t_0) \in \Omega_0 \end{equation}  $$

$\Omega_0$은 $t_0$일 때 연속체를 이루는 모든 점들이 차지하는 위치의 집합이다.

### 참고
$\Omega_0$를 `undeformed configuration` 혹은 `reference configuration`이라고 한다.

> Reference  
[book] (Lai et al) Introduction to Continuum Mechanics Chapter3.1