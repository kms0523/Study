
`구성방정식(constitutive equation)`은 stress와 그에 대응하는 변형의 관계를 나타내는 방정식이다.

# Linearly Elastic Solid
Small deformation 가정을 하자.

이 때, 다음 constitutive equation을 만족하는 재료를 `선형탄성재료(linearly elastic solid)`라고 한다.
$$ \sigma = C(\epsilon) $$

이 때, $\sigma$는 Cauchy stress tensor이고 ${\epsilon}$은 infinitesimal strain tensor이고 $C$는 `선형 강성 텐서(linear stiffness tensor)`이다.

$C$는 4차 텐서로 $\sigma - \epsilon$의 선형관계를 나타내는 계수들을 표현한 텐서이다.

Linear elastic solid의 constitutive equation을 cartesian coordinate에서 나타내면 다음과 같다.
$$ \sigma_{ij} = C_{ijkl} \epsilon_{kl} $$

> Reference  
> [Book] (Lai et al) Introduction to Continuum Mechanics Chap5.2  

## Elasticity Tensor
$\bf C$는 4차 텐서임으로 81개의 독립변수를 갖는다. 하지만 ${\epsilon}$과 ${\sigma}$의 대칭성 및 $U$에 의해 독립변수 개수가 줄어들게 된다.

먼저 ${\epsilon}$의 대칭성을 고려해보자. $\epsilon_{kl} = \epsilon_{lk}$임으로 $C_{ijkl}\epsilon_{kl} + C_{ijlk}\epsilon_{lk} = (C_{ijkl} + C_{ijlk} ) \epsilon_{kl}$이다(여기서는 summation notation이 사용된게 아니다). 따라서 두개의 독립변수 $C_{ijkl}, C_{ijlk}$가 있는 것이 아닌 하나의 독립변수 $( C_{ijkl} + C_{ijlk} )$가 있게 된다. $( C_{ijkl} + C_{ijlk} )$를 하나의 독립변수로 두는 것은 $C_{ijkl} = C_{ijlk}$로 두는것과 동치이다. 이를 통해 $\bf C$의 독립변수 숫자는 $3 \times 3 \times 6 = 54$로 줄어들게 된다.

다음으로 ${\sigma}$의 대칭성을 고려해보자. $\sigma_{ij} = \sigma_{ji} \Rightarrow C_{ijkl}\epsilon_{kl} = C_{jikl}\epsilon_{kl}$임으로 $C_{ijkl} = C_{jikl}$이 된다. 따라서 $\bf C$의 독립변수 숫자는 $6 \times 6 = 36$로 줄어들게 된다.

마지막으로 $U$를 고려하자. $\sigma_{ij} = C_{ijkl}\epsilon_{kl}$임으로 다음이 성립한다.
$$ C_{ijkl} = \frac{\partial\sigma_{ij}}{\partial \epsilon_{kl}} $$

식(12)를 대입하면 다음과 같다.
$$ C_{ijkl} = \frac{\partial^2 U}{\partial \epsilon_{ij}\partial \epsilon_{kl}} = \frac{\partial\sigma_{kl}}{\partial \epsilon_{ij}} = C_{klij} $$

따라서 $\bf C$의 독립변수 숫자는 21개로 줄어들게 된다.

>참고  
[book] (Lai et al) Introduction to Continuum Mechanics Chap5.2

# 등방성 선형 탄성 재료
특정 방향에 따라 물성치가 변하지 않을 때 `등방성(isotropic)`재료라고 한다. 따라서 등방성 재료의 경우 모든 방향에서 응력-변형률 관계가 같아야 한다. 그리고 모든 방향에서 응력-변형률 관계가 같으려면 $\bf C$가 isotropic tensor여야 한다.

fourth-order isotropic tensor의 경우 다음과 같은 general form을 갖는다.
$$ C_{ijkl} = \lambda \delta_{ij}\delta_{kl} + \alpha \delta_{ik}\delta_{jl} + \beta \delta_{il}\delta_{jk} $$

