N = int(input())

dict = {}

for i in range(N):
    ch = input()[0]

    if ch not in dict.keys():
        dict[ch] = 1
    
    else:
        dict[ch] += 1

list = sorted(dict.keys())
print(list)