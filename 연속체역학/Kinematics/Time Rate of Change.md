# Time Rate of Deformation
Deformation $\varphi$가 있다고 하자.
$$ x(X,t) := \varphi(X,t) $$

$\varphi$를 시간으로 편미분하면 연속체의 한 점을 고정한 채 연속체의 한 점이 공간상의 차지하는 한 점(위치)의 시간에 따른 변화량, 즉 속도 $V$를 얻게 된다.
$$ V(X,t) := \frac{\partial \varphi}{\partial t}  $$

### 참고
$V$를 spatial description으로 나타낸 함수 $v$를 다음과 같이 정의한다.
$$ v(x,t) = V \circ \varphi^{-1} $$


> 참고  
> [book] (Lai et al) Introduction to Continuum Mechanics Chapter 3.12

### 명제1
Deformation $\varphi$와 이에 따른 속도 $V$가 있다고 하자.

점 $X \in \Omega_0$와 vector $\Delta X$가 있을 때, 점 $x \in \Omega$와 vector $\Delta x$를 다음과 같이 정의하자.
$$ \begin{aligned} x &:= \varphi(X,t) \\ \Delta x &:= \varphi(X + \Delta X, t) - \varphi(X, t) \end{aligned} $$


$\Delta X$가 충분히 작을 때, 다음을 증명하여라.
$$ \frac{D}{Dt} \Delta x = (\nabla_{X} V) \Delta X $$

**Proof**

$\Delta x$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial}{\partial t} \Delta x &= \frac{\partial}{\partial t} \varphi(X + \Delta X, t) - \frac{\partial}{\partial t} \varphi(X, t) \\ &= V(X + \Delta X,t) - V(X,t) \end{aligned} $$

$\Delta X$가 충분히 작아 $V(X + \Delta X,t)$를 선형으로 근사할 수 있다고 가정하면 다음과 같다.
$$ \begin{aligned} \frac{\partial}{\partial t} \Delta x &= V(X + \Delta X,t) - V(X,t) \\&= V(X,t) + \nabla_X V \Delta X - V(X,t) \\&= \nabla_{X} V \Delta X \quad {_\blacksquare} \end{aligned} $$

> 참고  
> [book] (Lai et al) Introduction to Continuum Mechanics Chapter 3.12

### 명제2
Deformation $\varphi$와 이에 따른 속도 $V$가 있다고 하자.

점 $X \in \Omega_0$와 vector $\Delta X$가 있을 때, 점 $x \in \Omega$와 vector $\Delta x$를 다음과 같이 정의하자.
$$ \begin{aligned} x &:= \varphi(X,t) \\ \Delta x &:= \varphi(X + \Delta X, t) - \varphi(X, t) \end{aligned} $$

$\Delta x$가 충분히 작을 때, 다음을 증명하여라.
$$ \frac{\partial}{\partial t} \Delta x = (\nabla_{x} v) \Delta x $$

**Proof**

명제1과 $v$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial}{\partial t} \Delta x &= V(X + \Delta X,t) - V(X,t) \\&= (v \circ \varphi)(X + \Delta X,t) - (v \circ \varphi)(X,t) \\&= v(x + \Delta x, t) - v(x, t)  \end{aligned} $$

$\Delta x$가 충분히 작아 $v(x + \Delta x,t)$를 선형으로 근사할 수 있음으로 다음이 성립한다
$$ \begin{aligned} \frac{\partial}{\partial t} \Delta x &= v(x + \Delta x,t) - v(x,t) \\&= v(x,t) + \nabla_x v \Delta x - v(x,t) \\&= \nabla_{x} v \Delta x \quad {_\blacksquare} \end{aligned} $$

> 참고  
> [book] (Lai et al) Introduction to Continuum Mechanics Chapter 3.12

# Time Rate of Deformation Gradient
### 명제1
Deformation $\varphi$와 이에 따른 속도 $V$가 있다고 하자.

Deformation gradient $F$가 있을 때, 다음을 증명하여라.
$$ \frac{\partial F}{\partial t} = \nabla_X V  $$

**Proof**

Deformation gradient $F$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial F_{ij}}{\partial t} &=  \frac{\partial }{\partial t}\frac{\partial \varphi_i}{\partial X_j} \\&= \frac{\partial }{\partial X_j}\frac{\partial \varphi_i}{\partial t} \\&= \frac{\partial V_i }{\partial X_j} \quad {_\blacksquare} \end{aligned} $$

### 명제2
Deformation $\varphi$와 이에 따른 속도 $V$가 있다고 하자.

Deformation gradient $F$가 있을 때, 다음을 증명하여라.
$$ \frac{\partial F}{\partial t} = \nabla_x v F $$

**Proof**

명제 1과 $v$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial F_i}{\partial t} &= \frac{\partial V_i }{\partial X_j} \\&= \frac{\partial}{\partial X_j} (v \circ \varphi)_i \\&= \frac{\partial v_i}{\partial \varphi_j} \frac{\partial \varphi_j}{\partial X_k} \\&= \frac{\partial v_i}{\partial x_j} F_{jk} \quad {_\blacksquare} \end{aligned} $$