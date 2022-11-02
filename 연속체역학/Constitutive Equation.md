
`구성방정식(constitutive equation)`은 stress와 그에 대응하는 변형의 관계를 나타내는 방정식이다.
# Linearly Elastic Solid
Small deformation 가정을 하자.

이 때, 다음 constitutive equation을 만족하는 재료를 `선형탄성재료(linearly elastic solid)`라고 한다.
$$ \sigma_{ij} = C_{ijkl} \epsilon_{kl} $$

이 때, $\sigma$는 Cauchy stress tensor이고 ${\epsilon}$은 infinitesimal strain tensor이고 $C$는 `선형 강성 텐서(linear stiffness tensor)`이다.

$C$는 4차 텐서로 $\sigma - \epsilon$의 선형관계를 나타내는 계수들을 표현한 텐서이다.

> Reference  
> [Book] (Lai et al) Introduction to Continuum Mechanics Chap5.2  

### 명제1
$C$가 선형 강성 텐서라고 할 떄, 다음을 증명하여라.
$$ C \text{ has 21 independent variables} $$

**Proof**

$C$는 4차 텐서임으로 81개의 독립변수를 갖는다.

이 때, $\epsilon$의 대칭성에 의해 다음이 성립한다.
$$ C_{ijkl}\epsilon_{kl} + C_{ijlk}\epsilon_{lk} = (C_{ijkl} + C_{ijlk} ) \epsilon_{kl} \quad (\text{not summation}) $$

따라서 두개의 독립변수 $C_{ijkl}, C_{ijlk}$가 있는 것이 아닌 하나의 독립변수 $( C_{ijkl} + C_{ijlk} )$가 있게 된다. $( C_{ijkl} + C_{ijlk} )$를 하나의 독립변수로 두는 것은 $C_{ijkl} = C_{ijlk}$로 두는것과 동치이다.

따라서, 유의미한 $(k,l)$은 다음과 같다.
$$ (k,l) \in \{(1,1), (1,2), (1,3), (2,2), (2,3), (3,3) \} $$

이를 통해 $C$의 독립변수 숫자는 $3 \times 3 \times 6 = 54$로 줄어들게 된다.

다음으로, $\sigma$의 대칭성에 의해 다음이 성립한다.
$$ C_{ijkl}\epsilon_{kl} = C_{jikl}\epsilon_{kl} $$

위와 동일한 논리로, $C_{ijkl} = C_{jikl}$이 되게 되고 유의미한 $(i,j)$는 다음과 같다.
$$ (i,j) \in \{(1,1), (1,2), (1,3), (2,2), (2,3), (3,3) \} $$

이를 통해 $C$의 독립변수 숫자는 $6 \times 6 = 36$으로 줄어들게 된다.

마지막으로 strain energy function $U$에 의해 다음이 성립한다.
$$ \begin{aligned} C_{ijkl} &=  \frac{\partial \sigma_{ij}}{\partial \epsilon_{kl}}  \\&= \frac{\partial^2 U}{\partial \epsilon_{ij}\partial \epsilon_{kl}} \\&= \frac{\partial\sigma_{kl}}{\partial \epsilon_{ij}} \\&= C_{klij} \end{aligned}  $$

따라서, 유의미한 $(i,j,k,l)$는 다음과 같다.
$$ (i,j,k,l) \in \{ (1,1,1,1), \cdots, (1,1,3,3), (1,2,1,2), \cdots , (1,2,3,3), \cdots, (3,3,3,3) \} $$

이를 통해, $C$의 독립변수 숫자는 $6 + \cdots + 1 = 21$으로 줄어든다. $\quad\tiny\blacksquare$

> Reference    
> [book] (Lai et al) Introduction to Continuum Mechanics p.205

#### 참고
vognit notation을 이용하여 행렬로 나타내면 다음과 같다.
$$ \begin{bmatrix} \sigma_{11} \\ \sigma_{22} \\ \sigma_{33} \\ \sigma_{23} \\ \sigma_{13} \\ \sigma_{12} \end{bmatrix} =  \begin{bmatrix} c_{1111} & c_{1122} & c_{1133} & c_{1123} & c_{1113} & c_{2212} \\ & c_{2222} & c_{2233} & c_{2223} & c_{2213} & c_{2212} \\ && c_{3333} & c_{3323} & c_{3313} & c_{3312} \\ &&& c_{2323} & c_{2313} & c_{2312} \\ &\text{sym}&&& c_{1313} & c_{1312} \\ &&&&& c_{1212} \end{bmatrix} \begin{bmatrix} \epsilon_{11} \\ \epsilon_{22} \\ \epsilon_{33} \\ 2\epsilon_{23} \\ 2\epsilon_{13} \\ 2\epsilon_{12} \end{bmatrix} $$

