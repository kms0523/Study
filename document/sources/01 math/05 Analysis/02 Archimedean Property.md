# Archimedean Property
## 정의
Ordered field $\F$가 다음을 만족할 때, `archimedean property`를 갖는다고 한다.

$$ \forall x \in \F, \quad \exist n \in \N \st x < n $$

### 명제1
Archimedean property를 만족하는 Ordered field $\F$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ \forall x \in \F^+ \implies \exist n \in \N \st \frac{1}{n} < x  $$

**Proof**

Archimedean property에 의해 다음이 성립한다.

$$ \begin{aligned} & \forall y \in \F^+ \\\implies& \exist n \in \N \st y < n \\\implies& \exist n \in \N \st \frac{1}{n} < \frac{1}{y} \end{aligned} $$

$x = 1/y $로 두면, $x \in \F^+$임으로 다음이 성립한다.

$$ \forall x \in \F^+ \implies \exist n \in \N \st \frac{1}{n} < x \qed  $$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/61630/archimedean-property-of-the-rational-numbers)