# Chapter3

## 3.1 Preliminary
### 응력 변형률 관계
$$ \sigma = E \epsilon $$

### 변형률-변위 관계
$$ \epsilon = B d $$

### 강성 행렬
$$ k = \iint B^Tp E B t dx dy $$

이 때, k는 `강성 행렬(stifness matrix)`, $t$는 두께이다.

### Compatibility
compatibility condition이란 변위는 연속인 `일가함수(single-valued function)`여야 한다는 조건이다.

plane 문제에서 compatibility condition은 다음과 같다. `(이해안됨)`
$$ \frac{\partial^2 \epsilon_1}{\partial^2x} + \frac{\partial^2 \epsilon_2}{\partial^2x} = \frac{\partial^2 \gamma_{12}}{\partial x \partial y} $$

이는, compatibility 조건이 만족될 경우 변형률간의 관계가 반드시 존재함을 의미한다.

`이해안됨`

### Exact and Approximate Solutions
compatible displacement field에서 시작한다면, 변위로 부터 변형률을 구할 수 있고, 변형률로 부터 응력을 구할 수 있다. 이렇게 구한 응력이 모든 점에서 평형 방정식을 만족하고, 경계 면에서 경계조건을 만족할 경우, 수학적 모델을 만족하는 exact 해를 구한것이다.

유한 요소 기반의 displacement field는 모든 점에서 평형 조건을 만족하지는 않는다. 하지만 적분형태나 평균값 맥락에서 평형 조건을 만족한다.

## 3.2 보간과 모양 함수
보간하는 것은 유한한 점들에서 평형 조건을 만족시키기 위해 연속 함수를 만드는것이다. 

먼저 간단한 1차원 스칼라 예를 생각해보자. 스칼라 값 $\phi$를 다항식으로 근사하면 다음과 같이 표현할 수 있다.
$$\phi \approx \sum_{i=0}^n a_ix^i \\ \phi = \bf xa$$

이 떄, 서로 다른 $n$개의 점에서 $\phi$값을 알고 있다면 다음과 같이 행렬로 표현할 수 있다.
$$ \mathbf {Aa} = \boldsymbol \phi_e \\ \text{where,} \quad A_{ij} = x_i^j $$

따라서, $\bf a = A^{-1} \boldsymbol\phi$이다.

이를 원래 식에 대입하면 모양 함수 벡터 $\bf n$을 얻을 수 있다.
$$ \begin{align} &\phi = \mathbf {n^T} \boldsymbol \phi_e \\ \text{where,} \quad &\bf n^T = x^TA^{-1} \end{align}  $$

### Degree of Continuity
Field quantity인 $\phi$가 FE 격자계 위에서 요소별로 보간된다. 따라서 $\phi$는 요소 내에서 연속인 다항식으로 근사되지만 요소 경계에서는 연속이 아닐 수도 있다. 

$C^m$은 $m$계 미분계수까지 요소 경계에서 연속임을 의미한다.

### $C^0$ 보간
1차원 요소의 $\bf n$을 구해보면 각각의 원소가 라그랑지 다항 함수임을 알 수 있으며 라그랑지 다항 함수는 다음과 같이 구한다.

$$ N_i = \prod_{\substack{j = 1 \\ j \neq i}}^n \frac{x_j - x}{x_j - x_i}   $$

* 모든 모양함수들은 같은 차수의 다항식이다
* $x = x_i$ 일 때 $N_i = 1, N_j = 0 (i \neq j)$이다.
* $\displaystyle\sum N_i = 1$이다. ($\phi = 1$로 두면 식(1)로부터 증명 된다.)

`라그랑지 보간법(Lagrangian interpolation)`은 기울기에 대한 정보를 사용하지 않는다. 따라서 라그랑지 보간법으로 구한 기울기는 각 점의 주어진 기울기와는 다른 값을 가질 수 있다.

### $C^1$ 보간
좌표값과 기울기 정보를 모두 사용해서 보간하는 방법을 `에르미트 보간법(Hermitian interpolation)`이라고 한다.

