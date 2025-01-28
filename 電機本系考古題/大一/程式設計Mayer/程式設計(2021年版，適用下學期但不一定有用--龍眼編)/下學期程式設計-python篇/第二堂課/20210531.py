import random as r
class Boss:
    def __init__(self,hp,attack):
        self.hp=hp
        self.attack=attack
class Player:
    def __init__(self,hp,attack,name):
        self.hp=hp
        self.attack=attack
        self.name=name
    def fight(self):
        print(self.name,"要打怪物")
    def treat(self):
        print(self.name,"要回100滴血")           
monster=Boss(300,100)
name1=input("第一個玩家：")
name2=input("第二個玩家：")
p1=Player(100,100,name1)
p2=Player(50,70,name2)
print("\n戰鬥開始")
while 1 :
    print("====================================")
    print("<角色資訊>\n名稱      血量      攻擊")
    print("怪物      ",monster.hp,"      ",monster.attack)
    print(p1.name,"      ",p1.hp,"      ",p1.attack)
    print(p2.name,"      ",p2.hp,"      ",p2.attack,"\n")
    die= r.choice([0,1])
    if die == 0 :
        print("怪物想肛",name1)
        p1.hp-=monster.attack
    else :
        print("怪物想肛",name2)
        p2.hp-=monster.attack
    print("\n<我方回應>")
    c1=input("玩家一要1.攻擊還是2.回100血?")
    c2=input("玩家二要1.攻擊還是2.回100血?")
    c1=int(c1)
    c2=int(c2)
    if c1 == 1 :#攻擊
        p1.fight()
        monster.hp-=p1.attack
    else :#回復
        p1.treat()
        p1.hp+=100
    if c2 == 1 :#攻擊
        p2.fight()
        monster.hp-=p2.attack
    else :#回復
        p2.treat()
        p2.hp+=100
    if monster.hp <= 0:#win
        print("\n\n恭喜你們贏了!!!!")
        break
    if p1.hp <= 0 or p2.hp <= 0 :
        print("\n\n你們輸了!!!!")
        break