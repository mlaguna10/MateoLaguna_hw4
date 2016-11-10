import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("data.dat")
A = np.matrix(np.split(data[0:125000],250))

data2 = np.loadtxt("electricoA.dat")
data3 = np.loadtxt("electricoB.dat")

d = np.sqrt(data2**2 + data3**2)

fig = plt.figure()
ax = fig.add_subplot(1,1,1)
ax.set_aspect('equal')
plt.imshow(A, interpolation='nearest', cmap=plt.cm.ocean)
plt.colorbar()
plt.title("Grafica del potencial")
plt.savefig("placas.pdf")
plt.show()


