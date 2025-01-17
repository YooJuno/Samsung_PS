N = int(input())
q = list(range(1, N + 1))

while len(q) > 1:
    q.pop(0)
    q.append(q[0])
    q.pop(0)

print(q[0])