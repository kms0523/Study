import sympy
from sympy import diff as diff
from sympy import integrate as integ
from sympy import exp as exp
from sympy.plotting import plot

import numpy as np
from numpy import mat as mat
from numpy import zeros as zeros
from numpy.linalg import inv as inv


x = sympy.symbols("x")
exact_solution = 1 + 3*x - 0.5*x**2

plt1 = plot(exact_solution, (x, 0, 2), legend=True,label='$u_{ex}$', show = False)

def B_WF(w,u):
    dwdx = diff(w,x)
    dudx = diff(u,x)

    return integ(dwdx*dudx, (x, 0, 2))

def l_WF(w):
    u2 = 1
    w2 = w

    if not sympy.simplify(w).is_constant():
        w2 = w.subs(x,2)        

    return w2*u2 + integ(w, (x, 0, 2))

n = 2
u = sympy.symarray("u", n)
u[0] = x-1
u[1] = x**2+x+1
u[2] = x**2
# for i in range(0,n):
#     u[i] = pow(x,i)

w = sympy.symarray("w", n)
for i in range(0,n):
    w[i] = u[i]

# Weak Formulation (Galerkin Method)
Bm_WF = mat(zeros((n,n)))
for i in range(0,n):
    for j in range(0,n):
        Bm_WF[i,j] = B_WF(w[i], u[j])

lm_WF = mat(zeros((n,1)))
for i in range(0,n):
    lm_WF[i,0] = l_WF(w[i])

# consider BC
new_row = mat(zeros((1,n)))
for i in range(0,n):
	new_row[0,i] = u[i].subs(x,0)

B_BC = np.vstack([new_row, Bm_WF])
l_BC = np.vstack([[1],lm_WF])

# remove 1eq
row = 0
B1 = np.delete(B_BC,1,row)
l1 = np.delete(l_BC,1,row)
a1 = inv(B1) * l1

print(a1)

sol1 = 0
for i in range(0,n):
    sol1 += a1[i,0]*u[i]

plt_sol1 = plot(sol1, (x,0,2), show = False, label = "sol1")

# remove 2eq
row = 0
B2 = np.delete(B_BC,2,row)
l2 = np.delete(l_BC,2,row)
a2 = inv(B2)*l2

print(a2)

sol2 = 0
for i in range(0,n):
    sol2 += a2[i,0]*u[i]

plt_sol2 = plot(sol2, (x,0,2), show = False, label='sol2')

# remove 3eq
B3 = np.delete(B_BC,3,row)
l3 = np.delete(l_BC,3,row)
a3 = inv(B3)*l3

print(a3)

sol3 = 0
for i in range(0,n):
    sol3 += a3[i,0]*u[i]

plt_sol3 = plot(sol3, (x,0,2), show = False, label='sol3')

plt1.extend(plt_sol1)
plt1.extend(plt_sol2)
plt1.extend(plt_sol3)
plt1.show()

# a_WF = inv(Bm_WF) * lm_WF

# solution_WF = phi_WF
# for i in range(0,n_WF):
#     solution_WF += a_WF[i,0]*u_WF[i]


# print(solution_WRF)
# print(solution_WF)

# plt2 = plot(solution_WRF, (x,0,2), legend=True, label='$u_{WRF}$',show = False)
# plt3 = plot(solution_WF, (x,0,2), legend=True, label='$u_{WF}$',show = False)

# plt1.extend(plt2)
# plt1.extend(plt3)
# plt1.show()