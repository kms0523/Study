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
Reference figure $\Omega_0$와 deforemd firuge $\Omega$ 그리고 deformation $\varphi$가 있다고 하자.

점 $X \in \Omega_0$와 vector $\Delta X$가 있을 때, 점 $x \in \Omega$와 vector $\Delta x$를 다음과 같이 정의하자.
$$ \begin{aligned} x &:= \varphi(X,t) \\ \Delta x &:= \varphi(X + \Delta X, t) - \varphi(X, t) \end{aligned} $$

이 때, vector $\Delta x$를 크기 $l$과 단위 vector $m$으로 나타내자.
$$ \Delta x = lm $$

 $\Delta X$가 충분히 작을 때, 다음을 증명하여라.
$$ \frac{1}{l} \frac{\partial l}{\partial t} = m \cdot Dm $$

**Proof**

Time rate of change의 명제에 의해 다음이 성립한다. 
$$ \begin{aligned} \frac{1}{l} \frac{\partial l}{\partial t} &= m \cdot (\nabla_xv)m \\&= m \cdot (D + W)m \end{aligned} $$

명제1.1에 의해 다음이 성립한다.
$$ \begin{aligned} & \frac{1}{l} \frac{\partial l}{\partial t} = m \cdot (D + W) m  \\ \Rightarrow \enspace & \frac{1}{l} \frac{\partial l}{\partial t} = m \cdot D m \quad {_\blacksquare}  \end{aligned} $$

#### 명제1.1
$A \in M_{nn}(\mathbb F)$와 $x \in M_{n1}(\mathbb F)$가 있다고 하자.

$A$가 Anti symmetric matrix일 때, 다음을 증명하여라.
$$ x \cdot A x = 0 $$

**Proof**

내적의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} x \cdot A x &= A x \cdot x \\&= x^T A^T x \\&= x \cdot A^T x \\&= - x \cdot A x \end{aligned} $$

따라서 다음이 성립한다.
$$ 2 x \cdot Ax = 0 \enspace \Rightarrow \enspace x \cdot Ax = 0 \quad {_\blacksquare} $$

#### 참고
$W$는 길이 변화에 영향을 주지 않는다.

### 명제2
Rate deformation tensor $D$와 infinitesimal strain tensor $E$가 있다고 하자.

small deformation을 가정할 때, 다음을 증명하여라.
$$ D = \frac{\partial E}{\partial t} $$

**Proof**

$E$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial E}{\partial t} &= \frac{\partial E_{ij}}{\partial t}e_{ij} \\&=\frac{1}{2} \frac{\partial }{\partial t} \bigg( \frac{\partial d_i}{\partial X_j} + \frac{\partial d_j}{\partial X_i} \bigg)e_{ij} \\&= \frac{1}{2} \bigg( \frac{\partial}{\partial X_j}\frac{\partial d_i}{\partial t} + \frac{\partial}{\partial X_i}\frac{\partial d_j}{\partial t} \bigg) e_{ij} \\&= \frac{1}{2} \bigg( \frac{\partial}{\partial X_j}\frac{\partial (x_i -X_i)}{\partial t} + \frac{\partial}{\partial X_i}\frac{\partial (x_j -X_j)}{\partial t} \bigg) e_{ij} \\&= \frac{1}{2} \bigg( \frac{\partial V_i}{\partial X_j} + \frac{\partial V_j}{\partial X_i} \bigg) e_{ij} \\&= \frac{1}{2} \bigg( \frac{\partial v_i}{\partial x_k}\frac{\partial x_k}{\partial X_j} + \frac{\partial v_j}{\partial x_k}\frac{\partial x_k}{\partial X_i} \bigg) e_{ij} \\&= \frac{1}{2} \bigg( \frac{\partial v_i}{\partial x_k}\frac{\partial (X_k + d_k)}{\partial X_j} + \frac{\partial v_j}{\partial x_k}\frac{\partial (X_k + d_k)}{\partial X_i} \bigg) e_{ij} \\&= \frac{1}{2} \bigg( \frac{\partial v_i}{\partial x_k}\delta_{kj} + \frac{\partial v_i}{\partial x_k}\frac{\partial d_k}{\partial X_j} + \frac{\partial v_j}{\partial x_k} \delta_{ki} + \frac{\partial v_j}{\partial x_k}\frac{\partial d_k}{\partial X_i} \bigg) e_{ij} \end{aligned} $$

