# Function Approximation
함수 $\phi : \R^n \rightarrow \R^m$와 $\phi$의 component functions $\phi^i, \enspace i=1,\cdots,m$가 있다고 하자.

$$ \phi^i : \R^n \rightarrow \R, \enspace i=1,\cdots,m $$

이 떄, 서로 다른 $k$개의 점 $x_1, \cdots x_k \in \R^n$에서 $\phi$의 값을 알고 있을 때, $\phi$의 approximate function $\phi_h$를 구해보자.

## $C^0$ Approximation

$\phi_h$는 $\phi$의 approximate function임으로 approximation의 기준을 정해야 되는데, 이 때 한가지 타당한 기준은 다음과 같다.

$$ \phi(x_i) = \phi_h(x_i), \enspace i=1,\cdots,k $$

즉, 값이 주어진 점들에서 approximate function이 원래 function과 정확히 일치하는 것을 approximation의 기준으로 삼는것이다.

이제, 기준이 결정되었으니 기준을 만족하는 $\phi_h$를 찾아보자.

### Search
집합 $V$를 다음과 같이 정의하자.

$$ V := \Set{f :\R^d \rightarrow \R} $$

Vector space의 정의에 의해, $V/\R$은 vector space이다.

이 떄, infinite dimension vector space $V$를 탐색할 수 없음으로 탐색할 $V$의 finite subspace $\mathcal{M}$을 결정하자.

$\mathcal{M}$의 basis가 될 $l$개의 linearly independent한 function들을 다음과 같이 정의하자.

$$ m_i : \R^n \rightarrow \R, \enspace i=1,\cdots,l $$

그러면, $m_i$는 $\mathcal{M}$의 basis임으로 다음이 성립한다.

$$ \mathcal{M} = \span(\Set{m_i}) $$

그리고 $\phi_h$의 각각의 component function $\phi_h^i$에 대해 다음을 가정하자.

$$ \exist \phi_h^i \in \mathcal{M} \st \phi^i(x_j) = \phi_h^i(x_j), \enspace i=1,\cdots,m, \enspace j=1,\cdots,k $$

$\phi_h \in \mathcal{M}$임으로 다음이 성립한다.

$$ \exist a_i^1, \cdots, a_i^l \in \R \st \phi_h^i = a_i^jm_j, \enspace i=1,\cdots,m $$

이 때, $\phi_h$는 $\phi(x_i) = \phi_h(x_i), \enspace i=1,\cdots,k$ 조건을 만족함으로 이를 matrix form으로 쓰면 다음과 같다.

$$ \begin{gathered} \begin{bmatrix} a_1^1 &\cdots& a_1^l \\ \vdots \\ a_m^1 &\cdots& a_m^l \end{bmatrix} \begin{bmatrix} m_1(x_1) &\cdots& m_1(x_k) \\ \vdots && \vdots \\ m_l(x_1) &\cdots& m_l(x_k) \end{bmatrix}  = \begin{bmatrix} \phi^1(x_1) &\cdots& \phi^1(x_k) \\ \vdots \\ \phi^m(x_1) &\cdots& \phi^m(x_k) \end{bmatrix} \\ AM =\Phi \end{gathered}  $$

만약 $M$이 invertible matrix면 다음이 성립한다.

$$ \begin{gathered} A = \Phi M^{-1} \\ l=k \end{gathered}  $$

#### 명제1
다음을 증명하여라.

$$ f \in \mathcal{M} \iff f = f_h $$

**Proof**

[$\implies$]  
$f_h = a^im_i$라고 하고 $\hat{f} := \begin{bmatrix} f(x_1) &\cdots& f(x_k) \end{bmatrix}$라고 하면 다음이 성립한다.

$$ a = \hat{f}M^{-1} $$

$f \in \mathcal{M}$임으로 다음이 성립한다.

$$ f = b^im_i $$

