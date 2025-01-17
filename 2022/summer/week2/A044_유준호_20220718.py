from collections import Counter
class Solution:
    def checkRecord(self, s: str) -> bool:
        answer = True
        a_count = 0
        
        for i in range(len(s)):
            if s[i] == 'A':
                a_count = a_count + 1
                if a_count == 2:
                    answer = False
                    break
            elif s[i] == 'L' and i+2 < len(s):
                if s[i+1] == 'L' and s[i+2] == 'L':
                    answer = False
                    break
                    
        return answer