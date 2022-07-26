# Material coordinates
운동하는 연속체 한 점의 위치가 시간 $t$에 대한 벡터 함수로 주어진다고 하자.
$$ \mathbf x = \mathbf p(t) $$

연속체의 운동을 표현하기 위해 위의 표현법을 사용해서 연속체를 이루는 모든 점들의 위치를 나타내면 다음과 같다.
$$ \mathbf x_i = \mathbf p_i(t), \quad i=1, \cdots, N, \cdots $$

하지만 연속체 내부에는 무한한 점이 포함되어 있기 때문에 점마다 번호를 부여하는 방법은 한계가 있다. 따라서 이러한 한계를 극복하기 위해 기준 시간 $t_0$때 위치를 가지고 연속체의 한 점을 표현하는 `물질좌표(material coordinates)` $\bm X$를 도입한다.
$$ X^i = p^i(\bm X,t_0) $$

물질좌표는 연속체의 특정 한 점을 표현하는 방법이며, 물질좌표를 이용해서 연속체를 이루는 모든 점들의 위치를 나타내면 다음과 같다.
$$ \begin{equation} \mathbf x = \mathbf p(\bm X,t) \quad \text{with} \quad \bm X = \mathbf p(\bm X, t_0) \in \Omega_0 \end{equation}  $$

$\Omega_0$은 $t_0$일 때 연속체를 이루는 모든 점들의 위치의 집합이다.

> 참고  
[book] (Lai et al) Introduction to Continuum Mechanics Chapter3.1

# Material & spatial description
운동하는 연속체의 어떤 물리량을 나타내는 텐서 $\bf Q$가 있다고 하자. $\bf Q$가 시간에 따라 변한다고 할 때, $\bf Q$를 다음 두가지 관점으로 서술할 수 있다.

## Material description
연속체의 한 점을 따라가면서 $\bf Q$의 시간에 대한 변화를 함수로 나타내면 다음과 같다.
$$ \mathbf Q = \mathbf F(\bm X,t) $$

이러한 서술 방법을 물질 관점 혹은 Lagrangian관점이라고 한다.

물질 관점에서 서술하는것은 $\bm X$로 표현되는 연속체의 한 점에 $\bf Q$가 $t$에 따라 변화하는 정도다. 이 때 주목할만한 점은, $t$가 변하면 $\bm X$로 표현되는 연속체의 점의 위치도 변한다는 것이다. 따라서 물질 관점에서 서술할 경우, 한 위치에서 연속체의 물리량이 어떻게 변하는지에 대한 정보를 직접적으로 제공하지는 않는다.

## Spatial description
위치를 기준으로 $\bf Q$의 시간에 대한 변화를 함수로 나타내면 다음과 같다.
$$ \begin{equation} \mathbf Q = \mathbf G(\mathbf x, t) \end{equation}  $$

이러한 서술 관점을 공간 관점 혹은 Eulerian관점이라고 한다.

공간 관점에서 서술하는것은 $\bf x$에서 $\bf Q$의 $t$에 대한 변화다. 이 때 주목할만한 점은, $t$가 변하면 $\bf x$를 차지하고 있는 연속체의 한 점도 변한다는 점이다. 따라서 공간 관점에서 서술할 경우, 연속체의 한 점에 물리량이 어떻게 변하는지에 대한 정보를 직접적으로 제공하지는 않는다.

하지만 식(1)에 의해서 공간 관점으로 서술된 표현을 물질 관점으로 서술된 표현으로 바꿀 수 있다. 식(1)을 식(2)에 대입하면 다음과 같다.
$$ \mathbf Q = \mathbf G( \mathbf p({\bm X}, t), t) = \mathbf F(\bm X, t)$$

> 참고  
[book] (Lai et al) Introduction to Continuum Mechanics Chapter3.2

# Material Derivative
연속체 한 점의 물리량이 시간에 따라 변하는 정도를 `물질미분(material derivative)`이라고 하며, $D/Dt$로 표현한다.

