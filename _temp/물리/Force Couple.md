# Force Couple
`Force couple`이란 resultant moment는 존재하지만 resultant force는 없는 system이다.

> Reference  
> [Wiki - Couple](https://en.wikipedia.org/wiki/Couple_(mechanics))

### 명제
Force couple이 있다고 하자.

moment의 기준이 되는 점을 reference point라 할 때, 다음을 증명하여라.
$$ \text{couple is independent of the reference point} $$

**Proof**

임의의 기준점 $p$와 힘 $f_i$가 작용하는 점 사이의 vector를 $r_i$라 하면 다음이 성립한다.
$$ M_{p} = \sum_{i=1}^N r_i \times f_i $$

이 때, 새로운 기준점을 $q$라 하고 $p$와 $q$사이의 vector를 $r$이라 하면 다음이 성립한다.
$$ \begin{aligned} M_p &= \sum_{i=1}^N (r_i + r) \times f_i \\ &= \sum_{i=1}^N r_i \times f_i + r \times \sum_{i=1}^N  f_i \end{aligned} $$

couple인 경우에는 resultant force가 0임으로 다음이 성립한다.
$$ M_p = M_q \quad {_\blacksquare} $$

> Reference  
> [Wiki - Couple](https://en.wikipedia.org/wiki/Couple_(mechanics))

# Simple Couple
`Simple couple`은 크기는 같고 방향은 반대이면서 평행한 line of action을 갖는 두 force로 이루어진 system이다.

> Reference  
> [Wiki - Couple](https://en.wikipedia.org/wiki/Couple_(mechanics))