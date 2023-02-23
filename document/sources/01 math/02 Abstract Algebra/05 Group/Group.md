# Group
## 정의
Monoid $G$가 있다고 하자.

$G$가 다음을 만족할 떄, $G$를 `군(group)`이라고 한다.

$$ \forall x \in G, \quad \exist x^{-1} \in G \quad s.t. \quad x * x^{-1} = x^{-1} * x = e $$ 

### 참고
이 때, $x^{-1}$를 $x$의 `역원(inverse element)`이라고 한다.

즉, group이란 각 원소의 inverse element를 갖는 monoid이다.

### 예시
$(\N,\times)$은 군이 아니다. $\left( \because x\in \N-\{1\}, \quad \frac{1}{x} \notin \N \right)$  

$(\Z,+),(\mathbb{Q},+),(\R,+)$은 군이다.

$(\mathbb{Q}-\{0\},\times),(\R-\{0\}, \times)$은 군이다.

$(\{A \in \R^{n \times n} | \det(A) \neq 0\}, \times)$은 군이다.

$(\{f:A \rightarrow A | f \text{ is bijective} \},\circ)$은 군이다.

### 명제1 
Group $G$가 있을 때, 다음을 증명하여라.

$$ \forall x \in G,\quad !x^{-1} $$

**Proof**  

$x\in G$가 있을 떄, $x$의 inverse element를 $y,z \in G$라 하자.  

Group의 성질에 의해 다음이 성립한다.

$$ \exist e \st y = y*e $$

이 때, inverse element의 정의에 의해 다음이 성립한다.

$$ y * x * y = y * x * z $$

$y$가 inverse element임으로 다음이 성립한다.

$$ \begin{aligned} y * x * y &= y * x * z \\ e*y &= e*z \\ y&=z \end{aligned} $$

임의의 $x \in G$에 두개의 inverse element가 있다면 반드시 같아야 함으로 다음이 성립한다.

$$ \forall x \in G,\quad !x^{-1} \qed $$

### 명제2(Cancellation Law)
Group $G$가 있을 때, 다음을 증명하여라.

$$ \forall x,y,z, \in G, \quad x*z = y*z \implies x=y $$

**Proof**  

$x\in G$가 있다고 하자.

Group의 성질에 의해 다음이 성립한다.

$$ \exist e \st x = x*e $$

이 때, inverse element의 정의에 의해 다음이 성립한다.

$$ x * e = x * z * z^{-1} $$

전제에 의해 다음이 성립한다.

$$ x * z * z^{-1} = y * z * z^{-1} = y $$

따라서, 위를 종합하면 다음이 성립한다.

$$ x = y \qed $$

### 명제3
집합 $S$가 있을 떄, 다음을 증명하여라.

$$ S \text{ is a group} \iff \begin{gathered} \exist * \st S \text{ is closed under }* \\ \forall x \in S, \quad \exist x^{-1} \in S \end{gathered}  $$

**Proof**

[$\implies$]  
$S$는 group이기 때문에, semi-group의 성질 또한 만족한다.

따라서 semi-group의 정의에 의해 다음이 성립한다.

$$ \exist * \st S \text{ is closed under }* $$

또한, group의 정의에 의해 inverse element가 존재해야 함으로 다음이 성립한다.

$$ \forall x \in S, \quad  x^{-1} \in S \qed $$

[$\impliedby$]  
첫번째 전제에 의해 $*$가 $S$위의 binary operation임으로 다음이 성립한다.

$$ S \text{ is a semi group} $$

두번째 전제에 의해 inverse element가 존재함으로, inverse element의 정의에 의해 다음이 성립한다.

$$ \exist e \in S \st e \text{ is an indentity element of } S $$ 

따라서 $H$는 monoid이고, 두번째 전제에 의해 모든 원소에 inverse element가 존재함으로 다음이 성립한다.

$$ S \text{ is a group} \qed $$


