import numpy as np
import matplotlib.pyplot as plt
import os

data = np.loadtxt("datos.dat")
z=np.zeros(100)
x=0

for i in range(len(data)):
    if((i%100)==0 and i!=0):
        z[i%100]=0
        z[(i-1)%100]=0
        plt.title('Ecuacion de onda')
        plt.ylabel('u')
        plt.xlabel('x')
        plt.plot(z,color='g')
        plt.ylim((-2,2))
        plt.savefig(str(x))
        plt.close()
        x+=1
    else:
        z[i%100]=data[i]
    
os.system('convert -delay 100 -loop 0 *.png cuerda.gif')    

