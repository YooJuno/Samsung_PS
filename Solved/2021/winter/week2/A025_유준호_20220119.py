class Solution(object):
    def isPowerOfFour(self, n):
        if n <= 0: 
            answer =False 
        else: 
            while n % 4 == 0: 
                n = n / 4 
            if n == 1: 
                answer = True 
            else: 
                answer = False 
        return answer


        
        