## 군 준동형 사상
군 $(G,*),(H,\cdot)$이 있을 때, `군 준동형 사상(group homomorphism)` $f:G \rightarrow H$은 다음을 만족하는 함수이다.

$$ g_1,g_2 \in G \Rightarrow f(g_1 * g_2)=f(g_1) \cdot f(g_2) $$

### 명제1
군 $(G,*),(H,\cdot)$과 준동형 사상 $f:G \rightarrow H$가 있을 때 $f(e_G)=e_H$를 증명하여라.

**proof**

$$ \begin{aligned} f(e_G) &= f(e_G*e_G) =f(e_G) \cdot f(e_G) \\ &= f(e_G) \cdot e_H \\ \therefore  f(e_G)  &= e_H \quad {_\blacksquare}  \end{aligned} $$

### 명제2
군 $(G,*),(H,\cdot)$과 준동형 사상 $f:G \rightarrow H$가 있을 때, $g \in G$에 대해 $f(g^{-1})=(f(g))^{-1}$를 증명하여라.

**proof**

$$ \begin{aligned} f(e_G) &= f(g*g^{-1}) = f(g) \cdot f(g^{-1}) \\ &= e_H \\ \therefore  f(g^{-1})  &= (f(g))^{-1} \quad {_\blacksquare}  \end{aligned} $$

### 명제3
군 $(G,*),(H,\cdot)$과 준동형 사상 $f:G \rightarrow H$가 있을 때 $f(G) \le H$를 증명하여라.

**proof**

$f(G)$는 상임으로 $f(G) \subseteq H$이다.

[연산에 닫혀있다]
$$ \begin{aligned} & h_1, h_2 \in f(G) \\ \Rightarrow \enspace & \exist g_1,g_2 \in G, \quad f(g_1)=h_1, f(g_2)=h_2 \\ \Rightarrow \enspace & h_1 \cdot h_2 = f(g_1) \cdot f(g_2) = f(g_1 * g_2) \in f(G) \quad (\because g_1 * g_2 \in G) \quad {_\blacksquare}  \end{aligned} $$

[역원이 존재한다]
$$ \begin{aligned} & h \in f(G) \\ \Rightarrow \enspace & \exist g \in G, \quad f(g)=h \\ \Rightarrow \enspace & h^{-1} = f(g^{-1}) \in f(G) \quad (\because 명제2) \quad {_\blacksquare}  \end{aligned} $$

### 예시
군 $(\R,+),(\R_{>0},\times)$과 함수 $\exp(x) : \R \rightarrow \R_{>0}, \quad x \mapsto e^x$.가 있을 때, 다음이 성립한다.

$$\exp(x+y)=\exp(x) \times \exp(y)$$

따라서, 명제 1,2,3에 의해 $\exp(x)$함수는 군 준동형 사상이며 이에 의해 **군 구조가 보존된다.** 

## 핵
군 $(G,*),(H,\cdot)$과 군 준동형 사상 $f:G \rightarrow H$가 있을 때, $f$의 `핵(kernel)` $\ker(f)$은 다음과 같이 정의된 집합이다.
$$\ker(f):=\{ g \in G | f(g) = e_H \}$$

### 명제
군 $(G,*),(H,\cdot)$과 군 준동형 사상 $f:G \rightarrow H$이 있을 때, $\ker(f) \le G$를 증명하여라.

**proof**

[연산에 닫혀있다]
$$ \begin{aligned} & g_1, g_2 \in \ker (f) \\ \Rightarrow \enspace & f(g_1 * g_2) = f(g_1) \cdot f(g_2) = e_H \\ \Rightarrow \enspace & g_1 * g_2 \in \ker(f) \quad {_\blacksquare}  \end{aligned} $$

[역원이 존재한다]
$$ \begin{aligned} & g \in \ker (f) \\ \Leftrightarrow \enspace & f(g) = e_H \\ \Leftrightarrow \enspace & (f(g))^{-1} = f(g^{-1}) =e_H \\ \Leftrightarrow \enspace & g^{-1} \in \ker(f) \quad {_\blacksquare}  \end{aligned} $$

