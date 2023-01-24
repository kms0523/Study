# Linear Algebra 1

## **Definition: binary operation**
Let $S$ be a set.  
If $*:S \times S \rightarrow S$ satisfies,
$$ (x*y)*z=x*(y*z), \quad \forall x,y,z \in S,$$   
We say $*$ is a binary operation.  

## **Definition: semigroup**
Let $S$ be a set and $*$ be a binary operation.  
Then we call $(S,*)$ a semigroup.  
### Example
$(\mathbb{N},+)$ is a semigroup.  
$(\mathbb{N},-)$ is not a semigroup ($\because -$ is not a binary operation).  
$(\{0,1\},\times)$ is a semigroup.

## **Defintion: monoid & identity**
Let $(M,*)$ be a semigroup.  
If
$$\exist e \in M \quad s.t. \quad a*e=e*a=a, \quad \forall a \in M$$  
We say $(M,*)$ is a monoid and $e$ is a identity of $M$.
### Example
$(\mathbb{N},+)$ is not a monoid $(\because 0 \notin \mathbb{N})$.  
$(\mathbb{N},\times),(\mathbb{Z},\times)$ are monoids.
### Theorem
Let $(M,*)$ be a monoid.  
Then $e$ of $M$ is unique.
#### proof
Let $e_1,e_2$ be indentities of $M$.  
$$e_1 = e_1*e_2 = e_2*e_1 = e_2 \quad _\blacksquare$$

## **Definition: group**
Let $(G,*)$ be a monoid.  
If 
$$\exist x^{-1} \in G \quad s.t. \quad x*x^{-1}=x^{-1}*x=e, \quad \forall x \in G$$  
we say $(G,*)$ is a group.
### Example
$(\mathbb{N},\times)$ is not a group. $\left(\because \frac{1}{x} \notin \mathbb{N} \;\; for \;\; x\in \mathbb{N}-\{1\} \right)$  
$(\mathbb{Z},+),(\mathbb{Q},+),(\mathbb{R},+)$ are groups.  
$(\mathbb{Q}-\{0\},\times),(\mathbb{R}-\{0\},\times)$ are groups.  
$(\{A \in M_{nn}(\mathbb{R}) | \det(A) \neq 0\},\times)$ is a group.  
$(\{f:A \rightarrow A | f : 1-1 \},\circ)$ is a group.
### Theorem1
Let $(G,*)$ be a group and $x,y,z \in G$.  
$x*z=y*z \Rightarrow x=y$.
#### proof
$$x=x*e=x*z*z^{-1}=y*z*z^{-1}=y$$
### Theorem2 
Let $(G,*)$ be a group and $x \in G$.  
Then $\exist!x^{-1}$.
#### proof
Let $x_1^{-1},x_2^{-1}$ be inverse of $x$.  
$$x*x_1^{-1}=x*x_2^{-1} \Rightarrow x_1^{-1}=x_2^{-1} \quad _\blacksquare$$

## **Definition: commutative group**
Let $(G,*)$ be a group.  
If 
$$x*y=y*x, \quad \forall x,y \in G$$  
we call $(G,*)$ a commutative group.

## **Definition: Abelian group**
Let $(G,*)$ be a commutative group.  
If $*=+$, we call $(G,+)$ be an Abelian group.

## **Definition: distributive**
Let $S$ be a set and $+:S \times S \rightarrow S$, $\cdot : S \times S \rightarrow S$.  
If  
$$(x+y)\cdot z = x \cdot z + y \cdot z$$
$$x \cdot (y+z) = x \cdot y + x \cdot z$$   
$$\forall x,y,z \in S $$
we call $\cdot$ is distributive w.r.t $+$.

## **Definition: ring**
Let $R$ be a set.  
If $R$ is equiibed with $+:R \times R \rightarrow R$, $\cdot : R \times R \rightarrow R$ and satisfy
1. $(R,+)$ is an Abelian group
2. $(R,\cdot)$ is a monoid
3. $\cdot$ is distributive w.r.t. $+$.
     
we call $(R,+,\cdot)$ a ring.

## **Definition: field**
Let $(F,+,\cdot)$ be a ring.  
If $(F-\{e_+\},\cdot)$ is a commutative group  
we call $(F,+,\cdot)$ a field
### Remark
사칙연산이 만족한다의 엄밀한 정의
### Example
$(\mathbb{R},+,\times)$ is a field.  
$(\mathbb{Q},+,\times)$ is a field.

## **Definition: module**
Let $M$ be a set and $R$ be a ring.  
If $M$ is equuipped with addition $+:M \times M \rightarrow M$ and scalalr multiplication $\cdot: R\times M \rightarrow M$ and satisfy
1. $(M,+)$ is Abelian group
2. $\forall r_1,r_2 \in R, \forall m\in M, \quad (r_1 + r_2)m = r_1m+r_2m$
3. $\forall r \in R, \forall m_1,m_2\in M, \quad r(m_1+m_2) = rm_1+rm_2$
4. $\forall m \in M, \quad e_{(R,+)}m=e_{(M,+)}$
5. $\forall r_1,r_2 \in R, \forall m\in M, \quad (r_1r_2)m = r_1(r_2m)$

we call $(M,+,\cdot)$ a module
### Remark
적절한 compatability(distributive & associative property)를 부여하여 다루기 쉬운 구조를 갖는다.

## **Definition: vector space**
Let $F$ be a field.
If $V$ is a $F$ module,  
we call $V$ a vector space.

## **Definition: algebra**
Let $R$ be a ring and $A$ be a set.  
If $A$ has 3 operations with compatability
$$ +:A \times A \rightarrow A $$
$$ \times:A \times A \rightarrow A $$
$$ \cdot:R \times A \rightarrow A $$
we call $A$ an algebra.