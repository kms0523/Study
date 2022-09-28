import matplotlib.pyplot as plt
import numpy as np

from Plot_API import plot_implicit_function
from Plot_API import plot_sphere

def Von_Mises_yield_function(x,y,z):    
    return (x-y)**2 + (y-z)**2 + (z-x)**2 - 8

def deviatoric_stress_plane(x,y,z):
    return x + y + z

fig = plt.figure(figsize=(7,7))

sigma_Y = 3

# draw Von Mises yield function on deviatoric axis
ax = fig.add_subplot(1,1,1, projection = '3d')
plot_sphere(ax, np.sqrt(2 * sigma_Y**2 / 3), 'green', 0.2, 'Von Mises yield function')

# draw deviatoric stress plane on deviatoric axis
resolution = 30
num_layers = 100

xmin, xmax = -5, 5
ymin, ymax = -5, 5
zmin, zmax = -5, 5

coords1 = []
coords1.append(np.linspace(xmin, xmax, resolution))
coords1.append(np.linspace(ymin, ymax, resolution))
coords1.append(np.linspace(zmin, zmax, num_layers))
plot_implicit_function(ax, deviatoric_stress_plane, coords1, 'blue', 0.1, 'deviatoric stress plane')

# draw Von Mises yield surface on deviatoric axis
ts = np.linspace(0, 2*np.pi, 100)

coords2 =[]
coords2.append(sigma_Y / 3 * (np.sqrt(3) * np.cos(ts) - np.sin(ts)))
coords2.append(sigma_Y / 3 * 2 * np.sin(ts))
coords2.append(-sigma_Y / 3 * (np.sqrt(3) * np.cos(ts) + np.sin(ts)))
ax.plot(coords2[0],coords2[1],coords2[2], color = 'black', label = "Von Mises yield surface")

# controll axes style
ax.set_xlim3d(xmin, xmax)
ax.set_ylim3d(ymin, ymax)
ax.set_zlim3d(-4, 4)

ax.set_xlabel(r'$\tilde\sigma_1$', fontsize = 20)
ax.set_ylabel(r'$\tilde\sigma_2$', fontsize = 20)
ax.set_zlabel(r'$\tilde\sigma_3$', fontsize = 20)
ax.xaxis.set_rotate_label(False)
ax.yaxis.set_rotate_label(False)
ax.zaxis.set_rotate_label(False)
# ax.text2D(0.05, 0.95, "Front View", transform = ax.transAxes)

ax.xaxis.set_tick_params(colors = 'white')
ax.yaxis.set_tick_params(colors = 'white')
ax.zaxis.set_tick_params(colors = 'white')

ax.view_init(azim = 3, elev= 20)
ax.legend(loc = 'upper right')

plt.show()

# Reference
# axes label & text style : https://stackoverflow.com/questions/37711538/matplotlib-3d-axes-ticks-labels-and-latex