### 참고
벡터 공간 $V,W/F$와 선형변환 $\Phi: V \rightarrow W$이 있을 때 다음이 성립한다.
$$\ker(\Phi)=\{v \in V | \Phi(v) = 0 \} \le V \\ \mathrm{img}(\Phi) \le W $$

이 때, 벡터 공간은 초른의 보조정리에의해 기저가 존재하고 차원을 정의할 수 있다. 따라서 $\dim(\ker(\Phi))$를 $\Phi$의 `퇴화차수(nullity)`라고 하고 $\dim(\mathrm{img}(\Phi))$를 $\Phi$의 `계수(rank)`라고 한다.

## 군 단사준동형 사상 
군 $(G,*),(H,\cdot)$이 있을때, `군 단사준동형 사상(group monomorphism)` $f: G \rightarrow H$은 군 준동형 사상이고 단사인 함수이다.

### 명제
군 $(G,*),(H,\cdot)$과 군 준동형 사상 $f:G \rightarrow H$이 있을 때, $\ker(f)=\{e_G\} \Leftrightarrow f \text{ is injective}$를 증명하여라.

[$\Rightarrow$]  
$g_1,g_2 \in G$에 대해,

$$ \begin{aligned} & f(g_1) = f(g_2) \\ \Rightarrow \enspace & f(g_1) \cdot f(g_1^{-1}) = f(g_2) \cdot f(g_1^{-1}) \\ \Rightarrow \enspace & f(e_G) = f(g_2 * g_1^{-1}) \\ \Rightarrow \enspace & e_G = g_2 *g_1^{-1} \quad (\because \ker(f) = \{ e_g \}) \\ \Rightarrow \enspace & g_1 = g_2 \quad {_\blacksquare} \end{aligned} $$

[$\Leftarrow$]  
$f(e_G) =e_H$이고, $f$가 단사함수임으로 $\ker(f)=\{e_G\}$이다. $\quad {_\blacksquare}$

## 군 전사준동형 사상 
군 $(G,*)$와 $(H,\cdot)$가 있을때, `군 전사준동형 사상(group epimorphism)` $f: G \rightarrow H$은 군 준동형 사상이고 전사인 함수이다.

## 군 동형 사상 
군 $(G,*)$와 $(H,\cdot)$가 있을때, `군 동형 사상(group isomorphism)` $f: G \rightarrow H$은 군 준동형 사상이고 전단사인 함수이다.

이떄 $G$를 $F$와 $f$에 의해 `군 동형(group isomorphic)`이라 하고 $G \overset{f\;}{\cong} H$로 표기한다. 다시 말해, $G$와 $F$는 같은 군 구조를 가지고 있다.

## 순환군

군 $(G,*)$와 $x \in G$이 있을 때, $x$에 의해 생성된 `순환군(cyclic group)`이란 $span(\{ x \}) = \lang x \rang = \{ x^n | n \in \Z \}$이다. 

이 때, $x^n = \begin{cases} \underbrace{x * \cdots * x}_{n} & 0 < n \\ 0_G & n= 0 \\ \underbrace{ x^{-1} * \cdots * x^{-1} } _ {|n|} & n < 0 \end{cases}$ 를 의미한다.

### 예시

$(\Z,+) = \lang 1 \rang = \lang -1 \rang$  
$(\Z / n\Z,+)$ 는 순환군이다. 왜냐하면 $\Z / n\Z= \{ [0], \cdots, [n-1] \}$이고 $[a]+[b] = [a+b])$임으로,
$(\Z / n\Z,+) = \lang [1] \rang$이다.

### 명제1

군 $(G,*)$과 $x \in G$가 있을 때, $\lang x \rang$은 $(\Z, +)$나 $n \in \N$에 대해 $(\Z / n\Z, +)$와 군 동형임을 증명하여라.

**proof**  
$\lang x \rang$은 $x^i, x^j \in \lang x \rang$에 대해 $x^i = x^j$을 만족하는 서로 다른 $i,j$가 존재하는 경우와 존재하지 않는 경우이다.

