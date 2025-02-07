dict = {'a':0}
max = 'a'

for ch in input().upper():
    if ch not in dict.keys():
        dict[ch] = 1
    else:
        dict[ch] += 1

jungbok = 0

for i in dict.keys():
    if dict[i] > dict[max]:
        max = i
        jungbok = 0
    elif dict[max] == dict[i]:
        jungbok += 1

if jungbok > 0:
    print('?')
else:
    print(max)

