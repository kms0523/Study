# Cyclic Group
## Definition
Group $G$와 $G$의 임의의 singletone set $\Set{x}$가 있다고 하자.

이 때, singletone set $\Set{x}$에 의해 생성되는 $\span(\Set{x})$를 `cyclic group`이라고 한다.

### Example
* $(\Z,+) = \braket{1} = \braket{-1}$
* $(\Z/n\Z,+) = \braket{[1]_n}$

### 명제1(Classification)
Group $G$와 $G$의 cyclic group $\braket{x}$가 있다고 하자.

이 때, 어떤 $n \in \N$에 대해서 다음을 증명하여라.

$$ \braket{x} \cong (\Z,+) \lor \braket{x} \cong (\Z/n\Z, +) $$

**Proof**

$\braket{x}$는 다음 두가지 경우로 나눌 수 있다.

1. $\forall i,j \in \Z, \enspace x^i = x^j \implies i = j$
2. $\exist i,j \in \Z \st x^i = x^j \land i \neq j$

[case1]  
함수 $f$를 다음과 같이 정의하자.

$$f : \braket{x} \rightarrow \Z \st x^i \mapsto i $$

전제에 의해 $f$는 well-defined이다.

[$f$ is group isomorphism]  
-[$f$ is a group homorphism]  
$\braket{x}$의 임의의 elements를 $x^i,x^j$라고 하면 다음이 성립한다.

$$ f(x^i*x^j) = f(x^{i+j}) = i+j = f(x^i) + f(x^j) \qed $$

-[$f$ is an injective]  
$\braket{x}$의 임의의 elements를 $x^i,x^j$라고 하면 다음이 성립한다.

$$ f(x^i) = f(x^j) \implies i=j \implies x^i = x^j \qed $$

-[$f$ is a surjective]  
$\Z$의 임의의 element를 $i$라고 하면 다음이 성립한다.

$$ \exist x^i \in \braket{x} \st f(x^i) = i \qed $$

[case2]  
일반성을 잃지 않고 $j < i$라고 하자.

그러면 $i-j \in \N$이고 $x^{i-j} = e_G$이다.

이 때, set $S$를 다음과 같이 정의하자.

$$ S := \Set{n \in \N | x^n = e_G} $$

그러면, $S$는 $\N$의 non empty subset이다.

따라서, well ordering principle에 의해서 다음이 성립한다.

$$ \exist n_0 = \min(S) $$

함수 $f$를 다음과 같이 정의하자.

$$ f : \braket{x} \rightarrow \Z/n_0 \Z \st x^i \mapsto [i]_{n_0} $$

[$f$ is well defined]  
$\braket{x}$의 임의의 elements를 $x^i,x^j$라고 하면 다음이 성립한다.

$$ x^i = x^j \implies i = kn_0 + j \implies [i]_{n_0} = [kn_0 + j]_{n_0} = [j]_{n_0} \implies f(x^i) = f(x^j) \qed $$

[$f$ is a group isomorphism]  
-[$f$ is a group homorphism]  
$\braket{x}$의 임의의 elements를 $x^i,x^j$라고 하면 다음이 성립한다.

$$ f(x^i*x^j) = f(x^{i+j}) = [i+j]_{n_0} = [i]_{n_0} + [j]_{n_0} = f(x^i) + f(x^j) \qed $$

-[$f$ is an injective]  
$\braket{x}$의 임의의 elements를 $x^i,x^j$라고 하면 다음이 성립한다.

$$ f(x^i)=f(x^j) \implies [i]_{n_0} = [j]_{n_0} \implies i = kn_0 + j \implies x^i = x^{kn_0 +j} = x^j \qed $$

-[$f$ is surjective]  
$\Z/n_0\Z$의 임의의 element를 $[i]_{n_0}$라고 하면 다음이 성립한다.

$$ \exist x^i \in \braket{x} \st f(x^i) = [i]_{n_0} \qed $$

### 명제2
Group $G$와 $G$의 임의의 cyclic group $\braket{x}$가 있다고 하자.

$\braket{x}$의 subgroup $H$가 있을 때, 다음을 증명하여라.

$$ H \text{ is a cyclic group} $$

**Proof**

Set $S$를 다음과 같이 정의하자.

$$ S := \Set{n \in \N | x^n \in H} $$

그러면 $S$는 $\N$의 non empty subset임으로 well ordering principle에 의해 다음이 성립한다.

$$ \exist n_0 = \min(S) $$

이 때, $H = \braket{n_0}$임을 보이자.

[$H \subseteq \braket{n_0}$]  
$H$의 임의의 element를 $x^m$이라고 하자.

division algorihtm에 의해 다음이 성립한다.

$$ m = pn_0 + q $$

$q = m - pn_0$임으로 다음이 성립한다.

$$ x^q = x^{m-pn_0} = x^m \in H $$

이 떄, 다음을 가정하자.

$$ q \neq 0 $$ 

그러면, $q \in S$이고 $1\le q \le n_0-1$이다.

하지만 이는 $n_0 = \min(S)$라는 사실에 모순임으로 proof by contradiction에 의해 다음이 성립한다.

$$ q= 0 $$

그러면 다음이 성립한다.

$$ x^m = x^{n_0p} \in \braket{n_0} \qed $$





