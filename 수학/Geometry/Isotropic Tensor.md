
# Levi-Civita Tensor
다음 성질을 만족하는 $\epsilon_{ijk}$을 `Levi-Civita tensor` 혹은 `permutation tensor`라고 한다.
$$ \epsilon_{ijk} = \begin{cases} 1 & (i,j,k) \in \{ (1,2,3), (2,3,1), (3,2,1) \} \\ -1 & (i,j,k) \in \{ (3,2,1), (2,1,3), (1,3,2) \} \\ 0 & \text{otherwise} \end{cases} $$

### 명제1
$\epsilon_{ijk}$를 Levi-Civita tensor라 하자.

다음을 증명하여라.
$$ \epsilon_{ijk}\epsilon_{ilm} = \delta_{jl}\delta_{km} - \delta_{jm}\delta_{kl} $$

**Proof**

직접 계산해보면 성립함을 알 수 있다.

# Isotropic Tensor

> Reference  
> [Blog - Isotropic Tensors](https://farside.ph.utexas.edu/teaching/336L/Fluid/node252.html)