식(11)에 대입하여 응력-변형률 관계식을 정리하면 다음과 같다.
$$ \begin{equation} \sigma_{ij} = \lambda \epsilon_{kk}\delta_{ij} + 2\mu\epsilon_{ij} \end{equation} $$
$$ \text{Where, } 2\mu = \alpha + \beta$$

식(13)으로부터 다음 관계식을 얻을 수 있다.
$$ \sigma_{ii} = (3\lambda + 2\mu) \epsilon_{kk} $$

따라서 식(13)을 정리하여 변형률-응력 관계식을 정리하면 다음과 같다.
$$ \begin{equation} \epsilon_{ij} = \frac{1}{2\mu} \left( \sigma_{ij} - \frac{\lambda}{3\lambda + 2\mu}\sigma_{kk}\delta_{ij} \right) \end{equation} $$

응력-변형률 관계식과 변형률-응력 관계식에서 공통적으로 나타나는 두 개의 재료 상수 $\lambda$, $\mu$를 `Lame's constant`라고 한다. $\epsilon$이 무차원 변수임으로 Lame's constant는 응력과 동일한 차원을 갖는다.

> 참고  
[book] (Lai et al) Introduction to Continuum Mechanics Chap5.3

## unaxial stress state
만약 하나의 normal stree만 존재하고 나머지는 전부 0인 경우를 `uniaxial stress state`라고 한다. 

uniaxial stress state 일 때, 변형률-응력 관계식은 다음과 같다.
$$ \begin{equation} \begin{gathered} \epsilon_{11} = \frac{1}{2\mu} \left( \sigma_{11} - \frac{\lambda}{3\lambda + 2\mu}\sigma_{11} \right) = \frac{\lambda + \mu}{\mu (3\lambda + 2\mu)}\sigma_{11} \\ \epsilon_{22} = \epsilon_{33} = \frac{1}{2\mu} \left( 0 - \frac{\lambda}{3\lambda + 2\mu}\sigma_{11} \right) = -\frac{\lambda}{2\mu (3\lambda + 2\mu)}\sigma_{11} = - \frac{\lambda}{2(\lambda + \mu)}\epsilon_{11} \\ \epsilon_{12} = \epsilon_{13} = \epsilon_{23} = 0 \end{gathered} \end{equation} $$

식(15)로부터 다음과 같은 새로운 재료상수를 얻을 수 있다.
$$ \begin{equation} \begin{gathered} E_Y = \frac{\sigma_{11}}{\epsilon_{11}} =  \frac{\mu (3\lambda + 2\mu)}{\lambda + \mu} \\ \nu = -\frac{\epsilon_{22}}{\epsilon_{11}} = -\frac{\epsilon_{33}}{\epsilon_{11}} = \frac{\lambda}{2(\lambda + \mu)} \end{gathered} \end{equation}   $$

이 때, $E_Y$를 `탄성계수(Young's modulus, modulus of elasticity)`라고 하며 $\nu$를 `프와송비(Poisson's ratio)`라고 한다.

식(16)에서 $\lambda$를 제거하면 $\mu(E_Y,\nu)$을 얻을 수 있고 이를 통해 $\lambda(E_Y,\nu)$도 얻을 수 있다.
$$ \begin{equation} \begin{aligned} \mu &= \frac{E_Y}{2(1+\nu)} \\ \lambda &= \frac{\nu}{(1-2\nu)(1+\nu)}E_Y \end{aligned} \end{equation} $$