스칼라 물리량 $\phi$가 다음과 같이 Lagrangian관점과 Eulerian관점으로 표현되었다고 하자.
$$ \phi = f(\bm X, t) = g(\mathbf x, t) $$

$\phi$의 물질미분은 다음과 같다.
$$ \begin{aligned} \frac{D\phi}{Dt} = \frac{\partial\phi}{\partial t}\bigg\vert_{\bm X = const} &= \frac{\partial f}{\partial t} \\ &= \frac{\partial g}{\partial x^i} \frac{\partial x^i}{\partial t} + \frac{\partial g}{\partial t} = \nabla g \cdot \mathbf u + \frac{\partial g}{\partial t} \end{aligned} $$

이 때, $\bf x$는 식(1)에 의해 $\bm X, t$의 함수임으로 편미분의 Chain rule을 사용하여 표현해야 한다.

이번에는 벡터 물리량 $\boldsymbol \phi$가 다음과 같이 Lagrangian관점과 Eulerian관점으로 표현되었다고 하자.
$$ \boldsymbol \phi = \mathbf f(\bm X, t) = \mathbf g(\mathbf x, t) $$

$\phi$의 물질미분은 다음과 같다.
$$ \begin{aligned} \frac{D \boldsymbol \phi}{Dt} = \frac{\partial \boldsymbol \phi}{\partial t}\bigg\vert_{\bm X = const} & = \frac{\partial \mathbf f}{\partial t} \\ & = \frac{\partial g^i}{\partial x^j} \frac{\partial x^j}{\partial t} + \frac{\partial g^i}{\partial t} = \nabla \mathbf g \cdot \mathbf u + \frac{\partial \mathbf g}{\partial t} \end{aligned} $$

> 참고  
[book] (Lai et al) Introduction to Continuum Mechanics Chapter3.3

# Displacement 
연속체 한 점의 변위 $\bf d$는 식(1)에 의해 다음과 같다.
$$ \mathbf d(\bm X, t) = \mathbf p(\bm X, t) - \bm X $$

# Kinematic Equation for Rigid Body Motion
## translation
강체 `병진(translation)`운동의 방정식은 다음과 같다.
$$ \mathbf p(\bm X,t) = \bm X + \mathbf c(t) $$

따라서, 변위 벡터는 다음과 같다.
$$ \mathbf d(\bm X,t) = \mathbf c(t) $$

병진운동에서는 위치에 상관없이 모든 점이 동일한 크기와 방향의 변위를 갖는다는 것을 의미한다.

## Rotation
강체 `회전(rotation)`운동의 운동방정식은 다음과 같다.
$$ \mathbf p(\bm X,t) - \mathbf b = \mathbf R(t)(\bm X - \mathbf b) $$
$$ \text{Where, } \mathbf b \text{ is rotational center and } \\ \mathbf R \text { is a proper orthogonal tensor} $$

따라서, 변위 벡터는 다음과 같다.
$$ \mathbf d(\bm X,t) = (\mathbf R - \mathbf I)(\bm X - \mathbf b) $$

$\mathbf x - \mathbf b$는 회전중심에서 현재 위치까지의 벡터를 나타내고, $\bm X - \mathbf b$는 회정중심에서 초기 위치까지의 벡터를 나타낸다. 따라서 운동방정식이 말하는 바는, 회전중심에서 초기 위치까지의 벡터가 회전하여 회전 중심에서 현재 위치까지의 벡터가 되었다는것을 의미한다.

## General motion
강체의 운동방정식은 다음과 같다.
$$ \mathbf p(\bm X,t) - \mathbf b = \mathbf R(t)(\bm X - \mathbf b) + \mathbf c(t) $$

따라서, 변위 벡터는 다음과 같다.
$$ \mathbf d(\bm X,t) = (\mathbf R - \mathbf I)(\bm X - \mathbf b) + \mathbf c $$

### 명제1
강체의 운동에서 서로 다른 두점의 거리는 변하지 않음을 증명하여라.

