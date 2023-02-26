# Standard Form in Cartesian Coordinates
Catesian coordinate system에서 conic section의 `standard form`은 다음과 같다.

$$ \def\arraystretch{1.5}\begin{array}{c|c} \text{ellipse} & \dfrac{x^{2}}{a^{2}} + \dfrac {y^{2}}{b^{2}} =1 \\ \text{parabola} & y^{2}=4ax , x^2 = 4ay \\ \text{hyperbola} & \dfrac {x^{2}}{a^{2}}-\dfrac {y^{2}}{b^{2}}=1 \end{array} $$

## Shifted Center Form
standard form에서 중심점을 $(c_1,c_2)$로 옮기게 되면 standard form에 $x = x'-c_1, y = y'-c_2$를 대입하면 된다.

이를 풀어 쓰면 다음과 같은 형태를 갖게 된다.

$$ a x^2 + b y^2 + cx + dy + e =0 $$

이 떄, 고차항의 계수에 따라 다음과 같이 구분할 수 있다.

$$ \def\arraystretch{1.5}\begin{array}{c|c} \text{ellipse} & ab > 0 \\ \text{parabola} & ab = 0 \\ \text{hyperbola} & ab < 0 \end{array} $$

> Reference  
> [wiki - conic section](https://en.wikipedia.org/wiki/Conic_section)  

### 명제(General form)
Catesian coordinate system에서 2변수 2차 방정식의 general form은 다음과 같다.
$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0, \quad a,c \neq 0 $$

이 떄, 적절한 회전 변환에 의해 2변수 2차 방정식의 general form conic section의 standard form이 됨을 증명하시오.

**Proof**

위를 행렬 형태로 나타내면 다음과 같다.
$$ \mathbf x^T \mathbf A \mathbf x + \mathbf d^T \mathbf x + f =0 $$

$$ \text{Where, } \mathbf x = \begin{bmatrix} x \\ y \end{bmatrix}, \enspace \mathbf A = \begin{bmatrix} a & b \\ b & c  \end{bmatrix}, \enspace \mathbf d = \begin{bmatrix} 2d & 2e \end{bmatrix} $$

$\mathbf A$는 symmetric matrix이기 때문에 $A$의 eigen value를 $\lambda_1,\lambda_2$라 하면 다음을 만족하는 orthonormal matrix $\bf P$가 존재한다.
$$ \bf A = P^T\Lambda P $$

$$ \text{Where, } \mathbf \Lambda := \begin{bmatrix} \lambda_1 & 0 \\ 0 & \lambda_2  \end{bmatrix} $$

이 때, 다음과 같은 변수변환을 생각해보자.
$$ \bf x = Pu $$

$$ \text{Where, } \mathbf u = \begin{bmatrix} u \\ v \end{bmatrix} $$

이를 원래 행렬 형태에 적용하면 다음과 같다.
$$ \mathbf u^T \mathbf \Lambda \mathbf u + \mathbf d^T \mathbf P \mathbf u +f = 0 $$

풀어 쓰면 다음과 같다.
$$ \lambda_1 u^2 + \lambda_2 v^2 + d'u + e'v + f =0 $$

이는 conic section의 Catesian coordinates에서의 standard form임으로 위와 같은 모든 2변수 2차 방정식은 conic section을 나타낸다.

> Reference  
> [Note] (Dey) Conic section

# Degenerate Conic
다음과 같이 conic section의 general form이 주어졌다고 하자.
$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0, \quad a,c \neq 0 $$

이 떄, $A \in M_{33}(\R)$를 다음과 같이 정의하자.
$$ A := \begin{bmatrix} a & b & d \\ b & c & e \\ d & e & f \end{bmatrix} $$

$\det(A) = 0$이면 `degenerate conic`이라고 한다.

> Reference  
> [Wiki - Degenerate conic](https://en.wikipedia.org/wiki/Degenerate_conic)

# Classification of Nondegenerate Conic
다음과 같이 non-degenerate conic section이 주어졌다고 하자.
$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0, \quad a,c \neq 0 $$

이 떄, $A \in M_{22}(\R)$를 다음과 같이 정의하자.
$$ A = \begin{bmatrix} a & b \\ b & c  \end{bmatrix} $$

$A$의 eigen value를 $\lambda_{1,2}$라 할 떄, 이는 다음과 같은 strandard form으로 변환될 수 있다.
$$ \lambda_1 u^2 + \lambda_2 v^2 + d'u + e'v + f =0 $$

따라서 다음과 같이 분류할 수 있다.
$$\begin{gathered} \lambda_1 \lambda_2 > 0 & \text{ellipse} \\ \lambda_1 \lambda_2 = 0 & \text{parabola} \\ \lambda_1 \lambda_2 < 0 & \text{hyperbola} \end{gathered} $$

### 명제1
다음과 같이 non-degenerate conic section이 주어졌다고 하자.
$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0, \quad a,c \neq 0 $$

이 떄, $A \in M_{22}(\R)$를 다음과 같이 정의하자.
$$ A := \begin{bmatrix} a & b \\ b & c  \end{bmatrix} $$

$\det(A)$에 따라 다음과 같이 분류할 수 있음을 증명하여라.
$$\begin{gathered} \det(A) > 0 & \text{ellipse} \\ \det(A) = 0 & \text{parabola} \\ \det(A) < 0 & \text{hyperbola} \end{gathered} $$

**Proof**

$A$의 eigen value를 $\lambda_{1,2}$라 할 떄, 다음이 성립한다.
$$ \det(A) = \lambda_1 \lambda_2 $$

따라서, $\det$를 이용한 분류가 성립된다. $\quad {_\blacksquare}$

> Reference  
> [wiki - conic section](https://en.wikipedia.org/wiki/Conic_section) 

### 예시
다음과 같은 이차방정식이 주어졌다고 하자.
$$ 2x^2 + 4xy + 5y^2 + 4x + 13y - 1/4 =0 $$

이 떄, $A \in M_{22}(\R)$를 다음과 같이 정의하자.
$$ A := \begin{bmatrix} 2 & 2 \\ 2 & 5  \end{bmatrix} $$

$A$의 eigen value와 eigen vector는 다음과 같다.
$$ \begin{gathered} \lambda_1 = 1, \enspace v_1 = \frac{1}{\sqrt 5} \begin{bmatrix} 2 \\ -1 \end{bmatrix} \\ \lambda_2 = 6, \enspace v_2 = \frac{1}{\sqrt 5} \begin{bmatrix} 1 \\ 2 \end{bmatrix} \end{gathered} $$

이 떄, $P \in M_{22}(\R)$를 다음과 같이 정의하자.
$$ P := \begin{bmatrix} v_1 & v_2 \end{bmatrix} = \frac{1}{\sqrt 5} \begin{bmatrix} 2 & 1 \\ -1 & 2  \end{bmatrix} $$

$x = Pu$로 변수변환 하면 다음과 같이 정리할 수 있다.
$$ \begin{aligned} & u^2 + 6v^2 - \sqrt 5 u + 6 \sqrt 5v - 1/4 = 0 \\ \Rightarrow \enspace & (u - 1/2 \sqrt 5)^2 + 6(v + 1/2 \sqrt 5)^2 = 9 \end{aligned} $$

이를 그림으로 나타내면 다음과 같다.
<p align = "center">
<img src = "./image/connic_section1.png">
</p>

그림을 통해 eigen vector가 $u,v$ 두 축을 나타내는것을 알 수 있다.

> Reference  
> [Note] (Dey) Conic section