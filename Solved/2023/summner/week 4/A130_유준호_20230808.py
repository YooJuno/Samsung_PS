k = int(input())  # 줄 갯수
stack = []
sum_val = 0

for _ in range(k):
    num = int(input())
    if num != 0:
        stack.append(num)
    else:
        stack.pop()

sum_val = sum(stack)
print(sum_val)
