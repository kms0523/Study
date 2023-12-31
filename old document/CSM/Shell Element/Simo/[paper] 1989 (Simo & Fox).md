## 2. Geometric preliminaries
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
differetiable manifold인 집합 $\mathscr C$를 다음과 같이 정의한다.
$$ \mathscr C := \{ (\varphi, t) \enspace | \enspace \mathscr A \rightarrow \R^3 \times S^2 \} $$

$$ \text {Where, } \varphi : \mathscr A \rightarrow \R^3, \enspace t : \mathscr A \rightarrow S^2 $$

이 때, $\mathscr A \subset \R^2$는 smooth boundary $\partial \mathscr A$를 갖는  compact set이며 map $\varphi$는 shell의 mid-surface의 위치를 정의하며, map $t$는 surface의 각 점마다 unit vector field(director field)를 정의한다.

### Basic Assumption
함수 $\Phi$를 다음과 같이 정의하자.
$$\Phi : \mathscr A \times [h^-, h^+] \rightarrow \mathscr S \quad s.t. \quad (\xi^1,\xi^2,\xi) \mapsto \varphi(\xi^1, \xi^2) + \xi t(\xi^1, \xi^2) $$

$$ \text {Where, } (\varphi,t) \in \mathscr C $$

임의의 shell의 configuration을 $\mathscr S \subset \R^3$라 할 때, $\mathscr S$를 다음과 같이 정의하자.
$$ \mathscr S := \{ \mathbf x \in \R^3 \enspace | \enspace \mathbf x = \Phi(\xi^1,\xi^2,\xi) \} $$

이 때, reference configuration은 다음과 같다.
$$ \mathscr B := \{ \mathbf x_0 \in \R^3 \enspace | \enspace \mathbf x_0 = \Phi_0(\xi^1,\xi^2, \xi) \text { where } \Phi_0 = \varphi_0 + \xi t_0 \} $$

shell의 deformation을 $\mathcal X : \mathscr B \rightarrow \mathscr S$라 하면 $\mathcal X$는 다음과 같다.
$$ \mathcal X := \Phi \circ (\Phi_0)^{-1} $$




# 6. The variational formulation
momentum equation이 다음과 같이 주어져 있다고 하자.
<p align = "center">
<img src = "./image/1989 (Simo & Fox)_1.png" width = 400>
</p>

weak form은 다음과 같다.
<p align = "center">
<img src = "./image/1989 (Simo & Fox)_2.png">
</p>

component expression으로 나타내면 다음과 같다.
<p align = "center">
<img src = "./image/1989 (Simo & Fox)_3.png">
</p>

위의 component expression을 operator expressions으로 나타내면 다음과 같다.
<p align = "center">
<img src = "./image/1989 (Simo & Fox)_4.png">
<img src = "./image/1989 (Simo & Fox)_5.png">
</p>