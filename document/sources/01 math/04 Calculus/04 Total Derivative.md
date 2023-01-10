# Total Derivative
## 정의
open subset $U \subset \R^n$과 함수 $f : U \rightarrow \R^m$이 있다고 하자.

$a \in U$와 linear map $L: \R^n \rightarrow \R^m $이 있다고 하자.

$L$이 다음을 만족할 경우, $L$을 $a$에서 $f$의  `total derivative`라고 한다.

$$ \lim_{h \rightarrow 0_n} \frac{1}{|h|}(f(a + h) - f(a) - L(h)) = 0_n $$

이런 $L$이 존재하는 경우, $f$가 $a$에서 `미분가능(differentiable)`하다고 한다.

### 명제1
open subset $U \subset \R^n$과 함수 $f : U \rightarrow \R^m$이 있다고 하자.

$\R^n$과 $\R^m$의 basis가 각 각 $\beta,\gamma$이고 $a \in U$에서 $f$가 미분가능할 때, 다음을 증명하여라.

$$ \mathfrak{m}_\beta^\gamma(L) = \begin{bmatrix} D_1f^1(a) & \cdots & D_nf^1(a) \\ \vdots & & \vdots \\ D_1f^m(a) & \cdots & D_nf^m(a) \end{bmatrix}$$

**Proof**

$h = t\beta_i$라 하면 정의에 의해 다음이 성립한다.

$$ \begin{aligned} & \lim_{t \rightarrow 0} \frac{1}{\norm{t \beta_i}}(f(a+t\beta_i) - f(a) - L(t\beta_i)) = 0 \\\implies & \lim_{t\rightarrow 0} \frac{1}{t}(f(a + t \beta_i) - f(a)) -L(\beta_i) = 0 \\\implies & D_i f(a) = L(\beta_i) \end{aligned} $$

행렬표현은 다음과 같다.

$$ \mathfrak{m_\gamma}(L(\beta_i)) = \mathfrak{m_\gamma}(D_if(a)) = \begin{bmatrix} D_if_1(a) \\ \vdots \\ D_if_m(a) \end{bmatrix} $$

$L$이 linear map임으로, 다음이 성립한다.

$$ \mathfrak{m}_\beta^\gamma(L) = \begin{bmatrix} \mathfrak{m}_\gamma(L(\beta_1)) & \cdots & \mathfrak{m}_\gamma(L(\beta_n)) \end{bmatrix} = \begin{bmatrix} D_1f_1(a) & \cdots & D_nf_1(a) \\ \vdots & & \vdots \\ D_1f_m(a) & \cdots & D_nf_m(a) \end{bmatrix} \qed $$

#### 참고1
선형변환 $L$의 행렬표현을 $f$의 `Jacobian matrix`라고 부르며 $J_f$로 표기한다.

$$ \mathfrak{m}_\beta^\gamma(L) =J_f(a) = \begin{bmatrix} D_1f_1( a) & \cdots & D_nf_1( a) \\ \vdots & & \vdots \\ D_1f_m( a) & \cdots & D_nf_m( a) \end{bmatrix}$$

#### 참고2
$\mathfrak{m}_\beta^\gamma(L) =J_f(a)$이려면 $f$가 differtiable해야 한다.

### 참고
Total derivative의 의미는 $a\in\R^n$에서 함수 $f: \R^n \rightarrow \R^m$에 대한 best linear approximation이다.

따라서 위 정의는 $f$의 domain과 codomain이 Euclidean vector space일때 만 성립하는 것이 아니라, 임의의 vector space에 대해서도 성립한다.

$f$의 total erivative를 계산하는데 있어서, 정의를 사용하는것보다 $J_f$를 사용하는 것이 더 간단한 경우가 많다. 

