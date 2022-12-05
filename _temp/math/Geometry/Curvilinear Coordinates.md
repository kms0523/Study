# Orthogonal Curvilinear Coordinates in 3D
3차원 공간상의 한 점 $P \in \R^3$가 있다고 하자.

Cartesian coordinates의 standard basis vector를 $e_{1,2,3}$이라 할 떄, $P$는 다음과 같이 표현할 수 있다.
$$ P = x^1e_1 + \cdots + x^3e_3 = x^ie_i $$

이 떄, 다음과 같이 정의된 diffeomorphism $f$가 있다고 하자.
$$ f : \R^3 \rightarrow \R^3 \quad s.t. \quad (q^1,q^2,q^3) \mapsto (x^1,x^2,x^3) $$

그러면 다음 관계가 성립한다.
$$ x^i = f^i(q^1,q^2,q^3), \enspace q^i = (f^{-1})^i(x^1,x^2,x^3)$$

---

$q^{1,2,3}$로 표현되는 curvilinear coordinates의 local basis를 $h_{1,2,3}$이라 할 떄, $P$는 다음과 같이 표현할 수 있다.
$$ P = q^ih_i $$

> Q. 이게 사실이 아니라면 왜 $h_i = \frac{\partial P}{\partial q^i}$인가?

---

> Reference  
> [Wiki](https://en.wikipedia.org/wiki/Curvilinear_coordinates)

## Coordainate surfaces
$$ q^1 = constant, \enspace q^2 = constant, \enspace q^3 = constant $$

> Reference  
> [Wiki](https://en.wikipedia.org/wiki/Curvilinear_coordinates)

### 예시
$q^1 = c_1 \in \R$이고 $q^2 = r, \enspace q^3 = s$라 하자.

$q^1 = constant$인 coordinate surface는 다음과 같이 표현된다.
$$ \begin{aligned} S(r,s) &:= x^i(r,s)e_i \\ &= f^i(c_1,r,s)e_i \end{aligned}  $$

## Coordainate curves
다음과 같이 정의된 space curve를 `coordinate curves`라고 한다.
$$ \text{intersection of coordinate surface pairs } $$

> Reference  
> [Wiki](https://en.wikipedia.org/wiki/Curvilinear_coordinates)

### 예시
$q^1 = c_1 \in \R, \enspace q^2 = c_2 \in \R, \enspace q^3 = t$라 하자.

$q^1 = constant$과 $q^2 = constant$인 coordinate surfaces의 intersection인 coordinate curve는 다음과 같이 표현된다.
$$ \begin{aligned} l(t) &:= x^i(t)e_i \\ &= f^i(c_1,c_2,t)e_i \end{aligned}  $$

## Basis
Cartesian coordinate의 standard basis $e_{1,2,3}$은 $P$의 local coordinate에 위치의 미분으로 다음과 같이 유도할 수 있다.
$$ \begin{aligned} e_i &= \frac{\partial P}{\partial x^i} \\&= \frac{\partial x^j}{\partial x^i}e_j \end{aligned}  $$

동일한 맥락으로 curvilinear coordinate의 basis $h_{1,2,3}$도 다음과 같이 유도할 수 있다.
$$ \begin{aligned} h_i &= \frac{\partial P}{\partial q^i} \\&= \frac{\partial x^j}{\partial q^i}e_j \\&= \frac{\partial f^j}{\partial q^i}e_j \end{aligned}  $$

이렇게 유도한 basis $h_i$는 $P$의 위치에 따라 크기와 방향이 바뀔수 있음으로 `local basis`라고 부른다.


> Reference  
> [Wiki](https://en.wikipedia.org/wiki/Curvilinear_coordinates)  
> [Stackexchange.math - basis-vectors-in-a-general-curvilinear-coordinate-system](https://math.stackexchange.com/questions/1854909/basis-vectors-in-a-general-curvilinear-coordinate-system)  
> [Stackexchange.math - coordinate-basis-and-coordinate-systems](https://math.stackexchange.com/questions/3067566/coordinate-basis-and-coordinate-systems)  