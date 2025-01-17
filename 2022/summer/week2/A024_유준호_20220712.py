 class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        list = []
        five = 0
        ten = 0
        
        for i in bills:
            if i == 5:
                five += 1    
                continue
                
            elif i == 10:
                ten += 1
                if five >= 1:
                    five -= 1
                    continue
                else:
                    return False
                    
            elif i == 20:
                if five >= 1 and ten >= 1:
                    five -= 1
                    ten -= 1
                    continue
                elif five >=3 :
                    five -= 3
                    continue
                else :
                    return False
        return True