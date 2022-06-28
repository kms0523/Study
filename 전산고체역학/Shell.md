# $SO(3)$
3차원 Euclidean 공간의 원점을 보존하는 모든 회전변환의 집합에 연산으로 `합성(composition)`을 주면 군구조를 만족하며 이를 $SO(3)$라 한다.
$$ SO(3) := \{ \mathbf P : \R^3 \rightarrow \R^3 | \mathbf P^{-1} = \mathbf P^T \land \det(\mathbf P) = 1 \} $$

$SO(3)$는 다음 성질을 같는다.
$$ \mathbf P \in SO(3) \Rightarrow \exist \mathbf v \in \R^3 \quad s.t. \quad \mathbf {Pv = v} $$

> 왜 eigenvector를 갖는가?  
왜 eigen value는 1인가?  
rotation about $\mathbf v$?  

$SO(3)$의 identity에서 tangent space $T_ISO(3)$를 $so(3)$라고 하며 다음과 같다.
$$ so(3) = \{ \mathbf Q : \R^3 \rightarrow \R^3 | \mathbf Q + \mathbf Q^T = 0  \} $$

> tangent space가 무엇인가?  
왜 SO(3)의 tangent space가 저렇게 정의되는가?  

$so(3)$는 다음 성질을 같는다.
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

# 2004 [Lee & Bathe]  
> displacement-based shell structure는 shell이 얇아질 때 왜 shear and membrane locking이 발생할까?  
shear and membrane locking이 발생하면 왜 stiff해질까?  

quadrilateral element의 경우에는 MITC technique을 사용한 quadrilateral shell finite elements가 optimal에 가깝다.
하지만 triangular element에는 "uniformly optimal" element뿐만 아니라 close to optimal인 element도 없다.

Ellipcity, Consistency, Inf-sup condition, spatial locality을 만족하는 triangular element를 만든다.

Ellipcity란 zero energy mode가 없어서 FE 차분식이 물리적으로 의미 있는 값으로 풀리는 성질이다.
> zero energy mode란?  
> single shell finite element는 왜 6개의 zero energy mode를 갖는가?  

Consistency는 element가 작아질수록 FE solution이 mathematical solution으로 수렴하는 성질이다. 즉, FE formulation에서 나타나는 Bilinear form이 $h$가 작아질수록 mathematical model의 bilinear form으로 가는 성질이다.
> bilinear form?  

Inf-sup condition은 이상적으로 mixed FE 차분이 만족해야 하는 조건이다. 이 조건을 만족하는 shell FE는 bending-dominated shell problem에서 uniform optimal convergence를 갖는다는 것을 알 수 있다.
> Inf-sup condition이란?  
> Inf-sup condition을 만족하면 왜 shear & membrance locking 현상으로 부터 자유로운가?  

spatial isotropy란 triangular element의 stiffness matrices가 node numbering에 독립적이여야 한다는 성질이다. 자세히 말하면, 모든 변의 길이가 같은 isotropic trianglular element에서는 각 corner에서 nodal displacement/rotation 그리고 each midside nodal displacement/rotation이 동일한 방식으로 변한다. 만약 element의 성질이 orientation에 의존하면 각 element의 orientation에 대해 특별히 신경을 써줘야 한다. 
>왜 sptatil isotropy 조건이 locking-free trianglular shell element를 만드는데 가장 큰 장애물이지?

* spatially isotropic behavior
* no spurious zero energy mode (ellipticity condition)
* no shear licking in plate bending problem
* optimal result for membrane dominated shell problem
* 실용적으로 많이 쓰이는 얇은 두께에서 optimal result for bending dominated shell problem 
* 비선형 해석으로 확장성

## 2
Mixed Interpolation of Tensorial Components(MITC)

MITC의 핵심 아이디어는 displacement와 변위를 각각 interpolation하고 tying points에서 두 interpolation을 연결시켜주는 방법이다.

따라서 displacement와 strain의 interpolation을 각각 ellipticity와 consistency를 만족하고 inf-sup condition을 최대한 만족하게끔 결정한다.

displacement-based shell element의 geometry는 다음과 같다.
$$ \mathbf x( \mathbf r) = n_i(\mathbf r) \mathbf x_i + \frac{t}{2} a_i n_i(\mathbf r) \mathbf v^i $$
> geometry가 왜 이렇게 표현되지?

이 때, $n_i$는 $i$점의 standard 2D shape function이고 $\mathbf x_i$는 $i$점의 직교 좌표이며 $a_i$는 $i$점의 shell thickness, $\mathbf v_i$는 $i$점의 director vector이다.
>director vector가 뭐지?

Element의 displacement는 다음과 같이 주어진다.
$$ \mathbf d(\mathbf r) = n_i\mathbf d(\mathbf x_i) + \frac{1}{2} a_in_i(-\mathbf v_2^i \alpha_i + \mathbf v_1^i \beta_i) $$
> 왜 displacement가 이렇게 표현되지?

이 때, $\mathbf v^i_{1,2}$는 각 각 $\mathbf v^i_n$에 수직한 단위 벡터이고, $\alpha_i, \beta_i$는 rotation of the director vector $\mathbf v^i_n$ about $\mathbf v^i_{1,2}$.

