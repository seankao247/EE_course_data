import msvcrt as ms
import numpy as np
import os
word = []
sentence = []
count = 0
while 1 :
    a = ms.getch()
    b = str(a)
    bb = list(a)
    c = b.split("'")
    if bb == [13]:
        break   
    word.append(c[1])
    if bb == [8]:
        print("8")
        word.pop()
        word.pop()
        print(word)
        count-=1
        print(count)
        os.system("cls")
        for x in range(0,count):
            print(word[x])
    else :
        count += 1
        print(c[1],bb)
sentence = word[0] + word[1]
for i in range(2,count) :
    sentence += word[i]
print(sentence)