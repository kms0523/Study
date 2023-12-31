# Kronecker Delta Tensor
다음 성질을 만족하는 $\delta_{ij}$를 `Kronecker delta tensor`라고 한다.
$$ \delta_{ij} = \begin{cases} 0 & i \neq j \\ 1 & i = j \end{cases} $$

### 명제1
$\delta$를 Kronecker delta tensor라고 하자.

다음을 증명하여라.
$$ \delta_{ij} = \delta_{ji} $$

**Proof**

$\delta$의 정의에 의해 자명하다.$\quad {_\blacksquare}$

### 명제2
$\delta$를 Kronecker delta tensor라고 하자.

다음을 증명하여라.
$$ \delta_{ij} = \delta_{ik}\delta_{kj} $$

**Proof**

직접 계산해보면 성립함을 알 수 있다.$\quad {_\blacksquare}$

#### 명제2.1
$\delta$를 Kronecker delta tensor라고 하자.

다음을 증명하여라.
$$ \delta_{ij} = \delta_{ik}\delta_{jk} $$

**Proof**

명제1과 명제2에 의해 자명하다. $\quad {_\blacksquare}$

# Levi-Civita Tensor
다음 성질을 만족하는 $\epsilon_{ijk}$을 `Levi-Civita tensor` 혹은 `permutation tensor`라고 한다.
$$ \epsilon_{ijk} = \begin{cases} 1 & (i,j,k) \in \{ (1,2,3), (2,3,1), (3,2,1) \} \\ -1 & (i,j,k) \in \{ (3,2,1), (2,1,3), (1,3,2) \} \\ 0 & \text{otherwise} \end{cases} $$

### 명제1
$\epsilon$를 3차원 Levi-Civita tensor라 하자.

$a,b \in \R^3$에 대해 다음을 증명하여라.
$$ a \times b = \epsilon_{ijk}a^jb^k $$

**Proof**

직접 계산해보면 성립함을 알 수 있다. $\quad {_\blacksquare}$

### 명제2
$\epsilon$를 3차원 Levi-Civita tensor라 하자.

$A \in M_{33}(\R)$에 대해 다음을 증명하여라.
$$ \det(A) = \epsilon_{ijk}a_{i1}a_{j2}a_{k3} $$

**Proof**

$\det$의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} \det(A) &= A_{*1} \cdot A_{*2} \times A_{*3} \\&= A_{*1} \cdot (\epsilon_{ijk}a_{j2}a_{k3}) \\&= \epsilon_{ijk}a_{i1}a_{j2}a_{k3} \end{aligned} $$

### 명제3
$\epsilon$를 3차원 Levi-Civita tensor라 하자.

다음을 증명하여라.
$$ \epsilon_{ijk}\epsilon_{ilm} = \delta_{jl}\delta_{km} - \delta_{jm}\delta_{kl} $$

**Proof**

직접 계산해보면 성립함을 알 수 있다. $\quad {_\blacksquare}$

### 명제4
$\epsilon$를 3차원 Levi-Civita tensor라 하자.

다음을 증명하여라.
$$ \epsilon_{ijk}\epsilon_{jki} = 6 $$

**Proof**

$\epsilon$이 3차원임으로 cyclic order일 때, $+$ 값을 갖는다.

이 떄, $\epsilon_{ijk} ,\epsilon_{jki}$는 cyclic order임으로 같은 값을 갖는다.

따라서, $ijk$가 cyclic order여서 $1 \times 1$인 경우가 3번, $ijk$가 reverse cyclic order여서 $-1 \times -1$인 경우가 3번 해서 6이 된다. $\quad {_\blacksquare}$

