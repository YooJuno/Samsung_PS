num = int(input())
count = 0

for i in range(1, num + 1):
    if i < 100:
        count += 1
    else:
        temp = i
        jari = [0] * 3
        jari[0] = temp // 100
        temp -= jari[0] * 100

        jari[1] = temp // 10
        temp -= jari[1] * 10

        jari[2] = temp

        dif = [jari[0] - jari[1], jari[1] - jari[2]]

        if dif[0] == dif[1]:
            count += 1

print(count)
