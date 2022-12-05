import matplotlib.pyplot as plt
import numpy as np

ts = np.linspace(0, 2*np.pi, 100) # theta

x = np.sqrt(3)*np.cos(ts)-np.sin(ts)
y = 2*np.sin(ts)
z = -(np.sqrt(3) * np.cos(ts) + np.sin(ts))

figure = plt.figure()
ax = figure.add_subplot(projection = "3d")

ax.plot(x, y, z)
plt.show()