# Time Rate of Deformation
Reference figure $\Omega_0$와 deforemd firuge $\Omega$ 그리고 deformation $\varphi$가 있다고 하자.

$\varphi$를 시간으로 편미분하면 연속체의 한 점의 시간에 따른 위치 변화량, 즉 `속도(velocity)` $V$를 얻게 된다.
$$ V(X,t) := \frac{\partial \varphi}{\partial t}  $$

### 참고
$V$를 spatial description으로 나타낸 함수 $v$를 다음과 같이 정의한다.
$$ v(x,t) := V \circ \varphi^{-1} $$

따라서, 다음 관계식이 성립한다.
$$ V = v \circ \varphi $$


> 참고  
> [book] (Lai et al) Introduction to Continuum Mechanics Chapter 3.12

# Time Rate of Deformation Gradient
### 명제1
Reference figure $\Omega_0$와 deforemd firuge $\Omega$ 그리고 deformation $\varphi$가 있다고 하자.

Deformation gradient $F$와 $\varphi$에 따른 속도 $V(X,t)$가 있을 때, 다음을 증명하여라.
$$ \frac{\partial F}{\partial t} = \nabla_X V  $$

**Proof**

$F$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial F_{ij}}{\partial t} &=  \frac{\partial }{\partial t}\frac{\partial \varphi_i}{\partial X_j} \\&= \frac{\partial }{\partial X_j}\frac{\partial \varphi_i}{\partial t} \\&= \frac{\partial V_i }{\partial X_j} \quad {_\blacksquare} \end{aligned} $$

### 명제2
Deformation $\varphi$와 이에 따른 속도 $v(x,t)$가 있다고 하자.

Deformation gradient $F$가 있을 때, 다음을 증명하여라.
$$ \frac{\partial F}{\partial t} = \nabla_x v F $$

**Proof**

명제1과 $v$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial F_i}{\partial t} &= \frac{\partial V_i }{\partial X_j} \\&= \frac{\partial}{\partial X_j} (v \circ \varphi)_i \\&= \frac{\partial v_i}{\partial \varphi_j} \frac{\partial \varphi_j}{\partial X_k} \\&= \frac{\partial v_i}{\partial x_j} F_{jk} \quad {_\blacksquare} \end{aligned} $$

#### 명제2.1
Deformation $\varphi$와 이에 따른 속도 $V(X,t), v(x,t)$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ \nabla_XV = \nabla_x vF $$

**Proof**

명제1과 2에의해 성립한다.

### 명제3
deformation $\varphi$와 deformation gradient $F$ 그리고 그에 따른 속도 $v(x,t)$가 있다고 하자.

이 떄, 다음을 증명하여라.
$$ \frac{\partial}{\partial t} \det(F) = \text{div}(v)\det(F) $$

**Proof**

Jacobi's theorem과 $F$의 시간변화율에 의한 성질에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial}{\partial t} \det(F) &= \det(F) \text{tr}(F' F^{-1}) \\&= \det(F)\text{tr}(\nabla_x v) \\&= \det(F)\text{div}(v) \quad {_\blacksquare} \end{aligned} $$

# Other Time Rates

### 명제1
Deformation $\varphi$와 이에 따른 속도 $V(X,t)$가 있다고 하자.

점 $X \in \Omega_0$와 vector $\Delta X$가 있을 때, 점 $x \in \Omega$와 vector $\Delta x$를 다음과 같이 정의하자.
$$ \begin{aligned} x &:= \varphi(X,t) \\ \Delta x &:= \varphi(X + \Delta X, t) - \varphi(X, t) \end{aligned} $$

$\Delta X$가 충분히 작을 때, 다음을 증명하여라.
$$ \frac{\partial}{\partial t} \Delta x = (\nabla_{X} V) \Delta X $$

**Proof**

$\Delta x$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial}{\partial t} \Delta x &= \frac{\partial}{\partial t} \varphi(X + \Delta X, t) - \frac{\partial}{\partial t} \varphi(X, t) \\ &= V(X + \Delta X,t) - V(X,t) \end{aligned} $$

$\Delta X$가 충분히 작아 $V(X + \Delta X,t)$를 선형으로 근사할 수 있다고 가정하면 다음과 같다.
$$ \begin{aligned} \frac{\partial}{\partial t} \Delta x &= V(X + \Delta X,t) - V(X,t) \\&= V(X,t) + \nabla_X V \Delta X - V(X,t) \\&= \nabla_{X} V \Delta X \quad {_\blacksquare} \end{aligned} $$

> 참고  
> [book] (Lai et al) Introduction to Continuum Mechanics Chapter 3.12

