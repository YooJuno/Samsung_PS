num = int(input())

for _ in range(num):
    A, B = map(int, input().split())
    a = A
    b = B
    
    if a > b:
        a, b = b, a
    
    while b != 0:
        rem = a % b
        a = b
        b = rem
        if b == 0:
            max_val = a
            break
    
    temp1 = A // max_val
    temp2 = B // max_val
    min_val = (temp1 * temp2) * max_val
    print(min_val)
