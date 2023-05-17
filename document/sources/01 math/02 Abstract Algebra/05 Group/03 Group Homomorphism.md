# Group Homomorphism
## Definition
Group $G_1,G_2$가 있다고 하자.

이 때, 함수 $f : G_1\rightarrow G_2$가 다음을 만족할 때, $f$를 `군 준동형사상(group homomorphism)`이라고 한다.

$$ \forall a,b \in G_1, \enspace f(a*_1 b) = f(a) *_2 f(b) $$

### 예제
$\exp : (\R,+) \rightarrow (\R,\times)$

### 명제1
Group $G_1,G_2$와 group homomorphism $f : G_1 \rightarrow G_2$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ f(e_{G_1}) = e_{G_2} $$

**Proof**

$$ \begin{gathered}f(e_{G_1}*e_{G_1}) = f(e_{G_1})*f(e_{G_1}) \\f(e_{G_1}*e_{G_1}) = f(e_{G_1}) \end{gathered} \implies f(e_{G_1}) = e_{G_2} \qed $$

### 명제2
Group $G_1,G_2$와 group homomorphism $f : G_1 \rightarrow G_2$가 있다고 하자.

$G_1$의 임의의 element를 $a$라고 할 때, 다음을 증명하여라.

$$ f(a^{-1}) = f(a)^{-1} $$

**Proof**

$$ \begin{gathered} f(a*a^{-1}) = f(a)*f(a^{-1}) = e_{G_2} \\ f(a^{-1}*a) = f(a^{-1})*f(a) = e_{G_2} \end{gathered} \implies f(a^{-1}) = f(a)^{-1} \qed  $$

## Group Monomorphism
Group $G_1,G_2$와 group homomorphism $f : G_1 \rightarrow G_2$가 있다고 하자.

$f$가 injective일 때, $f$를 `group monomorphism`이라고 한다.

## Group Epimorphism
Group $G_1,G_2$와 group homomorphism $f : G_1 \rightarrow G_2$가 있다고 하자.

$f$가 surjective일 때, $f$를 `group epimorphism`이라고 한다.

## Group Isomorphism
Group $G_1,G_2$와 group homomorphism $f : G_1 \rightarrow G_2$가 있다고 하자.

$f$가 bijective일 때, $f$를 `group isomorphism`이라고 한다.

### 참고
1. 집합에서는 bijective function만 있으면 두 set을 같게 볼 수 있었다면 이제는 group structure까지 보존해야 두 group을 같게 볼 수 있다.
2. $G_1,G_2$를 group isomorphic하다고 한다.
3. $G_1,G_2$를 같은 group structure를 가지고 있다고 한다.