[존재하지 않는 경우]  
함수 $\Phi := \lang x \rang \rightarrow \Z, \quad x^n \mapsto n$는 $x^i = x^j$를 만족하는 경우가 없기 때문에 $x^n = x^m \Rightarrow n = m$이고 잘 정의된다(well defined).

-[$\Phi$ is group isomorphism]  
--[$\Phi$ is group homorphism]  
$x^n, x^m \in \lang x \rang$에 대해,

$$ \Phi(x^n * x^m) = \Phi(x^{n+m}) = n+m = \Phi(x^n) + \Phi(x^m) \quad {_\blacksquare} $$

--[$\Phi$ is injective]  
$x^n, x^m \in \lang x \rang$

$$ \begin{aligned} & \Phi(x^n) = \Phi(x^m) \\ \Rightarrow \enspace & n = m \\ \Rightarrow \enspace & x^n = x^m \quad {_\blacksquare}  \end{aligned}$$

--[$\Phi$ is surjective]  
$z \in \Z$에 대해, $x^z \in \lang x \rang$임으로, $\exist x^z \in \lang x \rang, \quad \Phi(x^z) = z$이다.
$\quad {_\blacksquare}$

[존재하는 경우]  
일반성을 잃지 않고 $j < i$라고 할 수 있다. 

$$ \begin{aligned} & x^i = x^j \\ \Leftrightarrow \enspace &  x^i * (x^j)^{-1} = e_G \\ \Leftrightarrow \enspace & x^{i-j} = e_G, \quad i-j \in \N \end{aligned} $$

따라서 $S = \{ n \in \N | x^n = e \}$는 공집합이 아니며, well-ordering principle에 의해 $\exist n_0 = \min S$이다.

이제 함수 $\Phi := \lang x \rang \rightarrow \Z / n_0\Z, \quad x^n \mapsto [n]$를 정의하자.

-[보조정리]  
$S = \{ kn_0 | k \in \Z \}$임을 증명하여라.

**proof**

$$ \begin{aligned} & \exist n_0 + l \in S, \quad l < n_0 \\ \Rightarrow \enspace & x^{n_0 + l} = e_G \\ \Rightarrow \enspace & x^l = e_G \quad \Rightarrow \!\! \Leftarrow (\text{minimality of } n_0)    \end{aligned} $$

-[$\Phi$ is well defined]  

$$ \begin{aligned} & x^n = x^m \\ \Leftrightarrow \enspace & n-m = n_0k \\ \Leftrightarrow \enspace & [n] = [m] \quad (\because \text{definition of } \Z / n_0\Z) \\ \Leftrightarrow \enspace & \Phi(x^n) = \Phi(x^m) \end{aligned} $$

-[$\Phi$ is group isomorphism]  
--[$\Phi$ is group homorphism]  

$$ \Phi(x^n * x^m) = \Phi(x^{n+m}) = [n + m] = [n] + [m] = \Phi(x^n) + \Phi(x^m) \quad {_\blacksquare} $$

--[$\Phi$ is injective]  
$x^n, x^m \in \lang x \rang$

$$ \begin{aligned} & \Phi(x^n) = \Phi(x^m) \\ \Rightarrow \enspace & [n] = [m] \\ \Leftrightarrow \enspace & n - m = n_0k \\ \Leftrightarrow \enspace & x^n = x^{m+n_0k} = x^m \quad {_\blacksquare}  \end{aligned}$$

--[$\Phi$ is surjective]  
$[z] \in \Z / n_0\Z$에 대해, $x^z \in \lang x \rang$임으로, $\exist x^z \in \lang x \rang, \quad \Phi(x^z) = [z]$이다.
$\quad {_\blacksquare}$

### 참고1

순환군은 무한집할일 경우 $\Z$와 군 동형이고 무한집합이 아닐 경우 적절한 $n_0$에 대해서 $\Z / n_0\Z$와 군 동형이어야 한다.

