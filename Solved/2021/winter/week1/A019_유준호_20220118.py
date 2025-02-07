a = int(input())
b = int(input())
c = int(input())
total_str = str(a*b*c)  # 숫자를 곱해서 str타입으로 변환

for num in range(10):  # 0부터 9까지
    num_count = total_str.count(str(num))
    print(num_count)