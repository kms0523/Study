# 함수의 극한
subset $X \subset \R^n$와 함수 $\mathbf f : X \rightarrow \R^m$가 있다고 하자.

$\mathbf x_0 \in \overline X$가 있을 때, $\mathbf x \in X$가 $\mathbf x_0$로 갈 때, $f(\mathbf x)$의 극한값이 $\mathbf L$이라는 말은 다음과 동치이다.
$$ \forall \epsilon > 0, \quad \exist  \delta \quad s.t. \quad 0 < |\mathbf x - \mathbf x_0| < \delta \Rightarrow |\mathbf f(\mathbf x_0) - \mathbf L| < \epsilon. $$

이를 간단하게 표현하면 다음과 같다.
$$\lim_{\mathbf x \rightarrow \mathbf x_0} \mathbf f(\mathbf x) = \mathbf L$$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach Chapter 1.5

### 참고1
$\mathbf x$는 $\mathbf x_0$와 항상 $\delta$만큼 떨어져 있기 때문에 극한을 정의하는데 있어 함수 $\bf f(x)$는 $\mathbf x = \mathbf x_0$에서 반드시 정의되어 있을 필요는 없다.

> Reference  
> [Book] (J. Stewart) Calculus 1.7   

### 참고2
함수의 극한이값이 $L$이기 위해서는 $0 < |\mathbf x - \mathbf x_0| < \delta$을 만족하는 모든 $\mathbf x$에 대해서 $|\mathbf f(\mathbf x_0) - \mathbf L| < \epsilon$을 만족해야 된다.

$0 < |\mathbf x - \mathbf x_0| < \delta$을 만족하는 특정 $\mathbf x$에 대해 $|\mathbf f'(\mathbf x_0) - \mathbf L'| < \epsilon$을 만족하는 $\mathbf L'$은 극한값이 될 수 없다.

#### 예시
$f(x) = \sin \frac{1}{x}$이 있다고 하자.

$x_n = \frac{1}{(2n + 0.5)\pi}, \enspace x_m = \frac{1}{(2m - 0.5)\pi}$로 두면, $x_n,x_m$ 모두 0에 얼마든지 가깝게 갈 수 있으나 $f(x_n) = 0.5, \enspace f(x_m) = -0.5$이다. 

따라서 $f(x)$의 경우에는 극한값이 존재하지 않게 된다.

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach Chapter 1.5


### 참고3
극한의 정의가 갖는 의미를 이해하기 위해 구체적인 예시를 살펴보자. 

먼저 함수 $f(x)$가 다음과 같이 정의되어 있다고 하자.
$$ f(x) = \begin{cases} 2x-1 & \text{if} \quad x \neq 3 \\ 6 & \text{if} \quad x = 3 \end{cases} $$

함수의 정의로부터 $x \neq 3$일 때, $x$가 $3$으로 다가갈수록 $f(x)$가 5에 가까워진다는 것을 직관적으로 알 수 있다. 하지만 "다가간다"는 표현과 "가까워진다"는 표현이 명확하지 않아 "다가간다는것은 무엇인가?", "$x$가 $3$에 얼마나 다가가야 하는가?", "가까워진다는것은 무엇인가?", "$f(x)$가 $5$에 얼마나 가까워지는가?"에 대한 질문에 대답을 하기가 어렵다. 따라서 모호한 표현을 명확하게 하기 위해 다음과 같은 질문을 해보자.

"$x$와 3의 거리가 얼마 이하여야 $f(x)$와 5의 거리가 $\epsilon$이하가 되는가?"

여기서는 "다가간다", "가까워진다"라는 표현대신 거리라는 표현을 사용하였고 이를 통해 위의 질문을 수학적으로 표현할 수 있으며 위의 질문은 다음과 같은 수학 문제가 된다.

$$ \text{find } \delta \enspace \text{satisfying} \quad 0 < |x-3| < \delta \Rightarrow |f(x) - 5| < \epsilon $$

위 문제의 해가 존재한다면 $x$가 $(3-\delta, 3+\delta)$구간에 들어갈정도로 3에 충분히 가까이 가면 $f(x)$와 5의 오차가 $\epsilon$보다 작아진다는 의미를 갖는다. 즉, "$x$가 $3$에 얼마나 다가가야 하는가?"에 대한 대답이 $\delta$가 되고 "$f(x)$가 $5$에 얼마나 가까워지는가?"에 대한 대답이 $\epsilon$이 된다.  이를 그림으로 표현하면 다음과 같다.

<p align = "center">
<img src = "./image/Limit1.png" height = 300>
</p>

만약 임의의 양수 $\epsilon$에 대해서 위 문제에 해가 존재한다면, $x$가 3에 충분히 가까이만 간다면 $f(x)$는 얼마든지 5에 가까워 질 수 있다는 의미를 갖게되고 이러한 논의를 통해 $x$가 $3$으로 갈 때 $f(x)$의 극한값이 $5$라는 말은 다음과 같이 표현할 수 있다.
$$ \forall \epsilon > 0, \quad \exist \delta \enspace \text{satisfying} \quad 0 < |x-3| < \delta \Rightarrow |f(x) - 5| < \epsilon $$

다음은 실제로 $\delta$가 존재하는지를 확인해보자. $|f(x) - 5| = 2|x -3|$임으로, $|x-3| < 0.5\epsilon$면 $|f(x) - 5| < \epsilon$임을 알 수 있다. 따라서 $\delta$는 $0.5 \epsilon$보다 작은 임의의 양수면 되고 이로써 $\delta$는 존재함을 알 수 있다. $\delta$의 존재성을 보였음으로 $x$가 $3$으로 갈 때 $f(x)$의 극한값은 $5$다.

> Reference  
> [Book] (J. Stewart) Calculus 1.7   