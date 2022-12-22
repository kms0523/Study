# Governing Equation

## Momentum Equations
연속체 $\Omega$가 있다고 하자.

$\Omega$에 Euler의 운동방정식과 Euler-Cauchy stress principle을 적용하면 다음과 같다.

$$ \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho f_b \thinspace dV = \frac{d}{dt} \int_\Omega \rho u \thinspace dV $$

이를 `적분형(integral form)` 운동방정식이라 한다.

### Equilibrium State
$\Omega$가 정적 평형 상태에 있을 때, 적분형 운동방정식은 다음과 같다.

$$ \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho  f_b \thinspace dV = 0 $$

### 명제1(Differential form)
연속체 $\Omega$가 있다고 하자.

$\rho u, \sigma$가 충분히 매끄럽다고 할 때, 다음을 증명하여라.

$$ \begin{aligned} & \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho f_b \thinspace dV = \frac{d}{dt} \int_\Omega \rho u \thinspace dV \\ \iff \enspace & \mathrm{div}(\boldsymbol\sigma) + \rho  f_b = \frac{\partial}{\partial t}(\rho  u) + \mathrm{div}(\rho  u \otimes u) \end{aligned}  $$

**Proof**

$\rho u$가 충분히 매끄러움으로, Integral form $\frac{d}{dt} \int_\Omega \rho u \thinspace dV$에 Leibniz integral theorem을 적용하면 다음과 같다.

$$ \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho  f_b \thinspace dV = \int_\Omega \frac{\partial}{\partial t} (\rho u) + \text{div}(\rho u \otimes u) \thinspace dV $$

이 때, $\sigma$도 충분히 매끄러움으로 $\int_{\partial\Omega} \sigma n \thinspace dS$에 divergence theorem을 적용하면 다음과 같다.

$$ \int_{\Omega} \text{div} (\sigma) +\rho  f_b \thinspace dV = \int_\Omega \frac{\partial}{\partial t} (\rho u) + \text{div}(\rho u \otimes u) \thinspace dV $$

위 식은 임의의 $\Omega$에서 성립해야 함으로 다음이 성립한다.

$$ \mathrm{div}(\boldsymbol\sigma) + \rho  f_b = \frac{\partial}{\partial t}(\rho  u) + \mathrm{div}(\rho  u \otimes u) $$

따라서, 위 식은 적분형 운동방정식과 동일하며 이를 미분형 운동방정식이라 한다.$\qed$

#### 따름명제1.1
연속체 $\Omega$가 정적 평형상태에 있다고 하자.

$\rho u, \sigma$가 충분히 매끄럽다고 할 때, 다음을 증명하여라.

$$ \begin{aligned} & \int_{\partial\Omega} \sigma n \thinspace dS + \int_\Omega \rho f_b \thinspace dV = 0 \\ \iff \enspace & \mathrm{div}(\boldsymbol\sigma) + \rho  f_b = 0 \end{aligned}  $$

**Proof**

명제1과 동일한 방법으로 증명할 수 있다. $\qed$


