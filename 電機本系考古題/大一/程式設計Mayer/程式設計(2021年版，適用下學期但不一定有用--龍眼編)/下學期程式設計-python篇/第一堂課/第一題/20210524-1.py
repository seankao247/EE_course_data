import numpy as np
import matplotlib.pyplot as plt

plt.xticks([-1.00,-0.75,-0.50,-0.25,0.00,0.25,0.50,0.75,1.00])
plt.yticks([-4,-2,0,2,4])
plt.xlabel("value of x",fontsize=16)
plt.ylabel("value of y",fontsize=16)
plt.title("Test Chart",fontsize=20)

xp = np.linspace(-1.0,1.0,1000000,endpoint=True)
yp1= [5*x for x in xp]
yp2= [5*(x**2) for x in xp]
yp3= [5*(x**3) for x in xp]

plt.plot(xp,yp1,color="blue")
plt.plot(xp,yp2,color="orange")
plt.plot(xp,yp3,color="green")
plt.show()