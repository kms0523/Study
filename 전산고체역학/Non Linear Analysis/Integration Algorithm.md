# Integration Algorithm
선형 탄성 재료에 J2 plasticity model을 사용한다고 하자.

이 떄, 다음 값들이 주어져 있다고 하자.
* elastic modulus $E$
* plastic modulus $H$
* $n$번째 load increment에서 stress ${}^n\sigma$
* $n$번째 load increment에서 back stress ${}^n\alpha$
* $n$번째 load increment에서 effective plastic strain ${}^n\epsilon_e^p$

이 상황에서 strain increment $\Delta \epsilon$이 주어졌을 때, ${}^{n+1}\sigma, {}^{n+1}\alpha,{}^{n+1}\epsilon_e^p$를 구해보자.

## 1. Elasticity assumption
J2 plasticity model의 가정에 의해 다음이 성립한다.
$$ \sigma = C : \epsilon^e $$

$$ \text{Where, } C \text{ is a linear elastic stiffness tensor} $$

$\Delta \epsilon$가 더해진 후에도 elastic영역이여서 $\Delta \epsilon^p = 0$이라 가정하면 다음이 성립한다.
$$ \begin{aligned} {}^{tr} \sigma &= C : ({}^{n}\epsilon + \Delta \epsilon) \\ {}^{tr}\alpha &= {}^n\alpha \\ {}^{tr} \epsilon_e^p &= {}^n\epsilon_e^p \end{aligned}  $$

이 때, trial deviatoric stress은 다음과 같다.
$$ {}^{tr}\tilde\sigma = {}^{n}\tilde\sigma + 2 \mu \Delta \tilde\epsilon $$

### 명제1
${}^{tr}\sigma$가 아래와 같이 주어졌다고하자.
$$ {}^{tr}\sigma = C:({}^n \epsilon + \Delta \epsilon) $$

$$ \text{Where, } C \text{ is a linear elastic stiffness tensor} $$

이 떄, 다음을 증명하여라.
$$ {}^{tr}\tilde\sigma = {}^{n}\tilde\sigma + 2 \mu \Delta \tilde\epsilon $$

**Proof**

$$ \begin{aligned} {}^{tr}\tilde\sigma &= C : (\widetilde{{}^n \epsilon + \Delta \epsilon}) \\ &= C : ({}^n \tilde\epsilon + \Delta \tilde\epsilon) \\&= (\lambda\delta_{ij}\delta_{kl} + \mu (\delta_{ik}\delta_{jl} + \delta_{il}\delta_{jk})) ({}^n \tilde\epsilon_{kl} + \Delta \tilde\epsilon_{kl}) e_{ij} \\&= \lambda\delta_{ij}({}^n \tilde\epsilon_{kk} + \Delta \tilde\epsilon_{kk}) e_{ij} + \mu ({}^n \tilde\epsilon_{ij} + {}^n \tilde\epsilon_{ji} + \Delta \tilde\epsilon_{ij} + \Delta \tilde\epsilon_{ji}) e_{ij} \end{aligned} $$

$\tilde \epsilon$와 $\Delta \tilde \epsilon$ 모두 symmetric & deviatoric tensor임으로 다음이 성립한다.
$$ \begin{aligned} {}^{tr}\tilde\sigma &= \lambda\delta_{ij}({}^n \tilde\epsilon_{kk} + \Delta \tilde\epsilon_{kk}) e_{ij} + \mu ({}^n \tilde\epsilon_{ij} + {}^n \tilde\epsilon_{ji} + \Delta \tilde\epsilon_{ij} + \Delta \tilde\epsilon_{ji}) e_{ij} \\&= 2\mu {}^n (\tilde\epsilon_{ij} + \Delta \tilde\epsilon_{ij}) e_{ij} \\&= {}^n \tilde\sigma + 2\mu \Delta \tilde\epsilon \quad {_\blacksquare} \end{aligned} $$


## 2. Checking yield condition
Elasticity 가정이 옳바른지 판단하기 위해, 현재 trial stress들이 yield condition을 만족하는지 확인한다.

J2 plasticity model의 yield function $f$는 다음과 같다.
$$ f(\sigma, \alpha, \epsilon_e^p) := \lVert \eta(\sigma,\alpha) \rVert - \sqrt{\frac{2}{3}}K(\epsilon_e^p) $$

$$ \text{Where, } \eta := \tilde\sigma - \alpha $$

