class Solution(object):
    def maximumUnits(self, boxTypes, truckSize):
        sBoxTypes = sorted(boxTypes, key = lambda x : -x[1]) 
        cnt = 0 
        ans = 0 
        for box, unit in sBoxTypes: 
            cnt += box 
            if cnt > truckSize:
                ans += (truckSize - (cnt - box)) * unit 
                break 
            ans += box * unit 
        return ans

