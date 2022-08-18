## Geometric preliminaries
### rotation group and Lie algebra
3차원 Euclidean 공간의 원점을 보존하는 모든 회전변환의 집합에 연산으로 `합성(composition)`을 주면 군구조를 만족하며 이를 $SO(3)$라 한다.
$$ SO(3) := \{ \mathbf P : \R^3 \rightarrow \R^3 \enspace | \enspace \mathbf P^{-1} = \mathbf P^T \land \det(\mathbf P) = 1 \} $$

$SO(3)$의 원소는 다음 성질을 만족한다.
$$ \mathbf P \in SO(3) \Rightarrow \exist \mathbf v \in \R^3 \quad s.t. \quad \mathbf {Pv = v} $$

기하학적으로, $\mathbf P$는 $\mathbf v$를 축으로 하는 회전을 나타낸다.

> 참고  
> [Mathematics - property of SO3](https://math.stackexchange.com/questions/1127388/property-of-so3)  
> [Wiki - Determinant](https://en.wikipedia.org/wiki/Determinant)  

$SO(3)$의 identity에서 tangent space $T_{id}SO(3)$를 $so(3)$라고 하며 다음과 같다.
$$ so(3) = \{ \mathbf Q : \R^3 \rightarrow \R^3 \enspace | \enspace \mathbf Q + \mathbf Q^T = 0  \} $$

> 참고  
> [블로그 - Lie Theory 개념 정리](https://alida.tistory.com/9#ref6)  

$so(3)$의 원소는 다음 성질을 만족한다.
$$ \mathbf Q \in so(3) \Rightarrow \exist \mathbf v \in \R^3 \quad s.t. \quad \mathbf Q \mathbf v = 0 $$ 

다음과 같은 isomorphism $\Phi$가 존재한다.
$$ \Phi :so(3) \rightarrow \R^3 \quad s.t. \quad \mathbf Q \mapsto \mathbf v \quad \text{satisfying } \forall \mathbf x \in \R^3  \quad \mathbf{Qx} = \mathbf {v \times x}$$

이 떄, $\bf v$는 $\bf Q$의 eigen vector이며 $\mathbf Q$는  $\mathbf v$를 축으로 하는 infinitesimal rotation을 나타낸다.

임의의 $\lambda \in SO(3)$에서의 tangent space는 다음과 같이 정의된다.
$$ T_\lambda SO(3) := \{ \lambda \mathbf Q \equiv \mathbf q\lambda \enspace | \enspace \mathbf Q \in so(3) \enspace \lor \enspace \mathbf q = \lambda \mathbf Q \lambda^t \in so(3) \} $$

이 때, $\lambda \mathbf Q \in T_\lambda SO(3)$는 finite rotation superposed onto an infinitesimal rotation으로 볼 수 있다. 또는 $\mathbf q \lambda$를 infinitesimal rotation $\mathbf q$ superposed onto a finite rotation.

# 3.Kinematic description of the shell
## 3.1 Configurations
differetiable manifold인 집합 $\mathcal C$를 다음과 같이 정의한다.
$$ \mathcal C := \{ (\varphi, t) \enspace | \enspace \mathcal A \rightarrow \R^3 \times S^2 \} $$

이 때, $\mathcal A \subset \R^2$는 smooth boundary $\partial \mathcal A$를 갖는 open set이며 compact closure이다.




$S^2 := \{ t \in \R^3 \enspace | \enspace \Vert t \Vert = 1 \}$를 `단위 구(unit sphere)`, $T_tS^2 := \{ w \in \R^3 \enspace | \enspace t \cdot w = 0 \}$을 $t \in S^2$에서의 `접평면(tangent space)`라 하자.

shell의 configuration sppce를 $\mathcal C$라 하면, 다음과 같이 정의된다.
$$ \mathcal C := \{ \Phi := (\varphi, t) : \mathcal A \rightarrow \R^3 \times S^2 \} $$

이 때, $\mathcal A \subset \R^2$은 compact이며, boundary $\partial \mathcal A$를 갖는다. 이 때, $\partial_\varphi \mathcal A \subset \partial \mathcal A$는 displacement가 $\partial_t \mathcal A \subset \partial \mathcal A$는 rotation이 주어진 boudnary이다.

임의의 shell의 configuration을 $\mathcal S$라 할 때, $\mathcal S$가 다음과 같이 정의된다고 가정하자.
$$ \mathcal S := \{ x \in \R^3 \enspace | \enspace x = \varphi + \xi t \text{ where } (\varphi,t) \in \mathcal C \text { and } \xi \in [h^-, h^+] \} $$

이 때, shell의 두께는 $h = h^+ - h^-$로 주어지고, $\varphi : \mathcal A \rightarrow \R^3$은 shell의 mid-surface를 정의하며, $t : \mathcal A \rightarrow S^2$이다.