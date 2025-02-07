count = int(input())
count_check = 0
flag = 0

for i in range(1, count + 1):
    for j in range(i):
        count_check += 1

        if count == count_check:
            if i % 2 == 0:
                print(f"{j + 1}/{i - j}")
            else:
                print(f"{i - j}/{j + 1}")
            flag = 1
            break

    if flag == 1:
        break
