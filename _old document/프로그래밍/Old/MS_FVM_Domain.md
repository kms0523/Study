conservation law :
$$ \frac{\partial q(x,t)}{\partial t} + \nabla \cdot F(q(x,t)) = 0 $$
$$ q \in \mathbb{R}^{N_e}, \quad F \in \mathbb{R}^{N_e \times 2}, \quad  x \in \mathbb{R}^2 $$
$$ F := \text{physical flux}, \quad N_e := \text{number of equations} $$

The physical domain $\Gamma$ is well approximated by $N_p$ non-overlapping polygonal $\Omega_i$ :
$$\Gamma \approx \Omega =\bigcup_{i=1}^{N_p} \Omega_𝑖$$
$$ N_p := \text{number of polygonals} $$

Approximate $q$ as average value on each $\Omega_i$ :  
$$ q(x,t) \approx \bar{q}_i(t), \quad x\in \Omega_i $$
$$ \bar{q}_i(t) \equiv \frac{1}{|\Omega_i|} \int_{\Omega_i}q(x,t)\;d\Omega_i$$

At the beginning, simply take center $(x_{ic})$ initial value $(q_I)$ of $\Omega_i$:
$$ \bar{q}_i(0) \approx q_I(x_{ic})$$

FVM semi-discrete equation of each $\Omega_i$ :
$$ \frac{d}{dt}\bar{q_i}=RHS_i $$
$$ RHS_i \equiv -\frac{1}{|\Omega_i|}\sum_{j=1}^{N_f} |\omega_j|\hat{f}(\bar{q}^+_j,\bar{q}^-_j,n_j) $$
$$ \hat{f} : \R^{N_e} \times \R^{N_e} \times \R^d \rightarrow \R^{N_e} $$
$$ \omega := \text{face of } \Omega_i, \quad \hat{f} := \text{numerical flux function} $$
$$ \bar{q}^+ := \text{owner cell solution}, \quad \bar{q}^- := \text{neighbor cell solution},  \quad n := \text{normal vector}$$

For all $\Omega$ :
$$ \frac{d}{dt}\begin{bmatrix} \bar{q}_1 & \cdots & \bar{q}_{N_p} \end{bmatrix} =
\begin{bmatrix} RHS_1 & \cdots & RHS_{N_p} \end{bmatrix} $$
$$ \frac{d}{dt} \bar{q} = RHS $$

Calculate $RHS$ as follow :  
1. calculate $|\omega_j|\hat{f}(\bar{q}^+_j,\bar{q}^-_j,n_j)$ at a face
2. Since $n$ is determined by owner cell based, neighbor cell has minus sign (orginally have $-$, it becomes $+$)
$$ RHS_{I_o} = RHS_{I_o} - |\omega_j|\hat{f}(\bar{q}^+_j,\bar{q}^-_j,n_j) $$
$$ RHS_{I_n} = RHS_{I_n} + |\omega_j|\hat{f}(\bar{q}^+_j,\bar{q}^-_j,n_j) $$
$$ I_o := \text{owner cell index}, \quad I_N := \text{neighbor cell index} $$
3. repeat 1-2 for all faces
4. divide $RHS_i$ by $|\Omega_i|$


Explicit multi stage time integration, TVDRK3 :
$$\begin{aligned}
\bar{q}^{(1)} =& \quad \bar{q} + \Delta t RHS(\bar{q}) \\\\
\bar{q}^{(2)} =& \quad \frac{1}{4}\left[3\bar{q} + \bar{q}^{(1)} + \Delta tRHS(\bar{q}^{(1)})\right] \\\\
\bar{q}^{new} =& \quad \frac{1}{3}\left[\bar{q} + 2\bar{q}^{(2)} + 2\Delta tRHS(\bar{q}^{(2)})\right]
\end{aligned}$$

# Error
If we know exact solution$({q}_{ex})$, we can define local error function of each cell $e_i(x,t)$:
$$ e_i := {q}_{ex} - {q} $$

