# Relation
집합 $A,B$가 있다고 하자.

`이항관계(binary relation)` $R$은 $A \times B$의 subset이다.

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

