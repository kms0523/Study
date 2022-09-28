import numpy as np
from math import isclose as isclose

# For Graph
import matplotlib.pyplot as plt

def Von_Mises_yield_function(x,y,z):    
    return np.power((x-y),2) + np.power((y-z),2) + np.power((z-x),2) - 2
    # return round((x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x) - 2, 1)

def Max_Shear_Stress_yield_function(x,y,z):
    return max(x,y,z) - min(x,y,z) - 3

# x_temp = np.linspace(-2, 2, 100)
x_temp = np.arange(-2, 2, 0.005)
y_temp = np.arange(-2, 2, 0.005)
z_temp = np.arange(-2, 2, 0.4)

xlist = []
ylist = []
zlist = []

for x in x_temp:
    for y in y_temp:
        for z in z_temp:  
            # if (abs(Von_Mises_yield_function(x,y,z)) <= 1.0e-1):
            #     if (abs(Von_Mises_yield_function(x,y,z)) >= 1.0e-2):
            #         print("coordinates")
            #         print(x,y,z)
            #         print("vonMises")
            #         print(Von_Mises_yield_function(x,y,z))
            if (abs(Von_Mises_yield_function(x,y,z)) <= 1.0e-3):
                xlist.append(x)
                ylist.append(y)
                zlist.append(z)

fig = plt.figure(figsize=(10,3))
ax = fig.add_subplot(1, 2, 1, projection = "3d")
ax.scatter3D(xlist, ylist, zlist, s = 1, color = 'black' ,alpha=0.1)

ax.set_xlabel(r'$\sigma_1$')
ax.set_ylabel(r'$\sigma_2$')
ax.set_zlabel(r'$\sigma_3$')
ax.text2D(0.05, 0.95, "Maximum Shear Front View", transform = ax.transAxes)

ax.xaxis.set_tick_params(colors = 'white')
ax.yaxis.set_tick_params(colors = 'white')
ax.zaxis.set_tick_params(colors = 'white')

ax.view_init(azim = 45, elev= 28)


ax2 = fig.add_subplot(1, 2, 2, projection = "3d")
ax2.scatter3D(xlist, ylist, zlist, s = 1, color = 'black' ,alpha=0.1)
ax2.set_xlabel(r'$\sigma_1$')
ax2.set_ylabel(r'$\sigma_2$')
ax2.set_zlabel(r'$\sigma_3$')
ax2.text2D(1.85, 0.95, "Maximum Shear Side View", transform = ax.transAxes)

ax2.xaxis.set_tick_params(colors = 'white')
ax2.yaxis.set_tick_params(colors = 'white')
ax2.zaxis.set_tick_params(colors = 'white')

ax2.view_init(azim = 34, elev= 20)

plt.show()


# 참고
# scatter3D:        https://pythonguides.com/matplotlib-3d-scatter/
# add subplot:      https://jehyunlee.github.io/2021/07/10/Python-DS-80-mpl3d2/

# remove axis tip:          https://stackoverflow.com/questions/29041326/3d-plot-with-matplotlib-hide-axes-but-keep-axis-labels
# axis tip label size:      https://stackoverflow.com/questions/37711538/matplotlib-3d-axes-ticks-labels-and-latex
# axis tip label color:     https://stackoverflow.com/questions/53549960/setting-tick-colors-of-matplotlib-3d-plot

# view init:        https://stackoverflow.com/questions/12904912/how-to-set-camera-position-for-3d-plots-using-python-matplotlib
# save fig:         https://stackoverflow.com/questions/27567001/3d-plot-with-matplotlib
# text & set label: https://matplotlib.org/2.0.2/examples/mplot3d/text3d_demo.html