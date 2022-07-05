# Affine space
집합 $A$와 벡터 공간 $V/\mathbb F$이 있을 때, 다음과 같은 이항연산이 있다고 하자.
$$ + : A \times V \rightarrow A $$

$+$가 다음 성질들을 만족한다고 하자.
$$ \begin{aligned} 1) \quad & \forall a \in A \Rightarrow a + 0_V = a \\ 2) \quad & v_1, v_2 \in V \land a \in A \Rightarrow (a + v_1) + v_2 = a + (v_1 + v_2) \\ 3) \quad & a \in A, \quad \exist f:V \rightarrow A \quad s.t. \quad v \mapsto a + v \quad \land \quad f \text{ is bijective} \end{aligned} $$

`Affine space`란 집합 $A$에 벡터 공간 $V$와 $+$가 주어진 구조이다.

$+$의 1), 2) 성질은 right group action을 정의하고 있다.

### 명제1
$+$의 3번 성질이 다음과 동치임을 증명하여라.
$$ (a,b) \in A^2, \quad \exist! v \in V \quad s.t. \quad b = a+v$$

### 명제2


> 참고  
> [what-are-differences-between-affine-space-and-vector-space - mathematics](https://math.stackexchange.com/questions/884666/what-are-differences-between-affine-space-and-vector-space)  


# Manifold

다음과 같은 집합이 주어졌다고 하자.
$$ \R^n := \{ (x_1, \cdots, x_n) | x_i \in \R \} $$

$\R^n$은 벡터공간이다.

다음과 같이 정의된 내적 $\lang \cdot , \cdot \rang$이 주어졌다고 하자.
$$ a,b \in \R^n, \quad \lang a,b \rang = a^ib_i$$

$(\R^n, \lang \cdot , \cdot \rang)$을 통해 공간을 일반화한것이 `다양체(Manifold)`이다.


## chart
다음을 가정하자.
$$\forall p \in M, \quad \exist\varphi_p : V_p \rightarrow B(0,r), \quad \exist \varphi^{-1}, \quad \varphi, \varPhi^{-1} \in C^\infty $$

이 떄, $V_p$는 P점을 포함하는 주변의 집합이며 $B(0,r)$은 원점이 0이고 반지름이 $r$인 원 내부에 있는 점의 집합이다.

가정에 의해 존재성이 보장된 $\varphi_p$를 `chart`라고 하며 $\varphi_p$는 각 $p$점마다 존재한다. 따라서 $\varphi_p$는 $p$에 의존하는 함수이며 $\varphi_p$에 의해 Manifold의 국소적인 부분($V_p$)을 $\R^n$으로 볼 수 있다.

점 $p$에서 $\varphi_p$의 존재성은 강제하지만 유일성은 강제하지 않는다. 따라서 다양한 chart가 존재할 수 있고 그 chart에 따라서 계산값이 바뀔 수 있다. 따라서 수학적으로 chart에 따라서 값이 변하지 않는것들을 유의미하다고 본다.

> 참고  
> [relationship-between-covariant-contravariant-basis-vectors - Mathematics](https://math.stackexchange.com/questions/393316/relationship-between-covariant-contravariant-basis-vectors)

## Tangent space
점 $p \in M$에서 `tangent space`를 $T_pM$이라고 한다. $T_pM$은 점 $p$에서 $M$에 접하는 모든 벡터들의 집합이며, 벡터공간이 된다. $T_pM$이 벡터공간임으로 dual space를 갖으며 $T_pM^*$을 `cotangent space`라고 한다.


### 명제1
$T_x\R^n$의 basis가 $\frac{\partial}{\partial x_i}$임을 보여라.




> 참고  
> [relationship-between-covariant-contravariant-basis-vectors - Mathematics](https://math.stackexchange.com/questions/393316/relationship-between-covariant-contravariant-basis-vectors)
> [why-are-the-partial-derivatives-a-basis-of-the-tangent-space](https://math.stackexchange.com/questions/3330025/why-are-the-partial-derivatives-a-basis-of-the-tangent-space)  

---

2번조건
$$ \forall p \in M, \exist \varphi_1 : v_p \rightarrow B(0,r_1), \exist \varphi_2 : u_p \rightarrow B(0,r_2) $$

$$ \varphi_2 \circ (\varphi_1)^{-1} : \R^n \rightarrow \R^n, \quad \text{bijective,} \quad \varphi_2 \circ (\varphi_1)^{-1}, (\varphi_2 \circ (\varphi_1)^{-1})^{-1} \in C^\infty $$

1번조건과 2번조건을 만족할 때, M