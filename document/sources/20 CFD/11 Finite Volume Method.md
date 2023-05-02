# Finite Volume Method
$\Omega$가 일정하다고 하자.

그러면 다음이 성립한다.

$$ \begin{aligned} & \diff{}{t} \int_{\Omega} q \thinspace dV + \int_{\partial\Omega} f \cdot dS = 0 \\\implies& \diff{}{t} \frac{1}{\Omega} \int_{\Omega} q \thinspace dV + \frac{1}{\Omega}\int_{\partial\Omega} f \cdot dS = 0 \\\implies& \diff{\bar{q}}{t} = - \frac{1}{\Omega}\int_{\partial\Omega} f \cdot dS  \end{aligned} $$
