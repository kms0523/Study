

### 명제1
$A \in M_{33}(\R)$이라 하자.

이 때, 다음을 증명하여라.
$$ \det(A) = A_{1*} \cdot (A_{2*} \times A_{3*}) $$

**Proof**

직접 계산하면 동일함을 알 수 있다. $\quad {_\blacksquare}$

#### 참고1
$\det(A) = \det(A^T)$임으로 행이 아닌 열에 대해서도 성립한다.
$$ \det(A) = A_{*1} \cdot (A_{*2} \times A_{*3}) $$

#### 참고2
Scalar triple product는 circular shift에 대해서 교환법칙이 성립함으로 다음이 성립한다.
$$ \det(A) = A_{1*} \cdot (A_{2*} \times A_{3*}) = A_{2*} \cdot (A_{3*} \times A_{1*}) = A_{3*} \cdot (A_{1*} \times A_{2*}) $$


> Referece  
> [Mathematics - Scalar triple product and determinant](https://math.stackexchange.com/questions/314275/scalar-triple-product-why-equivalent-to-determinant)  
> [Wiki - Triple product](https://en.wikipedia.org/wiki/Triple_product)

### 참고1

$$ A = \begin{bmatrix} a & b \\ c & d \end{bmatrix}, \quad \det(A) = ad - bc $$

$\det(A)$는 $A$의 행 벡터들에 의해 생성되는 부호있는 부피이다.

따라서 $\det(A) = 0$이라는 말은 행 벡터들이 선형 독립이 아니라서 의미있는 부피(차원)을 만들어내지 못한다는 말이다.

#### 명제1
$\det(A) = \det(A^T)$

이로써 $\det(A)$가 열 벡터들에 의해 생성되는 부호있는 부피이기도 하다는것을 알 수 있다.

**proof**

#### 명제2
$\det(AB) = \det(A)\det(B)$

**proof**

### 라플라스 전개

$\det(A) = \sum _{k=1}^n a_{kj}M_{kj}$