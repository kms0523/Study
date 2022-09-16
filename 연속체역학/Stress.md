# Stress Vector

<p align = "center">
<img src = "./image/stress2.png">
</p>

물체에 하중이 가해졌을 때, 물체 내부의 분자들에 작용하는 힘을 표시한 (a)와 물체 내부를 가상의 평면으로 나눈 (b)를 보자.

(b)에 나타난 가상의 평면에 작용하는 힘을 정확히 표현하기 위해서는 평면 위의 분자들간의 상호작용을 모두 고려해야 한다. 하지만 많은 분자를 모두 고려하는 일은 매우 어려운 일이다. 

이를 해결하기 위해 Cauchy는 (c)와 같이 물질의 분자구조를 무시하고 가상의 평면에 작용하는 가상의 분자력 $\bf F$를 고안하였다. 이 때, $\bf F$는 평면 위의 분자들에 의해 평면에 작용하는 힘이다.

(d)를 보면 알 수 있듯이 $\bf F$는 어떤 평면을 선택하냐에 따라 달라지며 이는 평면이 달라지면 평면에 힘을 가하는 분자들의 집합이 달라지기 때문이다.

다음으로, (c)와 같이 가정한 상황에서 가상의 평면위의 점 $P$에 작용하는 가상의 분자력에 의해 발생하는 응력을 고려해보자.

<p align = "center">
<img src = "./image/stress1.png" width = 300>
</p>

위의 그림과 같이 $P$를 포함하는 영역을 $\Delta A$라 하고 $\Delta A$ 위에 작용하는 가상의 분자력을 $\Delta \bf F$라 하자.

이 때, $P$에 작용하는 `응력 벡터(stress vector)` $\bf t_n$은 다음과 같이 정의한다.
$$ \mathbf{t_n} = \lim_{\Delta A \rightarrow 0} \frac{\Delta \bf F}{\Delta A} $$

위에 살펴보았듯이 평면의 선택 즉, $\bf n$에 따라서 $\Delta \bf F$가 달라지기 때문에 $\bf t_n$을 표기할 때 하첨자로 $\bf n$을 사용한다.

# Cauchy's Stress Principle
연속체 역학의 기본 공리인 Cauchy's stress principle은 다음과 같다. 

"주어진 점 $\bf x$와 시간 $t$에서 동일한 접평면을 갖는 모든 면의 응력 벡터는 동일하다."

즉, 주어진 점을 포함하는 가상의 곡면의 형태(곡률)와는 전혀 관계 없이 주어진 점에서 접평면만 동일하다면 응력벡터는 동일하다는 의미로 이를 식으로 나타내면 다음과 같다.
$$ \mathbf {t_n} = \mathbf {t_n}(\mathbf {x, n}, t) $$

또한, 동일한 접평면에서 단위 접선 벡터만 반대방향일 경우 응력 벡터 또한 크기는 같고 방향만 반대이다.
$$ \mathbf {t_n} = -\mathbf {t_{-n}} $$

이는 Newton의 작용 반작용 법칙과 동치이다.

# Stress Tensor
Cauchy's stress principle에 의해 주어진 점 $\bf x$와 시간 $t$에서 $\bf t_n$은 $\bf n$에 의해 결정된다. 

따라서 다음을 만족하는 변환 $\boldsymbol \sigma$를 `stress tensor`라 한다.
$$ \begin{equation} \bf t_n = \boldsymbol \sigma (n) \end{equation} $$

### 명제1
$\R^3$공간의 임의의 기저 $\epsilon$이 있다고 하자.

이 때, 다음을 증명하여라.
$$ \boldsymbol \sigma (n^i \mathbf e_i) = n^i \boldsymbol \sigma (\mathbf{e}_i)$$

**Proof**

<p align = "center">
<img src = "./image/stress3.png" width = 300>
</p>

Normal vector가 $\mathbf e_i$와 평행한 면의 면적을 $\Delta A^i$라 하고 $\mathbf n$과 평행한 면의 면적을 $\Delta A^n$이라 하자.

이 때, 운동 방정식은 다음과 같다.
$$ \begin{equation} \mathbf{t_{-e_i}} \Delta A^i + \mathbf{t_{n}} \Delta A^n + \mathbf f_b \Delta V = \rho \Delta V \mathbf a \end{equation} $$

이 때, $\Delta x^i \ll 1 \enspace (i = 1, 2, 3)$이라면 $\Delta V \ll \Delta A$이고 $\Delta V$와 관련된 항을 무시할 수 있게 된다.

따라서 식(2)는 다음과 같이 간단해 진다.
$$ \begin{equation} \mathbf t_{- \mathbf e_i} \Delta A^i + \mathbf{t_{n}} \Delta A^n = \mathbf 0 \end{equation} $$

이 때, $\Delta A^i = n^i \Delta A^n$이고 Cauchy's stress principle에 의해 식(3)은 다음과 같다.
$$ \begin{equation} \mathbf{t_{n}} = n^i\mathbf{t_{e_i}} \end{equation} $$

