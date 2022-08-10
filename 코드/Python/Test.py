import sympy
import numpy


m = numpy.mat(numpy.zeros((3,3)))

m[0,0] = 1
m[0,1] = 0
m[0,2] = 0
m[1,0] = -1
m[1,1] = 3/2
m[1,2] = -1
m[2,0] = 3/2
m[2,1] = -4/3
m[2,2] = 2

inv_m = numpy.linalg.inv(m)

l = numpy.array([1, 1, -1/2])

print(inv_m @ l)





