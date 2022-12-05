conservation law :
$$ \frac{\partial q(x,t)}{\partial t} + \nabla \cdot (F \circ q)(x,t) = 0, $$
$$ q : \R^d \times \R \rightarrow \R^{N_e}, \quad F : \R^{N_e} \rightarrow \R^{N_e \times d}, \quad  x \in \R^d, $$
$$ F := \text{physical flux function}, \quad N_e := \text{number of equation}, \quad d:=\text{space dimension} $$

The physical domain $\Gamma$ is well approximated by $N_p$ non-overlapping polygonal $\Omega_i$ :
$$\Gamma \approx \Omega =\bigcup_{i=1}^{N_p} \Omega_𝑖$$
$$ N_p := \text{number of polygonal} $$

We want to know $q$ that satisfy conservation law but it is too difficult.  
So we approximate $q$ as polynomial degree $n$ on each $\Omega_i$ :
$$ q \approx q^{(i)}_h(x,t) \in \mathbb{P}^n(\Omega_i) $$
$$ q_h^{(i)} = \sum_{j=1}^{N_b} \hat{q}_j^{(i)}(t) \phi^{(i)}_j(x)$$
$$ q_h^{(i)} : \R^d \times \R \rightarrow \R^{N_e}, \quad \hat{q}_j^{(i)} : \R \rightarrow \R^{N_e}, \quad 
\phi_j^{(i)} : \R^d \rightarrow \R $$
$$ \phi^{(i)}_j := \text{basis of } \mathbb{P}^n(\Omega_i) \text{ space}, \quad N_b := \text{number of } \phi_j  $$

From now on, we omit cell index $(i)$ for notational simplicity.  
In vector form
$$ q_h = \hat{q}\phi $$
$$ \hat{q} \equiv \begin{bmatrix} \hat{q}_1 & \cdots & \hat{q}_{N_b} \end{bmatrix}, \quad
\phi = \begin{bmatrix} \phi_1 \\ \vdots \\ \phi_{N_b}  \end{bmatrix}$$
$$ \hat{q} : \R \rightarrow \R^{N_e \times N_b}, \quad \phi : \R^d \rightarrow \R^{N_b}$$


Substitute $q_h$ to conservation law
$$ \frac{\partial q_h}{\partial t} + \nabla \cdot F(q_h) = r_i $$
$$ r_i := \text{local residual} $$

If $r_i=0$, we can say that $q_h$ is an exact solution. But it is hard to find $q_h$ make $r_i=0$.  
To detour the problem, we use Galerkin dimension reduction and polynomial approximation error is intrinsically occurred here.  
Now we try to find $q_h$ make $\text{proj}_{\mathbb{P}^n(\Omega_i)} r_i = 0$. It means $r_i \perp \mathbb{P}^n(\Omega_i)$ :
$$ \mathrm{proj}_{\mathbb{P}^n} r_i = 0$$
$$ \Rightarrow \sum_{j=1}^{N_b}\frac{\lang r_i, \phi_j \rang}{\lang \phi_j, \phi_j \rang} \phi_j = 0 $$
$$ \Rightarrow \lang r_i, \phi_j \rang =0 \quad \forall j$$
$$ \Rightarrow \left\lang \frac{\partial q_h}{\partial t} + \nabla \cdot F(q_h), \phi_j \right\rangle = 0  \quad \forall j $$
$$ \Rightarrow \left\lang \frac{\partial q_h}{\partial t} ,\phi_j \right\rang +  \lang\nabla \cdot F(q_h), \phi_j \rang = 0  \quad \forall j $$

By divergence theorem : 
$$\lang \nabla \cdot F(q_h), \phi_j \rang = \int_{\Omega_i} \nabla \cdot F(q_h) \phi_j dV = - \int_{\Omega_i} F(q_h) \nabla \phi_j dV + \int_{\partial\Omega_i} F(q_h) \phi_j n ds $$

we get set of weak formulars :
$$ \int_{\Omega_i} \frac{\partial q_h}{\partial t} \phi_j dV - \int_{\Omega_i} F(q_h) \nabla \phi_j dV + \int_{\partial\Omega_i} F(q_h) \phi_j n ds =0 \quad \forall j$$

