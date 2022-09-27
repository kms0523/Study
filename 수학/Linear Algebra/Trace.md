
### 명제1
$A \in M_{nn}(\R)$이라 하면 다음이 성립한다.
$$ \text{tr}(A^2) = \sum_{i=1}^n \sum_{j=1}^n A_{ij}A_{ji} $$

**Proof**

직접 계산하면 동일함을 알 수 있다. $\quad {_\blacksquare}$

### 명제2
$A \in M_{nn}(\R)$이라 하자.

$A$가 symmetric metrix일 때, 다음을 증명하여라.
$$ A : A = \text{tr}(A^2) $$

**Proof**

$$ \begin{aligned} A : A &= A_{ij}A_{ij} \\&= A_{ij}A_{ji} \\&= \text{tr}(A^2) \quad {_\blacksquare} \end{aligned} $$

### 명제3
$A \in M_{nn}(\R)$가 symmetric metrix라 하자.

$A \sim B$일 때, 다음을 증명하여라.
$$ A : A = B : B $$

**Proof**

$$ \begin{aligned} A : A &= \text{tr}(A^2) \\ &= \text{tr}(B^2) \\ &= B : B\quad {_\blacksquare} \end{aligned} $$


> Referece  
> [Wiki - Trace](https://en.wikipedia.org/wiki/Trace_(linear_algebra))