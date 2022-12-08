# General Linear Group
역행렬이 존재하는 행렬의 집합을 $S$라 하자.
$$ S := \{ m \in M_{nn}(\mathbb F) \enspace | \enspace \det(m) \neq 0 \} $$

`General linear group` $GL(n, \mathbb F)$은 집합 $S$에 binary operation으로 행렬의 곱이 주어진 group이다.
$$ GL(n; \mathbb F) = (S, \times) $$

# Converge
$M_{nn}(\mathbb F)$위의 수열 $s(m)$이 있다고 하자.

$\lim_{m \rightarrow \infty} s(m) = A \in M_{nn}(\mathbb F)$은 다음과 동치이다.
$$ \lim_{m \rightarrow \infty} s(m)_{ij} = A_{ij} $$

즉, 각각의 component가 $A$의 component로 수렴한다는 의미이다.

# Matrix Lie Group
$G \le GL(n; \mathbb F)$이 있다고 하자.

$G$위의 임의의 sequence $s(m)$이 있을 때, 다음이 성립한다고 하자.
$$ \lim_{m \rightarrow \infty} s(m)\in G $$

이 떄, $G$를 `matrix Lie group`이라 한다.

### 참고
$G$가 matrix Lie group일 경우, $G$위의 임의의 sequence가 전부 $G$로 수렴함으로 matrix Lie group은 $GL(n;\mathbb F)$의 closed subgroup이다.