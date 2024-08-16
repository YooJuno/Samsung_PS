
vec_stack = []
length = int(input())

for i in range(length):
    command = input()

    if command == "push":
        num = int(input())
        vec_stack.append(num)
    elif command == "pop":
        if not vec_stack:
            print("-1")
        else:
            print(vec_stack.pop())
    elif command == "size":
        print(len(vec_stack))
    elif command == "empty":
        print(int(not vec_stack))
    elif command == "top":
        if not vec_stack:
            print("-1")
        else:
            print(vec_stack[-1])
    else:
        print("ERROR")

