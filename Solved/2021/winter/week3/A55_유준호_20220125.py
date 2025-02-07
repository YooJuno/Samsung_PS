def removeOuterParentheses(self, S: str) -> str:
        stack = []
        index_remove=set()
        res=""
        for i, v in enumerate(S):
            if v == "(":
                stack.append(i)
            else:
                left_index = stack.pop()
                if not stack:
                    index_remove.add(left_index)
                    index_remove.add(i)
        for i, v in enumerate(S):
            if i not in index_remove:
                res+=v
        return res