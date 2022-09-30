# Deviatoric Strain
미소 변위, 변형률을 가정하면 volume-chainging은 다음과 같이 정의된다.
$$ \frac{\Delta V}{V} = \text{tr}(\epsilon) $$

$$ \text{Where, } \lambda, \mu \text{ are Lame's constants} $$

따라서 volume-chainging이 $0$이 되게 $\tilde \epsilon$을 다음과 같이 정의한다.
$$ \tilde \epsilon := \epsilon - \epsilon_m I $$

$$ \text{Where, } \epsilon_m = \frac{1}{3}\text{tr}(\epsilon) $$

이 떄, $\epsilon_mI$를 $\epsilon$의 volume-chainging part, $\epsilon_m$을 volumetric strain이라고 하며 $\tilde \epsilon$를 $\epsilon$의 volume-preserving part 또는 `deviatoric strain`이라고 한다. 

### 명제
Infinitesimal strains $\epsilon_{1,2}$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ \widetilde{\epsilon_1 + \epsilon_2} = \tilde \epsilon_1 + \tilde \epsilon_2 $$

**Proof**

Deviatoric strain의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \widetilde{\epsilon_1 + \epsilon_2} &= \epsilon_1 + \epsilon_2 - \frac{1}{3}\text{tr}(\epsilon_1 + \epsilon_2)I \\&= \epsilon_1 - \frac{1}{3} \text{tr}(\epsilon_1)I + \epsilon_2 - \frac{1}{3} \text{tr}(\epsilon_2)I \\&= \tilde \epsilon_1 + \tilde \epsilon_2 \quad {_\blacksquare}\end{aligned} $$


# Deviatoric Stress
미소 변위, 변형률을 가정하고 등방성 선형 탄성재료의 경우 구성방정식은 다음과 같다.
$$ \sigma = \lambda \text{tr}(\epsilon) I + 2\mu \epsilon $$

구성방정식을 $\tilde \epsilon$으로 나타내면 다음과 같다.
$$ \begin{aligned} \sigma &= \lambda \text{tr}(\epsilon) I + 2\mu \epsilon \\ &= 3 \lambda \epsilon_m I + 2\mu(\tilde \epsilon + \epsilon_m I) \\ &= (3\lambda + 2\mu)\epsilon_m I + 2\mu \tilde \epsilon \end{aligned} $$

Volume chainging part와 관련된 항을 제외한 stress $\tilde \sigma$를 다음과 같이 정의한다.
$$ \tilde \sigma := 2\mu \tilde \epsilon $$

이 때, $\tilde \sigma$를 `deviatoric stress`라고 한다.

### 명제1
미소 변위, 변형률을 가정하고 등방성 선형 탄성재료라고 하자.

이 때, 다음을 증명하여라.
$$ \tilde \sigma = \sigma - \sigma_m I $$

$$ \text{Where, } \sigma_m = \frac{1}{3}\text{tr}(\sigma) $$

**Proof**

구성방정식에 의해 다음이 성립한다.
$$ \sigma - \tilde \sigma = (3\lambda + 2\mu)\epsilon_m I $$

동시에 다음도 성립한다.
$$ \begin{aligned} \text{tr}(\sigma) &= (\lambda \text{tr}(\epsilon) I + 2\mu \epsilon) : I \\ &= (3\lambda +  2\mu) \text{tr}(\epsilon) \\ &= 3 (3\lambda +  2\mu) \epsilon_m \end{aligned} $$

두 식을 비교하면 다음이 성립한다.
$$ \begin{aligned} \sigma - \tilde \sigma &= \frac{1}{3}\text{tr}(\sigma)I \\ &= \sigma_mI \end{aligned}  $$

위 식을 정리하면 다음이 성립한다.
$$ \tilde \sigma = \sigma - \sigma_m I \quad {_\blacksquare}$$

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
$$ \begin{aligned} U_d &= \frac{1}{2}(\tilde \sigma : \tilde \epsilon ) \\ &= \frac{1}{4\mu}(\tilde \sigma : \tilde \sigma) \quad {_\blacksquare} \end{aligned} $$

### 명제2
다음을 증명하여라.
$$ U_d = \mu(\tilde \epsilon : \tilde \epsilon) $$

**Proof**

$\tilde \sigma$의 정의에 의해 다음이 성립한다.
$$ \tilde \sigma = 2\mu \tilde \epsilon $$

따라서 다음이 성립한다.
$$ \begin{aligned} U_d &= \frac{1}{2}(\tilde \sigma : \tilde \epsilon ) \\ &= \mu(\tilde \epsilon : \tilde \epsilon) \quad {_\blacksquare} \end{aligned} $$


### 명제3
1D Tensile test에서 항복응력이 $\sigma_Y$라고 하자.

항복응력이 가해졌을 때 $U_d$가 다음과 같음을 증명하여라.
$$ U_d = \frac{1}{6\mu}\sigma_Y^2 $$

**Proof**

$\tilde \sigma$를 $\sigma$로 나타내면 다음과 같다.
$$ \tilde \sigma = \sigma - \sigma_mI = \begin{bmatrix} \frac{2}{3}\sigma_Y & 0 & 0 \\ 0 & -\frac{1}{3}\sigma_Y & 0 \\ 0 & 0 & -\frac{1}{3}\sigma_Y \end{bmatrix} $$

따라서 다음이 성립한다.
$$ U_d = \frac{1}{4\mu}(\tilde \sigma : \tilde \sigma) = \frac{1}{4\mu} \frac{2}{3} \sigma_Y^2 = \frac{1}{6\mu}\sigma_Y^2 \quad {_\blacksquare} $$