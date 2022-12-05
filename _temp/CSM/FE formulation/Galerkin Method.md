We consider a conservation law
$$ \frac{\partial q(x,t)}{\partial t} + \nabla \cdot F(q(x,t)) = 0 $$
$$ x \in \mathbb{R}^d $$

It is subject to the well-posed initial condition and boundary condition on the appropriate physical domain.  
The physical domain $\Omega$ is well approximated by $p$ non-overlapping polygonal element $\Omega_i$
$$\Omega \approx \bigcup_{i=1}^p \Omega_𝑖$$

We want to know $q$ but it is too difficult.  
So we approximate $q$ as polynomial on each $\Omega_i$.  
$$ q \approx q_h(x,t) \in \mathbb{P}^n(\Omega_i) $$

Substitute $q_h$ to conservation law, we can get local residual $r_i(x,t)$
$$ \frac{\partial q_h}{\partial t} + \nabla \cdot F(q_h) = r_i $$

If $r_i(x,t)$ go to 0, we can say that our approximate solution is an exact solution.  
But it is hard to find $q_h$ make $r_i=0$.  
To detour the problem, we use Galerkin dimension reduction and polynomial approximate error is intrinsically occurred here.  
Now we try to find $q_h$ make $\mathrm{proj}_{\mathbb{P}^n} r_i = 0$.  
It means that $r_i \perp \mathbb{P}^n(\Omega_i).$  
Let $\phi_1,\cdots,\phi_{N_b}$ be a basis of $\mathbb{P}^n(\Omega_i)$.  
Then

$$ \mathrm{proj}_{\mathbb{P}^n} r_i = 0$$
$$ \Rightarrow \sum_{j=1}^{N_b}\frac{\lang r_i, \phi_j \rang}{\lang \phi_j, \phi_j \rang} \phi_j = 0 $$
$$ \Rightarrow \lang r_i, \phi_j \rang =0 \quad \forall j$$
$$ \Rightarrow \left\lang \frac{\partial q_h}{\partial t} + \nabla \cdot F(q_h), \phi_j \right\rangle = 0  \quad \forall j $$
$$ \Rightarrow \left\lang \frac{\partial q_h}{\partial t} ,\phi_j \right\rang +  \lang\nabla \cdot F(q_h), \phi_j \rang = 0  \quad \forall j $$

By divergence theorem : 
$$\lang \nabla \cdot F(q_h), \phi_j \rang = \int_{\Omega_i} \nabla \cdot F(q_h) \phi_j dV = - \int_{\Omega_i} F(q_h) \nabla \phi_j dV + \int_{\partial\Omega_i} F(q_h) \phi_j n ds $$

we get weak formular :
$$ \int_{\Omega_i} \frac{\partial q_h}{\partial t} \phi_j dV - \int_{\Omega_i} F(q_h) \nabla \phi_j dV + \int_{\partial\Omega_i} F(q_h) \phi_j n ds =0 \quad \forall j$$