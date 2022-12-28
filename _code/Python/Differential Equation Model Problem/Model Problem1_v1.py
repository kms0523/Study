import sympy
from sympy import diff as diff
from sympy import integrate as integ
from sympy import exp as exp
from sympy.plotting import plot

import numpy as np
from numpy import mat as mat
from numpy import zeros as zeros
from numpy.linalg import inv as inv

from math import pi as pi


x = sympy.symbols("x")
exact_solution = 2 * exp(x**2)

plt1 = plot(exact_solution, (x, 0, 2), show = False, legend=True, label='exact')

def B_WF(w,u):
    dwdx = diff(w, x)

    wu = w*u
    
    wu2 = wu

    if not sympy.simplify(wu).is_constant():
        wu2 = wu.subs(x,2)

    return wu2 - integ(u*(dwdx + 2*x*w), (x, 0, 2))

n = 7
u = sympy.symarray("u", n)
for i in range(0,n):
    u[i] = pow(x,i)

w = sympy.symarray("w", n)
for i in range(0,n):
    w[i] = u[i]


# Weak Formulation (Galerkin Method)
Bm_WF = mat(zeros((n,n)))
for i in range(0,n):
    for j in range(0,n):
        Bm_WF[i,j] = B_WF(w[i], u[j])

# consider BC
a0 = 2

B_BC = Bm_WF[:,1:]
l_BC = -a0*Bm_WF[:,:1]

# remove 1eq
row = 0
B1 = np.delete(B_BC,0,row)
l1 = np.delete(l_BC,0,row)
a1 = inv(B1) * l1

sol1 = a0 * u[0]
for i in range(1,n):
    sol1 += a1[i-1,0]*u[i]

plt_sol1 = plot(sol1, (x,0,2), show = False, label = "sol1")

# remove 2eq
row = 0
B2 = np.delete(B_BC,1,row)
l2 = np.delete(l_BC,1,row)
a2 = inv(B2)*l2

sol2 = a0 * u[0]
for i in range(1,n):
    sol2 += a2[i-1,0]*u[i]

plt_sol2 = plot(sol2, (x,0,2), show = False, label='sol2')

# remove 3eq
B3 = np.delete(B_BC,2,row)
l3 = np.delete(l_BC,2,row)
a3 = inv(B3)*l3

sol3 = a0 * u[0]
for i in range(1,n):
    sol3 += a3[i-1,0]*u[i]

plt_sol3 = plot(sol3, (x,0,2), show = False, label='sol3')

plt1.extend(plt_sol1)
plt1.extend(plt_sol2)
plt1.extend(plt_sol3)
plt1.show()