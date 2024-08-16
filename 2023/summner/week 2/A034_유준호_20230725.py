list = [0 for i in range(43)]

for i in range(10):
    num = int(input())

    list[num%42] = 1

sum = 0
for i in range(43):
    sum += list[i]

print(sum)