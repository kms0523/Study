# Boundary
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, $X$에서 $U$의 `boundary` $\partial U$는 다음과 같이 정의된다.
$$ \partial U := X - (\Int(U) \cup \Ext(U)) $$

### 명제1
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, 다음을 증명하여라.
$$ x \in \partial U \iff \forall \mathcal{N_x}, \quad \exist y_1,y_2 \in \mathcal{N_x} \quad s.t. \quad y_1 \in U \land y_2 \in X-U $$

**Proof**

[$\implies$]
$\partial U$의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \partial U &= X - (\Int(U) \cup \Ext(U)) \\&= X \cap (\Int(U)^C \cap \Ext(U)^C) \\&= (X-\Int(U)) \cap (X-\Ext(U)) \\&= (X-\Int(U)) \cap (X-(X-\bar{U}))) \\&= (X-\Int(U)) \cap \bar{U} \end{aligned} $$

그럼으로, $x \in \partial U$에 대해서 다음이 성립한다.
$$ x \notin \Int(U) \land x \in \bar{U} $$

이 떄, Interior의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} &\nexists \mathcal{N_x} \quad s.t. \quad \mathcal{N_x} \subseteq U \\\implies& \exist y \in \mathcal{N_x} \quad s.t. \quad y \in X-U \end{aligned} $$

동시에, closure의 성질에 의해 다음이 성립한다.
$$ \begin{aligned} &\mathcal{N_x} \cap U \neq \empty \\\implies& \exist y \in \mathcal{N_x} \quad s.t \quad y \in U  \end{aligned}  $$

[$\impliedby$]
가정을 만족하는 $x \in X$가 있다고 하자.

가정에 의해 다음이 성립한다.
$$ \begin{aligned} & y_1 \in U \\\implies& \forall\mathcal{N_x}, \quad \mathcal{N_x} \cap U \neq \empty \\\implies& x \in \bar{U} \\& y_2 \in X-U \\\implies& y_2 \notin \Int(U) \\\implies& \nexists\mathcal{N_x} \st \mathcal{N_x} \subseteq U \\\implies& x \notin \Int(U) \end{aligned} $$

따라서, 다음이 성립한다.
$$ \begin{aligned} &x \notin \Int(U) \land x \in \bar{U} \\\implies& x \in (X-\Int(U)) \cap \bar{U} \\\implies& x \in \partial U \qed  \end{aligned}  $$

