N, K = map(int, input().split())
q = list(range(1, N + 1))

result = []
idx = 0

while q:
    idx = (idx + K - 1) % len(q)
    result.append(q.pop(idx))

print('<' + ', '.join(map(str, result)) + '>')