Small deformation 가정에 의해 다음이 성립한다고 하자.
$$  \bigg \lVert \frac{\partial v}{\partial x} \bigg\rVert \ll1, \enspace \bigg\lVert \frac{\partial d}{\partial X} \bigg\rVert \ll 1 $$

미소항의 고차항을 무시하면 다음이 성립한다.
$$ \begin{aligned} \frac{\partial E}{\partial t} &= \frac{1}{2} \bigg( \frac{\partial v_i}{\partial x_k}\delta_{kj} + \frac{\partial v_i}{\partial x_k}\frac{\partial d_k}{\partial X_j} + \frac{\partial v_j}{\partial x_k} \delta_{ki} + \frac{\partial v_j}{\partial x_k}\frac{\partial d_k}{\partial X_i} \bigg) e_{ij} \\&= \frac{1}{2} \bigg( \frac{\partial v_i}{\partial x_j} + \frac{\partial v_j}{\partial x_i} \bigg) e_{ij} \\&= D_{ij}e_{ij} \\&= D \quad {_\blacksquare} \end{aligned} $$

> Reference  
> [book] (Lai et al) Introduction to Continuum Mechanics Example 5.2.1 (a)  

## 각도의 시간 변화율
이번에는 두 요소가 이루는 각도가 시간에 따라 어떻게 변화하는지 알아보자.

시간 $t$에서 요소가 다음과 같이 표현된다고 하자.
$$ \begin{gathered} \Delta x = l_1 n \\ \Delta y = l_2 m \end{gathered}  $$

따라서 다음이 성립한다.
$$ \begin{equation} \Delta x \cdot \Delta y  = l_1 l_2 \cos \theta \end{equation} $$

시간에 따른 변화율을 보기 위해 식(9)를 물질미분하면 다음과 같다.
$$ \begin{equation} \begin{aligned} \frac{\partial}{\partial t} \Delta x \cdot \Delta y + \Delta x \cdot \frac{\partial}{\partial t} \Delta y  = & \left( \frac{\partial}{\partial t} l_1 \right) l_2 \cos \theta + l_1 \left( \frac{\partial}{\partial t} l_2 \right) \cos \theta \\  &- l_1 l_2 \sin \theta \frac{D\theta}{\partial t} \end{aligned} \end{equation} $$

식 (10)의 왼쪽항을 rate of deformation tensor와 spin tensor를 이용해서 표현하면 다음과 같다.
$$ \begin{aligned} & \frac{\partial}{\partial t} \Delta x \cdot \Delta y + \Delta x \cdot \frac{\partial}{\partial t} \Delta y \\ = \enspace & \nabla_x v \Delta x \cdot \Delta y + \Delta x \cdot \nabla_x v \Delta y \\ = \enspace & \Delta x \cdot ( \nabla_x v + (\nabla_x v)^T) \Delta y \\ = \enspace & 2 \Delta x \cdot D \Delta y \\ = \enspace & 2 l_1 l_2 n \cdot D m  \end{aligned} $$

식 (10)에 다시 대입해서 정리하면 다음과 같다.
$$ 2 n \cdot D m =  \left( \frac{1}{l_1} \frac{\partial}{\partial t} l_1 + \frac{1}{l_2} \frac{\partial}{\partial t} l_2 \right) \cos \theta - \sin \theta \frac{D\theta}{\partial t}$$

만약 ${n = e,m = e_j}$이었다면, $2D_{ij}$는 $e$방향과 $e_j$방향에 있는 요소사이의 각도의 감소율을 나타낸다.

