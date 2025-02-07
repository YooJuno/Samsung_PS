class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:

        char_count = {}
        
        for char in text:
            if char in "balloon":
                char_count[char] = char_count.get(char, 0) + 1
        
        char_count["l"] //= 2
        char_count["o"] //= 2
        
        min_count = float('inf')
        
        for char in "balon":
            min_count = min(min_count, char_count.get(char, 0))
        
        return min_count