# Isotropic Linear Elastic Solid
특정 방향에 따라 물성치가 변하지 않을 때 `등방성(isotropic)`재료라고 한다. 

### 명제1
Isotropic linear elastic solid일 때, 다음을 증명하여라.
$$ \sigma_{ij} = \lambda \epsilon_{kk}\delta_{ij} + 2\mu\epsilon_{ij} $$

**Proof**

등방성 재료의 경우 모든 방향에서 응력-변형률 관계가 같아야 하기 때문에 $C$는 isotropic tensor여야 한다.

Fourth-order isotropic tensor의 경우 다음과 같은 general form을 갖는다.
$$ C_{ijkl} = \lambda \delta_{ij}\delta_{kl} + \alpha \delta_{ik}\delta_{jl} + \beta \delta_{il}\delta_{jk} $$

$\sigma_{ij} = C_{ijkl} \epsilon_{kl}$임으로 다음이 성립한다.
$$ \sigma_{ij} = \lambda \epsilon_{kk}\delta_{ij} + 2\mu\epsilon_{ij} $$

$$ \text{Where, } 2\mu = \alpha + \beta \quad\tiny\blacksquare $$

#### 참고1
재료 상수 $\lambda$, $\mu$를 `Lame's constant`라고 한다.

$\epsilon$이 무차원 변수임으로 Lame's constant는 응력과 동일한 차원을 갖는다.

#### 참고2
vognit notation을 이용하여 행렬로 나타내면 다음과 같다.
$$ \begin{bmatrix} \sigma_{11} \\ \sigma_{22} \\ \sigma_{33} \\ \sigma_{12} \\ \sigma_{23} \\ \sigma_{31} \end{bmatrix} =  \begin{bmatrix} c_1 & c_2 & c_2 & & & \\ c_2 & c_1 & c_2 &&& \\ c_2 & c_2 & c_1 &&& \\ &&& c_3 && \\ &&&& c_3 & \\ &&&&& c_3 \end{bmatrix} \begin{bmatrix} \epsilon_{11} \\ \epsilon_{22} \\ \epsilon_{33} \\ \epsilon_{12} \\ \epsilon_{23} \\ \epsilon_{31} \end{bmatrix} $$

$$ \begin{aligned} \text{Where, } c_1 &= 2\mu + \lambda \\ c_2 &= \lambda \\ c_3 &= 2\mu \end{aligned}  $$

### 명제2
Isotropic linear elastic solid일 때, 다음을 증명하여라.
$$ \epsilon_{ij} = \frac{1}{2\mu} \left( \sigma_{ij} - \frac{\lambda}{3\lambda + 2\mu}\sigma_{kk}\delta_{ij} \right) $$

**Proof**

Isotropic linear elastic solid임으로 다음이 성립한다.
$$ \begin{aligned} \sigma_{kk} &= (3\lambda + 2\mu) \epsilon_{kk} \\ \Rightarrow \enspace \epsilon_{kk} &= \frac{\sigma_{kk}}{3\lambda + 2\mu} \end{aligned} $$

따라서 다음이 성립한다.
$$ \begin{aligned} & \sigma_{ij} = \lambda \epsilon_{kk}\delta_{ij} + 2\mu\epsilon_{ij} \\ \Rightarrow\enspace& \sigma_{ij} = \lambda\frac{\sigma_{kk}}{3\lambda + 2\mu}\delta_{ij} + 2\mu\epsilon_{ij} \\ \Rightarrow\enspace& \epsilon_{ij} = \frac{1}{2\mu} \left( \sigma_{ij} - \frac{\lambda}{3\lambda + 2\mu}\sigma_{kk}\delta_{ij} \right) \quad\tiny\blacksquare \end{aligned} $$

#### 참고
vognit notation을 이용하여 행렬로 나타내면 다음과 같다.
$$ \begin{bmatrix} \epsilon_{11} \\ \epsilon_{22} \\ \epsilon_{33} \\ \epsilon_{12} \\ \epsilon_{23} \\ \epsilon_{31} \end{bmatrix} =  \begin{bmatrix} c_1 & c_2 & c_2 & & & \\ c_2 & c_1 & c_2 &&& \\ c_2 & c_2 & c_1 &&& \\ &&& c_3 && \\ &&&& c_3 & \\ &&&&& c_3 \end{bmatrix} \begin{bmatrix} \sigma_{11} \\ \sigma_{22} \\ \sigma_{33} \\ \sigma_{12} \\ \sigma_{23} \\ \sigma_{31} \end{bmatrix} $$