$b := \begin{bmatrix} b^1 &\cdots& b^k \end{bmatrix}$라고 할 때, $f(x_i) \enspace i=1,\cdots,k$를 matrix form으로 쓰면 다음과 같다.

$$ bM = \begin{bmatrix} f(x_1) &\cdots& f(x_k) \end{bmatrix} $$

$M$이 invertible matrix이면 다음이 성립한다.

$$ b = \hat{f} M^{-1} = a $$

따라서, 다음이 성립한다.

$$ f = f_h \qed $$

[$\impliedby$]  
자명하다.$\qed$

### Shape Function
계산의 편의성을 위해 행렬 $m$을 다음과 같이 정의하자.

$$ m := \begin{bmatrix} m_1(x) \\ \vdots \\ m_k(x)  \end{bmatrix} $$  

그러면 다음이 성립한다.

$$ \begin{aligned} \phi_h &= Am \\&= \Phi M^{-1} m \end{aligned} $$

이 때, 행렬 $n$을 다음과 같이 정의하자.

$$ n := M^{-1}m $$

그러면 다음이 성립한다.

$$ \begin{aligned} \phi_h &= \Phi n \\&= \phi(x_i)n_i \end{aligned} $$

이 때, $n_i, \enspace i=1,\cdots,k$을 `shape function`이라고 한다.

#### 명제1
Shape function $n_i, \enspace i=1,\cdots,n$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ \Set{n_i} \text{ is an linearly independent set} $$

**Proof**

다음을 만족하는 $c_i, i=1,\cdots, n$을 찾아보자.

$$ c_in_i = 0_V $$

Shape function의 정의에 의해 다음이 성립한다.

$$ c_i((M^{-1})_{ji}m_j ) = 0_V  $$

이 떄, $c'_i, \enspace i=1,\cdots,n$을 다음과 같이 정의하자.

$$ c'_i := c_j(M^{-1})ij $$

그러면 다음이 성립한다.

$$ c_i'm_i = 0 $$

$\Set{m_i}$는 linearly independet set임으로 다음이 성립한다.

$$ c_i' = 0, \enspace i=1,\cdots,n $$

이를 행렬식으로 나타내면 다음과 같다.

$$ \begin{bmatrix} M^{-1}_{11} & \cdots & M^{-1}_{1n} \\ \vdots && \vdots \\ M_{n1}^{-1} &\cdots&  M_{nn}^{-1} \end{bmatrix} \begin{bmatrix} c_1 \\ \vdots \\ c_n \end{bmatrix} = 0_n $$

따라서, $c := \begin{bmatrix} c_1 & \cdots& c_n \end{bmatrix}^T$일 떄, 다음이 성립한다.

$$ \begin{aligned} M^{-1}c &= 0_n \\ c &= 0_n \\ c_i &= 0, \enspace i=1,\cdots,n \end{aligned}  $$

따라서, linearly independent set의 정의에 의해 다음이 성립한다.

$$ \Set{n_i} \text{ is an linearly independent set} \qed $$

#### 명제2
Shape function $n_i, \enspace i=1,\cdots,n$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ n_i(x_j) = \delta_{ij}, \enspace i,j=1,\cdots,n $$

**Proof**

임의의 $i \in [1,n]$가 있을 때, 다음을 가정하자.

$$ \phi = n_i $$

$\phi \in \mathcal{M}$임으로, $\phi = \phi_h$이다.

그러면, 다음이 성립한다.

$$ \begin{aligned} \phi &= \phi(x_j)n_j \\ n_i &= n_i(x_j)n_j \end{aligned} $$

이 떄, $c_j$를 다음과 같이 정의하자.

$$ c_j = \begin{cases} n_i(x_j) & j \neq i \\ n_i(x_j) - 1 & j = i \end{cases} $$

그러면 다음이 성립한다.

$$ c_jn_j = 0_V $$

