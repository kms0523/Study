import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure(figsize=(5,5))
ax1 = fig.add_subplot(1,1,1)

xs1 = np.array([1,2,3,4,5])
ys1 = np.array([2,5,3,1,2])

xs2 = np.array([1,3,4,5])
ys2 = np.array([2,7,-3,1])

ax1.plot(xs1,ys1, linestyle = 'dotted', color = 'black', label = r'$f_1$')
ax1.plot(xs2,ys2, linestyle = 'solid', color = 'blue', label = r'$f_2$')
ax1.legend(loc = 'upper right')
plt.show()

# (Linestyles)[https://matplotlib.org/stable/gallery/lines_bars_and_markers/linestyles.html] 
# (legend)[https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.legend.html]