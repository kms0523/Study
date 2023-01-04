# Basis
## 정의
Vector space $V/F$와 $\beta \subseteq V$가 있을 때, `기저(basis)`란 다음을 만족하는 부분집합이다.

$$ \beta \text{ is linearly independent set} \land \span(\beta) = V $$

### 명제1
Vector space $V/F$와 linearly independent set $S \subseteq V$가 있을 때, 집합 $F$를 다음과 같이 정의하자.

$$F := \{ A \subseteq V | S \subseteq A \land A \text{ is linearly independent}\}$$ 

이 때, $(F,\subseteq)$가 극대원소 $M$을 갖음을 증명하여라.

**Proof**  
<<<<<<< HEAD
$S \in F$임으로 다음이 성립한다.

$$ F \neq \empty $$

따라서, poset의 성질에 의해 다음이 성립한다.

$$ (F,\subseteq) \text{ is a poset} $$

$(F,\subseteq)$의 임의의 chain $C_i$를 다음과 같이 표현하자.

$$ C_i = \Set{A_{i1}, \cdots, A_{in}} \subseteq F $$

$C_i$는 전순서집합임으로 `일반성을 잃지 않고(without loss of generality, WLOG)` $A_{i1} \subseteq \cdots \subseteq A_{in}$라 가정하자. 

그러면 $C_i$는 항상 상계 $A_{in}$을 갖는다.

부분순서집합 $(F,\subseteq)$의 모든 사슬이 상계를 갖음으로, Zorn's lemma에 의해 $F$는 극대원소 $M$을 갖는다. $\qed$
=======
$S \in F$임으로 $F \neq \empty$이고 $(F,\subseteq)$은 partially ordered set이다. 

$(F,\subseteq)$의 임의의 사슬 $C_i = \{ A_{i1}, \cdots, A_{in} \} \subseteq F$에 대해, $C$는 전순서집합임으로 `일반성을 잃지 않고(without loss of generality, WLOG)` $A_{i1} \subseteq \cdots \subseteq A_{in}$라 가정할 수 있다. 따라서 $C_i$는 항상 상계 $A_{in}$을 갖는다.

부분순서집합 $(F,\subseteq)$의 모든 사슬이 상계를 갖음으로, `초른의 보조정리(Zorn's lemma)`에 의해 $F$는 극대원소 $M$을 갖는다. $\qed$
>>>>>>> 7e448f5baabbdae86ac17923c9c154564537bb13

### 명제2
정리 1의 극대원소 $M$이 $span(M)=V$을 만족함을 증명하여라.

**Proof**

$$ \begin{aligned} & V \neq span(M) \\ \Leftrightarrow \enspace & V - span(M) \neq \empty \\ \Leftrightarrow \enspace & \exist v \in V - span(M), \quad v \neq 0_V \\ \Rightarrow \enspace &  M \cup \{v\} \in F \enspace \land \enspace M \subseteq M \cup \{v\} \\ \Rightarrow \enspace & \Rightarrow \!\! \Leftarrow \text{maximality of } M \quad {_\blacksquare} \end{aligned} $$

### 명제3 (기저의 존재 정리)
모든 벡터공간 $V/F$이 기저를 갖음을 증명하여라.

**Proof** 

$V = \{ 0_V \}$인 경우 자명하게 $\beta = \emptyset$이다.

$V \neq \{ 0_V \}$인 경우  $\exist v \in V - \{ 0_V \}$이고 따라서 집합 $S = \{ av | a \in F \}$는 $V$의 선형 독립 집합이다. 

이 때, 명제1,2에 의해 $S \subseteq M$이고 $V = span(M)$인 선형 독립 집합 $M$이 존재한다.

따라서 $M$은 $V/F$의 기저가 된다. $\quad {_\blacksquare}$

#### 참고

1. 기저는 극대 선형 독립 집합이다.
2. 기저의 존재성은 초른의 보조정리에 의존한다.
3. 공리(초른의 보조정리)에 의해 기저의 존재성을 보장했을 뿐 기저가 무엇인지는 알 수 없다.
4. 기저의 유일성은 보장되지 않기 때문에 기저는 여러개일 수 있다.

### 명제4
벡터공간 $V/F$와 기저 $\beta_1,\beta_2$가 있을 때 $|\beta_1| = |\beta_2|$임을 증명하여라.

**proof**

$|\beta_1| \le |\beta_2|$라 하자.

