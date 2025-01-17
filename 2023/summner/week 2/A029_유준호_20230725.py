N = int(input())

input = bool(int(input()))
door = input
flag = 0
for i in range(2, N+1):
    door = not(door)

    if (i%2==0 and door == input) or (i%3==0 and door != input):
        flag = 1
        break

if flag == 1:
    print('Love is open door')
else:
    for i in range(N-1):
        input = not(input)
        print(int(input))