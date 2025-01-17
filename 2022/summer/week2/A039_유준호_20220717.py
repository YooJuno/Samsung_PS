 class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        sqrt_num = num ** 0.5
        
        answer = False
        
        if sqrt_num == int(sqrt_num):
            answer = True
            
        return answer
