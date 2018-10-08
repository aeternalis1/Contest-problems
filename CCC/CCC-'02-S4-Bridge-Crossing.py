import sys
raw_input = sys.stdin.readline
M = input()
Q = input()
names = []
times = []
for i in range(Q):
  names.append(raw_input().strip('\n'))
  times.append(input())

dp = [[10000] for x in range(Q+1)]
dp[0][0] = 0
for i in range(Q+1):
  for j in range(1,M+1):
    if j + i > Q:
      continue
    if max(times[i:i+j]) + dp[i][0] < dp[i+j][0]:
      dp[i+j] = [x for x in dp[i]]
      dp[i+j][0] += max(times[i:i+j])
      dp[i+j].append(names[i:i+j])

print "Total Time:",dp[Q][0]
for i in range(1,len(dp[Q])):
  print ' '.join(dp[Q][i])
