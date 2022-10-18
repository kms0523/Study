# Levi-Civita Tensor
다음 성질을 만족하는 $\epsilon_{ijk}$을 `Levi-Civita tensor` 혹은 `permutation tensor`라고 한다.
$$ \epsilon_{ijk} = \begin{cases} 1 & (i,j,k) \in \{ (1,2,3), (2,3,1), (3,2,1) \} \\ -1 & (i,j,k) \in \{ (3,2,1), (2,1,3), (1,3,2) \} \\ 0 & \text{otherwise} \end{cases} $$

### 명제1
$\epsilon_{ijk}$를 Levi-Civita tensor라 하자.

$a,b \in \R^3$에 대해 다음을 증명하여라.
$$ a \times b = \epsilon_{ijk}a^jb^k $$

**Proof**

직접 계산해보면 성립함을 알 수 있다.

### 명제2
$\epsilon_{ijk}$를 Levi-Civita tensor라 하자.

$A \in M_{33}(\R)$에 대해 다음을 증명하여라.
$$ \det(A) = \epsilon_{ijk}a_{i1}a_{j2}a_{k3} $$

**Proof**

$\det$의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} \det(A) &= A_{*1} \cdot A_{*2} \times A_{*3} \\&= A_{*1} \cdot (\epsilon_{ijk}a_{j2}a_{k3}) \\&= \epsilon_{ijk}a_{i1}a_{j2}a_{k3} \end{aligned} $$

### 명제3
$\epsilon_{ijk}$를 Levi-Civita tensor라 하자.

다음을 증명하여라.
$$ \epsilon_{ijk}\epsilon_{ilm} = \delta_{jl}\delta_{km} - \delta_{jm}\delta_{kl} $$

**Proof**

직접 계산해보면 성립함을 알 수 있다.

# Isotropic Tensor

> Reference  
> [Blog - Isotropic Tensors](https://farside.ph.utexas.edu/teaching/336L/Fluid/node252.html)

