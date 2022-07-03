# Affine

[what-are-differences-between-affine-space-and-vector-space - mathematics](https://math.stackexchange.com/questions/884666/what-are-differences-between-affine-space-and-vector-space)  

# Manifold

다음과 같은 집합이 주어졌다고 하자.
$$ \R^n := \{ (x_1, \cdots, x_n) | x_i \in \R \} $$

$\R^n$은 벡터공간이다.

다음과 같이 정의된 내적 $\lang \cdot , \cdot \rang$이 주어졌다고 하자.
$$ a,b \in \R^n, \quad \lang a,b \rang = a_ib_i$$

$(\R^n, \lang \cdot , \cdot \rang)$을 통해 공간을 일반화한것이 `다양체(Manifold)`이다.

Manifold는 국소적으로 $\R^n$이다.

Manifold위의 임의의 점 $P$를 잡고, $P$를 $\R^n$에 보내주는 함수 $\varphi$가 있다.

P점을 포함하는 주변의 집합 $V_p$을 neighbor hood(open set)라고 하자. $\varphi : V_p \rightarrow B(0,r)$

$B(0,r)$ 원점이 0이고 반지름이 r인 ball.

이 때, $\varphi$가 bijective하고 $C^\infty$의 원소이길 바란다.

1번조건
$$\forall p \in M, \quad \exist\varphi : V_p \rightarrow B(0:r), \quad \exist \varphi^{-1}, \quad \varphi, \varPhi^{-1} \in C^\infty $$

$\varphi_p$ : chart 각 $p$마다 $p$에 의존하는 $\varphi_p$가 있다. 

점$p$에서 $\varphi_p$의 존재성은 강제하지만 유일성은 강제하지 않는다. 따라서 다양한 chart가 존재할 수 있고 그 chart에 따라서 계산값이 바뀔 수 있다. 따라서 수학적으로 chart에 따라서 값이 변하지 않는것들을 유의미하다고 본다.


2번조건
$$ \forall p \in M, \exist \varphi_1 : v_p \rightarrow B(0,r_1), \exist \varphi_2 : u_p \rightarrow B(0,r_2) $$

$$ \varphi_2 \circ (\varphi_1)^{-1} : \R^n \rightarrow \R^n, \quad \text{bijective,} \quad \varphi_2 \circ (\varphi_1)^{-1}, (\varphi_2 \circ (\varphi_1)^{-1})^{-1} \in C^\infty $$

1번조건과 2번조건을 만족할 때, M