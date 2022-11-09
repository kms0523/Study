# Affine space
`Affine space`란 집합 $A$에 vector space $V / \mathbb F$와 다음과 같이 정의된 이항연산 $+$가 주어진 구조이다.
$$ + : A \times V \rightarrow A $$

$+$는 $V$의 $A$로의 작용으로써 다음 성질들을 만족한다.
$$ \begin{aligned} 1) \quad & p \in A \Rightarrow p + 0_V = p \\ 2) \quad & v_1, v_2 \in V \land p \in A \Rightarrow (p + v_1) + v_2 = p + (v_1 + v_2) \\ 3) \quad & p \in A \enspace \land \enspace f_p : V \rightarrow A \quad s.t. \quad v \mapsto p + v = p_v \Rightarrow f_p \text{ is bijective} \end{aligned} $$

> Reference  
> [Affine space - wiki](https://en.wikipedia.org/wiki/Affine_space)  

### 참고1
집합 $A$의 원소를 `점(point)`, $+$를 `translation`이라고 한다.

> Reference  
> [Affine space - wiki](https://en.wikipedia.org/wiki/Affine_space)  

### 참고2
$+$의 1), 2)성질은 right group action을 정의하고 있다.

$+$의 3)성질은 $p \in A$가 주어지면 $A$와 $V$를 오갈 수 있는 $f_p$가 존재한다는 의미이다.

이 때, $p$를 `원점(origin)`이라고 하며 1) 성질에 의해 $0_V$는 $f_p$에 의해 항상 $p$로 mapping 된다. 

### 참고3
origin $p$가 주어지면 다음과 같이 point와 vector의 pair로 이루어진 vector space를 구성할 수 있다.
$$ V_p := \{(p,v) \enspace | \enspace v \in V  \} $$

### 참고4
만약 origin $P_0$와 $V$의 기저 $\beta$가 결정되면, bijective function $\phi : A \rightarrow \R^n$가 존재한다. 

이 때, $v \in V$에 의해 $P_0$점이 $P_v$로 translation 됨으로, $v$를 Cartesian coordinate상에서 $\phi(P_0)$점에서 시작해서 $\phi(P_v)$로 가는 화살표로 표현할 수 있다.

### 명제1
vector space $V / \mathbb F$가 주어진 affine space $A$와 $v \in V$가 있을 때, 다음과 같이 정의된 함수를 $f_v$라 하자.
$$f_v : A \rightarrow A \quad s.t. \quad P \mapsto P + v$$
이 때, $f_v$가 전단사 함수임을 증명하여라.

**Proof**

[injective]  
$P_1,P_2 \in A$라 하자.  
$$ \begin{aligned} & f_v(P_1) = f_v(P_2) \\ \Rightarrow \enspace & P_1 + v = P_2 + v \\ \Rightarrow \enspace & P_1 + v + v^{-1} = P_2 + v + v^{-1} \\ \Rightarrow \enspace & P_1 + 0_V = P_2 + 0_V \\ \Rightarrow \enspace & P_1 = P_2 \quad {_\blacksquare}\end{aligned} $$

[surjective]  
$P \in A$라 하자.
$$ \begin{aligned} & P + (-v) \in A (\because + \text { is binary operator = closed}) \\ \Rightarrow \enspace & f(P + (-v)) = P + (-v) + v = P \quad {_\blacksquare}\end{aligned} $$

### 명제2
$+$의 3번 성질이 다음과 동치임을 증명하여라.
$$ P_1, P_2 \in A \Rightarrow \exist! v \in V \quad s.t. \quad P_2 = P_1+v$$

**Proof**

[$\Rightarrow$]  
$f_{P_1}$가 전단사함수임으로, $f_{P_1}(v) = P_2$가 되는 $v$가 유일하게 존재한다. 즉, $P_2 = P_1 + v$인 $v$가 유일하게 존재한다. $\quad {_\blacksquare}$

[$\Leftarrow$]  
[injective]  
$v_1,v_2 \in V$라 하자.  
$$ \begin{aligned} & f_{P_1}(v_1) = f_{P_1}(v_2) \\ \Rightarrow \enspace & P_1 + v_1 = P_1 + v_2 \\ \Rightarrow \enspace & v_1 = v_2 (\because \text{uniquness of } v) \quad {_\blacksquare}\end{aligned} $$