Then we can define $l_p$ norm of $e_i$:
$$ || e_i ||_p \equiv \left( \frac{ 1 }{|\Omega_i|} \int_{\Omega_i} |{q}_{ex} - {q}|^p \; d\Omega_i \right) ^{1/p}$$
$$ || e_i ||_p \equiv \left( \frac{1}{|\Omega_i|} \left| \int_{\Omega_i} ( {q}_{ex} - {q} )^p \; d\Omega_i \right| \right) ^{1/p} $$

as $p$ approaches $\infty$ the $p-$norm approaches the infinity norm or maximum norm: 
$$||e||_\infty \equiv \max |e_i| $$ 

Then we can can calculate global error $||E||_p$ as follow:
$$ ||E||_p \equiv \frac{1}{N_c} \sum_{i=1}^{N_c} ||e_i||_p $$


# $\Delta t$
Choose $\Delta t$ as minimum local time step$(\Delta t_i)$
$$ \Delta t = \min \Delta t_i$$

$\Delta t_i$ caclulated from spectral radii of $x,y$ $(r_x,r_y)$
$$ \Delta t_i \equiv CFL \times \frac{|\Omega_i|}{r_x + r_y}$$

$$r_x,r_y \equiv |\Omega_{ix}|\lambda_{mx}, |\Omega_{iy}|\lambda_{my} $$
$$|\Omega_{ix}|,|\Omega_{iy}| := \text{ projected volume to } x,y \text{ coordinate} $$
$$\lambda_{mx}, \lambda_{my} :=  \text{ coordinate projected } \lambda_m $$
$$\lambda_m := \text{maximum characteristic speed} $$

$\lambda_{mx}, \lambda_{my}$ depend on Governing Eq :
$$\begin{aligned} 
\lambda_{mx}, \lambda_{my} = \qquad & |a_1|, |a_2| && \mathrm{linear \; advection}  \\\\
&|q|, |q| && \mathrm{Burgers} \\\\
&(|u_1|+ a), (|u_2| + a) && \mathrm{Euler} \\
\end{aligned}$$

# Inner Face Flux
$F_I$ is LLF method :  
$$F_I \equiv \frac{1}{2}\left\{(F\left(\bar{q}^+)+F(\bar{q}^-)\right)n+\lambda_{If}(\bar{q}^+ - \bar{q}^-)\right\}$$
$$\lambda_{If} \equiv \max(\lambda_f(\bar{q}^+),\lambda_f(\bar{q}^-)), \quad \lambda_f \equiv \max \{ \mathrm{|\lambda| \; of \; }J_{F\cdot n(\bar{q})} \} $$
$$\lambda_{If} := \lambda_f \text{ at inner face}, \quad \lambda_{f} := \lambda_m \text{ at face} $$

Governing eq에 따라 $F$와 $\lambda_m$이 정해진다.

$$\begin{aligned} 
F = \qquad &\begin{bmatrix} a_1q & a_2q \end{bmatrix} && \mathrm{linear \; advection}  \\\\
&\begin{bmatrix} \frac{1}{2} q^2 & \frac{1}{2} q^2 \end{bmatrix} && \mathrm{Burgers} \\\\
&\begin{bmatrix} 
\rho u_1 & \rho u_2 \\ \\
\rho u_1^2 +p & \rho u_1u_2 \\ \\
\rho u_1u_2 & \rho u_2^2 + p \\ \\
(\rho E + p)u_1 & (\rho E + p)u_2 \\
\end{bmatrix} && \mathrm{Euler}  \\\\    
\lambda_f = \qquad &|a \cdot n| && \mathrm{linear \; advection}  \\\\
&|q (n_1+n_2)| && \mathrm{Burgers} \\\\
&|u \cdot n| + a && \mathrm{Euler} \\
\end{aligned}$$

# Boundary Flux
$F_B$ can be $F_B$ for supersonic outlet BC$(F_{Bso})$ or slip wall BC$(F_{Bsw})$ :
$$F_{Bso}\equiv F(\bar{q}^+)n $$
$$F_{Bsw}\equiv \begin{bmatrix}
0 \\
p(\bar{q}^+) n_{x} \\
p(\bar{q}^+) n_{y} \\
0 \\
\end{bmatrix}$$
choice of $F_B$ is depend on Governing eq

