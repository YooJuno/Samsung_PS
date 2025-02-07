class Solution:
    def addBinary(self, a: str, b: str) -> str:
        """
        Runtime : faster than 94.74% of Python3
        Memory Usage : less than 5.43% of Python3
        """
        return format(int(a, 2) + int(b, 2),'b')