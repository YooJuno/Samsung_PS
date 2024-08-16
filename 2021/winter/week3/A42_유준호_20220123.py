def backspaceCompare(self, S: str, T: str) -> bool:
        s_stack = []
        t_stack = []
        for s in S:
            if s == '#' and s_stack:
                s_stack.pop()
                continue
            if s != '#': s_stack.append(s)
        for t in T:
            if t == '#' and t_stack:
                t_stack.pop()
                continue
            if t != '#': t_stack.append(t)
        return s_stack == t_stack