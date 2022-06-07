# Linear Algebra 5

## $\mathit{Definition \; 5.1 - Matrix \; representation}$
Let $V/F$ and $W/F$ be vector spaces with $dim(V)=n$ and $dim(W)=m$.  
Let $T:V \rightarrow W$ be a linear transformation.  
Fix a basis  $\beta = \{v_1,\cdots,v_n\}$ of $V$ and $\gamma = \{w_1,\cdots,w_m\}$ of $W$.  
Then matrix representation of $T$ denote $[T]_\beta^\gamma$
$$ [T]_\beta^\gamma \equiv 
\begin{bmatrix}
a_{11} & \cdots & a_{1n} \\
\vdots & \ddots & \vdots \\
a_{m1} & \cdots & a_{mn} \\
 \end{bmatrix}$$
Where each column of $[T]_\beta^\gamma$ is coordinate of $T(\beta)$.
$$T(v_1) = a_{11}w_1 + \cdots + a_{m1}w_m$$
$$\vdots$$
$$T(v_n) = a_{1n}w_1 + \cdots + a_{mn}w_m$$

### Example1  
Given a vector space $V/F$ with $dim(V)=n$.  
Let $\beta=\{v_1,\cdots,v_n\}$ be a basis of $V$ and $\epsilon = \{e_1,\cdots,e_n\}$ of $F^n$ where $e_i$ refer to standard basis.  
Define a linear trasnformation $T$ 
$$T:V \rightarrow F^n \quad s.t. \quad coordinate(V)=coordinate(F^n)$$  
Then
$$T(v_1) = e_1, \cdots , T(v_n) = e_n$$
$$\Rightarrow[T]_\beta^\epsilon=I$$

### Example2  
Define a map $T$
$$ T:M_{22}(F) \rightarrow M_{22}(F) \quad s.t. \quad A \rightarrow A^T $$
Since $T(cA+B)=(cA+B)^T=cA^T+B^T=cT(A)+T(B)$,  
$T$ is an linear map.  
Choose a basis $\epsilon=\{e_{11},e_{12},e_{21},e_{22}\}$.  
Then
$$T(e_{ij}) = e_{ji}$$
$$\Rightarrow [T]_\epsilon^\epsilon=
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 0 & 1 & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 0 & 1 \\
\end{bmatrix}$$

<br>

## $\mathit{Remark \; 5.1}$
Let $V,W$ be vector spaces over $F$ with $dim(V)=n, dim(W)=m$.  
Let $T:V \rightarrow W$ be an linear map.  
Let $\beta,\gamma$ be basis of $V,W$ respectively.
$$
\begin{matrix}
V & \xrightarrow{T} & W \\ \\
\phi_n \big\downarrow \quad &  & \quad \big\downarrow \phi_m \\ \\
F^n & \xrightarrow{f} & F^m \\
\end{matrix}$$
Since $\phi_n$ and $\phi_m$ are vector space isomorphism,  
$f=\phi_m \circ T \circ \phi_n^{-1}$ and it is an linear map from $F^n$ to $F^m$.  
Let $\epsilon_n,\epsilon_m$ be the standard basis of $F^n,F^m$ respectively.  
Then
$$[f]_{\epsilon_n}^{\epsilon_m} = [\phi_m \circ T \circ \phi_n^{-1}]_{\epsilon_n}^{\epsilon_m}=[\phi_m]_{\gamma}^{\epsilon_m}[T]_{\beta}^{\gamma}[\phi_n^{-1}]_{\epsilon_n}^{\beta} = [T]_{\beta}^{\gamma}$$

### Exercise  
Let $V,W,Z$ be finite dimensional vector spaces over $F$.  
Let $T_1:V \rightarrow W$, $T_2:W \rightarrow Z$ be linear maps.  
Then $T_2 \circ T_1 : V \rightarrow Z$ is also an linear map.  
Let $\alpha,\beta,\gamma$ be basis of $V,W,Z$ respectively.  
Then show that 
$$[T_2 \circ T_1]^{\gamma}_{\alpha}=[T_2]^{\gamma}_{\beta}[T_1]^{\beta}_{\alpha}$$

<br>

## $\mathit{Proposition \; 5.1}$
Let $V,W$ be vector spaces over $F$ with $dim(V)=n, dim(W)=m$.  
Let $\beta,\gamma$ be basis of $V,W$ respectively.   
Let $\mathcal{L}(V,W)$ be vector space of all linear maps from $V$ into $W$.    
Define a map $\Phi$
$$\Phi:\mathcal{L}(V,W) \rightarrow M_{mn}(F) \quad s.t. \quad T \rightarrow [T]^{\gamma}_{\beta} $$
Then $\Phi$ is 1-1, onto(*i.e.* bijective).  
*i.e.* there is an 1-1 correspondence between linear trasnformation and matrices.  
그러므로, linear trasnformation을 생각하는데 있어 matrix로 충분하다.  
즉 선형 사상을 이해하는것은 행렬을 이해하는것과 같다.

$\mathit{proof}$  
< $\Phi$ is 1-1 >  
Let $T_1,T_2 \in \mathcal{L}(V,W)$.  
Suppose that $T_1 \neq T_2$.  
Write $\beta = \{ v_1, \cdots, v_n \}$ and $\gamma = \{ w_1, \cdots, w_m \}$.  
Then
$$ \begin{matrix}
T_1(v_1) = a_{11}w_1 + \cdots + a_{m1}w_m &T_2(v_1) = b_{11}w_1 + \cdots + b_{m1}w_m \\
\vdots & \vdots  \\
T_1(v_n) = a_{1n}w_1 + \cdots + a_{mn}w_m & T_2(v_n) = b_{1n}w_1 + \cdots + b_{mn}w_m\\
\end{matrix}$$
Since $T_1 \neq T_2$, 
$$\exist (i,j) \quad s.t \quad a_{ij} \neq b_{ij}.$$  
$$\therefore \Phi(T_1) \neq \Phi(T_2) \quad _\blacksquare$$

< $\Phi$ is onto >  
Take any $m \in M_{mn}(F)$.  
Define a map $T$
$$T:V \rightarrow W \quad s.t. \quad  coordinate(T(v_i))=m_{i,*} \quad \forall i$$  
Then $T \in \mathcal{L}(V,W) \quad _\blacksquare$  

