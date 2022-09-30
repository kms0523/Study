# Deformation
운동하는 연속체의 reference figure를 $\Omega_0$라 하자.

시간 $t$에서 deformed figure $\Omega$의 위치가 벡터함수 $\varphi$로 나타난다고 하자.
$$ \varphi : \Omega_0 \times \R \rightarrow \Omega \quad  $$

그러면 $\varphi$에 의해서 연속체 내부에 있는 모든점의 변형된 위치가 서술된다. 

따라서 $\varphi$를 `변형(deformation)`이라고 한다.

# Displacement 
연속체 한 점의 `변위(displacement)` $\bf d$는 다음과 같이 정의한다.
$$ \mathbf d(\bm X, t) = \varphi(\bm X, t) - \bm X $$

# Deformation Gradient
Reference figure $\Omega_0$와 deforemd firuge $\Omega$가 있다고 하자.

두 점 $\bm X, \bm X + \Delta \bm X \in \Omega_0$이 있을 때, 두 점으로 이루어진 벡터 $\Delta \bm X$를 다음과 같이 정의하자.
$$ \Delta \bm X := (\bm X + \Delta \bm X) - \bm X $$

시간 $t$가 지난후 변형된 두 점 $\bm X, \bm X + \Delta \bm X$으로 이루어진 변형된 벡터를 $\Delta \mathbf x$라 하고 다음과 같이 정의하자.
$$ \Delta \mathbf x(t) := \varphi(\bm X + \Delta \bm X, t) - \varphi(\bm X,t) $$

$\Delta \bm X$가 충분히 작아 $\varphi (\bm X + \Delta \bm X, t)$를 선형으로 근사할 수 있다고 가정하면 $\Delta \mathbf x$는 다음과 같다.
$$ \begin{aligned} \Delta \mathbf x & \approx \frac{\partial p_i}{\partial X_j} \Delta X_j \\ & = \nabla \varphi \Delta \bm X \\ & =  (\mathbf I + \nabla \mathbf d )\Delta X \\ & = \mathbf F \Delta \bm X \end{aligned} $$

$$ \text{Where, } \mathbf F = \nabla \varphi = \mathbf I + \nabla \mathbf d $$

이 때, $\mathbf F$를 `deformation gradient`, $\nabla \mathbf d$를 `displacement gradient`라 한다.


### 명제1(Change of length)
두 점 $\bm X, \bm X + \Delta \bm X$이 있을 때, 두 점으로 이루어진 벡터를 $\Delta \bm X$, 변형된 벡터를 $\Delta x$가 다음을 만족한다고 하자.
$$ \Delta \bm X = l_0 \mathbf n, \enspace \Delta \mathbf x = l \mathbf m$$

$\bf n, m$이 단위벡터이고 $\Delta \bm X$가 충분히 작을 때, 다음을 증명하여라.
$$ l = \lVert \mathbf{Fn} \rVert l_0, \enspace \mathbf m = \frac{\mathbf F \mathbf n}{\lVert \mathbf F \mathbf n \rVert} $$

**Proof**

$\Delta \bm X$가 충분히 작음으로 다음이 성립한다.
$$ \begin{aligned} & \Delta \mathbf x = \mathbf F \Delta \bm X \\ \Rightarrow \enspace &  l \mathbf m = l_0 \mathbf F \mathbf n \end{aligned} $$

$\mathbf m$은 $\mathbf F \mathbf n$과 평행하고 단위방향 벡터임으로 다음이 성립한다.
$$ \mathbf m = \frac{\mathbf F \mathbf n}{\lVert \mathbf F \mathbf n \rVert} $$

이를 활용하면 다음이 성립한다.
$$ \begin{aligned} & l \mathbf m = l_0 \mathbf F \mathbf n \\ \Rightarrow \enspace & l \mathbf F \mathbf n = \lVert \mathbf F \mathbf n \rVert l_0 \mathbf F \mathbf n \\ \Rightarrow \enspace & l = \lVert \mathbf F \mathbf n \rVert l_0 \quad {_\blacksquare} \end{aligned} $$

### 명제2(Change of area)
세 점 $\bm X, \bm X + \Delta \bm X_1, \bm X + \Delta \bm X_2$이 있다고 하자

