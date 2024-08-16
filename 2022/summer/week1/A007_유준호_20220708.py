input = [int(i) for i in input().split()]

answer = [i for i in range(1, 9)]
r_answer = sorted(answer, reverse=True)

if input == answer:
    print('ascending')
elif input == r_answer:
    print('descending')
else:
    print('mixed')