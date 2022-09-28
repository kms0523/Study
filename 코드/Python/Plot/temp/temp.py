import numpy as np
from math import isclose as isclose

# For Graph
import matplotlib.pyplot as plt

def Von_Mises_yield_function(x,y):    
    return (x-y)**2 + y**2 + x**2 - 2

x_temp = np.arange(-2, 2, 0.01)
y_temp = np.arange(-2, 2, 0.01)

xlist = []
ylist = []

for x in x_temp:
    for y in y_temp:
        if (abs(Von_Mises_yield_function(x,y)) <= 1.0e-3):
            xlist.append(x)
            ylist.append(y)



fig = plt.figure(figsize=(10,3))
ax = fig.add_subplot(1, 2, 1)
ax.scatter(xlist, ylist, s = 1, color = 'black' ,alpha=1.0)

# ax.set_xlabel(r'$\sigma_1$')
# ax.set_ylabel(r'$\sigma_2$')
# ax.set_zlabel(r'$\sigma_3$')
# ax.text2D(0.05, 0.95, "Maximum Shear Front View", transform = ax.transAxes)

# ax.xaxis.set_tick_params(colors = 'white')
# ax.yaxis.set_tick_params(colors = 'white')
# ax.zaxis.set_tick_params(colors = 'white')

# ax.view_init(azim = 45, elev= 28)


# ax2 = fig.add_subplot(1, 2, 2, projection = "3d")
# ax2.scatter3D(xlist, ylist, zlist, s = 1, color = 'black' ,alpha=0.1)
# ax2.set_xlabel(r'$\sigma_1$')
# ax2.set_ylabel(r'$\sigma_2$')
# ax2.set_zlabel(r'$\sigma_3$')
# ax2.text2D(1.85, 0.95, "Maximum Shear Side View", transform = ax.transAxes)

# ax2.xaxis.set_tick_params(colors = 'white')
# ax2.yaxis.set_tick_params(colors = 'white')
# ax2.zaxis.set_tick_params(colors = 'white')

# ax2.view_init(azim = 34, elev= 20)

plt.show()