T = int(input())

list = []

list.append([])
for i in range(15):
    list[0].append(i)

for i in range(1, 14+1):
    list.append([])
    sum = 0
    for j in range(0, 14+1):
        sum += list[i-1][j]
        list[i].append(sum)


for iter in range(T):
    k = input()
    n = input()
    k = int(k)
    n = int(n)
    print(list[k][n])
        
            

