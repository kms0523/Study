# Affine space
`Affine space`란 집합 $A$에 vector space $V / \mathbb F$와 다음과 같이 정의된 이항연산 $+$가 주어진 구조이다.
$$ + : A \times V \rightarrow A $$

일반적으로, 집합 $A$의 원소를 `점(point)`이라고 한다.

$+$는 $V$의 $A$로의 작용으로써, 다음 성질들을 만족한다.
$$ \begin{aligned} 1) \quad & P \in A \Rightarrow P + 0_V = P \\ 2) \quad & v_1, v_2 \in V \land P \in A \Rightarrow (P + v_1) + v_2 = P + (v_1 + v_2) \\ 3) \quad & P \in A \enspace \land \enspace f_P : V \rightarrow A \quad s.t. \quad v \mapsto P + v = P_v \Rightarrow f_P \text{ is bijective} \end{aligned} $$

1), 2) 성질은 right group action을 정의하고 있으며, 3) 성질은 임의의 point $P$가 주어졌을 때, 함수 $f_P$를 통해 $v$와 $P_v$를 동일시 할 수 있다는 것을 보여준다. 

이 때, $P$를 `원점(origin)`이라고 한다면, 1) 성질에 의해 $0_V$는 항상 origin과 동일시 된다.

따라서, $A$의 모든 points들을 시각화 할 수 있고, origin을 $P_0$로 결정한다면, $v \in V$는 $P_0$점에서 시작해서 $P_v = P_0 + v$점으로 가는 선으로 시각화 할 수 있다. 만약 origin을 $P_0$에서 $P_1$으로 옮긴다음 $v \in V$를 다시 시각화하면, 시각화된 $v$의 원점만 $P_1$으로 옮긴 모습이 된다.






## Substraction and Weyl's axioms
위의 주어진 $+$의 성질을 활용하여 다음같은 이항연산을 정의할 수 있다.
$$ - := A \times A \rightarrow V \quad s.t. \quad (P_1,P_2) \mapsto P_2 - P_1 $$

$$ \text{Where, }  P_1 + (P_2 - P_1) = P_2 $$

이 때, $-$는 다음 성질들을 만족한다.

$$ \begin{aligned} 1) \quad & P \in A \enspace \land \enspace v \in V \Rightarrow \exist! P_v \in A \quad s.t. \quad P_v - P = v \\ 2) \quad & P_1,P_2,P_3 \in A \Rightarrow (P_3 - P_2) + (P_2 - P_1) = P_3 - P_1 \end{aligned} $$

다음 두 명제를 Weyl's axioms라고 하며, 2)을 일반적으로 `평행사변형 법칙(parallelogram rule)`이라고 한다.

Affine space는 집합 A에 벡터 공간 $V / \mathbb F$와 $-$를 주어도 동일하게 정의 할 수 있으며, 이 경우에는 $+$ 연산은 Weyl's axioms을 활용하여 정의할 수 있다.

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
> [when-is-a-vector-glued-to-the-origin - mathmatics](https://math.stackexchange.com/questions/2392479/when-is-a-vector-glued-to-the-origin)  
> [must-vectors-in-mathbbrn-have-their-tail-at-origin - mathematics](https://math.stackexchange.com/questions/627616/must-vectors-in-mathbbrn-have-their-tail-at-origin)