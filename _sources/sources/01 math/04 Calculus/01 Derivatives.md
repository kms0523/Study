# Derivatives
open set $U \subset \R$과 함수 $f : U \rightarrow \R$이 있다고 하자.

$a \in U$에서 $f$의 `미분(derivatives)`은 다음과 같이 정의된다.
$$ f'(a) := \lim_{h \rightarrow 0} \frac{1}{h}(f(a + h) - f(a)) $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.7

### 참고1
극한값이 존재하는 경우 미분가능하다고 한다.

### 참고2
$f'$은 $U$의 변화량과 그에 따른 $f$의 변화량의 비율의 극한이다.
$$ \frac{\text{change in }f}{\text{change in }U} = \frac{f(a+h)-f(a)}{h}  $$

### 참고3(Alternative Form)
위의 정의를 다차원으로 확장하기 위해 open set $U \subset \R^n$와 함수 $f : U \rightarrow \R^m$이 있다고 하자.

$a \in U$에서 $f'$은 $U$의 변화량과 그에 따른 $f$의 변화량의 비율의 극한임으로 다음과 같다.
$$ f'(a) := \lim_{h \rightarrow 0_{\R^n}} \frac{1}{h}(f(a + h) - f(a)) $$

이 떄, $h \in \R^n$임으로 vector로 나눈다는것은 정의되지 않은 연산이다.

따라서, 다차원으로의 확장을 고려하면 기존의 정의를 다른 형태로 변형해야 한다.

#### Altenative form1
다차원 확장을 고려하여 정의를 다음과 같이 변경해보자.
$$ f'(a) := \lim_{h \rightarrow 0} \frac{1}{|h|}(f(a + h) - f(a)) $$

이 경우에는 다차원으로 확장하더라도 vector의 크기로 나누기 때문에 정의되지 않은 연산은 없다. 

하지만 이 경우에는 $h \rightarrow 0$로 가면서 부호 문제가 발생하여 기존의 미분 가능하던 함수들이 미분 불가능하게 된다.

##### 예시
$f(x) = x^2$라 하자.

$f'(a)$를 계산하면 다음과 같다.
$$ f'(a) = \lim_{h \rightarrow 0} \frac{1}{|h|}(2ah + h^2) = \begin{cases} 2a & h>0 \\ -2a & h<0 \end{cases} $$

따라서, 극한값이 존재하지 않아 미분불가능해지는 문제가 발생한다.

