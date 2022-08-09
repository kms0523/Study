# Manifold

다음과 같은 집합이 주어졌다고 하자.
$$ \R^n := \{ (x_1, \cdots, x_n) | x_i \in \R \} $$

$\R^n$은 벡터공간이다.

다음과 같이 정의된 내적 $\lang \cdot , \cdot \rang$이 주어졌다고 하자.
$$ a,b \in \R^n, \quad \lang a,b \rang = a^ib_i$$

$(\R^n, \lang \cdot , \cdot \rang)$을 통해 공간을 일반화한것이 `다양체(Manifold)`이다.


## chart
$M$을 smooth manifold라고 하자. 

$M$위의 임의의 원소 $p \in M$가 있을 때, $V_p \subset M$는 P를 포함하는 $M$의 부분집합이며 $B(0,r)$은 $\R^n$ 집합에서 원점이 0이고 반지름이 $r$인 원 내부에 있는 점의 집합이라고 하자.

이 때, 다음과 같은 함수가 존재한다고 가정하자.
$$\varphi_p : V_p \rightarrow B(0,r) \land  \varphi_p \text { is homeomorphism} $$

여기서 `homeomorphism`이란 두개의 topological space를 정의역과 공역으로 갖고 역함수가 smooth function$(\in C^\infty)$인 함수이다. (역함수가 존재하기 때문에 homeomorphism 함수는 전단사함수이고, 역함수가 smooth function이기 때문에 homeomorphism함수 또한 smooth function이다)

가정에 의해 존재성이 보장된 $\varphi_p$를 `chart`라고 하며 $\varphi_p$는 모든 $p \in M$마다 존재한다. 따라서 $\varphi_p$는 $p$에 의존하는 함수이며 각 $p$마다 $\varphi_p$에 의해 Manifold의 부분집합 $V_p$를 $\R^n$집합으로 볼 수 있다.



점 $p$에서 $\varphi_p$의 존재성은 강제하지만 유일성은 강제하지 않는다. 따라서 다양한 chart가 존재할 수 있고 그 chart에 따라서 계산값이 바뀔 수 있다. 따라서 수학적으로 chart에 따라서 값이 변하지 않는것들을 유의미하다고 본다.

> 참고  
> [relationship-between-covariant-contravariant-basis-vectors - Mathematics](https://math.stackexchange.com/questions/393316/relationship-between-covariant-contravariant-basis-vectors)

## Tangent space
점 $p \in M$에서 `tangent space`를 $T_pM$이라고 한다. $T_pM$은 점 $p$에서 $M$에 접하는 모든 벡터들의 집합이며, 벡터공간이 된다. $T_pM$이 벡터공간임으로 dual space를 갖으며 $T_pM^*$을 `cotangent space`라고 한다.


### 명제1
$T_x\R^n$의 basis가 $\frac{\partial}{\partial x_i}$임을 보여라.




> 참고  
> [relationship-between-covariant-contravariant-basis-vectors - Mathematics](https://math.stackexchange.com/questions/393316/relationship-between-covariant-contravariant-basis-vectors)  
> [why-are-the-partial-derivatives-a-basis-of-the-tangent-space - Mathematics](https://math.stackexchange.com/questions/3330025/why-are-the-partial-derivatives-a-basis-of-the-tangent-space)  
> [what-is-the-affine-space-and-what-is-it-for - Mathematics](https://math.stackexchange.com/questions/1545889/what-is-the-affine-space-and-what-is-it-for)  
> [basis-for-the-tangent-space-and-derivations-at-a-point - Mathematics](https://math.stackexchange.com/questions/3350081/basis-for-the-tangent-space-and-derivations-at-a-point)  
> [coordinate-basis-of-tangent-space - Mathematics](https://math.stackexchange.com/questions/3294659/coordinate-basis-of-tangent-space)  

---

2번조건
$$ \forall p \in M, \exist \varphi_1 : v_p \rightarrow B(0,r_1), \exist \varphi_2 : u_p \rightarrow B(0,r_2) $$

$$ \varphi_2 \circ (\varphi_1)^{-1} : \R^n \rightarrow \R^n, \quad \text{bijective,} \quad \varphi_2 \circ (\varphi_1)^{-1}, (\varphi_2 \circ (\varphi_1)^{-1})^{-1} \in C^\infty $$

1번조건과 2번조건을 만족할 때, M