class Solution:
    def convertToTitle(self, n):
        str = ''
        while n != 0:
            tmp = 'A' + (n-1) % 26
            n = (n-1) // 26
            str = tmp + str
        return str