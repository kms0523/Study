# Distortion Strain Energy Density
미소 변위, 변형률을 가정하고 선형 탄성재료의 경우 다음과 같은 strain energy function을 갖는다.
$$ U = \frac{1}{2} \sigma : \epsilon $$

이를 $\tilde \sigma, \tilde \epsilon$로 나타내면 다음과 같다.
$$ \begin{aligned} U &= \frac{1}{2} \sigma : \epsilon \\ &= \frac{1}{2}(\tilde \sigma + \sigma_m I) : (\tilde \epsilon + \epsilon_m I) \\ &= \frac{1}{2} (\tilde \sigma : \tilde \epsilon + 3\sigma_m \epsilon_m) \end{aligned} $$

Volume-chainging과 관련된 항을 제외한 strain energy density를 다음과 같이 정의한다.
$$ U_d = \frac{1}{2}(\tilde \sigma : \tilde \epsilon ) $$

이 때, $U_d$를 `Distortion strain energy density`라 한다.

### 명제1
다음을 증명하여라.
$$ U_d = \frac{1}{4\mu}(\tilde \sigma : \tilde \sigma) $$

**Proof**

$\tilde \sigma$의 정의에 의해 다음이 성립한다.
$$ \tilde \epsilon = \frac{1}{2\mu} \tilde \sigma $$

따라서 다음이 성립한다.
$$ \begin{aligned} U_d &= \frac{1}{2}(\tilde \sigma : \tilde \epsilon ) \\ &= \frac{1}{4\mu}(\tilde \sigma : \tilde \sigma) \quad\tiny\blacksquare \end{aligned} $$

### 명제2
다음을 증명하여라.
$$ U_d = \mu(\tilde \epsilon : \tilde \epsilon) $$

**Proof**

$\tilde \sigma$의 정의에 의해 다음이 성립한다.
$$ \tilde \sigma = 2\mu \tilde \epsilon $$

따라서 다음이 성립한다.
$$ \begin{aligned} U_d &= \frac{1}{2}(\tilde \sigma : \tilde \epsilon ) \\ &= \mu(\tilde \epsilon : \tilde \epsilon) \quad\tiny\blacksquare \end{aligned} $$


### 명제3
1D Tensile test에서 항복응력이 $\sigma_Y$라고 하자.

항복응력이 가해졌을 때 $U_d$가 다음과 같음을 증명하여라.
$$ U_d = \frac{1}{6\mu}\sigma_Y^2 $$

**Proof**

$\tilde \sigma$를 $\sigma$로 나타내면 다음과 같다.
$$ \tilde \sigma = \sigma - \sigma_mI = \begin{bmatrix} \frac{2}{3}\sigma_Y & 0 & 0 \\ 0 & -\frac{1}{3}\sigma_Y & 0 \\ 0 & 0 & -\frac{1}{3}\sigma_Y \end{bmatrix} $$

따라서 다음이 성립한다.
$$ U_d = \frac{1}{4\mu}(\tilde \sigma : \tilde \sigma) = \frac{1}{4\mu} \frac{2}{3} \sigma_Y^2 = \frac{1}{6\mu}\sigma_Y^2 \quad\tiny\blacksquare $$