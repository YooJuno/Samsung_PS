class Solution(object):
    def isPerfectSquare(self, num):
        sqrt_num = num ** 0.5 
        answer = False 
        if sqrt_num == int(sqrt_num): 
            answer = True 
        return answer

