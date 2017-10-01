dist = int(input())
n = int(input())
clubs = [int(input().strip()) for x in range(n)]
dp = [10000 for x in range(dist+1)]
dp[0] = 0
for i in range(dist):
  for j in range(n):
    if clubs[j] + i <= dist:
      dp[i+clubs[j]] = min(dp[i+clubs[j]],dp[i]+1)
      
if dp[-1] != 10000:
  print ("Roberta wins in",dp[-1],"strokes.")
else:
  print ("Roberta acknowledges defeat.")