식(1)에 식(4)을 대입하면 다음과 같다.
$$ \begin{equation} \begin{aligned} \boldsymbol \sigma (n^i \mathbf e_i) &= \mathbf t_n \\ &= n^i \mathbf t_{\mathbf e_i} \\ &= n^i \boldsymbol \sigma (\mathbf{e}_i) \end{aligned}  \end{equation} $$

따라서 $\boldsymbol \sigma$는 선형변환이며 이를 `응력텐서(stress tensor)`라 한다.

### 명제2
$\R^3$공간의 임의의 기저 $\beta$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ \boldsymbol \sigma (n^i \beta_i) = n^i \boldsymbol \sigma (\beta_i)$$

**Proof**

$B$를 $\epsilon$에서 $\beta$으로 변환하는 기저변환 행렬이라고 하면 다음이 성립한다.
$$ \beta_i = B^j_ie_j $$

따라서 다음이 성립한다.
$$ \begin{aligned} \sigma(n^i\beta_i) &= \sigma(n^iB^j_ie_j) \\ &= n^i\sigma(B^j_ie_j) \\ &= n^i \boldsymbol \sigma (\beta_i) \quad {_\blacksquare} \end{aligned} $$

### 명제3
$\R^3$공간의 임의의 기저 $\beta$가 있다고 하자.

$\frak m^\beta_\beta(\boldsymbol\sigma) = \sigma$라 할 떄, 다음을 증명하여라.
$$ \mathbf t_{\beta_i} = \sigma^j_i\beta_j $$

**Proof**

응력 텐서의 정의에 의해 다음이 성립한다.
$$ \frak m^\beta_\beta(\boldsymbol\sigma) = \begin{bmatrix} \frak m_\beta(\boldsymbol{\sigma}(\beta_1)) & \cdots & \frak m_\beta(\boldsymbol{\sigma}(\beta_3)) \end{bmatrix} = \begin{bmatrix} \frak m_\beta(\mathbf t_{\beta_1}) & \cdots & \frak m_\beta(\mathbf t_{\beta_3}) \end{bmatrix} $$

따라서 다음이 성립한다.
$$ \mathbf t_{\beta_i} = \sigma^j_i\beta_j $$

#### 참고
$\sigma^j_i$는 $\beta_i$를 normal vector로 갖는 평면에 작용하는 stress vector의 $\beta_j$방향의 크기다.

### 명제4
$\R^3$공간의 standard basis $\epsilon$이 있다고 하자.

$\frak m^\epsilon_\epsilon(\boldsymbol\sigma) = \sigma$라 할 떄, 다음을 증명하여라.
$$ \sigma \text{ is symmetric.}$$

**Proof**

<p align = "center">
<img src = "./image/stress4.png" width = 300>
</p>

응력텐서 $\boldsymbol{\sigma}$가 작용하는 정육면체 미소요소의 $A$점에서 $x_3$ 방향의 모멘트 평형 방정식을 고려해보자.
$$ \begin{equation} (M_A)_3 = I_{33}\alpha \end{equation} $$

정중앙의 점 $A$에서 모멘트와 회전관성을 계산하면 다음과 같다.
$$ \begin{equation} \begin{aligned} (M_A)_3 &= \sigma^2_1(\Delta x_2)(\Delta x_3)(\Delta x_1 / 2) + (\sigma^2_1 + \Delta \sigma^2_1)(\Delta x_2)(\Delta x_3)(\Delta x_1 / 2) \\ &- \sigma^1_2(\Delta x_1)(\Delta x_3)(\Delta x_2 / 2) - (\sigma^1_2 + \Delta \sigma^1_2)(\Delta x_1)(\Delta x_3)(\Delta x_2 / 2) \\ I_{33} &= \Delta x_1 \Delta x_2 \Delta x_3((\Delta x_1)^2 + (\Delta x_2)^2) \end{aligned} \end{equation}  $$

식(6)에 식(7)을 대입하면 다음과 같다.
$$ \sigma^2_1 + \Delta \sigma^2_1 - \sigma^1_2 - \Delta \sigma^1_2 = \alpha ((\Delta x_1)^2 + (\Delta x_2)^2)$$

미소 값을 무시하면 다음과 같다.
$$ \begin{gathered} \sigma^2_1 - \sigma^1_2 = 0 \\ \therefore \sigma^2_1 = \sigma^1_2 \end{gathered} $$

다른 방향으로의 모멘트 평형 방정식을 고려하면 다음의 결론을 얻을 수 있다.
$$ \sigma^3_1 = \sigma^1_3, \sigma^3_2 = \sigma^2_3 $$

따라서 $\sigma$는 대칭이며 6개의 독립적인 응력성분을 갖는다.

> Q. standard basis 말고는 성립안하는 특징인가?

> Reference  
[book] (Lai et al) Introduction to Continuum Mechanics Chapter4.4  


---

# 오일러-코시 응력 법칙
연속체로 가정한 물체 내부의 모든점에 작용하는 `체적력(body force)`과 `표면력(surface force)`을 고려해보자.

체적력은 중력, 전자기력과 같이 단위 부피당 작용하는 힘을 의미하며 표면력은 실제 표면이나 물체를 두부분으로 나누는 가상의 표면에 작용하는 힘이다.

먼저 표면력을 생각해보자. 