### 명제2
Example 3.6.2

> 참고  
[book] (Lai et al) Introduction to Continuum Mechanics Chapter3.6

# Deformation
운동하는 연속체를 생각해보자. 운동 하고 있는 연속체의 한 점의 위치는 시간에 따라 바뀌게 된다. 이를 벡터함수 $\mathbf p$로 나타낸다고 할 때 $\mathbf p$에 의해서 연속체 내부에 있는 모든점의 변형된 위치가 서술된다. 따라서 $\mathbf p$를 `변형(deformation)`이라고 한다.

두 점 $\bm X, \bm X + \Delta \bm X$이 있을 때, 벡터 $\Delta \mathbf x$를 다음과 같이 정의하자.
$$ \Delta \mathbf x(t) := \mathbf p(\bm X + \Delta \bm X, t) - \mathbf p(\bm X,t) $$

그러면 정의에 의해 $\Delta \mathbf x(t_0) = \Delta \bm X$이다.

## 선형근사
$\Delta \bm X$가 충분히 작아 $\mathbf p (\bm X + \Delta \bm X, t)$를 선형으로 근사할 수 있다고 가정하자. 그러면 $\Delta \mathbf x$는 다음과 같이 간단하게 나타낼 수 있다.
$$ \begin{aligned} \Delta \mathbf x & \approx \frac{\partial p_i}{\partial X_j} \Delta X_j \\ & = \nabla \mathbf p \Delta \bm X \\ & =  (\mathbf I + \nabla \mathbf d )\Delta X \\ & = \mathbf F \Delta \bm X \end{aligned} $$

$$ \text{Where, } \mathbf F = \nabla \mathbf p = \mathbf I + \nabla \mathbf d $$

이 때, $\mathbf F$를 `deformation gradient`, $\nabla \mathbf d$를 `displacement gradient`라 한다.

## 변형 후 길이
$\Delta \bm X, \Delta \mathbf x$를 길이와 단위방향벡터로 표현하면 다음과 같다.
$$ \Delta X = \Delta S \mathbf n, \enspace \Delta \mathbf x = \Delta S' \mathbf n' $$