식(16)에서 얻은 재료 상수를 식(13)에 대입하고 식(17)의 관계를 이용하면 다음과 같은 변형률-응력 관계식을 얻는다.
$$ \begin{equation} \begin{aligned} \epsilon_{ij} &= \frac{1}{2\mu} \left( \sigma_{ij} - \frac{\lambda}{3\lambda + 2\mu}\sigma_{kk}\delta_{ij} \right) \\ &=  \frac{\lambda + \mu}{\mu(3\lambda + 2\mu)} \left( \frac{3\lambda + 2\mu}{2(\lambda + \mu)} \sigma_{ij} - \frac{\lambda}{2(\lambda + \mu)}\sigma_{kk}\delta_{ij} \right) \\ &= \frac{1}{E_Y} \left( \frac{E_Y}{2\mu} \sigma_{ij} - \nu\sigma_{kk}\delta_{ij} \right) \\ &= \frac{1}{E_Y} \Big( (1 + \nu) \sigma_{ij} - \nu\sigma_{kk}\delta_{ij} \Big) \end{aligned} \end{equation} $$

> 참고  
[book] (Lai et al) Introduction to Continuum Mechanics Chap5.4

## Simple shear stress state
하나의 shear stress만 존재하고 나머지는 전부 0인 경우를 `simple shear stress state`라고 한다.

simple shear stress state일 때 Lame's constant로 나타낸 변형률-응력 관계식은 다음과 같다.
$$ \begin{equation} \epsilon_{12} = \frac{\sigma_{12}}{2\mu} \end{equation} $$

식(19)로부터 다음과 같은 재료상수를 얻을 수 있다.
$$ G = \frac{\sigma_{12}}{2\epsilon_{12}} = \mu $$

이 때, $G$를 `전단계수(shear modulus)`라고 한다.

다음으로, simple shear stress state일 때 $E_Y, \nu$로 나타낸 변형률-응력 관계식은 다음과 같다.
$$ \epsilon_{12} = \frac{1+\nu}{E_Y}\sigma_{12} $$

따라서 다음이 성립한다.
$$ G =\frac{\sigma_{12}}{2\epsilon_{12}} = \frac{E_Y}{2(1 + \nu)} $$

> 참고  
[book] (Lai et al) Introduction to Continuum Mechanics Chap5.4

## hydrostatic state of stress
${\sigma} = p \bf I$인 경우를 `hydrostatic state of stress`라고 한다.

hydrostatic state of stress일 때 Lame's constant로 나타낸 변형률-응력 관계식은 다음과 같다.
$$ \begin{equation} \epsilon_{ii} = \frac{3p}{3\lambda + 2\mu} \end{equation} $$

식(20)으로부터 다음과 같은 재료상수를 얻을 수 있다.
$$ k = \frac{p}{\epsilon_{ii}} = \lambda + \frac{2}{3}\mu $$

이 떄, $k$를 `체적계수(bulk modulus)`라고 한다.

다음으로, hydrostatic state of stress일 때 $E_Y, \nu$로 나타낸 변형률-응력 관계식은 다음과 같다.
$$ \epsilon_{ii} = \frac{3(1 - 2\nu)}{E_Y}p $$

따라서 다음이 성립한다.
$$ k =\frac{p}{\epsilon_{ii}} = \frac{E_Y}{3(1 - 2\nu)} $$

## 상수간의 관계식
지금까지 본 재료상수들 $\lambda, \mu, E_Y, \nu, G, \kappa$중 등방성 선형 탄성재료에서는 2개만 독립이다. 즉, 두개의 재료상수로 나머지 재료 상수들을 전부 표현할 수 있고 그 관계식은 [book] (Lai et al) Introduction to Continuum Mechanics의 Table 5.1(212p)에 잘 정리되어 있다.

> 참고  
[book] (Lai et al) Introduction to Continuum Mechanics Chap5.4

# 비등방성 선형탄성 재료
방향에 따라 물성치가 변할 경우 이를 `비등방성(anistropic)`재료라고 한다.


# 유체
## 구성방정식

> 참고  
[Navier-Stokes equation - Wiki](https://en.wikipedia.org/wiki/Navier%E2%80%93Stokes_equations)  

