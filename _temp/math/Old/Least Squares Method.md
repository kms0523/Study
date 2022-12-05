# Preliminary
## Calculus with vectors and matrices
Let $f: \mathbb{F}^n \rightarrow \mathbb{F}$ and $x, y \in \mathbb{F}^n, A\in M_{nn}(\mathbb{F})$
$$ x \cdot y = x^Ty = y^Tx $$
$$ x^T A = A^Tx $$
$$ \frac{\partial f}{\partial x}  \equiv grad(f) = \frac{\partial f}{\partial {x_i}} $$
$$ \frac{\partial }{\partial x}(x \cdot y) = y  $$
$$ \frac{\partial}{\partial x}(x^TAx) = (A+A^T)x $$

# Least Squares Method
Consider 
$${Ax=b}$$
$${A} \in M_{mn}(\mathbb{R}), \quad {x} \in F^n(\mathbb{R}), \quad {b} \in F^m(\mathbb{R}), \quad m \ge n $$  
We want to find 
$${x} \quad s.t. \quad \text{minimize} ~~ {||Ax-b||} $$

## Derivation
Since
$$ ||Ax-b|| = \sqrt{ \lang Ax-b,Ax-b \rang } = \sqrt{ (Ax-b)^T (Ax-b)} $$
The problem is changed to minimize $(Ax-b)^T(Ax-b)$.
$$ \begin{aligned}
e = \quad & (Ax-b)^T(Ax-b)\\\\
  = \quad & (x^TA^T-b^T)(Ax-b)\\\\
  = \quad & x^TA^TAx -x^TA^Tb -b^TAx -b^Tb\\\\
  = \quad & x^TA^TAx -2x^TA^Tb -b^Tb 
\end{aligned} $$

$e$ is minimized when ${de}/{dx}=0$
$$ \frac{de}{dx}  = 2A^TAx -2A^Tb $$
$$ \therefore x = (A^TA)^{-1}A^Tb $$