### 참고2

군 동형인 경우에는 같다고 분류할 경우, 정리1에 의해 모든 순환군이 $\Z, \Z/n\Z$로 분류된다.

### 명제2
군 $(G,*)$과 $x \in G$가 있을 때, $H \le \lang x \rang \Rightarrow H$ is cyclic group을 증명하여라.

**proof**

집합 $S = \{ n \in \N | x^n \in H \}$와 well-ordering principle에 의해 $\min S = n_0$가 있다.

이 때, $H = \lang x^{n_0} \rang$임을 보여 $H$가 순환군임을 증명하려고 한다.

[$H \subseteq \lang x^{n_0} \rang$]  
$x^n \in H$에 대해 division algorithm에 의해 $\exist q \in \Z, r \in \{ 0, \cdots, n_0 -1 \}, \quad n = n_0q +r$이다.

$$ x^r = x^{n-n_0q} = x^n * x^{-n_0q} \in H $$

이 때, $r$이 0이 아닌경우 $n_0$가 최소라는 가정에 문제가 발생함으로 $r=0$이다. 

$$ x^n = x^{n_0q} \in \lang x^{n_0} \rang \quad {_\blacksquare} $$

[$\lang x^{n_0} \rang \subseteq H$]  
$x^{n_0q} \in \lang x^{n_0} \rang$에 대해, $x^{n_0} \in H$이고 $H$는 군 구조를 가지고 있음으로 연산에 닫혀 있어야 함으로 $x^{n_0q} \in H$이다. $\quad {_\blacksquare}$

## 순환군의 차수

군 $(G,*)$와 $x \in G$이 있을 때, x의해 생성되는 순환군 $\lang x \rang$의 `차수(order)` $ord(x)$는 다음과 같이 정의된다.

$$ ord(x) = | \lang x \rang | =  \begin{cases} \min \{ n \in \N | x^n = e_G \} & \exist n \quad s.t. \quad x^n = e_G \\ \infty & \not\exist n \quad s.t. \quad x^n = e_G   \end{cases} $$


### 보조정리1

군 $(G,*)$와 $x \in G$에 대한 $|\lang x \rang| = n$인 $\lang x \rang$이 있을 때, $| \lang x^a \rang | = \frac{n}{\gcd (n,a)}$를 증명하여라.

**proof**

$x^a$를 $\frac{n}{\gcd (n,a)}$번 연산한것이 $e_G$가 되고 $\frac{n}{\gcd (n,a)}$이 가장 작은 자연수임을 보이려고한다.

[step1]  

$$(x^a)^{\frac{n}{\gcd (n,a)}} = (x^n)^{\frac{a}{\gcd (n,a)}} = e_G \quad {_\blacksquare}$$

[가장 작은 자연수]  
이를 보이려면 아래를 증명하면 된다.
$$(x^a)^m = e \Rightarrow  \frac{n}{\gcd (n,a)} \le m$$

division algorithm에 의해 $am = nq + r, \quad 0 \le r \le n-1$이 성립한다.

이 때, $r = am - nq$임으로 $x^r = e_G$인데 $n$이 가장 작은 자연수라는 가정에 모순이 발생한다.

즉, $r=0$이고 $am = nq$이다.

이를 통해 $n | am$이고 $n' = \frac{n}{\gcd(n,a)}$, $a' = \frac{a}{\gcd(n,a)}$라 할때 $n' | a'm$이다.

따라서 $n' | m$이고 $n' = \frac{n}{\gcd(n,a)} \le m$이다. $\quad {_\blacksquare}$


### 라그랑지 정리의 역

군 $(G,*)$와 $x \in G$에 대한 $|\lang x \rang| < \infty$인 $\lang x \rang$이 있을 때, 다음을 증명하여라.

$$ \forall d | n, \quad \exist! H \le \lang x \rang \quad s.t. \quad d = |H| $$

**proof**