그러면 함수 $f: \beta_1 \rightarrow \beta_2$는 단사함수이지만 전사함수는 아닌 함수가 존재한다.

이 경우 $f(\beta_1) \subset \beta_2$이다.

$\exist v_1 \in \beta_2 - f(\beta_1)$

Since $\beta_1, \beta_2$ are both maximal, it is contradiction.

`(미완성)`

### 명제5
$n$차원 vector space $V / \mathbb F$가 있다고 하자.

$S_1, S_2 \le V$이고 각각의 기저가 $\beta_1,\beta_2$일 때,  다음을 증명하여라.
$$ S_1 \cap S_2 = \{ 0_V \} \Rightarrow \beta_1 \cap \beta_2 = \empty$$

**Proof**

$\beta_1 \cap \beta_2 \neq \empty$라 가정하자.

$\beta \in \beta_1 \cap \beta_2$라 하면 다음이 성립한다.
$$ \begin{aligned} & \beta \in \text{span}(\beta_1) \land \beta \in \text{span}(\beta_2) \\ \Rightarrow \enspace & \beta \in S_1 \cap S_2 \\ \Rightarrow \enspace & \beta = 0_V \end{aligned}  $$

하지만, basis는 $0_V$가 될 수 없음으로 모순이 발생한다. 따라서, $\beta_1 \cap \beta_2 = \empty$이다. $\quad {_\blacksquare}$

### 명제6
$n$차원 vector space $V / \mathbb F$와 기저 $\beta$가 있다고 하자.

$U = \text{span}(\{\beta_1, \cdots, \beta_k \}), W = \text{span}(\{ \beta_{k+1}, \cdots \beta_n \})$라 할 때, 다음을 증명하여라.
$$V = U \oplus W$$

**Proof**

[$V \subseteq U \oplus W$]  
$$ \begin{aligned} & v \in V \\ \Rightarrow \enspace & v = a_1 \beta_1 + \cdots + a_k \beta_k + a_{k+1} \beta_{k+1} + \cdots + a_n \beta_n \\ \Rightarrow \enspace & v = u + w \\ \Rightarrow \enspace & v \in U \oplus W  \quad {_\blacksquare} \end{aligned}$$

[$U \oplus W \subseteq V$]  
$$ \begin{aligned} & x \in U \oplus W \\ \Rightarrow \enspace & x = a_1 \beta_1 + \cdots + a_k \beta_k + a_{k+1} \beta_{k+1} + \cdots + a_n \beta_n \\ \Rightarrow \enspace & x \in V  \quad {_\blacksquare} \end{aligned}$$


### 명제7
$n$차원 vector space $V / \mathbb F$가 있다고하자.

$W_1, \cdots, W_n \le V$이고 $V = W_1 \oplus \cdots \oplus W_n$일 때, $W_i$의 기저를 $\omega_i$라 하자.

이 때, 다음을 증명하여라.
$$ \bigcup_{i=1}^k \omega_i \text{ is a basis of } V$$

**Proof**

[linearly independent]  
다음과 같이 가정하자.
$$\{ \beta_1, \cdots, \beta_m \} = \bigcup_{i=1}^k \omega_i$$

명제5에 의해 $i \neq j$면, $\omega_i \cap \omega_j = \empty$임으로, 어떤 $w_i \in \text{span}(\omega_i)$에 대해  다음이 성립한다.
$$ \begin{aligned} & a^1\beta_1 + \cdots + a^m\beta_m = 0_V \\ \Rightarrow \enspace & w_1 + \cdots + w_k  = 0_V \end{aligned}  $$

이 떄, $w_1$과 $w_2+ \cdots + w_k$는 서로 다른 vector space에 있기 때문에 덧셈에 대한 역원이 될 수 없고 따라서 $w_1 = (w_2 + \cdots + w_k) = 0_V$다. 이를 반복하면 $w_i = 0$임을 알 수 있다.

즉, $a^1, \cdots, a^m = 0_{\mathbb F}$이다. $\quad {_\blacksquare}$

[$\text{span}(\bigcup_{i=1}^k \omega_i) = V$]  

명제5에 의해 $i \neq j$면, $\omega_i \cap \omega_j = \empty$임으로, 다음이 성립한다.
$$ \text{span}(\bigcup_{i=1}^k \omega_i) = \bigoplus_{i=1}^k \text{span}(\omega_i) = \bigoplus_{i=1}^k W_i = V \quad {_\blacksquare} $$
