# Diagonalize(선형변환)
vector space $V/ \mathbb F$와 $T \in L(V)$가 있을 때, $\frak m_\beta^\beta(T)$가 대각행렬이 되게 만드는 $V$의 기저 $\beta$가 존재하는 경우 $T$를 `대각화 가능(diagonalizable)`하다고 한다. 

### 명제1
$n$차원 vector space $V/ \mathbb F$와 $T \in L(V; V)$가 있다고 하자.

$\beta$가 $T$의 고유벡터로 이루어진 기저일 때, 다음을 증명하여라.
$$ T \text{ is diagonalizeble} $$

**Proof**

$\frak m_\beta^\beta(T)$를 풀어쓰면 다음과 같다.
$$ \frak m_\beta^\beta(T) = \begin{bmatrix} \frak m_\beta(T(\beta_1)) & \cdots & \frak m_\beta(T(\beta_n)) \end{bmatrix} $$

이 때, $T(\beta_i) = \lambda^i \beta_i$임으로 $\frak m_\beta^\beta(T)$는 대각행렬이다. $\quad {_\blacksquare}$

#### 참고
$T$가 고유벡터로 이루어진 기저를 갖는다는 것과, $T$가 대각화 가능하다는 것은 동치이다.

### 명제2
$n$차원 vector space $V/ \mathbb F$와 $T \in L(V;V)$가 있다고 하자.

$T$가 서로 다른 $n$개의 고유값을 갖을 때, 다음을 증명하여라.
$$ T \text{ is diagonalizeble} $$

**Proof**

고유벡터를 $\beta_1, \cdots, \beta_n$이라 하고 해당하는 고유값들을 $\lambda^1, \cdots , \lambda^n$이라 하자. 

고유벡터의 집합이 선형종속이라고 가정하고, 일반성을 잃지 않고 선형 종속인 원소를 $\beta_n$이라고 하자.

$\beta_n$은 선형종속임으로 다음이 성립한다.
$$  \begin{aligned} & \beta_n = a^1\beta_1 + \cdots + a^{n-1}\beta_{n-1} \\ \Rightarrow \enspace & T(\beta_n) = T(a^1\beta_1+ \cdots + a^{n-1}\beta_{n-1}) \\ \Rightarrow \enspace & \lambda^n \beta_n = \lambda^1a^1\beta_1 + \cdots + \lambda^{n-1}a^{n-1}\beta_{n-1} \end{aligned} $$

동시에 다음도 성립한다.
$$ \begin{aligned} & \beta_n = a^1\beta_1 + \cdots + a^{n-1}\beta_{n-1} \\ \Rightarrow \enspace &  \lambda^n\beta_n = \lambda^n a^1 \beta_1 + \cdots + \lambda^n a^{n-1} \beta_{n-1} \end{aligned} $$

두 식을 빼면 다음과 같다.
$$ 0_V = a^1(\lambda^n - \lambda^1)\beta_1 + \cdots + a^{n-1}(\lambda^n - \lambda^{n-1})\beta_{n-1} $$

이 때, 서로 다른 고유값을 가짐으로 $a_1 = \cdots = a_{n-1} = 0$이되고 $\beta_n = 0_V$가 된다. 이 때, 고유값은 $0_V$가 아님으로 모순이 발생한다.

고유벡터의 집합이 선형종속이라 가정하였을 때 모순이 발생함으로, 고유벡터의 집합은 선형독립이 되고 고유벡터의 집합은 기저가 된다.

따라서, 고유벡터로 이루어진 기저가 존재함으로 명제1에 의해 대각화 가능하다. $\quad {_\blacksquare}$ 

#### 참고
반드시 서로 다른 고유값들을 가져야만 대각화 가능한 것은 아니다.

예를 들어 다음의 행렬을 생각해보자.
$$ A= \begin{bmatrix} 4 & 0 & 1 \\ 2 & 3 & 2 \\ 1 & 0 & 4 \end{bmatrix} $$

다음 행렬의 특성다항식의 근은 $\lambda = 3,5$로 두개의 근을 갖는다. 하지만 $\lambda =3$일 때, 두개의 선형독립인 고유벡터 $\begin{bmatrix} 1 \\ 0 \\ -1 \end{bmatrix}, \begin{bmatrix} -1 \\ 0 \\ 1 \end{bmatrix}$가 존재하며, $\lambda = 5$일 때, $\begin{bmatrix} 1 \\ 4 \\ 1 \end{bmatrix}$인 고유벡터가 존재한다. 이 세개의 고유벡터로 이루어진 기저가 존재함으로, $L_A : \R^2 \rightarrow \R^2$는 대각화 가능하며 $\begin{bmatrix} 5 && \\ & 3 & \\ &&-1 \end{bmatrix}$인 대각행렬을 갖는다.

### 명제3
$n$차원 vector space $V/ \mathbb F$와 $T \in L(V)$가 있을 때, $T$가 대각화 가능하다는 말과 고유값 $\lambda^1, \cdots \lambda^k, \enspace k \le n$에 대해 $V = \oplus_i^k E_{\lambda^i}$가 동치임을 증명하여라.

**Proof**

