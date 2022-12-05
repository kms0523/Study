# Von Mises Yield Criterion
항복은 분자간의 상대적인 미끄러짐에 의해 발생한다. 그리고 분자간의 상대적인 미끄러짐이 발생할 경우 부피는 변하지 않는다.

따라서 distortion strain energy density를 이용하여 failure criterion을 결정하는 방법을 `Von Mises yield criterion`이라 한다.

1D tensile test의 항복응력이 가해졌을 때, distortion strain energy density $U_d$를 $U_d|_Y$라 할 때, Von Mises yield criterion은 다음과 같다.

$$ \begin{aligned} U_d &\le U_d|_Y \\ \frac{1}{4\mu}(\tilde \sigma : \tilde \sigma) &\le \frac{1}{6\mu}\sigma_Y^2 \\ \frac{3}{2} \tilde \sigma : \tilde \sigma &\le \sigma_Y^2 \end{aligned}  $$

## Equivalent Stress
`Equivalent stress` 혹은 `Von-mises stress` $\sigma_e$를 다음과 같이 정의하자.

$$ \sigma_e := \sqrt{\frac{3}{2} \tilde \sigma : \tilde \sigma} $$

그러면 Von-mises yield criterion은 다음과 같이 간단해진다.

$$ \begin{aligned} & \frac{3}{2} \tilde \sigma : \tilde \sigma \le \sigma_Y^2 \\\implies& \sigma_e^2 \le \sigma_Y^2 \end{aligned}  $$

### 명제1
다음을 증명하여라.

$$ \sigma_e = \sqrt{6\mu^2\tilde\epsilon:\tilde\epsilon} $$

**Proof**

$\tilde\sigma$의 정의에 의해 $\tilde\sigma = 2\mu\tilde\epsilon$임으로, $\sigma_e$의 정의에 대입하면 성립함을 알 수 있다. $\qed$

## Equivalent Strain 
Equivalent strain $\epsilon_e$는 다음과 같이 정의한다.

$$ \epsilon_e := \frac{2 U_d}{\sigma_e}  $$

### 참고1
$\epsilon_e$의 정의에 의해 다음이 성립한다.

$$ U_d = \frac{1}{2}\sigma_e \epsilon_e  $$

### 명제1
다음을 증명하여라.

$$ \epsilon_e = \sqrt {\frac{1}{6\mu^2} \tilde \sigma : \tilde \sigma} $$

**Proof**

$\epsilon_e$의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} \epsilon_e &= \frac{2 U_d}{\sigma_e} \\ &= \frac{ \frac{1}{2\mu}(\tilde \sigma : \tilde \sigma)}{\sqrt{\frac{3}{2} \tilde \sigma : \tilde \sigma}} \\ &= \sqrt {\frac{1}{6\mu^2} \tilde \sigma : \tilde \sigma} \qed \end{aligned}  $$

### 명제2
다음을 증명하여라.

$$ \epsilon_e = \sqrt {\frac{2}{3} \tilde \epsilon : \tilde \epsilon} $$

**Proof**

명제1에 의해 다음이 성립한다.

$$ \begin{aligned} \epsilon_e &= \sqrt {\frac{1}{6\mu^2} \tilde \sigma : \tilde \sigma} \\ &= \sqrt {\frac{2}{3} \tilde \epsilon : \tilde \epsilon} \qed\end{aligned} $$

### 명제3
다음을 증명하여라.

$$\epsilon_e = \sqrt{\frac{4}{3}J_2(\tilde{\epsilon})} $$

**Proof**

명제2와 $\tilde{\epsilon}$의 성질에 의해 다음이 성립한다.

$$ \begin{aligned} \epsilon_e &= \sqrt{\frac{2}{3}\tilde\epsilon:\tilde\epsilon} \\&= \sqrt{\frac{4}{3}J_2(\tilde{\epsilon})} \qed\end{aligned} $$

#### 따름명제3.1
다음을 증명하여라.

$$ J_2(\tilde{\epsilon}) = \frac{3}{4}\epsilon_e^2 $$

## Yield function
Yield function은 $f$는 다음을 만족하는 함수이다.

$$ \begin{gathered} f \le 0 & \text{elastic region} \\ f > 0 & \text{plastic region} \\ f = 0 & \text{yield surface} \end{gathered} $$

### Form1
Von Mises yield criterion이 $\sigma_e^2 \le \sigma_Y^2$로 주어짐으로 yield function $f^1_{VM}$을 다음과 같이 정의하는 것이 자연스럽다.

$$ f^1_{VM}(\sigma) = \sigma_e^2 - \sigma_Y^2 $$

### Form2
Yield function $f_{VM}^2$을 다음과 같이 정의하자.

$$ f^2_{VM}(\sigma) = \sigma_e - \sigma_Y $$

$0 < \sigma_e, \sigma_Y$이기 때문에 $f_{VM}^2$도 Yield function의 정의를 만족한다.

### Form3
Yield function $f_{VM}^3$을 다음과 같이 정의하자.

$$ \begin{aligned} f^3_{VM}(\sigma) &= \sqrt{\frac{2}{3}} f^2_{VM} \\ &= \sqrt{\frac{2}{3}} (\sigma_e - \sigma_Y) \\ &= \lVert \tilde\sigma \rVert - \sqrt{\frac{2}{3}}\sigma_Y \end{aligned} $$

$f_{VM}^2$에 양수를 곱한 형태이기 때문에 $f_{VM}^3$ Yield function의 정의를 만족한다.










-