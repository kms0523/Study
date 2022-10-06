# Rate of Deformation Tensor
Deformation $\varphi$와 이에 따른 속도 $v(x,t)$가 있다고 하자.

$\nabla_x v$를 다음과 같이 symmetric part와 antisymmetric part로 나눠보자.
$$ \nabla_x v = D + W $$
$$ \text{Where, } D = \frac{1}{2} \left( \nabla_x v + (\nabla_x v)^T \right), \quad W = \frac{1}{2} \left( \nabla_x v - (\nabla_x v)^T \right)  $$

이 때, $D$를 `rate of deformation tensor` $W$를 `spin tensor`라고 한다.

### 참고
$W$는 antisymmetric tensor임으로 dual vector를 $\boldsymbol \omega$라 할 때, 다음을 만족한다.
$$ W \Delta x = \boldsymbol \omega \times \Delta x $$

$W$의 단위가 $/s$임으로, $W$은 $\Delta x$를 각속도 $\boldsymbol{\omega}$로 회전 시킨다는것을 알 수 있다.

벡터의 시간변화율을 $D, W$로 나타내면 다음과 같다.
$$ \frac{\partial}{\partial t} \Delta x = \nabla_x v \Delta x = D \Delta x + W \Delta x = D \Delta x + \boldsymbol \omega \times \Delta x$$

> 참고  
> [book] (Lai et al) Introduction to Continuum Mechanics Chapter 3.13

### 명제1
Reference figure $\Omega_0$, deformation $\varphi$, defromation gradient $F$가 있다고 하자.

점 $X \in \Omega_0$와 vector $\Delta X$가 있을 때, 점 $x \in \Omega$와 vector $\Delta x$를 다음과 같이 정의하자.
$$ \begin{aligned} x &:= \varphi(X,t) \\ \Delta x &:= \varphi(X + \Delta X, t) - \varphi(X, t) \end{aligned} $$

이 때, vector $\Delta x$를 크기 $l$과 단위 vector $m$으로 나타내자.
$$ \Delta x = lm $$

 $\Delta X$가 충분히 작을 때, 다음을 증명하여라.
$$ \frac{1}{l} \frac{\partial l}{\partial t} = m \cdot Dm $$

**Proof**

time rate of change의 명제에 의해 다음이 성립한다. 
$$ \frac{1}{l} \frac{\partial l}{\partial t} = m \cdot (\nabla_xv)m $$



$$ \begin{aligned} & l^2 = \Delta x \cdot \Delta x \\ \Rightarrow \enspace & 2 l \frac{\partial l}{\partial t} = 2 \Delta x \cdot \frac{\partial}{\partial t} \Delta x \\ \Rightarrow \enspace & l \frac{\partial l}{\partial t} = l^2 m \cdot \nabla_x v m \\ \Rightarrow \enspace & \frac{1}{l} \frac{\partial l}{\partial t} = m \cdot (D + W) m  \end{aligned} $$

보조명제에 의해 다음이 성립한다.
$$ \begin{aligned} & \frac{1}{l} \frac{\partial l}{\partial t} = m \cdot (D + W) m  \\ \Rightarrow \enspace & \frac{1}{l} \frac{\partial l}{\partial t} = m \cdot D m \quad {_\blacksquare}  \end{aligned} $$

**Proof2**

vector $\Delta X$를 크기 $l_0$와 단위 vector $n$으로 나타내자.
$$ \Delta X = l_0n $$

그러면 deformation gradient의 성질에 의해 다음이 성립한다.
$$ l = \lVert Fn \rVert l_0, \enspace m = \frac{Fn}{\lVert Fn \rVert} $$

따라서, 다음이 성립한다.
$$ \begin{aligned} \frac{\partial l}{ \partial t} &= l_0 \frac{\partial}{\partial t} (Fn \cdot Fn)^{1/2} \\&= l_0 \frac{1}{2} (Fn \cdot Fn)^{-1/2} \frac{\partial}{\partial t} (Fn \cdot Fn) \\&= l_0 \frac{1}{\lVert Fn \rVert} Fn \cdot (\frac{\partial}{\partial t} F)n \\&= l_0m \cdot \nabla _x vFn \\&= l m \cdot (D + W) m \end{aligned} $$

