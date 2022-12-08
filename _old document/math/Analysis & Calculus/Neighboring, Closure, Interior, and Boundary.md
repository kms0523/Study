# Neighborhood
Metric space $M$이 있다고 하자.

$x \in M$의 `neighborhood`는 다음을 만족하는 $\mathcal N_x \le M$이다.
$$ \exist \epsilon > 0, \quad  B(x,\epsilon) \le \mathcal N_x $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5 

### 참고
정의에서 알 수 있듯이, neighborhood는 $x$를 중심으로 하는 어떤 open ball을 포함하는 집합일 뿐이다. 즉, neighborhood 자체가 반드시 open set일 필요는 없다. 

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5 

### 명제1
Metric space $M$과 $S \le M$이 있다고 하자.

이 때, 다음을 증명하여라.
$$ \forall x \in S, \quad \exist \mathcal N_x \quad s.t. \quad \mathcal N_x \le S \Leftrightarrow S \text{ is an open set. } $$

**Proof**

[$\Rightarrow$]  
$$ \begin{aligned} x \in S &\Rightarrow \mathcal N_x \le S \\ &\Rightarrow \exist \epsilon \quad s.t. \quad B(x,\epsilon) \le \mathcal N_x \\ &\Rightarrow  B(x,\epsilon) \le U \\ &\Leftrightarrow U \text{ is an open set.} \quad {_\blacksquare} \end{aligned} $$

[$\Leftarrow$]  
$$ \begin{aligned} x \in S &\Rightarrow \exist r >0 \quad s.t. \quad B(x,r) \le U \\ &\Rightarrow \exist \epsilon \quad s.t. \quad 0 < \epsilon < r \\ &\Rightarrow \exist \mathcal N_x \quad s.t. \quad B(x,\epsilon) \le \mathcal N_x \le B(x,r) \\ &\Rightarrow  \mathcal N_x \le U \quad {_\blacksquare} \end{aligned} $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5 
 
### 명제2
Metric space $M$있다고 하자.

$x,y \in M$이 있을 때, 다음을 증명하여라.
$$ \text{disjoint }x,y \Rightarrow \exist \text{ disjoint } \mathcal N_x, \mathcal N_y $$

**Proof**

$x \neq y$임으로, open ball의 성질에 의해 다음이 성립한다.
$$ \exist r \quad s.t. \quad B_M(x,r) \text{ and } B_M(y,r) \text{ are disjoint.} $$

따라서, $\mathcal N_x = B_M(x,r), \mathcal N_y = B_M(y,r)$라고 둘 수 있음으로, $\mathcal N_x, \mathcal N_y$는 disjoint이다. 

따라서, $x,y$는 항상 disjoint neighborhood를 갖는다. $\quad\tiny\blacksquare$

> Reference  
> [Proof Wiki](https://proofwiki.org/wiki/Distinct_Points_in_Metric_Space_have_Disjoint_Neighborhoods)

# Closure
Metric space $M$과 $S \le M$이 있다고 하자.

`Closure`는 다음과 같이 정의된 집합 $\overline S$이다.
$$ \overline S := \{ x \in M \enspace | \enspace \forall r>0, \quad B(x,r) \cap S \neq \empty \} $$

### 참고1
closure는 $U$를 포함하는 가장 작은 closed set이다.

### 참고2
closed set의 closure는 자기 자신이 된다.

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5  

# Interior
Metric space $M$과 $S \le M$이 있다고 하자.

`Interior`는 다음과 같이 정의된 집합 $\mathring S$이다.
$$ \mathring S := \{ x \in M \enspace | \enspace \exist r > 0 \quad s.t \quad  B(x,r) \subset U \} $$

### 참고1
interior는 $S$에 포함된 가장 큰 open set이다.

### 참고2
open set의 interior는 자기 자신이 된다.

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5  

# Boudnary of subset
Metric space $M$과 $S \le M$이 있다고 하자.

`Boundary`는 다음과 같이 정의된 집합 $\partial S$이다.
$$ \partial S := \{ x \in M \enspace | \enspace \forall \mathcal N_x, \quad \mathcal N_x \cap S \neq \empty \enspace \land \enspace \mathcal N_x \cap S^c \neq \empty \} $$

### 참고1
$x$의 모든 neighborhood가 $S$와 $S^c$ 모두에게 교집합이 존재하는 경우를 boundary로 보겠다는 의미이다.

### 참고2
$\partial U$에 대해서 다음과 같은 관계식이 성립한다.
$$ \begin{aligned} \bar U &= U \cup \partial U \\ \mathring U &= U - \partial U \\ \partial U &= \bar U - \mathring U \end{aligned}  $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5  
