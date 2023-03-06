# Span
## 정의
Vector space $V/\F$와 $V$의 subset $S$가 있다고 하자.

 $S$의 `생성(span)`이란 다음과 같이 정의된 집합이다.

$$ \span(S) = \lang S \rang  := \left \{ \sum_{k=1}^{n}a_kv_k \; \Big\vert \; n \in \N, a_i \in F, v_i \in S \right \} $$

### 참고1
$\span(S)$란 $S$에서 임의의 $n$개의 vector의 `선형결합(linear combination)`들의 집합이다.

즉, $S$의 가능한 모든 선형결합들의 집합이다.

### 참고2
$\span(\empty) = \{ 0_V \}$로 정의한다.

### 참고3
선형결합에서 $a_1,\cdots,a_n$을 `계수(coefficients)`라고 부른다.

### 명제1
벡터공간 $V/\F$와 $S \subseteq V$가 있을 때, 다음을 증명하여라.

$$ \span(S) \text{ is a vector space } $$

**proof**  

[$\span(S)$ is an abelian group]  
-[closed]  
$s_1, s_2 \in \span(S)$가 있을 때, $V$의 elements들의 linear combination의 합은 $V$의 element들의 linear combination의 합임으로 $s_1 + s_2 \in S$가 성립한다. $\qed$

-[identity]  
$\span(S)$의 모든 element는 $V$의 element임으로 다음이 성립한다.

$$ \forall s \in \span(S), \enspace s + 0_V = 0_V + s = s $$

이 떄, $S=\empty$면 $0_V \in \span(S)$이고, $S \neq \empty$일 때도, $s \in S$에 대해서 $0_\F s = 0_V \in \span(S)$이다. $\qed$

-[inverse]  
$\span(S)$의 임의의 element를 $x$라 하면 다음이 성립한다.

$$ x = \sum_{i=1}^n a_iv_i, \enspace a_i\in\F,v_i \in V $$

이 때, $V$는 $\F-$module 임으로 module의 성질에 의해 다음이 성립한다.

$$ -x = \sum_{i=1}^n -a_iv_i $$

따라서 $x^{-1}$ 또한 $V$의 elements의 linear combination임으로 다음이 성립한다.

$$ x^{-1} \in \span(S) \qed $$

-[commutative]  
$\span(S)$의 모든 element는 $V$의 element임으로 다음이 성립한다.

$$ \forall s_1,s_2 \in \span(S), \enspace s_1+s_2 = s_2+s_1 \qed $$

[module]    
$\span(S)$의 임의의 element를 $s$라 하자. 

그러면 $s\in V$임으로 $V$의 scalar multiplication을 그대로 사용할 수 있다.

또한, $\F$의 임의의 element를 $c$라고 할 때, $cs \in \span(S)$임으로 다음이 성립한다. 

$$ \span(S) = \F-\text{module} $$

따라서, 다음이 성립한다.

$$ \span(S) \text{ is a vector space } \qed $$

### 명제2
벡터공간 $V/\F$와 $V$의 subset $S$가 있다고 하자.

$V$의 subspace의 collection $H$를 다음과 같이 정의하자.

$$H := \{ W \enspace | \enspace S \subseteq W \land W \le V \}$$

이 떄, 다음을 증명하여라.
$$ \span(S)=\bigcap H $$

**proof**

[$\span(S) \subseteq \bigcap H$]  
$\span(S)$의 임의의 element를 $v$라 하면 다음이 성립한다.

$$ v = a_1v_1+ \cdots + a_nv_n, \enspace a_i \in \F, v_i \in S $$

$H$의 임의의 element를 $H_i \in H$라 하자.

$H$의 정의에 의해 $S \subseteq H_i$이고 $H_i$는 $+,\cdot$에 닫혀 있음으로 다음이 성립한다.

$$ v \in H_i $$

임의의 $H_i$에 대해 위에가 성립함으로 다음이 성립한다.

$$ v \in \bigcap H_i $$

임의의 element에 대해 위에가 성립함으로, 다음이 성립한다.

$$ \span(S) \subseteq \bigcap H \qed $$

[$\bigcap H \subseteq \span(S)$]  
$\span(S)$는 $S$를 포함하며 명제1에 의해 $V$의 subspace임으로 다음이 성립한다.

$$ \span(S) \in H \implies \bigcap H \subseteq \span(S) \qed $$

#### 참고
$\span(S)$는 $H$의 element이면서 동시에 $\span(S) = \bigcap H$를 만족한다.

따라서, $S$를 포함하는 모든 subspace는 $\span(S)$를 포함하며, $\span(S)$는 $S$를 포함하는 $V$의 subspace중에 가장 작은 subspace이다.

### 명제3
벡터공간 $V/\F$가 있을 때, 다음을 증명하여라.

$$ \span(V) = V $$

**proof**

[$\span(V) \subseteq V$]  
$x \in \span(V)$라고 하자.

$V$는 $+, \cdot$ 연산에 닫혀있기 때문에 다음이 성립한다.

$$ x \in V \qed $$

[$V \subseteq \span(V)$]  
$V$의 임의의 원소는 그 원소 한개를 뽑아서 선형결합한 것으로 볼 수 있기 때문에 자명하게 $\span(V)$에 들어간다. $\qed$

#### 참고
$V$의 부분집합으로 $S=V$를 잡게 되면 $\span(S) = \span(V) = V$가 된다. 

즉, $V$의 부분집합중 span을 통해 $V$를 만들어내는 부분집합이 반드시 존재한다.