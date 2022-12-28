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
exact_solution = 3 / sympy.sin(2) * sympy.sin(x) + x

plt1 = plot(exact_solution, (x, 0, 2), legend=True,label='$u_{ex}$', show = False)

def B_WF(w,u):
    dwdx = diff(w,x)
    dudx = diff(u,x)

    return integ(w*u - dwdx*dudx, (x, 0, 2))

def l_WF(w):
    return integ(w*x, (x, 0, 2))

n = 3
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

lm_WF = mat(zeros((n,1)))
for i in range(0,n):
    lm_WF[i,0] = l_WF(w[i])

# consider BC
a0 = 0
B_BC = Bm_WF[:,1:]
l_BC = lm_WF - a0*Bm_WF[:,:1]

# remove 1eq
row = 0
B1 = np.delete(B_BC,0,row)
l1 = np.delete(l_BC,0,row)
a1 = inv(B1) * l1

sol1 = a0 * u[0]
for i in range(1,n):
    sol1 += a1[i-1,0]*u[i]

plt_sol1 = plot(sol1, (x,0,2), show = False, label = "sol1")


plt1.extend(plt_sol1)
# plt1.extend(plt_sol2)
# plt1.extend(plt_sol3)
plt1.show()

# phi_WF = 5*x/2
# n_WF = 1
# u_WF = sympy.symarray("u_RF", n_WF)
# u_WF[0] = x*(x-2)
# # u_WF[1] = x**2

# w_RF = sympy.symarray("w_RF", n_WF)
# for i in range(0,n_WF):
#     w_RF[i] = u_WF[i]

# Bm_WF = mat(zeros((n_WF,n_WF)))
# for i in range(0,n_WF):
#     for j in range(0,n_WF):
#         Bm_WF[i,j] = B_WF(w_RF[i], u_WF[j])

# lm_WF = mat(zeros((n_WF,1)))
# for i in range(0,n_WF):
#     lm_WF[i,0] = l_WF(w_RF[i]) - B_WF(w_RF[i], phi_WF)

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