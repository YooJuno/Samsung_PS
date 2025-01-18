n = int(input())  # 나무의 개수
trees = list(map(int, input().split()))  # 각 나무 자라는 시간
trees.sort(reverse=True)  # 나무를 자라는 시간 역순으로 정렬

max_time = 0

for i in range(n):
    max_time = max(max_time, trees[i] + i + 2)

print(max_time)
