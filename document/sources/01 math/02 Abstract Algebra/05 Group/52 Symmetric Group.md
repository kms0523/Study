# Symmetric Group
## Definition
finite set $X$가 있다고 하자. 

set $S_X$를 다음과 같이 정의하자.

$$ S_X := \Set{f : X \rightarrow X | f \text{ is bijective}} $$

이 때, $(S_X,\circ)$를 $X$위의 `대칭군(symmetric group)`이라고 한다.

### 명제1
다음을 증명하여라.

$$ (S_X,\circ) \text{ is a group} $$

**Proof**

[closed]  
$S_X$의 임의의 elements를 $f,g$라고 하면 다음이 성립한다.

$$ f\circ g : f \rightarrow f \in S_X  \qed $$

[identity]  
$S_X$의 임의의 elements를 $f$라고 하면 $id_X \in S_X$임으로 다음이 성립한다.

$$ f \circ id_X = id_X \circ f = f $$

따라서, $id_X$는 $(S_X,\circ)$의 identity element이다. $\qed$

[inverse]  
$S_X$의 임의의 elements를 $f$라고 하면 $f^{-1} \in S_X$임으로 다음이 성립한다.

$$ f \circ f^{-1} = f^{-1} \circ f = id_X $$

따라서, $(S_X,\circ)$의 모든 element는 inverse element를 갖는다.$\qed$


