import sympy

from numpy import array as array
from numpy import mat as mat
from numpy import zeros as zeros
from numpy.linalg import det as det

from math import sqrt as sqrt

num_term = 3

a = sympy.symarray("a",num_term)
b = sympy.symarray("b",num_term)

r,s = sympy.symbols("r, s")
monomials = array([1,r,s])

ert = a.dot(monomials)
est = b.dot(monomials)
eqt = sqrt(0.5)*(est-ert)

num_equation = 6
eq_array = sympy.symarray("temp", num_equation)

eq_array[0] = ert.subs([(r,0), (s,0)])
eq_array[1] = ert.subs([(r,1), (s,0)])
eq_array[2] = est.subs([(r,0), (s,0)])
eq_array[3] = est.subs([(r,0), (s,1)])
eq_array[4] = eqt.subs([(r,1), (s,0)])
eq_array[5] = eqt.subs([(r,0), (s,1)])

num_variable = a.size + b.size
A = mat(zeros((num_equation,num_variable)))

for i in range (0,num_equation) :        
    for j in range (0, a.size) :
        target_variable = a[j]
        A[i, j] = eq_array[i].coeff(target_variable)
    for j in range (0, b.size) :
        target_variable = b[j]
        A[i, j + a.size] = eq_array[i].coeff(target_variable)

mrt, mst, mqt = sympy.symbols("mrt, mst, mqt")
b = array([mrt, mrt, mst, mst, mqt, mqt])
b = mat(b).T

x = A.I * b
print(x)





# er1,es2,er3,es3 = sympy.symbols("er1 es2 er3 es3")

# c = sqrt(0.5)

# A = mat(
#     [[1, 0, 0, 0, 0, 0],
#      [1, 1, 0, 0, 0, 0],
#      [0, 0, 0, 1, 0, 0],
#      [0, 0, 0, 1, 0, 1],     
#      [-c, -c, 0, c, c, 0],
#      [-c, 0, -c, c, 0, c]
#     ])

# A_inv = inv(A)

# b = mat([[er1],[er1],[es2],[es2],[c*(es3-er3)],[c*(es3-er3)]])

# print(A_inv * b)