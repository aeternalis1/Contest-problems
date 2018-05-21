t = int(input()) #number of test cases

def path(x,y,count): #y controls what column you are on, x controls which row you are on (ik it's flipped, but i screwed up)
  count += 1 
  checked[x][y] = count
  if checked[r-1][c-1] == c+r-1:
    return
  if grid[x][y] == '+':
    if x < r-1:
      if checked[x+1][y] == 0 and grid[x+1][y] != '*' or checked[x+1][y] > count and grid[x+1][y] != '*': #moving down
        path(x+1,y,count)
    if y < c-1:
      if checked[x][y+1] == 0 and grid[x][y+1] != '*' or checked[x][y+1] > count and grid[x][y+1] != '*': #moving right
        path(x,y+1,count)
    if x > 0:
      if checked[x-1][y] == 0 and grid[x-1][y] != '*' or checked[x-1][y] > count and grid[x-1][y] != '*':
        path(x-1,y,count)
    if y > 0:
      if checked[x][y-1] == 0 and grid[x][y-1] != '*' or checked[x][y-1] > count and grid[x][y-1] != '*':
        path(x,y-1,count)
  if grid[x][y] == '-':
    if y < c-1:
      if checked[x][y+1] == 0 and grid[x][y+1] != '*' or checked[x][y+1] > count and grid[x][y+1] != '*':
        path(x,y+1,count)
    if y > 0:
      if checked[x][y-1] == 0 and grid[x][y-1] != '*' or checked[x][y-1] > count and grid[x][y-1] != '*':
        path(x,y-1,count)
  if grid[x][y] == '|':
    if x < r-1:
      if checked[x+1][y] == 0 and grid[x+1][y] != '*' or checked[x+1][y] > count and grid[x+1][y] != '*':
        path(x+1,y,count)
    if x > 0:
      if checked[x-1][y] == 0 and grid[x-1][y] != '*' or checked[x-1][y] > count and grid[x-1][y] != '*':
        path(x-1,y,count)

for i in range(t):
  r = int(input()) #number of rows (maximum y value)
  c = int(input()) #numbere of columns (maximum x value)
  grid = []
  checked = []
  for j in range(r):
    row = input()
    grid.append(row)
    row = []
    for k in range(c):
      row.append(0)
    checked.append(row)
  checked[0][0] = 1
  path(0,0,0)
  
  if checked[r-1][c-1] != 0:
    print (checked[r-1][c-1])
  else:
    print (-1)
