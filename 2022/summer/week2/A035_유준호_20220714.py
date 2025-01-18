T = int(input())

# @는 3을 곱하고
# %는 5를 더하며
# #는 7을 빼는 연산자

for i in range(T):
    list = input().split()

    sum = 0

    for j in list:
        if j == '@':
            sum *= 3.0

        elif j == '%':
            sum += 5.0

        elif j == '#':
            sum -= 7.0

        else:
            sum += float(j)

    print("%.2f"%(sum))