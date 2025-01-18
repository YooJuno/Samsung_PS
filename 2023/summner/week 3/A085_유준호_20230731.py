
N = int(input())
s = []

for i in range(N):
    temp = input()
    s.append(temp)

s.sort(key=lambda x: (len(x), sum(int(c) for c in x if c.isdigit()), x))

for item in s:
    print(item)

