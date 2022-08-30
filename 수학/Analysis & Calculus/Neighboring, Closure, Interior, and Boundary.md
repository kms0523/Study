# Neighborhood
$\mathbf x \in \R^n$의 `neighborhood`는 다음을 만족하는 $\R^n$의 부분집합 $\mathcal N_\mathbf x$이다.
$$ \exist \epsilon > 0, \quad  B_\epsilon(\mathbf x) \subseteq \mathcal N_\mathbf x $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5 

### 참고
정의에서 알 수 있듯이, neighborhood는 $\mathbf x$를 중심으로 하는 어떤 open ball을 포함하는 집합일 뿐이다. 즉, neighborhood 자체가 반드시 open set일 필요는 없다. 

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5 

### 명제
부분집합 $U \subset \R^n$이 있을 때, 다음을 증명하여라.

$$ \forall x \in U, \quad \exist \mathcal N_x \quad s.t. \quad \mathcal N_x \subseteq U \Leftrightarrow U \text{ is an open set } $$

**Proof**

[$\Rightarrow$]  
$$ \begin{aligned} x \in U &\Rightarrow \mathcal N_x \subseteq U \\ &\Rightarrow \exist \epsilon \quad s.t. \quad B_\epsilon(x) \subseteq \mathcal N_x \\ &\Rightarrow \exist \epsilon \quad s.t. \quad B_\epsilon(x) \subseteq U \\ &\Leftrightarrow U \text{ is an open set.} \quad {_\blacksquare} \end{aligned} $$

[$\Leftarrow$]  
$$ \begin{aligned} x \in U &\Rightarrow \exist r >0 \quad s.t. \quad B_r(x) \subseteq U \\ &\Rightarrow \exist \epsilon \quad s.t. \quad 0 < \epsilon < r \\ &\Rightarrow \exist \mathcal N_x \quad s.t. \quad \mathcal N_x \subseteq B_r(x) \\ &\Rightarrow \exist \mathcal N_x \quad s.t. \quad \mathcal N_x \subseteq U \end{aligned} $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5 
 

# Closure
부분집합 $U \subset \R^n$이 있을 때, 다음과 같이 정의된 부분집합 $\bar U$를 $U$의 `closure`라고 한다.
$$ \bar U := \{ \mathbf x \in \R^n \enspace | \enspace \forall r>0, \quad B_r(\mathbf x) \cap U \neq \empty \} $$

closure는 $U$를 포함하는 가장 작은 closed set이라는 의미다.

따라서 closed set의 closure는 자기 자신이 된다.

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5  

# Interior
부분집합 $U \subset \R^n$이 있을 때, 다음과 같이 정의된 부분집합 $\mathring U$를 $U$의 `interior`라고 한다.
$$ \mathring U := \{ \mathbf x \in \R^n \enspace | \enspace \exist r > 0 \quad s.t \quad  B_r(\mathbf x) \subset U \} $$

interior는 $U$에 포함된 가장 큰 open set이라는 의미다.

따라서 open set의 interior는 자기 자신이 된다.

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5  

# Boudnary of subset
부분집합 $U \subset \R^n$이 있을 때, 다음과 같이 정의된 부분집합 $\partial U$를 $U$의 `boundary`라고 한다.
$$ \partial U := \{ \mathbf x \in \R^n \enspace | \enspace \forall \mathcal N_\mathbf x, \quad \mathcal N_\mathbf x \cap U \neq \empty \enspace \land \enspace \mathcal N_\mathbf x \cap U^c \neq \empty \} $$

이는 $\mathbf x$의 모든 neighborhood가 $U$와 $U^c$ 모두에게 교집합이 존재하는 경우를 boundary로 보겠다는 의미이다.

$\partial U$에 대해서 다음과 같은 관계식이 성립한다.
$$ \begin{aligned} \bar U &= U \cup \partial U \\ \mathring U &= U - \partial U \\ \partial U &= \bar U - \mathring U \end{aligned}  $$

> Reference  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5  
