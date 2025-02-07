N = int(input())
number_list = list(map(int, input().split()))


for i in sorted(list(set(number_list))): 
    print(i, end = ' ')