이 때, yield condition은 다음과 같다.
$$ f({}^{tr}\sigma, {}^{tr}\alpha, {}^{tr}\epsilon_e^p) \le 0 $$

Yield condition을 만족하는 경우 elastic assumption은 참이 된다.

따라서 ${}^{n+1}\sigma, {}^{n+1}\alpha,{}^{n+1}\epsilon_e^p$는 다음과 같은 값을 갖는다.
$$ \begin{aligned} {}^{n+1}\sigma &= {}^{tr}\sigma \\ {}^{n+1}\alpha &= {}^{tr}\alpha \\ {}^{n+1} \epsilon_e^p &= {}^{tr} \epsilon_e^p \end{aligned}$$

이 떄, $\Delta \sigma$는 다음과 같다.
$$ \Delta \sigma = C : \Delta \epsilon $$

Yield condition을 만족하는 경우, 원하는 모든 값들을 찾았음으로 알고리즘을 종료한다.

## 3. Plasticity correction
Yield condition을 만족하지 않는 경우 elastic assumption은 거짓이 된다.

따라서 $\Delta \epsilon^p \neq 0$이 되고 plastic strain에 대한 correction이 필요하게 된다. 
$$ \begin{aligned} {}^{n+1} \sigma &= {}^{tr} \sigma + \sigma_c \\ {}^{n+1}\alpha &= {}^{tr}\alpha + \alpha_c \\ {}^{n+1} \epsilon_e^p &= {}^{tr} \epsilon_e^p + (\epsilon_e^p)_c \end{aligned}$$

Time integration scheme으로 backward Euler method를 사용한다고하자.

J2 plasticity model에 의해 stress correction term $\sigma_c$, back stress correction term $\alpha_c$, effective plastic strain correction term $(\epsilon_e^p)_c$는 다음과 같다.
$$ \begin{aligned} \sigma_c &= -2 \mu \Delta\gamma ({}^{n+1}N) \\  \alpha_c &= H \Delta\gamma ({}^{n+1}N) \\ (\epsilon_e^p)_c &= \sqrt{\frac{2}{3}} \Delta\gamma \end{aligned} $$

$$ \text{Where, } N = \frac{\sigma - \alpha}{\lVert \sigma - \alpha \rVert} $$

따라서 stress, back stress, yield stress는 다음과 같다.
$$ \begin{aligned} {}^{n+1}\sigma &= {}^{tr}\sigma -2 \mu \Delta\gamma ({}^{n+1}N) \\ {}^{n+1}\alpha &= {}^{tr}\alpha + H({}^{n+1}\epsilon_e^p) \Delta\gamma ({}^{n+1}N) \\ {}^{n+1} \epsilon_e^p &= {}^{tr}\epsilon_e^p + \sqrt{\frac{2}{3}} \Delta\gamma \end{aligned} $$

$$ \text {Where, } {}^{n+1}N := N({}^{n+1}\sigma, {}^{n+1}\alpha)$$

이 떄, $\Delta \sigma$는 다음과 같다.
$$ \Delta \sigma = C : \Delta \epsilon - 2 \mu \Delta\gamma N $$

### 명제1
선형 탄성 재료에 J2 plasticity model을 사용한다고 하자.

$\Delta \epsilon$이 주어졌을 때, ${}^{tr}\sigma$을 다음과 같이 가정하자.
$$ {}^{tr} \sigma = C:({}^n \epsilon + \Delta \epsilon) $$

Time integration scheme으로 backward Euler method를 사용하고 $\Delta \epsilon^p \neq 0$일 때, 다음을 증명하여라.
$$ {}^{n+1}\sigma = {}^{tr}\sigma - 2\mu \Delta \gamma ({}^{n+1}N) $$

**Proof**

J2 plasticity model의 flow rule에 의해 다음이 성립한다.
$$ \frac{\partial \epsilon^p}{\partial t} = \gamma N $$

또한 J2 plasticity model의 linear elastic 가정에 의해 다음이 성립한다.
$$ \begin{aligned} {}^{n+1}\sigma &= C : ({}^{n}\epsilon +  \Delta \epsilon^e) \\&= C : ({}^{n}\epsilon + \Delta \epsilon - \Delta \epsilon^p ) \\&= C : ({}^{n}\epsilon + \Delta \epsilon) - C : \Delta \epsilon^p \end{aligned} $$

