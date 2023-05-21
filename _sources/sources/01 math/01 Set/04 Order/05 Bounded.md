# Bounded
POSET $X$와 $X$의 부분집합 $U$가 있다고 하자.

## Bounded from Above
다음이 성립할 때 $U$를 `위로 유계(bounded from above)`되었다고 한다.

$$ \exist M \in X \st \forall u \in U, \quad u \le M $$

> Reference  
> [wiki](https://en.wikipedia.org/wiki/Upper_and_lower_bounds)

### 참고1(Upper Bound)
$U$가 bounded from above일 때, 다음을 만족하는 $M \in X$를 $U$의 `upper bound`라고 한다.

$$ \forall u \in U, \quad u \le M $$

### 참고2
$U$의 greatest element는 $U$의 element이지만 $U$의 upper bound는 $X$의 element이다.

즉, upper bound는 $U$의 element가 아닐 수 있다.

### 참고3
$U = \empty$인 경우, $\forall u \in U$가 항상 거짓임으로 공허하게 참인 명제가 된다.

따라서, 다음이 성립한다.

$$ \forall x \in X, \quad x \text{ is an upper bound of } U $$

### 명제1
POSET $X$와 $X$의 부분집합 $U$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ U \text{ has a greatest element } u \implies \begin{gathered} U \text{ is bounded from above} \\ u \text{ is a upper bound of } U \end{gathered} $$

**Proof**

greatest element의 정의에 의해 자명하다. $\qed$

### 명제2
POSET $X$와 $X$의 부분집합 $U$가 있다고 하자.

$M$을 $U$의 upper bound라고 할 떄, 다음을 증명하여라.

$$ M \in U \implies M \text{ is a greatest element of } U $$

**Proof**

greatest element의 정의에 의해 자명하다. $\qed$

## Bounded from Below
다음이 성립할 때 $U$를 `아래로로 유계(bounded from below)`라고 한다.

$$ \exist m \in X \st \forall u \in U, \quad m \le u $$

> Reference  
> [wiki](https://en.wikipedia.org/wiki/Upper_and_lower_bounds)

### 참고1(Lower Bound)
$U$가 bounded from below일 때, 다음을 만족하는 $M \in X$를 $U$의 `lower bound`라고 한다.

$$ \forall u \in U, \quad m \le u $$

### 참고2
$U$의 least element는 $U$의 element이지만 $U$의 lower bound는 $X$의 element이다.

즉, lower bound는 $U$의 element가 아닐 수 있다.

### 명제1
POSET $X$와 $X$의 부분집합 $U$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ U \text{ has a least element } u \implies \begin{gathered} U \text{ is bounded from below} \\ u \text{ is a lower bound of } U \end{gathered} $$

**Proof**

least element의 정의에 의해 자명하다. $\qed$

### 명제2
POSET $X$와 $X$의 부분집합 $U$가 있다고 하자.

$m$을 $U$의 lower bound라고 할 떄, 다음을 증명하여라.

$$ m \in U \implies m \text{ is a least element of } U $$

**Proof**

least element의 정의에 의해 자명하다. $\qed$