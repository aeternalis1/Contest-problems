T = int(raw_input())
N = int(raw_input())
items = [[] for x in range(T)]
for i in range(N):
  a,b,c = map(int,raw_input().split()) #cost then value
  items[c-1].append([a,b])
B = int(raw_input())
dp = [0 for x in range(B+1)]
added = 0
ans = 0
for i in range(T):
  for k in range(B,-1,-1):
    for j in range(len(items[i])):
      if k + items[i][j][0] <= B:
        if k == 0 and i == 0 or dp[k] != 0 and dp[k] + items[i][j][1] > dp[k+items[i][j][0]]:
          dp[k+items[i][j][0]] = dp[k]+items[i][j][1]
          if added == i:
            added += 1
if added < T:
  print -1
else:
  for i in range(B+1):
    if dp[i] > ans:
      ans = dp[i]
  print ans
