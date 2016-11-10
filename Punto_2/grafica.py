import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("data.dat")
A = np.matrix(np.split(data[0:125000],250))

data2 = np.loadtxt("electricoA.dat")
data3 = np.loadtxt("electricoB.dat")

fig = plt.figure()
ax = fig.add_subplot(1,1,1)
ax.set_aspect('equal')
plt.imshow(A, interpolation='nearest', cmap=plt.cm.ocean)
plt.colorbar()
plt.title("Grafica del potencial")
plt.savefig("placas.pdf")
plt.show()
plt.close()

fig2 = plt.figure()
Y,X = np.mgrid[-3:3:15j, -3:3:15j]
plt.streamplot(X,Y,np.matrix(data2),np.matrix(data3),density=0.6,color='k')
plt.title("Grafica del Campo Electrico")
plt.savefig("electrico.pdf")
plt.show()
plt.close()





