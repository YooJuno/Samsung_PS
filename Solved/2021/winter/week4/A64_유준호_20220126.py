class Solution(object):
    def heightChecker(self, heights):
        sorted_height = sorted(heights)
        
        cnt = 0
        
        for i, height in enumerate(heights):
            if sorted_height[i] != height:
                cnt = cnt + 1
                
        return cnt