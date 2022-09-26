import matplotlib.pyplot as plt
import numpy as np

def plot_implicit_function(ax, fn, xs, ys, zs):
    f = np.vectorize(fn) # vectorization for line 29

    X,Y = np.meshgrid(xs,ys) 

    # plot contours     
    for z in zs: 
        Z = f(X,Y,z)
        ax.contour(X, Y, Z+z, [z], zdir='z', alpha=0.2)


def plot_sphere(ax, r, c = 'black', transeparancy = 1.0):
    angle = np.linspace(0, 2*np.pi, 30)
    theta, phi = np.meshgrid(angle, angle)
    
    X = r*np.sin(phi)*np.cos(theta)
    Y = r*np.sin(phi)*np.sin(theta)
    Z = r*np.cos(phi)

    ax.plot_surface(X, Y, Z, color = c, alpha = transeparancy)    