> Reference
> [northeastern.edu](https://web.northeastern.edu/suciu/MATH4565/MATH4565-fa21-handout2.pdf)

### 명제2
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, 다음을 증명하여라.
$$ x \in \partial U \implies x \in \bar{U} $$

**Proof**

$X$의 closed set $A$가 다음을 만족한다고 하자.
$$ U \subseteq A $$

이 떄, 다음을 가정하자.
$$ \exist A \st x \notin A $$

가정을 만족하는 $A$에 대해 $X-A$가 open set임으로 다음이 성립한다.
$$ \exist\mathcal{N_x} \st \mathcal{N_x} \subseteq X-A $$

전제에 의해 $x \in \partial U$임으로 위의 명제는 명제1에 모순된다.

따라서, proof by contradiction에 의해 다음이 성립한다.
$$ \forall A, \quad x \in A $$

$U$를 포함하는 모든 closed set에는 $x$가 원소로 존재함으로, closure의 정의에 의해 다음이 성립한다.
$$ x \in \bar{U} \qed $$

> Reference
> [math.stackexchange](https://math.stackexchange.com/questions/703911/prove-that-the-union-of-the-interior-of-a-set-and-the-boundary-of-the-set-is-the)

#### 따름명제2.1
다음을 증명하여라.
$$ \partial U \subseteq \bar{U} $$

### 명제3
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 때, 다음을 증명하여라.
$$ x \in \bar{U} \iff x \in \Int(U) \cup \partial U $$

**Proof**

[$\implies$]
다음을 가정하자.
$$ x \in \Ext(U) $$

Exterior point의 성질에 의해 다음이 성립한다.
$$ \exist\mathcal{N_x} \st \mathcal{N_x} \subseteq X-U $$

따라서, $X-\mathcal{N_x}$는 다음을 만족한다.
$$ \begin{aligned} &X-\mathcal{N_x} \text{ is closed set of } X \\\land\enspace& U \subseteq X-\mathcal{N_x} \\\land\enspace& x \notin X-\mathcal{N_x} \end{aligned} $$

하지만 이는 Closure의 정의에 의해 $x \in \bar{U}$에 모순된다.

따라서, proof by contradiction과 보조명제3.1에 의해 다음이 성립한다.
$$ \begin{aligned} x &\in \Ext(U)^C \\&\in \partial U \cup \Int(U) \end{aligned}  $$

[$\impliedby$]
가정에 의해 다음이 성립한다.
$$ x \in \Int(U) \lor x \in \partial U $$

$x \in \Int(U)$인 경우에는 closure의 정의에 의해 자명하게 다음이 성립한다.
$$ x \in \bar{U} $$

$x \in \partial U$인 경우에는 명제2에 의해 다음이 성립한다.
$$ x \in \bar{U} \qed $$
#### 보조명제3.1
다음을 증명하여라.
$$ \Ext(U)^C = \partial U \cup \Int(U) $$

**Proof**

정의에 의해 $\partial U \cap \Ext(U) = \empty, \enspace \Int(U) \cap \Ext(U) = \empty$임으로 다음이 성립한다.
$$ \begin{aligned} \Ext(U)^C &= X - \Ext(U) \\&= (\partial U\cup\Int(U)\cup\Ext(U)) \cap \Ext(U)^C \\&= (\partial U - \Ext(U))\cup(\Int(U) - \Ext(U))\cup\empty \\&= \partial U \cup\Int(U) \qed \end{aligned} $$

#### 따름명제3.1
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄, 다음을 증명하여라.
$$ \bar{U} = \Int(U) \cup \partial U $$

**Proof**

명제3에 의해 자명하다.$\qed$

### 명제4
다음을 증명하여라.
$$ U \cup \partial U = \Int(U) \cup \partial U $$

**Proof**

[$U \cup \partial U \subseteq \Int(U) \cup \partial U$]
-[$U \subseteq \Int(U)\cup\partial U$]
$x \in U$가 있으면 명제3에 의해 다음이 성립한다.
$$ \begin{aligned} x &\in U \\&\in \bar{U} \\&\in \Int(U) \cup \partial U \end{aligned} $$

따라서, 다음이 성립한다.
$$ U \subseteq \Int(U)\cup\partial U $$

-[$\partial U \subseteq \Int(U)\cup\partial U$]
자명하다.

[$\Int(U) \cup \partial U \subseteq U \cup \partial U$]
자명하다. $\qed$

#### 따름명제 4.1
다음을 증명하여라.
$$ \bar{U} = U \cup \partial U $$

**Proof**

명제3,4에 의해 성립한다. $\qed$

### 명제5
Topological space $X$가 있다고 하자.

$X$의 subset $U$가 있을 떄,다음을 증명하여라.
$$ \partial U \text{ is a closed set of } X $$

**Proof**

Boudnary의 정의에 의해 다음이 성립한다.
$$ X - \partial U = \Int(U)\cup\Ext(U) $$

이 떄, $\Int(U), \Ext(U)$ 모두 $X$의 open set이고 open set의 union은 open set임으로 다음이 성립한다.
$$ X - \partial U \text{ is an open set of } X $$

따라서 closed set의 정의에 의해 다음이 성립한다.
$$ \partial U \text{ is a closed set of } X \qed $$

### 명제6
Topological space $X$가 있다고 하자.

$X$의 open set $U$가 있을 떄, 다음을 증명하여라.
$$ U \cap \partial U = \empty $$

**Proof**

Boundary의 정의에 의해 다음이 성립한다.
$$ \partial U \cap \Int(U) = \empty  $$

이 떄, $U$가 open set임으로 다음이 성립한다.
$$ U = \Int(U) $$

따라서 다음이 성립한다.
$$ U \cap \partial U = \empty \qed $$

### 명제7
Topological space $X$가 있다고 하자.

$X$의 closed set $U$가 있을 떄, 다음을 증명하여라.
$$ \partial U \subseteq U $$

**Proof**

$U$가 closed set임으로 다음이 성립한다.
$$ U = \bar{U} $$

따라서, 명제 2에의해 다음이 성립한다.
$$ \partial U \subseteq \bar{U} \implies \partial U \subseteq U \qed $$

