# Linear Algebra 4

## **Definition: coordinate**  
Let $V/F$ be a finite demensional vector space and $\beta = \{ v_1,\cdots, v_n \}$ be a basis of $V$.  
If 
$$ \exist a_1, \cdots ,a_n \in F \quad s.t \quad v=a_1v_1 + \cdots + a_nv_n$$  
We say $[v]_\beta = (a_1,\cdots,a_n)$ is a coordinate w.r.t $\beta$   
### Theorem
Let $V/F$ be a finite demensional vector space and $\beta = \{ v_1,\cdots, v_n \}$ be a basis of $V$.  
$$ \exist! [v]_\beta, \quad \forall v \in V$$
#### proof 
Existence)  
$$V=span(\beta) = \{ a_1v_1 + \cdots + a_nv_n | a_i \in F \}$$  
$$\therefore \exist (a_1,\cdots,a_n) \in F^n \quad s.t. \quad a_1v_1 + \cdots + a_nv_n=v \quad _\blacksquare$$
Uniquness)  
Suppose that
$$\exists b_1,\cdots, b_n \quad s.t. \quad a_1v_1 + \cdots + a_nv_n = b_1v_1 + \cdots + b_nv_n$$
Then 
$$(a_1-b_1)v_1 + \cdots + (a_n-b_n)v_n = 0_V $$
Here $e_{(V,+)} \equiv 0_V$.  
Since $\beta$ is linearly independent
$$a_1-b_1 =0, \; \cdots, a_n-b_n=0 $$
$$\Longleftrightarrow a_1=b_1, \cdots ,a_n=b_n \;\; {}_\blacksquare $$
### Remark
Finite dimensional vector space $V/F$: abstract concept.   
Basis $\beta$ : abstract concept, we only know its existence.  
we want to give meaning to *coordinate*.

## **Definition: linear transformation**
Let $V,W/F$ be finite demensional vector spaces.   
If $\Phi:V \rightarrow W$ preserve an linearity:  
$$\Phi(av_1+v_2)=a\Phi(v_1)+\Phi(v_2), \quad \forall v_1,v_2 \in V, \; \forall a \in F.$$  
We say $\Phi$ is an linear transformation.  
Additionally, we denote the vector space of all linear trasnformations from $V$ into $W$ by $L(V,W)$.
### Theorem
Let $V,W/F$ be finite demensional vector spaces and $\Phi \in L(V,W)$.  
Then $\Phi(0_V)=0_W$.
#### proof
Let $v \in V$ and $w = \Phi(v)$.
$$ \Phi(v)=\Phi(v+0_V)=\Phi(v)+\Phi(0_V) $$
$$ \Rightarrow w = w+\Phi(0_V)$$
$$ \therefore \Phi(0_V) = 0_W  $$

## **Definition: vector space isomorphism**  
Let $V,W/F$ be finite demensional vector spaces and $\Phi \in L(V,W)$.  
If $\Phi^{-1}:W \rightarrow V$ is also an linear transformation,  
We say $\Phi$ is a vector space isomorphism.  
### Theorem1  
Let $V,W/F$ be finite demensional vector spaces and $\Phi \in L(V,W)$.  
$\Phi$ is 1-1 and onto $\rightarrow$ $\Phi$ is a vector space isomorphism.
#### proof
Let $w_1,w_2 \in W$.  
Since $\Phi$ is one to one and onto,  
$$ \exist v_1,v_2 \in V \quad s.t. \quad \Phi(v_1)=w_1, \Phi(v_2)=w_2 $$
$$ \exist \Phi^{-1}$$
Since $\Phi \in L(V,W)$
$$\Phi(av_1+v_2) = aw_1+w_2, \quad \forall a \in F $$
$$\Rightarrow av_1+v_2=\Phi^{-1}(aw_1+w_2)$$
$$\Rightarrow \Phi^{-1}(aw_1+w_2)=a\Phi^{-1}(w_1)+\Phi^{-1}(w_2) \quad _\blacksquare $$
### Theorem2  
Let $V,W/F$ be finite demensional vector spaces, $\beta = \{ v_1 \; \cdots \; v_n \}$ be a basis of $V$ and $\Phi:V \rightarrow W$ be a vector space isomorphism.  
Define set $r$
$$ r :=  \{ \Phi(v_1),\cdots,\Phi(v_n) \}$$
Then $r$ is a basis of $W$.
#### proof
linearly independent of $r$)    
Suppose that
$$ \exist a_1,\cdots,a_n \quad s.t. \quad a_1\Phi(v_1)+\cdots+a_n\Phi(v_n) = 0_W$$
Since $\Phi \in L(V,W)$,
$$ \Phi(a_1v_1+\cdots+a_nv_n) = 0_W =\Phi(0_V) $$
$$ \Rightarrow a_1v_1+\cdots+a_nv_n = 0_V $$
$$ \therefore a_1=\cdots=a_n=0 \quad _\blacksquare$$
$\mathrm{span}(r)=W)$  
Since $r \subset W$
$$span(r)\subseteq W$$  
Since $\Phi$ is 1-1 and onto
$$ \quad \exists! v \in V \quad s.t \quad \Phi(v)=w, \quad \forall w \in W $$
$$ \Rightarrow w=\Phi(a_1v_1+\cdots+a_nv_n) $$
$$ \Rightarrow w=a_1\Phi(v_1)+\cdots+a_n\Phi(v_n) $$
$$ \Rightarrow w\in span(r) $$
$$\Rightarrow W \subseteq span(r) $$
$$\therefore span(r) = W  \quad _\blacksquare$$