# Gradient
we want to solve :
$$ R_c\nabla q_{,i} = \Delta q_{,i} $$
$$ R_c \equiv \begin{bmatrix}  (x_1 - x_0)^T \\ \cdots \\ (x_{N_{NC}} - x_o)^T \end{bmatrix}, \quad
\Delta q_{,i} \equiv \begin{bmatrix} q_{1,i} - q_{0,i} \\ \vdots \\ q_{N_{NC},i} - q_{0,i} \end{bmatrix} $$
$$ R_c \in \R^{N_{NC} \times N_d}, \quad \Delta q_{,i} \in \R^{N_{NC}} $$
$$ R_c := \text {center to center matrix}, \quad N_{NC} := \text{number of near cell} $$

Since it is over determined system, we can not find solution that satisfy all equations.  
Thus we use least squares method which make sum of square of errors become minimum.
$$ \nabla q_{,i} = R_c^+ \Delta q_{,i} $$
$$ R_c^+ \equiv (R_c^T R_c)^{-1} R_c^T \in \mathbb{R}^{N_d \times N_{NC}} $$

For all equations
$$ [\nabla q_{,1}, \cdots, \nabla q_{,N_e}] = R_c^+ [\Delta q_{,1}, \cdots, \Delta q_{,N_e}]$$

Transpose it
$$ \nabla q = \Delta q  (R_c^+)^T $$
$$ \nabla q \in \R^{N_e \times N_d}, \quad \Delta q \in \R^{N_e \times N_{NC}}, \quad (R_c^+)^T = R_c(R_c^T R_c)^{-1} \in \R^{N_{NC} \times N_d}$$
$$ \Delta q := \text{ solution delta matrix} $$
$$ (R_c^+)^T := \text{ least square matrix} $$


# Limiter
Solution form :
$$ q = \bar{q} + \phi\nabla q(r-r_c) $$
$$ \phi := \text{limiting function}$$

Limiting function value and gradient calculate from neighbor solutions

# MLP-u1
To satisfy MLP condition at every vertex:
$$ q_m \le q_v \le q_M $$

calculate allowable min max solution at each vertex
$$ q_{m,j} \equiv \min \{ q_{i,j} | i \in \{ \text{vertex share cell indexes} \} \} $$
$$ q_{M,j} \equiv \max \{ q_{i,j} | i \in \{ \text{vertex share cell indexes} \} \} $$
$$ j=1,\cdots,N_e $$

calculate vertex solution delta matrix$(\Delta q_v \in \mathbb{R}^{N_d \times N_V})$
$$\begin{aligned}
\Delta q_v \equiv \nabla q R_v = & 
\begin{bmatrix}
\nabla q_{,1} \cdot (r_{v1}) & \cdots & \nabla q_{,1} \cdot r_{vN_V} \\ \\
\vdots & \cdots & \vdots\\ \\
\nabla q_{,N_e} \cdot r_{v1} & \cdots & \nabla q_{,N_e} \cdot r_{vN_V} \\
\end{bmatrix} \\ \\ 
= & 
\begin{bmatrix} 
q_{v1} - q_0 & \cdots & q_{vN_V} - q_0 
\end{bmatrix} 
\end{aligned}$$
$$ r_{vi} = x_{vi} - x_c $$

choose minimum limiting value at all vertexes
$$ \phi_{\text{MLP-u1}} = \min \{\phi_v | v \in \{ v_\Omega \} \}$$
$$ \phi_v = \min \left(1, \begin{cases}
(q_m - q) / \nabla q \cdot r_v & \text{if} & \nabla q \cdot r_v \le 0 \\ \\
(q_M - q) / \nabla q \cdot r_v & \text{if} & \nabla q \cdot r_v \ge 0 
\end{cases} \right)$$
Let $q_m \le q_v \le q_M$ and $\nabla q \cdot r_v \ge 0$
$$ q_v \le q_M $$
$$\Rightarrow 1 \le q_M - q / \nabla q \cdot r_v \quad (\because \nabla q \cdot r_v = q_v - q )$$
$$\therefore \phi_v = 1$$

# Equation Of State
Assume calorically ideal gas where $\gamma$ is a constant.
$$ e = \frac{p}{\rho(\gamma -1)} $$
$$ a = \sqrt{\frac{\gamma p}{\rho}} $$