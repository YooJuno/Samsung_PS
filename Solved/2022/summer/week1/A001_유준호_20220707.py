class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        child=cookie=0
        
        g.sort()
        s.sort()
        
        num=0
        
        while child<len(g) and cookie<len(s):
            if g[child]<=s[cookie]: 
                num+=1
                child+=1
            cookie+=1
        return num