Since we does not have any assumption on surface, there are no reason to have continuous solution at surface.  
Handle the discontinuity at surface, we bring the numerical flux concept in FVM method :
$$ \int_{\Omega_i} \frac{\partial q_h}{\partial t} \phi_j dV - \int_{\Omega_i} F(q_h) \nabla \phi_j dV + \int_{\partial\Omega_i} \hat{f}(q_h^+,q_h^-,n) \phi_j ds =0 \quad \forall j$$
$$ \hat{f} : \R^{N_e} \times \R^{N_e} \times \R^d \times \R \rightarrow \R^{N_e} $$
$$ \hat{f} := \text{numerical flux function} $$

If $\phi$ is orthonormal basis, 
$$ \frac{d\hat{q}_j}{dt}  = rhs_{cell,j}(t) + rhs_{face,j}(t) \quad \forall j $$
$$ rhs_{cell,j}(t) \equiv \int_{\Omega_i} F(q_h) \nabla \phi_j dV, \quad rhs_{face,j}(t) \equiv - \int_{\partial\Omega_i} \hat{f}(q_h^+,q_h^-,n) \phi_j ds $$
$$ rhs_{cell,j}(t) : \R \rightarrow \R ^ {N_e}, \quad rhs_{face,j}(t) : \R \rightarrow \R ^ {N_e},$$

Write these system of equations to matrix form :
$$ \frac{d\hat{q}}{dt} = rhs_{cell}(t) + rhs_{face}(t)$$
$$ \hat{q} \equiv \begin{bmatrix} \hat{q}_1 & \cdots & \hat{q}_{N_b} \end{bmatrix} \in \R^{N_e \times N_b}  $$
$$ rhs_{cell}(t) \equiv \begin{bmatrix} rhs_{cell,1} & \cdots & rhs_{cell,N_b} \end{bmatrix} = \int _{\Omega_i} F (\nabla \phi)^T dV$$
$$ rhs_{face}(t) \equiv \begin{bmatrix} rhs_{face,1} & \cdots & rhs_{face,N_b} \end{bmatrix} = - \int_{\partial\Omega_i} \hat{f} \phi^T ds $$
$$ (\nabla \phi)^T \equiv \begin{bmatrix} \nabla \phi_1 & \cdots \nabla \phi_{N_b} \end{bmatrix} $$
$$ rhs_{cell}(t) : \R \rightarrow \R^{N_e \times N_b}, \quad 
rhs_{face}(t) : \R \rightarrow \R^{N_e \times N_b}, \quad
(\nabla \phi)^T : \R^d \rightarrow \R^{d \times N_b} $$

Use quadrature rule to compute integral numerically :
$$ rhs_{cell}(t) = \sum_{i=1}^{N_q} F(x_i,t) (\nabla \phi(x_i))^T w_i$$
$$ rhs_{face}(t) = - \sum_{i=1}^{N_q} \hat{f}(x_i,t) \phi^T(x_i) w_i $$
$$ N_q := \text{number of quadrature point} $$

In vector form
$$ rhs_{cell}(t) = F_QW_{\nabla\phi} $$
$$ F_Q(t) \equiv \begin{bmatrix} F(x_1,t) & \cdots & F(x_{N_q},t) \end{bmatrix}, \quad 
W_{\nabla\phi} \equiv \begin{bmatrix} (\nabla \phi(x_1))^T w_1 \\ \vdots \\ (\nabla \phi(x_{N_q}))^Tw_{N_q}  \end{bmatrix}$$
$$ rhs_{cell}(t) : \R \rightarrow \R^{N_e \times N_b}, \quad F_Q(t) : \R \rightarrow \R^{N_e \times (d \times N_q)}, \quad W_{\nabla\phi}  \in \R^{(N_q \times d) \times N_b} $$
$$ F_Q := \text{flux quadrature function}, \quad W_{\nabla\phi} := \text{gradient basis weight matrix} $$

