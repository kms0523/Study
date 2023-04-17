# Deviatoric Strain
## Motivation
strain tensor를 $\epsilon$이라고 하자.

이 때, $\epsilon$을 volume chainging과 관련이 없는 `deviatoric strain`과 `volumetric strain`으로 나누어 보자.

infinitesimal deformation 가정을 하면 volume chainging은 다음과 같다.

$$ \frac{\Delta V}{V} = \text{tr}(\epsilon) $$

따라서, $\epsilon_m = \tr(\epsilon)/3$이라고 할 때, $\epsilon$을 다음과 같이 나누어 보자.

$$ \begin{bmatrix} \epsilon_{11}&\cdots&\epsilon_{13}\\\vdots&&\vdots\\\epsilon_{31}&\cdots&\epsilon_{33} \end{bmatrix} = \begin{bmatrix} \epsilon_{11} - \epsilon_m&\epsilon_{12}&\epsilon_{13}\\\epsilon_{21}&\epsilon_{22} - \epsilon_m&\epsilon_{23}\\\epsilon_{31}&\epsilon_{32}&\epsilon_{33} - \epsilon_m \end{bmatrix} + \begin{bmatrix}\epsilon_m&&\\&\epsilon_m&\\&&\epsilon_m \end{bmatrix}  $$

$$ \epsilon = \tilde\epsilon + \epsilon_V $$

그러면 $\tr(\tilde\epsilon) = 0$임으로 $\tilde\epsilon$을 deviatoric strain $\epsilon_V$를 volumetric strain이라고 할 수 있다.

### 명제1
다음을 증명하여라.

$$ \tilde\epsilon = I_{dev}:\epsilon $$

**Proof**

$$ \begin{aligned} I_{dev} : \epsilon &= \sym(\epsilon) - \frac{1}{3}\tr(\epsilon)I \\&= \epsilon - \epsilon_mI \qed  \end{aligned} $$

### 명제2
다음을 증명하여라.

$$ \widetilde{\epsilon_1 + \epsilon_2} = \tilde \epsilon_1 + \tilde \epsilon_2 $$

**Proof**

Deviatoric strain의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} \widetilde{\epsilon_1 + \epsilon_2} &= I_{dev} :(\epsilon_1 + \epsilon_2) \\&= I_{dev}:\epsilon_1 + I_{dev}:\epsilon_2 \\&= \tilde \epsilon_1 + \tilde \epsilon_2 \qed\end{aligned} $$

### 명제3
$\epsilon$의 eigen value가 $\epsilon_{1,2,3}$일 때, 다음을 증명하여라.

$$ \tilde\epsilon : \tilde\epsilon = (\epsilon_1 - \epsilon_m)^2 + (\epsilon_2 - \epsilon_m)^2 + (\epsilon_3 - \epsilon_m)^2 $$

**Proof**

$\tilde\epsilon, D_{\tilde{\epsilon}}$은 symmetric 함으로 다음이 성립한다.

$$ \tilde\epsilon : \tilde\epsilon = \text{tr}(\tilde\epsilon^2) = \text{tr}(D_{\tilde\epsilon}^2) = D_{\tilde\epsilon}: D_{\tilde\epsilon}  $$

이 떄, $\epsilon$이 diagonalizable함으로 다음이 성립한다.

$$ D_{\tilde{\epsilon}} = D_{\epsilon} - \frac{\tr(D_\epsilon)}{3}I = D_{\epsilon} - \epsilon_mI $$

따라서, 다음이 성립한다.

$$ \begin{aligned} D_{\tilde\epsilon}: D_{\tilde\epsilon} &= (D_{\epsilon} - \epsilon_mI) : (D_{\epsilon} - \epsilon_mI) \\&= (\epsilon_1 - \epsilon_m)^2 + (\epsilon_2 - \epsilon_m)^2 + (\epsilon_3 - \epsilon_m)^2 \qed \end{aligned} $$

#### 따름명제3.1
다음을 증명하여라.

$$ \tilde\epsilon : \tilde\epsilon = \frac{1}{3}( (\epsilon_1 - \epsilon_2)^2 + (\epsilon_2 - \epsilon_3)^2 + (\epsilon_3 - \epsilon_1)^2) $$

**Proof**

명제3에 의해 다음이 성립한다.

