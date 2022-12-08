
### 명제1

$$ \sum_i^n \sum_j^m a_i b_j  = \sum_i^n a_i \sum_j^m b_j = \sum_j^m b_j \sum_i^n a_i = \sum_j^m \sum_i^n a_i b_j $$

**proof**

곱셈은 덧셈에 대해 분배법칙이 성립함으로 다음이 성립한다.

$$ \sum_i^n \sum_j^m a_i b_j = \sum_i^n \left( a_i \sum_j^m b_j \right) = \sum_i^n a_i \sum_j^m b_j $$

다음의 표를 보자.

$$ \begin{matrix} a_1b_1 & \cdots & a_1 b_m &  & a_1 \displaystyle \sum_{j=1}^m b_j \\ \vdots & & \vdots & & \vdots  \\  a_nb_1 & \cdots & a_n b_m &  & a_1 \displaystyle \sum_{j=1}^m b_j \\ b_1 \displaystyle \sum_{i=1}^n a_i & \cdots & b_m \displaystyle \sum_{i=1}^n a_i \end{matrix} $$

행의 합 $(\sum_i^n a_i \sum_j^m b_j)$은 열의 합$(\sum_j^m b_j \sum_i^n a_i)$과 같다.

또한 곱셈의 덧셈에 대한 분배법칙에 의해 다음이 성립한다.

$$\sum_j^m b_j \sum_i^n a_i = \sum_j^m \left( b_j \sum_i^n a_i \right) = \sum_j^m \sum_i^n a_i b_j  $$