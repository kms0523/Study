import sympy
import numpy

from numpy import array
from numpy import mat as mat
from numpy import zeros as zeros
from numpy.linalg import det as det
from math import sqrt as sqrt

num_interpolation_term = 6
a = sympy.symarray("a",num_interpolation_term)
b = sympy.symarray("b",num_interpolation_term)

r,s = sympy.symbols("r, s")
monomials = array([1,r,s,r**2,r*s,s**2])

ert = a.dot(monomials)
est = b.dot(monomials)
eqt = sqrt(0.5)*(est-ert)

# print(a)
# print(monomials)
# print(ert)

num_equation = 12
eq_array = sympy.symarray("temp", num_equation)
eq_array[0] = ert.subs([(r,0), (s,0)])
eq_array[1] = ert.subs([(r,1/2), (s,0)])
eq_array[2] = ert.subs([(r,1), (s,0)])
eq_array[3] = ert.subs([(r,1/3), (s,1/3)])
eq_array[4] = est.subs([(r,0), (s,0)])
eq_array[5] = est.subs([(r,0), (s,1/2)])
eq_array[6] = est.subs([(r,0), (s,1)])
eq_array[7] = est.subs([(r,1/3), (s,1/3)])
eq_array[8] = eqt.subs([(r,1), (s,0)])
eq_array[9] = eqt.subs([(r,1/2), (s,1/2)])
eq_array[10] = eqt.subs([(r,0), (s,1)])
eq_array[11] = eqt.subs([(r,1/3), (s,1/3)])

# print(eq_array[0])
# print(eq_array[1])
# print(eq_array[2])
# print(eq_array[3])

# print((eq_array[4]))
# print((eq_array[5]))
# print((eq_array[6]))
# print((eq_array[7]))

# print(sympy.factor(eq_array[8]))
# print(sympy.factor(eq_array[9]))
# print(sympy.factor(eq_array[10]))
# print(sympy.factor(eq_array[11]))

num_variable = a.size + b.size

x = sympy.symarray("temp", num_variable)
for i in range(0, a.size):
    x[i] = a[i]
for i in range(0, b.size):
    x[i + a.size] = b[i]

A = mat(numpy.zeros((num_equation,num_variable)))
for i in range (0,num_equation) :     
    eq = eq_array[i]   
    for j in range (0, num_variable) :
        target_variable = x[j]
        A[i, j] = eq.coeff(target_variable)

print(det(A))

# mrt, lrt, ecr, mst, lst, ecs, mqt, lqt, ecq = sympy.symbols("mrt, lrt, ecr, mst, lst, ecs, mqt, lqt, ecq")
# b = array([mrt-lrt, mrt, mrt + lrt, ecr, mst-lst, mst, mst + lst, ecs, mqt-lqt, mqt, mqt + lqt, ecq])
# b = mat(b).T

# A_inv = A.I
# x = A_inv * b
# print(x)