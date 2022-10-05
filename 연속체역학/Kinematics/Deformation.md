# Deformation
운동하는 연속체의 reference figure를 $\Omega_0$라 하자.

시간 $t$에서 deformed figure $\Omega$의 위치가 벡터함수 $\varphi$로 나타난다고 하자.
$$ \varphi : \Omega_0 \times \R \rightarrow \Omega \quad  $$

그러면 $\varphi$에 의해서 연속체 내부에 있는 모든점의 변형된 위치가 서술된다. 

따라서 $\varphi$를 `변형(deformation)`이라고 한다.

### 참고
$\varphi$는 특정 점의 특정 시간에서 변형된 위치를 서술함으로 물리적으로 말이 되기 위해서는 반드시 전단사 함수여야 한다.

따라서, $\varphi$는 역함수가 존재한다.

# Displacement 
연속체 한 점의 `변위(displacement)` $\bf d$는 다음과 같이 정의한다.
$$  d(X, t) = \varphi(X, t) - X $$

# Deformation Gradient
Reference figure $\Omega_0$와 deforemd firuge $\Omega$가 있다고 하자.

두 점 $X, X + \Delta X \in \Omega_0$이 있을 때, 두 점으로 이루어진 벡터 $\Delta X$를 다음과 같이 정의하자.
$$ \Delta X := (X + \Delta X) - X $$

시간 $t$가 지난후 변형된 두 점 $X, X + \Delta X$으로 이루어진 변형된 벡터를 $\Delta  x$라 하고 다음과 같이 정의하자.
$$ \Delta  x(t) := \varphi(X + \Delta X, t) - \varphi(X,t) $$

$\Delta X$가 충분히 작아 $\varphi (X + \Delta X, t)$를 선형으로 근사할 수 있다고 가정하면 $\Delta  x$는 다음과 같다.
$$ \begin{aligned} \Delta  x & \approx \frac{\partial \varphi_i}{\partial X_j} \Delta X_j \\ & = \nabla \varphi \Delta X \\ & =  ( I + \nabla  d )\Delta X \\ & =  F \Delta X \end{aligned} $$

$$ \text{Where, }  F = \nabla \varphi =  I + \nabla  d $$

이 때, $ F$를 `deformation gradient`, $\nabla  d$를 `displacement gradient`라 한다.


### 명제1(Change of length)
Reference figure $\Omega_0$, deformation $\varphi$, defromation gradient $F$가 있다고 하자.

두 점 $X, X + \Delta X \in \Omega_0$이 있을 때, 두 점으로 이루어진 vector $\Delta X, \Delta x$를 다음과 같이 정의하자.
$$ \begin{aligned} \Delta X &= l_0n  \\ \Delta x &= \varphi(X + \Delta X, t) - \varphi(X, t) = lm \end{aligned} $$

이 때, $l_0, l$은 길이를 나타내는 scalar 값이고 $n,m$은 단위벡터이다.

 $\Delta X$가 충분히 작을 때, 다음을 증명하여라.
$$ l = \lVert Fn \rVert l_0, \enspace m = \frac{Fn}{\lVert Fn \rVert} $$

**Proof**

$\Delta X$가 충분히 작음으로 다음이 성립한다.
$$ \begin{aligned} & \Delta  x =  F \Delta X \\ \Rightarrow \enspace &  l  m = l_0  F  n \end{aligned} $$

$ m$은 $ F  n$과 평행하고 단위방향 벡터임으로 다음이 성립한다.
$$  m = \frac{ F  n}{\lVert  F  n \rVert} $$

이를 활용하면 다음이 성립한다.
$$ \begin{aligned} & l  m = l_0  F  n \\ \Rightarrow \enspace & l  F  n = \lVert  F  n \rVert l_0  F  n \\ \Rightarrow \enspace & l = \lVert  F  n \rVert l_0 \quad {_\blacksquare} \end{aligned} $$

### 명제2(Change of area)
세 점 $X, X + \Delta X_1, X + \Delta X_2$이 있다고 하자

$X, X + \Delta X_1$ 이루어진 벡터를 $\Delta X_1$이라하고 $X, X + \Delta X_2$ 이루어진 벡터를 $\Delta X_2$, 변형된 벡터를 $\Delta x_1, \Delta x_2$가 다음을 만족한다고 하자.
$$ \Delta X_1 \times \Delta X_2 = A_0  n, \enspace \Delta  x_1 \times \Delta  x_2 = A  m$$

$\bf n, m$이 단위벡터이고 $\Delta X$가 충분히 작을 때, 다음을 증명하여라.
$$ A = \lVert  F^{-T}  n \rVert \det( F) A_0, \enspace  m = \frac{{F^{-T}n}}{\lVert {F^{-T}n} \rVert} $$

**Proof**

$\Delta X$가 충분히 작음으로 다음이 성립한다.
$$ \begin{aligned} & A  m = ( F \Delta X_1) \times ( F \Delta X_2) \\ \Rightarrow \enspace &  A  F  n \cdot   m =  F  n \cdot ( F \Delta X_1) \times ( F \Delta X_2) \\ \Rightarrow \enspace &  A  n \cdot  F^T  m = \det(  {FX}) \\ \Rightarrow \enspace &  A   F^T  m = \det( F)\det( X)  n \\ \Rightarrow \enspace &  A   m = \det( F) A_0  F^{-T}  n \end{aligned} $$

$$ \text{Where, }  X = \begin{bmatrix}  n & \Delta X_1 & \Delta X_2 \end{bmatrix} $$

$ m$은 $ F^{-T}  n$과 평행하고 단위방향 벡터임으로 다음이 성립한다.
$$  m = \frac{ F^{-T}  n}{\lVert  F^{-T}  n \rVert} $$

이를 활용하면 다음이 성립한다.
$$ \begin{aligned} &  A  m = A_0 \det( F)  F^{-T}  n \\ \Rightarrow \enspace & A  F^{-T}  n = \lVert  F^{-T}  n \rVert \det( F) A_0  F^{-T}  n \\ \Rightarrow \enspace & A = \lVert  F^{-T}  n \rVert \det( F) A_0 \quad {_\blacksquare} \end{aligned} $$

### 명제3(Change of volume)
네 점 $X, X + \Delta X_1, X + \Delta X_2, X + \Delta X_3$이 있다고 하자

$X, X + \Delta X_{1,2,3}$ 이루어진 벡터를 $\Delta X_{1,2,3}$이라하고 변형된 벡터를 $\Delta x_{1,2,3}$라 할 떄, 다음을 만족한다고 하자.
$$ \Delta X_1 \cdot \Delta X_2 \times \Delta X_3 = V_0 , \enspace \Delta  x_1 \cdot \Delta  x_2 \times \Delta  x_2 = V$$

$\Delta X$가 충분히 작을 때, 다음을 증명하여라.
$$ V = \det( F) V_0 $$

**Proof**

$\Delta X$가 충분히 작음으로 다음이 성립한다.
$$ \begin{aligned} V &= (F\Delta X_1) \cdot (F\Delta X_2) \times (F\Delta X_3) \\ &=  \det({FX}) \\ &= \det( F) V_0 \quad {_\blacksquare} \end{aligned} $$

$$ \text{Where, }  X = \begin{bmatrix} \Delta X_1 & \Delta X_2 & \Delta X_3 \end{bmatrix} $$