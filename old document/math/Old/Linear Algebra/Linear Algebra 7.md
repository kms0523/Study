# Linear Algebra 7

## Homomorphism
Recall that $(\mathbb{R},+),(\mathbb{R_{>0}},\times)$ are groups.  
Let $\exp:\mathbb{R} \rightarrow \mathbb{R_{>0}}$ as $x \mapsto e^x=\exp(x)$.  
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