[$\Rightarrow$]  
$\exist \beta = \{ v_{1,1}, \cdots, v_{1,m_1} \cdots, v_{k,1}, \cdots, v_{k,m_k}\}$


# Diagonalize(행렬)
$A \in \mathbb M_{nn}(\mathbb F)$가 있을 때, 선형변환을 다음과 같이 정의하자.
$$L_A : \mathbb F^n \rightarrow \mathbb F^n \quad s.t. \quad x \mapsto Ax$$

$\mathbb F^n$의 임의의 기저를 $\beta$라 하면 다음이 성립한다.
$$ \frak m_\beta^\beta(L_A) = \frak m_{\epsilon_n}^\beta(id) \frak m_{\epsilon_n}^{\epsilon_n}(L_A) \frak m^{\epsilon_n}_\beta(id) = P^{-1}AP $$

즉, $\frak m_\beta^\beta(L_A) \sim A$이다.

이 때, $L_A$가 diagonalizable하고, $\beta$가 고유벡터로 이루어졌다고 하자.

그러면 $\frak m_\beta^\beta(L_A)$는 대각행렬이 되고 $A$는 대각행렬과 similar하다.

결론적으로, $A$가 어떤 대각행렬 $D \in F^{n \times n}$과  similar인 경우 $L_A$가 diagonalizable하며, 이 경우 행렬 $A$가 diagonalizable하다고 한다.


### 참고1
Diagonalize는 어떤 `체(field)`인지에 따라 달라진다. 다음 예시를 보자.

회전 변환으로 잘 알려진 선형변환 $L_R$이 다음과 같이 주어졌다.
$$ L_R : \mathbb F^n \rightarrow \mathbb F^n \quad s.t. \quad x \mapsto Rx$$
$$ \text {where, } R = \begin{bmatrix} \cos \theta & - \sin \theta \\ \sin \theta & \cos \theta \end{bmatrix}, \quad 0 < \theta < 2\pi \land \theta \neq \pi $$

이 때, $L_R$이 diagonalizable지 알아보자. $L_R$이 diagonalizable한지 알아보기 위해서는 고유벡터를 찾아야한다. 즉, 다음을 만족 $v \in \mathbb F^n - \{ 0_{\mathbb F^n} \}$를 찾아야 한다.
$$ \begin{equation} \begin{aligned} & L_R(v) = \lambda v, \quad \lambda \in \mathbb F \\ \Leftrightarrow \enspace & Rv = \lambda v \\ \Leftrightarrow \enspace & (R -\lambda I)v = 0  \end{aligned} \end{equation} $$

$v \neq 0$이라는 사실을 통해 $R-\lambda I$가 역행렬이 없어야 함을 알 수 있다. 따라서 $\det(R - \lambda I) = 0$이어야 하고 $\det(R - \lambda I)$를 행렬의 `특성다항식(characteristic polynomial)`이라고 한다.

특성다항식이 0이되는 경우를 찾아보자.
$$ \begin{equation} \begin{aligned} & (\cos \theta - \lambda)^2 + \sin \theta^2 = 0 \\ \Leftrightarrow \enspace & \lambda^2 - 2 \cos \theta \lambda + 1 = 0 \end{aligned} \end{equation}   $$

이제, $\mathbb F = \R$인 경우를 생각해보자. 식(2)의 판별식을 확인해보면 모든 $\theta$에 대해서 0보다 작음을 알 수 있으며 따라서 $\lambda \in \R$에서는 위의 특성다항식을 만족하는 해가 존재하지 않는다. 따라서 고유벡터 또한 존재하지 않고 대각화 불가능하다.

다음으로 $\mathbb F = \mathbb C$인 경우를 생각해보자. $\lambda \in \mathbb C$에서는 위의 특성다항식을 만족하는 해 $\lambda = \cos \theta \pm i \sin \theta = e^{\pm i \theta}$가 존재한다. 고유값에 해당하는 고유벡터를 찾기 위해서 식(1)에 대입한다.

먼저, $\lambda = \cos \theta + i \sin \theta$ 경우를 대입해 정리하면 다음과 같다.
$$ \begin{aligned} & -i\sin \theta v_1 - \sin \theta v_2 = 0 \\ \Leftrightarrow \enspace & -i v_1 = v_2  \\ \Leftrightarrow \enspace & v_1 = t, \quad v_2 = -i t \quad t \neq 0 \end{aligned}  $$

동일하게 $\lambda = \cos \theta - i \sin \theta$ 경우를 대입해 정리하면 다음과 같다.
$$ v_1 = s, \quad v_2 = i s \quad s \neq 0 $$

$t,s$를 각각 $1$로 잡아주면 다음과 같은 두개의 고유벡터로 이루어진 기저를 얻을 수 있다.
$$ \beta = \left( \begin{bmatrix} 1 \\ -i \end{bmatrix}, \begin{bmatrix} 1 \\ i \end{bmatrix} \right) $$ 

따라서, $L_R$은 대각화 가능하며 대각행렬은 다음과 같다.
$$ [L_R]_\beta = \begin{bmatrix} e^{i\theta} & 0 \\ 0 & e^{-i\theta} \end{bmatrix} $$