[$\exist$]  
$$ \begin{aligned} & \frac{n}{d} \in \Z \\ \Rightarrow \enspace & x^\frac{n}{d} \in G \\ \Rightarrow \enspace &  \lang x^\frac{n}{d} \rang \le G \\ \Rightarrow \enspace & | \lang x^\frac{n}{d} \rang | = \frac{n}{\gcd (n,\frac{n}{d})} = \frac{n}{\frac{n}{d}} = d \quad {_\blacksquare} \end{aligned} $$

[!]  
$m \in \Z$에 대해 $|\lang x^m \rang|=d$인 $\lang x^m \rang \le \lang x \rang$가 있다고 하자.

보조정리에 의해 $d= \frac{n}{\gcd (n,m)} \Leftrightarrow \frac{n}{d} = \gcd (n,m)$이 성립한다.

[$\lang x ^{\frac{n}{d}} \rang \subseteq \lang x^m \rang$]  
$s,t \in \Z$에 대해 $\gcd (n,m) = ns + mt$ 임으로 $y \in \lang x ^{\frac{n}{d}} \rang = \lang x ^{ns+mt} \rang$에 대해

$$ y = x^{k(ns+mt)} = (x^n)^{ks} * (x^m)^{kt} = (x^m)^{kt} \in \lang x^m \rang \quad {_\blacksquare}$$

[$\lang x^m \rang \subseteq \lang x ^{\frac{n}{d}} \rang$]  
$m' \in \Z$에 대해 $m = \gcd(n,m) \times m' = \frac{n}{d} \times m'$임으로 $y \in \lang x^m \rang$에 대해

$$ y = x^{km}=  x^{k \frac{d}{n} m'} =  (x^{\frac{d}{n}})^{km'} \in \lang x ^{\frac{n}{d}} \rang  \quad {_\blacksquare}$$

#### 따름정리1

소수 $P$가 있을 때, $\Z / P\Z$는 $\{ e_G \}$를 제외한 `진부분군(proper subgroup)`을 갖지 않는다.

#### 따름정리2

$\Z / n\Z$의 `생성자(genrator)`의 수는 $\varphi(n)$과 같다.

이 때, $\varphi(n)$ `오일러 파이 함수(Euler's phi function)`는 다음과 같다.

$$ \varphi : \Z \rightarrow \Z , \quad n \mapsto \varphi(n) := \{ k \in \{ 0, \cdots, n \} | \gcd(n,k)=1 \} $$

**proof**

군 $(G,*)$와 $x \in G$가 있을 때, 보조정리에 의해서 $| \lang x^k \rang | = \frac{n}{\gcd(n,k)}$이다.

이 때, $x^k$가 생성자가 되기 위해서는 $| \lang x^k \rang | = n$이어야 하고 즉, $\gcd(n,k) = 1$이어야 한다. $\quad {_\blacksquare}$

### 명제1

소수 $P$가 있을 때, $k \in \N$에 대해 $\varphi(P^k) = P^k - P^{k-1}$임을 증명하여라.

### 명제2

$m,n \in \Z$가 있을 때, $\gcd(m,n) = 1 \Rightarrow \varphi(mn) = \varphi(m) \varphi(n)$를 증명하여라.

### 참고

$k \in \N$에 대해 소인수분해와 명제 2에의해 $\varphi(k) = \varphi(P_1^{m_1}) \cdots \varphi(P_r^{m_r})$가 되고 명제 1에 의해 $(P_1^{m_1} - P_1^{m_1 - 1}) \cdots (P_r^{m_1} - P_r^{m_1 - 1}) = P_1^{m_1} \cdots P_r^{m_r} \Pi _{i=1}^r (1 - \frac{1}{P_i}) = k \Pi _{i=1}^r (1 - \frac{1}{P_i})$이다.


## 왼쪽 잉여류

군 $(G,*)$이 있을 때, $H \le G$과 $g \in G$에 대해 관계 $L \subseteq G \times G$이 다음과 같이 주어졌다고 하자.

