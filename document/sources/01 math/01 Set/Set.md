# Set

## 들어가며
이 내용은 [집합론 기초 - 수학의 즐거움 youtube](https://www.youtube.com/playlist?list=PL4m4z_pFWq2rboSAR7cvRLcCI36Fb8ruF)를 공부한 내용을 바탕으로 작성하였다.

## 정의
`집합(set = collection = family)`이란 서로 뚜렷이 구분되는 원소들의 모임이다.

## 상집합

집합 $S$와 동치 관계 $R \subseteq S \times S$이 있을 때, `상집합(quotient set)` [S]_R은 다음과 같이 정의되는 집합이다.

$$ [S]_R = S/R = \{ [s]_R | s \in S \} $$

즉, 동치류의 집합이다.

## 첨수 집합

$i \in I$에 대해 집합 $S_i$가 대응될 때 $i$를 `첨수(index)`, $I$를 `첨수 집합(index set)` 이라고 한다.

## 분할

집합 $S$와 $S_i \subseteq S$에 대응하는 첨수 집합 $I$가 있을 때, 다음을 만족한다고 하자.

$$ i \in I, \quad S_i \neq \empty \enspace \land \enspace j,k \in I, S_j \neq S_k \Rightarrow S_j \cap S_k = \empty \enspace \land \enspace \bigcup_{i \in I} S_i = S $$

이 때, `분할(partition)` $F$는 다음과 같이 정의된 집합이다.

$$ F := \{ S_i \subseteq S | i \in I \} $$

즉, 분할은 부분집합들의 집합이며, 각각의 부분 집합들은 공집합이 아니면서 서로 같거나 아니면 겹치지 않는 집합들이며 부분집합들의 합은 전체가 되도록 구성되어 있다.

### 예시

다음과 같이 집합을 정의하자.  
$$[k] := \{ x \in \Z | x = 3a + k, \quad a,k \in \Z \}$$

정의에 의해 $\cdots [-3] = [0] = [3] \cdots, \quad \cdots [-2] = [1] = [4] \cdots, \quad \cdots [-1] = [2] = [5] \cdots$ 이다.

이 때, $[0],[1],[2]$는 각각 공집합이 아니며 교집합은 공집합이고 합집합은 $\Z$가 된다.

따라서 $F := \{ [x] | x \in \Z \} = \{ [0], [1], [2] \}$는 분할이다.

### 명제1

집합 $S$와 동치 관계 $R \subseteq S \times S$가 있을 때, $[S]_R$이 $S$의 분할임을 증명하여라.

**proof**

동치류 명제1에 의해 $x \in [S]_R$에 대해 $x \neq \empty$이다. 동치류 명제4에 의해 $x,y \in [S]_R$에 대해 $x \neq y \Rightarrow x \cap y = \empty$이다. 또한 $\bigcup_{x \in [S]_ R} x = S$이다. $\quad {_\blacksquare}$

### 명제2

집합 $S$와 분할 $F$가 있을 때, $S$에 동치 관계가 존재함을 증명하여라.

**proof**

적절한 첨수 집합 $I$가 존재하여, $F = \{ S_i \subseteq S | i \in I \}$라 하자.

다음과 같이 정의된 관계 $R$이 동치 관계임을 보여 명제를 증명하려고 한다.

$$ R = \{ (a,b) \in S \times S | i \in I, \quad a,b \in S_i\} $$

[반사관계]  
$$ \begin{aligned} & s \in S \\ \Leftrightarrow \enspace & \exist i \in I, \quad s \in S_i \\ \Leftrightarrow \enspace & (s,s) \in R \quad {_\blacksquare} \end{aligned} $$

[대칭관계]  
$$ \begin{aligned} & (x,y) \in R \\ \Leftrightarrow \enspace & \exist i \in I, \quad x,y \in S_i \\ \Leftrightarrow \enspace & (y,x) \in R \quad {_\blacksquare} \end{aligned} $$

[추이관계]  
$$ \begin{aligned} & (x,y), (y,z) \in R \\ \Leftrightarrow \enspace & \exist i,j \in I, \quad x,y \in S_i, \quad y,z \in S_j \\ \Rightarrow \enspace & S_i = S_j \quad (\because S_i \cap S_j \neq \empty \Rightarrow S_i = S_j \text{ by definition of partition}) \\ \Rightarrow \enspace & (x,z) \in R \quad {_\blacksquare} \end{aligned} $$

이렇게 정의된 $R$을 $F$에 의해 유도된 동치관계라고 한다.

이 때, $R$은 $F$에 의해 분할된 각 부분집합내의 원소끼리 관계를 맺어준것이다.

### 명제3

집합 $S$, 분할 $F$와 $F$에 의해 유도된 동치 관계 $R$가 있을 때, $[S]_R =F$을 증명하여라.

**proof**

적절한 첨수 집합 $I$가 존재하여 $F = \{ S_i \in S | i \in I \}$라 하자.

이 때, $R = \{ (a,b) \in S \times S | \exist i \in I, \quad a,b \in S_i \}$임으로

$$ \begin{aligned} & X \in [S]_R \\ \Leftrightarrow \enspace & \exist i \in I, \quad X = S_i \quad (\because \text{definition of }R) \\ \Leftrightarrow \enspace & X \in F \quad {_\blacksquare} \end{aligned} $$

### 명제4

집합 $S$, 동치관계 $R$이 주어졌을 때, 분할 $[S]_R$에 의해 유도된 동치관계 $R^*$에 대해 $R = R^*$임을 증명하여라.

**proof**

$[S]_R$에 의해 유도된 동치관계는 다음과 같다.

$$ R^* := \{ (a,b) \in S \times S | \exists t \in S \quad s.t. \quad a,b \in [t]_R \} $$

$$ \begin{aligned} & (x,y) \in R \\ \Leftrightarrow \enspace & \exist t \in S \quad s.t. \quad x,y \in [t]_R & \quad \\ \Leftrightarrow \enspace & (x,y) \in R^* & \quad & (\because \text{ definition of } R^*) \end{aligned} $$

### 참고

명제 1-4에 의해 동치 관계와 분할 사이에는 일대일 대응 관계가 존재함을 알 수 있다.

## 부분순서

집합 $A$와 관계 $R \in A \times A$ 있을 떄, `부분순서(partial order)` $\le(\sim_ R)$는 다음을 만족하는 $R$이다.

$$ \begin{aligned} & \text{반사관계(reflexive relation)} & \qquad & x \in A \Rightarrow (x,x) \in R & \qquad & x \le x \\ & \text{반대칭관계(anti-symmetric relation)} & \qquad & (x,y) \in R \land (y,x) \in R \Rightarrow x = y & \qquad & x \le y \land y \le x \Rightarrow x=y \\ & \text{추이관계(transitive relation)} & \qquad & (x,y) \in R \land (y,z) \in R \Rightarrow (x,z) \in R & \qquad & x \le y \land y \le z \Rightarrow x \le z \\ \end{aligned} $$

## 부분순서집합

집합 $A$와 부분순서 $\le$가 있을 때, 부분순서가 주어진 집합 $(A, \le)$를 `부분순서집합(partially ordered set, poset)`이라고 한다.

### 참고

부분순서 집합은 부분순서의 정의에 따라 모든 원소에 대해서 반사관계를 만족해야하지만 반대칭관계나 추이관계는 모든 원소에 대해 만족할 필요가 없다. 그저 비교가능한 원소들에 대해서만 반대칭관계와 추이관계를 만족하면 된다.

### 예시

집합 $A$와 $P(A)$가 있을 때, $(P(A), \subseteq)$는 부분순서집합이다.

## 극대,극소 원소

부분순서집합 $(A,\le)$와 $a \in A$가 있을 때,

$\forall b \in A, \quad a \le b \Rightarrow a=b$이면 $a$를 `극대 원소(maximal element)`,

$\forall b \in A, \quad b \le a \Rightarrow a=b$이면 $a$를 `극소 원소(maximal element)`라 한다.

즉, 극대 원소는 비교가능한 원소중 가장 큰 원소, 극소 원소는 비교가능한 원소중 가장 작은 원소이다.

## 전순서집합

부분순서집합 $(A,\le)$가 있을 때, `전순서집합(totally ordered set)`은 다음을 만족하는 $(A,\le)$이다.

$$ a,b \in A \Rightarrow a \le b \lor b \le a $$

### 참고

전순서집합은 부분순서집합과 다르게 모든 원소가 비교가능해야함을 의미한다.

## 사슬

부분순서집합 $(A,\le)$가 주어졌을 때, 전순서집합인 $(C \subseteq A, \le)$를 `사슬(chain)`이라 한다.

### 참고

$A$안에서는 모든 원소가 비교가능할 필요는 없지만 적어도 $C$안에서는 모든 원소가 비교가능해야 한다.

### 초른의 보조정리

부분순서집합 $(A,\le)$의 모든 사슬 $C$가 상계를 가지면 $S$는 극대원소를 갖는다.

#### 참고

[초른의 보조정리 - 2!=2 블로그](https://chocobear.tistory.com/69)