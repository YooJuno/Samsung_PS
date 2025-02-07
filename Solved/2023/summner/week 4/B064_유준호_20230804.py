n = int(input())  # 숫자의 개수
numbers = list(map(int, input().split()))  # 숫자들
target = int(input())  # 목표 합

numbers.sort()  # 숫자들을 오름차순으로 정렬

left = 0
right = n - 1
count = 0  # 경우의 수 카운트

while left < right:
    curr_sum = numbers[left] + numbers[right]
    
    if curr_sum == target:
        count += 1
        left += 1
        right -= 1
    elif curr_sum < target:
        left += 1
    else:
        right -= 1

print(count)
