# Subgroup
## 정의
Group $G$와 $G$의 부분집합 $H$가 있다고 하자.

$(H,*_G)$가 군이 되면 $H$를 $G$의 `부분군(subgroup)`이라고 하고 $H\le G$로 표기한다.  

### 명제1
Group $G$와 $G$의 subset $H$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ H\le G \iff ( \forall a,b\in H, \quad a*_Gb\in H ) \land ( \forall c \in H, \quad  c^{-1} \in H ) $$

**proof**

[$\implies$]  
$H$는 group이기 때문에, semi-group의 성질 또한 만족한다.

따라서 $*_G|_{(H\times H)}$가  $H$위의 binary operation이 되어야 함으로 다음이 성립한다.

$$ \forall a,b\in H, \quad a*_Gb\in H $$

또한, group의 정의에 의해 inverse element가 존재해야 함으로 다음이 성립한다.

$$ \forall c \in H, \quad  c^{-1} \in H \qed $$

[$\impliedby$]  
첫번째 전제에 의해 $*$가 $H$위의 binary operation임으로 다음이 성립한다.

$$ H \text{ is a semi group} $$

두번째 전제에 의해 inverse element가 존재함으로, inverse element의 정의에 의해 다음이 성립한다.

$$ \exist e_H \in H $$

따라서 $H$는 monoid이고, 두번째 전제에 의해 모든 원소에 inverse element가 존재함으로 다음이 성립한다.

$$ H \text{ is a group} $$

$H$가 group임으로 subgroup의 정의에 의해 다음이 성립한다.

$$ H \le G \qed $$


### 명제2
Group $G$와 $G$의 subgroup $H$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ e_H = e_G $$

**Proof**

$H \subseteq G$임으로 다음이 성립한다.

$$ e_H, e_G \in G $$

$\forall x \in H$에 대해서, $x \in G$임으로 다음이 성립한다.

$$ x+e_H = x + e_G $$

이 떄, group의 cancellation law에 의해 다음이 성립한다.

$$ e_H = e_G \qed $$

### 예시
$$(\mathbb{Q},+) \le (\R,+) \\ (\mathbb{Q}-\{0\},\times) \le (\R-\{0\},\times)$$