스칼라 값 $\phi$를 다항식으로 근사하면 다음과 같이 표현할 수 있다.
$$\phi \approx \sum_{i=0}^n a_ix^i \\ \frac{d\phi}{dx} \approx \sum_{i=1}^n ia_ix^{i-1} $$

1차원 요소의 두 끝점에 대한 $\phi$값과 $\displaystyle\frac{d\phi}{dx}$값이 주어지면 다음과 같이 행렬로 표현할 수 있다.

$$ \mathbf {Aa} = \boldsymbol \phi_h \\ \text{where,} \quad A = \begin{bmatrix} 1 & x_1 & x_1^2 & x_1^3 \\ 0 & 1 & 2x_1 & 3x_1 \\ 1 & x_2 & x_2^2 & x_2^3 \\ 0 & 1 & 2x_2 & 3x_2^2  \end{bmatrix}, \quad \boldsymbol \phi_h = \begin{bmatrix} \phi_1 \\ \phi_{1,x} \\ \phi_2 \\ \phi_{2,x} \end{bmatrix} $$

## 3.3 요소 행렬의 구성

# Chapter6
$$ B = B(x,y) = B(\xi,\eta) $$


## 6.3 수치적분
`가우스 구적법(Gauss quadrature)`은 다항식의 적분 오차를 최소화하는 점과 가중치를 사용한다.

`가우스 르장드르 계수(Gauss-Legendre coefficients)`라고 불리기도 하는데 이는 점의 위치가 르장드르 다항식의 해이기 때문이다.

수치적분의 정확도가 요소 거동의 정확도와 같지 않다. 오히려 수치적분의 차수를 줄였을 때 더 정확한 결과를 얻을 수도 있다. 그러나 낮은 차수를 사용하면 요소가 하나 이상의 가짜 모드를 갖을 수 있다.

### full integration
강성 행렬의 계수를 정확하게 적분하기에 충분한 차수를 사용할 경우 full integration이라고 한다.

### Underintegartion
full integration보다 적은 차수를 사용할 경우 underintegartion 혹은 reduced integration이라고 한다.

underintegration은 계산시간을 감소시켜주고 overstiffness 문제의 경우 계산결과의 정확도를 높혀준다. underintegration의 경우 변형률 에너지(strain energy)에 대해 고차항에 의한 영향을 줄여줌으로써 강성도를 줄이는 효과가 있다.

하지만 동시에 singular mode, zero-energy deformation mode, hourglass mode, kinematic mode등 다양한 `거짓 모드(spurious mode)`들과 불안정성(instability)을 야기할 수 있다.



## 6.4 이차 사각형 요소

## 6.5 육면체 등매개변수 요소

$$ k = \iint B^T E B J d\xi d\eta d\zeta $$

## 6.6
4점 사각형요소와 8점 육면체요소는 가짜 전단 변형률에 의해 강성도가 높아지는 `전단 잠김(shear locking)` 현상이 발생한다.

## 6.7
전역 방정식(global equations) $KD = R$.  
$D$는 모든 요소의 자유도, $R$그와 관련된 하중.  

