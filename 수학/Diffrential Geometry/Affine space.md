# Affine space
집합 $A$와 벡터 공간 $V/\mathbb F$이 있을 때, 다음과 같은 이항연산이 있다고 하자.
$$ + : A \times V \rightarrow A $$

$+$가 다음 성질들을 만족한다고 하자.
$$ \begin{aligned} 1) \quad & \forall a \in A \Rightarrow a + 0_V = a \\ 2) \quad & v_1, v_2 \in V \land a \in A \Rightarrow (a + v_1) + v_2 = a + (v_1 + v_2) \\ 3) \quad & a \in A \enspace \land \enspace f_a:V \rightarrow A \quad s.t. \quad v \mapsto a + v \Rightarrow f_a \text{ is bijective} \end{aligned} $$

`Affine space`란 집합 $A$에 벡터 공간 $V$와 $+$가 주어진 구조이다.

$+$의 1), 2) 성질은 right group action을 정의하고 있다.

### 명제1
$v \in V$가 있을 때, 다음과 같이 정의된 함수를 $f_v$라 하자.
$$f_v : A \rightarrow A \quad s.t. \quad a \mapsto a+v$$
이 때, $f$가 전단사 함수임을 증명하여라.

**Proof**

[injective]  
$a,b \in A$라 하자.  
$$ \begin{aligned} & f_v(a) = f_v(b) \\ \Rightarrow \enspace & a+v = b+v \\ \Rightarrow \enspace & a + v + v^{-1} = b + v + v^{-1} \\ \Rightarrow \enspace & a + 0_V = b + 0_V \\ \Rightarrow \enspace & a = b \quad {_\blacksquare}\end{aligned} $$

[surjective]  
$a \in A$라 하자.
$$ \begin{aligned} & a + (-v) \in A (\because + \text { is binary operator = closed}) \\ \Rightarrow \enspace & f(a+ (-v)) = a + (-v) + v = a \quad {_\blacksquare}\end{aligned} $$

### 명제2
$+$의 3번 성질이 다음과 동치임을 증명하여라.
$$ a,b \in A \Rightarrow \exist! v \in V \quad s.t. \quad b = a+v$$

**Proof**

[$\Rightarrow$]  
$f_a$가 전단사함수임으로, $f_a(v) = b$가 되는 $v$가 유일하게 존재한다. 즉, $b = a + v$인 $v$가 유일하게 존재한다. $\quad {_\blacksquare}$

[$\Leftarrow$]  
[injective]  
$v_1,v_2 \in V$라 하자.  
$$ \begin{aligned} & f_a(v_1) = f_a(v_2) \\ \Rightarrow \enspace & a + v_1 = a+ v_2 \\ \Rightarrow \enspace & v_1 = v_2 (\because \text{uniquness of } v) \quad {_\blacksquare}\end{aligned} $$

[surjective]  
$b \in A$면 $b = a + v$를 만족하는 $v$가 존재함으로 $f_a(v) = b$를 만족하는 $v$도 존재한다. 따라서 $f_a$는 전사함수이다. $\quad {_\blacksquare}$

> 참고  
> [Affine space - wiki](https://en.wikipedia.org/wiki/Affine_space)  
> [what-are-differences-between-affine-space-and-vector-space - mathematics](https://math.stackexchange.com/questions/884666/what-are-differences-between-affine-space-and-vector-space)  
> [an-affine-space-is-nothing-more-than-a-vector-space - mathmatics](https://math.stackexchange.com/questions/3527297/an-affine-space-is-nothing-more-than-a-vector-space-whose-origin-we-try-to-forg)  