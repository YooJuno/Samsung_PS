a, b = map(int, input().split())
sum_val = 0
count = 0

for i in range(1, b + 1):
    for j in range(1, i + 1):
        if count >= a - 1:
            sum_val += i
        count += 1
        if count == b:
            break
    if count == b:
        break

print(sum_val)
