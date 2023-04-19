import numpy as np
import sympy as sp

m1 = np.matrix([[1.193737075048E-09,	1.193717604220E-09,	1.662576118399E-08,	1.662583385235E-08],
              [8.596337794000E-06,	8.596174198079E-06,	3.208141934154E-05,	3.208158293746E-05]])

m2 = np.matrix([[0.2500000000000,	1.8660254037844,	-0.500000000000,   	0.1339745962156,	-0.5000000000000],
              [0.2500000000000,	-0.500000000000,	1.8660254037844,   -0.5000000000000,	0.1339745962156],
              [0.2500000000000,	-0.500000000000,	0.1339745962156,   -0.5000000000000,	1.8660254037844],
              [0.2500000000000,	0.1339745962156,	-0.500000000000,   	1.8660254037844,	-0.5000000000000]])
print(m1)
print(m2)
print(m1*m2)

# print(m1[1,:])
# print(m2[:,1])

# x = sp.symbols("x")
# y = sp.symbols("y")

# c1 = 3.2e-05
# c2 = 8.6e-06
# c3 = np.sqrt(3)

# f1 = 1-x
# f2 = 1+x
# f3 = 1-y
# f4 = 1+y

# s1 = 0.25*f1*f3
# s2 = 0.25*f2*f3
# s3 = 0.25*f2*f4
# s4 = 0.25*f1*f4

# xs = [0, -c3, c3, c3, -c3]
# ys = [0, -c3, -c3, c3, c3]


# m = np.zeros((4,5))
# for i in range(0,5):
#     m[0,i] = s1.subs([(x,xs[i]),(y,ys[i])])
#     m[1,i] = s2.subs([(x,xs[i]),(y,ys[i])])
#     m[2,i] = s3.subs([(x,xs[i]),(y,ys[i])])
#     m[3,i] = s4.subs([(x,xs[i]),(y,ys[i])])

# print(m)

# m[[2,3],:] = m[[3,2],:]

# print(m)

# m2 = np.array([c2,c2,c1,c1])
# result = np.matmul(m2,m)
# print(result)

# q = c1*(s1+s2) + c2*(s3+s4)

# print(q.subs([(x,0),(y,0)]))
# print(q.subs([(x,-c3),(y,-c3)]))
# print(q.subs([(x,c3),(y,-c3)]))
# print(q.subs([(x,c3),(y,c3)]))
# print(q.subs([(x,-c3),(y,c3)]))



# A = sp.Matrix([[sp.cos(x), sp.sin(x), 0],
#                [-sp.sin(x), sp.cos(x), 0],
#                [0,0,1]])
# B = sp.Matrix([[0,0,1],
#                [sp.cos(y), sp.sin(y), 0],
#                [-sp.sin(y), sp.cos(y), 0]])

# sp.pprint(A*B)

# A = np.matrix([[1,1,1],
#                [1,2,1],
#                [3,4,3]])

# print(np.linalg.det(A))

# b = np.matrix([[5],[7],[17]])

# row = 0
# column = 1
# A = np.delete(A,0,column)

# A0 = A
# A0 = np.delete(A0,0,row)
# b0 = np.delete(b,0,row)
# x0 = np.linalg.inv(A0)*b0
# print(x0)

# A1 = A
# A1 = np.delete(A1,1,row)
# b1 = np.delete(b,1,row)
# x1 = np.linalg.inv(A1)*b1
# print(x1)

# A2 = A
# A2 = np.delete(A2,2,row)
# b2 = np.delete(b,2,row)
# x2 = np.linalg.inv(A2)*b2
# print(x2)





# K1 = np.matrix(([1,-1,0,0],
#                 [-1,1,0,0],
#                 [0,0,0,0],
#                 [0,0,0,0]))
# K2 = np.matrix(([0,0,0,0],
#                 [0,1,-1,0],
#                 [0,-1,1,0],
#                 [0,0,0,0]))
# K3 = K2
# K4 = np.matrix(([0,0,0,0],
#                 [0,1,0,-1],
#                 [0,0,0,0],
#                 [0,-1,0,1]))
# K5 = np.matrix(([0,0,0,0],
#                 [0,0,0,0],
#                 [0,0,1,-1],
#                 [0,0,-1,1]))

# K = K1 + K2 + K3 + K4 + K5;

# print(K)
# print(np.linalg.det(K))

# x = sp.symbols("x")

# Q = sp.Matrix([[sp.cos(x), sp.sin(x), 0, 0],
#               [-sp.sin(x), sp.cos(x), 0, 0],
#               [0,0,sp.cos(x), sp.sin(x)],
#               [0,0,-sp.sin(x), sp.cos(x)]])
# QT = sp.transpose(Q)

# K = np.matrix([[1,0,-1,0],
#                [0,0,0,0],
#                [-1,0,1,0],
#                [0,0,0,0]])

# print(QT * K * Q)

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
