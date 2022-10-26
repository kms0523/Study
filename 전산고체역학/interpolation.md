# $C^0$ interpolation
## $\phi : \R^d \rightarrow \R$
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
$$ \boldsymbol{\hat{\phi}} = \mathbf M^T \mathbf a \\ \text{where,} \quad \mathbf M =  \begin{bmatrix} \mathbf m(x_1) & \cdots & \mathbf m(x_n) \end{bmatrix}, \quad \hat{\phi}_i = \phi(\mathbf x_i) $$

따라서 $\bf a = (M^T)^{-1} \boldsymbol{\hat{\phi}}$이고 이를 원래 식에 대입하면 다음과 같다. 
$$ \begin{aligned} \phi_h &= \mathbf {a \cdot m} \\ &= \mathbf {m \cdot a} \\ &= \mathbf m^T (\mathbf M^T)^{-1} \boldsymbol{\hat{\phi}} \\ &= \mathbf n \cdot \boldsymbol{\hat{\phi}} \quad  \end{aligned} $$

만약, $d = 1$이고 $\mathbf m$이 다음과 같이 주어졌다고 하자.
$$ m_i = x^{i-1} $$

이 때, $\mathbf n = \mathbf M^{-1} \mathbf m$은 형상함수 벡터이고 $n_i$는 다음과 같은 Lagrange 다항식 형태로 주어진다.

$$ n_i = \prod_{\substack{j = 1 \\ j \neq i}}^n \frac{x_j - x}{x_j - x_i} $$

따라서 이를 `라그랑지 보간(Lagrangian interpolation)`이라고 한다.

## $\boldsymbol{\phi} : \R^d \rightarrow \R^r$
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

# $C^1$ 보간
## $\phi : \R \rightarrow \R$
함수 $\phi : \R \rightarrow \R$를 $2n$개의 `단항식(monomial)`을 갖는 `다항식(polynomial)`으로 근사하면 다음과 같이 표현할 수 있다.
$$ \phi(x) \approx \mathbf a \cdot \mathbf m(x) $$

이 떄, 서로 다른 $n$개의 $x_i$에서 $\phi(x_i), \phi'(x_i)$값을 알고 있다면 $\phi(x_i) = \mathbf a \cdot \mathbf m(x_i)$와 $\phi'(x_i) = \mathbf a \cdot \mathbf m'(x_i)$를 만족하도록 $\mathbf a$를 결정할 수 있다.

위의 조건을 행렬 형태로 나타내면 다음과 같다.
$$ \boldsymbol{\hat{\phi}} = \mathbf M^T \mathbf a \\ \text{where,} \quad \mathbf M =  \begin{bmatrix} \mathbf m(x_1) & \mathbf m'(x_1) & \cdots & \mathbf m(x_n) & \mathbf m'(x_n) \end{bmatrix}, \quad \boldsymbol{\hat{\phi}} = \begin{bmatrix} \phi(x_1) \\ \phi'(x_1) \\ \vdots \\ \phi(x_n) \\ \phi'(x_n) \end{bmatrix} $$

따라서 $\bf a = (M^T)^{-1} \boldsymbol{\hat{\phi}}$이고 이를 원래 식에 대입하면 다음과 같다. 
$$ \begin{aligned} \phi &= \mathbf {a \cdot m} \\ &= \mathbf {m \cdot a} \\ &= \mathbf m^T (\mathbf M^T)^{-1} \boldsymbol{\hat{\phi}} \\ &= \mathbf n \cdot \boldsymbol{\hat{\phi}} \quad  \end{aligned} $$

이와 같이 각 점에서 값과 기울기 값을 만족하게 보간하는 방법을 `에르미트 보간(Hermitian interpolation)`이라고 한다.