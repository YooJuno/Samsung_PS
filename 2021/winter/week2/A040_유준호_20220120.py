class Solution(object):
    def halvesAreAlike(self, s):
        vowels =  ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
        a = s[:len(s)//2]
        b = s[len(s)//2:]
        
        a_vowel_count = 0
        b_vowel_count = 0
        for a_c, b_c in zip(a, b):
            if a_c in vowels:
                a_vowel_count += 1
            if b_c in vowels:
                b_vowel_count += 1

        return a_vowel_count == b_vowel_count