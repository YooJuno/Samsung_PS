sentence = input()

for i in range(len(sentence)):
    print(sentence[i],end='')

    if i%10 == 9:
        print('')