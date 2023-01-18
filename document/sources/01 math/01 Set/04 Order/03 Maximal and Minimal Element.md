# Minimal and Maximal Element
Poset $X$가 있다고 하자.

## Maximal Element
$M \in X$가 다음을 만족할 때, $M$을 $X$의 maximal element라고 한다.

$$ M \le x \implies x \le M $$

> Reference  
> [wiki](https://en.wikipedia.org/wiki/Maximal_and_minimal_elements#Definition)

## Minimal Element
$M \in X$가 다음을 만족할 때, $M$을 $X$의 minimal element라고 한다.

$$ x \le M \implies M \le x $$

> Reference  
> [wiki](https://en.wikipedia.org/wiki/Maximal_and_minimal_elements#Definition)

### 참고
Maximal element와 minimal element는 존재성과 유일성이 보장되지 않는다.

1. $S=[1,\infty)$는 maximal element를 갖지 않는다.
2. $S=\Set{s\in\Q |1\le s^2\le 2 }$는 maximal element를 갖지 않는다.
3. fence $S = \Set{ a_i,b_i |a_1 \le b_1 \ge a_2 \le b_2 \ge \cdots, a_i \neq b_i}$에서 모든 $a_i$는 mimal element이며 모든 $b_i$는 maximal element이다.