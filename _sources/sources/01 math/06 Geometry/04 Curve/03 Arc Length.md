# Arc Length
## 정의
$\R$의 open set $U$와 $U$에서 differentiable한 $r : U \rightarrow \R^n$이 있다고 하자.

$r$로 표현되는 curve를 $C$라고 했을 때, $C$의 `arc length function` $s$를 다음과 같이 정의한다.

$$ s(t) := \int^t_a \norm{r'(x)}\thinspace dx $$

이 때, $a= \inf(U)$이다.

### 참고1
$r$이 $C$를 여러번 지나갈 경우 arc length function은 $C$의 길이를 나타내지 않는다.

예를 들어 $U = (0,2\pi)$이고 $r$이 다음과 같이 주어졌다고 하자.

$$ r(t) =  (3\cos(4t),3\sin(4t)) $$

그러면 $s(\pi)$는 다음과 같다.

$$ s(\pi) = \int^\pi_0 12 \thinspace dx = 12\pi $$

하지만 실제로 $C$가 나타내는 curve는 반지름이 3인 원이고 둘레는 6$\pi$가 된다. 하지만 주어진 $U$에서 $r$이 $C$를 2번 지나감으로 arc length function이 2배의 값이 나오게 된다.

이처럼 $C$를 $r$이 여러번 지나가는 경우 arc length function의 값이 arc length가 아닐 수 있다.

### 명제1
$\R$의 open set $U$와 $U$에서 differentiable한 $r : U \rightarrow \R^n$이 있다고 하자.

$r$의 arc length function을 $s$라고 할 때, 다음을 증명하여라.

$$ \diff{s}{t} = \norm{r'(t)} $$

**Proof**

$s$의 정의와 fundamental theorem of calculus에 의해 자명하다. $\qed$

### 명제2
$\R$의 open set $U$와 $U$에서 differentiable한 $r : U \rightarrow \R^n$이 있다고 하자.

$r$의 arc length function을 $s$라고 할 때, 다음을 증명하여라.

$$ s \text{ is bijective} $$

**Proof**

$s$는 정의에 의해 monotonic increase 함수임으로 자명하다. $\qed$

### 명제3
$\R$의 open set $U,V$와 $U$에서 differentiable한 $r:U\rightarrow\R^n$과 $V$에서 differentiable한 $s:V\rightarrow\R^n$과이 있다고 하자.

동일한 curve가 $r,s$로 표현된다고 했을 때, 다음을 증명하여라.

$$ \int^t_{\inf(U)} \norm{r'(x)}\thinspace dx = \int^t_{\inf(V)} \norm{s'(y)}\thinspace dy $$

**Proof**

동일한 curve가 $r,s$로 표현됨으로 다음이 성립한다.

$$ \begin{gathered} \exist f:U\rightarrow V \st f\text{ is bijective} \\ \forall x \in U, \quad  r(x) = s(f(x)) \end{gathered} $$

$m(x) = \norm{r'(x)}, n(y) = \norm{s'(y)} $으로 두면 substitution rule에 의해 다음이 성립한다.

$$ \begin{aligned} \int^t_{\inf(V)} \norm{s'(y)}\thinspace dy &= \int^t_{\inf(V)} n(y)\thinspace dy \\&= \int^{f^{-1}(t)}_{f^{-1}(\inf(V))} n(f(x)) f'(x)\thinspace dx \\&= \int^t_{\inf(U)} \norm{r'(x)}\thinspace dx \qed \end{aligned}   $$

#### 참고
즉, $s$는 parametric independent 하다.