$$ rhs_{face}(t) = -\hat{f}_QW_{\phi} $$
$$ \hat{f}_Q(t) \equiv \begin{bmatrix} \hat{f}(q_h^+,q_h^-,n)(x_1,t) & \cdots & \hat{f}(q_h^+,q_h^-,n)(x_{N_q},t) \end{bmatrix} , \quad
W_{\phi} \equiv \begin{bmatrix} \phi^T(x_1) w_1 \\ \vdots \\ \phi^T(x_{N_q})w_{N_q}  \end{bmatrix}$$
$$ rhs_{face}(t) : \R \rightarrow \R^{N_e \times N_b}, \quad \hat{f}_Q(t) : \R \rightarrow \R^{N_e \times N_q}, \quad W_{\phi} \in \R^{N_q \times N_b}  $$
$$ \hat{f}_Q := \text{numerical flux quadrature function}, \quad W_{\phi} := \text{quadrature    weights basis matrix} $$

With cell index $(i)$ :
$$ \frac{d\hat{q}^{(i)}}{dt} = RHS^{(i)}(t)$$
$$ RHS^{(i)}(t) \equiv rhs_{cell}^{(i)}(t) + \sum _{j=1} ^{N_F} rhs_{face}^{(j)}(t) $$ 
$$ RHS^{(i)}(t) : \R \rightarrow \R^{N_e \times N_b} $$
$$ N_F :=\text{number of face in $i$ cell} $$

For all cell :
$$ \frac{d\hat{q}}{dt} = RHS $$
$$ \hat{q} \equiv \begin{bmatrix} \hat{q}^{(1)}  & \cdots & \hat{q}^{(N_p)} \end{bmatrix}, \quad 
RHS \equiv \begin{bmatrix} RHS^{(1)}  & \cdots & RHS^{(N_p)} \end{bmatrix} $$

This is semi-discretized equation of conservation law by discontinuous Galerking(DG) method.

To solve semi-discretized equation we use explicit time integration method SSPRK33 :
$$\begin{aligned}
\hat{q}^{*} =& \quad \hat{q} + \Delta t RHS(\hat{q}) \\\\
\hat{q}^{**} =& \quad \frac{1}{4}\left[3\hat{q} + \hat{q}^{*} + \Delta tRHS(\hat{q}^{*})\right] \\\\
\hat{q}^{new} =& \quad \frac{1}{3}\left[\hat{q} + 2\hat{q}^{**} + 2\Delta tRHS(\hat{q}^{**})\right]
\end{aligned}$$

This is discretized equation of conservation law by discontinuous Galerking(DG) method.



# Calculate $RHS(t_0)$ 
Calculate $RHS(t_0)$ as follow :
1. Pre-calculate $W_{\nabla \phi}$ for all cells
2. calculate $rhs_{cell}(t_0)$ for all cells
3. Pre-calculate owner cell side $W_{\phi}$ ($W_{\phi,oc}$) and neighbor cell side $W_{\phi}$ ($W_{\phi,nc}$) for all faces
4. calculate $\hat{f}_Q(t_0)$ for all faces
5. Since $n$ is determined by owner cell based, neighbor cell has minus sign (orginally have $-$, it becomes $+$)
$$ RHS_{I_o} = RHS_{I_o} - \hat{f}_Q W_{\phi, oc} $$
$$ RHS_{I_n} = RHS_{I_n} + \hat{f}_Q W_{\phi , nc} $$
$$ I_o := \text{owner cell index}, \quad I_N := \text{neighbor cell index} $$   
4. repeat 2-3 for all faces

# Calculate Initial coefficients
$$ f =\sum_{i=1}^{N_b} \hat{q}_i\phi_i $$
$$ \Rightarrow \int _\Omega  f\phi_j d\Omega = \int _\Omega \sum_{i=1}^{N_b} \hat{q}_i\phi_i \phi_j d\Omega \quad \forall j $$
$$ \Rightarrow \int _\Omega  f\phi_j d\Omega = \hat{q}_j \quad \forall j $$
$$ \hat{q} = \begin{bmatrix} \hat{q}_1 & \cdots & \hat{q}_{N_b} \end{bmatrix} 
= \begin{bmatrix} \int _\Omega  f\phi_1 d\Omega & \cdots & \int _\Omega  f\phi_{N_b} d\Omega \end{bmatrix} $$

