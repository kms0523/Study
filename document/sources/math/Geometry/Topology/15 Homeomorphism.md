# Homeomorphism

## 정의
Topological space $X,Y$가 있다고 하자.

함수 $f: X \rightarrow Y$가 다음 성질을 만족할 떄, $f$를 $X$에서 $Y$로의 `위상동형사상(homeomorphism)`이라 한다.

$$ f \text{ is bijective} \enspace \land \enspace f, f^{-1} \text{ are continous. } $$

만약 homeomorphism $\phi$가 존재한다면, $X$와 $Y$를 `위상동형(homeomorphic, topologically equivalent)`이라고 한다.

> Referece  
> {cite}`LeeTM` p.28

### 명제1
Topological space $(X_1,\mathcal T_1),(X_2,\mathcal T_2)$가 있다고 하자.

함수 $f : X_1 \rightarrow X_2$가 bijective일 때, 다음을 증명하여라.

$$ f \text{ is a homeomorphism} \iff f(\mathcal T_1) = \mathcal T_2 $$

**Proof**

[$\implies$]  
-[$f(\mathcal T_1) \subseteq \mathcal T_2$]  
$U \in \mathcal{T_1}, \enspace f(U) \in f(\mathcal T_1)$이라 하자.

$f$가 bijective function 임으로 다음이 성립한다.

$$ f^{-1}(f(U)) \text{ is an open set on } X_1 $$

$f^{-1}$이 continous함으로  다음이 성립한다.

$$ \begin{aligned} & f^{-1}(f(U)) \text{ is a open set on } X_1 \\ \implies\enspace& \text{preimg}(f^{-1}(f(U))) \text{ is a open set on } X_2 \\ \implies\enspace& f(U) \text{ is a open set on } X_2 \\ \implies\enspace& f(U) \in \mathcal T_2 \end{aligned}  $$

-[$\mathcal T_2 \subseteq f(\mathcal T_1)$]  
$V \in \mathcal{T_2}$이라 하자.

$f$가 bijective function 임으로 다음이 성립한다.

$$ f(f^{-1}(V)) \text{ is an open set on } X_2 $$

$f$가 continous함으로  다음이 성립한다.

$$ \begin{aligned} & f(f^{-1}(V)) \text{ is a open set on } X_2 \\ \implies\enspace& \text{preimg}(f(f^{-1}(V))) \text{ is a open set on } X_1 \\ \implies\enspace& f^{-1}(V) \text{ is a open set on } X_1 \\ \implies\enspace& f^{-1}(V) \in \mathcal T_1 \\ \implies\enspace& V \in f(\mathcal T_1) \quad\tiny\blacksquare \end{aligned}  $$

[$\impliedby$]  
-[$f$ is continous]  
$V \in \mathcal T_2$라 하자.

$f$가 bijective임으로 다음이 성립한다.

$$ \text{preimg}(f(f^{-1}(V))) = f^{-1}(V) $$

이 때, $f(\mathcal T_1) = \mathcal T_2$임으로 다음이 성립한다.

$$ \begin{aligned} & \mathcal{T}_1 = f^{-1}(\mathcal{T}_2) \\ \implies\enspace& f^{-1}(V) \in \mathcal T_1 \end{aligned}  $$

즉, $X_2$ 위의 임의의 open set에 대한 $f$의 preimage가 $X_1$위의 open set임으로 $f$는 continous이다.

-[$f^{-1}$ is continous]  
$U \in \mathcal T_1$라 하자.

$f$가 bijective임으로 다음이 성립한다.

$$ \text{preimg}(f^{-1}(f(U))) = f(U) $$

$f(\mathcal T_1) = \mathcal T_2$임으로 다음이 성립한다.

$$ f(U) \in \mathcal T_2 $$

즉, $X_1$ 위의 임의의 open set에 대한 $f^{-1}$의 preimage가 $X_2$위의 open set임으로 $f^{-1}$는 continous이다. $\quad\tiny\blacksquare$

### 명제2
Topological space $X,Y$와 homeomorphism $f: X \rightarrow Y$가 있다고 하자.

open set $U \subseteq X$가 있을 때, 다음을 증명하여라.

$$ f|_{U \times f(U)} \text{ is a homeomorphism}$$

**Proof**

[$f|_{U \times f(U)}$ is bijective]  
bijective function의 domain & codomain restriction은 bijective function이다.

[$f|_{U \times f(U)}$ is continuous]  
continuous function의 domain restriction과 관련된 성질에 의해 다음이 성립한다.

$$ f|_{U \times f(U)} \text{ is a continuous} $$

[$(f|_{U \times f(U)})^{-1}$ is continuous]  
inverse function의 domain & codomian restriction과 관련된 성질에 의해 다음이 성립한다.

$$ (f|_{U \times f(U)})^{-1} = f^{-1}|_{f(U) \times U} $$

$f$가 homeomorphism임으로 $f^{-1}$은 continuous function이다. 따라서, continuous function의 domain restriction과 관련된 성질에 의해 다음이 성립한다.

$$ \begin{aligned} & f^{-1}|_{f(U) \times U} \text{ is a continuous} \\ \iff\enspace& (f|_{U \times f(U)})^{-1} \text{ is a continuous} \end{aligned} $$

[결론]  
$f|_{U \times f(U)}$는 bijective이고 $f|_{U \times f(U)}$와 그 역함수가 모두 continuous함으로 homeomorphism이다. $\quad\tiny\blacksquare$

> Reference  
> [Proof Wiki](https://proofwiki.org/wiki/Restriction_of_Homeomorphism_is_Homeomorphism)

