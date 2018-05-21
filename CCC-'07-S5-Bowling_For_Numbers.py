import sys
raw_input = sys.stdin.readline
T = int(raw_input())
for _ in range(T):
  N,n,w = map(int,raw_input().split())
  pins = [0]
  for i in range(N):
    pins.append(int(raw_input()))
  dp = [[0 for x in range(N+1)] for x in range(n+1)]
  for i in range(1,n+1):
    cur = 0
    for j in range(1,N+1):
      if j < w+1:
        cur += pins[j]
        dp[i][j] = cur
      else:
        cur += pins[j]-pins[j-w]
        dp[i][j] = max(dp[i-1][j-w]+cur,dp[i][j-1])
  print dp[n][N]

#dp state is essentially to collect the max number of points achievable by throwing balls up to index j, assuming you will never again throw a ball that hits a pin left of index j
