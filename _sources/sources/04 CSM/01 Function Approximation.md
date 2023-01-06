# Function Approximation
함수 $\phi : \R^d \rightarrow \R$가 있을 떄, 서로 다른 $n$개의 점 $x_i \in \R^n$에서 $\phi$의 값 $\phi(x_i)$을 알고 있다고 하자.

$$ \phi(x_i) \text{ is known}, \enspace i=1,\cdots,n $$

이 때, $\phi$의 approximate function $\phi_h$를 구해보자.

$\phi_h$는 $\phi$의 approximate function임으로 approximation의 기준을 정해야 되는데, 이 때 한가지 타당한 기준은 다음과 같다.

$$ \phi(x_i) = \phi_h(x_i), \enspace i=1,\cdots,n $$

즉, 값이 주어진 점들에서 approximate function이 원래 function과 정확히 일치하는 것을 approximation의 기준으로 삼는것이다.

이제, 기준이 결정되었으니 기준을 만족하는 $\phi_h$를 찾아보자.

## Search

집합 $V$를 다음과 같이 정의하자.

$$ V := \Set{f :\R^d \rightarrow \R} $$

선형대수의 성질에 의해, $V/\R$은 vector space이다.

이 떄, infinite dimension vector space $V$를 탐색할 수 없음으로 탐색할 $V$의 finite subspace $\mathcal{M}$을 결정하자.

$\mathcal{M}$의 basis가 될 linearly independent한 function들을 다음과 같이 정의하자.

$$ m_i : \R^d \rightarrow \R, \enspace i=1,\cdots,k $$

그러면, $m_i$는 $\mathcal{M}$의 basis임으로 다음이 성립한다.

$$ \mathcal{M} = \span(\Set{m_i}) $$

그리고 다음을 가정하자.

$$ \exist \phi_h \in \mathcal{M} \st \phi(x_i) = \phi_h(x_i), \enspace i=1,\cdots,n $$

$\phi_h \in \mathcal{M}$임으로 다음이 성립한다.

$$ \exist a_1, \cdots, a_k \in \R \st \phi_h = a^im_i $$

이 때, $\phi_h$는 $\phi(x_i) = \phi_h(x_i), \enspace i=1,\cdots,n$ 조건을 만족함으로 이를 matrix form으로 쓰면 다음과 같다.

$$ \begin{gathered} \begin{bmatrix} m_1(x_1) &\cdots& m_k(x_1) \\ \vdots && \vdots \\ m_1(x_n) &\cdots& m_k(x_n) \end{bmatrix} \begin{bmatrix} a^1 \\ \vdots \\ a^k \end{bmatrix} = \begin{bmatrix} \phi(x_1) \\ \vdots \\ \phi(x_n) \end{bmatrix} \\ Ma =\hat{\phi} \end{gathered}  $$

만약 $M$이 invertible matrix면 다음이 성립한다.

$$ \begin{gathered} a = M^{-1}\hat{\phi} \\ k=n \end{gathered}  $$

### 명제1
다음을 증명하여라.

$$ \phi \in \mathcal{M} \iff \phi = \phi_h $$

**Proof**

[$\implies$]  
$\phi \in \mathcal{M}$임으로 다음이 성립한다.

$$ \phi = b^im_i $$

$b := \begin{bmatrix} b^1 &\cdots& b^n \end{bmatrix}^T$라고 할 때, $\phi(x_i) \enspace i=1,\cdots,n$를  matrix form으로 쓰면 다음과 같다.

$$ Mb = \hat{\phi} $$

$M$이 invertible matrix이면 다음이 성립한다.

$$ b = M^{-1}\hat{\phi} = a $$

따라서, 다음이 성립한다.

$$ \phi = \phi_h \qed $$

[$\impliedby$]  
자명하다.$\qed$

## Shape Function
계산의 편의성을 위해 행렬 $m$을 다음과 같이 정의하자.

$$ m := \begin{bmatrix} m_1(x) \\ \vdots \\ m_n(x)  \end{bmatrix} $$  

그러면 다음이 성립한다.

$$ \begin{aligned} \phi_h &= m^Ta \\&= m^TM^{-1}\hat{\phi} \end{aligned} $$

이 때, 행렬 $n$을 다음과 같이 정의하자.

$$ n := (M^{-1})^Tm $$

그러면 다음이 성립한다.

$$ \begin{aligned} \phi_h &= n^T\hat{\phi} \\&= \phi(x_i)n_i \end{aligned} $$

이 때, $n_i, \enspace i=1,\cdots,n$을 `shape function`이라고 한다.

### 명제1
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

### 명제2
Shape function $n_i, \enspace i=1,\cdots,n$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ n_i(x_j) = \delta_{ij}, \enspace i,j
=1,\cdots,n $$

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




# Interpolation
## $C^0$ interpolation
### $\phi : \R^d \rightarrow \R$
함수 $\phi : \R^d \rightarrow \R$가 있을 때, 서로 다른 $n$개의 $\mathbf x_i$에서 $\phi(\mathbf x_i)$값을 알고 있다고 하자.

이 때, $\phi$를 `다항식(polynomial)`으로 근사해보자.

$\phi$를 $n$개의 `단항식(monomial)` $m_i$으로 이루어진 다항식으로 근사하면 다음과 같이 표현할 수 있다.

$$ \phi(x) \approx \phi_h(x) = a_i m_i(\mathbf x) $$

이를 행렬 형태로 표현하면 다음과 같다.

$$ \phi_h = \mathbf a \cdot \mathbf m $$

이 때, 벡터함수 $\mathbf m : \R \rightarrow \R^n$을 `monomial vector function`이라 한다. 

