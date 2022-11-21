# Exteriror
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, $X$에서 $U$의 `exterior` $\Ext(U)$는 다음과 같이 정의된다.
$$ \Ext(U) := X - \bar{U} $$

### 명제1
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ \Ext(U) \text{ is an open set of } X $$

**Proof**

closure의 성질에 의해 $\bar{U}$가 $X$의 closed set이다.

따라서, closed set의 정의에 의해 $X-\bar{U}$는 $X$의 open set임으로 다음이 성립한다. 
$$ \Ext(U) \text{ is an open set of } X \qed $$


### 명제2
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ x \in \Ext(U) \iff \exist\mathcal{N_x} \subseteq X -U $$

**Proof**

[$\implies$]
명제1에 의해 $\Ext(U)$는 open set임으로 다음이 성립한다.
$$ \Int(\Ext(U)) = \Ext(U) $$

따라서, interior의 성질에 의해 다음이 성립한다.
$$ x \in \Ext(U) \implies \exist\mathcal{N_x} \subseteq \Ext(U) $$

$\Ext(U)$의 정의와 $U \subseteq \bar{U}$임으로 다음이 성립한다.
$$ \begin{aligned} x \in \Ext(U) &\implies \exist\mathcal{N_x} \subseteq \Ext(U) \\&\implies \exist\mathcal{N_x} \subseteq X - \bar{U} \\&\implies \exist\mathcal{N_x} \subseteq X - U \end{aligned} $$

[$\impliedby$]
$x \in X-U$가 있다고 하자.

$X - U$에 포함되는 $\mathcal{N_x}$가 존재하기 때문에 다음이 성립한다.
$$ \exist \text{open set } A \quad s.t. \quad x \in A \subseteq X-U $$

이 때, closure의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} &A \subseteq X-U \\\implies& A \subseteq X - \bar{U} \\\implies& A \subseteq \Ext(U) \\\implies& x  \in \Ext(U) \qed \end{aligned} $$