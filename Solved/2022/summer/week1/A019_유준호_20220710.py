num1 = int(input())
num2 = int(input())
num3 = int(input())

k = num1 * num2 * num3
list = list(str(k))
for i in range(10):
    num_count = list.count(str(i))
    print(num_count)