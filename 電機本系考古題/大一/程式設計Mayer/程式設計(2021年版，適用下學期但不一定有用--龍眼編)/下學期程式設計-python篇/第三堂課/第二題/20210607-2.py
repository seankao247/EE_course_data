import pandas as pd
from pandas.core.frame import DataFrame
import numpy as np
data = pd.read_csv("data.csv")
print(data)
print("============================================================")
second_data = data.nlargest(5,"Goals")
print(second_data)
print("============================================================")
team = data["Team"]
yellow = data["Yellow Cards"]
red = data["Red Cards"]
yellow_number = list(yellow)
red_number = list(red)
foul_number = np.add(red_number,yellow_number)
foul = pd.Series(foul_number)
Third_data = pd.DataFrame({"Team":team,"Yellow Cards":yellow,"Red Cards":red,"Foul":foul})
Third_data = Third_data.sort_values(by="Foul",ascending=False)
print(Third_data)