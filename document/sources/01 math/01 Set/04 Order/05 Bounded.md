# Bounded
POSET $X$와 $X$의 부분집합 $U$가 있다고 하자.

## Bounded from Above
다음이 성립할 때 $U$를 `위로 유계(bounded from above)`되었다고 한다.

$$ \exist M \in X \st \forall u \in U, \quad u \le M $$

> Reference  
> [wiki](https://en.wikipedia.org/wiki/Upper_and_lower_bounds)


### Upper Bound
$U$가 bounded from above일 때, 다음을 만족하는 $M \in X$를 $U$의 `upper bound`라고 한다.

$$ \forall u \in U, \quad u \le M $$

#### 참고1
$U$의 greatest element는 $U$의 element이지만 $U$의 upper bound는 $X$의 element이다.

즉, upper bound는 $U$의 element가 아닐 수 있다.

#### 참고2
만약 $M \in U$이면 greatest element의 정의에 의해 다음이 성립한다.

$$ M \text{ is a greatest element of } U $$


## Bounded from Below
다음이 성립할 때 $U$를 `아래로로 유계(bounded from below)`라고 한다.

$$ \exist m \in X \st \forall u \in U, \quad m \le u $$

> Reference  
> [wiki](https://en.wikipedia.org/wiki/Upper_and_lower_bounds)


### Lower Bound
$U$가 bounded from below일 때, 다음을 만족하는 $x \in X$를 $U$의 `lower bound`라고 한다.

$$ \forall u \in U, \quad m \le u $$

#### 참고1
$U$의 least element는 $U$의 element이지만 $U$의 lower bound는 $X$의 element이다.

즉, lower bound는 $U$의 element가 아닐 수 있다.

#### 참고2
만약 $m \in U$이면 least element의 정의에 의해 다음이 성립한다.

$$ m \text{ is a least element of } U $$