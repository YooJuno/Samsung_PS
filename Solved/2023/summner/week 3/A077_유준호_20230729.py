
num = list(map(int, input().split()))
count = {num[i]: i+1 for i in range(8)}

for i in range(7):
    for j in range(i+1, 8):
        if num[i] < num[j]:
            num[i], num[j] = num[j], num[i]

rank = [count[num[i]] for i in range(5)]
sum_val = sum(num[:5])

for i in range(4):
    for j in range(i+1, 5):
        if rank[i] > rank[j]:
            rank[i], rank[j] = rank[j], rank[i]

print(sum_val)
print(*rank)

