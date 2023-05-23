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

$$ \exist a \in \Z \st  H = \braket{x^a} $$

**Proof**

Set $S$를 다음과 같이 정의하자.

$$ S := \Set{n \in \N | x^n \in H} $$

그러면 $S$는 $\N$의 non empty subset임으로 well ordering principle에 의해 다음이 성립한다.

$$ \exist n_0 = \min(S) $$

이 때, $H = \braket{x^{n_0}}$임을 보이자.

[$H \subseteq \braket{x^{n_0}}$]  
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

$$ x^m = x^{n_0p} \in \braket{x^{n_0}} \qed $$

[$\braket{x^{n_0}} \subseteq H$]  
$n_0 \in S$이고 $H$가 group 임으로 다음이 성립한다.

$$ x^{n_0} \in H \implies \braket{x^{n_0}} \subseteq H \qed $$

## Order
Group $G$와 $G$의 cyclic group $\braket{x}$가 있다고 하자.

이 때, set $S$를 다음과 같이 정의하자.

$$ S := \Set{n \in \N | x^n = e_G} $$

이 때, $x$의 order $o(x)$는  다음과 같이 정의된 자연수이다.

$$ o(x) = \min(S) $$

### 참고
1. $x^n = e$를 만족하는 $n$이 없는 경우 $o(x) = \infty$이다.
2. $o(x)=n < \infty$인 경우 $\braket{x} \cong \Z/n\Z$이다.
3. $o(x)= \infty$인 경우 $\braket{x} \cong \Z$이다.

### 명제1
Group $G$와 $G$의 cyclic group $\braket{x}$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ o(x) = n \implies |\braket{x}| = n  $$

**Proof**

$$ x^n = e_G \implies \braket{x} = \Set{e,x,x^2,\cdots,x^{n-1}} \implies |\braket{x}| = n \qed $$ 


### 명제2
Group $G$와 $G$의 cyclic group $\braket{x}$가 있다고 하자.

$o(x) = n < \infty$이고 $\Z$의 임의의 element를 $a$라고 할 때, 다음을 증명하여라.

$$ o(x^a) = \frac{n}{\gcd(n,a)} $$

**Proof**

집합 $S$를 다음과 같이 정의하자.

$$ S := \Set{m \in \N | (x^a)^m = e_G} $$

$S$의 임의의 element $m$에 대해서 $o(x) = n$이기 때문에 division algorithm에 의해 어떤 $q \in \Z$에 대해서,  $am = qn$이다.

이 때, $a' = a / \gcd(n,a), n' = n / \gcd(n,a)$이라고 하면 $a'$과 $n'$은 relative prime임으로 다음이 성립한다.

$$ am = qn \implies a'm = qn' \implies m = q'n' $$

이 때, $m,n \in \N$임으로 $q' \in \N$이고 따라서 다음이 성립한다.

$$ n' \le m \iff \frac{n}{\gcd(n,a)} \le m $$

그리고 $a' \in \Z$임으로 다음이 성립한다.

