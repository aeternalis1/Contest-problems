import sys
raw_input = sys.stdin.readline
R,C = map(int,raw_input().split())
grid = [[9999999999 for x in range(C)] for x in range(R)]
def sqr(n):
  return n*n
for i in range(R):
  row = list(raw_input())
  for j in range(C):
    if row[j] == 'x':
      grid[i][j] = 0
      for k in range(1,C-j):
        if grid[i][j+k] > k:
          grid[i][j+k] = k
        else:
          break
      for k in range(j-1,-1,-1):
        if grid[i][k] > j-k:
          grid[i][k] = j-k
        else:
          break
Q = int(raw_input())
for i in range(Q):
  y,x = map(int,raw_input().split())
  x,y = x-1, y-1
  ans = 9999999999
  for j in range(R):
    if grid[j][x] != 9999999999:
      if sqr(y-j)+sqr(grid[j][x]) < ans:
        ans = sqr(y-j)+sqr(grid[j][x])
        if ans == 0:
            break
  grid[y][x] = 0
  for k in range(1,C-x):
    if grid[y][x+k] > k:
      grid[y][x+k] = k
    else:
      break
  for k in range(x-1,-1,-1):
    if grid[y][k] > x-k:
      grid[y][k] = x-k
    else:
      break
  print ans
