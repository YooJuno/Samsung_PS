from collections import deque


N = int(input())
Q = deque()

for _ in range(N):
    str_input = input().split()

    if str_input[0] == "push":
        num = int(str_input[1])
        Q.append(num)
    elif str_input[0] == "pop":
        if not Q:
            print("-1")
        else:
            print(Q.popleft())
    elif str_input[0] == "size":
        print(len(Q))
    elif str_input[0] == "empty":
        print(int(not Q))
    elif str_input[0] == "front":
        if not Q:
            print("-1")
        else:
            print(Q[0])
    elif str_input[0] == "back":
        if not Q:
            print("-1")
        else:
            print(Q[-1])

