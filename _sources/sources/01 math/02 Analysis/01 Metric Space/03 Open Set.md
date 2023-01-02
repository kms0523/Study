# Open set
## 정의
Metric space $M$과 $S \le M$이 있다고 하자.

$\forall x \in S$에 대해서 다음을 만족하면 $S$를 $M$에서의 `open set`이라고 한다.

$$ \exist r \in \R^+ \quad s.t. \quad B_M(x,r) \le S $$

> Reference  
> {cite}`hubbard` chap 1.5  

### 명제1
Metric space $M$이 있을 때, 다음을 증명하여라.

$$ \text {Any union of open sets on } M \text{ is open set on } M. $$

**Proof**

$M$의 모든 open set의 집합을 $S$라 하고 집합 $X$를 다음과 같이 정의하자.

$$ X := \bigcup_{s \in S} s $$

$\forall x \in X$에 대해 다음을 만족한다.

$$ \exist s \in S \quad s.t. \quad x \in s $$
 
이 때, $s$는 $M$위의 open set임으로, 다음이 성립한다.

$$\exist r \in \R^+ \quad s.t. \quad B_M(x,r) \le s$$

$X$의 정의에 의해 $s \le X$임으로, 다음이 성립한다.

$$\exist r \in \R^+ \quad s.t. \quad B_M(x,r) \le X$$

따라서 $X$는 $M$에서의 open set이다. $\qed$

> Refrence  
> {cite}`apostol` chapter 3.7  
> {cite}`hubbard` prob 1.5.3

### 명제2
Metric space $M$이 있을 때, 다음을 증명하여라.

$$ \text {Any finite intersection of open sets is open.} $$

**Proof**

$M$의 모든 open set의 집합을 $S$라 하고 $s_i \in S, \enspace i = 1, \cdots, n$일 떄, 집합 $X$를 다음과 같이 정의하자.

$$ X := \bigcap_{i=1}^n s_i $$

$\forall x \in X$에 대해, 다음이 성립한다.

$$ x \in s_i, \enspace i=1,\cdots,n $$

이 때, $s_i$는 open set임으로 다음이 성립한다.

$$\exist r_i \quad s.t. \quad B_M(x, r_i) \le s_i, \enspace i=1,\cdots,n$$

$\min(\{ r_i \}) = r$이라 하면 다음이 성립한다.

$$ B_M(x,r) \le s_i, \enspace i=1,\cdots,n $$

$X$의 정의에 의해 다음이 성립한다.

$$ B_M(x,r) \le X$$

따라서 $X$는 $M$에서의 open set이다. $\qed$

> Refrence  
> {cite}`apostol` chatper 3.8  
> {cite}`hubbard` prob 1.5.3
> 
### 명제3
Metric space $M$이 있을 때, 다음을 증명하여라.

$$ \text {An infinite intersection of open sets is not necessarily open.} $$

**Proof**

Metric space $\R$위의 open set들의 집합을 $S$를 다음과 같이 정의하자.

$$ S := \{ {(-1/n, 1/n)} \enspace | \enspace i=1,2,3, \cdots \} $$

모든 $s \in S$의 intersection은 $\{ 0 \}$이 되고 $\{ 0 \}$은 open set이 아니다. 

즉, infinite intersection을 고려하는 경우 open set이 아닌 경우가 있다. $\qed$

> Refrence  
> {cite}`apostol` chapter 3.8  
> {cite}`hubbard` prob 1.5.3

### 명제4
Metric space $M$이 있다고 하자.

이 때, 다음을 증명하여라.

$$ M \text{ is an open set on } M $$

**Proof**

$x \in M$이 있다고 하자.

임의의 $r \in \R^+$에 대해, $B_M(x,r)$의 정의에 의해 다음이 성립한다.

$$ B_M(x,r) \le M $$

이로 인해 $\forall x \in M$에 대해, 다음이 성립한다.

$$ \exist r \in R^+ \quad s.t. \quad B_M(x,r) \le M $$

따라서 $M$는 $M$에서의 open set이 된다.$\qed$


#### 따름명제4.1
Metric space $M$과 $S \le M$이 있다고 하자.

이 때, 다음을 증명하여라.

$$ S \text{ is an open set on } S $$

