from copy import deepcopy
N = int(raw_input())
dp = [0 for x in range(N)]
x = int(raw_input())
dp[0] = x
ans = x
for i in range(1,N):
  line = list(map(int,raw_input().split()))
  temp = [0 for x in range(N)]
  for j in range(i+1):
    if j==0:
      temp[0] = line[0]+dp[0]
    elif j==i:
      temp[j] = line[j]+dp[j-1]
    else:
      temp[j] = max(line[j]+dp[j-1],line[j]+dp[j])
    if temp[j] > ans:
      ans = temp[j]
  dp = deepcopy(temp)
print ans
