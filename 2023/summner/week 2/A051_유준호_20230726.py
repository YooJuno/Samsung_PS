def number(ch):
    if 'A' <= ch <= 'C':
        return 3
    elif 'D' <= ch <= 'F':
        return 4
    elif 'G' <= ch <= 'I':
        return 5
    elif 'J' <= ch <= 'L':
        return 6
    elif 'M' <= ch <= 'O':
        return 7
    elif 'P' <= ch <= 'S':
        return 8
    elif 'T' <= ch <= 'V':
        return 9
    else:
        return 10

def main():
    dial = input()
    time = 0
    for ch in dial:
        time += number(ch)
    print(time)

if __name__ == "__main__":
    main()
