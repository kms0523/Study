# Geometric compatibility
Adjacent elements have to fit each other to preserve correct geometry by the mapping from $(ξ,η)$ to $(x,y)$.  
It leads the coordinates of each side must be uniquely determined by the nodal coordinates on that side.  

<center>
<img src=./image/geometric_compatibility.png width = "600" height = 250>
</center>

For example, If along a side 12 $(\eta = -1)$ the coordinates $x$ and $y$ defined parametrically in terms of as linear
$$ x = c_1 +c_2\xi,$$
$$ y = c_3 +c_4\xi,$$
$x$ and $y$ coordinates pass through node1 and node2 are uniquely defined and it leads good mapping.  
On the other hand, if the coordinates defined as quadratic
$$ x = c_1 +c_2\xi + c_3\xi^2,$$
$$ y = c_4 +c_5\xi + c_6\xi^2$$
coordinates can not be uniquely defined and it may cause bad mapping.

# Geometry Mapping
Let
$$ x = Cm $$
$$ x : \tilde{\Omega} \rightarrow \Omega, \quad
   C \in \R^{d_p \times N_m}, \quad
   m : \tilde{\Omega} \rightarrow \R^{N_m} $$
$$ x:= \text{mapping function}, \quad
   C:= \text{mapping coefficient matrix}, \quad
   m:= \text {mapping monomial vector fuction} $$
$$ \Omega := \text{physical geometry}, \quad
   \tilde{\Omega} := \text{reference geometry}, \quad 
   N_m := \text {number of monomial} $$

To determine $x$, we need to determine $C$ and $m$.

## Line Geometry
Since $\tilde{\Omega}$ : $r \in [-1,1]$, suppose that $m = \begin{bmatrix} 1 \\ r \\ \vdots \\ r^{N_m-1} \end{bmatrix}$.  
If we know $N_m$ mapping relation($N_m$ pairs of mapping node and mapped node), we determine $C$ as follow :
$$ X=CM $$
$$ \Rightarrow C = XM^{-1}. $$
$$ X \equiv \begin{bmatrix} x_1 & \cdots & x_{N_m} \end{bmatrix}, \quad
   M \equiv \begin{bmatrix} m_1 & \cdots & m_{N_m} \end{bmatrix}, $$
$$ X \in \R^{d_{\Omega} \times N_m}, \quad M \in \R^{N_m \times N_m}. $$
$$ X:= \text{mapped node matrix}, \quad C:= \text{mapping coefficient matrix}, \quad M:= \text{mapping monomial matrix} $$

## Triangle Geometry
$\tilde{\Omega}$ consists of 3 face ($r=-1, s=-1, r=-s$ line gemoetries).  
To satisfy geometric compatability, each face should be equivalent line geometry for given mapped points.  

Therefore, $m$ should be
$$ m = \begin{matrix} 1 \\ r & s \end{matrix} \quad,\quad
       \begin{matrix}  1   \\ r & s \\ r^2 & rs & s^2 \end{matrix} \quad \cdots$$
$$ (\text{on each face, it becomes }[1,\xi],[1,\xi,\xi^2], \cdots \text{ form}) $$

mapping nodes should be  

<center>
<img src=./image/triangle_mapping_nodes.png width = "500" height = 220>
</center>

## Quadrilateral Geometry
$\tilde{\Omega}$ consists of 4 face ($r=\pm1, s=\pm1$ line gemoetries).  
To satisfy geometric compatability, each face should be equivalent line geometry for given mapped points.  

Therefore, $m$ should be
$$ m = \begin{matrix} 1 & r \\ s & rs \end{matrix} \quad,\quad
       \begin{matrix} 1 & r & r^2   \\ s & rs & r^2s \\ s^2 & rs^2 & r^2s^2 \end{matrix} \quad \cdots$$
$$ (\text{on each face, it becomes }[1,\xi],[1,\xi,\xi^2], \cdots \text{ form}) $$

mapping nodes should be  

<center>
<img src=./image/quadrilateral_mapping_nodes.png width = "500" height = 220>
</center>

## Hexahedral Geometry
$\tilde{\Omega}$ consists of 6 face ($r=\pm1, s=\pm1, t=\pm1$ quadrilateral gemoetries).  
To satisfy geometric compatability, each face should be equivalent quadrilateral geometry for given mapped points.  

Therefore, $m$ should be
$$ m = \begin{bmatrix} 1 & r & s & t & rs & rt & ts & rst \end{bmatrix}, \cdots$$
$$ (\text{on each face, it becomes }[1,\xi,\eta, \xi\eta], \cdots \text{ form}) $$