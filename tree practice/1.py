from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-1,1,15)
y = np.linspace(-1,1,15)

a,b = np.meshgrid(x,y)

def f(m,n):
   return np.cos(abs(m)+abs(n))

z=f(a,b)

ax = plt.axes(projection = '3d')

ax.plot_surface(a,b,z)

ax.set_xlabel('x-axis')
ax.set_ylabel('y-axis')
ax.set_zlabel('z-axis')

plt.show()
