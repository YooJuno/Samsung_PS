class Solution:
    def addDigits(self, num: int) -> int:
        cnt = 1
        temp = num
        while 1:
            sum = 0
            for ch in str(temp):
                sum += int(ch)
                
            if sum < 10 :
                break
            else :
                cnt += 1
                temp = sum
                
        return cnt