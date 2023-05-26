# Partition
## Definition
집합 $S$와 임의의 $S$의 subset family $H$가 있다고 하자.

이 때, $H$가 다음을 만족하는 경우 $H$를 `분할(partition)`이라고 한다.

$$ \begin{gathered} \empty \notin H \\ \forall H_i,H_j \in H, \enspace H_i \neq H_j \implies H_i \cap H_j = \empty \\ \bigcup H = S \end{gathered} $$

### 예시
다음과 같이 집합을 정의하자.  
$$[k] := \{ x \in \Z | x = 3a + k, \quad a,k \in \Z \}$$

정의에 의해 $\cdots [-3] = [0] = [3] \cdots, \quad \cdots [-2] = [1] = [4] \cdots, \quad \cdots [-1] = [2] = [5] \cdots$ 이다.

이 때, $[0],[1],[2]$는 각각 공집합이 아니며 교집합은 공집합이고 합집합은 $\Z$가 된다.

따라서 $F := \{ [x] | x \in \Z \} = \{ [0], [1], [2] \}$는 분할이다.

### 명제1
Set $S$와 equivalence relation $\sim \subseteq S \times S$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$  S/\sim \text{ is a partition of } S$$

**proof**

[$\empty$]  
Equivalence relation은 reflexive property가 있음으로 다음이 성립한다.

$$ \forall [x] \in S/\sim, \enspace x \in [x] \implies \empty \notin S/\sim \qed  $$

[$\cap$]  
Equivalence class의 성질에 의해 다음이 성립한다.

$$ \forall [x],[y] \in S/\sim, \enspace [x]\neq[y] \implies [x] \cap [y] = \empty \qed $$

[$\cup$]  
Quotient set의 정의에 의해 다음이 성립한다.

$$ \forall x \in S, \enspace \exist [x]\in S/\sim \st x \in [x] \implies \bigcup (S/\sim) = S \qed $$

### 명제2
집합 $S$와 partition $F$가 있다고 하자.

이 때, $S$에 동치 관계가 존재함을 증명하여라.

$$ \exist! \text{Equivalence relation } \sim \subseteq S \times S \st S/\sim = F $$

**proof**

Relation $\sim \subseteq S \times S$을 다음과 같이 정의하자.

$$ \sim := \Set{ (a,b) \in S \times S | a,b \in F_i \text{ for some } F_i \in F} $$

[existence]  
-[Equivalence Relation]
--[reflexive]  
$S$의 임의의 element를 $s$라고 하자.

$F$가 partition임으로 다음이 성립한다.

$$ \exist F_i \in F \st s \in F_i $$

이 때, $s,s \in F_i$로 보면 $\sim$의 정의에 의해 다음이 성립한다.

$$ s \sim s \qed $$

--[symmetric]  
$x \sim y$라고 하자.

그러면 relation의 construction에 의해 다음이 성립한다.

$$ \exist F_i \in F \st x,y \in F_i $$

따라서, $y,x \in F_i$로 보면 $\sim$의 정의에 의해 다음이 성립한다.

$$ y \sim x \qed $$

--[transitive]  
$x \sim y, \enspace y \sim z$라고 하자.

그러면 relation의 construction에 의해 다음이 성립한다.

$$ \begin{gathered} \exist F_i \in F \st x,y \in F_i \\ \exist F_j \in F \st y,z \in F_j \end{gathered}  $$

따라서, $F_i \cap F_j \neq \empty$임으로 partition의 정의에 의해 다음이 성립한다.

$$ F_i = F_j $$

즉, $x,z \in F_i = F_j$임으로 $\sim$의 정의에 의해 다음이 성립한다.

$$ x \sim z $$

-[$F = S/\sim$]    
--[$F \subseteq S/\sim$]  
$F$의 임의의 element를 $F_i$라고 하자.

$\sim$의 construction에 의해 $F_i$에 있는 모든 elements들은 equivalence relation을 갖음으로 다음이 성립한다.

$$ \exist! [x] \in S/\sim \st \forall y \in F_i, \enspace y \in [x] $$

따라서, $F_i = [x] \implies F_i \in S/\sim$임으로 다음이 성립한다.

$$ F \subseteq S/\sim \qed $$

--[$S/\sim \subseteq F$]  
$S/\sim$의 임의의 element를 $[x]$라고 하자.

$\sim$의 construction에 의해 다음이 성립한다.

$$ \exist! F_i \in F \st \forall y \in [x], \enspace y \in F_i $$

따라서, $[x] = F_i \implies [x] \in F$임으로 다음이 성립한다.

$$ S/\sim \subseteq F \qed $$

[uniqueness]
$\sim' \subseteq S \times S$가 $S/\sim' = F$를 만족한다고 하자.

그러면 $F = S/\sim$임으로 다음이 성립한다.

$$S/\sim' = S/\sim \implies \sim' = \sim \qed$$

#### 참고1
Equivalence relation과 partition 사이에는 일대일 대응 관계가 존재함을 알 수 있다.

#### 참고2
꼭 equivalence relation만 partition을 만들어 내는 것은 아니다.

예를 들어 $X:=\Set{1,2,3}$으로 두고 $\sim :=\Set{\Set{1,3},\Set{2,2},\Set{3,1}}$두자.

그러면 $\sim$은 equivalence relation이 아니다. 

이 때, $X$의 subset을 다음과 같이 정의하자.

$$ [i] := \Set{x \in X | i \sim x} $$

정의에 의해 다음이 성립한다.

$$ [1] = \Set{3}, \enspace [2] = \Set{2}, \enspace [3] = \Set{1}$$

따라서, $\sim$에 의해 만들어진 $[i]$의 family를 $F$라고 하면 $F$는 $X$의 partition이 된다.

$$ F = \Set{[1],[2],[3]} = \Set{\Set{3},\Set{2},\Set{1}} $$