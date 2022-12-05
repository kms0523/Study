import matplotlib.pyplot as plt
import numpy as np

def plot_implicit(fn, bbox=(-5,5)):

    length = bbox[1]- bbox[0]

    xmin, xmax = bbox
    ymin, ymax = bbox    
    zmin, zmax = bbox[0] + length*0.2, bbox[1] - length*0.2

    fig = plt.figure(figsize=(10,3))
    
    resolution = 30
    num_layer = 50
    
    xs = np.linspace(xmin, xmax, resolution) # x & y coordinates
    zs = np.linspace(zmin, zmax, num_layer) # z coordinates
    
    ax = fig.add_subplot(1,3, 1, projection='3d')
    
    X,Y = np.meshgrid(xs,xs) # grid on which the contour is plotted 
    Z = np.zeros((resolution, resolution))
    
    for z in zs: # plot contours in the XY plane
        for i in range(0, resolution):
            for j in range(0, resolution):
                x = xs[i]
                y = xs[j]
                Z[i,j]= fn(x,y,z)
        
        cset = ax.contour(X, Y, Z+z, [z], zdir='z', alpha=0.2)


        # X,Y = A1,A2
        # Z = fn(X,Y,z)
        # cset = ax.contour(X, Y, Z+z, [z], zdir='z', alpha=0.2)
        # [z] defines the only level to plot for this contour for this value of z


    # ax = fig.add_subplot(1,3, 1, projection='3d')
    # for z in B: # plot contours in the XY plane
    #     X,Y = A1,A2
    #     Z = fn(X,Y,z)
    #     cset = ax.contour(X, Y, Z+z, [z], zdir='z', alpha=0.2)
    #     # [z] defines the only level to plot for this contour for this value of z

    # ax2 = fig.add_subplot(1,3,2, projection='3d')
    # for y in B: # plot contours in the XZ plane
    #     X,Z = A1,A2
    #     Y = fn(X,y,Z)
    #     cset = ax2.contour(X, Y+y, Z, [y], zdir='y', alpha=0.2)

    # ax3 = fig.add_subplot(1,3,3, projection='3d')
    # for x in B: # plot contours in the YZ plane
    #     Y,Z = A1,A2
    #     X = fn(x,Y,Z)
    #     cset = ax3.contour(X+x, Y, Z, [x], zdir='x', alpha=0.2)

    # must set plot limits because the contour will likely extend
    # way beyond the displayed level.  Otherwise matplotlib extends the plot limits
    # to encompass all values in the contour.
    ax.set_xlim3d(xmin,xmax)
    ax.set_ylim3d(ymin,ymax)
    ax.set_zlim3d(zmin,zmax)
    # ax2.set_xlim3d(xmin,xmax)
    # ax2.set_ylim3d(ymin,ymax)
    # ax2.set_zlim3d(zmin,zmax)
    # ax3.set_xlim3d(xmin,xmax)
    # ax3.set_ylim3d(ymin,ymax)
    # ax3.set_zlim3d(zmin,zmax)

    plt.show()

def Von_Mises_yield_function(x,y,z):    
    return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-y) - 2

def Max_Shear_Stress_yield_function(x,y,z):
    return max(x,y,z) - min(x,y,z) - 2

plot_implicit(Max_Shear_Stress_yield_function)
# plot_implicit(Von_Mises_yield_function)

#참고
# https://stackoverflow.com/questions/4680525/plotting-implicit-equations-in-3d