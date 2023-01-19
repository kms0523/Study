# Sumpremum and Infimum
POSET $X$와 $X$의 subset $U$가 있다고 하자.

## Supremum
$U$가 bounded from above일 때, $U$의 upper bound의 집합을 $S$라고 하자.

이 떄, $S$의 least element를 $U$의 `least upper bound, supremum`이라고 한다.

> Reference  
> [wiki](https://en.wikipedia.org/wiki/Infimum_and_supremum)

### 명제1
POSET $X$와 $X$의 bounded from above subset $U$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ \sup(U) \in U \implies \sup(U) \text{ is an greatest elemt of } U $$

**Proof**

supremum과 greatest element의 정의에 의해 자명하다. $\qed$

### 명제2
POSET $X$와 $X$의 bounded from above subset $U$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ \begin{gathered} \exist\sup(U) \\ u \text{ is greatest element of } U \end{gathered} \implies u = \sup(U) $$

**Proof**

supremum은 upper bound임으로 다음이 성립한다.

$$ \forall u \in U, \quad u \le \sup(U) $$

또한 Greatest element의 성질에 의해 다음이 성립한다.

$$ u \text{ is an upper bound of } U $$

그러면 supremum의 정의에 의해 다음이 성립한다.

$$ \sup(U) \le u $$

위의 결과를 종합하면 partial order의 antisymmetric 성질에 의해 다음이 성립한다.

$$ u = \sup(U) \qed $$

## Infimum
$U$가 bounded from below일 때, $U$의 least bound의 집합을 $S$라고 하자.

이 떄, $S$의 maximal element를 $U$의 `greatest lower bound, infimum`이라고 한다.

> Reference  
> [wiki](https://en.wikipedia.org/wiki/Infimum_and_supremum)

### 명제1
POSET $X$와 $X$의 bounded below subset $U$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ \inf(U) \in U \implies \inf(U) \text{ is an least elemt of } U $$

**Proof**

infimum과 least element의 정의에 의해 자명하다. $\qed$

### 명제2
POSET $X$와 $X$의 bounded from below subset $U$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ \begin{gathered} \exist\inf(U) \\ u \text{ is least element of } U \end{gathered} \implies u = \inf(U) $$

**Proof**

infimum은 lower bound임으로 다음이 성립한다.

$$ \forall u \in U, \quad \inf(U) \le u $$

또한 least element의 성질에 의해 다음이 성립한다.

$$ u \text{ is an lower bound of } U $$

그러면 infimum의 정의에 의해 다음이 성립한다.

$$ u \le \inf(U) $$

위의 결과를 종합하면 partial order의 antisymmetric 성질에 의해 다음이 성립한다.

$$ u = \inf(U) \qed $$