$\bm X, \bm X + \Delta \bm X_1$ 이루어진 벡터를 $\Delta \bm X_1$이라하고 $\bm X, \bm X + \Delta \bm X_2$ 이루어진 벡터를 $\Delta \bm X_2$, 변형된 벡터를 $\Delta x_1, \Delta x_2$가 다음을 만족한다고 하자.
$$ \Delta \bm X_1 \times \Delta \bm X_2 = A_0 \mathbf n, \enspace \Delta \mathbf x_1 \times \Delta \mathbf x_2 = A \mathbf m$$

$\bf n, m$이 단위벡터이고 $\Delta \bm X$가 충분히 작을 때, 다음을 증명하여라.
$$ A = \lVert \mathbf F^{-T} \mathbf n \rVert \det(\mathbf F) A_0, \enspace \mathbf m = \frac{\mathbf{F^{-T}n}}{\lVert \mathbf{F^{-T}n} \rVert} $$

**Proof**

$\Delta \bm X$가 충분히 작음으로 다음이 성립한다.
$$ \begin{aligned} & A \mathbf m = (\mathbf F \Delta \bm X_1) \times (\mathbf F \Delta \bm X_2) \\ \Rightarrow \enspace &  A \mathbf F \mathbf n \cdot  \mathbf m = \mathbf F \mathbf n \cdot (\mathbf F \Delta \bm X_1) \times (\mathbf F \Delta \bm X_2) \\ \Rightarrow \enspace &  A \mathbf n \cdot \mathbf F^T \mathbf m = \det( \mathbf {FX}) \\ \Rightarrow \enspace &  A  \mathbf F^T \mathbf m = \det(\mathbf F)\det(\mathbf X) \mathbf n \\ \Rightarrow \enspace &  A  \mathbf m = \det(\mathbf F) A_0 \mathbf F^{-T} \mathbf n \end{aligned} $$

$$ \text{Where, } \mathbf X = \begin{bmatrix} \mathbf n & \Delta \bm X_1 & \Delta \bm X_2 \end{bmatrix} $$

$\mathbf m$은 $\mathbf F^{-T} \mathbf n$과 평행하고 단위방향 벡터임으로 다음이 성립한다.
$$ \mathbf m = \frac{\mathbf F^{-T} \mathbf n}{\lVert \mathbf F^{-T} \mathbf n \rVert} $$

이를 활용하면 다음이 성립한다.
$$ \begin{aligned} &  A \mathbf m = A_0 \det(\mathbf F) \mathbf F^{-T} \mathbf n \\ \Rightarrow \enspace & A \mathbf F^{-T} \mathbf n = \lVert \mathbf F^{-T} \mathbf n \rVert \det(\mathbf F) A_0 \mathbf F^{-T} \mathbf n \\ \Rightarrow \enspace & A = \lVert \mathbf F^{-T} \mathbf n \rVert \det(\mathbf F) A_0 \quad {_\blacksquare} \end{aligned} $$

### 명제3(Change of volume)
네 점 $\bm X, \bm X + \Delta \bm X_1, \bm X + \Delta \bm X_2, \bm X + \Delta \bm X_3$이 있다고 하자

$\bm X, \bm X + \Delta \bm X_{1,2,3}$ 이루어진 벡터를 $\Delta \bm X_{1,2,3}$이라하고 변형된 벡터를 $\Delta x_{1,2,3}$라 할 떄, 다음을 만족한다고 하자.
$$ \Delta \bm X_1 \cdot \Delta \bm X_2 \times \Delta \bm X_3 = V_0 , \enspace \Delta \mathbf x_1 \cdot \Delta \mathbf x_2 \times \Delta \mathbf x_2 = V$$

$\Delta \bm X$가 충분히 작을 때, 다음을 증명하여라.
$$ V = \det(\mathbf F) V_0 $$

**Proof**

$\Delta \bm X$가 충분히 작음으로 다음이 성립한다.
$$ \begin{aligned} V &= (F\Delta \bm X_1) \cdot (F\Delta \bm X_2) \times (F\Delta \bm X_3) \\ &=  \det(\mathbf{FX}) \\ &= \det(\mathbf F) V_0 \quad {_\blacksquare} \end{aligned} $$

$$ \text{Where, } \mathbf X = \begin{bmatrix} \Delta \bm X_1 & \Delta \bm X_2 & \Delta \bm X_3 \end{bmatrix} $$