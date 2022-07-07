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

# 2004 [Lee & Bathe]  
## 1
> displacement-based shell structure는 shell이 얇아질 때 왜 shear and membrane locking이 발생할까?  

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

## 2 MITC formulation
Mixed Interpolation of Tensorial Components(MITC)

MITC의 핵심 아이디어는 변위와 변형률을 각각 interpolation하고 tying points에서 두 interpolation을 연결시켜주는 방법이다.

따라서 displacement와 strain의 interpolation을 각각 ellipticity와 consistency를 만족하고 inf-sup condition을 최대한 만족하게끔 결정한다.

displacement-based shell element의 geometry는 다음과 같다.
$$ \mathbf x( r_1,r_2,r_3) = n_i(r_1,r_2) \mathbf x_i + \frac{r_3}{2} n_i(r_1,r_2) a_i \mathbf v^i $$
> geometry가 왜 이렇게 표현되지?  
> (Bathe) The finite element shell element Eq(6.30) 

이 때, $n_i$는 $i$점의 standard 2D shape function이고 $\mathbf x_i$는 $i$점의 직교 좌표이며 $a_i$는 $i$점의 shell thickness, $\mathbf v^i$는 $i$점의 director vector이다. 이 때, $\mathbf v^i$는 shell midsurface에 수직일 필요는 없다.
>director vector가 뭐지?

Element의 displacement는 다음과 같이 주어진다.
$$ \mathbf d(r_1,r_2,r_3) = n_i(r_1,r_2)\mathbf d(\mathbf x_i) + \frac{r_3}{2} a_in_i(-\mathbf v_2^i \alpha_i + \mathbf v_1^i \beta_i) $$
> 왜 displacement가 이렇게 표현되지?

이 때, $\mathbf v^i_{1,2}$는 각 각 $\mathbf v^i$에 수직한 단위 벡터이고, $\alpha_i, \beta_i$는 rotation of the director vector $\mathbf v^i$ about $\mathbf v^i_{1,2}$.

covariant strain component는 다음과 같다.
$$ e_{ij} = \frac{1}{2} \left( \frac{\partial \bf x}{\partial r_i} \cdot \frac{\partial \bf d}{\partial r_j} + \frac{\partial \bf x}{\partial r_j} \cdot \frac{\partial \bf d}{\partial r_i} \right)$$ 

$n_{ij}$개의 tying points $\{(r_1)_k, (r_2)_k\} \quad k=1,\cdots,n_{ij}$에서 assumed covariant strain component를 다음과 같이 정의하자.
$$ \begin{equation} \tilde{e}_{ij}(r_1,r_2,r_3) = \tilde{n}_k(r_1,r_2)e_{ij}|_{((r_1)_k,(r_2)_k,r_3)} \end{equation}  $$

$\tilde{n}_{k}$는 assumed interpolation function으로 다음을 만족한다.
$$ \tilde n_i((r_1)_j , (r_2)_j) = \delta_{ij} $$

Displacement-based covariant strain component는 다음과 같이 주어진다.
$$ EQ(7) ?? $$

## 3 Strain interpolation
MITC 기법을 성공적으로 적용하기 위해서는 적절한 assumed strain interpolations(EQ.(1))을 사용해야 하며, tying points를 잘 정해야 한다.

### 3.1 Strain interpolation methods
$f(x)$는 2차 다항식이고 $f(x_1),f(x_2)$가 주어졌을 때

#### Method i
$f_h(x) = a_1x + a_0$로 근사하고 다음 두개의 선형방정식을 풀어 $a_i$를 구한다.
$$ f_h(x_1) = f(x_1), \quad f_h(x_2) = f(x_2) $$

#### Method ii
$f_h(x) = n_i(x)f(x_i)$로 근사한다. 이 때, $n_i$는 다음을 만족한다.
$$ n_1 = a_1x + a_0, \quad n_2 = b_1x + b_0, \quad n_i(x_j) = \delta_{ij} $$

다음 4개의 선형방정식을 풀어 $a_i,b_i$를 구한다.
$$ n_1(x_1) = 1, \quad n_1(x_2) = 0, \quad  n_2(x_1) = 0, \quad n_2(x_1) = 1 $$

#### New Method
$f_h(x) =  a_0 + a_1x + a_2 x^2$로 근사하고

### 3.2 Interpolation of transverse shear strain field
isotropic한 tranverse shear strain fields를 얻기 위해서는 삼각형의 세 edge에서 동일한 strain variation을 얻어야 한다.

New Method를 사용해서 .... 하면 isotropic transverse shear strain field를 얻는다.

각 edge에서 isotropic transverse shear strain field를 구한다.

---

먼저 $e_{rt},e_{st}$를 다항식으로 근사한다.
$$ e_{rt} = a_0 + a_1 r + a_2 s + \cdots \\ e_{st} = b_0 + b_1 r + b_2 s + \cdots $$

관계식으로 부터 $e_{qt}$가 결정된다.
$$ e_{qt} = (a_0-b_0) + (a_1-b_1) r + (a_2-b_2) s + \cdots $$


### 3.3
istropic한 in-plane strain fields를 얻기 위해서 빗변의 $e_{qq}$항을 고려한다.

## 4
bending dominated shell problem에서 좋은 성능을 보이는 element는 membrane dominated shell problem에서 좋지 못한 성능을 보인다. 또는 반대로 작동한다. 따라서 적절한 trade-off를 통해 strain interpolation을 사용해야 한다.

bending dominated shell problem에서 shear and membrane locking현상을 제거하고 membrane dominated shell problem에서는 consistency를 유지하는것이 목표이다.