# Archimedean Property
## 정의
Ordered field $\F$가 다음을 만족할 때, `archimedean property`를 갖는다고 한다.

$$ \forall x \in \F, \quad \exist n \in \N \st x < n $$

### 명제1
Archimedean property를 만족하는 Ordered field $\F$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ \forall x \in \F^+ \implies \exist n \in \N \st \frac{1}{n} < x  $$

**Proof**

Archimedean property와 ordered field의 성질에 의해 다음이 성립한다.

$$ \forall y \in \F^+\implies \exist n \in \N \st \frac{1}{n} < \frac{1}{y} $$

$x = 1/y $로 두면, $x \in \F^+$임으로 다음이 성립한다.

$$ \forall x \in \F^+ \implies \exist n \in \N \st \frac{1}{n} < x \qed  $$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/61630/archimedean-property-of-the-rational-numbers)


### 명제2
다음을 증명하여라.

$$ \Q \text{ has an archimedean property} $$

**Proof**

$x \in \Q$가 있다고 하자.

만약 $x \in \Q^-_0$면 모든 자연수가 $x$보다 큼으로 다음이 자명하게 성립한다.

$$ \forall x \in \Q^-_0, \quad \exist n \in \N \st x < n $$


다음으로 $x\in \Q^+$인 경우를 보자.

$\Q^+$의 정의에 의해  다음이 성립한다.

$$ \forall x \in \Q^+, \quad \exist n,m \in \N \st x = \frac{n}{m} $$

따라서, 다음이 성립한다.

$$ mx = n $$

$\forall n \in \N, \quad x \le nx$임으로 다음이 성립한다.

$$ x \le mx \implies x \le n $$

따라서, 다음이 성립한다.

$$ \forall x \in \Q^+, \quad x < n+1 $$

$n+1 \in \N$임으로 다음이 성립한다.

$$ \forall x \in \Q^+, \quad \exist n \in \N \st x < n $$

$\Q = \Q^-_0 \cup \Q^+$임으로 위의 결과를 종합하면 다음이 성립한다.

$$ \forall x \in \Q \implies \exist n \in \N \st x < n $$


### 명제3
다음을 증명하여라.

$$ \R \text{ has an archimedean property} $$

**Proof**

다음을 가정하자.

$$ \R \text{ does not have an archimedean property} $$

그러면 다음이 성립한다.

$$ \exist M \in \R \st \forall n \in N, \quad n \le M $$

따라서 $M$은 $\N$의 upper bound임으로 다음이 성립한다.

$$ \N \text{ is bounded above} $$

$\R$의 axiom of completeness에 의해 다음이 성립한다.

$$ \exist \sup(\N) \in \R $$

이 때, $\N$은 $\R$의 subset임으로 $\R$의 성질에 의해 다음이 성립한다.

$$ \exist y \in \R \st \sup(\N) - 1 < y $$