$$ \begin{aligned} \text{Where, } c_1 &= \frac{1}{2\mu} \bigg( 1-\frac{\lambda}{3\lambda + 2\mu} \bigg) = \frac{\lambda + \mu}{\mu(3\lambda + 2\mu)} \\ c_2 &= -\frac{\lambda}{2\mu(3\lambda + 2\mu)} \\ c_3 &= \frac{1}{2\mu} \end{aligned}  $$

> Reference  
> [book] (Lai et al) Introduction to Continuum Mechanics Chap5.3

### 명제3(Uniaxial stress state)
uniaxial stress가 다음과 같이 주어졌다고 하자.
$$\sigma_{ij} = \begin{cases} \sigma_{11} & i=j=1 \\ 0 & \text{else} \end{cases} $$

이 떄, `탄성계수(Young's modulus, modulus of elasticity)` $E$와  `프와송비(Poisson's ratio)` $\nu$를 다음과 같이 정의하자.
$$ \begin{aligned} E &:= \frac{\sigma_{11}}{\epsilon_{11}} \\ \nu &:= -\frac{\epsilon_{22}}{\epsilon_{11}} = -\frac{\epsilon_{33}}{\epsilon_{11}} \end{aligned} $$

다음을 증명하여라.
$$ \begin{aligned} E &= \frac{\mu (3\lambda + 2\mu)}{\lambda + \mu} \\ \nu &= \frac{\lambda}{2(\lambda + \mu)} \end{aligned} $$

**Proof**

명제1에 의해 다음이 성립한다.
$$ \begin{aligned} \epsilon_{11} &= \frac{1}{2\mu} \left( \sigma_{11} - \frac{\lambda}{3\lambda + 2\mu}\sigma_{11} \right) \\&= \frac{\lambda + \mu}{\mu (3\lambda + 2\mu)}\sigma_{11} \\ \epsilon_{22} = \epsilon_{33} &= -\frac{\lambda}{2\mu (3\lambda + 2\mu)}\sigma_{11} \\&= - \frac{\lambda}{2(\lambda + \mu)}\epsilon_{11}  \end{aligned} $$

따라서, 다음이 성립한다.
$$ \begin{aligned} E &= \frac{\sigma_{11}}{\epsilon_{11}} \\&=  \frac{\mu (3\lambda + 2\mu)}{\lambda + \mu} \\ \nu &= -\frac{\epsilon_{22}}{\epsilon_{11}} = -\frac{\epsilon_{33}}{\epsilon_{11}} \\&= \frac{\lambda}{2(\lambda + \mu)} \quad\tiny\blacksquare \end{aligned} $$

> Reference  
> [book] (Lai et al) Introduction to Continuum Mechanics Chap5.4


### 명제4(Simple shear stress state)
simple shear stress가 다음과 같이 주어졌다고 하자.
$$\sigma_{ij} = \begin{cases} \sigma_{12} & i=1, j=2 \\ 0 & \text{else} \end{cases} $$

이 떄, `전단계수(shear modulus)` $G$를 다음과 같이 정의하자.
$$ G:= \frac{\sigma_{12}}{2\epsilon_{12}}$$

다음을 증명하여라.
$$ G = \mu $$

**Proof**

명제1에 의해 다음이 성립한다.
$$ \begin{aligned} \epsilon_{12} &= \frac{1}{2\mu}  \sigma_{12} \\ \frac{\sigma_{12}}{2\epsilon_{12}} &= \mu \quad\tiny\blacksquare \end{aligned} $$

> Reference  
> [book] (Lai et al) Introduction to Continuum Mechanics Chap5.4

### 명제5(Hydrostatic state of stress)
simple shear stress가 다음과 같이 주어졌다고 하자.
$$\sigma_{ij} = \begin{cases} p & i=j \\ 0 & \text{else} \end{cases} $$

이 떄, `체적계수(bulk modulus)` $k$를 다음과 같이 정의하자.
$$ k:= \frac{p}{\epsilon_{ii}}$$

다음을 증명하여라.
$$ k = \lambda + \frac{2}{3}\mu $$

**Proof**

명제1에 의해 다음이 성립한다.
$$ \begin{aligned} & \epsilon_{ij} = \frac{1}{2\mu} \left( \sigma_{ij} - \frac{\lambda}{3\lambda + 2\mu}\sigma_{kk}\delta_{ij} \right)  \\ \Rightarrow \enspace &  \epsilon_{ii} = \frac{1}{2\mu} \left( 3p - \frac{9p\lambda}{3\lambda + 2\mu} \right) \\  \Rightarrow \enspace & \epsilon_{ii} = \frac{3p}{3\lambda + 2\mu} \\ \Rightarrow \enspace & \frac{p}{\epsilon_{ii}} = \lambda + \frac{2}{3}\mu \quad\tiny\blacksquare \end{aligned} $$