Implicit Euler method 의해 다음이 성립한다.
$$ \begin{aligned} {}^{n+1}\sigma &= C : ({}^{n}\epsilon + \Delta \epsilon) - C : \Delta \epsilon^p \\&= {}^{tr}\sigma - \Delta t \gamma C : {}^{n+1}N \\&= {}^{tr}\sigma - 2\mu \Delta \gamma({}^{n+1}N) \quad {_\blacksquare} \end{aligned} $$


### 명제2
선형 탄성 재료에 J2 plasticity model을 사용한다고 하자.

$\Delta \epsilon^p \neq 0$일 때, 다음을 증명하여라.
$$ {}^{n+1}\alpha = {}^{n}\alpha + H({}^{n+1}\epsilon_e^p) \Delta \gamma({}^{n+1}N) $$

**Proof**

J2 plasticity model의 hardening rule과 flow rule에 의해 다음이 성립한다.
$$ \frac{\partial \alpha}{\partial t} = H(\epsilon_e^p) \ \gamma N $$

Implicit Euler integration method에 의해 다음이 성립한다.
$$ \begin{aligned} {}^{n+1}\alpha &= {}^{n}\alpha + \Delta t H({}^{n+1}\epsilon_e^p) \gamma({}^{n+1}N) \\&= {}^{n}\alpha + H({}^{n+1}\epsilon_e^p) \Delta\gamma({}^{n+1}N) \quad {_\blacksquare} \end{aligned} $$

### 명제3
선형 탄성 재료에 J2 plasticity model을 사용한다고 하자.

$\Delta \epsilon^p \neq 0$일 때, 다음을 증명하여라.
$$ {}^{n+1}\epsilon_e^p = {}^{n}\epsilon_e^p + \sqrt{\frac{2}{3}}\Delta \gamma $$

**Proof**

J2 plasticity model의 hardening rule과 flow rule에 의해 다음이 성립한다.
$$ \frac{\partial \epsilon_e^p}{\partial t} = \sqrt{\frac{2}{3}} \gamma  $$

Implicit Euler method에 의해 다음이 성립한다.
$$ \begin{aligned} {}^{n+1}\epsilon_e^p &= {}^{n}\epsilon_e^p + \Delta t \sqrt{\frac{2}{3}} \gamma \\&= {}^{n}\epsilon_e^p + \sqrt{\frac{2}{3}}\Delta \gamma \quad {_\blacksquare}\end{aligned} $$

### 명제4
stress, back stress가 다음과 같이 주어졌을다고 하자.
$$ \begin{aligned} {}^{n+1}\sigma &= {}^{tr}\sigma -2 \mu \Delta\gamma ({}^{n+1}N) \\ {}^{n+1}\alpha &= {}^{tr}\alpha + H({}^{n+1}\epsilon_e^p) \Delta\gamma ({}^{n+1}N), \end{aligned} $$

다음을 증명하여라.
$$ {}^{n+1}\eta  = {}^{tr}\eta - \Delta\gamma(2\mu + H)({}^{n+1}N) $$

**Proof**

$N$은 deviatoric tensor임으로 다음이 성립한다.
$$ \begin{aligned} {}^{n+1}\tilde\sigma &= {}^{tr}\tilde\sigma -2 \mu \Delta\gamma ({}^{n+1}\tilde N) \\&= {}^{tr}\tilde\sigma -2 \mu \Delta\gamma ({}^{n+1} N) \end{aligned} $$

따라서 $\eta$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} {}^{n+1}\eta &= {}^{n+1}\tilde\sigma - {}^{n+1}\alpha \\&= {}^{tr}\eta - \Delta\gamma (2 \mu  + H)({}^{n+1}N) \\&= {}^{tr}\eta - \Delta\gamma (2 \mu  + H)({}^{n+1}N) \quad {_\blacksquare} \end{aligned} $$


### 명제5
stress, back stress, yield stress가 다음과 같이 주어졌을 때,
$$ \begin{aligned} {}^{n+1}\sigma &= {}^{tr}\sigma -2 \mu \Delta\gamma ({}^{n+1}N) \\ {}^{n+1}\alpha &= {}^{tr}\alpha + H({}^{n+1}\epsilon_e^p) \Delta\gamma ({}^{n+1}N) \\ {}^{n+1} \epsilon_e^p &= {}^{tr}\epsilon_e^p + \sqrt{\frac{2}{3}} \Delta\gamma, \end{aligned} $$