## **Definition: isomorphic**  
Let $V,W/F$ be finite demensional vector spaces and $\Phi:V \rightarrow W$ be a vector space isomorphism.   
We call $V$ and $W$ are isomorphic and denote $V \overset{\Phi \;}{\cong} W$ or simply $V \cong W$.
### Theorem
Let $V,W/F$ be finite demensional vector spaces
$$V \cong W \iff \dim(V)=\dim(W)$$
#### proof
$\Rightarrow$)  
Suppose that $V \cong W$,  
Let $\beta = \{ v_1 \; \cdots \; v_n \}$ be a basis of $V$ and $\Phi:V \rightarrow W$ be a vector space isomorphism.  
Define set $r$
$$ r :=  \{ \Phi(v_1),\cdots,\Phi(v_n) \} \subset W $$
Then $r$ is basis of $W$.  
Therefore $\dim(V)=\dim(W)$. $_\blacksquare$  
$\Leftarrow$)   
Suppose that  $\dim(V)=\dim(W)$.  
Let $\beta, \gamma$ be basis of $V,W$ respectively.  
Define a map $\varphi$
$$\varphi:V \rightarrow W \quad s.t \quad [v]_\beta=[w]_\gamma$$  
Then
$$\varphi(av_1+v_2) = w, \quad \forall v_1,v_2 \in V, \forall a \in F$$
$$\Rightarrow [w]_\gamma = a[v_1]_\beta + [v_2]_\beta$$
$$\Rightarrow w = a\varphi(v_1) + \varphi(v_2)$$
Thus $\varphi \in L(V,W)$.  
Suppose that $\varphi(v_1) = \varphi(v_2)$.  
Then
$$ [\varphi(v_1)]_\gamma = [\varphi(v_2)]_\gamma $$
$$ \Rightarrow [v_1]_\beta = [v_2]_\beta $$
$$ \Rightarrow v_1 = v_2$$
Thus $\varphi$ is 1-1.  
Since $\dim(V)=\dim(W)$
$$ \forall w \in W, \exist v \in V \quad s.t. \quad [w]_\gamma=[v]_\beta$$
Thus $\varphi$ is onto.  
Therefore $\varphi$ is a vector space isomorphism. $_\blacksquare$
### Remark
For the classification of all vector spaces,  
Consider $\mathcal{F}:= \{V|V:vector~space~over~F \}$.  
Give the relation "$\sim$" on $\mathcal{F}$.  
If $V \sim W, \exist \Phi : V \rightarrow W, where~ \Phi :vector~space~isomorphism$.  
It can be expressed $\dim(V)=\dim(W)$.  
Then $\sim$ is an equivalence relation.  
So, we have the partition.  
In particular, Consider $F^n = F\times \cdots \times F : vector~space~over~F$.  
Then $\dim(F^n)=n$.  
For any n-dimensional vector space $V$, $V \sim F^n$.  
*e.g.*) $V=M_{nm}(\mathbb{R}) \sim \mathbb{R}^{nm}$.  
매우 추상적인 벡터 공간 $V$와 $\mathbb{R}$의 관계를 통해 우리가 편하게 서술할 수 있는 관점을 제공한다.