#### Alternative form2
기존의 미분 정의로부터 다음 형태를 유도할 수 있다.
$$ \lim_{h \rightarrow 0} \frac{1}{h} \Big( f(a + h) - f(a) - f'(a)h \Big) = 0 $$

따라서, 위의 형태와 다차원으로 확장을 고려하여 다음과 같이 정의를 변경해보자.
$$ \lim_{h \rightarrow 0} \frac{1}{|h|} \Big( f(a+h)-f(a)-L(h) \Big) = 0 $$

이 때, 위의 식을 만족하는 함수 $L(h)$를 $hf'(a)$라고 정의하면 Alternative form1과 다르게 부호 문제가 발생하지 않는다.

##### 참고1
$f(a + h) - f(a)$항은 $\Delta f$를 나타내고, $L(a)h$항은 $\Delta f$를 선형근사한 값으로 볼 수 있다.

##### 참고2
위의 식이 성립하기 위해서는 $\Delta f$와 선형근사인 $L(a)h$사이의 차이가 $h \rightarrow 0$일 때, 선형보다 작아야 한다.

###### 예시
linear map $L,D$가 있다고 하자.

$L$은 $\Delta f - L(h) = c_1h, \enspace c_1 \in \R - \{ 0 \}$로 차이가 선형이라고 하면 다음과 같다.
$$ \lim_{h \rightarrow 0} \frac{1}{|h|} \Big( f(a+h)-f(a)-L(h) \Big) = \lim_{h \rightarrow 0}\frac{c_1h}{|h|} = \pm c_1 \neq 0 $$

즉, 차이가 선형인 경우 위의 식을 만족시키지 못한다.

$D$는 $\Delta f - D(h) = c_2h^2, \enspace c_2 \in \R - \{ 0 \}$로 차이가 선형보다 작다고 하면 다음과 같다.
$$ \lim_{h \rightarrow 0} \frac{1}{|h|} \Big( f(a+h)-f(a)-D(h) \Big) = \lim_{h \rightarrow 0}\frac{c_2 h^2}{|h|} = 0 $$

즉, 차이가 선형보다 작은 경우 위의 식을 만족시킨다.

# Partial Derivatives
open subset $U \subset \R^n$과 함수 $f : U \rightarrow \R$이 있다고 하자.

$\R^n$의 basis를 $\beta$라 할 떄, $a \in U$는 다음과 같이 표현된다.
$$ a = a^i\beta_i $$

$a$에서 $f$의 $i$번째 변수의 `편미분(partial derivatives)` $D_if(a)$은 다음과 같이 정의된다.
$$ \begin{aligned} D_if(a) &:= \lim_{h \rightarrow 0}\frac{f(a + h \beta_i) -f (a)}{h} \\&= \lim_{h \rightarrow 0} \frac{1}{h}(f(a^1, \cdots, a^i + h, \cdots, a^n) - f(a^1, \cdots, a^n))  \end{aligned} $$

위의 극한값이 존재할 경우 편미분은 그 극한값이 되며, 존재하지 않을 경우 편미분은 존재하지 않게 된다.

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.7

### 참고1
가장 널리 쓰이는 표기법은 다음과 같다.
$$ D_if = \frac{\partial f}{\partial x_i} $$

### 참고2
편미분은 다변수 함수를 일변수 함수처럼 보고 미분하는 방식이다. 다시 말해, 나머지 변수는 전부 상수로 간주하고 한 변수에 대해서 미분을 구하는 방식이다.

### 참고3
$D_i  f(a)$는 $a$에서 $e_i$방향으로 움직일 때, $f$가 어떻게 변하는지를 나타낸다.

# Partial Derivatives of Vector-valued Function
open subset $U \subset \R^n$과 함수 $f^i:U \rightarrow \R \enspace i=1,\cdots,m$이 있다고 하자.

$\R^m$의 basis를 $\gamma$라 할 떄, $f : U \rightarrow \R^m$는 다음과 같이 표현된다.
$$ f = f^i\gamma_i $$

또한, $\R^n$의 basis를 $\beta$라 할 떄, $a \in U$는 다음과 같이 표현된다.
$$ a = a^i\beta_i $$

$a \in U$에서 $f$의 $i$번째 변수의 편미분은 다음과 같다.
$$ \begin{aligned} D_i f(a) &:= \lim_{h \rightarrow 0}\frac{1}{h}(f(a + h \beta_i) -f (a)) \\&=\lim_{h \rightarrow 0} \frac{1}{h}(f(a^1, \cdots, a^i + h, \cdots, a^n) - f(a^1, \cdots, a^n)) \\&= \Big( \lim_{h \rightarrow 0} \frac{1}{h} (f^j(a^1, \cdots, a^i + h, \cdots, a^n) - f^j(a^1, \cdots, a^n)) \Big)\gamma_j \\&= D_if^j\gamma_j \end{aligned} $$ 

따라서, 행렬표현은 다음과 같다.
$$ \frak{m_\gamma}(D_if(a)) = \begin{bmatrix} D_if^1(a)\\\vdots\\D_if^m(a) \end{bmatrix} $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.7

# Total Derivative
open subset $U \subset \R^n$과 함수 $f : U \rightarrow \R^m$이 있다고 하자.

$a \in U$와 linear map $L: \R^n \rightarrow \R^m $이 있다고 하자.

$L$이 다음을 만족할 경우, $L$을 $a$에서 $f$의  `total derivative`라고 한다.
$$ \lim_{h \rightarrow 0_n} \frac{1}{|h|}(f(a + h) - f(a) - L(h)) = 0_n $$

이런 $L$이 존재하는 경우, $f$가 $a$에서 `미분가능(differentiable)`하다고 한다.

### 명제1
open subset $U \subset \R^n$과 함수 $f : U \rightarrow \R^m$이 있다고 하자.

$\R^n$과 $\R^m$의 basis가 각 각 $\beta,\gamma$이고 $a \in U$에서 $f$가 미분가능할 때, 다음을 증명하여라.
$$ \frak{m}_\beta^\gamma(L) = \begin{bmatrix} D_1f^1(a) & \cdots & D_nf^1(a) \\ \vdots & & \vdots \\ D_1f^m(a) & \cdots & D_nf^m(a) \end{bmatrix}$$

**Proof**

$h = t\beta_i$라 하면 정의에 의해 다음이 성립한다.
$$ \begin{aligned} & \lim_{t \rightarrow 0} \frac{1}{\norm{t \beta_i}}(f(a+t\beta_i) - f(a) - L(t\beta_i)) = 0 \\\implies & \lim_{t\rightarrow 0} \frac{1}{t}(f(a + t \beta_i) - f(a)) -L(\beta_i) = 0 \\\implies & D_i f(a) = L(\beta_i) \end{aligned} $$

행렬표현은 다음과 같다.
$$ \frak{m_\gamma}(L(\beta_i)) = \frak{m_\gamma}(D_if(a)) = \begin{bmatrix} D_if_1(a) \\ \vdots \\ D_if_m(a) \end{bmatrix} $$

$L$이 linear map임으로, 다음이 성립한다.
$$ \frak{m}_\beta^\gamma(L) = \begin{bmatrix} \frak{m}_\gamma(L(\beta_1)) & \cdots & \frak{m}_\gamma(L(\beta_n)) \end{bmatrix} = \begin{bmatrix} D_1f_1(a) & \cdots & D_nf_1(a) \\ \vdots & & \vdots \\ D_1f_m(a) & \cdots & D_nf_m(a) \end{bmatrix} \qed $$

#### 참고1
선형변환 $L$의 행렬표현을 $f$의 `Jacobian matrix`라고 부르며 $J_f$로 표기한다.
$$ \frak{m}_\beta^\gamma(L) =J_f(a) = \begin{bmatrix} D_1f_1( a) & \cdots & D_nf_1( a) \\ \vdots & & \vdots \\ D_1f_m( a) & \cdots & D_nf_m( a) \end{bmatrix}$$

#### 참고2
$\frak{m}_\beta^\gamma(L) =J_f(a)$이려면 $f$가 differtiable해야 한다.

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
$$ \frak{m_\beta^\beta}(L_f) = \frak{m_\gamma^\gamma}(L_g) $$

$f$의 정의에 의해 $a = a^{ij}\gamma_{ij} \in \R^{nn}$가 있을 떄, $g(v)$는 다음과 같다.
$$ g(v) = a^{ik}a^{kj}\gamma_{ij} $$

따라서, 다음이 성립한다.
$$ \frak{m_\gamma^\gamma}(L_g) = J_g(a) = \begin{bmatrix} D_{11}g^{11}( a) & \cdots & D_{nn}g^{11}(a) \\ \vdots & & \vdots \\ D_{11}g^{nn}( a) & \cdots & D_{nn}g^{nn}( a) \end{bmatrix} $$

$$ \text{Where, }D_{ij}g^{kl}(a) = \frac{\partial a^{kr}a^{rl}}{\partial a^{ij}} $$

그럼으로 $\frak{m_\beta^\beta}(L_f)$를 알고 있기 때문에 $L_f$에 대해 알 수 있다.

예를 들어 $m \in M_{nn}$에 대해서, $L_f(m)$은 다음과 같다.
$$ \begin{aligned} L_f(m) &= \varphi^{-1}(\frak{m_\beta}(L_f(m))) \\&= \varphi^{-1}(\frak{m_\beta^\beta}(L_f)\frak{m_\beta}(m)) \end{aligned} $$

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

# Directional Derivative
open subset $U \subset \R^n$과 함수 $f:U \rightarrow \R^m$이 있다고 하자.

$f$의 `directional derivative`는 다음과 같이 정의된 함수이다.
$$ Df : U \times \R^n \rightarrow \R^m \st (a,v) \mapsto \lim_{h \rightarrow 0}\frac{ f(a + h v) - f (a)}{h} $$

### 참고1(notation)
$Df(a,v)$는 $D_vf(a)$와 같이 표기하는 것이 일반적이다.

### 참고2
$D_vf(a)$는 $a$에서 $v$방향으로 변화량과 그에 따른 $f$의 변화량의 비율의 극한을 의미한다.

### 명제
open set $U \subset \R^n$과 함수 $f : U \rightarrow \R^m$이 있다고 하자.

$\R^m$의 basis를 $\beta$하고 $\forall a \in U$에서 $f$가 differentiable일 때, 다음을 증명하여라.
$$ Df\text{ is well-defined} \enspace\land\enspace \frak{m_\beta}(D_vf(a)) = \frak{m_\beta}(J_f(a)v) $$

**Proof**

$f$가 differentiable 함으로 다음이 성립한다.
$$ \begin{aligned} & \lim_{h \rightarrow 0}\frac{f(a + hv) -f (a) - L_a(hv)}{\norm{hv}} = 0 \\\implies& \lim_{h \rightarrow 0}\frac{f(a + hv) -f (a) - hL_a(v)}{h\norm{v}} = 0 \\\implies& \lim_{h \rightarrow 0}\frac{f(a + hv) -f (a) - hL_a(v)}{h} = 0 \\\implies& \lim_{h \rightarrow 0}\frac{f(a + hv) -f (a)}{h} = L_a(v) \end{aligned} $$

이 떄, $f$가 $a$에서 differentiable 함으로, 선형변환 $L_a$은 잘 정의된다. 

따라서, 극한값이 $L_a(v)$로 존재함으로, 함수 $Df$는 잘 정의된다.

또한, $D_vf(a) = L_a(v)$이고 Jacobian matrix의 정의에 따라 $L_a(v) = J_f(a)v$



> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach Proposition 1.7.14.

