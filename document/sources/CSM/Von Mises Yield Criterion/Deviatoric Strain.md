# Deviatoric Strain
미소 변위, 변형률을 가정하면 volume-chainging은 다음과 같이 정의된다.

$$ \frac{\Delta V}{V} = \text{tr}(\epsilon) $$

따라서 volume-chainging이 $0$이 되도록 `deviatoric strain` $\tilde \epsilon$을 다음과 같이 정의한다.

$$ \tilde \epsilon := I_{dev} : \epsilon $$

### 명제1
Infinitesimal strains $\epsilon_{1,2}$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ \widetilde{\epsilon_1 + \epsilon_2} = \tilde \epsilon_1 + \tilde \epsilon_2 $$

**Proof**

Deviatoric strain의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} \widetilde{\epsilon_1 + \epsilon_2} &= I_{dev} :(\epsilon_1 + \epsilon_2) \\&= I_{dev}:\epsilon_1 + I_{dev}:\epsilon_2 \\&= \tilde \epsilon_1 + \tilde \epsilon_2 \qed\end{aligned} $$

### 명제2
$\epsilon_m = \text{tr}(\epsilon)/3$이라 할 떄, 다음을 증명하여라.

$$ \tilde\epsilon = \epsilon - \epsilon_mI $$

**Proof**

$I_{dev}$의 정의와 $\epsilon$의 symmetry에 의해 다음이 성립한다.

$$ \begin{aligned} \tilde \epsilon &= I_{dev} : \epsilon \\&= \sym(\epsilon) - \frac{1}{3}\tr(\epsilon)I \\&= \epsilon - \epsilon_mI \qed  \end{aligned} $$

#### 참고
$\epsilon_m$을 volumetric strain이라고 하며 $\epsilon_m\delta_{ij}$를 $\epsilon$의 volume-chainging part라고 한다.

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

**Proof**


$$ \begin{aligned} \tilde{\epsilon}:\tilde{\epsilon} &= (\epsilon_{11}-\frac{1}{3}\epsilon_m)^2 + \cdots + (\epsilon_{33}-\frac{1}{3}\epsilon_m)^2 + \epsilon_{12}^2 + \cdots + \epsilon_{32}^2 \\&= \frac{1}{3}( (\epsilon_{11} - \epsilon_{22})^2 + (\epsilon_{22} - \epsilon_{33})^2 + (\epsilon_{33} - \epsilon_{11})^2) + 2(\epsilon_{12}^2 + \epsilon_{13}^2 + \epsilon_{23}^2) \\&= \frac{1}{3}( (\epsilon_{11} - \epsilon_{22})^2 + (\epsilon_{22} - \epsilon_{33})^2 + (\epsilon_{33} - \epsilon_{11})^2) + \frac{1}{2}(\gamma_{12}^2 + \gamma_{13}^2 + \gamma_{23}^2) \qed \end{aligned} $$


### 명제6
$J_2$를 다음과 같이 정의하자.

$$ J_2 = -I_2 $$

이 떄, 다음을 증명하여라.

$$ J_2(\tilde\epsilon) = \frac{1}{2}(\tilde\epsilon:\tilde\epsilon) $$

**Proof**

$I_2$의 정의에 의해 다음이 성립한다

$$ \begin{aligned} I_2 &= \frac{1}{2}(\text{tr}(\tilde \epsilon)^2 - \text{tr}(\tilde \epsilon^2)) \\ &= -\frac{1}{2}(\tilde\epsilon:\tilde\epsilon) \end{aligned} $$

따라서, 다음이 성립한다.

$$ J_2 =  \frac{1}{2}(\tilde\epsilon:\tilde\epsilon) \qed$$