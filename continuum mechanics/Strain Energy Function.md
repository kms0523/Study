# Strain Energy Function
infinitesimal strain $\epsilon$이 있다고 하자.

다음과 같이 정의된 함수 $U$를 `strain energy density function`라고 한다.
$$ U := \frac{1}{2}C^{ijkl}\epsilon_{ij}\epsilon_{kl} $$

### 명제1
strain energy density function $W$와 infinitesimal strain $\epsilon$가 있다고 하자.

다음을 증명하여라.
$$ \sigma_{ij} = \frac{\partial U}{\partial \epsilon_{ij}} $$

**Proof**

$U$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{\partial U}{\partial \epsilon_{ij}} &= \frac{1}{2} C^{ijkl} \frac{\partial}{\partial \epsilon_{ij}} (\epsilon_{ij}\epsilon_{kl}) \\&= \frac{1}{2} C^{ijkl} \bigg( \epsilon_{kl} \frac{\partial \epsilon_{ij}}{\partial \epsilon_{ij}} + \epsilon_{ij} \frac{\partial \epsilon_{kl}}{\partial \epsilon_{ij}} \bigg) \\&= \frac{1}{2} C^{ijkl} ( \epsilon_{kl} + \epsilon_{ij} \delta_{ki}\delta_{lj} ) \\&= C^{ijkl} \epsilon_{kl} \\&= \sigma_{ij} \end{aligned} $$

응력에 의한 일률 $P_s$가 내부 변형률 에너지 함수 $U$의 시간에 대한 변화량과 같다고 하자.
$$ P_s = \frac{dU}{dt} $$

이 때, $P_s = \sigma_{ij}D_{ij}$임으로 다음 관계식이 만족한다.(Ex 5.2.1.)
$$ \begin{equation} \sigma_{ij} = \frac{\partial U}{\partial \epsilon_{ij}} \end{equation}  $$

구성 방정식을 대입하면 다음과 같다.
$$ C_{ijkl}\epsilon_{kl} = \frac{\partial U}{\partial \epsilon_{ij}} $$