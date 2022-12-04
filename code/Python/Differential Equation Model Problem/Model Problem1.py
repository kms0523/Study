import sympy
from sympy import diff as diff
from sympy import integrate as integ
from sympy import exp as exp
from sympy.plotting import plot

from numpy import mat as mat
from numpy import zeros as zeros
from numpy.linalg import inv as inv

from math import pi as pi


x = sympy.symbols("x")
exact_solution = 2 * exp(x**2)

plt1 = plot(exact_solution, (x, 0, 2), show = False)



def B_WRF(w,u):    
    dudx = diff(u, x)
    return integ(w*(dudx - 2*x*u), (x, 0, 2))

def B_WF(w,u):
    dwdx = diff(w, x)

    wu = w*u
    
    wu2 = wu
    wu0 = wu

    if not sympy.simplify(wu).is_constant():
        wu2 = wu.subs(x,2)
        wu0 = wu.subs(x,0)

    return wu2 - wu0 - integ(u*(dwdx + 2*x*w), (x, 0, 2))

phi = 2

n = 1
u = sympy.symarray("u", n)
for i in range(0,n):
    u[i] = pow(x,i+1)

w = sympy.symarray("w", n)
for i in range(0,n):
    w[i] = u[i]


# Weighted Residual Formulation(Galerkin Method)
Bm_WRF = mat(zeros((n,n)))
for i in range(0,n):
    for j in range(0,n):
        Bm_WRF[i,j] = B_WRF(w[i], u[j])

l_WRF = mat(zeros((n,1)))
for i in range(0,n):
    l_WRF[i,0] = -B_WRF(w[i], phi)

a_WRF = inv(Bm_WRF) * l_WRF

solution_WRF = phi
for i in range(0,n):
    solution_WRF += a_WRF[i,0]*u[i]

# Weak Formulation (Galerkin Method)
Bm_WF = mat(zeros((n,n)))
for i in range(0,n):
    for j in range(0,n):
        Bm_WF[i,j] = B_WF(w[i], u[j])

l_WF = mat(zeros((n,1)))
for i in range(0,n):
    l_WF[i,0] = -B_WF(w[i], phi)

a_WF = inv(Bm_WF) * l_WF

solution_WF = phi
for i in range(0,n):
    solution_WF += a_WF[i,0]*u[i]


print(solution_WRF)
print(solution_WF)

plt2 = plot(solution_WRF, (x,0,2), show = False)
plt3 = plot(solution_WF, (x,0,2), show = False)

plt1.extend(plt2)
plt1.extend(plt3)
plt1.show()