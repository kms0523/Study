# from Jupyterbook.TOC_Writer import TOC_Writer


# writer = TOC_Writer()

# source_folder_path = "Jupyterbook/test/"
# writer.write(source_folder_path)

import numpy as np
import sympy as sp

m = np.matrix(([-1,0,0],[2,-1,0],[-1,2,-1],[0,-1,1]))
q = np.matrix(([-1],[-2],[-2],[-1]))



x = sp.symbols("x")
u_ext = x**2 - 2*x

sol_ext = np.zeros((3,1))
sol_ext[0,0] = u_ext.subs(x,1/3)
sol_ext[1,0] = u_ext.subs(x,2/3)
sol_ext[2,0] = u_ext.subs(x,1)

print("exact sol:")
print(sol_ext)

# print(m)

for i in range(0,4):
	print("rmove " + str(i+1) + " equation")
	m_removed = np.delete(m,i,0)

	if np.linalg.det(m_removed) == 0:
		print("cause singular matrix")
		continue

	q_removed = np.delete(q,i,0)

	sol = np.linalg.inv(m_removed)*q_removed
	sol = sol / 9
	print("sol:")
	print(sol)

