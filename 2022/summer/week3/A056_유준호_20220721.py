def findNextGreaterElements(input):
     if not input:
        return
     for i in range(len(input)):
        next = -1
        for j in range(i + 1, len(input)):

            if input[j] > input[i]:
                next = input[j]
                break
 
        print(next, end=' ')
 
 
if __name__ == '__main__':
 
    input = [2, 7, 3, 5, 4, 6, 8]
    findNextGreaterElements(input)
 
