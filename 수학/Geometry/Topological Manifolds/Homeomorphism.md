# Homeomorphism
Topological space $X,Y$가 있다고 하자.

함수 $f: X \rightarrow Y$가 다음 성질을 만족할 떄, $f$를 $X$에서 $Y$로의 `위상동형사상(homeomorphism)`이라 한다.
$$ f \text{ is bijective} \enspace \land \enspace f, f^{-1} \text{ are continous. } $$

만약 homeomorphism $\phi$가 존재한다면, $X$와 $Y$를 `위상동형(homeomorphic, topologically equivalent)`이라고 한다.

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds p.28

### 명제1
Topological space $(X_1,\mathcal T_1),(X_2,\mathcal T_2)$가 있다고 하자.

함수 $f : X_1 \rightarrow X_2$가 bijective일 때, 다음을 증명하여라.
$$ f \text{ is a homeomorphism} \Leftrightarrow f(\mathcal T_1) = \mathcal T_2 $$

**Proof**

[$\Rightarrow$]  
-[$f(\mathcal T_1) \subseteq \mathcal T_2$]  
$s \in \mathcal{T_1}$이라 하자.

$f$가 homeomorphism임으로 다음이 성립한다.
$$ \begin{aligned} & \text{img(s)} \in \mathcal T_2 \\ \Leftrightarrow \enspace & f(s) \in \mathcal T_2\end{aligned}  $$

-[$\mathcal T_2 \subseteq f(\mathcal T_1)$]  
$s \in \mathcal{T_2}$이라 하자.

$f$가 homeomorphism임으로 다음이 성립한다.
$$ \begin{aligned} & \text{preimg(s)} \in \mathcal T_1 \\ \Leftrightarrow \enspace & f^{-1}(s) \in \mathcal T_1 \\ \Leftrightarrow \enspace & s \in f(\mathcal T_1) \end{aligned}  $$

[$\Leftarrow$]  
-[$f$ is continous]  
$s \in \mathcal T_2$라 하자.

$f(\mathcal T_1) = \mathcal T_2$이고, $f$가 bijective임으로 다음이 성립한다.
$$ f^{-1}(s) \in \mathcal T_1 $$

따라서 다음이 성립한다.
$$ \text{preimg}(s) = f^{-1}(s) \in \mathcal T_1 $$

즉, $X_2$ 위의 임의의 open set에 대한 $f$의 preimage가 $X_1$위의 open set임으로 $f$는 continous이다.

-[$f^{-1}$ is continous]  
$s \in \mathcal T_1$라 하자.

$f(\mathcal T_1) = \mathcal T_2$이고, $f$가 bijective임으로 다음이 성립한다.
$$ f(s) \in \mathcal T_2 $$

따라서, 다음이 성립한다.
$$ \text{preimg}(s) = f(s) \in \mathcal T_2 $$

즉, $X_1$ 위의 임의의 open set에 대한 $f^{-1}$의 preimage가 $X_2$위의 open set임으로 $f^{-1}$는 continous이다. $\quad\tiny\blacksquare$

### 명제2
Topological space $X,Y$와 homeomorphism $f: X \rightarrow Y$가 있다고 하자.

open set $U \subseteq X$가 있을 때, 다음을 증명하여라.
$$ f|_U \text{ is a homeomorphism}$$

**Proof**

[$f|_U$ is bijective]  
bijective function의 restriction은 bijective function이다.

[$f|_U$ is continuous]  
continuous function의 restriction과 관련된 성질에 의해 다음이 성립한다.
$$ f|_U \text{ is a continuous} $$

[$(f|_U)^{-1}$ is continuous]  
inverse function의 restriction과 관련된 성질에 의해 다음이 성립한다.
$$ (f|_U)^{-1} = f^{-1}|_{f(U)} $$

$f$가 homeomorphism임으로 $f^{-1}$은 continuous function임으로 continuous function의 restriction과 관련된 성질에 의해 다음이 성립한다.
$$ \begin{aligned} & f^{-1}|_{f(U)} \text{ is a continuous} \\ \Leftrightarrow\enspace& (f|_U)^{-1} \text{ is a continuous} \end{aligned} $$





> Reference  
> [Proof Wiki](https://proofwiki.org/wiki/Restriction_of_Homeomorphism_is_Homeomorphism)