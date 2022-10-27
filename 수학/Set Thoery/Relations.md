# Relation
집합 $A,B$가 있다고 하자.

`이항관계(binary relation)` $R$은 $R \subseteq A \times B$인 집합이다.

이 때, $(a,b) \in R$이면 $a \sim_R b$라고 표현한다.

### 예시1

두 집합 $A = \{ 1,2 \}, B = \{ 4,5 \}$ 이 주어졌을 때

곱집합 $A \times B = \{ \{ 1,4 \} , \{ 1,5 \}, \{ 2,4 \}, \{ 2,5 \} \}$의 부분집합 $R = \{ \{ 1,4 \} , \{ 1,5 \} \}$을 선택하면

$1 \sim_R 4, 1 \sim_R 5$라고 표현할 수 있다.

### 예시2

집합 $A,B$와 함수 $f:A \rightarrow B$가 있을 때, $f$는 $A \times B$의 부분집합이다.

따라서 $f$는 관계이며, $x \in A$에 대해 $x \sim_f y$라고 표현할 수 있다.

### 예시3

집합 $S$와 관계 $R \subseteq S \times S$를 다음과 같이 정의하자.

$$ S:= \{ x | x \text{ is student in SNU} \} \\ R:= \{ (x,y) \in S \times S | \text{ x thinks y is a friend} \} $$

이때, $a,b,c \in S$에 대해 다음과 같은 재미있는 질문들을 할 수 있다.

1.  자기 자신은 자기를 친구로 생각할 것인가? $a \sim_R a$
2.  $a$가 $b$를 친구로 생각하면 $b$는 $a$를 친구로 생각하는가? $a \sim_R b \Rightarrow b \sim_R a ?$
3.  $a$가 $b$를 친구로 생각하고 $b$가 $c$를 친구로 생각하면 $a$는 $c$를 친구로 생각하는가? $a \sim_R b \land b \sim_R c \Rightarrow a \sim_R c ?$

## 동치 관계

집합 $A$와 관계 $R \subseteq A \times A$가 있을 때, `동치 관계(equivalence relation)`는 다음을 만족하는 관계이다.

$$ \begin{aligned} & \text{반사관계(reflexive relation)} & \qquad & x \in A \Rightarrow (x,x) \in R & \qquad & x \sim_R x \\ & \text{대칭관계(symmetric relation)} & \qquad & (x,y) \in R \Rightarrow (y,x) \in R & \qquad & x \sim_R y \Rightarrow y \sim_R x \\ & \text{추이관계(transitive relation)} & \qquad & (x,y) \in R \land (y,z) \in R \Rightarrow (x,z) \in R & \qquad & x \sim_R y \land y \sim_R z \Rightarrow x \sim_R z \\ \end{aligned} $$

### 참고

동치 관계에 있는 두 원소는 동일한 그룹으로 볼 수 있다.

### 예시1

집합 $A = \{ 1,2,3,4 \}$로 동치 관계를 만들어보자.

대칭관계와 추이관계는 $A$의 모든 원소가 만족할 필요가 없다. 하지만 반사관계는 모든 원소에 대해 반드시 만족해야 한다. 따라서 최소한 동치관계에는 다음의 원소들이 포함되어야 하며 동치 관계의 `필요 조건(necessary condition)`이라고 볼 수 있다.

$$ R = \{ \{ 1,1 \}, \{ 2,2 \}, \{ 3,3 \}, \{ 4,4 \} \} $$

만약 $\{ 1,2 \}$를 $R$에 포함할 경우 대칭관계에 의해 $\{ 2,1 \}$도 포함되어야 하며, 둘중 하나가 빠질경우 둘다 빠져야 된다.

### 예시2

집합 $A$와 관계 $R:= \{ (X \times Y) \in P(A) \times P(A) | \exist f : P(A) \rightarrow P(A), \quad f \text { is bijective} \}$이 있을 때, $R$은 동치 관계이다.

[반사관계]  
$id_{P(A)}$가 전단사 함수이기 때문에 $R$은 반사관계를 만족시키는 모든 원소를 포함하고 있다. $\quad {_\blacksquare}$

[대칭관계]  
$$ \begin{aligned} & X \sim_R Y \\ \Leftrightarrow \enspace & \exist f : P(A) \rightarrow P(A), \quad Y = f(X), \quad f\text{ is bijective} \\ \Leftrightarrow \enspace & \exist f^{-1} : P(A) \rightarrow P(A) , \quad X = f^{-1}(Y) \quad f^{-1} \text{ is bijective} \quad (\because \text{역함수 명제1,2}) \\ \Leftrightarrow \enspace & Y \sim_R X \quad {_\blacksquare} \end{aligned} $$

[추이관계]

$$ \begin{aligned} & X \sim_R Y \land Y \sim_R Z \\ \Leftrightarrow \enspace & \exist f,g : P(A) \rightarrow P(A), \quad Y = f(X), \quad Z=g(Y), \quad f,g \text{ is bijective} \\ \Rightarrow \enspace & Z = g(f(X)), \quad g \circ f \text{ is bijective} \quad (\because \text{전단사 함수 명제1}) \\ \Leftrightarrow \enspace & X \sim_R Z \quad {_\blacksquare} \end{aligned} $$