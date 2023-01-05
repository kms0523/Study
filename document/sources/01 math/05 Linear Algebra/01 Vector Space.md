# Vector Space
## 정의
Abelian group $V$와 field $\F$가 있다고 하자.

`벡터공간(vector space)` $V/\F$란, $\F-$module이다.

### 명제1
Non empty set $S$와 field $\F$가 있다고 하자.

이 떄, 집합 $F$를 다음과 같이 정의하자.

$$ F:= \Set{f:S\rightarrow\F} $$

$F$의 binary operator $+$가 다음과 같이 정의되어 있다고 하자.

$$ \forall f,g \in F, \quad \forall s \in S, \quad (f+g)(s) = f(s) + g(s) $$

Action of $\F$ on $F$ $\cdot$은 다음과 같이 정의되어 있다고 하자.

$$ \forall c \in \F, \quad \forall f \in F, \quad \forall s \in S, \quad  (cf)(s) = cf(s) $$

이 떄, 다음을 증명하여라.

$$ F \text{ is a vector space over } \F $$

**Proof**

[$F$ is an Abellian group]  
-[commutative]
$F$의 정의에 의해 다음이 성립한다.

$$ \forall f,g \in F, \quad \forall s \in S, \quad f(s), g(s) \in \F $$

Field의 정의에 의해 $\F$는 commutative함으로 다음이 성립한다.

$$ \forall f,g \in F, \quad \forall s \in S, \quad (f+g)(s) = f(s) + g(s) = g(s) + f(s) = (g+f)(s) $$

따라서, $+_F$는 commtative binary operation이다. $\qed$

-[closed]
$F$의 정의에 의해 다음이 성립한다.

$$ \forall f,g \in F, \quad \forall s \in S, \quad f(s), g(s) \in \F $$

따라서, 다음이 성립한다.

$$ \forall f,g \in F, \quad \forall s \in S, \quad (f+g)(s) \in \F $$

그럼으로 $F$의 정의에 의해 다음이 성립한다.

$$ (f+g) \in F \qed $$

-[identity element]
$0_F$를 다음과 같이 정의하자

$$ 0_F : S \rightarrow \F \st s \mapsto 0_\F $$

그러면 정의에 의해 다음이 성립한다.

$$ \forall f \in F, \quad \forall s \in S, \quad (f+0_\F)(s) = f(s) + 0_\F(s) = f(s) $$

따라서, 다음이 성립한다.

$$ \forall f \in F, \quad f + 0_\F = f $$

그럼으로 identity element의 정의에 의해 다음이 성립한다.

$$ 0_F \text{ is an identity element of } F $$

-[inverse element]

$f \in F$가 있다고 하자.

이 떄, $-f$를 다음과 같이 정의하자.

$$ -f : S \rightarrow \F \st s \mapsto f(s)^{-1} $$

그러면 정의에 의해 다음이 성립한다.

$$ \forall s \in S, \quad (f+(-f))(s) = f(s) + (-f(s)) = 0_\F $$

그럼으로 inverse element의 정의에 의해 다음이 성립한다.

$$ \forall f \in F, \quad -f \text{ is an inverse element} \qed $$

[결론]
$F$가 Abelian group이고 $\F$는 commutative ring임으로 다음이 성립한다.

$$ F \text{ is a } \F-\text{module} $$

따라서, vector space의 정의에 의해 다음이 성립한다.

$$ F \text{ is a vector space over } \F \qed $$

#### 참고
$F$의 binary operator $+$를 정의한 방식을 `pointwise addition`이라 하고 Action of $\F$ on $F$ $\cdot$을 정의한 방식을 `pointwise scalar multiplication`이라고 한다.