$$  x^{a \frac{n}{\gcd(n,a)}} = x^{n \frac{a}{\gcd(n,a)}} = e^{a'} = e \implies \frac{n}{\gcd(n,a)} \in S  $$

따라서, 다음이 성립한다.

$$ o(x^a) = \frac{n}{\gcd(n,a)} \qed $$

#### 따름명제1
Group $G$와 $G$의 cyclic group $\braket{x}$가 있다고 하자.

이 때, 다음을 증명하여라.

$$ o(x) = n \text{ is a prime number} \implies \braket{x} \text{ has no proper subgroup except } \Set{e_G} $$

**Proof**

$\braket{x}$의 subgroup을 $H$라고 하면, 다음이 성립한다.

$$ \exist a \in \Z \st H = \braket{x^a} $$

이 때, 명제2에 의해 다음이 성립한다.

$$ |H| = o(x^a) = \frac{n}{\gcd(n,a)} = 1 \lor n $$

$|H| = n$인 경우 $\braket{x^a}$는 proper subgroup이 아니며 $|H| = 1$인 경우 $H = \Set{e_G}$이다. $\qed$

#### 따름명제2
Group $G$와 $G$의 cyclic group $\braket{x}$가 있다고 하자.

$o(x) = n < \infty$이고 $\Z$의 임의의 element를 $a$라고 할 때, 다음을 증명하여라.

$$ n,a \text{ are relative prime} \implies \braket{x} = \braket{x^a} $$

**Proof**

전제에 의해 다음이 성립한다.

$$ o(x^a) = |\braket{x^a}| = n $$

이 떄, $\braket{x^a}$는 $\braket{x}$의 subgroup이고 $|\braket{x^a}| = |\braket{x}|$임으로 다음이 성립한다.

$$ \braket{x} = \braket{x^a} \qed $$

##### 참고1
$\braket{x} = \braket{x^a}$라는 말은 $x^a$ 또한 $\braket{x}$의 generator라는 말이다.

따라서, $[0,n)$ 구간에서 relative prime의 수가 $\braket{x}$의 generator의 수가 된다.

그리고 Euler's phi 함수 $\varphi$가 다음과 같이 정의된다.

$$ \varphi : \Z \rightarrow \Z \st n \mapsto |\Set{k \in [0,n) | \gcd(n,k) = 1}| $$

즉, Euler's phi의 값이 $\braket{x}$의 generator 수이다.

##### 참고2
Euler's phi function $\varphi$와 prime number $p$가 있다고 하자.

그러면 $1$보다 큰 자연수 $i$에 대해서 다음이 성립한다.

$$ \varphi(p^i) = p^i - p^{i-1} $$

**Proof**

$\varphi$의 정의에 의해 다음이 성립한다.

$$ \varphi(p^i) = |\Set{k \in [0,p^i) | \gcd(p^i,k) = 1}| $$

즉 $p^i$개의 선택지 중에서 relative prime이 아닌 수를 빼야 한다.

이 때, $p^i$와 relative prime이 아닌 수들의 집합을 생각하면 $p$의 배수 형태여야 함으로 다음이 성립한다.

$$ \Set{mp | m \in [0, p^{i-1})} $$

즉, relative prime이 아닌 수들은 총 $p^{i-1}$개가 된다.

따라서 다음이 성립한다.

$$ \varphi(p^i) = p^i - p^{i-1} \qed $$

> Reference  
> [wiki](https://en.wikipedia.org/wiki/Euler%27s_totient_function#Computing_Euler's_totient_function)

##### 참고3
Euler's phi function $\varphi$와 relative prime number $n,m$이 있다고 하자.

그러면 다음이 성립한다.

$$ \varphi(nm) = \varphi(n)\varphi(m) $$

**Proof**

..?

##### 참고4
Euler's phi function $\varphi$와 임의의 자연수 $n$이 있다고 하자.

prime decomposition에 의해 $n=\prod_{i=1}^mp_i^{k_i}$라고 하면 다음이 성립한다.

$$ \varphi(n) = n \prod_{i=1}^m\left(1 - \frac{1}{p_i}\right)  $$

**Proof**

$$ \begin{aligned} \varphi(n) &= \varphi(\prod_{i=1}^mp_i^{k_i}) \\&= \prod_{i=1}^m (p_i^{k_i} - p_i^{k_i-1}) \\&= \prod_{i=1}^m p_i^{k_i} \prod_{i=1}^m \left(1 - \frac{1}{p_i}\right) \\&= n \prod_{i=1}^m\left(1 - \frac{1}{p_i}\right) \qed \end{aligned} $$

##### 예제1
$G = \Z / 6\Z$로 두고 $\braket{\bar{2}}$를 생각해보자.

$\braket{2\bar{2}} = \braket{\bar{4}}$이고 $o(\bar{2}) = 3$임으로 $n=3$ $a=2$인 경우이다.

이 때, $\braket{\bar{2}} = \braket{\bar{4}}$이다.

##### 예제2
$G = \Z / 5\Z$로 두고 $\braket{\bar{1}}$를 생각해보자.

$\braket{3\bar{1}} = \braket{\bar{3}}$이고 $o(\bar{1}) = 5$임으로 $n=5$ $a=3$인 경우이다.

이 때, $\braket{\bar{1}} = \braket{\bar{3}}$이다.

### 명제3
Group $G$와 $G$의 cyclic group $\braket{x}$가 있다고 하자.

$o(x) = n < \infty$ 일 때, 다음을 증명하여라.

$$ \forall d |n, \enspace \exist! H \le \braket{x} \st |H| = d $$ 

**Proof**

[existence]  
$d|n$임으로 $n/d \in \Z$이다.

$H = \braket{x^{n/d}}$라고 두면 다음이 성립한다.

$$ \begin{gathered} H \le \braket{x} \\ |H| = |x^{n/d}| = o(x^{n/d}) = \frac{n}{\gcd(n,n/d)} = d \end{gathered} \qed  $$

[uniquness]  
$H'$가 $H' \le \braket{x}$이고 $|H'| = d$라고 하자.

$H' \le \braket{x}$임으로 다음이 성립한다.

$$ \exist m \in \Z \st H' = \braket{x^m} $$

그리고 $|H'| = d$임으로 다음이 성립한다.

$$ |H'| = o(x^m) = \frac{n}{\gcd(n,m)} = d \implies \frac{n}{d} = \gcd(n,m) $$

-[$\braket{x^m} \subseteq \braket{x^{n/d}}$]  
$\gcd(n,m) = n/d$임으로 다음이 성립한다.

$$ \exist m' \in \Z \st m = m'\gcd(n,m) = m'\frac{n}{d} $$

따라서, 다음이 성립한다.

$$ x^m = x^{m' \frac{n}{d}} \in \braket{x^{n/d}} \qed $$

-[$\braket{x^{n/d}} \subseteq \braket{x^n}$]  
$\gcd(n,m) = n/d$임으로 베주의 항등식에 의해 다음이 성립한다.

$$ \exist s,t \in \Z \st \frac{n}{d} = ns + mt $$

따라서, 다음이 성립한다.

$$ x^{d/n} = x^{ns + mt} = x^{mt} \in \braket{x^m} \qed $$

-[결론]  
따라서, $\braket{x^m} = \braket{x^{n/d}}$임으로 다음이 성립한다.

$$ H' = \braket{x^m} = \braket{x^{n/d}} = H \qed $$