이 때, 보조명제에 의해 다음이 성립한다.
$$ \frac{1}{l}\frac{\partial l}{ \partial t} = m \cdot D m \quad {_\blacksquare} $$

#### 보조명제
$A \in M_{nn}(\mathbb F)$와 $x \in M_{n1}(\mathbb F)$가 있다고 하자.

$A$가 Anti symmetric matrix일 때, 다음을 증명하여라.
$$ x \cdot A x = 0 $$

**Proof**

내적의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} x \cdot A x &= A x \cdot x \\&= x^T A^T x \\&= x \cdot A^T x \\&= - x \cdot A x \end{aligned} $$

따라서 다음이 성립한다.
$$ 2 x \cdot Ax = 0 \enspace \Rightarrow \enspace x \cdot Ax = 0 \quad {_\blacksquare} $$

#### 참고
$n$방향에 있는 요소의 단위 길이당 길이의 시간변화율은 $n \cdot Dn$으로 표현되며 $D_{ii}$은 $e$방향에 있는 요소의 단위 길이당 길이의 시간변화율을 나타낸다.

식(10)에서 알 수 있듯이, $W$는 $\Delta x$로 표현되는 요소의 길이 변화에 영향을 주지 않는다.

## 각도의 시간 변화율
이번에는 두 요소가 이루는 각도가 시간에 따라 어떻게 변화하는지 알아보자.

시간 $t$에서 요소가 다음과 같이 표현된다고 하자.
$$ \begin{gathered} \Delta x = l_1 n \\ \Delta y = l_2 m \end{gathered}  $$

따라서 다음이 성립한다.
$$ \begin{equation} \Delta x \cdot \Delta y  = l_1 l_2 \cos \theta \end{equation} $$

시간에 따른 변화율을 보기 위해 식(9)를 물질미분하면 다음과 같다.
$$ \begin{equation} \begin{aligned} \frac{\partial}{\partial t} \Delta x \cdot \Delta y + \Delta x \cdot \frac{\partial}{\partial t} \Delta y  = & \left( \frac{\partial}{\partial t} l_1 \right) l_2 \cos \theta + l_1 \left( \frac{\partial}{\partial t} l_2 \right) \cos \theta \\  &- l_1 l_2 \sin \theta \frac{D\theta}{Dt} \end{aligned} \end{equation} $$

식 (10)의 왼쪽항을 rate of deformation tensor와 spin tensor를 이용해서 표현하면 다음과 같다.
$$ \begin{aligned} & \frac{\partial}{\partial t} \Delta x \cdot \Delta y + \Delta x \cdot \frac{\partial}{\partial t} \Delta y \\ = \enspace & \nabla_x v \Delta x \cdot \Delta y + \Delta x \cdot \nabla_x v \Delta y \\ = \enspace & \Delta x \cdot ( \nabla_x v + (\nabla_x v)^T) \Delta y \\ = \enspace & 2 \Delta x \cdot D \Delta y \\ = \enspace & 2 l_1 l_2 n \cdot D m  \end{aligned} $$

식 (10)에 다시 대입해서 정리하면 다음과 같다.
$$ 2 n \cdot D m =  \left( \frac{1}{l_1} \frac{\partial}{\partial t} l_1 + \frac{1}{l_2} \frac{\partial}{\partial t} l_2 \right) \cos \theta - \sin \theta \frac{D\theta}{Dt}$$

만약 ${n = e,m = e_j}$이었다면, $2D_{ij}$는 $e$방향과 $e_j$방향에 있는 요소사이의 각도의 감소율을 나타낸다.

## 부피의 시간 변화율
$$ \frac{1}{\Delta V} \frac{\partial}{\partial t} \Delta V = \text{div} (v) $$