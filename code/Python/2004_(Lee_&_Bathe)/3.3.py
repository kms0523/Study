from numpy import mat as mat
from numpy.linalg import det as det

a = mat([[1,0,0], [1, 0.5, 0], [1,1,0]])
print(det(a))

b = mat([[1,0,0], [1, 0, 0.5], [1,0,1]])
print(det(b))
