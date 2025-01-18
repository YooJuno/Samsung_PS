class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:

        morse_code = [
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."
        ]

        unique_codes = set()

        for word in words:
            morse_word = ""
            for char in word:
                morse_word += morse_code[ord(char) - ord('a')]
            unique_codes.add(morse_word)

        return len(unique_codes)
    