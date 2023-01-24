- [1.군,환,체,가군,벡터공간,대수의 정의](#1군환체가군벡터공간대수의-정의)
  - [Binary operation](#binary-operation)
    - [Remark](#remark)
  - [Semigroup](#semigroup)
    - [Remark](#remark-1)
    - [Example](#example)
  - [Monoid & Identity](#monoid--identity)
    - [Remark](#remark-2)
    - [Example](#example-1)
    - [Theorem](#theorem)
      - [proof](#proof)
  - [Group](#group)
    - [Remark](#remark-3)
    - [Example](#example-2)
    - [Theorem1](#theorem1)
      - [proof](#proof-1)
    - [Theorem2](#theorem2)
      - [proof](#proof-2)
  - [Commutative Group](#commutative-group)
  - [Abelian Group](#abelian-group)
  - [Distributive](#distributive)
  - [Ring](#ring)
  - [Field](#field)
    - [Remark](#remark-4)
    - [Example](#example-3)
  - [Module](#module)
    - [Remark](#remark-5)
  - [Vector space](#vector-space)
  - [Algebra](#algebra)
- [2.선형결합의 추상화](#2선형결합의-추상화)
  - [linear algebra - abstract algebra](#linear-algebra---abstract-algebra)
    - [Theorem](#theorem-1)
      - [proof](#proof-3)
    - [Remark](#remark-6)
  - [Subgroup](#subgroup)
    - [Remark1](#remark1)
    - [Remark2](#remark2)
      - [Example](#example-4)
  - [Span](#span)
    - [Exercise1](#exercise1)
      - [proof](#proof-4)
    - [Remark](#remark-7)
    - [Exercise2](#exercise2)
      - [Proof](#proof-5)
    - [Exercise4](#exercise4)
- [3. 대수적 구조를 보존하는 함수 algebraic homomorphisms](#3-대수적-구조를-보존하는-함수-algebraic-homomorphisms)
  - [Homomorphism](#homomorphism)
  - [Definition : group homomorphism](#definition--group-homomorphism)
    - [Proposition](#proposition)
    - [Proposition](#proposition-1)
    - [Proposition](#proposition-2)
  - [Definition : Kernel](#definition--kernel)
    - [Proposition](#proposition-3)
    - [Proposition](#proposition-4)
    - [Remark](#remark-8)
  - [Definition : group monomorphism](#definition--group-monomorphism)
  - [Definition : group epimorphism](#definition--group-epimorphism)
  - [Definition : group isomorphism](#definition--group-isomorphism)
  - [Definition : ring homomorphism](#definition--ring-homomorphism)
  - [Definition : modoule homomorphism](#definition--modoule-homomorphism)
  - [Definition : linear transformation](#definition--linear-transformation)

# 1.군,환,체,가군,벡터공간,대수의 정의

## Binary operation
Let $S$ be a set.  

If $*:S \times S \rightarrow S$ satisfies,
$$ \forall x,y,z \in S, \quad (x*y)*z=x*(y*z)$$   
We say $*$ is a binary operation
### Remark
Associated law(결합법칙)

## Semigroup
Let $S$ be a set and $*$ be a binary operation. 

Then we call $(S,*)$ a semigroup.  

### Remark
Binary operation이 정의된 집합

### Example
$(\N,+)$ is a semigroup.  
$(\N,-)$ is not a semigroup ($\because -$ is not a binary operation).  
$(\{0,1\},\times)$ is a semigroup.

## Monoid & Identity
Let $(M,*)$ be a semigroup.  

$$ if \quad \exist e \in M \quad s.t. \quad a*e=e*a=a, \quad \forall a \in M$$  
We say $(M,*)$ is a monoid and $e$ is a identity of $M$.

### Remark
Identity가 존재하는 semigroup

### Example
$(\N,+)$ is not a monoid $(\because 0 \notin \N)$.  

$(\N,\times),(\mathbb{Z},\times)$ are monoids.

### Theorem
Let $(M,*)$ be a monoid.  

Then $e$ of $M$ is unique.

#### proof
Let $e_1,e_2$ be indentities of $M$.  
$$e_1 = e_1*e_2 = e_2*e_1 = e_2 \quad _\blacksquare$$

## Group
Let $(G,*)$ be a monoid.
$$ if \quad \forall x \in G, \quad \exist x^{-1} \in G \quad s.t. \quad x*x^{-1}=x^{-1}*x=e $$  
we say $(G,*)$ is a group.

### Remark
역원이 존재하는 monoid

### Example
$(\N,\times)$ is not a group. $\left(\because \frac{1}{x} \notin \N \;\; for \;\; x\in \N-\{1\} \right)$  

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

## Commutative Group
Let $(G,*)$ be a group.  
$$if \quad \forall x,y \in G, \quad x*y=y*x$$  
we call $(G,*)$ a commutative group.

## Abelian Group
Let $(G,*)$ be a commutative group.  

If $*=+$, we call $(G,+)$ be an Abelian group.

## Distributive
Let $S$ be a set and $+:S \times S \rightarrow S$, $\cdot : S \times S \rightarrow S$.  

$$ if \quad \forall x,y,z \in S, \quad \text{satisfying} $$
$$(x+y)\cdot z = x \cdot z + y \cdot z$$
$$x \cdot (y+z) = x \cdot y + x \cdot z$$   
$$ $$
we call $\cdot$ is distributive w.r.t $+$.

## Ring
Let $R$ be a set and $+:R \times R \rightarrow R$, $\cdot : R \times R \rightarrow R$. 

$$ if \quad (R,+,\cdot) \quad \text {satisfying} $$
$$ (R,+) \text{ is an Abelian group} $$
$$ (R,\cdot) \text { is a monoid } $$
$$ \cdot \text { is distributive w.r.t. } + $$
     
we call $(R,+,\cdot)$ a ring.

## Field
Let $(F,+,\cdot)$ be a ring. 

If $(F-\{e_+\},\cdot)$ is a commutative group  

we call $(F,+,\cdot)$ a field

### Remark
사칙연산이 만족한다의 엄밀한 정의

### Example
$(\mathbb{R},+,\times)$ is a field.  

$(\mathbb{Q},+,\times)$ is a field.

## Module
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

## Vector space
Let $F$ be a field.  
If $V$ is a $F$ module,  
we call $V$ a vector space.

## Algebra
Let $R$ be a ring and $A$ be a set.  
If $A$ has 3 operations with compatability
$$ +:A \times A \rightarrow A $$
$$ \times:A \times A \rightarrow A $$
$$ \cdot:R \times A \rightarrow A $$
we call $A$ an algebra.

# 2.선형결합의 추상화
## linear algebra - abstract algebra
Recall that given a vector space $V/F$.  

given $W \subseteq V$, $span(W):=\{a_1w_1+ \cdots +a_nw_n|w_i\in W, a_i \in F, n \in \N \}$

Observe that $span(W)$ is a vector space over $F$.  

Also $W\subseteq span(W) \subseteq V$.  

If $H$ is a vector space in $V$ containing $W$, then $span(W)\subseteq H$.  

Thus, $span(W)$ is the smallest subspace of $V$ containing $W$.

### Theorem
Given a vector space $V/F$, $W \subseteq V$.  
$$ \text{Define subspace} \quad H \le V \quad s.t. \quad  W \subseteq H $$
($\le$ means it has vector space structure.)

Then $span(W)=\cap H$

#### proof
[proof of $span(W) \subseteq \cap H$]

Take any $v \in span(W)$ and $H$.  

Write $v = a_1v_1+ \cdots + a_nv_n$, $v_i \in W, a_i \in F$.  

Since $v_i \in H$ and $H$ is a vector space over $F$,  $v = a_1v_1+ \cdots + a_nv_n \in H$.

Thus $v \in \cap H$

[proof of $span(W) \supseteq \cap H$]

It is enough to show $span(W)$ is, in fact, one of such $H$.  

$W\subseteq span(W) \le V$.

### Remark
given a vector space $V/F$, $\exists \text{ basis } \beta$ of $V$.  

$\beta$ is the maximal linearly independent set.

Moreover, $span(\beta)=V$.  

즉 $\beta$를 포함하고 vector space 구조가 되는 가장 작은 집합이 $V$이다.

## Subgroup
Let $(G,*)$ be a group and $H\subseteq G$.  

If $(H,*)$ is a group,

We say $H$ is a subgroup of $G$ and denote $H\le G$.

### Remark1
Let $(H,*) \le (G,*)$.  

By the uniqueness of identity, $e_H=e_G$.  

### Remark2
Let $H \subseteq G$.  

Then $H\le G$ iff $\forall a,b\in H, a*b\in H$ and $\forall c \in H, c^{-1} \in H$.

#### Example
$$(\mathbb{Q},+) \le (\mathbb{R},+)$$
$$(\mathbb{Q}-\{0\},\times) \le (\mathbb{R}-\{0\},\times)$$

## Span
Let $(G,*)$ be a group and $S\subseteq G$.  

$$ \text{Define} \quad H \le G \quad s.t. \quad S \subseteq H $$

Then 

$$span(S) := \cap H$$

the subgroup generated by $S$.

### Exercise1
Show that $\cap H \le G$.

#### proof
[proof of $e_G \in \cap H$]

Since $\forall i, \quad e_G \in H_i$, $e_G \in \cap H$

[proof of $x^{-1} \in \cap H$]

Suppose that $x \in \cap H$.
$$ then \quad \forall i, \quad x \in H_i $$

Since $\forall i, \quad H_i \le G$, 
$$ \forall i, \quad x^{-1} \in H_i $$
$$ \Rightarrow x^{-1} \in \cap H $$

Therefore, $\cap H$ is also group.

### Remark
$span(S)$ is the smallest subgroup of $G$ containing $S$.  

### Exercise2
Let $(G,+)$ be an abelian group.  

pick $x\in G$ $(\{ x \} \subseteq G)$  

$$span(\{ x \}) = \{ nx | n \in \mathbb{Z} \}$$

#### Proof
$$ \text{show that } \{ nx|n \in \mathbb{Z}\} \le G $$

show that $\{ nx|n \in \mathbb{Z}\}$ is the smallest. 

i.e., $\forall H \le G s.t. \{x\} \subseteq H, \{ nx | n \in \mathbb{Z} \} \subseteq H$.

### Exercise4
Let $(G,+)$ be an abelian group.  

pick $x,y \in G$.  

show that $span(\{x,y\})=\{nx+my|n,m \in \mathbb{Z}\}$.

# 3. 대수적 구조를 보존하는 함수 algebraic homomorphisms

## Homomorphism
Recall that $(\R,+),(\R_{>0},\times)$ are groups.  

Let $\exp:\R \rightarrow \R_{>0}$ as $x \mapsto e^x=\exp(x)$.  

Then we know
$$\exp(x+y)=\exp(x) \times \exp(y)$$
$$\exp(0)=1$$
$$\exp(-x)=\exp(x)^{-1}$$

Thus the group operations are preserved by $\exp$.  

In particualr, the identity of $(\mathbb{R},+)$ goes to the identity of $(\mathbb{R_{>0}},\times)$.  

Also, each inverse element of $x$ in $(\mathbb{R},+)$ goes to the inverse element of $\exp(x)$ in $(\mathbb{R_{>0}},\times)$.  

Moreover, $\exp$ is 1-1 and onto.  

Hence, $(\mathbb{R},+) \overset{\exp \;}{\cong} (\mathbb{R_{>0}},\times)$.(as groups).

## Definition : group homomorphism
Given $(G,*),(H,\cdot)$ groups,  
We call $f:G \rightarrow H$ is a group homomorphism  
if $\forall g_1,g_2 \in G, \quad f(g_1*g_2)=f(g_1) \cdot f(g_2)$

### Proposition 
Given $(G,*),(H,\cdot)$ groups and $f:G \rightarrow H$ is a group homomorphism.  
Then $f(e_{(G,*)})=e_{(H,\cdot)}$.

### Proposition 
Given $(G,*),(H,\cdot)$ groups and $f:G \rightarrow H$ is a group homomorphism.  
Then $\forall g \in G, f(g^{-1})=(f(g))^{-1}$

### Proposition 
Given $(G,*),(H,\cdot)$ groups and $f:G \rightarrow H$ is a group homomorphism.  
Then Image of $f$ is subgroup of $H$.

## Definition : Kernel
Given $(G,*),(H,\cdot)$ groups and $f:G \rightarrow H$ is a group homomorphism.  
$$\ker(f):=\{ g \in G | f(g) = e_{(H,\cdot)} \}$$

### Proposition
Given $(G,*),(H,\cdot)$ groups and $f:G \rightarrow H$ is a group homomorphism.  
Then $\ker(f)$ is subgroup of $G$

### Proposition
Given $(G,*),(H,\cdot)$ groups and $f:G \rightarrow H$ is a group homomorphism.  
Then $\ker(f)=\{e_{(G,*)}\} \iff$ $f$ is 1-1.

### Remark
Let $V,W/F$ be vector spaces and $\Phi: V \rightarrow W$ be an linear transformation.  
Then 
$$\ker(\Phi)=\{v \in V | \Phi(v) = 0 \} \le V$$
$$\mathrm{img}(\Phi) \le W $$
Recall that vector space has additional structure 'basis'.  
Thus we call $\dim(\ker(\Phi))$ as the nulltiy of $\Phi$.  
and we call $\dim(\mathrm{img}(\Phi))$ as the rank of $\Phi$.


## Definition : group monomorphism
Given $(G,*),(H,\cdot)$ groups,  
We call $f:G \rightarrow H$ is a group monomorphism  
if $f$ is group homomorphism and 1-1.

## Definition : group epimorphism
Given $(G,*),(H,\cdot)$ groups,  
We call $f:G \rightarrow H$ is a group epimorphism  
if $f$ is group homomorphism and onto.

## Definition : group isomorphism
Given $(G,*),(H,\cdot)$ groups,  
We call $f:G \rightarrow H$ is a group isomorphism  
if $f$ is group homomorphism and 1-1 and onto.  
We write $G \overset{f\;}{\cong} H$ and say $G$ and $H$ have the same group structure.

## Definition : ring homomorphism
Given $(R_1,+_1,\times_1),(R_2,+_2,\times_2)$ rings,  
We call $f:R_1 \rightarrow R_2$ is a ring homomorphism  
if $\forall r_1,r_2 \in R_1$
$$f(r_1 +_1 r_2)=f(r_1) +_2 f(r_2)$$
$$f(r_1 \times_1 r_2)=f(r_1) \times_2 f(r_2)$$

## Definition : modoule homomorphism
Given a ring R, and R-Modules $(M_1,+_1,\cdot_1),(M_2,+_2,\cdot_2)$,  
We call $f:M_1 \rightarrow M_2$ is a module homomorphism  
if $\forall m_1,m_2 \in M_1$, $\forall r \in R$
$$f(m_1 +_1 m_2)=f(m_1) +_2 f(m_2)$$
$$f(r \cdot_1 m_1)=r \cdot_2 f(m_1)$$
Thus $f(rm_1+m_2) = r_1f(m_1)+f(m_2)$ and $f$ has linearity.

## Definition : linear transformation
Ginve a field $F$ and vector spaces $V,W/F$.  
We say $\Phi:V \rightarrow W$ is a linear transformation  
if $\Phi$ is a module homomorphism$/F$

