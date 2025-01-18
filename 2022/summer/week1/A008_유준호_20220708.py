case = int(input())

for i in range(case):
    a = list(map(int, input().split()))
    avg = sum(a[1:])/a[0]
    cnt = 0
    for k in a[1:]:
        if k > avg :
            cnt += 1
    print("%0.3f" %round(cnt/a[0]*100,3)+'%')