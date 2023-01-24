import matplotlib.pyplot as plt
import numpy as np

from Plot_API import plot_implicit_function

def Von_Mises_yield_surface(x,y,z):    
    return (x-y)**2 + (y-z)**2 + (z-x)**2 - 18

fig = plt.figure(figsize=(14,7))
ax1 = fig.add_subplot(1,2,1, projection = '3d')
ax2 = fig.add_subplot(1,2,2, projection = '3d')

sigma_Y = 3

# draw Von Mises yield surface on principal stress axis
resolution = 30
num_layers = 100

xmin, xmax = -10, 10
ymin, ymax = -10, 10
zmin, zmax = -5, 5

coords1 = []
coords1.append(np.linspace(xmin, xmax, resolution))
coords1.append(np.linspace(ymin, ymax, resolution))
coords1.append(np.linspace(zmin, zmax, num_layers))
plot_implicit_function(ax1, Von_Mises_yield_surface, coords1, 'blue', 0.1, 'Von Mises yield surface')
plot_implicit_function(ax2, Von_Mises_yield_surface, coords1, 'blue', 0.1, 'Von Mises yield surface')

# draw hydro static pressure line
ts = np.linspace(-10, 10, 100)
ax1.plot(ts,ts,ts, linestyle = '--', color = 'black', label = r'$\sigma_1 = \sigma_2 = \sigma_3$')
ax2.plot(ts,ts,ts, linestyle = '--', color = 'black', label = r'$\sigma_1 = \sigma_2 = \sigma_3$')

# controll axes style
ax1.set_xlim3d(-12, 12)
ax1.set_ylim3d(-12, 12)
ax1.set_zlim3d(-10, 10)

ax1.set_xlabel(r'$\sigma_1$', fontsize = 20)
ax1.set_ylabel(r'$\sigma_2$', fontsize = 20)
ax1.set_zlabel(r'$\sigma_3$', fontsize = 20)
ax1.xaxis.set_rotate_label(False)
ax1.yaxis.set_rotate_label(False)
ax1.zaxis.set_rotate_label(False)
ax1.text2D(0.05, 0.95, "Side View", transform = ax1.transAxes)

ax1.xaxis.set_tick_params(colors = 'white')
ax1.yaxis.set_tick_params(colors = 'white')
ax1.zaxis.set_tick_params(colors = 'white')

ax1.legend(loc = 'upper right')

# controll axes style
ax2.set_xlim3d(-12, 12)
ax2.set_ylim3d(-12, 12)
ax2.set_zlim3d(-10, 10)

ax2.set_xlabel(r'$\sigma_1$', fontsize = 20)
ax2.set_ylabel(r'$\sigma_2$', fontsize = 20)
ax2.set_zlabel(r'$\sigma_3$', fontsize = 20)
ax2.xaxis.set_rotate_label(False)
ax2.yaxis.set_rotate_label(False)
ax2.zaxis.set_rotate_label(False)
ax2.text2D(0.05, 0.95, "Front View", transform = ax2.transAxes)

ax2.xaxis.set_tick_params(colors = 'white')
ax2.yaxis.set_tick_params(colors = 'white')
ax2.zaxis.set_tick_params(colors = 'white')

ax2.legend(loc = 'upper right')


# set view
ax1.view_init(azim = 3, elev= 20)
ax2.view_init(azim = 45, elev= 33)

plt.show()

# Reference
# axes label & text style : https://stackoverflow.com/questions/37711538/matplotlib-3d-axes-ticks-labels-and-latex