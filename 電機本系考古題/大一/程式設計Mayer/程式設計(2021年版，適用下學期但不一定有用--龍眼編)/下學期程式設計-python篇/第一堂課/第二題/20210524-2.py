import numpy as np
import matplotlib.pyplot as plt
x1=[]
y1=[]
x2=[]
y2=[]
with open("data.txt",mode="r",) as file :
    data=file.readlines()
    for x in range(0,20) :
        if x<10 :
           number=data[x].split(",")
           x1.append(int(number[0]))
           y1.append(int(number[1]))
        else :
           number=data[x].split(",")
           x2.append(int(number[0]))
           y2.append(int(number[1]))
plt.plot(x1,y1,color="blue")
plt.plot(x2,y2,color="orange")
plt.xlabel("x",fontsize=16)
plt.ylabel("y",fontsize=16)
plt.title("Chart",fontsize=20)
plt.show()
