import sys
raw_input = sys.stdin.readline
n,m = map(int,raw_input().split())
paths = [[] for x in range(n)]
for i in range(m):
  a,b,c = map(int,raw_input().split())
  paths[a].append([b,c])
dp = [[-1 for x in range(n)] for x in range(1<<n)] #current city, bits and crap

def solve(cur,bit,n):
  if cur == n-1:
    return 0
  if dp[bit][cur] != -1:
    return dp[bit][cur]
  res = -99999999
  for i in paths[cur]:
    if not bit&1<<i[0]:
      res = max(res,solve(i[0],bit|(1<<i[0]),n)+i[1])
  dp[bit][cur] = res
  return res

print solve(0,1,n)