다음을 증명하여라.
$$ {}^{n+1}N = {}^{tr}N $$

$$ \text {Where, } {}^{n}N := N({}^{n}\sigma, {}^{n}\alpha)$$

**Proof**

명제4에 의해 다음이 성립한다.
$$ \begin{aligned} & {}^{n+1}\eta  = {}^{tr}\eta - \Delta\gamma(2\mu + H)({}^{n+1}N) \\ \Rightarrow \enspace & (\lVert {}^{n+1}\eta \rVert + \Delta\gamma(2\mu + H)) ({}^{n+1}N) = {}^{tr}\eta\\ \Rightarrow \enspace & {}^{tr}\eta = C ({}^{n+1}N) \end{aligned} $$

이는 ${}^{tr}\eta$과 ${}^{n+1}N$이 평행하다는 의미이다.

따라서,  ${}^{tr}\eta$의 방향을 나타내는 ${}^{tr}N$과 같다.
$$ {}^{n+1}N = {}^{tr}N $$

#### 명제5.1
$$ \lVert {}^{tr}\eta + C ({}^{n+1}N) \rVert = \lVert {}^{tr}\eta \rVert + C $$

**Proof**
$$ \begin{aligned} \lVert {}^{tr}\eta + C ({}^{n+1}N) \rVert &= \lVert \lVert {}^{tr}\eta \rVert({}^{tr}N) + C ({}^{n+1}N) \rVert \\&= \lVert (\lVert {}^{tr}\eta \rVert + C) ({}^{n+1}N) \rVert \\&= \lVert {}^{tr}\eta \rVert + C \end{aligned} $$

### 명제6
함수 $f$가 다음과 같이 주어졌다고 하자.
$$ f(\sigma, \alpha,  \epsilon_e^p) = \lVert \eta \rVert - \sqrt{\frac{2}{3}}K(\epsilon_e^p) $$

stress, back stress, plastic equivalent stress가 다음과 같이 주어졌을 때,
$$ \begin{aligned} {}^{n+1}\sigma &= {}^{tr}\sigma -2 \mu \Delta\gamma ({}^{n+1}N) \\ {}^{n+1}\alpha &= {}^{tr}\alpha + H({}^{n+1}\epsilon_e^p) \Delta\gamma ({}^{n+1}N) \\ {}^{n+1} \epsilon_e^p &= {}^{tr}\epsilon_e^p + \sqrt{\frac{2}{3}} \Delta\gamma, \end{aligned} $$

다음을 증명하여라.
$$ f({}^{n+1}\sigma, {}^{n+1}\alpha, {}^{n+1} \epsilon_e^p) = \lVert {}^{tr}\eta \rVert - (H({}^{n+1}\epsilon_e^p) + 2\mu) \Delta\gamma - \sqrt{\frac{2}{3}}k({}^{n+1}\epsilon_e^p) $$

**Proof**

$f$에 주어진 값을 대입하면 다음과 같다.
$$ \begin{aligned} f({}^{n+1}\sigma, {}^{n+1}\alpha, {}^{n+1} \epsilon_e^p) &= \lVert {}^{n+1}\eta \rVert - \sqrt{\frac{2}{3}}k({}^{n+1}\epsilon_e^p) \\ &= \lVert {}^{tr}\eta - (H({}^{n+1}\epsilon_e^p) + 2\mu) \Delta\gamma ({}^{n+1}N) \rVert - \sqrt{\frac{2}{3}}k({}^{n+1}\epsilon_e^p) \end{aligned}$$

명제5.1에 의해 다음이 성립한다.
$$ \begin{aligned} f({}^{n+1}\sigma, {}^{n+1}\alpha, {}^{n+1} \epsilon_e^p) &= \lVert {}^{tr}\eta - (H({}^{n+1}\epsilon_e^p) + 2\mu) \Delta\gamma ({}^{n+1}N) \rVert - \sqrt{\frac{2}{3}}k({}^{n+1}\epsilon_e^p) \\&= \lVert {}^{tr}\eta \rVert - (H({}^{n+1}\epsilon_e^p) + 2\mu) \Delta\gamma - \sqrt{\frac{2}{3}}k({}^{n+1}\epsilon_e^p)\end{aligned}$$

