class Solution:
    def numPrimeArrangements(self, n: int) -> int:

        def is_prime(num):
            if num <= 1:
                return False
            if num <= 3:
                return True
            if num % 2 == 0 or num % 3 == 0:
                return False
            i = 5
            while i * i <= num:
                if num % i == 0 or num % (i + 2) == 0:
                    return False
                i += 6
            return True
        
        MOD = 10**9 + 7
        
        primes = sum(1 for i in range(1, n + 1) if is_prime(i))
        non_primes = n - primes
        
        def factorial(num):
            result = 1
            for i in range(1, num + 1):
                result = (result * i) % MOD
            return result
        
        return (factorial(primes) * factorial(non_primes)) % MOD
