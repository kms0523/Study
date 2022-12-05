### Theorem 1

실수 $x \in \R$을 정규화 된 부동수소점 형식으로 가장 가깝게 근사한 값을 $\hat{x}$라 하자.

이 때, 밑수(base)를 $\beta$, 정밀도(precision)을 $p$, 그리고 지수를 $e$라 하면 다음이 성립한다.

$$ |x-\hat{x}| \le \epsilon \times \beta ^e $$
$$ \frac{\epsilon}{\beta} \le \frac{|x-\hat{x}|}{|x|} \le \epsilon $$
$$ \epsilon \equiv \frac{1}{2}ulp, \quad ulp \equiv \beta^{-(p-1)} $$
$$ \epsilon := \text{machine error}, \quad ulp := \text{unit in last place} $$

#### proof
$x$보다 작은 부동소수점 수의 집합을 $\hat{f}^-$라 하고 $\hat{f}^-$의 상한을 $x^-$라 하자.

이 때, $x^+$을 $x^-$의 바로 다음 부동소수점이라하면 다음과 같이 표현할 수 있다.

$$ x^+ = x^- + ulp \times \beta ^e. $$

$x$에 가장 가까운 근사값 $\hat{x}$는 $x^+$와 $x^-$중 하나의 값이며, $|x-\hat{x}|$는 다음의 상한을 갖는다.

$$ \begin{aligned}
|x-\hat{x}| & \le \frac{1}{2} ulp \times \beta^e \\
& \le \epsilon \times \beta^e.
\end{aligned} $$

또한, $x$가 정규화된 부동소수점 형식으로 표현되어 있음으로 다음의 유계를 갖는다.

$$ 1.0 \times \beta^e \le |x| \le \beta \times \beta^e. $$

따라서 $|x-\hat{x}| / |x|$는 다음의 유계를 갖는다. 

$$ \frac{\epsilon}{\beta} \le \frac{|x-\hat{x}|}{|x|} \le \epsilon. \quad {_\blacksquare} $$