[surjective]  
$P_2 \in A$면 $P_2 = P_1 + v$를 만족하는 $v$가 존재함으로 $f_{P_1}(v) = P_2$를 만족하는 $v$도 존재한다. 따라서 $f_{P_1}$는 전사함수이다. $\quad {_\blacksquare}$

# Substraction and Weyl's axioms
위의 주어진 $+$의 성질을 활용하여 다음같은 이항연산을 정의할 수 있다.
$$ - := A \times A \rightarrow V \quad s.t. \quad (P_1,P_2) \mapsto P_2 - P_1 $$

$$ \text{Where, }  P_1 + (P_2 - P_1) = P_2 $$

이 때, $-$는 다음 성질들을 만족한다.

$$ \begin{aligned} 1) \quad & P \in A \enspace \land \enspace v \in V \Rightarrow \exist! P_v \in A \quad s.t. \quad P_v - P = v \\ 2) \quad & P_1,P_2,P_3 \in A \Rightarrow (P_3 - P_2) + (P_2 - P_1) = P_3 - P_1 \end{aligned} $$

다음 두 명제를 Weyl's axioms라고 하며, 2)을 일반적으로 `평행사변형 법칙(parallelogram rule)`이라고 한다.

Affine space는 집합 A에 벡터 공간 $V / \mathbb F$와 $-$를 주어도 동일하게 정의 할 수 있으며, 이 경우에는 $+$ 연산은 Weyl's axioms을 활용하여 정의할 수 있다.

### 명제1
vector space $V / \mathbb F$가 주어진 affine space $A$가 있을 때, $P_0 \in A$와  $V$의 기저 $\beta$를 결정하면 bijective function $\phi : A \rightarrow \R^n$이 존재함을 증명하여라.

**Proof**

$\phi$를 다음과 같이 정의하자.
$$ \phi : A \rightarrow \R^n \quad s.t. \quad P \mapsto [P-P_0]_\beta $$

명제2에 의해 $P-P_0$가 유일하게 존재함으로, 함수 $\phi$는 잘 정의되며 injective이다.

또한 +는 연산에 닫혀있음으로, $a \in \R^n$에 대해, $P = P_0 + a_i\beta_i$를 만족하는 $P$가 항상 존재함으로 surjective이다. $\quad {_\blacksquare}$

> Reference  
> [Affine space - wiki](https://en.wikipedia.org/wiki/Affine_space)  
> [what-are-differences-between-affine-space-and-vector-space - mathematics](https://math.stackexchange.com/questions/884666/what-are-differences-between-affine-space-and-vector-space)  
> [an-affine-space-is-nothing-more-than-a-vector-space - mathmatics](https://math.stackexchange.com/questions/3527297/an-affine-space-is-nothing-more-than-a-vector-space-whose-origin-we-try-to-forg)  
> [when-is-a-vector-glued-to-the-origin - mathmatics](https://math.stackexchange.com/questions/2392479/when-is-a-vector-glued-to-the-origin)  
> [must-vectors-in-mathbbrn-have-their-tail-at-origin - mathematics](https://math.stackexchange.com/questions/627616/must-vectors-in-mathbbrn-have-their-tail-at-origin)
> [Euclidean space - wiki](https://en.wikipedia.org/wiki/Euclidean_space) 

# Affine subspace
vector space $V_A / \mathbb F$가 주어진 affine space $A$와 $S \le V$가 있다고 하자.

$p \in A$에 대해서, 집합 $B$를 다음과 같이 정의하자.
$$ B := \{ p + v \enspace | \enspace v \in S \} $$

그러면 $B$는 vector space $S$가 주어진 affine space가 되며, $B$를 $A$의 affine subspace라 한다.

> Reference  
> [Affine space - wiki](https://en.wikipedia.org/wiki/Affine_space)  

### 참고
$B$가 $A$의 affine subspace라는 것을 다음과 같이 간단하게 나타낸다.
$$ B \le A $$

# Parallel
vector space $V_A / \mathbb F$가 주어진 affine space $A$가 있다고 하자.

$B,C \le A$일 때 $V_B = V_C$이면, $B$와 $C$가 `평행(parallel)`하다고 한다.

> Reference  
> [Affine space - wiki](https://en.wikipedia.org/wiki/Affine_space)  