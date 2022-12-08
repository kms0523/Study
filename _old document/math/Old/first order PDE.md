# First-Order Equations: Method of Characteristics
We start by looking at the case when $u(x,y)$.

</br>

## Linear Equation
Consider the following first-order, linear equation,
$$a(x,y)u_x +b(x,y)u_y = c(x,y)$$

Assume parametric solution surface 
$$ s(x,y) := \langle x,y,u \rangle $$

If $u$ is solution, we know that at each point
$$\langle a,b,c \rangle \cdot \langle u_x,u_y,-1 \rangle = 0$$

Note that $\langle u_x,u_y,-1 \rangle$ is normal vector of $s$.  
It means that the vector $\langle a,b,c \rangle$ lies in the tangent plane to $s$ at each point.  
Consequently, to find a solution, we will look for a $s$.   
We start by looking for a curve $c$ which lies in $s$.  
Here, $c$ is a special curve that $\langle a,b,c \rangle$ is tangent to the $c$ at each point. 
$$c(r):=\langle x(r),y(r),z(r) \rangle \quad s.t. \quad c'(r) = \langle a,b,c \rangle$$

we call $c$ as **integral curves** or **characteristic curves** for the vector field $\langle a,b,c \rangle$.    
It leads following system of ODEs
$$ \frac{dx}{dr}=a(x(r),y(r)) $$
$$ \frac{dy}{dr}=b(x(r),y(r)) $$
$$ \frac{dz}{dr}=c(x(r),y(r)) $$

we call it as the **set of characteristic equations**.  
Once we have found the characteristic curves, forming a surface $s$ as a union of these characteristic curves.  
We call $s$ as an **integral surface** for vector filed $\langle a,b,c \rangle$.  

### *Remark*
In effect, by introducing these characteristic equations, we have reduced our partial differential equation to a system of ordinary differential equations. We can use ODE theory to solve the characteristic equations, then piece together these characteristic curves to form a surface. Such a surface will provide us with a solution to our PDE.

### *Example*
We consider the transport equation,
$$ u_t + au_x = 0 $$

we need to find characterstic curve $c(r)$.  
Thus we solve characteristic equations
$$ \frac{dx}{dr}(r)=a $$
$$ \frac{dt}{dr}(r)=1 $$
$$ \frac{dz}{dr}(r)=0 $$

Solving the system, we have
$$ x(r) = ar + c_1 $$
$$ t(r) = r + c_2 $$
$$ z(r) = c_3 $$


<br><br>

## Initial Value Problem for Linear Equation 
Consider the following first-order linear equation with given initial condition
$$a(x,y)u_x +b(x,y)u_y = c(x,y)$$
$$u(x,0)=\phi(x) $$

As described earlier, constructing an integral surface $s$ as a union of characteristic curves.  
Now, we impose the extra condition that $s$ contains the curve $\langle x, 0, \phi(x) \rangle$.  
Let $\Gamma$ be the curve in $\mathbb{R}^2$ given by $\lang x,0 \rang$ on which we are prescribing our initial value.  
Let $\lang \Gamma,\phi \rang$ be the curve in $\mathbb{R}^3$ given by $\lang x,0,\phi(x) \rang$.  
To construct our solution, start by picking a point $\lang x_0,0,\phi(x_0) \rang$ on $\lang \Gamma,\phi \rang$.  
Now, let's construct a characteristic curve emanating from $\lang x_0,0,\phi(x_0) \rang$.  
It leads following system of ODEs
$$ \frac{dx}{dr}=a(x(r),y(r)) $$
$$ \frac{dy}{dr}=b(x(r),y(r)) $$
$$ \frac{dz}{dr}=c(x(r),y(r)) $$
which satisfies the initial conditions
$$ x(0)=x_0 $$
$$ y(0)=0 $$
$$ z(0)=\phi(x_0) $$
If we construct a characteristic curve from each point on $\lang \Gamma,\phi \rang$, and take the union of
these characteristic curves, we can find an integral surface $s$ for the vector field $\lang a,b,c \rang$
which contains the curve $\lang \Gamma,\phi \rang$.

### Example
We consider the initial-value problem for the transport equation,
$$\begin{cases}
u_t + au_x = 0 \\
u(x,0)=\phi(x). \\
\end{cases} $$

Let $\Gamma \equiv \lang x,0 \rang$ be the curve in $\mathbb{R^2}$ on which we are prescribing our data.  
Let $\lang \Gamma, \phi \rang$ be the curve in $\mathbb{R^3}$ given by $\lang x,0,\phi(x) \rang$.  
Parametrize $\Gamma = \lang x_0,0 \rang$.  
Now for each $x_0$, we need to find characterstic curve $c(r)$.  
Thus we solve characteristic equations
$$ \frac{dx}{dr}(r)=a $$
$$ \frac{dt}{dr}(r)=1 $$
$$ \frac{dz}{dr}(r)=0 $$
with initial conditons
$$ x(0)=x_0 $$
$$ t(0)=0 $$
$$ z(0)=\phi(x_0) $$
Solving the system, we see that
$$ x(r) = ar + c_1 $$
$$ t(r) = r + c_2 $$
$$ z(r) = c_3 $$
Now looking at our initial conditions, we see that
$$ x(r) = ar + x_0 $$
$$ t(r) = r $$
$$ z(r) = \phi(x_0) $$
Eliminating parameter $r$
$$ x-at = x_0 $$
$$ z = \phi(x_0) $$
Since $x_0$ is constant, $z$ is constant along the line $x_0=x-at$.  
The integral surface formed from a union of these characterstic curves emanating from all $x_0$.  
In doing so, we see that $z(x,t)$ is constant along the lines $x_0=x-at$.   
That is, $z(x,t)=f(x-at)=\phi(x-at)$.  
Letting $u(x,t)=z(x,t)=\phi(x-at)$, we have found the general solution.