class Solution:
    def checkRecord(self, s: str) -> bool:
        a_cnt = 0 # Record the number of absences 
        b_cnt = 0 # Record the number of consecutive lateness 
        for item in s:
            if item == 'A': a_cnt, b_cnt = a_cnt + 1, 0
            if item == 'L': b_cnt += 1
            if a_cnt == 2 or b_cnt == 3: return False
            if item == 'P': b_cnt = 0
        return True