## 4. Calculating $\Delta \gamma$
$n+1$번째 값들은 plastic state에 있어야 하기 때문에 다음과 같은 discrete plastic consistency condition을 만족해야한다.
$$ \begin{aligned} & f({}^{n+1}\sigma, {}^{n+1}\alpha, {}^{n+1} \epsilon_e^p) = 0 \\ \Rightarrow \enspace & \lVert {}^{tr}\eta \rVert - (H({}^{n+1}\epsilon_e^p) + 2\mu) \Delta\gamma - \sqrt{\frac{2}{3}}K({}^{n+1}\epsilon_e^p) = 0 \end{aligned} $$

이 때, ${}^{tr}\tilde\sigma,{}^{tr}\alpha,{}^{tr}\epsilon_e^p$는 전부 아는 값임으로 유일한 변수는 $\Delta\gamma$가 된다.
$$ f_{alg}(\Delta\gamma) := \lVert {}^{tr}\eta \rVert - (H({}^{n+1}\epsilon_e^p) + 2\mu) \Delta\gamma - \sqrt{\frac{2}{3}}K({}^{n+1}\epsilon_e^p)$$

따라서 $f_{alg}=0$이 되게 $\Delta\gamma$을 결정한다.

Nonlinear equation인 $f_{alg}=0$을 풀기 위해 newton-raphson method를 사용한다.

1. $k=0$으로 두고 초기 해 ${}^k\Delta\gamma = 0$으로 둔다.
2. ${}^k\Delta\gamma$에서 $f$를 선형근사한다.
$$ y= f_{alg}'({}^k\Delta\gamma)(\Delta\gamma - {}^k\Delta\gamma) + f_{alg}({}^k\Delta\gamma) $$

$$ \text{Where, } f_{alg}'(\Delta\gamma) := \frac{\partial f_{alg}}{\partial \Delta\gamma} = -2\mu + H({}^{n+1}\epsilon_e^p) + \frac{\partial H}{\partial \epsilon_e^p} \sqrt{\frac{2}{3}} \Delta\gamma + \frac{2}{3}\frac{\partial K}{\partial \epsilon_e^p}$$
3. 선형근사한 함수의 해 ${}^{k+1}\Delta\gamma$을 찾는다.
$$ {}^{k+1}\Delta\gamma = {}^{k}\Delta\gamma - \frac{f_{alg}({}^{k}\Delta\gamma)}{f_{alg}'({}^{k}\Delta\gamma)}$$
4. ${}^{k+1}\Delta\gamma$이 수렴 조건을 만족하는지 확인한다.
$$ f_{alg}({}^{k+1}\Delta\gamma) \le \epsilon \enspace \land \enspace N \le k + 1  $$   
5. 만족하지 않는 경우 $k = k +1$로 두고 과정2로 돌아간다.

### 명제1
함수 $f_{alg}$가 다음과 같이 주어졌다고 하자.
$$ f_{alg}(\Delta\gamma) := \lVert {}^{tr}\eta \rVert - (H({}^{n+1}\epsilon_e^p) + 2\mu) \Delta\gamma - \sqrt{\frac{2}{3}}K({}^{n+1}\epsilon_e^p)$$

이 때, 다음을 증명하여라.
$$ \frac{\partial f_{alg}}{\partial \Delta \epsilon} = 2\mu N - \bigg( 2\mu + H({}^{n+1}\epsilon_e^p) + \sqrt{\frac{2}{3}}\frac{\partial H}{\partial \epsilon_e^p} \Delta\gamma + \frac{2}{3} \frac{\partial K}{\partial \epsilon_e^p} \bigg)\frac{\partial \Delta \gamma}{ \partial \Delta \epsilon} $$

**Proof**

$f_{alg}$의 정의에 의해 다음이 성립한다.
$$ \frac{\partial f_{alg}}{\partial \Delta \epsilon} = \frac{\partial \lVert {}^{tr}\eta \rVert}{\partial \Delta \epsilon} - (H({}^{n+1}\epsilon_e^p) + 2\mu)  \frac{\partial \Delta\gamma}{\partial \Delta \epsilon} - \frac{\partial H({}^{n+1}\epsilon_e^p)}{\partial \Delta \epsilon} \Delta\gamma - \sqrt{\frac{2}{3}} \frac{\partial K({}^{n+1}\epsilon_e^p)}{\partial \Delta \epsilon} $$

명제1.1-3에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial f_{alg}}{\partial \Delta \epsilon} &= \frac{\partial \lVert {}^{tr}\eta \rVert}{\partial \Delta \epsilon} - (H({}^{n+1}\epsilon_e^p) + 2\mu)  \frac{\partial \Delta\gamma}{\partial \Delta \epsilon} - \frac{\partial H({}^{n+1}\epsilon_e^p)}{\partial \Delta \epsilon} \Delta\gamma - \sqrt{\frac{2}{3}} \frac{\partial K({}^{n+1}\epsilon_e^p)}{\partial \Delta \epsilon} \\&= 2\mu N - (H({}^{n+1}\epsilon_e^p) + 2\mu)  \frac{\partial \Delta\gamma}{\partial \Delta \epsilon} - \sqrt{\frac{2}{3}} \Delta \gamma \frac{\partial H}{\partial \epsilon_e^p} \frac{\partial \Delta \gamma}{\partial \Delta \epsilon} - \frac{2}{3} \frac{\partial K}{\partial \epsilon_e^p} \frac{\partial \Delta \gamma}{\partial \Delta \epsilon} \\&= 2\mu N - \bigg( 2\mu + H({}^{n+1}\epsilon_e^p) + \sqrt{\frac{2}{3}}\frac{\partial H}{\partial \epsilon_e^p} \Delta\gamma + \frac{2}{3} \frac{\partial K}{\partial \epsilon_e^p} \bigg)\frac{\partial \Delta \gamma}{ \partial \Delta \epsilon} \end{aligned} $$


