import matplotlib.pyplot as plt
import numpy as np

from Plot_API import plot_implicit_function

def Von_Mises_yield_function(x,y,z):    
    return (x-y)**2 + (y-z)**2 + (z-x)**2 - 8

def Sphere(x,y,z):
    return x**2 + y**2 + z**2 -6

def deviatoric_stress_plane(x,y,z):
    return x + y + z

resolution = 30
num_layers = 100

xmin, xmax = -5, 5
ymin, ymax = -5, 5
zmin, zmax = -5, 5

xs = np.linspace(xmin, xmax, resolution)
ys = np.linspace(ymin, ymax, resolution)
zs = np.linspace(zmin, zmax, num_layers)

# plot implicit function
fig = plt.figure(figsize=(8,6))
ax = fig.add_subplot(1,1,1, projection = '3d')
# plot_implicit_function(ax, Von_Mises_yield_function, xs,ys,zs)

plot_implicit_function(ax, Sphere, xs,ys,zs)
# plot_implicit_function(ax, deviatoric_stress_plane, xs,ys,zs)

ax.set_xlim3d(xmin, xmax)
ax.set_ylim3d(ymin, ymax)
ax.set_zlim3d(zmin, zmax)

ax.set_xlabel(r'$\sigma_1$')
ax.set_ylabel(r'$\sigma_2$')
ax.set_zlabel(r'$\sigma_3$')
ax.text2D(0.05, 0.95, "Front View", transform = ax.transAxes)

ax.view_init(azim = 45, elev= 28)

plt.show()

# def plot_implicit(fn, bbox=(-5,5)):
#     f = np.vectorize(fn) # vectorization for line 29

#     length = bbox[1]- bbox[0]

#     xmin, xmax = bbox
#     ymin, ymax = bbox    
#     zmin, zmax = bbox[0] + length*0.25, bbox[1] - length*0.25
       
#     resolution = 30
#     num_layers = 50
#     xs = np.linspace(xmin, xmax, resolution) # x coordinates
#     ys = np.linspace(ymin, ymax, resolution) # y coordinates
#     zs = np.linspace(zmin, zmax, num_layers) # z coordinates

#     X,Y = np.meshgrid(xs,xs) 


#     # plot contours     
#     fig = plt.figure(figsize=(8,5))

#     ax1 = fig.add_subplot(1,2,1, projection='3d')
#     for z in zs: 
#         Z = f(X,Y,z)
#         ax1.contour(X, Y, Z+z, [z], zdir='z', alpha=0.2)
        
#     ax1.set_xlim3d(bbox)
#     ax1.set_ylim3d(bbox)
#     ax1.set_zlim3d(bbox)

#     ax1.set_xlabel(r'$\sigma_1$')
#     ax1.set_ylabel(r'$\sigma_2$')
#     ax1.set_zlabel(r'$\sigma_3$')
#     ax1.text2D(0.05, 0.95, "Front View", transform = ax1.transAxes)

#     # ax1.xaxis.set_tick_params(colors = 'white')
#     # ax1.yaxis.set_tick_params(colors = 'white')
#     # ax1.zaxis.set_tick_params(colors = 'white')

#     ax1.view_init(azim = 45, elev= 28)

#     ax2 = fig.add_subplot(1, 2, 2, projection = "3d")
#     for z in zs: 
#         Z = f(X,Y,z)
#         ax2.contour(X, Y, Z+z, [z], zdir='z', alpha=0.2, label = 'f')

#     ax2.set_xlim3d(bbox)
#     ax2.set_ylim3d(bbox)
#     ax2.set_zlim3d(bbox)

#     ax2.set_xlabel(r'$\sigma_1$')
#     ax2.set_ylabel(r'$\sigma_2$')
#     ax2.set_zlabel(r'$\sigma_3$')
#     ax2.text2D(0.05, 0.95, "Side View", transform = ax2.transAxes)

#     # ax2.xaxis.set_tick_params(colors = 'white')
#     # ax2.yaxis.set_tick_params(colors = 'white')
#     # ax2.zaxis.set_tick_params(colors = 'white')

#     ax2.view_init(azim = 15, elev= 15)

#     ax2.plot(xs,xs,xs, linestyle = '--', color = "black", label = r'$\sigma_1 = \sigma_2 =\sigma_3$')
#     ax2.legend()

#     plt.show()



# def Max_Shear_Stress_yield_function(x,y,z):
#     return max(x,y,z) - min(x,y,z) - 2

# def test(x,y,z):
#     return x*y + y*z + z*x + 3

# plot_implicit(Max_Shear_Stress_yield_function)
# plot_implicit(Von_Mises_yield_function)
# plot_implicit(test)




#참고
# https://stackoverflow.com/questions/4680525/plotting-implicit-equations-in-3d
# https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.contour.html

    ## plot contours in the XZ plane
    # ax2 = fig.add_subplot(1,3,2, projection='3d')
    # X,Z = np.meshgrid(xs,xs) 
    # for y in zs:         
    #     Y = f(X,y,Z)
        # ax2.contour(X, Y+y, Z, [y], zdir='y', colors = 'black', alpha=0.2)

    ## plot contours in the YZ plane
    # ax3 = fig.add_subplot(1,3,3, projection='3d')
    # Y,Z = np.meshgrid(xs,xs) 
    # for x in zs: 
    #     X = f(x,Y,Z)
        # ax3.contour(X+x, Y, Z, [x], zdir='x', colors = 'black', alpha=0.2)
