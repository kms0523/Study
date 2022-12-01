Norm
==

$\mathit{Definition}$  
--
A norm is a generalization of notion of “length”.  
Let $V$ be a vector space   
A norm is a function, $||⋅||: V \rightarrow \mathbb{R^+}$ that satisfies the following conditions.  
$$\forall v_1,v_2 \in V, \quad \forall \alpha \in \mathbb{R}$$
1. $$ ||v_1+v_2||\le||v_1||+||v_2|| $$
2. $$ ||\alpha v||=|\alpha| \cdot ||v||$$
3. $$ ||v||= 0 \rightarrow v=0_V$$

<br><br>

Inner product space
==

$\mathit{Definition}$
--
An inner product space is a vector space $V$ over the field $F$ together with a map
$$\langle \cdot , \cdot \rangle : V \times V \rightarrow F $$
called an inner product that satisfies the following conditions.  
$$ \forall v_1,v_2,v_3 \in V, \quad \forall a \in F $$
1. $$ \lang av_1+v_2,v_3\rang = a \lang v_1,v_3 \rang + \lang v_2,v_3 \rang  $$
2. $$ \lang v_1,v_2 \rang = \overline{\lang v_2,v_1 \rang}  $$
3. $$ if \quad v_1 \neq 0_V \Rightarrow \lang v_1,v_1 \rang > 0 $$

<br>

$\mathit{Properties}$
--
1. $$ \lang 0_V,0_V \rang = 0 $$
$\mathit{proof}$
$$ \lang 0_V,0_V \rang = \lang 0_V+0_V,0_V \rang = \lang 0_V,0_V \rang + \lang 0_V,0_V \rang $$
$$ \therefore \lang 0_V,0_V \rang =0 \quad {}_\blacksquare $$ 

<br>

2. $$\lang v_1,v_1 \rang \in \mathbb{R}^+$$
$\mathit{proof}$  
$$ \lang v_1,v_1 \rang = \overline{\lang v_1,v_1 \rang} \quad {}_\blacksquare  $$

<br>

3. $$\lang v_1,av_2+v_3 \rang = \bar{a} \lang v_1,v_2 \rang + \lang v_1,v_3 \rang  $$
$\mathit{proof}$  
$$ \lang v_1,av_2+v_3 \rang = \overline{\lang av_2+v_3,v_1 \rang} = \bar{a} \overline{\lang v_2,v_1 \rang} + \overline{\lang v_3,v_1 \rang} = \bar{a} \lang v_1,v_2 \rang + \lang v_1,v_3 \rang \quad {}_\blacksquare  $$

<br>

4. <center> Inner product spaces are normed vector spaces for the norm defined by <center>
$$ ||v||=\sqrt{\lang v,v \rang} $$

5. $$ if \quad \lang v_1,v_2 \rang = 0 \Rightarrow ||v_1+v_2||^2=||v_1||^2+||v_2||^2 $$
$\mathit{proof}$

$$ \lang v_1+v_2,v_1+v_2 \rang = \lang v_1,v_1 \rang + 2\lang v_1,v_2 \rang + \lang v_2,v_2 \rang $$
$$ \therefore ||v_1+v_2||^2=||v_1 ||^2+||v_2 ||^2 \quad {}_\blacksquare $$

<br>

## $\mathit{Definition - closest}$  
Let $V$ be a inner product space and $W \subset V$ and $v \in V$ , $w \in W$.  
If $w$ satisfy $\forall \tilde{w} \in W, ||v-w||\le||v-\tilde{w}||$,  
Then $w$ is closest to $v$.

<br>

## $\mathit{Theorem~1}$  
Let $V$ be a inner product space and $W \subset V$ and $v \in V$ , $w \in W$.  
Then $w$ is closest to $v$ if and only if $v-w \perp W$  .