#### 명제1.1
선형 탄성 재료에 J2 plasticity model을 사용한다고 할 때, 다음을 증명하여라.
$$ \frac{\partial \lVert {}^{tr}\eta \rVert}{\partial \Delta \epsilon} = 2\mu N $$

**Proof**

${}^{tr}\eta$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial {}^{tr}\eta}{\partial \Delta\tilde\epsilon} &= \frac{\partial }{\partial \Delta \tilde \epsilon} ({}^n \tilde \sigma + 2 \mu \Delta \tilde \epsilon - {}^n\alpha) \\&= \frac{\partial }{\partial \Delta \tilde \epsilon_{kl}} ({}^n \tilde \sigma_{ij} + 2 \mu \Delta \tilde \epsilon_{ij} - {}^n\alpha_{ij}) e_{ijkl} \\&= 2\mu \delta_{ik} \delta_{jl} e_{ijkl} \end{aligned}  $$

따라서, chain rule에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial \lVert {}^{tr}\eta \rVert}{\partial \Delta \epsilon} &= \frac{\partial \lVert {}^{tr}\eta \rVert}{\partial {}^{tr}\eta} \frac{\partial {}^{tr}\eta}{\partial \Delta\tilde\epsilon} \frac{\partial \Delta \tilde \epsilon}{\partial \Delta\epsilon} \\&= N_{ij} (2\mu \delta_{ik} \delta_{jl}) \bigg( \delta_{km}\delta_{ln} - \frac{1}{3} \delta_{kl}\delta_{mn} \bigg)e_{mn} \\&= 2\mu N_{kl} \bigg( \delta_{km}\delta_{ln} - \frac{1}{3} \delta_{kl}\delta_{mn} \bigg)e_{mn} \\&= 2\mu ( N_{mn} - \frac{1}{3} N_{kk\delta_{mn}} ) e_{mn} \end{aligned} $$

$N$은 deviatoric tensor임으로 다음이 성립한다.
$$ \begin{aligned} \frac{\partial \lVert {}^{tr}\eta \rVert}{\partial \Delta \epsilon} &= 2\mu ( N_{mn} - \frac{1}{3} N_{kk\delta_{mn}} ) e_{mn} \\&= 2\mu N_{mn} e_{mn} \\&= 2\mu N \quad {_\blacksquare} \end{aligned} $$

#### 명제1.2
다음을 증명하여라.
$$ \frac{\partial H({}^{n+1}\epsilon_e^p)}{\partial \Delta \epsilon} = \sqrt{\frac{2}{3}} \frac{\partial H}{\partial \epsilon_e^p} \frac{\partial \Delta \gamma}{\partial \Delta \epsilon}  $$

**Proof**

