# Homeomorphism
Topological space $X,Y$가 있다고 하자.

$X$에서 $Y$로의 `위상동형사상(homeomorphism)` $\phi$는 다음과 같은 성질을 갖는 함수이다.
$$ \phi : X \rightarrow Y \quad s.t. \quad \phi, \phi^{-1} \text{ are continous. } $$

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

$f$가 homeomorphism임으로 $f^{-1}$도 continuous하고 따라서 다음이 성립한다.
$$ \begin{aligned} & \text{preimg(s)} \in \mathcal T_2 \\ \Leftrightarrow \enspace & f(s) \in \mathcal T_2\end{aligned}  $$

-[$\mathcal T_2 \subseteq f(\mathcal T_1)$]  
$s \in \mathcal{T_2}$이라 하자.

$f$가 homeomorphism임으로 다음이 성립한다.
$$ \begin{aligned} & \text{preimg(s)} \in \mathcal T_1 \\ \Leftrightarrow \enspace & f^{-1}(s) \in \mathcal T_1 \\ \Leftrightarrow \enspace & s \in f(\mathcal T_1) \end{aligned}  $$

[$\Leftarrow$]  
-[$f$ is continous]  
$s \in \mathcal T_2$라 하자.

$f(\mathcal T_1) = \mathcal T_2$이고, $f$가 bijective임으로 다음이 성립한다.
$$ \begin{aligned} & f^{-1}(s) \in \mathcal T_1 \\ \Leftrightarrow \enspace & \text{preimg}(s) \in \mathcal T_1 \end{aligned} $$

즉, $Y$에 있는 모든 open set의 preimage도 open set임으로 $f$는 continous이다.

-[$f^{-1}$ is continous]  
$s \in \mathcal T_1$라 하자.

$f(\mathcal T_1) = \mathcal T_2$이고, $f$가 bijective임으로 다음이 성립한다.
$$ \begin{aligned} & f(s) \in \mathcal T_2 \\ \Leftrightarrow \enspace & \text{preimg}(s) \in \mathcal T_2 \end{aligned} $$

즉, $X$에 있는 모든 open set의 preimage도 open set임으로 $f^{-1}$는 continous이다.

> Referece  
> [Book] (Lee) Introduction to Topological Manifolds Exercise 2.21