import matplotlib.pyplot as plt
import numpy as np

from Plot_API import plot_implicit_function
from Plot_API import plot_sphere

def Von_Mises_yield_function(x,y,z):    
    return (x-y)**2 + (y-z)**2 + (z-x)**2 - 8

def deviatoric_stress_plane(x,y,z):
    return x + y + z

fig = plt.figure(figsize=(8,6))
ax = fig.add_subplot(1,1,1, projection = '3d')
plot_sphere(ax, 3, 'blue', 0.2)

# resolution = 30
# num_layers = 100

# xmin, xmax = -5, 5
# ymin, ymax = -5, 5
# zmin, zmax = -5, 5

# xs = np.linspace(xmin, xmax, resolution)
# ys = np.linspace(ymin, ymax, resolution)
# zs = np.linspace(zmin, zmax, num_layers)

# plot implicit function

# plot_implicit_function(ax, Von_Mises_yield_function, xs,ys,zs)

# plot_implicit_function(ax, Sphere, xs,ys,zs)
# plot_implicit_function(ax, deviatoric_stress_plane, xs,ys,zs)

# ax.set_xlim3d(xmin, xmax)
# ax.set_ylim3d(ymin, ymax)
# ax.set_zlim3d(zmin, zmax)

ax.set_xlabel(r'$\sigma_1$')
ax.set_ylabel(r'$\sigma_2$')
ax.set_zlabel(r'$\sigma_3$')
ax.text2D(0.05, 0.95, "Front View", transform = ax.transAxes)

ax.view_init(azim = 45, elev= 28)

plt.show()