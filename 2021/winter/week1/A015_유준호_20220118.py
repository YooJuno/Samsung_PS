list_num = list(map(int, input().split()))

result = 0

for i in list_num:
    result += i ** 2

print(result % 10)