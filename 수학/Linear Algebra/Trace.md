### 명제1
$A,B \in M_{nn}(\R)$이라 하자.

이 떄, 다음을 증명하여라.
$$ \text{tr}(AB) = \sum_{i=1}^n \sum_{j=1}^n A_{ij}B_{ji} $$

**Proof**

직접 계산하면 동일함을 알 수 있다. $\quad {_\blacksquare}$

### 명제2
$A \in M_{nn}(\R)$이라 하자.

$A$가 symmetric metrix일 때, 다음을 증명하여라.
$$ A : A = \text{tr}(A^2) $$

**Proof**

$$ \begin{aligned} A : A &= A_{ij}A_{ij} \\&= A_{ij}A_{ji} \\&= \text{tr}(A^2) \quad {_\blacksquare} \end{aligned} $$

#### 따름명제
$A \in M_{nn}(\R)$가 symmetric metrix라 하자.

$A \sim B$일 때, 다음을 증명하여라.
$$ A : A = B : B $$

**Proof**

$$ \begin{aligned} A : A &= \text{tr}(A^2) \\ &= \text{tr}(B^2) \\ &= B : B\quad {_\blacksquare} \end{aligned} $$

### 명제4
$A,B \in M_{nn}(\R)$이라 하자.

이 떄, 다음을 증명하여라.
$$ \text{tr}(AB) = \text{tr}(BA) $$

**Proof**

$$ \begin{aligned} \text{tr}(AB) &= \sum_{i=1}^n \sum_{j=1}^n A_{ij}B_{ji} \\ &= \sum_{j=1}^n \sum_{i=1}^n B_{ji}A_{ij} \\&= \text{tr}(BA) \quad {_\blacksquare} \end{aligned} $$



> Referece  
> [Wiki - Trace Notes1](https://en.wikipedia.org/wiki/Trace_(linear_algebra))