$$ \begin{aligned} \tilde\epsilon : \tilde\epsilon &= (\epsilon_1 - \epsilon_m)^2 + (\epsilon_2 - \epsilon_m)^2 + (\epsilon_3 - \epsilon_m)^2 \\ &= \epsilon_1^2 + \epsilon_2^2 + \epsilon_3^2 +  - 2(\epsilon_1 + \epsilon_2 + \epsilon_3) \epsilon_m + 3\epsilon_m^2 \\ &= \epsilon_1^2 + \epsilon_2^2 + \epsilon_3^2 +  - \frac{1}{3} (\epsilon_1 + \epsilon_2 + \epsilon_3)^2 \\ &= \frac{1}{3} ( 2\epsilon_1^2 + 2\epsilon_2^2 + 2\epsilon_3^2 - 2(\epsilon_1\epsilon_2 + \epsilon_2\epsilon_3 + \epsilon_3\epsilon_1)) \\ &= \frac{1}{3} ( (\epsilon_1 - \epsilon_2)^2 + (\epsilon_2 - \epsilon_3)^2 + (\epsilon_3 - \epsilon_1)^2) \qed \end{aligned} $$

### 명제4
다음을 증명하여라.

$$ \tilde\epsilon:\tilde\epsilon = \frac{1}{3}( (\epsilon_{11} - \epsilon_{22})^2 + (\epsilon_{22} - \epsilon_{33})^2 + (\epsilon_{33} - \epsilon_{11})^2) + \frac{1}{2}(\gamma_{12}^2 + \gamma_{13}^2 + \gamma_{23}^2) $$

**Proof**

$$ \begin{aligned} \tilde{\epsilon}:\tilde{\epsilon} &= (\epsilon_{11}-\frac{1}{3}\epsilon_m)^2 + \cdots + (\epsilon_{33}-\frac{1}{3}\epsilon_m)^2 + \epsilon_{12}^2 + \cdots + \epsilon_{32}^2 \\&= \frac{1}{3}( (\epsilon_{11} - \epsilon_{22})^2 + (\epsilon_{22} - \epsilon_{33})^2 + (\epsilon_{33} - \epsilon_{11})^2) + 2(\epsilon_{12}^2 + \epsilon_{13}^2 + \epsilon_{23}^2) \\&= \frac{1}{3}( (\epsilon_{11} - \epsilon_{22})^2 + (\epsilon_{22} - \epsilon_{33})^2 + (\epsilon_{33} - \epsilon_{11})^2) + \frac{1}{2}(\gamma_{12}^2 + \gamma_{13}^2 + \gamma_{23}^2) \qed \end{aligned} $$

### 명제5
$J_2$를 다음과 같이 정의하자.

$$ J_2 = -I_2 $$

이 떄, 다음을 증명하여라.

$$ J_2(\tilde\epsilon) = \frac{1}{2}(\tilde\epsilon:\tilde\epsilon) $$

**Proof**

$I_2$의 정의에 의해 다음이 성립한다

$$ \begin{aligned} I_2 &= \frac{1}{2}(\text{tr}(\tilde \epsilon)^2 - \text{tr}(\tilde \epsilon^2)) \\ &= -\frac{1}{2}(\tilde\epsilon:\tilde\epsilon) \end{aligned} $$

따라서, 다음이 성립한다.

$$ J_2 =  \frac{1}{2}(\tilde\epsilon:\tilde\epsilon) \qed$$

## Plane Strain
Plane strain 요소는 $z$방향과 관련된 변형이 없다고 가정한 요소이다.

따라서, Plane strain 요소에서 volume chainging이 발생했다면, 가정에 의해 $x,y$방향의 변형에 의해서만 발생한 volumetric chainging일 것이다.

그럼으로 $\epsilon_m = \tr(\epsilon)/2$라고 할 때, Plane Strain 요소의 $\epsilon$은 다음과 같이 나누는것이 타당하다.

$$ \begin{bmatrix} \epsilon_{11}&\epsilon_{12}&\\\epsilon_{21}&\epsilon_{22}&\\&&0 \end{bmatrix} = \begin{bmatrix} \epsilon_{11} - \epsilon_m&\epsilon_{12}&\\\epsilon_{21}&\epsilon_{22} - \epsilon_m&\\&&0 \end{bmatrix} + \begin{bmatrix}\epsilon_m&&\\&\epsilon_m&\\&&0 \end{bmatrix}  $$