**Proof**

$\forall x \in S$에 대해, $B_S(x,r) = B_M(x,r) \cap S$임으로 다음이 성립한다.

$$ B_S(x,r) \le S $$

따라서, $S$는 $S$에서의 open set이 된다.$\qed$

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/1169561/why-is-a-metric-space-an-open-subset-of-itself)

### 명제5
Metric space $M$이 있다고 하자.

이 때, 다음을 증명하여라.

$$ \empty \text{ is an open set on } M $$

**Proof**

open set의 정의상, $x \in \empty$에 대해 open ball을 고려해야 되는데 공집합에서 원소를 뽑을 수는 없다.

따라서, 가정이 항상 거짓인 `공허하게 참인 명제(vacuously true statement)`가 된다.$\qed$

### 명제6
Metric space $M$이 있다고 하자.

이 떄, 다음을 증명하여라.

$$ \text{open ball in } M \text{ is an open set of } M$$

**Proof**  
$x \in M, r \in \R^+$이 있다고 하자.

$y \in B_M(x,r)$에 대해 $B_M(y,\epsilon)$을 고려해보자.

$\forall z \in B_M(y, \epsilon)$이 있을 떄, 다음이 성립한다.

$$ \begin{aligned} d(x,z) &< d(x,y) + d(y,z) \\&< d(x,y) + \epsilon \end{aligned} $$

이 떄, $\epsilon = r - d(x,y)$로 두면 다음이 성립한다.

$$ d(x,z) < r $$

$\forall z \in B_M(y, \epsilon)$에 대해 $d(x,z) < r$임으로 다음이 성립한다.

$$ B_M(y,\epsilon) \le B_M(x,r) $$

이를 정리하면 다음과 같다.

$$ \forall y \in B_M(x,r) \quad \exist\epsilon \in \R^+ \quad s.t. \quad B_M(y,r) \le B_M(x,r) $$

open set의 정의에 의해 $B_M(x,r)$은 $M$의 open set이다. $\qed$

### 명제7
Metric space $M$이 있다고 하자.

$M$의 subset $U$가 있을 때, 다음을 증명하여라.

$$ U \text{ is an open set} \iff U \text{ is an union of some collection of open balls} $$

**Proof**

[$\implies$]  
$U$의 정의에 의해 다음이 성립한다.

$$ \forall x \in U, \quad \exist r_x \in \R^+ \quad s.t. \quad B_M(x,r_x) \le S $$

따라서, 다음이 성립한다.

$$ U = \bigcup_{x \in U} B_M(x,r_x) \qed $$

[$\impliedby$]  
명제6에 의해 open ball은 open set이다.

open set의 성질에 의해 open set의 union은 open set이 된다. $\qed$

### 참고
명제1,2,4,5을 만족하는 집합족의 원소를 open set으로 정의할 경우 거리가 정의되어 있지 않은 공간에서도 open set과 closed set을 정의할 수 있다.

즉, 더 일반적인 형태의 open set과 closed set을 정의할 수 있게 된다.

> Reference  
> {cite}`hubbard` p.102 


### 예시1
부분집합 $U \subset \R^2$가 아래 그림과 같이 회색으로 표현된 영역에서 boundary를 뺀 부분이라고 하자.

```{figure} _image/0301.png
```

그러면 그림과 같이, 흰색으로 표현된 $\mathbf x \in U$를 어떻게 잡아도 검은색 실선으로 표현된 $B_r(\mathbf X)$이 존재하게 된다.

즉, open set이 되기 위해서는 기하학적으로 boundary를 하나도 포함하지 않아야 된다는 것을 알 수 있다.

> Reference  
> {cite}`hubbard` chap 1.5  

### 예시2
$a,b,c,d \in \R$라 하자.

* $a < b$라 할 때, $(a,b) := \{ x \in \R \enspace | \enspace a < x < b \}$는 open set이다.
* $a < b, \enspace c < d$라 할때, $(a,b) \times (c,d) := \{ (x,y) \in \R^2 \enspace | \enspace a < x < b, \enspace c < y < d \}$는 open set이다.
* $(a,\infty)$는 open set이다.
* $(-\infty, a)$는 open set이다.

> Reference  
> {cite}`hubbard` chap 1.5  