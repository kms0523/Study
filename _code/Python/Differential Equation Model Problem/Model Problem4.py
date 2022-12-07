import sympy
from sympy import diff as diff
from sympy import integrate as integ
from sympy import exp as exp
from sympy.plotting import plot

from numpy import mat as mat
from numpy import zeros as zeros
from numpy.linalg import inv as inv


x = sympy.symbols("x")
exact_solution = 1 + 3*x - 0.5*x**2

plt1 = plot(exact_solution, (x, 0, 2), legend=True,label='$u_{ex}$', show = False)

def B_WRF(w,u):    
    d2udx2 = diff(u, x, 2)
    return integ(w*(d2udx2), (x, 0, 2))

def l_WRF(w):
    return -integ(w, (x,0,2))

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


# Weighted Residual Formulation(Galerkin Method)
phi_WRF = x + 1
n_WRF = 1
u_WRF = sympy.symarray("u_WRF", n_WRF)
u_WRF[0] = x*(x-4)

w_WRF = sympy.symarray("w_WRF", n_WRF)
for i in range(0,n_WRF):
    w_WRF[i] = u_WRF[i]

Bm_WRF = mat(zeros((n_WRF,n_WRF)))
for i in range(0,n_WRF):
    for j in range(0,n_WRF):
        Bm_WRF[i,j] = B_WRF(w_WRF[i], u_WRF[j])

lm_WRF = mat(zeros((n_WRF,1)))
for i in range(0,n_WRF):
    lm_WRF[i,0] = l_WRF(w_WRF[i]) - B_WRF(w_WRF[i], phi_WRF)

a_WRF = inv(Bm_WRF) * lm_WRF

solution_WRF = phi_WRF
for i in range(0,n_WRF):
    solution_WRF += a_WRF[i,0]*u_WRF[i]

# Weak Formulation (Galerkin Method)
n_WF = 1
phi_WF = 1

u_WF = sympy.symarray("u_RF", n_WF)
u_WF[0] = x
# u_WF[1] = x**2

w_RF = sympy.symarray("w_RF", n_WF)
for i in range(0,n_WF):
    w_RF[i] = u_WF[i]

Bm_WF = mat(zeros((n_WF,n_WF)))
for i in range(0,n_WF):
    for j in range(0,n_WF):
        Bm_WF[i,j] = B_WF(w_RF[i], u_WF[j])

lm_WF = mat(zeros((n_WF,1)))
for i in range(0,n_WF):
    lm_WF[i,0] = l_WF(w_RF[i]) - B_WF(w_RF[i], phi_WF)

a_WF = inv(Bm_WF) * lm_WF

solution_WF = phi_WF
for i in range(0,n_WF):
    solution_WF += a_WF[i,0]*u_WF[i]


print(solution_WRF)
print(solution_WF)

plt2 = plot(solution_WRF, (x,0,2), legend=True, label='$u_{WRF}$',show = False)
plt3 = plot(solution_WF, (x,0,2), legend=True, label='$u_{WF}$',show = False)

plt1.extend(plt2)
plt1.extend(plt3)
plt1.show()