# Metric
## 정의
집합 $M$이 있다고 하자.

 함수 $d : M \times M \rightarrow \R$가 다음을 만족할 때, $d$를 $M$의 `metric` 혹은 `거리함수(distance function)`라고 한다.

$\forall x,y,z \in M$에 대해,
1. $$ d(x,x) = 0 $$
2. $$ d(x,y) > 0 \text{ if } x \neq y $$ 
3. $$ d(x,y) = d(y,x) $$
4. $$ d(x,y) \le d(x,z) + d(z,y) $$


### 참고1
집합 $M$에 함수 $d$가 주어진 구조인 $(M,d)$를 `metric space`라고 한다.

### 참고2
$M = \R^n$이고 $d(x,y) = |x-y|$로 주어진 metric space를 $n$ 차원 `Euclidean metric space`라고 한다.

$n$ 차원 Euclidean metric space를 간단하게 $\R^n$으로 표기한다.

> Reference  
> {cite}`apostol` Chap 3.13

