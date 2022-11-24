class Item:
    def __init__(self,hitPower):
        self.hitPower =hitPower
    
class GamePeice:
   
    def fight(self):
        return "fight with {} Hit Power is {} ".format(self.item.__class__.__name__,self.item.hitPower)

class Sword(Item):
    def __init__(self,hitPower,length):
        super().__init__(hitPower)
        self.length = length
        #Your code here set object varibale length = length
        
class Fist(Item):
    pass
   
    
class Human(GamePeice):
    
    def __init__(self,height):
        self.height = height
        #Your code here set object varibale height = height
        self.item = Fist(3.0)



class Swordman(Human):
    
    def __init__(self,height,swardHitPower,length):        
        super().__init__(height)
        self.item = Sword(swardHitPower,length)
        
        


def Problem1(): 
    aMan = Human(180)
    msgMan = aMan.fight()

    aSwordMan = Swordman(170,213,1.0)
    msgSwordMan  = aSwordMan.fight()
    return [msgMan, msgSwordMan]