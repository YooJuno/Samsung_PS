num = int(input())


sum = 0
for i in range(num):
    dict = {}
    word = input()
    dict[word[0]] = 1
    flag = 0
    for j in range(1, len(word)):
        if word[j] not in dict.keys():
            dict[word[j]] = 1

        elif word[j-1] != word[j] and  dict[word[j]] == 1:
            flag = 1
    
    if flag == 0:
        sum += 1
print(sum)



