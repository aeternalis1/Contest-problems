N,D = map(int,raw_input().split())
paths = [[] for x in range(N)]
col = [1 for x in range(N)]
dp = [[999999 for x in range(N*2+1)] for x in range(N)]

for i in range(N):
  dp[i][0] = 0

def dfs(cur,N):
  res = col[cur]
  if len(paths[cur])==2:
    temp = [[],[]]
    for l in range(2):
      i = paths[cur][l]
      res += dfs(i,N)
      for j in range(-N,N+1):
        if dp[i][j] != 999999:
          temp[l].append([j,dp[i][j]])
    for j in temp[0]:
      for k in temp[1]:
        dp[cur][k[0]+j[0]] = min(dp[cur][k[0]+j[0]],k[1]+j[1])
  elif len(paths[cur])==1:
    for i in paths[cur]:
      res += dfs(i,N)
      for j in range(-N,N+1):
        if dp[i][j] != 999999:
          dp[cur][j] = dp[i][j]
  dp[cur][res] = min(dp[cur][res],1)
  return res
white = N
for i in range(N):
  a,b,c = map(int,raw_input().split())
  if not b:
    col[a] = -1
    white -= 1
  for j in range(c):
    d = int(raw_input())
    paths[a].append(d)
dfs(0,N)
black = N-white
if dp[0][white-black-D]==999999:
  print -1
else:
  print dp[0][white-black-D]
#dp[cur][j] is the number of prunes to remove [j] white nodes
