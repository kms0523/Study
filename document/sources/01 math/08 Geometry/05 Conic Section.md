# Conic
##  Standard Form
Catesian coordinate system에서 conic의 `standard form`은 다음과 같다.

$$ \def\arraystretch{1.5}\begin{array}{c|c} \text{ellipse} & \dfrac{x^{2}}{a^{2}} + \dfrac {y^{2}}{b^{2}} =1 \\ \text{parabola} & y^{2}=4ax, \enspace x^2 = 4ay \\ \text{hyperbola} & \dfrac {x^{2}}{a^{2}}-\dfrac {y^{2}}{b^{2}}=1, \enspace -\dfrac{x^{2}}{a^{2}} +\dfrac {y^{2}}{b^{2}}=1 \end{array} $$

> Reference  
> [wiki - conic section](https://en.wikipedia.org/wiki/Conic_section)  

## General Catesian Form
Catesian coordinate system에서 conic의 general form은 다음과 같다.

$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0 $$

### 참고
conic의 genenral form은 2변수 2차 방정식의 general form과 같다.

이를 matrix form으로 표현하면 다음과 같이 표현할 수 있다.

$$ \begin{bmatrix} x&y&1 \end{bmatrix} \begin{bmatrix} a & b & d \\ b & c & e \\ d & e & f \end{bmatrix} \begin{bmatrix} x\\y\\1 \end{bmatrix} = 0 $$

또는 다음과 같이 표현할 수 있다.

$$ \begin{bmatrix} x&y \end{bmatrix} \begin{bmatrix} a & b \\ b & c \end{bmatrix} \begin{bmatrix} x\\y \end{bmatrix} + \begin{bmatrix} 2d & 2e \end{bmatrix} \begin{bmatrix} x \\ y \end{bmatrix} + f = 0 $$

## Degenerate Conic
`Degenerate conic`이란 irreducible curve가 아닌 conic을 말한다.

> Reference  
> [wiki - Degenerate conic](https://en.wikipedia.org/wiki/Degenerate_conic)  
> [wiki - irreducible component](https://en.wikipedia.org/wiki/Irreducible_component)  

## Classification of Conic
Conic의 general cartesian form이 다음과 같이 주어졌다고 하자.

$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0 $$

$A \in M_{33}(\R)$와 $B \in M_{22}(\R)$를 다음과 같이 정의하자.

$$ A := \begin{bmatrix} a & b & d \\ b & c & e \\ d & e & f \end{bmatrix}, \enspace B := \begin{bmatrix} a & b \\ b & c \end{bmatrix} $$

이 떄, conic은 다음과 같이 분류된다.

$$ \def\arraystretch{1.5}\begin{array}{c|c} \text{degenerate conic} & \det(A)=0 \\ \text{proper(non-degenerate) conic} & \det(A) \neq 0  \end{array} $$

또한 proper conic은 다음과 같이 분류된다.

$$ \def\arraystretch{1.5}\begin{array}{c|c} \text{hyperbola} & \det(B)<0 \\ \text{parabola} & \det(B) = 0 \\ \text{real ellipse} & \det(B)>0 \land (a+c)\det(A) <0  \\ \text{imaginary ellipse} & \det(B)>0 \land (a+c)\det(A)>0  \end{array} $$

> Reference  
> [wiki - matrix representation of conic section](https://en.wikipedia.org/wiki/Matrix_representation_of_conic_sections#Classification)

### 명제1
Conic의 general cartesian form이 다음과 같이 주어졌다고 하자.

$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0$$

이 떄, $A \in M_{33}(\R)$를 다음과 같이 정의하자.

$$ A := \begin{bmatrix} a & b & d \\ b & c & e \\ d & e & f \end{bmatrix} $$

$\det(A) = 0$이면 degenerate conic이 됨을 증명하여라.

**Proof**

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/387177/determine-if-a-conic-is-degenerate-with-the-determinant) 

### 명제2
Conic의 general cartesian form이 다음과 같이 주어졌다고 하자.

$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0$$

이 떄, 적절한 회전 변환에 의해 다음 형태로 변환할 수 있음을 증명하여라.

$$ \lambda_1 u^2 + \lambda_2 v^2 + 2d'u + 2e'v + f =0 $$

**Proof**

General catesian form을 행렬 형태로 나타내면 다음과 같다.

$$ \begin{bmatrix} x&y \end{bmatrix} \begin{bmatrix} a & b \\ b & c \end{bmatrix} \begin{bmatrix} x\\y \end{bmatrix} + \begin{bmatrix} 2d & 2e \end{bmatrix} \begin{bmatrix} x \\ y \end{bmatrix} + f = 0 $$

$B$는 symmetric matrix이기 때문에 선형대수에 의해 다음이 성립한다. 

$$ B = P^T \Lambda P $$

이 때, 다음과 같은 변수변환을 생각해보자.

$$ \begin{bmatrix} u \\ v \end{bmatrix} = P\begin{bmatrix} x \\ y \end{bmatrix} $$

이를 원래 행렬식에 대입하고 풀어 쓰면 다음과 같다.

$$ \lambda_1 u^2 + \lambda_2 v^2 + 2d'u + 2e'v + f =0 \qed $$

> Reference  
> [Note] (Dey) Conic section

### 명제3
Conic의 general cartesian form이 다음과 같이 주어졌다고 하자.

$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0$$

$b^2 - ac \neq 0$이고 $k = -\det(A)/\det(B)$일 때, 다음 형태로 변환할 수 있음을 증명하여라.

$$ \lambda_1 u^2 + \lambda_2 v^2 = k $$

**Proof**

$(x_c,y_c)$가 conic의 linear term이 전부 사라지는 center이라고 하면 다음이 성립한다.

$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = a(x-x_c)^2 + 2b(y-y_c)(x-x_c) + c(y-y_c)^2 + k $$

위의 식으로부터 다음 두 조건을 얻을 수 있다.

$$ \begin{gathered} ax_c + by_c + d =0 \\ bx_c + cy_c + e =0 \end{gathered} $$

이를 연립하여 풀면 다음을 얻을 수 있다.

$$ x_c = \frac{cd-be}{\det(B)}, \enspace y_c = \frac{ae-bd}{\det(B)} $$

다음으로 $k$는 다음을 만족한다.

$$ \begin{aligned} k &= f - (ax_c^2 + 2bx_cy_c + cy_c^2) \\&= \frac{1}{\det(B)} (\det(B)f - (x_c(ax_c+by_c) + y_c(cy_c +bx_c))) \\&= - \frac{\det(A)}{\det(B)}  \end{aligned}  $$

이를 행렬 형태로 나타내면 다음과 같다.

$$ \begin{bmatrix} x-x_c&y-y_c \end{bmatrix} \begin{bmatrix} a & b \\ b & c \end{bmatrix} \begin{bmatrix} x-x_c \\ y-y_c \end{bmatrix} + k = 0 $$

$B$는 symmetric matrix이기 때문에 선형대수에 의해 다음이 성립한다. 

$$ B = P^T \Lambda P $$

이 때, 다음과 같은 변수변환을 생각해보자.

$$ \begin{bmatrix} u \\ v \end{bmatrix} = P\begin{bmatrix} x-x_c \\ y-y_c \end{bmatrix} $$

이를 원래 행렬식에 대입하고 풀어 쓰면 다음과 같다.

$$ \lambda_1 u^2 + \lambda_2 v^2 = k \qed $$


> Reference  
> [wiki](https://en.wikipedia.org/wiki/Matrix_representation_of_conic_sections#Central_conics)  

### 명제3
none degerate Conic의 general cartesian form이 다음과 같이 주어졌다고 하자.

$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0$$

이 때, 다음을 증명하여라.

$$ \det(B)<0 \implies \text{hyperbola} $$

**Proof**

명제2에 의해 general catesian form은 적절한 회전변환에 의해 다음과 같이 표현할 수 있다.

$$ \lambda_1 u^2 + \lambda_2 v^2 + 2d'u + 2e'v + f =0 $$

따라서, 다음이 성립한다.

$$ \begin{aligned} \lambda_1 u^2 + \lambda_2 v^2 + 2d'u + 2e'v + f &=0  \\ \lambda_1\left(u^2+\frac{2d'}{\lambda_1}u\right) + \lambda_2\left(v^2+\frac{2e'}{\lambda_2}v\right) + f &=0 \\ \lambda_1\left(u+\frac{d'}{\lambda_1}\right)^2 + \lambda_2\left(v+\frac{e'}{\lambda_2}\right)^2 + f - \frac{(d')^2}{\lambda_1} - \frac{(e')^2}{\lambda_2} &=0 \end{aligned} $$

이 떄, $k$를 다음과 같이 정의하자.

$$ k = \frac{(d')^2}{\lambda_1} + \frac{(e')^2}{\lambda_2} - f $$

그러면 다음이 성립한다.

$$ \frac{\left(u+\dfrac{d'}{\lambda_1}\right)^2}{\dfrac{k}{\lambda_1}}  + \frac{\left(v+\dfrac{e'}{\lambda_2}\right)^2}{\dfrac{k}{\lambda_2}} = 1 $$

이 떄, $\lambda_{1,2}$는 $B$의 eigen value임으로 다음이 성립한다.

$$ \det(B) < 0 \iff \lambda_1 \lambda_2 < 0 $$

따라서 $\lambda_1,\lambda_2$의 부호가 다름으로 위 식은 중심점이 $\left(-\dfrac{d'}{\lambda_1}, -\dfrac{e'}{\lambda_2}\right)$이고 $u,v$축을 갖는 hyperbola이다.

### 명제4
none degerate Conic의 general cartesian form이 다음과 같이 주어졌다고 하자.

$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0$$

이 때, 다음을 증명하여라.

$$ \det(B)=0 \implies \text{parabola} $$

**Proof**

명제2에 의해 general catesian form은 적절한 회전변환에 의해 다음과 같이 표현할 수 있다.

$$ \lambda_1 u^2 + \lambda_2 v^2 + 2d'u + 2e'v + f =0 $$

이 떄, $\lambda_{1,2}$는 $B$의 eigen value임으로 다음이 성립한다.

$$ \det(B) = 0 \iff \lambda_1 = 0 \lor \lambda_2 =0 $$

먼저, $\lambda_1 = 0, \lambda_2 \neq 0$이라고 하자.

그러면 다음이 성립한다.

$$ \begin{aligned} \lambda_2 v^2 + 2d'u + 2e'v + f &= 0  \\ \lambda_2\left(v^2+\frac{2e'}{\lambda_2}v\right) + 2d'u + f &=0 \\  \lambda_2\left(v+\frac{e'}{\lambda_2}\right)^2  + 2d'u +  f - \frac{(e')^2}{\lambda_2}& = 0 \end{aligned} $$

이 떄, $k$를 다음과 같이 정의하자.

$$ k =  \frac{(e')^2}{\lambda_2} - f $$

그러면 다음이 성립한다.

$$ \left(v+\frac{e'}{\lambda_2}\right)^2 = - 2\frac{d'}{\lambda_2}\left(u - \frac{k}{2d'}\right) $$

위 식은 중심점이 $\left(\dfrac{k}{2d'}, -\dfrac{e'}{\lambda_2}\right)$이고 $u,v$축을 갖는 parabola이다.

마찬가지로 $\lambda_1 \neq 0, \lambda_2 = 0$일 때에도 동일한 과정을 거쳐서 parabola임을 보일 수 있다.

마지막으로 $\lambda_{1,2} = 0$인 경우를 보자.

$B$의 eigenvalue가 전부 0이려면 다음 조건을 만족해야 된다.

$$ \begin{gathered} a+c =0 \\ ac-b^2 = 0 \end{gathered} $$

이는 $a=b=c=0$일때만 가능하다.

그리고 이 경우에는 $\det(A) = 0$ 임으로 degenerate conic임으로 고려 대상이 아니다. 

따라서, 다음이 성립한다.

$$ \det(B)=0 \implies \text{parabola} \qed $$

### 명제5
none degerate Conic의 general cartesian form이 다음과 같이 주어졌다고 하자.

$$ ax^2 + 2bxy + cy^2 + 2dx + 2ey + f = 0$$

이 때, 다음을 증명하여라.

$$ \det(B)>0 \land (a+c)\det(A) <0 \implies \text{real ellipse} $$

**Proof**

명제2에 의해 general catesian form은 적절한 회전변환에 의해 다음과 같이 표현할 수 있다.

$$ \lambda_1 u^2 + \lambda_2 v^2 + 2d'u + 2e'v + f =0 $$

따라서, 다음이 성립한다.

$$ \begin{aligned} \lambda_1 u^2 + \lambda_2 v^2 + 2d'u + 2e'v + f &=0  \\ \lambda_1\left(u^2+\frac{2d'}{\lambda_1}u\right) + \lambda_2\left(v^2+\frac{2e'}{\lambda_2}v\right) + f &=0 \\ \lambda_1\left(u+\frac{d'}{\lambda_1}\right)^2 + \lambda_2\left(v+\frac{e'}{\lambda_2}\right)^2 + f - \frac{(d')^2}{\lambda_1} - \frac{(e')^2}{\lambda_2} &=0 \end{aligned} $$

이 떄, $k$를 다음과 같이 정의하자.

$$ k = \frac{(d')^2}{\lambda_1} + \frac{(e')^2}{\lambda_2} - f $$

그러면 다음이 성립한다.

$$ \frac{\left(u+\dfrac{d'}{\lambda_1}\right)^2}{\dfrac{k}{\lambda_1}}  + \frac{\left(v+\dfrac{e'}{\lambda_2}\right)^2}{\dfrac{k}{\lambda_2}} = 1 $$

이 떄, $\lambda_{1,2}$는 $B$의 eigen value임으로 다음이 성립한다.

$$ \det(B) > 0 \iff \lambda_1 \lambda_2 > 0 $$

따라서 $\lambda_1,\lambda_2$의 부호가 같다.

그리고 $A' \in M_{33}(\R)$을 다음과 같이 정의하자.

$$ A' := \begin{bmatrix} \lambda & 0 & d \\ 0 & \lambda & e \\ d & e & f \end{bmatrix} $$
다음으로 $a+c >0, \det(A) <0$인 경우를 생각해보자.

$A$의 characteristic polynomial을 보면 $a+c>0$이면 그 해인 $\lambda_1+\lambda_2>0$이다. 그리고 $\lambda_1,\lambda_2$의 부호가 같음으로 $\lambda_1,\lambda_2>0$이다.



위 식은 중심점이 $\left(-\dfrac{d'}{\lambda_1}, -\dfrac{e'}{\lambda_2}\right)$이고 $u,v$축을 갖는 hyperbola이다.


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

---

## Shifted Center Form
standard form에서 중심점을 $(c_1,c_2)$로 옮기게 되면 standard form에 $x = x'-c_1, y = y'-c_2$를 대입하면 된다.

이를 풀어 쓰면 다음과 같은 형태를 갖게 된다.

$$ a x^2 + b y^2 + cx + dy + e =0 $$

이 떄, 고차항의 계수에 따라 다음과 같이 구분할 수 있다.

$$ \def\arraystretch{1.5}\begin{array}{c|c} \text{ellipse} & ab > 0 \\ \text{parabola} & ab = 0 \\ \text{hyperbola} & ab < 0 \end{array} $$

