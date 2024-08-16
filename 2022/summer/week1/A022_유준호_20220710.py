N = int(input()) # 저번 달에 이용한 통화의 개수
arr = list(map(int, input().split())) # 통화 시간 N개

ys = 0 # 영수의 요금제
ms = 0 # 민식의 요금제

for a in arr:
  ys += ((a//30)+1)*10
  ms += ((a//60)+1)*15

if ys>ms: # 출력문
  print("M", ms)
elif ys<ms:
  print("Y", ys)
else:
  print("Y M", ys)