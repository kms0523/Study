# Deviatoric Stress
## 정의
미소 변위, 변형률을 가정하고 등방성 선형 탄성재료의 경우 구성방정식은 다음과 같다.

$$ \sigma = \lambda \text{tr}(\epsilon) I + 2\mu \epsilon $$

구성방정식을 $\tilde \epsilon$으로 나타내면 다음과 같다.

$$ \begin{aligned} \sigma &= \lambda \text{tr}(\epsilon) I + 2\mu \epsilon \\ &= 3 \lambda \epsilon_m I + 2\mu(\tilde \epsilon + \epsilon_m I) \\ &= (3\lambda + 2\mu)\epsilon_m I + 2\mu \tilde \epsilon \end{aligned} $$

$\epsilon_m$과 관련된 항을 제외한 stress $\tilde \sigma$를 다음과 같이 정의한다.

$$ \tilde \sigma := 2\mu \tilde \epsilon $$

이 때, $\tilde \sigma$를 `deviatoric stress`라고 한다.

### 명제1
미소 변위, 변형률을 가정하고 등방성 선형 탄성재료라고 하자.

이 때, 다음을 증명하여라.

$$ \tilde \sigma = I_{dev}:\sigma $$

**Proof**

구성방정식에 의해 다음이 성립한다.

$$ \begin{aligned} \text{tr}(\sigma) &= (\lambda \text{tr}(\epsilon) I + 2\mu \epsilon) : I \\ &= (3\lambda + 2\mu) \text{tr}(\epsilon) \\ &= 3(3\lambda +  2\mu)\epsilon_m \end{aligned} $$

$I_{dev}$의 정의와 $\sigma$의 symmetry에 의해 다음이 성립한다.

$$ \begin{aligned} I_{dev} : \sigma &= \sigma_{ij} - \frac{1}{3}\text{tr}(\sigma)\delta_{ij} \\&= (3\lambda + 2\mu)\epsilon_m \delta_{ij} + 2\mu \tilde \epsilon - (3\lambda +  2\mu)\epsilon_m\delta_{ij} \\&= 2\mu\tilde\epsilon  \qed \end{aligned} $$

#### 따름명제
$\sigma_m = \text{tr}(\sigma)/3$이라 할 떄, 다음을 증명하여라.

$$ \tilde \sigma = \sigma - \sigma_m I $$

**Proof**

명제1과 $\sigma$의 symmetry에 의해 다음이 성립한다.

$$ \begin{aligned} I_{dev} : \sigma &= \sym(\sigma) - \frac{1}{3}\sigma_{kk}I \\&= \sigma - \sigma_mI \qed \end{aligned} $$

### 명제2
미소 변위, 변형률을 가정하고 등방성 선형 탄성재료라고 하자.

$\sigma$의 eigen value가 $\sigma_{1,2,3}$일 때, 다음을 증명하여라.

$$ \tilde\sigma : \tilde\sigma = (\sigma_1 - \sigma_m)^2 + (\sigma_2 - \sigma_m)^2 + (\sigma_3 - \sigma_m)^2 $$

### 명제3
미소 변위, 변형률을 가정하고 등방성 선형 탄성재료라고 하자.

$\sigma$의 eigen value가 $\sigma_{1,2,3}$일 때, 다음을 증명하여라.

$$ \tilde\sigma : \tilde\sigma = \frac{1}{3}( (\sigma_1 - \sigma_2)^2 + (\sigma_2 - \sigma_3)^2 + (\sigma_3 - \sigma_1)^2) $$

### 명제4
Infinitesimal strains $\sigma$이 있다고 하자.

다음을 증명하여라.

$$ \tilde\sigma:\tilde\sigma = \frac{1}{3}( (\sigma_{11} - \sigma_{22})^2 + (\sigma_{22} - \sigma_{33})^2 + (\sigma_{33} - \sigma_{11})^2) + \frac{1}{2}(\gamma_{12}^2 + \gamma_{13}^2 + \gamma_{23}^2) $$

**Proof**


$$ \begin{aligned} \tilde{\sigma}:\tilde{\sigma} &= (\sigma_{11}-\frac{1}{3}\sigma_m)^2 + \cdots + (\sigma_{33}-\frac{1}{3}\sigma_m)^2 + \sigma_{12}^2 + \cdots + \sigma_{32}^2 \\&= \frac{1}{3}( (\sigma_{11} - \sigma_{22})^2 + (\sigma_{22} - \sigma_{33})^2 + (\sigma_{33} - \sigma_{11})^2) + 2(\sigma_{12}^2 + \sigma_{13}^2 + \sigma_{23}^2) \\&= \frac{1}{3}( (\sigma_{11} - \sigma_{22})^2 + (\sigma_{22} - \sigma_{33})^2 + (\sigma_{33} - \sigma_{11})^2) + \frac{1}{2}(\gamma_{12}^2 + \gamma_{13}^2 + \gamma_{23}^2) \qed \end{aligned} $$

### 명제5
$J_2$를 다음과 같이 정의하자.

$$ J_2 = -I_2 $$

이 떄, 다음을 증명하여라.

$$ J_2(\tilde\sigma) = \frac{1}{2}(\tilde\sigma:\tilde\sigma) $$

**Proof**

$I_2$의 정의에 의해 다음이 성립한다

$$ \begin{aligned} I_2 &= \frac{1}{2}(\text{tr}(\tilde \sigma)^2 - \text{tr}(\tilde \sigma^2)) \\ &= -\frac{1}{2}(\tilde\sigma:\tilde\sigma) \end{aligned} $$

따라서, 다음이 성립한다.

$$ J_2 =  \frac{1}{2}(\tilde\sigma:\tilde\sigma) \qed$$