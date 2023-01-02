import sympy
from sympy import diff as diff
from sympy import integrate as integ
from sympy import exp as exp
from sympy.plotting import plot

import numpy as np
from numpy import mat as mat
from numpy import zeros as zeros
from numpy.linalg import inv as inv


x = sympy.symbols("x")
exact_solution = 1 + 3*x - 0.5*x**2

plt = plot(exact_solution, (x, 0, 2), legend=True,label='$u_{ex}$', show = False)



def B_WF(w,u):
    dwdx = diff(w,x)
    dudx = diff(u,x)

    return integ(dwdx*dudx, (x, 0, 2))

def l_WF(w):
    u2 = 1
    w2 = w

    if not sympy.simplify(w).is_constant():
        w2 = w.subs(x,2)        

    return w2*u2 + integ(w, (x, 0, 2))

def remove_n_th_eq(B,l,n):
    row = 0
    B_removed = np.delete(B,n,row)
    l_removed = np.delete(l,n,row)

    return [B_removed,l_removed]

def make_restriction_form_matrix(u,w):
    B_RF = mat(zeros((n,n)))
    for i in range(0,n):
        for j in range(0,n):
            B_RF[i,j] = B_WF(w[i], u[j])

    l_RF = mat(zeros((n,1)))
    for i in range(0,n):
        l_RF[i,0] = l_WF(w[i])

    return [B_RF, l_RF]

def make_solution(a,u):
    sol = a[0,0] * u[0]
    for i in range(1,n):
        sol += a[i,0]*u[i]

    return sol

def RF_predefined_dof():
    u = sympy.symarray("u", n)
    for i in range(0,n):
        u[i] = pow(x,i)
    
    w = sympy.symarray("w", n)
    for i in range(0,n):
        w[i] = u[i]

    B,l = make_restriction_form_matrix(u,w)

    a0 = 1
    B_BC = B[:,1:]
    l_BC = l - a0*B[:,:1]

    for i in range(0,n):
        [B,l] = remove_n_th_eq(B_BC,l_BC,i)

        if np.linalg.det(B) == 0:
            print("remove " + str(i+1) + "equation cause singular matrix")
            continue

        a = inv(B) * l
        a = np.vstack([a0 , a])        
        sol = make_solution(a,u)
        plt_sol = plot(sol, (x,0,2), show = False, label='sol' + str(i+1))
        plt.extend(plt_sol)

def RF_additional_eq():
    u = sympy.symarray("u", n)
    u[0] = x-1
    u[1] = x+1
    u[2] = x**2-1
    # u[3] = x**2+x+1

    w = sympy.symarray("w", n)
    for i in range(0,n):
        w[i] = u[i]

    B,l = make_restriction_form_matrix(u,w)

    new_row = mat(zeros((1,n)))
    for i in range(0,n):
        if not sympy.simplify(u[i]).is_constant():
            new_row[0,i] = u[i].subs(x,0)
        else:
            new_row[0,i] = u[i]

    B_BC = np.vstack([new_row, B])
    l_BC = np.vstack([[1],l])

    for i in range(0,n):
        [B,l] = remove_n_th_eq(B_BC,l_BC,i+1)

        if np.linalg.det(B) == 0:
            print("remove " + str(i+1) + "equation cause singular matrix")
            continue

        a = inv(B) * l
        sol = make_solution(a,u)
        plt_sol = plot(sol, (x,0,2), show = False, label='sol' + str(i+1))
        plt.extend(plt_sol)


n = 3
# Restriction Form
# RF_predefined_dof()
# RF_additional_eq()

# Affine Form

plt.show()
