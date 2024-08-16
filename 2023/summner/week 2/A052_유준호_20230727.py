
num = int(input())
for j in range(num):
    OX = input()
    sum = 0
    temp = 0
    
    for i in range(len(OX)):
        if OX[i] == 'O':
            temp += 1
            sum += temp
        else:
            temp = 0
    
    print(sum)
