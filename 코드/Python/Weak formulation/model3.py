import sympy
import numpy

from sympy import diff as diff
from sympy import integrate as integ
from sympy import plot as plot

from numpy import mat as mat
from numpy import zeros as zeros
from numpy.linalg import inv as inv

def B(w,u):
    dw = diff(w, x)
    du = diff(u, x)

    return integ(dw*du + 2*w*du - u*w, (x, 0, 1))

def l(w):
    w0 = w
    w1 = w
    du0 = sympy.symbols("du0")

    if not sympy.simplify(w).is_constant():
        w1 = w.subs(x,1)
        w0 = w.subs(x,0)    
    
    return 2 * w1 + w0 * du0 - integ(w, (x, 0, 1))


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

# a = inv(Bw)@lw
# print(a)

# u_h = 0

# for i in range(0,n):
#     u_h += a[0,i]*mu[i]

# # Graph plot
# u_exact = 1 + x*sympy.exp(x-1)

# p1 = plot(u_exact, (x, 0, 1), show = False)
# p1.legend = True
# p1[0].label = "u_exact"
# p1[0].line_color = "black"

# p2 = plot(1 + 1.2*x, (x, 0, 1),show = False)
# p2[0].label = "u_h"
# p2[0].line_color = "Red"

# p3 = plot(1 + 24/5*x, (x, 0, 1),show = False)
# p3[0].label = "u_h2"
# p3[0].line_color = "Blue"

# p1.extend(p2)
# p1.extend(p3)
# p1.show()    
