# Span
## 정의
Vector space $V/F$와 $V$의 finite subset $S$가 있을 때, $S$의 `생성(span)`이란 다음과 같이 정의된 집합이다.
$$ \span(S) = \lang S \rang  := \left \{ \sum_{k=1}^{n}a_kv_k \; \Big\vert \; a_i \in F, v_i \in S \right \} $$

### 참고1
$\span(S)$란 $S$의 원소들의 선형결합으로 표현되는 집합이다. 

### 참고2
$\span(\empty) = \{ 0_V \}$로 정의한다.

### 명제1
Vector space $V/F$가 있을 때 다음을 증명하여라.

$$S \subseteq V \Rightarrow \span(S) \subseteq V $$

**proof**

벡터공간은 $+, \cdot$ 연산에 닫혀있기 때문에 $V$안의 원소들간의 $+, \cdot$연산으로 이루어진 생성의 결과는 $V$의 원소가 된다. $\qed$

### 명제2
벡터공간 $V/F$와 $S \subseteq V$가 있을 때, 다음을 증명하여라.

$$ \span(V) = V $$

**proof**

[$\span(V) \subseteq V$]  
$V$는 $V$의 부분집합이기 때문에 명제1에 의해 증명된다. $\qed$

[$V \subseteq \span(V)$]  
$$ \begin{aligned} & v_j \in V \\ \Rightarrow \enspace & v_j = \sum_{k=1}^{n} a_kv_k, \quad \left( a_k = \begin{cases} 1 &  k=j \\ 0 & k \neq j \end{cases} \right) \\ \Rightarrow \enspace & v_j \in span(V) \qed \end{aligned}   $$

#### 참고
$V$의 부분집합으로 $S=V$를 잡게 되면 $\span(S) = \span(V) = V$가 된다. 

즉, $V$의 부분집합중 생성을 통해 $V$를 만들어내는 부분집합이 반드시 존재한다.

### 명제3
벡터공간 $V/F$와 $S \subseteq V$가 있을 때, 다음을 증명하여라.

$$ \span(S) \text{ is a vector space } $$

**proof**  

[기본 연산 법칙]  
벡터 공간의 부분집합과 연산을 그대로 사용하기 때문에 교환법칙 분배법칙등 $F-$가군의 성질들이 전부 성립한다. $\qed$

[연산에 닫힘]  
$s_1, s_2 \in span(S), \enspace a \in F$가 있을 때 $as_1 + s_2 \in \span(S)$이 성립한다. $\qed$

[$+$연산 항등원의 존재성]  
모든 계수를 $0_F$로 두면, $0_V$가 된다. $\qed$

[$+$연산 역원의 존재성]  
scalar multiplication이 정의되어 있음으로 ring의 성질에 의해 역원이 항상 존재한다. $\qed$

#### 참고
$\span(S)$는 $V$의 subset이면서 vector space임으로 $V$의 subspace라고 한다.

간단하게 $\span(S) \le V$로 나타내기도 한다.

### 명제4
벡터공간 $V/F$와 $S \subseteq V$과 $H := \{ W \enspace | \enspace S \subseteq W \land W \le V \}$가 있을 때, 다음을 증명하여라.
$$ \span(S)=\bigcap H $$

**proof**

$S =\{ v_1, \cdots, v_n \}$이라 하자.

[$\span(S) \subseteq \bigcap H$]  
$v \in \span(S)$과 $H_i \in H$에 대해,

$$ \begin{aligned} & v = a_1v_1+ \cdots + a_nv_n \\\implies& v \in H_i \quad (\because S \subseteq H_i \land H_i \text { is closed under +,} \cdot)  \\\implies& v \in \bigcap H_i \end{aligned}  $$

[$\bigcap H \subseteq \span(S)$]  
$$ \begin{aligned} & S \subseteq \span(S) \land \span(S) \le V \\\implies& \span(S) \in H \qed \end{aligned} $$

#### 참고
$\span(S)$는 $S$를 포함하고 있는 $V$의 subspace중에 가장 작은 subspace이다.