이 때, 명제1에 의해 $\Set{n_j}$는 linearly independent set임으로 다음이 성립한다.

$$ c_j = 0, \enspace j=1,\cdots,n $$

따라서, $c_j$의 정의에 의해 다음이 성립한다

$$ n_i(x_j) = \delta_{ij} \qed $$

> Reference  
> [blog1](http://what-when-how.com/the-finite-element-method/fundamentals-for-finite-element-method-part-1/)  
> [blog2](http://what-when-how.com/the-finite-element-method/fundamentals-for-finite-element-method-part-2/)  

#### 참고
$\phi_h = \Phi n$에서 $\Phi$를 벡터 형태로 쓰면 다음과 같은 형태를 갖는다.

$$ \phi_h = \begin{bmatrix} n_1 \enspace \underbrace{0 \cdots 0}_{m-1}  && n_2 \enspace \underbrace{0 \cdots 0}_{m-1} && \cdots && n_n \enspace \underbrace{0 \cdots 0}_{m-1} \\ 0 \enspace n_1 \enspace \underbrace{0 \cdots 0}_{m-2} && 0 \enspace n_2 \enspace \underbrace{0 \cdots 0}_{m-2} && \cdots && 0 \enspace n_n \enspace \underbrace{0 \cdots 0}_{m-2} \\ && \qquad  \vdots \\ \underbrace{0 \cdots 0}_{m-1} \enspace  n_1 && \underbrace{0 \cdots 0}_{m-1} \enspace n_2 && \cdots && \underbrace{0 \cdots 0}_{m-1} \enspace n_n \end{bmatrix} \begin{bmatrix} \phi^1(x_1) \\\vdots\\ \phi^m(x_1) \\\vdots\\ \phi^1(x_k) \\\vdots\\ \phi^m(x_k) \end{bmatrix} $$

$$ \phi_h = N {\hat\phi} $$


# Interpolation


## $C^1$ 보간
### $\phi : \R \rightarrow \R$
함수 $\phi : \R \rightarrow \R$를 $2n$개의 `단항식(monomial)`을 갖는 `다항식(polynomial)`으로 근사하면 다음과 같이 표현할 수 있다.

$$ \phi(x) \approx \mathbf a \cdot \mathbf m(x) $$

이 떄, 서로 다른 $n$개의 $x_i$에서 $\phi(x_i), \phi'(x_i)$값을 알고 있다면 $\phi(x_i) = \mathbf a \cdot \mathbf m(x_i)$와 $\phi'(x_i) = \mathbf a \cdot \mathbf m'(x_i)$를 만족하도록 $\mathbf a$를 결정할 수 있다.

위의 조건을 행렬 형태로 나타내면 다음과 같다.

$$ \boldsymbol{\hat{\phi}} = \mathbf M^T \mathbf a \\ \text{where,} \quad \mathbf M =  \begin{bmatrix} \mathbf m(x_1) & \mathbf m'(x_1) & \cdots & \mathbf m(x_n) & \mathbf m'(x_n) \end{bmatrix}, \quad \boldsymbol{\hat{\phi}} = \begin{bmatrix} \phi(x_1) \\ \phi'(x_1) \\ \vdots \\ \phi(x_n) \\ \phi'(x_n) \end{bmatrix} $$

따라서 $\bf a = (M^T)^{-1} \boldsymbol{\hat{\phi}}$이고 이를 원래 식에 대입하면 다음과 같다. 

$$ \begin{aligned} \phi &= \mathbf {a \cdot m} \\ &= \mathbf {m \cdot a} \\ &= \mathbf m^T (\mathbf M^T)^{-1} \boldsymbol{\hat{\phi}} \\ &= \mathbf n \cdot \boldsymbol{\hat{\phi}} \quad  \end{aligned} $$

이와 같이 각 점에서 값과 기울기 값을 만족하게 보간하는 방법을 `에르미트 보간(Hermitian interpolation)`이라고 한다.