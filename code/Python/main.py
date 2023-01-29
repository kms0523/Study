# from Jupyterbook.TOC_Writer import TOC_Writer


# writer = TOC_Writer()

# source_folder_path = "Jupyterbook/test/"
# writer.write(source_folder_path)

import numpy as np
import sympy as sp

def make_T1_VCF(X):
    VCP = np.matrix(([-1,1,-1,0,0,-1],
                     [-1,-1,1,-1,0,0]))

    r =sp.symbols("r")
    s =sp.symbols("s")
    basis = [1, r, s, r**2, r*s, s**2]

    M= np.ones((6,6))
    for i in range(1,6):
        for j in range(0,6):
            r_value = VCP[0,j]
            s_value = VCP[1,j]
            M[i,j] = basis[i].subs([(r,r_value),(s,s_value)])

    C = X * np.linalg.inv(M)


    VCF = sp.symarray('VCF',3)

    for i in range(0,3):
        VCF[i] = 0
        for j in range(0,6):
            VCF[i] += C[i,j]*basis[j]

    return VCF

X = np.matrix(( [1,3,1,2,2,1],
                [1,1,3,1,2,2],
                [2,3,2,1,4,0]))

r =sp.symbols("r")
s =sp.symbols("s")

VCF = make_T1_VCF(X)

import matplotlib.pyplot as plt
import mslib.msplot as msplt

num_point = 21
delta = 2/(num_point-1)

fig = plt.figure()
ax1 = fig.add_subplot(1,1,1, projection = '3d')


for i in range(0,num_point):
    s_value = -1 + delta*i
    for j in range(0, num_point -i):
        r_value = -1 + delta*j

        x = VCF[0].subs([(r,r_value),(s,s_value)])
        y = VCF[1].subs([(r,r_value),(s,s_value)])
        z = VCF[2].subs([(r,r_value),(s,s_value)])

        msplt.plot_point(ax1,x,y,z)

plt.show()      
