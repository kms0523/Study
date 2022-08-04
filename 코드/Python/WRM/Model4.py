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

u_exact = 2 * exp(x**2)

# WRM_Galerkin method
n=2

phi = 2
mu1 = x
mu2 = x**2

dmu1 = diff(mu1, x)
dmu2 = diff(mu2, x)

B = mat(zeros((n,n)))
B[0,0] = integ(mu1 * (dmu1 - 2  * x * mu1), (x, 0, 1))
B[0,1] = integ(mu1 * (dmu2 - 2  * x * mu2), (x, 0, 1))
B[1,0] = integ(mu2 * (dmu1 - 2  * x * mu1), (x, 0, 1))
B[1,1] = integ(mu2 * (dmu2 - 2  * x * mu2), (x, 0, 1))

l = mat(zeros((n,1)))
l[0,0] = -integ(mu1 * (- 2  * x * phi), (x, 0, 1))
l[1,0] = -integ(mu2 * (- 2  * x * phi), (x, 0, 1))

a = inv(B)*l
u_Galerkin = phi + a[0,0] * mu1 + a[1,0] * mu2

# Weak Galerkin method1
phi = 2
wmu1 = x
wmu2 = x**2

dwmu1 = diff(wmu1, x)
dwmu2 = diff(wmu2, x)

Bw = mat(zeros((n,n)))

Ebdry_00 = wmu1 * wmu1
Ebdry_01 = wmu1 * wmu2
Ebdry_10 = wmu2 * wmu1
Ebdry_11 = wmu2 * wmu2

Bw[0,0] = Ebdry_00.subs(x,2) - integ((dwmu1 - 2* x *wmu1) * wmu1, (x, 0, 1) )
Bw[0,1] = Ebdry_01.subs(x,2) - integ((dwmu1 - 2* x *wmu1) * wmu2, (x, 0, 1) )
Bw[1,0] = Ebdry_10.subs(x,2) - integ((dwmu2 - 2* x *wmu2) * wmu1, (x, 0, 1) )
Bw[1,1] = Ebdry_11.subs(x,2) - integ((dwmu2 - 2* x *wmu2) * wmu2, (x, 0, 1) )

lw = mat(zeros((n,1)))

Ebdry_0 = wmu1 * phi
Ebdry_1 = wmu2 * phi

lw[0,0] = -(Ebdry_0.subs(x,2) - integ((dwmu1 - 2 * x * wmu1) * phi, (x, 0, 1)))
lw[1,0] = -(Ebdry_1.subs(x,2) - integ((dwmu2 - 2 * x * wmu2) * phi, (x, 0, 1)))

a = inv(Bw) * lw
u_weak_Galerkin = phi + a[0,0] * wmu1 + a[1,0] * wmu2


# Graph plot
p1 = plot(u_exact, (x, 0, 1), show = False)
p1.legend = True
p1[0].label = "exact"
p1[0].line_color = "black"

p2 = plot(u_Galerkin, (x, 0, 1),show = False)
p2[0].label = "Galerkin"
p2[0].line_color = "Red"

p3 = plot(u_weak_Galerkin, (x, 0, 1),show = False)
p3[0].label = "weak Galerkin"
p3[0].line_color = "Blue"

p1.extend(p2)
p1.extend(p3)
p1.show()


# 참고
# https://docs.sympy.org/latest/modules/plotting.html
