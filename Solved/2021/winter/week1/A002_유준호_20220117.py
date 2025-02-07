class Solution(object):
    def generate(self, numRows):
        result = []
        for i in range(numRows):     
            lst = [1] * (i+1)                                
            if (i+1) > 2:
                for j in range(len(result[-1])-1):
                    new = result[-1][j] + result[-1][j+1]
                    lst[0] = 1
                    lst[-1] = 1
                    lst[j+1] = new
            result.append(lst)
        
        return result