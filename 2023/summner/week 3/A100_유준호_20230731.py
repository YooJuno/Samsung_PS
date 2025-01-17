class Solution:
    def isValid(self, s: str) -> bool:

        stack = []
        parentheses_map = {')': '(', '}': '{', ']': '['}

        for char in s:
            if char in '({[':
                stack.append(char)
            elif char in ')}]':
                if not stack or stack.pop() != parentheses_map[char]:
                    return False

        return not stack