import numpy as np
import sympy as sp

K1 = np.matrix(([1,-1,0,0],
                [-1,1,0,0],
                [0,0,0,0],
                [0,0,0,0]))
K2 = np.matrix(([0,0,0,0],
                [0,1,-1,0],
                [0,-1,1,0],
                [0,0,0,0]))
K3 = K2
K4 = np.matrix(([0,0,0,0],
                [0,1,0,-1],
                [0,0,0,0],
                [0,-1,0,1]))
K5 = np.matrix(([0,0,0,0],
                [0,0,0,0],
                [0,0,1,-1],
                [0,0,-1,1]))

K = K1 + K2 + K3 + K4 + K5;

print(K)
print(np.linalg.det(K))

x = sp.symbols("x")

Q = sp.Matrix([[sp.cos(x), sp.sin(x), 0, 0],
              [-sp.sin(x), sp.cos(x), 0, 0],
              [0,0,sp.cos(x), sp.sin(x)],
              [0,0,-sp.sin(x), sp.cos(x)]])
QT = sp.transpose(Q)

K = np.matrix([[1,0,-1,0],
               [0,0,0,0],
               [-1,0,1,0],
               [0,0,0,0]])

print(QT * K * Q)

# b = np.matrix(([6],[2],[1]))

# A_1 = A[:,0]
# b = b - A_1

# # remove 0 column
# column = 1
# A = np.delete(A,0,column)

# # # remove 0 row
# # row = 0
# # A0 = np.delete(A,0,row)
# # b0 = np.delete(b,0,row)

# # x0 = np.linalg.inv(A0)*b0
# # x0.insert(0, 1)
# # print(x0)

# # remove 1 row
# row = 0
# A1 = np.delete(A,1,row)
# b1 = np.delete(b,1,row)

# x1 = np.linalg.inv(A1)*b1
# x1 = np.vstack([[1], x1])
# print(x1)

# # remove 2 row
# row = 0
# A2 = np.delete(A,2,row)
# b2 = np.delete(b,2,row)

# x2 = np.linalg.inv(A2)*b2
# x2 = np.vstack([[1], x2])
# print(x2)


# A_inv = np.linalg.inv(A)
# x = A_inv*b

# print(A)
# print(A[:,0])




# print(x)
# print(b)

# r =sp.symbols("r")
# s =sp.symbols("s")

# VCF = make_T1_VCF(X)

# import matplotlib.pyplot as plt
# import mslib.msplot as msplt

# num_point = 21
# delta = 2/(num_point-1)

# fig = plt.figure()
# ax1 = fig.add_subplot(1,1,1, projection = '3d')


# for i in range(0,num_point):
#     s_value = -1 + delta*i
#     for j in range(0, num_point -i):
#         r_value = -1 + delta*j

#         x = VCF[0].subs([(r,r_value),(s,s_value)])
#         y = VCF[1].subs([(r,r_value),(s,s_value)])
#         z = VCF[2].subs([(r,r_value),(s,s_value)])

#         msplt.plot_point(ax1,x,y,z)

# plt.show()      