> Reference  
> [book] (Lai et al) Introduction to Continuum Mechanics Chap5.4


### 명제6(Relation between materal constants)
다음을 증명하여라,
$$ \begin{aligned} \mu &= \frac{E}{2(1+\nu)} \\ \lambda &= \frac{\nu}{(1-2\nu)(1+\nu)}E \end{aligned} $$

**Proof**

명제2로부터 다음이 성립한다.
$$ \begin{aligned} \lambda &= \frac{2\nu}{1 - 2\nu}\mu \\&= \frac{\mu(2\mu-E)}{E-3\mu} \end{aligned}  $$

이를, $\mu$에 대해 정리하면 다음과 같다.
$$ \begin{aligned} & \frac{2\nu}{1 - 2\nu}\mu = \frac{\mu(2\mu-E)}{E-3\mu} \\ \Rightarrow \enspace & \frac{2\nu}{1 - 2\nu} = \frac{2\mu-E}{E-3\mu} \\ \Rightarrow \enspace & 2\nu E - 6 \mu \nu = (2\mu - E)(1-2\nu) \\ \Rightarrow \enspace & -2(1 + \nu)\mu = -E \\ \Rightarrow \enspace & \mu = \frac{E}{2(1 + \nu)} \end{aligned} $$

이를 다시 위에 식에 대입하면 다음이 성립한다.
$$ \begin{aligned} \lambda &= \frac{2\nu}{1 - 2\nu}\mu \\&= \frac{\nu E}{(1 - 2\nu)(1 + \nu)} \quad\tiny\blacksquare \end{aligned}  $$

#### 참고
지금까지 본 재료상수들 $\lambda, \mu, E, \nu, \kappa$중 등방성 선형 탄성재료에서는 2개만 독립이다. 

즉, 두개의 재료상수로 나머지 재료 상수들을 전부 표현할 수 있고 그 관계식은 [book] (Lai et al) Introduction to Continuum Mechanics의 Table 5.1(212p)에 잘 정리되어 있다.

> Reference  
> [book] (Lai et al) Introduction to Continuum Mechanics Table 5.1

#### 명제6.1
다음을 증명하여라.
$$ \sigma_{ij} = \frac{E}{(1-2\nu)(1 + \nu)} ((1-2\nu)\epsilon_{ij} + \nu\epsilon_{kk} \delta_{ij}) $$

**Proof**

명제1과 명제6에 의해 다음이 성립한다.
$$ \begin{aligned} \sigma_{ij} &= \lambda \epsilon_{kk} \delta_{ij} + 2\mu\epsilon_{ij} \\&= \frac{\nu E}{(1 - 2\nu)(1 + \nu)} \epsilon_{kk}\delta_{ij} + \frac{E}{1 + \nu} \epsilon_{ij} \\&= \frac{E}{(1-2\nu)(1 + \nu)} ((1-2\nu)\epsilon_{ij} + \nu\epsilon_{kk}\delta_{ij}) \quad\tiny\blacksquare \end{aligned} $$

##### 참고
vognit notation을 이용하여 행렬로 나타내면 다음과 같다.
$$ \begin{bmatrix} \sigma_{11} \\ \sigma_{22} \\ \sigma_{33} \\ \sigma_{12} \\ \sigma_{23} \\ \sigma_{31} \end{bmatrix} =  \begin{bmatrix} c_1 & c_2 & c_2 & & & \\ c_2 & c_1 & c_2 &&& \\ c_2 & c_2 & c_1 &&& \\ &&& c_3 && \\ &&&& c_3 & \\ &&&&& c_3 \end{bmatrix} \begin{bmatrix} \epsilon_{11} \\ \epsilon_{22} \\ \epsilon_{33} \\ \epsilon_{12} \\ \epsilon_{23} \\ \epsilon_{31} \end{bmatrix} $$

$$ \begin{aligned} \text{Where, } c_1 &= \frac{E(1 - \nu)}{(1-2\nu)(1 + \nu)} \\ c_2 &= \frac{E\nu}{(1-2\nu)(1 + \nu)} \\ c_3 &= \frac{E}{1 + \nu} \end{aligned}  $$

#### 명제6.2
다음을 증명하여라.
$$ \epsilon_{ij} = \frac{1}{E} \Big( (1 + \nu) \sigma_{ij} - \nu\sigma_{kk}\delta_{ij} \Big) $$

