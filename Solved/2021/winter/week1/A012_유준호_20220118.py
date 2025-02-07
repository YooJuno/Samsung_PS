class Solution(object):
    def countPrimes(self, n):
        if n <=2 : 
            return 0 
        prime = [0] * (n+1) 
        cnt = 0 
        for i in range(2,n): 
            if prime[i] == 0 : 
                cnt += 1 
                for j in range(i,n,i): 
                    prime[j] += 1 
        return cnt