$$ (g,g') \in L \Leftrightarrow g^{-1}g' \in H $$

$L$에 의해 정의되는 $g$의 동치류 $[g]_L$의 정의를 보면 다음과 같다.
$$ \begin{aligned} [g]_L &= \{ g' \in G | g \sim_L g' \} \\ &= \{ g' \in G | g^{-1}g' = h \in H \} \\ &= \{ g' \in G | h \in H, \quad g' = gh \} \\ &= \{ gh | h \in H \} \end{aligned} $$

이 때, $g$의 `왼쪽 잉여류(left coset)` $gH$는 $L$에 의해 정의되는 동치류 $[g]_L$이다.

그리고 $G/H = \{ gH | g \in G \}$이다.

### 명제1
왼쪽 잉여류를 정의하는 관계 $L$이 동치 관계임을 증명하여라.

### 명제2
$f : G/\{e_G\} \rightarrow G$가 군 동형 사상임을 증명하여라.

#### 예시
$n\Z \le \Z$임으로 $\Z / n\Z$, 잉여류는 정수에서 봤던 성질의 일반화이다.

### 명제3
군 $(G,*)$이 있을 때, $H \le G$과 $g_1, g_2 \in G$에 대해 다음을 증명하여라.

$$ g_1H = g_2H \Leftrightarrow g_1^{-1}g_2 \in H \Leftrightarrow g_2^{-1}g_1 \in H $$

**proof**

[$\Rightarrow$]  
$e \in H$ 임으로, $g_1e \in g_2H \Rightarrow g_1 \in g_2H \Rightarrow \exist h \in H, \quad  g_1 = g_2h \Rightarrow g_2^{-1}g_1 = h \in H \Rightarrow g_1^{-1}g_2 = h^{-1} \in H$

[$\Leftarrow$]  
$g_1^{-1}g_2 \in H \Rightarrow \exist h \in H, \quad  g_1^{-1}g_2 = h \Rightarrow g_2 = g_1h \Rightarrow g_2H = \{ g_2h | h \in H \} = \{ g_1h | h \in H \} = g_1H$

### 명제4
군 $(G,*)$이 있을 때, $H \le G$과 $g \in G$에 대해 $|gH|=|H|$를 증명하여라.

**proof**

$f:gH \rightarrow H$가 전단사함수임을 보여 증명하려고 한다.

[injective]  
$f(gh_1)=f(gh_2) \Rightarrow h_1 = h2 \Rightarrow gh_1 =gh_2$

[surjective]  
$h \in H \Rightarrow f(gh) = h$

### 라그랑지 정리
군 $(G,*)$가 있을 때, $H \le G$에 대해 $|H| \enspace | \enspace |G|$임을 증명하여라.

**proof**

$G = \bigcup gH \rightarrow |G| = \sum_{k=1}^r |g_kH| = r|H|$

#### 따름정리
소수 $P$, $|G|=P$면 $G$는 순환군이다.

**proof**

$g \in G - \{e\} \rightarrow \lang g \rang \le G \Rightarrow | \lang g \rang | \enspace | \enspace |G| \Rightarrow | \lang g \rang | = |G| \Rightarrow \lang g \rang = G$


## 오른쪽 잉여류

군 $(G,*)$이 있을 때, $H \le G$과 $g \in G$에 대해 관계 $R \subseteq G \times G$이 다음과 같이 주어졌다고 하자.

$$ (g,g') \in R \Leftrightarrow g'g^{-1} \in H $$

$R$에 의해 정의되는 $g$의 동치류 $[g]_R$의 정의를 보면 다음과 같다.
$$ \begin{aligned} [g]_R &= \{ g' \in G | g \sim_L g' \} \\ &= \{ g' \in G | g'g^{-1} = h \in H \} \\ &= \{ g' \in G | h \in H, \quad g' = hg \} \\ &= \{ hg | h \in H \} \end{aligned} $$

이 때, $g$의 `오른쪽 잉여류(right coset)` $Hg$는 $R$에 의해 정의되는 동치류 $[g]_R$이다.
