# Normal Subgroup

## Example1
Normal subgroup이 아닌 subgroup을 찾아보자.

$M := \Set{m \in M_{22}(\R) | \det(m) \neq 0}$라고 할 때, $(M,\times)$은 group이다.

이 때, $M$의 subgroup $H$을 다음과 같이 정의하자.

$$ H= \Braket{\begin{bmatrix} 1&1\\0&1 \end{bmatrix}} = \Set{\begin{bmatrix} 1&k\\0&1 \end{bmatrix} \mid k \in \Z} $$

그러면 $ m = \begin{bmatrix} 2&1\\1&1 \end{bmatrix} \in M$과 $ h =\begin{bmatrix} 1&1\\0&1 \end{bmatrix} \in H$에 대해 다음이 성립한다.

$$ mhm^{-1} = \begin{bmatrix} -1&1\\-1&3 \end{bmatrix} \notin H $$

따라서, $H$는 normal subgroup이 아닌 subgroup이다.

## Example2
symmetric group

## Importance
Group $G$와 normal subgroup $N$이 있다고 하자.

그러면 $N$의 성질에 의해 $G/N$은 quotient group이 된다.

$G/N$은 일반적으로 $G$보다 단순한 구조를 가지고 있으며, 이를 통해 $G$의 복잡한 구조를 이해하는 한가지 좋은 방법을 제공한다.

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/2626414/importance-of-normal-subgroups)