$$ \epsilon = \tilde\epsilon + \epsilon_V $$

그러면 $\tr(\tilde\epsilon) = 0$임으로 $\tilde\epsilon$을 deviatoric strain $\epsilon_V$를 volumetric strain이라고 할 수 있다.

### 참고
$$ I_2 = \begin{bmatrix}1&&\\&1&\\&&0 \end{bmatrix} $$

### 명제1
$\epsilon_2$를 다음과 같이 정의하자.

$$ \epsilon_2 = \begin{bmatrix} \epsilon_{11}&\epsilon_{12}\\\epsilon_{21}&\epsilon_{22} \end{bmatrix} $$

$\epsilon_2$의 eigen value를 $\epsilon_{1,2}$라고 할 때, 다음을 증명하여라.

$$ \tilde\epsilon : \tilde\epsilon = (\epsilon_1 - \epsilon_m)^2 + (\epsilon_2 - \epsilon_m)^2 $$

**Proof**

$\epsilon$은 diagonalizable함으로 다음이 성립한다.

$$ \exist P \st  P^T \epsilon P = \begin{bmatrix} \epsilon_{1}&&\\&\epsilon_{2}&\\&&0 \end{bmatrix}  $$

$$ P^T\epsilon P = D_\epsilon $$

이 떄, $\tilde{\epsilon} = \epsilon - \epsilon_mI_2$임으로 다음이 성립한다.

$$ P^T \tilde\epsilon P = D_{\epsilon} - \epsilon_mI_2 $$

$D_{\tilde\epsilon} =  D_{\epsilon} - \epsilon_mI_2 $라고 할 때, $\tilde\epsilon, D_{\tilde{\epsilon}}$은 symmetric 함으로 다음이 성립한다.

$$ \tilde\epsilon : \tilde\epsilon = \text{tr}(\tilde\epsilon^2) = \text{tr}(D_{\tilde\epsilon}^2) = D_{\tilde\epsilon}: D_{\tilde\epsilon}  $$


따라서, 다음이 성립한다.

$$ \begin{aligned} D_{\tilde\epsilon}: D_{\tilde\epsilon} &= (D_{\epsilon} - \epsilon_mI_2) : (D_{\epsilon} - \epsilon_mI_2) \\&= (\epsilon_1 - \epsilon_m)^2 + (\epsilon_2 - \epsilon_m)^2 \qed \end{aligned} $$

#### 따름명제3.1
다음을 증명하여라.

$$ \tilde\epsilon : \tilde\epsilon = \frac{1}{2} (\epsilon_1 - \epsilon_2)^2 $$

**Proof**

명제3에 의해 다음이 성립한다.

$$ \begin{aligned} \tilde\epsilon : \tilde\epsilon &= (\epsilon_1 - \epsilon_m)^2 + (\epsilon_2 - \epsilon_m)^2 \\ &= \epsilon_1^2 + \epsilon_2^2 - 2(\epsilon_1 + \epsilon_2) \epsilon_m + 2\epsilon_m^2 \\ &= \epsilon_1^2 + \epsilon_2^2 - \frac{1}{2} (\epsilon_1 + \epsilon_2)^2 \\ &= \frac{1}{2} (\epsilon_1^2 + \epsilon_2^2 - 2\epsilon_1\epsilon_2) \\ &= \frac{1}{2} (\epsilon_1 - \epsilon_2)^2 \qed \end{aligned} $$


### 명제2
다음을 증명하여라.

$$ \tilde\epsilon:\tilde\epsilon = \frac{1}{2}(\epsilon_{11} - \epsilon_{22})^2  + \frac{1}{2}\gamma_{12}^2 $$

**Proof**

$$ \begin{aligned} \tilde{\epsilon}:\tilde{\epsilon} &= (\epsilon_{11}-\epsilon_m)^2 + (\epsilon_{22}-\epsilon_m)^2 + \epsilon_{12}^2 + \epsilon_{21}^2 \\&= \frac{1}{2} (\epsilon_{11} - \epsilon_{22})^2 + 2\epsilon_{12}^2 \\&= \frac{1}{2} (\epsilon_{11} - \epsilon_{22})^2 + \frac{1}{2}\gamma_{12}^2 \qed \end{aligned} $$