하지만 domain과 codomain이 Euclidean vector space가 아닌 vector space인 경우에는 vector space isomorphism을 이용하여 Euclidean vector space에서 Jacobian matrix를 구하는 형태로 계산을 해야 되는데, 이 방법이 최선의 선택이 아닌 경우도 있다.

#### 예시
함수 $f$가 다음과 같이 정의되었다고 하자.

$$f : M_{nn} \rightarrow M_{nn} \st A \mapsto A^2 $$

##### $J_f$를 사용하는 경우
$M_{nn}$과 $\R^{nn}$은 다음 관계에 의해 vector space isomorphic이다.

$$ \begin{CD} M_{nn} @>f>> M_{nn} \\ @V{\varphi}VV @VV{\varphi}V \\ \mathbb \R^{nn} @>>g> \mathbb \R^{nn}  \end{CD} $$

$f,g$의 total derivative를 각 각 $L_f,L_g$라하고 $M_{nn}$과 $\R^{nn}$의 basis를 각 각 $\beta, \gamma$라 할 때, $\varphi$의 성질에 의해 다음이 성립한다.

$$ \mathfrak{m_\beta^\beta}(L_f) = \mathfrak{m_\gamma^\gamma}(L_g) $$

$f$의 정의에 의해 $a = a^{ij}\gamma_{ij} \in \R^{nn}$가 있을 떄, $g(v)$는 다음과 같다.

$$ g(v) = a^{ik}a^{kj}\gamma_{ij} $$

따라서, 다음이 성립한다.

$$ \mathfrak{m_\gamma^\gamma}(L_g) = J_g(a) = \begin{bmatrix} D_{11}g^{11}( a) & \cdots & D_{nn}g^{11}(a) \\ \vdots & & \vdots \\ D_{11}g^{nn}( a) & \cdots & D_{nn}g^{nn}( a) \end{bmatrix} $$


$$ \text{Where, }D_{ij}g^{kl}(a) = \frac{\partial a^{kr}a^{rl}}{\partial a^{ij}} $$

그럼으로 $\mathfrak{m_\beta^\beta}(L_f)$를 알고 있기 때문에 $L_f$에 대해 알 수 있다.

예를 들어 $m \in M_{nn}$에 대해서, $L_f(m)$은 다음과 같다.

$$ \begin{aligned} L_f(m) &= \varphi^{-1}(\mathfrak{m_\beta}(L_f(m))) \\&= \varphi^{-1}(\mathfrak{m_\beta^\beta}(L_f)\mathfrak{m_\beta}(m)) \end{aligned} $$

##### 정의를 사용하는 경우
Total derivative의 정의를 통해 $L_f$을 구해보자.

$$ \begin{aligned} & \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{\norm{H}}(f(A + H) - f(A) - \mathit L_f(H)) = 0_{M_{nn}} \\ \implies & \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{\norm{H}}(AH + HA + H^2 - \mathit L_f(H)) = 0_{M_{nn}} \end{aligned} $$

$f$가 $A$에서 미분가능하기 위해서는 위의 식이 만족되어야 함으로 $\norm{H}$로 나눠주면 $0_{M_{nn}}$이 되지 않는 선형 항들을 제거하기 위해 linear map $L_f$를 다음과 같이 정의하자.

$$ L_f : M_{nn} \rightarrow M_{nn} \st H \mapsto AH + HA $$

위와 같이 정의한 $L_f$에 의해 다음이 만족된다.

$$ \begin{aligned} \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{\norm{H}}(AH + HA + H^2 - \mathit L(H)) &= \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{\norm{H}}H^2 \\&\le \lim_{H \rightarrow 0_{M_{nn}}} \frac{1}{\norm{H}}\norm{H}\norm{H} \\ &= 0_{M_{nn}} \end{aligned} $$

따라서, $f$의 total derivative는 $L_f(A)$이다.

##### 결론
두 경우를 비교해보면 알 수 있듯이, 정의를 사용하는 경우가 훨씬 간단할수도 있다.

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach p.132