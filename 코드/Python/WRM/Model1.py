import sympy

from sympy import diff as diff
from sympy import exp as exp
from sympy import integrate as integ
from sympy import sin as sin
from sympy import cos as cos
from sympy import plot as plot

from math import pi as pi

from numpy import mat as mat
from numpy import zeros as zeros
from numpy.linalg import inv as inv

x = sympy.symbols("x")
ex = exp(x)

u_exact = 1/2 * (1 + exp(-x)*(cos(x) - sin(x)))
p1 = plot(u_exact, (x, 0, pi/2), show = False)

# du = diff(u_exact , x)
# ddu = diff(u_exact, x, 2)
# f = exp(x) * (du + ddu) - sin(x)
# print(sympy.simplify(f))


mu1 = x**2 - pi * x
mu2 = x**3 - 3 * pi**2 / 4 * x

dmu1 = diff(mu1, x)
ddmu1 = diff(mu1, x, 2)
dmu2 = diff(mu2, x)
ddmu2 = diff(mu2, x, 2)



n=2

# Galerkin method
B = mat(zeros((n,n)))
B[0,0] = integ(mu1 * ex * (dmu1 + ddmu1), (x, 0, pi/2))
B[0,1] = integ(mu1 * ex * (dmu2 + ddmu2), (x, 0, pi/2))
B[1,0] = integ(mu2 * ex * (dmu1 + ddmu1), (x, 0, pi/2))
B[1,1] = integ(mu2 * ex * (dmu2 + ddmu2), (x, 0, pi/2))

l = mat(zeros((n,1)))
l[0,0] = integ(mu1 * sin(x), (x, 0, pi/2))
l[1,0] = integ(mu2 * sin(x), (x, 0, pi/2))

a = inv(B)*l

phi = 1
uh = phi + a[0,0] * mu1 + a[1,0] * mu2

p2 = plot(uh, (x, 0, pi/2), show = False)
p1.extend(p2)

p1.show()
