# Force
연속체 $\Omega$에 작용하는 힘은 다음과 같이 주어진다.
$$ F = \int_{\partial \Omega} \sigma n \thinspace ds + \int_{\Omega} \rho b \thinspace dV $$

### 명제1
$\sigma$가 충분히 매끄러운 경우 다음을 증명하여라.
$$ F = \int_{\Omega} \text{div}(\sigma) + \rho b \thinspace dV $$

**Proof**

Divergence theorem에 의해 다음이 성립한다.
$$ \begin{aligned} F &= \int_{\partial \Omega} \sigma n \thinspace ds + \int_{\Omega} \rho b \thinspace dV \\&= \int_{\Omega} \text{div}(\sigma) + \rho b \thinspace dV \end{aligned} $$

# Force per Unit Volume
단위 부피당 작용하는 힘 $\mathcal F$를 다음과 같이 정의하자.
$$ \begin{aligned} \mathcal F &:= \text{div}(\sigma) + \rho b \end{aligned}  $$

# Power
연속체 $\Omega$에 작용하는 `일률(Power)` $P$를 다음과 같이 정의하자.
$$ P := \int_{\partial \Omega} \sigma n \cdot v \thinspace ds + \int_{\Omega} \rho b \cdot v \thinspace dV $$

### 명제1
$\sigma$가 충분히 매끄러운 경우 다음을 증명하여라.
$$ P = \int_{\Omega} \text{div}(\sigma^t v) \thinspace + \rho b \cdot v \thinspace dV $$

**Proof**

Divergence theorem에 의해 다음이 성립한다.
$$\begin{aligned} P &= \int_{\partial \Omega} \sigma n \cdot v \thinspace ds + \int_{\Omega} \rho b \cdot v \thinspace dV \\&= \int_{\partial \Omega} \sigma^t v \cdot n \thinspace ds + \int_{\Omega} \rho b \cdot v \thinspace dV \\&= \int_{\Omega} \text{div}(\sigma^t v) \thinspace + \rho b \cdot v \thinspace dV \quad {_\blacksquare} \end{aligned} $$

# Power per Unit Volume
단위 부피당 일률을 $\mathcal P$를 다음과 같이 정의하자.
$$ \mathcal P := \text{div}(\sigma^t v) \thinspace + \rho b \cdot v $$

### 명제1
다음을 증명하여라.
$$ \mathcal P = \mathcal F^i v^i + \sigma^i_j D^i_j $$

$$ \text{Where, } D \text{ is symmetric part of } \nabla_xv$$

**Proof**

$\mathcal P$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \mathcal P &= \text{div}(\sigma^t v) \thinspace + \rho b \cdot v \\&= \frac{\partial}{\partial x^i} (\sigma^j_i v^j) + \rho f_b^k v^k \\&= v^j \frac{\partial \sigma^j_i}{\partial x^i} + \sigma^j_i\frac{\partial v^j}{\partial x^i} + \rho f_b^k v^k \\&= \bigg( \frac{\partial \sigma^j_i}{\partial x^i} + \rho f_b^j \bigg) v^j + \sigma^j_i(D^j_i + W^j_i) \\&= \mathcal F^j v^j + \sigma^j_i (D^j_i + W^j_i) \end{aligned} $$

$$ \text{Where, } W \text{ is skew-symmetric part of } \nabla_xv $$

$\sigma$가 symmetric tensor임으로 다음이 성립한다.
$$ \begin{aligned} \mathcal P &= \mathcal F^j v^j + \sigma^j_i(D^j_i + W^j_i) \\&= \mathcal F^j v^j + \sigma^j_i D^j_i \end{aligned} $$

Dummy index를 바꿔주면 다음과 같다.
$$ \mathcal P = \mathcal F^i v^i + \sigma^i_j D^i_j \quad {_\blacksquare} $$

# Stress Power
$\mathcal P$에 대해 다음이 성립한다.
$$ \mathcal P = \mathcal F^i v^i + \sigma^i_j D^i_j $$

이 떄, 좌측항 $F^j v^j$은 단위 부피당 작용하는 힘에 의한 일률을 나타내며, 우측항 $\sigma^j_i D^j_i$은 단위 부피당 부피나 모양의 변형에 의한 일률을 나타낸다.

Stress power $\mathcal P_s$를 다음과 같이 정의한다.
$$ \mathcal P_s := \sigma^i_j D^i_j $$