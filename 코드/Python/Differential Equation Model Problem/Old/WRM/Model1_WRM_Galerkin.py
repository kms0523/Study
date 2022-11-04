import sympy

from sympy import diff as diff
from sympy import integrate as integ
from sympy import exp as exp
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

# du = diff(u_exact , x)
# ddu = diff(u_exact, x, 2)
# f = exp(x) * (du + ddu) - sin(x)
# print(sympy.simplify(f))

# WRM_Galerkin method

n=2

phi = 1
mu1 = x**2 - pi * x
mu2 = x**3 - 3 * pi**2 / 4 * x

dmu1 = diff(mu1, x)
ddmu1 = diff(mu1, x, 2)
dmu2 = diff(mu2, x)
ddmu2 = diff(mu2, x, 2)

B = mat(zeros((n,n)))
B[0,0] = integ(mu1 * ex * (dmu1 + ddmu1), (x, 0, pi/2))
B[0,1] = integ(mu1 * ex * (dmu2 + ddmu2), (x, 0, pi/2))
B[1,0] = integ(mu2 * ex * (dmu1 + ddmu1), (x, 0, pi/2))
B[1,1] = integ(mu2 * ex * (dmu2 + ddmu2), (x, 0, pi/2))

l = mat(zeros((n,1)))
l[0,0] = integ(mu1 * sin(x), (x, 0, pi/2))
l[1,0] = integ(mu2 * sin(x), (x, 0, pi/2))

a = inv(B)*l
u_Galerkin = phi + a[0,0] * mu1 + a[1,0] * mu2

# Weak Galerkin method1
phi = 1
wmu1 = x
wmu2 = x**2

dwmu1 = diff(wmu1, x)
dwmu2 = diff(wmu2, x)

Bw = mat(zeros((n,n)))

Ebdry_00 = -exp(x) * wmu1 * dwmu1
Ebdry_01 = -exp(x) * wmu1 * dwmu2
Ebdry_10 = -exp(x) * wmu2 * dwmu1
Ebdry_11 = -exp(x) * wmu2 * dwmu2

Bw[0,0] = Ebdry_00.subs(x,0) - integ(exp(x) * dwmu1 * dwmu1, (x, 0, pi/2) )
Bw[0,1] = Ebdry_01.subs(x,0) - integ(exp(x) * dwmu1 * dwmu2, (x, 0, pi/2) )
Bw[1,0] = Ebdry_10.subs(x,0) - integ(exp(x) * dwmu2 * dwmu1, (x, 0, pi/2) )
Bw[1,1] = Ebdry_11.subs(x,0) - integ(exp(x) * dwmu2 * dwmu2, (x, 0, pi/2) )

lw = mat(zeros((n,1)))
lw[0,0] = integ(wmu1 * sin(x), (x, 0, pi/2))
lw[1,0] = integ(wmu2 * sin(x), (x, 0, pi/2))

a = inv(Bw) * lw
u_weak_Galerkin = phi + a[0,0] * wmu1 + a[1,0] * wmu2


# Graph plot
p1 = plot(u_exact, (x, 0, pi/2), show = False)
p1.legend = True
p1[0].label = "exact"
p1[0].line_color = "black"

p2 = plot(u_Galerkin, (x, 0, pi/2),show = False)
p2[0].label = "Galerkin"
p2[0].line_color = "Red"

p3 = plot(u_weak_Galerkin, (x, 0, pi/2),show = False)
p3[0].label = "weak Galerkin"
p3[0].line_color = "Blue"

p1.extend(p2)
p1.extend(p3)
p1.show()


# 참고
# https://docs.sympy.org/latest/modules/plotting.html