> Reference  
> [Mathematics - odd-even-permutations](https://math.stackexchange.com/questions/361822/odd-even-permutations)  

### 명제5
$\epsilon$를 3차원 Levi-Civita tensor라 하자.

$x \in \R^3$일 떄, 다음을 증명하여라.
$$ \epsilon_{ijk}x_jx_k = 0 $$

**Proof**

명제1에 의해 다음이 성립한다.
$$ \begin{aligned} \epsilon_{ijk}x_jx_k &= x \times x \\&= 0 \quad {_\blacksquare} \end{aligned} $$

### 명제6
$\epsilon$를 3차원 Levi-Civita tensor라 하자.

$x,y,z \in \R^3$일 떄, 다음을 증명하여라.
$$ x \times (y \times z) = (x \cdot z)y - (x \cdot y)z  $$

**Proof**

명제1에 의해 다음이 성립한다.
$$ \begin{aligned} x \times (y \times z) &= \epsilon_{ijk}x_j \epsilon_{klm}y_lz_m \\&= \epsilon_{kij}\epsilon_{klm}x_jy_lz_m \end{aligned} $$

명제3에 의해 다음이 성립한다.
$$ \begin{aligned} x \times (y \times z) &= \epsilon_{kij}\epsilon_{klm}x_jy_lz_m \\&= (\delta_{il}\delta_{jm} - \delta_{im}\delta_{jl})x_jy_lz_m \\&= x_mz_my_i - x_jy_jz_i \\&= (x \cdot z)y - (x \cdot y)z \end{aligned} $$


# Isotropic Tensor

> Reference  
> [Blog - Isotropic Tensors](https://farside.ph.utexas.edu/teaching/336L/Fluid/node252.html)

## 2nd order symmetric unit tensor
$$ I = \delta_{ij}e_{ij} $$

## 4th order symmtric unit tensor
$$ I_{sym} = \frac{1}{2}(\delta_{ik}\delta_{jl} + \delta_{il}\delta_{jk})e_{ijkl} $$

### 명제
$A$가 second order tensor일 때, 다음을 증명하여라
$$ I_{sym}:A = \sym(A) $$

**Proof**

$$ \begin{aligned} I_{sym} : A &= \frac{1}{2}(\delta_{ik}\delta_{jl} + \delta_{il}\delta_{jk})A_{mn}\delta_{km}\delta_{ln} e_{ijmn} \\&= \frac{1}{2}(\delta_{ik}\delta_{jl} + \delta_{il}\delta_{jk})A_{kl} e_{ij} \\&= \frac{1}{2}(A_{ij} + A_{ji})e_{ij} \\&= \sym(A) \end{aligned} $$


## 4th order diffrential unit tensor
$$ I_{diff} = \delta_{ik}\delta_{jl}e_{ijkl} $$

## Deviatoric Tensor
$$ I_{dev} =  \left( \frac{1}{2}(\delta_{mp}\delta_{nq} + \delta_{mq}\delta_{np}) - \frac{1}{3}\delta_{mn}\delta_{pq} \right) e_{mnpq} $$


### 참고
$$ I_{dev} =  I_{sym} - \frac{1}{3}I \otimes I $$

### 명제1
다음을 증명하여라
$$ I_{diff} : I_{dev} = I_{dev} $$

**Proof**

$$ \begin{aligned} I_{diff} : I_{dev} &= \delta_{ik}\delta_{jl}e_{ijkl} : \left( \frac{1}{2}(\delta_{mp}\delta_{nq} + \delta_{mq}\delta_{np}) - \frac{1}{3}\delta_{mn}\delta_{pq} \right) e_{mnpq} \\&= \delta_{ik}\delta_{jl}\left( \frac{1}{2}(\delta_{mp}\delta_{nq} + \delta_{mq}\delta_{np}) - \frac{1}{3}\delta_{mn}\delta_{pq} \right) e_{ijkl} : e_{mnpq} \\&= \delta_{ik}\delta_{jl}\left( \frac{1}{2}(\delta_{mp}\delta_{nq} + \delta_{mq}\delta_{np}) - \frac{1}{3}\delta_{mn}\delta_{pq} \right) \delta_{kp}\delta_{lq} e_{ijmn} \\&= \delta_{ik}\delta_{jl} \left( \frac{1}{2}(\delta_{mk}\delta_{nl} + \delta_{ml}\delta_{nk}) - \frac{1}{3} \delta_{mn}\delta_{kl} \right) e_{ijmn} \\&= \left( \frac{1}{2}(\delta_{im}\delta_{jn} + \delta_{in}\delta_{jm}) - \frac{1}{3} \delta_{ij}\delta_{mn} \right) e_{ijmn} \\&= I_{dev} \end{aligned} $$

### 명제2
$A$가 second order tensor일 떄, 다음을 증명하여라.
$$ \tr(I_{dev}:A) = 0 $$

**Proof**

$$ \begin{aligned} \tr(I_{dev}:A) &= \tr(\sym(A) - \frac{1}{3}A_{kk}I) \\&= A_{ij}\delta_{ij} - \frac{1}{3}A_{kk}\delta_{ij}\delta_{ij} \\&= A_{ii} - A_{kk} \\&= 0  \end{aligned} $$

### 명제3
$A$가 second order tensor일 떄, 다음을 증명하여라.
$$ \frac{\partial I_{dev}:A}{\partial A} = I_{dev} $$

**Proof**

$$ \begin{aligned} \frac{\partial I_{dev}:A}{\partial A} &= \frac{\partial}{\partial A_{kl}} \bigg(\frac{1}{2}(A_{ij} + A_{ji}) - \frac{A_{kk}}{3}\delta_{ij}\bigg) e_{ijkl} \\&= \bigg( \frac{1}{2} (\delta_{ik}\delta_{jl} + \delta_{il}\delta_{jk}) - \frac{1}{3}\delta_{kl}\delta_{ij} \bigg)e_{ijkl} \\&= I_{dev}  \end{aligned} $$


### 명제4
$A$가 second order tensor일 때, 다음을 증명하여라.

$$ I_{dev} : A \text{ is symmetric} $$

**Proof**

$$ I_{dev} : A = \sym(A) - \frac{1}{3}A_{kk}I $$

$sym(A)$도 $I$도 symmetric tensor임으로 $I_{dev} : A$는 symmetric tensor이다. $\qed$



-
