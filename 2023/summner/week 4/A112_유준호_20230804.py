n, m = map(int, input().split())

min_package = 1000
min_single = 1000

for _ in range(m):
    package, single = map(int, input().split())
    min_package = min(min_package, package)
    min_single = min(min_single, single)

if min_package <= min_single * 6:
    print(min_package * (n // 6) + min(min_package, min_single * (n % 6)))
else:
    print(min_single * n)
