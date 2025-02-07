s = input()
count = 0
i = 0
len_s = len(s)

while i < len_s:
    if i + 1 < len_s and (s[i+1] == '=' or s[i:i+2] in ['lj', 'nj', '--']):
        count += 1
        i += 2
    elif i + 2 < len_s and s[i:i+3] == 'dz=':
        count += 1
        i += 3
    else:
        count += 1
        i += 1

print(count)