$\mathit{proof}$  
($\Leftarrow$)  
Suppose that $v-w \perp W$.   
$$ ||v-w||\le||v-\tilde{w}|| \Longleftrightarrow ||v-w||^2\le||v-\tilde{w}||^2$$
$$ \Rightarrow ||v-\tilde{w}||^2=||(v-w)+(w-\tilde{w})||^2=||v-w||^2+||w-\tilde{w}||^2 $$
$$ \Rightarrow ||v-\tilde{w}||^2 \le ||v-w||^2  \Longleftrightarrow ||v-w||\le||v-\tilde{w}|| \quad {}_\blacksquare $$

($\Rightarrow$)  
Suppose that $w$ is closest to $v$.  
Define function $f:\mathbb{R} \rightarrow \mathbb{R}$.  
$$ f(t):=||v-w+tx||^2, \quad x \in W $$
Then
$$f(t)= \lang v-w+tx,v-w+tx \rang = ||v-w||^2 + 2t\lang v-w,x \rang + t^2||x||^2 $$
$$\Rightarrow f'(t) = 2\lang v-w,x \rang +2t||x||^2 $$
$$\Rightarrow f'(0) = 2\lang v-w,x \rang $$
Since $f(t)$ has minima at 0
$$\lang v-w,x \rang =0 $$
As $x \in W$ was arbitrary, it follows that $v-w \perp W \quad _\blacksquare$

<br>

## $\mathit{Definition - projection }$
Let $V$ be a inner product space and $W \subset V$ and $v \in V$ , $w \in W$.  
If $w$ is closest to $v$,  
Then w us a projection of $v$ onto $W$.

<br>

## $\mathit{Theorem~2}$
Let $V$ be a inner product space and $W \subset V$ and $v \in V$ , $w \in W$.  
Let orthogonal basis of $W$ be $\phi_1,\cdots,\phi_n$.  
If $w$ is projection of $v$,  
Then 
$$ w = \sum_{i=1}^n a_i\phi_i  $$
$$ \mathrm{where} \quad a_i = \frac{\lang v, \phi_i \rang}{\lang \phi_i, \phi_i \rang}$$

### *proof*
Since $w \in W$
$$w = \sum_{i=1}^n a_i\phi_i$$  
Since $w$ is closest of $v$
$$ v-w \perp W $$
$$ \Rightarrow \lang v-w,\phi_i \rang = 0 \quad \forall i $$
$$ \Rightarrow \lang v,\phi_i \rang - \lang w,\phi_i \rang = 0 \quad \forall i $$
$$ \Rightarrow \lang v,\phi_i \rang = a_i \lang \phi_i, \phi_i \rang \quad \forall i$$
$$ \therefore a_i = \frac{\lang v, \phi_i \rang}{\lang \phi_i, \phi_i \rang} \quad _\blacksquare $$

<br>

## $\mathit{Theorem~3}$
Consider 
$${Ax=b}$$
$${A} \in M_{mn}(\mathbb{R}), \quad {x} \in F^n(\mathbb{R}), \quad {b} \in F^m(\mathbb{R}), \quad n < m $$  
${||Ax-b||}$ is minimized when ${x}={(A^TA)^{-1}A^Tb}$.

$\mathit{proof}$  
Let ${A}_{j*}$ denote the *jth* column of ${A}$.
$$ {A}=\begin{bmatrix} \vert &  & \vert \\ {A}_{1*} & \cdots & {A}_{n*} \\ \vert & & \vert  \end{bmatrix} $$
Then
$$ {Ax} = \sum_j{x_j{A}_{j*}} $$
The columns of ${A}$ span a $\{ {A}_{j*}\}$ $n$-dimensional subspace within the larger $m$-dimensional vector space that contains the vector ${b}$.  
Since $F^m(\mathbb{R})$ is inner proudct vector space, ${||Ax-b||}$ be minimized when ${Ax}$ is closest to ${b}$.
$${Ax-b} \perp \{{A}_{j*}\}$$
$$ \Rightarrow \lang {Ax-b}, {A}_{j*} \rang = 0, \quad \forall j $$
Written as a matrix equation
$$ ({Ax-b})^T {A}=0_n $$
$$ \Rightarrow {A}^T({Ax-b})=0_n $$
$$ \therefore {x}={(A^TA)^{-1}A^Tb} \quad _\blacksquare $$