위 다항식이 서로 다른 n개의 점에서 $\phi(\mathbf x_i) = \phi_h(\mathbf x_i)$을 만족해야하며 이를 성분으로 나타내면 다음과 같다.

$$ \phi_h(\mathbf x_i) = a_j m_j(\mathbf x_i) $$

이를 다시 행렬 형태로 나타내면 다음과 같다.

$$ \begin{gathered} \boldsymbol{\hat{\phi}} = \mathbf M^T \mathbf a \\ \text{where,} \quad \mathbf M =  \begin{bmatrix} \mathbf m(x_1) & \cdots & \mathbf m(x_n) \end{bmatrix}, \quad \hat{\phi}_i = \phi(\mathbf x_i) \end{gathered} $$

따라서 $\bf a = (M^T)^{-1} \boldsymbol{\hat{\phi}}$이고 이를 원래 식에 대입하면 다음과 같다. 

$$ \begin{aligned} \phi_h &= \mathbf {a \cdot m} \\ &= \mathbf {m \cdot a} \\ &= \mathbf m^T (\mathbf M^T)^{-1} \boldsymbol{\hat{\phi}} \\ &= \mathbf n \cdot \boldsymbol{\hat{\phi}} \quad  \end{aligned} $$

만약, $d = 1$이고 $\mathbf m$이 다음과 같이 주어졌다고 하자.

$$ m_i = x^{i-1} $$

이 때, $\mathbf n = \mathbf M^{-1} \mathbf m$은 형상함수 벡터이고 $n_i$는 다음과 같은 Lagrange 다항식 형태로 주어진다.


$$ n_i = \prod_{\substack{j = 1 \\ j \neq i}}^n \frac{x_j - x}{x_j - x_i} $$

따라서 이를 `라그랑지 보간(Lagrangian interpolation)`이라고 한다.

### $\boldsymbol{\phi} : \R^d \rightarrow \R^r$
벡터 함수 $\boldsymbol{\phi} : \R^d \rightarrow \R^r$를 $n$개의 단항식을 갖는 다항식으로 근사하면 다음과 같이 표현할 수 있다.


$$ \boldsymbol{\phi}\mathbf{(x)} = \mathbf {Am(x)} \\ \mathbf A \in \R^{r \times n}$$

이 때, 서로 다른 $n$개의 $\mathbf x_i$에서 $\boldsymbol{\phi}(\mathbf x_i)$ 값을 알고 있다면 $\boldsymbol{\phi}(\mathbf x_i) = \mathbf {Am(x}_i)$를 만족하도록 $\bf A$를 결정할 수 있다. 

$\boldsymbol{\phi}$의 $i$번째 원소 $\phi_i$는 다음과 같이 표현된다.

$$ \begin{equation} \phi_i(\mathbf x) = \mathbf A_{i*} \cdot \mathbf m(\mathbf x) \end{equation} $$

$i$번째 원소가 만족해야 하는 조건을 행렬 형태로 나타내면 다음과 같다.

$$ \hat{ \boldsymbol \phi_i} = \mathbf M^T \mathbf A_{i*} \\ \text{where,} \quad \mathbf M =  \begin{bmatrix} \bf m(x_1) & \cdots & \bf m(x_n) \end{bmatrix}, \quad \hat{\phi}_{i,j} = \phi_i(\mathbf x_j)$$

따라서 $\mathbf A_{i*} = (\mathbf M^T)^{-1} \hat{ \boldsymbol \phi_i}$이고 식(5)에 대입하면 다음과 같다.


$$ \begin{aligned} \phi_i &= \mathbf A_{i*} \cdot \mathbf m \\ &= \mathbf m \cdot \mathbf A_{i*} \\ &= \mathbf m^T (\mathbf M^T)^{-1} \boldsymbol{\hat{\phi}}_i \\ &= \mathbf n \cdot \boldsymbol{\hat{\phi}}_i \end{aligned} $$

모든 원소가 만족해야 하는 조건은 다음과 같다.

$$ \phi_i = \sum_{j=1}^n n_j\hat{\phi}_i(\mathbf x_j) \quad (i = 1, \cdots, r) $$

이를 하나의 행렬식으로 나타내면 다음과 같다.

$$ \boldsymbol{\phi} = \begin{bmatrix} n_1 \enspace \underbrace{0 \cdots 0}_{r-1}  && n_2 \enspace \underbrace{0 \cdots 0}_{r-1} && \cdots && n_n \enspace \underbrace{0 \cdots 0}_{r-1} \\ 0 \enspace n_1 \enspace \underbrace{0 \cdots 0}_{r-2} && 0 \enspace n_2 \enspace \underbrace{0 \cdots 0}_{r-2} && \cdots && 0 \enspace n_n \enspace \underbrace{0 \cdots 0}_{r-2} \\ && \qquad  \vdots \\ \underbrace{0 \cdots 0}_{r-1} \enspace  n_1 && \underbrace{0 \cdots 0}_{r-1} \enspace n_2 && \cdots && \underbrace{0 \cdots 0}_{r-1} \enspace n_n \end{bmatrix} \begin{bmatrix} \boldsymbol{\phi}(\mathbf x_1) \\ \vdots \\ \boldsymbol{\phi}(\mathbf x_r) \end{bmatrix} $$


$$ \boldsymbol{\phi} = \mathbf N \boldsymbol{\hat\phi} $$



#### 형상함수 성질
1. $$ \sum_i n_i = 1 $$
2. $$ n_i(x_j) = \delta_{ij} $$

> Q. 2번 성질이 왜 만족할까?

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