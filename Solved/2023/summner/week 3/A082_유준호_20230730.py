
N = int(input())
members = []

for _ in range(N):
    age, name = input().split()
    members.append((int(age), name))

members.sort(key=lambda x: x[0])  # 나이순으로 정렬

for member in members:
    print(member[0], member[1])

