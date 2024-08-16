import math

# def border(x1, y1, r1, x2, y2, r2):
    


count = int(input())

for _ in range(count):
    border = 0
    x1, y1, r1, x2, y2, r2 = map(int, input().split())

    len = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
    r3 = abs(r1 - r2)
    
    if r1 != r2:
        if len == r1 + r2:
            border = 1
        elif len == r3:
            border = 1
        elif r3 < len and len < r1 + r2:
            border = 2
        elif len > r1 + r2:
            border = 0
        else:
            border = 0
    else:
        if len == r1 + r2:
            border = 1
        elif r3 < len and len < r1 + r2:
            border = 2
        elif len == 0:
            border = -1
        else:
            border = 0
        

    print(border)

