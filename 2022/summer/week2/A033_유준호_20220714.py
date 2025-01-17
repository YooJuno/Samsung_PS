list = []
max = 0
top = 0
for i in range(5):
    sum = 0
    for num in input().split():
        sum += int(num)
    
    if sum > max:
        top = i
        max = sum

print(top+1, max)



    