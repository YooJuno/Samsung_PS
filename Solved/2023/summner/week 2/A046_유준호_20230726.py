N = int(input())

dict = {}

for i in range(N):
    ch = input()[0]

    if ch not in dict.keys():
        dict[ch] = 1
    
    else:
        dict[ch] += 1

list = sorted(dict.keys())

flag = 0
for key in list:
    if dict[key] >= 5:
        print(key,end='')
        flag = 1
if flag == 0:
    print('PREDAJA')