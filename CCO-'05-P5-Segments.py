N = int(raw_input())
seg = []
dp = [[0,0] for x in range(N)]
for i in range(N):
  seg.append(list(map(int,raw_input().split())))

dp[0] = [seg[0][1]-1+(seg[0][1]-seg[0][0]),seg[0][1]-1]

for i in range(1,N):
  dp[i][1] = min(abs(seg[i-1][1]-seg[i][0])+seg[i][1]-seg[i][0]+dp[i-1][1],abs(seg[i-1][0]-seg[i][0])+seg[i][1]-seg[i][0]+dp[i-1][0])
  dp[i][0] = min(abs(seg[i-1][0]-seg[i][1])+seg[i][1]-seg[i][0]+dp[i-1][0],abs(seg[i-1][1]-seg[i][1])+seg[i][1]-seg[i][0]+dp[i-1][1])
  dp[i][1],dp[i][0] = min(dp[i][1],dp[i][0]+seg[i][1]-seg[i][0]),min(dp[i][0],dp[i][1]+seg[i][1]-seg[i][0])

print min(dp[N-1][0]+abs(N-seg[N-1][0]),dp[N-1][1]+(N-seg[N-1][1])) + N-1
