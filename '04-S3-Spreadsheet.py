import sys
grid = []
grid2 = [[-1 for x in range(9)] for x in range(10)]
lets = "ABCDEFGHIJ"
for i in range(10):
  grid.append(raw_input().split())
for i in range(10):
  for j in range(9):
    try:
      grid2[i][j] = int(grid[i][j])
    except:
      None
    if lets[i]+str(j+1) in grid[i][j]: #undefined
      grid2[i][j] = -2
checked = [[0 for x in range(9)] for x in range(10)]
def solve(i,j):
  if checked[i][j]:
    grid2[i][j] = -2
    return -9999999999
  checked[i][j] = True
  nums = grid[i][j].split('+')
  res = 0
  for k in nums:
    a,b = lets.index(k[0]),int(k[1])-1
    if grid2[a][b] >= 0:
      res += grid2[a][b]
    elif grid2[a][b] == -1:
      res += solve(a,b)
    else:
      res -= 9999999999
  grid2[i][j] = res
  return res

for i in range(10):
  for j in range(9):
    if grid2[i][j] == -1:
      solve(i,j)

for i in range(10):
  for j in range(9):
    if grid2[i][j] < 0:
      grid2[i][j] = '*'
    else:
      grid2[i][j] = str(grid2[i][j])
for i in range(10):
  print " ".join(grid2[i])  
