import pandas as pd
import numpy as np
name = []
score = []
check = []
count = 0
while 1 :
    tem = input("名字：")
    if tem == 'quit':
        break
    name.append(tem)
    tem = input("成績：")
    score.append(int(tem))
print("=============================================")
name_series = pd.Series(name)
score_series = pd.Series(score)
length = name_series.size
for i in range(0,length):
    if int(score[i]) < 60 :
        check.append('Fail')
        count = count + 1
    else :
        check.append('Pass')
check_series = pd.Series(check)
List = pd.DataFrame({"Name":name_series,"Score":score_series,"Standard":check_series})
print(List)
print("=============================================") 
if count*2 > length :
    score = np.sqrt(score)*10
score_series = pd.Series(score)
List = pd.DataFrame({"Name":name_series,"Score":score_series,"Standard":check_series})
List=List.sort_values(by='Score',ascending=False)
print(List)