[Guyan reduction - wiki](https://en.wikipedia.org/wiki/Guyan_reduction)  

## 6.9 하중 고려

$$ r_e = \int N^T F dV + \int N^T \Phi dS + \int B^T E \epsilon_0 dV - \int B^T \sigma_0 dV $$

$r_e$은 nodal loads, $F$는 단위부피당 체적력, $\Phi$는 표면력, $\epsilon_0$는 초기 변형률, $\sigma_0$는 초기 응력이다.

## 6.10 하중 계산
$$ \sigma = E(Bd - \epsilon_0) + \sigma_0 $$

### 적분점에서의 응력
Q4 요소는 굽힘에서 거짓 전단응력 문제가 발생한다.

강성 행렬을 계산할 때 쓰는 차수와 응력 계산할 때 쓰는 차수가 같을 필요는 없다. 따라서 필요에 따라 응력 계산 할때는 더 적은 차수를 사용할 수 있다.

### 참고
적분 점에서 응력보다 node에서 응력에 보통 더 관심이 있다. 첫번째로는, node는 표면에 나타나는 반면 ... 두번째로, node를 공유하는 요소간 예측한 응력의 차이로 오차를 측정할 수 있다.

## 6.11 요소의 기하학적 형상의 영향

### 등매개변수 요소의 타당성
연속체의 충분히 작은 영역에서 변형률의 변화량은 변형률의 평균값보다 무시할 수 있을만큼 작다고 볼 수 있다. 그에 따라, 충분히 작은 격자계를 사용할 경우 FE 계산 결과는 각각의 요소에서 상수 변형률을 나타낼 수 있어야 한다.

$\phi = a_1 + a_2x + a_3y + a_4z$라 하자. 이 형태는 상수 변형률일 때, 변위 $u,v,w$를 나타낸다. 따라서 $a_1$은 강체의 평행이동(translation)과 관련 되어있다. 그 외의 $a_i$는 상수 변형률과 강체의 회전과 관련되어 있다.

## 6.13 Patch test

# 등매개변수 삼각형과 사면체
## 7.1 기준 좌표계와 모양함수
요소의 모양(shape)과 요소의 field quantity가 동일한 보간법(interpolation)으로 정의된다.

응력 분석시, 3점 삼각형과 4점 사면체 요소는 전단 잠김현상에 취약하다. 따라서 6점 삼각형, 10점 사면체와 같이 고차 요소들이 선호된다.

3점 삼각형 요소는 전단변형률과 같은 미분항이 없는 scalar field 문제에서 사용된다.

### 삼각형
변과 내부에 점들이 정규 패턴을 따르면 complete polynomial을 포함하는 family를 생성한다.

3점 삼각형의 모양함수는 0과 같다고 두면 그 점을 포함하지 않는 선분의 방정식이 된다. 고차 요소의 경우 각각의 모양 함수는 "line function"의 곱으로 표현된다.

### 사면체
4점 사면체의 모양함수는 0과 같다고 두면 그 점을 포함하지 않는 평면의 방정식이 된다. 고차 요소의 경우 각각의 모양 함수는 "line function"의 곱으로 표현된다.

다항식 공간의 차원은 다음과 같다.
$$ \dim(\mathbb{P}^n(\R^d)) = {}_{d+1}H_n = {}_{n+d}C_d $$

### 등매개변수 요소
기하형상을 $N_p$개의 점에서 $N_p$개의 모양 함수 $n_i$로 보간하면 다음과 같다.
$$ x = \sum_i^{N_p} n_ix_i, \quad y = \sum_i^{N_p} n_iy_i, \quad z = \sum_i^{N_p} n_iz_i, $$

이를 행렬 형태로 표현하면 다음과 같다.
$$ \mathbf{x = Xn} \\ \bf x = \begin{bmatrix} x_1 \\ \vdots \\ x_d \end{bmatrix}, \quad X = \begin{bmatrix} \bf{x_1} & \cdots & \mathbf{x}_{N_p}  \end{bmatrix}, \quad n = \begin{bmatrix} n_1 \\ \vdots \\ n_{N_p} \end{bmatrix} $$

Field quantity $\phi$을 기하형상과 동일한 모양 함수로 보간할 때, 등매개변수 요소라고 한다.
$$ \phi = \sum_i N_i \phi_i $$

## 7.2 요소의 특성 행렬
구조역학 문제에서 요소의 `특성행렬(characteristic matrix)`은 `강성행렬(stiffness matrix)`이다.

삼각형 scalar 요소의 특성행렬은 다음과 같다.
$$ \mathbf{k = \int B^T \boldsymbol{\kappa} B} t dA $$

$\boldsymbol{\kappa}$는 물질 상수로 이루어진 행렬이고 $t$는 요소 두께이다.

사면체 요소의 특성 행렬은 다음과 같다.
$$ \mathbf{k = \int B^T \boldsymbol{\kappa} B} dV $$

## 7.3 적분
요소가 직선으로 이루어져 있고, 등간격으로 분포되어 있어 $J$가 상수인것 처럼 요소의 기하적인 특성이 충분히 제한되어 있다면 강성행렬은 적분할 수 있다. 따라서 $\bf k$의 닫힌형태를 얻을 수 있다.

## 7.4 수치적분
요소가 곡선으로 이루어져 있거나 등간격으로 분포되어 있지 않은 경우 distorted 되었다고 한다. 이 경우에 $J$는 상수가 아니고 피적분함수는 다항함수가 아닌 유리함수가 된다.



---

### 선형 삼각형
다음을 만족하는 $B$를 찾는것이다.

$$ \begin{bmatrix} \phi_x \\ \phi_y \end{bmatrix} = B \begin{bmatrix} \phi_1 \\ \phi_2 \\ \phi_3 \end{bmatrix} $$

기준 좌표계에서 실 좌표계로 변환함수를 $\mathfrak{T} : \R^d \rightarrow \R^d$라 하면 다음의 관계식이 성립한다.

$$ \begin{bmatrix} \phi_r \\ \phi_s \end{bmatrix} = J \begin{bmatrix} \phi_x \\ \phi_y \end{bmatrix} $$

$$ J = J_{\mathfrak{T}}^T =  \begin{bmatrix} x_r & y_r \\ x_s & y_s \end{bmatrix} = \begin{bmatrix} \displaystyle \sum _i N_{i,r} x_i && \displaystyle \sum_i N_{i,r} y_i \\\\ \displaystyle \sum_i N_{i,s} x_i && \displaystyle \sum_i N_{i,s} y_i \end{bmatrix}  = NX$$

따라서,

$$ \begin{bmatrix} \phi_x \\ \phi_y \end{bmatrix} = J^{-1} \begin{bmatrix} \phi_r \\ \phi_s \end{bmatrix} $$


# Chapter 15

## 15.1 판 거동
`판(plate)`이란 두께가 다른 길이에 비해 매우 작은 평평한 물체를 의미한다. 이러한 기하학적인 특성때문에 판 해석시 3차원 요소를 사용하지 않는다. 두께만 얇은 3차원 요소를 사용할 경우 전단 잠김 현상이나 ill-conditioning 될 수 있다. compact한 3차원 요소를 사용해 이러한 현상을 피한다고 해도 너무 많은 DOF를 갖는 문제가 있다. 이러한 문제를 피하기 위해 판 이론에 기반한 요소를 사용한다. 판 이론의 종류에 따라 전단 잠김 현상을 피하기 위한 추가적인 식이 필요할 수 있다.

직선 빔과 같은 평판은 굽힘에의해 측면에 하중이 발생한다.

### 판 이론
판의 두께는 $t$이고 midsurface는 $t/2$에 위치한다. elementary plate bending theory에서는 homogeneous 판의 굽힘에서 midsurface는 $\epsilon_1 = \epsilon_2 = \gamma_{12} = 0$ 인 중립 면으로 둔다. 만약 면의 하중이 존재하면 큰 수평 굴절이 생기고 midsurface의 변형률은 0이 아니게 된다.

### Kirchhoff theory(thin-plate theory)
두께방향 응력과 `가로방향 전단변형(transverse shear deformation)`이 없다고 가정한 이론이다.

Transverse shear deformation이 없다고 하면 $w_x = \psi_x$고 $w_y = \psi_y$이다. 따라서 $\epsilon_x = -zw_{xx}, \epsilon_2 = -zw_{22}, \gamma_{12} = -2zw_{12}$이다.

$D$는 `휨 강도(flexural rigidity)`로 빔의 `휨 강성(flexural stiffness)`인 $EI$와 유사한 값이다.



### Mindlin theory
두께방향 응력이 없다고 가정한 이론이다.

Kirchhoff theory와 다르게 가로방향 전단변형을 고려하였기 때문에 하중이 가해지기 전에 midsurface의 법선은 하중이 가해진 후 법선이 아닐 수 있다.

Mindlin plate에서 변형과 응력을 묘사하기 위해서 $w, \psi_x, \psi_y$는 각각 x,y로 표현되야한다.

