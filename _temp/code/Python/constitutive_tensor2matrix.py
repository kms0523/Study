from numpy import mat as mat
from numpy import zeros as zeros

import sympy as sym

lamb = sym.symbols("lambda")
m = sym.symbols('mu')

def I_sym(i,j,k,l):
    result = 0
    
    if i==k and j==l:
        result += 1
    if i==l and j==k:
        result += 1
    
    return result * 0.5

def II(i,j,k,l):
    if i==j and k == l:
        return 1
    else:
        return 0

def I_dev(i,j,k,l):
    return I_sym(i,j,k,l) - II(i,j,k,l)/3

def C(i,j,k,l):
    return lamb*II(i,j,k,l) + 2*m*I_sym(i,j,k,l)


def tensor2matrix(tensor):
    n = 6
    M = sym.symarray('a',(n,n))

    M[0,0] = tensor(1,1,1,1)
    M[0,1] = M[1,0] = tensor(1,1,2,2)
    M[0,2] = M[2,0] = tensor(1,1,3,3)
    M[0,3] = M[3,0] = tensor(1,1,2,3)
    M[0,4] = M[4,0] = tensor(1,1,1,3)
    M[0,5] = M[5,0] = tensor(1,1,1,2)

    M[1,1] = tensor(2,2,2,2)
    M[1,2] = M[2,1] = tensor(2,2,3,3)
    M[1,3] = M[3,1] = tensor(2,2,2,3)
    M[1,4] = M[4,1] = tensor(2,2,1,3)
    M[1,5] = M[5,1] = tensor(2,2,1,2)

    M[2,2] = tensor(3,3,3,3)
    M[2,3] = M[3,2] = tensor(3,3,2,3)
    M[2,4] = M[4,2] = tensor(3,3,1,3)
    M[2,5] = M[5,2] = tensor(3,3,1,2)

    M[3,3] = tensor(2,3,2,3)
    M[3,4] = M[4,3] = tensor(2,3,1,3)
    M[3,5] = M[5,3] = tensor(2,3,1,2)

    M[4,4] = tensor(1,3,1,3)
    M[4,5] = M[5,4] = tensor(1,3,1,2)

    M[5,5] = tensor(1,2,1,2)

    return M

matrix1 = tensor2matrix(C)
print(matrix1)


# matrix1 = tensor2matrix(I_sym)
# print(matrix1)

# matrix2 = tensor2matrix(II)
# print(matrix2)

# matrix3 = tensor2matrix(I_dev)
# print(matrix3)