class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        num = 1
        while 1:
            if num == n:
                return True
            else:
                num *= 4