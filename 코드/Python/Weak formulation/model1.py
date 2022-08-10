import sympy

from sympy import diff as diff
from sympy import integrate as integ
from sympy import plot as plot

from numpy import mat as mat
from numpy import zeros as zeros
from numpy.linalg import inv as inv

def B(w,u):
    dw = diff(w, x)
    du = diff(u, x)

    return integ(dw*du, (x, 0, 2))

def l(w):
    w2 = 0
    w0 = 0
    du0 = sympy.symbols("du0")

    if not sympy.simplify(w).is_constant():
        w2 = w.subs(x,2)
        w0 = w.subs(x,0)    
    
    return integ(w, (x, 0, 2)) + w2 - w0 * du0


x = sympy.symbols("x")

n = 2

mu = sympy.symarray("mu", n)
mu[0] = 1
mu[1] = x

w = sympy.symarray("w", n)
w[0] = x
w[1] = x-2

Bw = mat(zeros((n,n)))
for i in range(0,n):
    for j in range(0,n):
        Bw[i,j] = B(w[i], mu[j])

lw = sympy.symarray("lw", n)
for i in range(0,n):
    lw[i] = l(w[i])

print(Bw)
print(lw)


# # Graph plot
# u_exact = 1 + 3*x - 0.5 * x **2
# u_h = 1 + lw[1]/Bw[1,1]*x

# p1 = plot(u_exact, (x, 0, 2), show = False)
# p1.legend = True
# p1[0].label = "u_exact"
# p1[0].line_color = "black"

# p2 = plot(u_h, (x, 0, 2),show = False)
# p2[0].label = "u_h"
# p2[0].line_color = "Red"

# p1.extend(p2)
# p1.show()