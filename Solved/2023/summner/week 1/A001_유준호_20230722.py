class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
    
        g.sort()  # Sort the greed factor array in ascending order
        s.sort()  # Sort the cookie size array in ascending order
        
        content_children = 0
        i, j = 0, 0
        
        while i < len(g) and j < len(s):
            if g[i] <= s[j]:
                content_children += 1
                i += 1
            j += 1
        
        return content_children
