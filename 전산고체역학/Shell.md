# Geometric definition of a shell


# $SO(3)$
3차원 Euclidean 공간의 원점을 보존하는 모든 회전변환의 집합에 연산으로 `합성(composition)`을 주면 군구조를 만족하며 이를 $SO(3)$라 한다.
$$ SO(3) := \{ \mathbf P : \R^3 \rightarrow \R^3 | \mathbf P^{-1} = \mathbf P^T \land \det(\mathbf P) = 1 \} $$

$SO(3)$의 원소는 다음 성질을 만족한다.
$$ \mathbf P \in SO(3) \Rightarrow \exist \mathbf v \in \R^3 \quad s.t. \quad \mathbf {Pv = v} $$

> 왜 eigenvector를 갖는가?  
왜 eigen value는 1인가?  
rotation about $\mathbf v$?  

$SO(3)$의 identity에서 tangent space $T_ISO(3)$를 $so(3)$라고 하며 다음과 같다.
$$ so(3) = \{ \mathbf Q : \R^3 \rightarrow \R^3 | \mathbf Q + \mathbf Q^T = 0  \} $$

> tangent space가 무엇인가?  
왜 SO(3)의 tangent space가 저렇게 정의되는가?  

$so(3)$의 원소는 다음 성질을 만족한다.
$$ \mathbf Q \in so(3) \Rightarrow \exist \mathbf v \in \R^3 \quad s.t. \quad \mathbf Q \mathbf v = 0 $$ 

> 왜 eigenvector를 갖는가?  
왜 eigen value는 0인가?  

다음과 같은 isomorphism $\Phi$가 존재한다.
$$ \Phi :so(3) \rightarrow \R^3 \quad s.t. \quad \mathbf Q \mapsto \mathbf v \quad \text{satisfying } \forall \mathbf x \in \R^3  \quad \mathbf{Qx} = \mathbf {v \times x}$$

이 떄, $\bf v$는 $\bf Q$의 eigen vector이다.

> 왜 eigen vector가 이런 성질을 만족하는가?


>참고  
[3D rotation group - Wiki](https://en.wikipedia.org/wiki/3D_rotation_group)

# Cosserat surface
Cosserat surface란 3차원 Euclidean 공간에서 director라고 불리는 변형 가능한 벡터가 모든점에 할당된 표면이다.

>참고  
[paper] 1965 [Green et al] A General Theory of a Cosserat Surface

# 1989 [Simo & Fox]
shell을 inextensible한 one-director Cosserat surface로 본 뒤, 수치해석과 FE에 알맞은 국소적인(local) 평형 방정식, 구성 방정식, 운동 방정식의 weak form을 구성한다.

