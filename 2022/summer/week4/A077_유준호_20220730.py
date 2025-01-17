n=int(input(''))

num=list(map(int,input('').split()))

sum=0
count=0
for i in range(n):
    if num[i]==1:
        count=count+1
    else:
        count=0

    sum=sum+count

print(sum)