# Deviatoric Strain
미소 변위, 변형률을 가정하면 volume-chainging은 다음과 같이 정의된다.
$$ \frac{\Delta V}{V} = \text{tr}(\epsilon) $$

따라서 volume-chainging이 $0$이 되도록 `deviatoric strain` $\tilde \epsilon$을 다음과 같이 정의한다.
$$ \tilde \epsilon := I_{dev} : \epsilon $$

### 명제1
$\epsilon_m = \text{tr}(\epsilon)/3$이라 할 떄, 다음을 증명하여라.
$$ \tilde \epsilon_{ij} = \epsilon_{ij} - \epsilon_m\delta_{ij} $$

**Proof**

$I_{dev}$의 정의와 $\epsilon$의 symmetry에 의해 다음이 성립한다.
$$ \begin{aligned} \tilde \epsilon &= I_{dev} : \epsilon \\&= \frac{1}{2}(\epsilon_{ij} + \epsilon_{ji}) - \frac{1}{3}\epsilon_{kk}\delta_{ij} \\&= \epsilon_{ij} - \epsilon_m\delta_{ij} \qed  \end{aligned} $$

#### 참고
$\epsilon_m$을 volumetric strain이라고 하며 $\epsilon_m\delta_{ij}$를 $\epsilon$의 volume-chainging part라고 한다.

### 명제2
Infinitesimal strains $\epsilon_{1,2}$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ \widetilde{\epsilon_1 + \epsilon_2} = \tilde \epsilon_1 + \tilde \epsilon_2 $$

**Proof**

Deviatoric strain의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \widetilde{\epsilon_1 + \epsilon_2} &= \epsilon_1 + \epsilon_2 - \frac{1}{3}\text{tr}(\epsilon_1 + \epsilon_2)I \\&= \epsilon_1 - \frac{1}{3} \text{tr}(\epsilon_1)I + \epsilon_2 - \frac{1}{3} \text{tr}(\epsilon_2)I \\&= \tilde \epsilon_1 + \tilde \epsilon_2 \qed\end{aligned} $$

### 명제3
Infinitesimal strains $\epsilon$이 있다고 하자.

$\epsilon$의 eigen value가 $\epsilon_{1,2,3}$일 때, 다음을 증명하여라.
$$ \tilde\epsilon : \tilde\epsilon = (\epsilon_1 - \epsilon_m)^2 + (\epsilon_2 - \epsilon_m)^2 + (\epsilon_3 - \epsilon_m)^2 $$

**Proof**

Double dot 연산의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} \tilde\epsilon : \tilde\epsilon &= \text{tr}(\tilde\epsilon^2) \\&= \text{tr}(D_{\tilde\epsilon}^2) \\&= (\epsilon_1 - \epsilon_m)^2 + (\epsilon_2 - \epsilon_m)^2 + (\epsilon_3 - \epsilon_m)^2 \qed  \end{aligned} $$

### 명제4
Infinitesimal strains $\epsilon$이 있다고 하자.

$\epsilon$의 eigen value가 $\epsilon_{1,2,3}$일 때, 다음을 증명하여라.
$$ \tilde\epsilon : \tilde\epsilon = \frac{1}{3}( (\epsilon_1 - \epsilon_2)^2 + (\epsilon_2 - \epsilon_3)^2 + (\epsilon_3 - \epsilon_1)^2) $$

**Proof**

명제3에 의해 다음이 성립한다.
$$ \begin{aligned} \tilde\epsilon : \tilde\epsilon &= (\epsilon_1 - \epsilon_m)^2 + (\epsilon_2 - \epsilon_m)^2 + (\epsilon_3 - \epsilon_m)^2 \\ &= \epsilon_1^2 + \epsilon_2^2 + \epsilon_3^2 +  - 2(\epsilon_1 + \epsilon_2 + \epsilon_3) \epsilon_m + 3\epsilon_m^2 \\ &= \epsilon_1^2 + \epsilon_2^2 + \epsilon_3^2 +  - \frac{1}{3} (\epsilon_1 + \epsilon_2 + \epsilon_3)^2 \\ &= \frac{1}{3} ( 2\epsilon_1^2 + 2\epsilon_2^2 + 2\epsilon_3^2 - 2(\epsilon_1\epsilon_2 + \epsilon_2\epsilon_3 + \epsilon_3\epsilon_1)) \\ &= \frac{1}{3} ( (\epsilon_1 - \epsilon_2)^2 + (\epsilon_2 - \epsilon_3)^2 + (\epsilon_3 - \epsilon_1)^2) \qed \end{aligned} $$

### 명제5
Infinitesimal strains $\epsilon$이 있다고 하자.

다음을 증명하여라.
$$ \tilde\epsilon:\tilde\epsilon = \frac{1}{3}( (\epsilon_{11} - \epsilon_{22})^2 + (\epsilon_{22} - \epsilon_{33})^2 + (\epsilon_{33} - \epsilon_{11})^2) + \frac{1}{2}(\gamma_{12}^2 + \gamma_{13}^2 + \gamma_{23}^2) $$


### 명제6
Infinitesimal strains $\epsilon$이 있을 때, 다음을 증명하여라.
$$ \frac{\partial\tilde\epsilon}{\partial \epsilon} = I_{dev} $$

**Proof**

$\tilde{\epsilon}$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial\tilde\epsilon_{ij}}{\partial \epsilon_{kl}} &= \frac{\partial(\frac{1}{2}(\epsilon_{ij} + \epsilon_{ji}) - \frac{1}{3}\epsilon_{mm}\delta_{ij})}{\partial \epsilon_{kl}} \\&= \frac{1}{2} \bigg( \frac{\partial \epsilon_{ij}}{\partial \epsilon_{kl}} + \frac{\partial \epsilon_{ji}}{\partial \epsilon_{kl}} \bigg) - \frac{1}{3} \delta_{ij} \frac{\partial \epsilon_{mm}}{\partial \epsilon_{kl}} \\&= \frac{1}{2}(\delta_{ik}\delta_{jl} + \delta_{il}\delta_{jk}) - \frac{1}{3} \delta_{ij} \delta_{kl} \qed \end{aligned} $$

### 명제7
$J_2$를 다음과 같이 정의하자.
$$ J_2 = -I_2 $$

이 떄, 다음을 증명하여라.
$$ J_2(\tilde\epsilon) = \frac{1}{2}(\tilde\epsilon:\tilde\epsilon) $$

**Proof**

$I_2$의 정의에 의해 다음이 성립한다
$$ \begin{aligned} I_2 &= \frac{1}{2}(\text{tr}(\tilde \epsilon)^2 - \text{tr}(\tilde \epsilon^2)) \\ &= -\frac{1}{2}(\tilde\epsilon:\tilde\epsilon) \end{aligned} $$

따라서, 다음이 성립한다.
$$ J_2 =  \frac{1}{2}(\tilde\epsilon:\tilde\epsilon) \qed$$

# Deviatoric Stress
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
미소 변위, 변형률을 가정하고 등방성 선형 탄성재료라고 할 때, 다음을 증명하여라.
$$ \frac{\partial\tilde\sigma}{\partial\sigma} = I_{dev}$$
