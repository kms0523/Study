# Neighborhood
$\mathbf x \in \R^n$의 `neighborhood`는 다음을 만족하는 $\R^n$의 부분집합 $\mathcal N_\mathbf x$이다.
$$ \exist \epsilon > 0, \quad  B_\epsilon(\mathbf x) \subset \mathcal N_\mathbf x $$

정의에서 알 수 있듯이, neighborhood는 임의의 크기의 $\mathbf x$에서의 open ball을 포함하는 집합이지만 neighborhood 자체가 open set은 아니다. 따라서, $\mathbf x$주위의 영역을 표현할 때, open set인 조건을 포함하지 않기 위해 사용된다. 

만약, 어떤 집합이 모든 점에서 Neighborhood가 존재한다면 그 집합은 open set이 된다.

> 참고  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5  

# Closure
부분집합 $U \subset \R^n$이 있을 때, 다음과 같이 정의된 부분집합 $\bar U$를 $U$의 `closure`라고 한다.
$$ \bar U := \{ \mathbf x \in \R^n \enspace | \enspace \forall r>0, \quad B_r(\mathbf x) \cap U \neq \empty \} $$

closure는 $U$를 포함하는 가장 작은 closed set이라는 의미다.

따라서 closed set의 closure는 자기 자신이 된다.

> 참고  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5  

# Interior
부분집합 $U \subset \R^n$이 있을 때, 다음과 같이 정의된 부분집합 $\mathring U$를 $U$의 `interior`라고 한다.
$$ \mathring U := \{ \mathbf x \in \R^n \enspace | \enspace \exist r > 0 \quad s.t \quad  B_r(\mathbf x) \subset U \} $$

interior는 $U$에 포함된 가장 큰 open set이라는 의미다.

따라서 open set의 interior는 자기 자신이 된다.

> 참고  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5  

# Boudnary of subset
부분집합 $U \subset \R^n$이 있을 때, 다음과 같이 정의된 부분집합 $\partial U$를 $U$의 `boundary`라고 한다.
$$ \partial U := \{ \mathbf x \in \R^n \enspace | \enspace \forall \mathcal N_\mathbf x, \quad \mathcal N_\mathbf x \cap U \neq \empty \enspace \land \enspace \mathcal N_\mathbf x \cap U^c \neq \empty \} $$

이는 $\mathbf x$의 모든 neighborhood가 $U$와 $U^c$ 모두에게 교집합이 존재하는 경우를 boundary로 보겠다는 의미이다.

$\partial U$에 대해서 다음과 같은 관계식이 성립한다.
$$ \begin{aligned} \bar U &= U \cup \partial U \\ \mathring U &= U - \partial U \\ \partial U &= \bar U - \mathring U \end{aligned}  $$

> 참고  
> [Book] (Hubbard & Hubbard) Vector Calculus, Linear Algebra, and Differential Forms_ A Unified Approach chap 1.5  
