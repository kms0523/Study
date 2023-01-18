# Neighborhood
## 정의
Metric space $M$이 있다고 하자.

$x \in M$의 `neighborhood`는 다음을 만족하는 $\mathcal N_x \le M$이다.

$$ \exist \epsilon > 0, \quad  B(x,\epsilon) \le \mathcal N_x $$

> Reference  
> {cite}`hubbard` chap 1.5 

### 참고
정의에서 알 수 있듯이, neighborhood는 $x$를 중심으로 하는 어떤 open ball을 포함하는 집합일 뿐이다. 즉, neighborhood 자체가 반드시 open set일 필요는 없다. 

> Reference  
> {cite}`hubbard` chap 1.5 

### 명제1
Metric space $M$과 $S \le M$이 있다고 하자.

이 때, 다음을 증명하여라.

$$ \forall x \in S, \quad \exist \mathcal N_x \quad s.t. \quad \mathcal N_x \le S \iff S \text{ is an open set. } $$

**Proof**

[$\implies$]  

$$ \begin{aligned} x \in S &\implies \mathcal N_x \le S \\ &\implies \exist \epsilon \quad s.t. \quad B(x,\epsilon) \le \mathcal N_x \\ &\implies  B(x,\epsilon) \le U \\ &\iff U \text{ is an open set.} \quad {_\blacksquare} \end{aligned} $$

[$\Leftarrow$]  

$$ \begin{aligned} x \in S &\implies \exist r >0 \quad s.t. \quad B(x,r) \le U \\ &\implies \exist \epsilon \quad s.t. \quad 0 < \epsilon < r \\ &\implies \exist \mathcal N_x \quad s.t. \quad B(x,\epsilon) \le \mathcal N_x \le B(x,r) \\ &\implies  \mathcal N_x \le U \quad {_\blacksquare} \end{aligned} $$

> Reference  
> {cite}`hubbard` chap 1.5 
 
### 명제2
Metric space $M$있다고 하자.

$x,y \in M$이 있을 때, 다음을 증명하여라.

$$ \text{disjoint }x,y \implies \exist \text{ disjoint } \mathcal N_x, \mathcal N_y $$

**Proof**

$x \neq y$임으로, open ball의 성질에 의해 다음이 성립한다.

$$ \exist r \quad s.t. \quad B_M(x,r) \text{ and } B_M(y,r) \text{ are disjoint.} $$

따라서, $\mathcal N_x = B_M(x,r), \mathcal N_y = B_M(y,r)$라고 둘 수 있음으로, $\mathcal N_x, \mathcal N_y$는 disjoint이다. 

따라서, $x,y$는 항상 disjoint neighborhood를 갖는다. $\quad\tiny\blacksquare$

> Reference  
> [Proof Wiki](https://proofwiki.org/wiki/Distinct_Points_in_Metric_Space_have_Disjoint_Neighborhoods)