**Proof**

명제2와 명제6에 의해 다음이 성립한다.
$$ \begin{aligned} \epsilon_{ij} &= \frac{1}{2\mu} \left( \sigma_{ij} - \frac{\lambda}{3\lambda + 2\mu}\sigma_{kk}\delta_{ij} \right) \\ &=  \frac{\lambda + \mu}{\mu(3\lambda + 2\mu)} \left( \frac{3\lambda + 2\mu}{2(\lambda + \mu)} \sigma_{ij} - \frac{\lambda}{2(\lambda + \mu)}\sigma_{kk}\delta_{ij} \right) \\ &= \frac{1}{E} \left( \frac{E}{2\mu} \sigma_{ij} - \nu\sigma_{kk}\delta_{ij} \right) \\ &= \frac{1}{E} \Big( (1 + \nu) \sigma_{ij} - \nu\sigma_{kk}\delta_{ij} \Big) \end{aligned} $$

##### 참고
vognit notation을 이용하여 행렬로 나타내면 다음과 같다.
$$ \begin{bmatrix} \epsilon_{11} \\ \epsilon_{22} \\ \epsilon_{33} \\ \epsilon_{12} \\ \epsilon_{23} \\ \epsilon_{31} \end{bmatrix} =  \begin{bmatrix} c_1 & c_2 & c_2 & & & \\ c_2 & c_1 & c_2 &&& \\ c_2 & c_2 & c_1 &&& \\ &&& c_3 && \\ &&&& c_3 & \\ &&&&& c_3 \end{bmatrix} \begin{bmatrix} \sigma_{11} \\ \sigma_{22} \\ \sigma_{33} \\ \sigma_{12} \\ \sigma_{23} \\ \sigma_{31} \end{bmatrix} $$

$$ \begin{aligned} \text{Where, } c_1 &= \frac{1}{E} \\ c_2 &= -\frac{\nu}{E} \\ c_3 &= \frac{1 + \nu}{E} \end{aligned}  $$


#### 명제6.3
다음을 증명하여라.
$$ \sigma_{ij} = (k - \frac{2}{3}\mu)\epsilon_{kk}\delta_{ij} + 2\mu\epsilon_{ij} $$

**Proof**

명제1과 Reference에 의해 다음이 성립한다.
$$ \begin{aligned} \sigma_{ij} &= \lambda \epsilon_{kk} \delta_{ij} + 2\mu\epsilon_{ij} \\&= (k- \frac{2}{3}\mu) \epsilon_{kk}\delta_{ij} + 2\mu \epsilon_{ij} \quad\tiny\blacksquare \end{aligned} $$

> Reference  
> [book] (Lai et al) Introduction to Continuum Mechanics Table 5.1

##### 참고
vognit notation을 이용하여 행렬로 나타내면 다음과 같다.
$$ \begin{bmatrix} \sigma_{11} \\ \sigma_{22} \\ \sigma_{33} \\ \sigma_{12} \\ \sigma_{23} \\ \sigma_{31} \end{bmatrix} =  \begin{bmatrix} c_1 & c_2 & c_2 & & & \\ c_2 & c_1 & c_2 &&& \\ c_2 & c_2 & c_1 &&& \\ &&& c_3 && \\ &&&& c_3 & \\ &&&&& c_3 \end{bmatrix} \begin{bmatrix} \epsilon_{11} \\ \epsilon_{22} \\ \epsilon_{33} \\ \epsilon_{12} \\ \epsilon_{23} \\ \epsilon_{31} \end{bmatrix} $$

$$ \begin{aligned} \text{Where, } c_1 &= k + \frac{4}{3}\mu \\ c_2 &= k - \frac{2}{3}\mu \\ c_3 &= 2\mu \end{aligned}  $$

##### 참고2
다음과 같이 형태를 변형할 수 있다.
$$ \begin{aligned} \sigma_{ij} &= (k - \frac{2}{3}\mu)\epsilon_{kk}\delta_{ij} + 2\mu\epsilon_{ij} \\&= 2\mu(\epsilon_{ij} - \frac{\epsilon_{kk}}{3}\delta_{ij}) + k \epsilon_{kk} \delta_{ij} \end{aligned} $$

# 비등방성 선형탄성 재료
방향에 따라 물성치가 변할 경우 이를 `비등방성(anistropic)`재료라고 한다.

# 유체
## 구성방정식

> 참고  
[Navier-Stokes equation - Wiki](https://en.wikipedia.org/wiki/Navier%E2%80%93Stokes_equations)  

