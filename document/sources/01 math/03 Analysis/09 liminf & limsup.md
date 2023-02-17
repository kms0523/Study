# Limit Inferior & Superior
$\R$위의 bounded sequence $s_n$이 있다고 하자.

이 때, sequence $a_n,b_n$을 다음과 같이 정의하자.

$$ \begin{gathered} a_k := \inf(\Set{s_n | k \le n}) \\ b_k := \sup(\Set{s_n | k \le n}) \end{gathered} $$

$s_n$의 `limit inferior`과 `limit superior`은 다음과 같이 정의한다.

$$ \begin{gathered} \liminf_{n\rightarrow\infty} s_n := \lim_{n\rightarrow\infty} a_n \\ \limsup_{\ninf} s_n := \lim_{n\rightarrow\infty} b_n  \end{gathered} $$

### 참고1
정의에 의해 $a_n$은 monotone increasing bounded above sequence이고 $b_n$은 monotone decreasing bounded below sequence이다.

따라서, MCT에 의해 다음이 성립한다.

$$ \lim_{n\rightarrow\infty} a_n = \sup(a_n), \enspace \lim_{n\rightarrow\infty} b_n = \inf(b_n) $$

이런 이유로 다음과 같은 표기를 사용하기도 한다.

$$ \begin{gathered} \liminf_{\ninf} s_n = \sup_{1\le n}\inf_{n\le m} s_n \\ \limsup_{\ninf} s_n = \inf_{1\le n}\sup_{n\le m} s_n \end{gathered} $$

### 참고2
$s_n$이 convergence sequence가 아니더라도, limit inferior과 limit superior은 존재한다.

### 참고3
limit inferior은 개념적으로 inferior들 중 큰 값을 찾아가는 과정이라고 볼 수 있고, limit superior은 개념적으로 superior들 중 작은 값을 찾아가는 과정이라고 볼 수 있다.

### 명제1
$\R$위의 bounded sequence $s_n$이 있다고 하자.

이 때, 다음을 증명하여라.

$$ \liminf_{\ninf}s_n \le \limsup_{\ninf}s_n $$

**Proof**

sequence $a_n,b_n$을 다음과 같이 정의하자.

$$ \begin{gathered} a_k := \inf(\Set{s_n | k \le n}) \\ b_k := \sup(\Set{s_n | k \le n}) \end{gathered} $$

그러면 정의에 의해 다음이 성립한다.

$$ \begin{aligned} & \forall k\in \N, \enspace a_1 \le\cdots\le a_k \le b_k \le\cdots\le b_1 \\\implies& \begin{gathered} \forall k\in\N, \enspace b_k \text{ is an upper bound of } a_n \\ \forall k\in\N, \enspace a_k \text{ is an lower bound of } b_n \end{gathered} \end{aligned}$$

따라서, 다음이 성립한다.

$$ \begin{aligned} &\liminf_{\ninf} s_n = \lim_{\ninf} a_n = \sup(a_n) \\\implies& \forall k\in\N, \enspace \liminf_{\ninf}s_n \le b_k \\\implies& \liminf_{\ninf}s_n \text{ is an lower bound of } b_n \end{aligned}    $$

그럼으로 다음이 성립한다.

$$ \begin{aligned} & \limsup_{\ninf}s_n = \lim_{\ninf} b_n = \inf(b_n) \\\implies& \liminf_{\ninf}s_n \le \limsup_{\ninf}s_n \qed \end{aligned} $$


