def main():
    N = int(input())
    num = [False] * 2001

    for i in range(N):
        temp = int(input())
        temp += 1000
        num[temp] = True

    for i in range(2001):
        if num[i]:
            print(i - 1000, end=' ')

if __name__ == "__main__":
    main()