Chain rule에 의해서 다음이 성립한다.
$$ \begin{aligned} \frac{\partial H({}^{n+1}\epsilon_e^p)}{\partial \Delta \epsilon} &= \frac{\partial H({}^{n+1}\epsilon_e^p)}{\partial ({}^{n+1}\epsilon_e^p)} \frac{\partial ({}^{n+1}\epsilon_e^p)}{\partial \Delta \gamma} \frac{\partial \Delta \gamma}{\partial \Delta \epsilon} \\&= \sqrt{\frac{2}{3}}  \frac{\partial H(\epsilon_e^p)}{\partial \epsilon_e^p} \frac{\partial \Delta \gamma}{\partial \Delta \epsilon} \quad {_\blacksquare} \end{aligned}  $$

#### 명제1.3
다음을 증명하여라.
$$ \frac{\partial K({}^{n+1}\epsilon_e^p)}{\partial \Delta \epsilon} = \sqrt{\frac{2}{3}} \frac{\partial K}{\partial \epsilon_e^p} \frac{\partial \Delta \gamma}{\partial \Delta \epsilon}  $$

**Proof**

Chain rule에 의해서 다음이 성립한다.
$$ \begin{aligned} \frac{\partial K({}^{n+1}\epsilon_e^p)}{\partial \Delta \epsilon} &= \frac{\partial K({}^{n+1}\epsilon_e^p)}{\partial ({}^{n+1}\epsilon_e^p)} \frac{\partial ({}^{n+1}\epsilon_e^p)}{\partial \Delta \gamma} \frac{\partial \Delta \gamma}{\partial \Delta \epsilon} \\&= \sqrt{\frac{2}{3}}  \frac{\partial K(\epsilon_e^p)}{\partial \epsilon_e^p} \frac{\partial \Delta \gamma}{\partial \Delta \epsilon} \quad {_\blacksquare} \end{aligned}  $$


# Discrete Plastic Consistency Requirement
선형 탄성 재료에 J2 plasticity model을 기반으로한 알고리즘을 사용한다고 하자.

Stress calculation 과정에서 plastic state일 때, yield surface에 머물러 있어야 함으로 다음이 성립해야 한다.
$$ \begin{aligned} &\frac{\partial f_{alg}}{\partial \Delta \epsilon} = 0 \\ \Rightarrow \enspace & 2\mu N - \bigg( 2\mu + H({}^{n+1}\epsilon_e^p) + \sqrt{\frac{2}{3}}\frac{\partial H}{\partial \epsilon_e^p} \Delta\gamma + \frac{2}{3} \frac{\partial K}{\partial \epsilon_e^p} \bigg) \frac{\partial \Delta \gamma}{ \partial \Delta \epsilon} = 0 \\ \Rightarrow \enspace & \frac{\partial \Delta \gamma}{ \partial \Delta \epsilon} = \frac{2\mu N}{2\mu + H({}^{n+1}\epsilon_e^p) + \sqrt{\frac{2}{3}}\frac{\partial H}{\partial \epsilon_e^p} \Delta\gamma + \frac{2}{3} \frac{\partial K}{\partial \epsilon_e^p}}  \end{aligned} $$

### 명제
선형 탄성 재료에 J2 plasticity model을 사용한다고 하자.

Plastic state일 때, 알고리즘을 통해 계산된 $\Delta \sigma$가 있다고 할 때, 다음을 증명하여라.
$$ \frac{\partial \Delta \sigma}{ \partial \Delta \epsilon} = C - \frac{4 \mu^2 N \otimes N}{2\mu + H + \sqrt{\frac{2}{3}}\frac{\partial H}{\partial \epsilon_e^p} \Delta \gamma + \frac{2}{3}\frac{\partial K}{\partial \epsilon_e^p}} - \frac{4 \mu^2 \Delta \gamma}{\lVert {}^{tr}\eta \rVert}(I_{dev} - N \otimes N)   $$

**Proof**

$$ \begin{aligned} \frac{\partial \Delta \sigma}{ \partial \Delta \epsilon} = C - 2\mu N \otimes \frac{\partial \Delta \gamma}{\partial \Delta \epsilon} - 2\mu \Delta \gamma \frac{\partial N}{\partial \Delta \epsilon} \end{aligned} $$

# Tangent Stiffness Tensor


Plastic state일 때, 알고리즘을 통해 계산된 $\Delta \sigma$는 다음과 같다.
$$ \Delta \sigma = C : \Delta \epsilon - 2 \mu \Delta\gamma N $$