### 명제2
Deformation $\varphi$와 이에 따른 속도 $v(x,t)$가 있다고 하자.

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

### 명제3
Reference figure $\Omega_0$, deformation $\varphi$, defromation gradient $F$가 있다고 하자.

점 $X \in \Omega_0$와 vector $\Delta X$가 있을 때, 점 $x \in \Omega$와 vector $\Delta x$를 다음과 같이 정의하자.
$$ \begin{aligned} x &:= \varphi(X,t) \\ \Delta x &:= \varphi(X + \Delta X, t) - \varphi(X, t) \end{aligned} $$

이 때, vector $\Delta x$를 크기 $l$과 단위 vector $m$으로 나타내자.
$$ \Delta x = lm $$

 $\Delta X$가 충분히 작을 때, 다음을 증명하여라.
$$ \frac{1}{l} \frac{\partial l}{\partial t} = m \cdot (\nabla_xv)m $$

**Proof1**

$\Delta x$의 정의에 의해 다음이 성립한다. 
$$ \begin{aligned} & l^2 = \Delta x \cdot \Delta x \\ \Rightarrow \enspace & 2 l \frac{\partial l}{\partial t} = 2 \Delta x \cdot \frac{\partial}{\partial t} \Delta x \\ \Rightarrow \enspace & l \frac{\partial l}{\partial t} = l^2 m \cdot \nabla_x v m \\ \Rightarrow \enspace & \frac{1}{l} \frac{\partial l}{\partial t} = m \cdot (\nabla_xv) m  \end{aligned} $$

**Proof2**

vector $\Delta X$를 크기 $l_0$와 단위 vector $n$으로 나타내자.
$$ \Delta X = l_0n $$

그러면 deformation gradient의 성질에 의해 다음이 성립한다.
$$ l = \lVert Fn \rVert l_0, \enspace m = \frac{Fn}{\lVert Fn \rVert} $$

따라서, 다음이 성립한다.
$$ \begin{aligned} \frac{\partial l}{ \partial t} &= l_0 \frac{\partial}{\partial t} (Fn \cdot Fn)^{1/2} \\&= l_0 \frac{1}{2} (Fn \cdot Fn)^{-1/2} \frac{\partial}{\partial t} (Fn \cdot Fn) \\&= l_0 \frac{1}{\lVert Fn \rVert} Fn \cdot (\frac{\partial}{\partial t} F)n \\&= l_0m \cdot \nabla _x vFn \\&= l m \cdot (\nabla_xv) m \end{aligned} $$

### 명제4
deformation $\varphi$와 그에 따른 속도 $v(x,t)$가 있다고 하자.

$X \in \Omega_0$와 vector $\Delta X_{1,2,3}$가 있을 때, $x \in \Omega$와 vector $\Delta x_{1,2,3}$를 다음과 같이 정의하자.
$$ \begin{aligned} x &:= \varphi(X,t) \\ \Delta x_{1,2,3} &:= \varphi(X + \Delta X_{1,2,3}, t) - \varphi(X, t) \end{aligned} $$

이 떄, vector $\Delta x_{1,2,3}$로 이루어진 부피를 $\rm V$ 표현하자.
$$ \rm V:= \Delta  x_1 \cdot \Delta  x_2 \times \Delta  x_2$$

$\Delta X_{1,2,3}$가 충분히 작을 때, 다음을 증명하여라.
$$ \frac{1}{\rm V} \frac{\partial \rm V}{\partial t} = \text{div}(v) $$

**Proof**

Vector $\Delta X_{1,2,3}$로 이루어진 부피를 $\rm V_0$라 하자.
$$ \mathrm V_0 := \Delta X_1 \cdot \Delta X_2 \times \Delta X_3 $$

Deformation gradient를 $F$라 할 때, $\Delta X_{1,2,3}$가 충분히 작기 때문에 다음이 성립한다.
$$ \begin{aligned} \mathrm V &= \det(F) \mathrm V_0 \\ \Rightarrow \enspace \frac{\partial \rm V}{\partial t} &= \frac{\partial \det(F)}{\partial t} \mathrm V_0 \end{aligned}  $$

Jacobi's Theorem과 $F$의 시간변화율에 대한 성질에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial \rm V}{\partial t} &= \frac{\partial \det(F)}{\partial t} \mathrm V_0 \\&= \mathrm V \text{tr} \bigg( \frac{\partial F}{\partial t} F^{-1} \bigg) \\ \frac{1}{\mathrm V}\frac{\partial \rm V}{\partial t} &= \text{tr}(\nabla_x v) \\&= \text{div}(v) \quad {_\blacksquare} \end{aligned}  $$