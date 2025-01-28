import matplotlib.pyplot as plt
import numpy as np
xp=[]
yp=[]
upsum=0
downsum=0
with open("data.txt",mode="r") as file:
    data=file.readlines()
    for x in range (0,20):
        number=data[x].split(",")
        xp.append(int(number[0]))
        yp.append(int(number[1]))
xarray=np.array(xp)
yarray=np.array(yp)
avex=xarray.mean()
avey=yarray.mean()
for i in range(0,20):
    upsum+=(xarray[i]-avex)*(yarray[i]-avey)
    downsum+=(xarray[i]-avex)*(xarray[i]-avex)
slope=upsum/downsum
y=avey-slope*(10.5)
plt.scatter(xarray,yarray,s=40,color="blue")
plt.plot(xarray,xarray*slope+y,color="red")
plt.show()