변형 후 길이를 구하기 위해 내적을 이용하고 선형근사하면 다음 관계식을 얻을 수 있다.
$$ \begin{equation} \begin{aligned} \Delta \mathbf x \cdot \Delta \mathbf x &= \Delta \bm X ^T \mathbf F^T \mathbf F \Delta \bm X \\ (\Delta S')^2 &=  (\Delta S)^2 \mathbf n ^T \mathbf C \mathbf n \end{aligned} \end{equation} $$
$$ \text{Where, } \mathbf C = \mathbf F^T \mathbf F $$

이 떄, $\bf C$를 `Chauchy-Green deformation tensor`라고 하며 $\bf C$를 풀어쓰면 다음과 같다.
$$ \begin{aligned} \mathbf C &= \mathbf {(I + \nabla d)}^T \mathbf {(I + \nabla d)} \\ &= \mathbf {I + (\nabla d)}^T + \nabla \mathbf d + (\nabla \mathbf d)^T \nabla \mathbf d \\ &= \mathbf I + 2 \mathbf E_f  \end{aligned} \\  \text{Where, } \mathbf E_f =\frac{1}{2} \left(\nabla \mathbf d + \nabla \mathbf d^T + \nabla \mathbf d^T \nabla \mathbf d \right)$$

이 때, $\mathbf E_f$을 `finite strain tensor`라고 한다. 

만약 $\bf d$가 모든 점에서 동일한 강체 운동일 경우 $\nabla \bf d = 0$이고 $\mathbf E_f = 0$임으로 $\bf C = I$가 된다. 즉, $\mathbf E_f$은 변위의 변화율로 구성되어 있으며 변형률을 표현하는 값이 된다. 

$\mathbf E_f$을 이용해서 변형 후 길이를 표현하면 다음과 같다.
$$ \begin{aligned} (\Delta S')^2 &=  (\Delta S)^2 \mathbf n ^T \mathbf C \mathbf n \\ &= (\Delta S)^2 \mathbf n^T (\mathbf I + 2 \mathbf E_f) \mathbf n \\ &= (\Delta S)^2 + 2 (\Delta S)^2 (\mathbf n^T \mathbf E_f  \mathbf n) \end{aligned} $$

### 단위 길이당 변화율
위 식을 아래 과정으로 정리하면 단위 길이당 변화율을 얻을 수 있다.
$$ \begin{aligned} & (\Delta S')^2 = (\Delta S)^2 + 2 (\Delta S)^2 (\mathbf n^T \mathbf E_f  \mathbf n) \\ \Leftrightarrow \enspace & \frac{(\Delta S')^2 - (\Delta S)^2}{2 (\Delta S)^2} =  (\mathbf n^T \mathbf E_f  \mathbf n) \\ \Leftrightarrow \enspace & \frac{\Delta S' - \Delta S}{\Delta S} = \frac{2 \Delta S}{\Delta S' + \Delta S} (\mathbf n^T \mathbf E_f  \mathbf n) \end{aligned} $$

## 변형 후 각도
또 다른 점 $\bm X + \Delta \bm Y$이 있을 때, 벡터 $\Delta \mathbf y$를 다음과 같이 정의하자.
$$ \Delta \mathbf y(t) := \mathbf p(\bm X + \Delta \bm Y, t) - \mathbf p(\bm X,t) $$

벡터들을 길이와 단위벡터로 다음과 같이 표현하자.
$$ \Delta \bm X = \Delta S_1 \mathbf n, \enspace \Delta \bm Y = \Delta S_2 \mathbf m \\ \Delta \mathbf x = \Delta S_1' \mathbf n', \enspace \Delta \mathbf y = \Delta S_2' \mathbf m' $$

이 떄, 두 벡터가 $t_0$에서 수직하다고 하자.
$$ \mathbf n \cdot \mathbf m = 0  $$

$\Delta \mathbf x$와 $\Delta \mathbf y$가 이루는 각도는 내적을 통해 다음과 같이 알 수 있다.
$$ \begin{equation} \begin{aligned} & \Delta \mathbf x \cdot \Delta \mathbf y = \Delta \bm X^T \mathbf C \Delta \bm Y \\ \Leftrightarrow \enspace & \Delta S_1' \Delta S_2' \cos \theta = \Delta S_1 \Delta S_2 \mathbf n^T (\mathbf I + \mathbf 2E_f) \mathbf m \\ \Leftrightarrow \enspace & \Delta S_1' \Delta S_2' \cos \theta = 2\Delta S_1 \Delta S_2 (\mathbf n^T \mathbf E_f \mathbf m)  \\ \Leftrightarrow \enspace & \cos \theta = 2\frac{\Delta S_1 \Delta S_2}{\Delta S'_1 \Delta S'_2 } (\mathbf n^T \mathbf E_f \mathbf m) \end{aligned} \end{equation} $$

### 줄어든 각도
줄어든 각도를 $\gamma$라 하면 다음이 성립한다.
$$ \theta = \frac{\pi}{2} - \gamma $$

이를 식(4)에 대입하면 다음과 같다.
$$ \sin \gamma = 2\frac{\Delta S_1 \Delta S_2}{\Delta S'_1 \Delta S'_2 } (\mathbf n^T \mathbf E_f \mathbf m) $$

# Infinitesimal Deformation
변형이 매우 작다고 가정하면 변형률을 나타내는 $\nabla \mathbf d$가 매우 작은 값을 갖는다. 이러한 가정을 통해 다음과 같은 간략화가 가능하다.

## Cauchy-Green deformation tensor
$\nabla \mathbf d$가 충분히 작다면 고차항인 $(\nabla \mathbf d)^T \nabla \mathbf d$를 무시할 수 있고 $\bf C$를 다음과 같이 근사할 수 있다.
$$ \begin{aligned} \mathbf C &= \mathbf I + 2 \mathbf E_f \\ & \approx  \mathbf I + 2 \mathbf E \end{aligned}  $$
$$ \text{Where, } \mathbf E = \frac{1}{2}(\nabla \mathbf d + \nabla \mathbf d^T ) $$

이 때, $\mathbf E$는 $\mathbf E_f$에 미소변형 가정을 적용해 얻은 strain tensor임으로 `infinitesimal strain tensor`라고 한다. 

### infinitesimal strain tensor
$\mathbf E$는 $\nabla \bf d$의 symmetric part다. 따라서 $\mathbf E$는 diagonalizable하며 서로 수직인 고유벡터들을 갖는다. 

각각의 고유벡터들을 principal directions라고 하며 고유값들을 `주변형률(principal strain)`이라 한다. 기하학적으로, 고유벡터 방향에 있는 요소들은 변형 후에도 방향은 변하지 않으며 크기가 고유값만큼 상수배 된다.

주변형률은 모든 방향중에 최대 최소 normal strain값을 갖으며 다음의 특성 방정식으로 주변형률을 구할 수 있다.
$$ \lambda^3 - I_1 \lambda^2 + I_2 \lambda - I_3 = 0 $$
$$ \begin{gathered} \text{Where, } I_1 = E_{ii} \\ I_2 = \bigg|\begin{matrix} E_{11} & E_{12} \\ E_{21} & E_{22} \end{matrix} \bigg| + \bigg|\begin{matrix} E_{22} & E_{23} \\ E_{32} & E_{33} \end{matrix} \bigg| + \bigg|\begin{matrix} E_{11} & E_{13} \\ E_{31} & E_{33} \end{matrix} \bigg| \\ I_3 = |E_{ij}| \end{gathered}  $$

이 떄, $I_{1,2,3}$는 $\mathbf E$의 `불변량(invariant)`라고 하며 기저 변환을 하더라도 변하지 않는 값들이다.

여기서 $I_1$을 `dilatation`이라고 하며 기하학적으로 단위 부피당 변화량을 의미한다. 왜냐하면 주변형률 방향으로 길이가 각 각 $\Delta S_{1,2,3}$인 직육면체가 있다고 하면 변형후에는 각 각 $\Delta S_{1,2,3}(1 + E_{11,22,33})$의 길이를 갖는 직육면체가 된다. 따라서 부피 변화량은 다음과 같다.
$$ \begin{aligned} \Delta V &= \Delta S_1 \Delta S_2 \Delta S_3 (1 + E_{11})(1 + E_{22})(1 + E_{33}) - \Delta S_1 \Delta S_2 \Delta S_3 \\ &= \Delta S_1 \Delta S_2 \Delta S_3(E_{11} + E_{22} + E_{33}) + \text{high-order term} \end{aligned} $$

변형률이 매우 작아 $\bf E$가 매우 작고, 따라서 $\bf E$의 고차항을 무시할 수 있다면 부피 변화률은 다음과 같다.
$$ \frac{\Delta V}{V} = E_{11} + E_{22} + E_{33} $$

> 참고  
> [book] (Lai et al) Introduction to Continuum Mechanics Chapter 3.7-10


## 변형후 길이
$\nabla \mathbf d$가 충분히 작다면 변형후 벡터의 길이는 다음과 같이 근사 할 수 있다.
$$ \begin{aligned} (\Delta S')^2 & = (\Delta S)^2 + 2 (\Delta S)^2 (\mathbf n^T \mathbf E_f \mathbf n) \\ & \approx (\Delta S)^2 + 2 (\Delta S)^2 (\mathbf n^T \mathbf E \mathbf n) \end{aligned} $$

### 단위 길이당 변화율
$\nabla \mathbf d$가 충분히 작아 $\Delta S' \approx \Delta S$라 근사하면 단위 길이당 변화율을 다음과 같이 근사할 수 있다.
$$ \begin{aligned} \frac{\Delta S' - \Delta S}{\Delta S} &= \frac{2 \Delta S}{\Delta S' + \Delta S} (\mathbf n^T \mathbf E_f  \mathbf n) \\ & \approx \mathbf n^T \mathbf E  \mathbf n \end{aligned} $$

즉, $\bf n$방향 벡터의 단위 길이당 변화율은 $\mathbf n^T \mathbf E  \mathbf n$으로 근사 할 수 있다.

만약 $\bf e_1,e_2,e_3$방향일 경우, 단위 길이당 변화율은 각 각 $E_{11},E_{22},E_{33}$로 나타난다. 따라서 $\bf E$의 대각성분에 있는 값들을 `normal strain`이라고 한다.

## 변형후 각도
$\nabla \mathbf d$가 충분히 작다면 변형후 각도는 다음과 같이 근사할 수 있다.
$$ \begin{aligned} \cos \theta &= 2\frac{\Delta S_1 \Delta S_2}{\Delta S'_1 \Delta S'_2 } (\mathbf n^T \mathbf E_f \mathbf m) \\ & \approx 2\frac{\Delta S_1 \Delta S_2}{\Delta S'_1 \Delta S'_2 } (\mathbf n^T \mathbf E \mathbf m) \end{aligned} $$

### 줄어든 각도
$\nabla \mathbf d$가 충분히 작아 $\Delta S'_i \approx \Delta S_i$로 근사하면, 줄어든 각도 $\gamma$는 다음과 같이 근사할 수 있다.
$$ \begin{aligned} \sin \gamma &= 2\frac{\Delta S_1 \Delta S_2}{\Delta S'_1 \Delta S'_2 } (\mathbf n^T \mathbf E_f \mathbf m) \\ & \approx 2 (\mathbf n^T \mathbf E \mathbf m) \end{aligned} $$

이 때, $\gamma \approx 0$이라고 근사하면, 줄어든 각도는 다음과 같이 근사 된다.
$$ \gamma \approx 2 (\mathbf n^T \mathbf E \mathbf m) $$

$\mathbf n = \mathbf e_i, \enspace \mathbf m = \mathbf e_j$이 일 경우 $\gamma = 2E_{ij}$가 되며 이는 기존에 $\mathbf e_i, \mathbf e_j$방향에 있던 두 벡터가 이루던 각도가 얼마나 줄어들었는지를 알려준다.

# Time rate of change of a material element
$\mathbf p$를 물질미분하면 연속체의 한 점을 고정한 채 연속체의 한 점이 공간상의 차지하는 한 점(위치)의 시간에 따른 변화량, 즉 속도를 얻게 된다.

이 때, $\mathbf p$가 Lagrangian관점으로 서술되었을 경우 $\mathbf p$의 물질미분이 함수 $\mathbf u$로, $\mathbf p$가 Eulerian관점으로 서술 되었을 경우 $\mathbf p$의 물질미분이 함수 $\mathbf v$로 표현된다고 하자.


연속체의 두 점 $\bm X, \bm X + \Delta \bm X$으로 이루어진 벡터를 다음과 같이 정의하자.
$$ \begin{equation} \Delta \mathbf x = \mathbf p(\bm X + \Delta \bm X, t) - \mathbf p(\bm X, t) \end{equation}  $$

식(7)을 물질미분 하면 다음과 같다.
$$ \begin{aligned} \frac{D}{Dt} \Delta \mathbf x &= \frac{D}{Dt} \mathbf p(\bm X + \Delta \bm X, t) - \frac{D}{Dt} \mathbf p(\bm X, t) \\ &= \mathbf u(\bm X + \Delta \bm X,t) - \mathbf u(\bm X,t) \\ &= \mathbf v(\mathbf x + \Delta \mathbf x,t) - \mathbf v(\mathbf x,t) \end{aligned} $$

$\Delta \bm X, \Delta \mathbf x$가 충분히 작아 $\mathbf u(\bm X + \Delta \bm X,t), \mathbf v(\mathbf x + \Delta \mathbf x,t)$를 선형으로 근사할 수 있다고 가정하면 다음과 같다.
$$ \begin{equation} \frac{D}{Dt} \Delta \mathbf x = (\nabla_{\bm X} \mathbf u) \Delta \bm X = (\nabla_{\mathbf x} \mathbf v) \Delta \mathbf x \end{equation} $$

이후로 $\nabla \mathbf v$는 Eulerian관점에서 서술한 $\nabla_{\mathbf x} \mathbf v$을 나타낸다.

> 참고  
> [book] (Lai et al) Introduction to Continuum Mechanics Chapter 3.12

## The rate of deformation tensor
$\nabla \mathbf v$를 다음과 같이 symmetric part와 antisymmetric part로 나눠보자.
$$ \nabla \mathbf v = \mathbf D + \mathbf W $$
$$ \text{Where, } \mathbf D = \frac{1}{2} \left( \nabla \mathbf v + (\nabla \mathbf v)^T \right), \quad \mathbf W = \frac{1}{2} \left( \nabla \mathbf v - (\nabla \mathbf v)^T \right)  $$

이 때, $\mathbf D$를 `rate of deformation tensor` $\mathbf W$를 `spin tensor`라고 한다.

$\mathbf W$는 antisymmetric tensor임으로 dual vector를 $\boldsymbol \omega$라 할 때, 다음을 만족한다.
$$ \begin{equation} \mathbf W \Delta \mathbf x = \boldsymbol \omega \times \Delta \mathbf x \end{equation}  $$

식(10)을 보면 $\mathbf W$의 단위가 $/s$임으로, $\mathbf W$은 $\Delta \mathbf x$를 각속도 $\boldsymbol{\omega}$로 회전 시킨다는것을 알 수 있다.

벡터의 시간변화율을 $\mathbf D, \mathbf W$로 나타내면 다음과 같다.
$$ \frac{D}{Dt} \Delta \mathbf x = \mathbf D \Delta \mathbf x + \mathbf W \Delta \mathbf x = \mathbf D \Delta \mathbf x + \boldsymbol \omega \times \Delta \mathbf x$$

> 참고  
> [book] (Lai et al) Introduction to Continuum Mechanics Chapter 3.14 + Prob. 3.48

## 길이의 시간 변화율
두 점 $\bm X, \bm X + \Delta \bm X$으로 이루어진 요소가 시간 $t$에서 다음과 같이 표현된다고 하자.
$$ \Delta \mathbf x = \Delta S \mathbf n $$

요소 길이의 시간 변화율을 보기 위해 다음과 같은 과정을 거치자.
$$ \begin{equation} \begin{aligned} & \Delta \mathbf x \cdot \Delta \mathbf x = (\Delta S)^2 \\  \rightarrow \enspace & 2 \Delta \mathbf x \cdot \frac{D}{Dt} \Delta \mathbf x = 2 \Delta S \frac{D}{Dt}\Delta S \end{aligned} \end{equation} $$

왼쪽항을 rate of deformation tensor와 spin tensor를 이용해서 표현하면 다음과 같다.
$$ \Delta \mathbf x \cdot \frac{D}{Dt} \Delta \mathbf x = \Delta \mathbf x \cdot \nabla \mathbf v \Delta \mathbf x = \Delta \mathbf x \cdot (\mathbf D + \mathbf W) \Delta \mathbf x = \Delta \mathbf x \cdot \mathbf D \Delta \mathbf x = (\Delta S)^2 \mathbf n \cdot \mathbf{Dn} $$

식(8)에 대입해서 정리하면 다음과 같다.
$$ \begin{equation} \frac{1}{\Delta S} \frac{D}{Dt} \Delta S = \mathbf n \cdot \mathbf{Dn} \end{equation} $$

$\mathbf n$방향에 있는 요소의 단위 길이당 길이의 시간변화율은 $\mathbf n \cdot \mathbf{Dn}$으로 표현되며 $D_{ii}$은 $\mathbf e$방향에 있는 요소의 단위 길이당 길이의 시간변화율을 나타낸다.

식(10)에서 알 수 있듯이, $\mathbf W$는 $\Delta \mathbf x$로 표현되는 요소의 길이 변화에 영향을 주지 않는다.

## 각도의 시간 변화율
이번에는 두 요소가 이루는 각도가 시간에 따라 어떻게 변화하는지 알아보자.

시간 $t$에서 요소가 다음과 같이 표현된다고 하자.
$$ \begin{gathered} \Delta \mathbf x = \Delta S_1 \mathbf n \\ \Delta \mathbf y = \Delta S_2 \mathbf m \end{gathered}  $$

따라서 다음이 성립한다.
$$ \begin{equation} \Delta \mathbf x \cdot \Delta \mathbf y  = \Delta S_1 \Delta S_2 \cos \theta \end{equation} $$

시간에 따른 변화율을 보기 위해 식(9)를 물질미분하면 다음과 같다.
$$ \begin{equation} \begin{aligned} \frac{D}{Dt} \Delta \mathbf x \cdot \Delta \mathbf y + \Delta \mathbf x \cdot \frac{D}{Dt} \Delta \mathbf y  = & \left( \frac{D}{Dt} \Delta S_1 \right) \Delta S_2 \cos \theta + \Delta S_1 \left( \frac{D}{Dt} \Delta S_2 \right) \cos \theta \\  &- \Delta S_1 \Delta S_2 \sin \theta \frac{D\theta}{Dt} \end{aligned} \end{equation} $$

식 (10)의 왼쪽항을 rate of deformation tensor와 spin tensor를 이용해서 표현하면 다음과 같다.
$$ \begin{aligned} & \frac{D}{Dt} \Delta \mathbf x \cdot \Delta \mathbf y + \Delta \mathbf x \cdot \frac{D}{Dt} \Delta \mathbf y \\ = \enspace & \nabla \mathbf v \Delta \mathbf x \cdot \Delta \mathbf y + \Delta \mathbf x \cdot \nabla \mathbf v \Delta \mathbf y \\ = \enspace & \Delta \mathbf x \cdot ( \nabla \mathbf v + (\nabla \mathbf v)^T) \Delta \mathbf y \\ = \enspace & 2 \Delta \mathbf x \cdot \mathbf D \Delta \mathbf y \\ = \enspace & 2 \Delta S_1 \Delta S_2 \mathbf n \cdot \mathbf D \mathbf m  \end{aligned} $$

식 (10)에 다시 대입해서 정리하면 다음과 같다.
$$ 2 \mathbf n \cdot \mathbf D \mathbf m =  \left( \frac{1}{\Delta S_1} \frac{D}{Dt} \Delta S_1 + \frac{1}{\Delta S_2} \frac{D}{Dt} \Delta S_2 \right) \cos \theta - \sin \theta \frac{D\theta}{Dt}$$

만약 $\mathbf {n = e,m = e_j}$이었다면, $2D_{ij}$는 $\mathbf e$방향과 $\mathbf e_j$방향에 있는 요소사이의 각도의 감소율을 나타낸다.

## 부피의 시간 변화율
$$ \frac{1}{\Delta V} \frac{D}{Dt} \Delta V = \text{div} (\mathbf v) $$

# infinitesimal rotation tensor
$\nabla \mathbf d$의 antisymmetric part  $\boldsymbol{\Omega} = (\nabla \mathbf d)^A$를 `infinitesimal rotation tensor`라고 한다.

$\mathbf t^A$가 $\boldsymbol{\Omega}$의 dual vector라고하면 다음이 성립한다.
$$ \mathbf t^A \times \Delta \bm X = \boldsymbol{\Omega} \Delta \bm X $$
$$ \text{Where, } \mathbf t^A = \Omega_{32} \mathbf e_1 + \Omega_{13} \mathbf e_2 + \Omega_{21} \mathbf e_3 $$

> 참고  
> [book] (Lai et al) Introduction to Continuum Mechanics Chapter 3.11
