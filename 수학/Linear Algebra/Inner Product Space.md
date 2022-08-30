# Inner Product
$n$차원 vector space $V / \mathbb F$가 있을 때, 다음 성질을 만족하는 함수 $B:V \times V \rightarrow \mathbb F$를 `내적(inner product)`라 한다.

$x,y,z \in V$이고 $c \in \mathbb F$일 때,
1. $$ B(x+y, z) = B(x,z) + B(y,z) $$
2. $$ B(cx,y) = cB(x,y) $$
3. $$ B(x,y) = \overline{B(y,x)} $$
4. $$ 0 \le B(x,x) \quad (B(x,x) = 0_\mathbb F \text{ when } x = 0_V ) $$

### 참고1
$x,y,z \in V$이고 $c \in \mathbb F$일 때,

$\mathbb F = \R$이면, 다음이 성립한다.
$$ B(x,cy + z) = c B(x,y) + B(x,z) $$

즉, $B$는 symmetric하고 따라서 bilinear이다.

하지만 $\mathbb F = \mathbb C$이면 다음이 성립한다.
$$ B(x,cy + z) = \bar c B(x,y) + B(x,z) $$

즉, $B$는 더이상 symmetric하지 않고 bilinear하지 않다. 이렇게 scalar multiplcation은 conjugate되서 나오고 벡터의 덧셈은 보존될 때 이를 `Hermitian` 혹은 `conjugate linear`라고 한다.

### 참고2
다음과 같은 표기법을 많이 사용한다.
$$ B(x,y) \equiv \lang x,y \rang $$

# Inner Product Space
$n$차원 vector space $V / \mathbb F$에 내적 $B$가 주어진 공간을 `내적 공간(inner product space)`라고 한다.

# Norm
$n$차원 inner product space $V / \mathbb F$가 있을 때, `norm`은 다음과 같이 정의된 함수이다.
$$ n : V \rightarrow \R \quad s.t. \quad v \mapsto \sqrt{ B(v,v)} $$

### 참고
다음과 같은 표기법을 많이 사용한다.
$$ n(v) \equiv \lVert n \rVert $$

# Angle
$n$차원 inner product space $V / \mathbb F$가 있을 때, `angle`는 다음과 같이 정의된 함수이다.
$$ a : V \times V \rightarrow \R \quad s.t. \quad (v,w) \mapsto \cos^{-1} \bigg(\frac{B(v,w)}{\lVert v \rVert \lVert w \rVert} \bigg) $$

### 참고
두 벡터 $v,w \in V$가 주어졌을 때, 두 벡터 사이의 각도를 $\theta$라고 하면 다음이 성립한다.
$$ \cos \theta =  \frac{B(v,w)}{\lVert v \rVert \lVert w \rVert} $$


# Distance
$n$차원 inner product space $V / \mathbb F$가 있을 때, `distance`는 다음과 같이 정의된 함수이다.
$$ d : V \times V \rightarrow \R \quad s.t. \quad (v,w) \mapsto \lVert v-w \rVert $$



# Orthogonal Subset
$n$차원 inner product space $V / \mathbb F$가 있다고 하자.

$S = \{ v_1, \cdots, v_k \} \subset V - \{ 0_V\}$가 다음을 만족할 때, $S$를 `orthogonal subset`이라고 한다.
$$ i \neq j \Rightarrow B(v_i, v_j) = 0 $$

### 명제1
$n$차원 inner product space $V / \mathbb F$가 있다고 하자.

$S = \{ v_1, \cdots, v_k \}$가 orthogonal subset일 때 다음을 증명하여라.
$$ S \text { is linearly independent} $$

**Proof**

다음과 같이 가정하자.
$$ a^iv_i = 0_V $$

내적을 이용하면 다음이 성립한다.
$$ B(a^iv_i, v_j) = a^j \lVert v_j \rVert = 0_\mathbb F $$

norm의 정의에 의해, 모든 j에 대해 $a^j = 0$임을 알 수 있다. 따라서 linearly independent하다. $\quad {_\blacksquare}$

### 명제2
$n$차원 inner product space $V / \mathbb F$가 있다고 하자.

$S = \{ v_1, \cdots, v_k \}$가 orthogonal subset일 때 다음을 증명하여라.
$$ y \in \text{span}(S) \Rightarrow y = \frac{B(y,v_i)}{\lVert v_i \rVert} v_i $$

**Proof** 

$y$는 다음과 같이 표현할 수 있다.
$$ y = a^iv_i $$

내적을 이용하면 다음이 성립한다.
$$ \begin{aligned} & B(y, v_j) = B(a^iv_i, v_j) = a^j \lVert v_j \rVert \\ \Rightarrow \enspace & a^j = \frac{B(y,v_j)}{\lVert v_j \rVert} \end{aligned}  $$

이를 원래 표현식에 대입하면 다음을 얻을 수 있다.
$$ y = \frac{B(y,v_i)}{\lVert v_i \rVert} v_i \quad {_\blacksquare}$$