import sys
raw_input = sys.stdin.readline

R,C = map(int,raw_input().split()) #rows and columns
grid = []
checked = []
queue = []
queue2 = []

for i in range(R):
  row = list(raw_input())
  row2 = []
  if 'D' in row or 'S' in row or '*' in row:
    for j in range(C):
      if row[j] == 'D':
        endy,endx = i,j
      elif row[j] == 'S':
        queue2.append([i,j])
      elif row[j] == '*':
        queue.append([i,j]) #this queue will be for water
  for j in range(C):
    row2.append(False)
  grid.append(row)
  checked.append(row2)

while len(queue2)>0:
  for i in range(len(queue)): #move water to adjacent blocks
    current = queue.pop(0)
    y = current[0]
    x = current[1]
    if x > 0:
      if grid[y][x-1] == '.':
        grid[y][x-1] = '*'
        queue.append([y,x-1])
    if x < C-1:
      if grid[y][x+1] == '.':
        grid[y][x+1] = '*'
        queue.append([y,x+1])
    if y > 0:
      if grid[y-1][x] == '.':
        grid[y-1][x] = '*'
        queue.append([y-1,x])
    if y < R-1:
      if grid[y+1][x] == '.':
        grid[y+1][x] = '*'
        queue.append([y+1,x])
  for i in range(len(queue2)):
    current = queue2.pop(0)
    y = current[0]
    x = current[1]
    if y == endy and x == endx:
      break
    if x > 0:
      if grid[y][x-1] != 'X' and grid[y][x-1] != '*' and checked[y][x-1] == False:
        checked[y][x-1] = checked[y][x] + 1
        queue2.append([y,x-1])
    if x < C-1:
      if grid[y][x+1] != 'X' and grid[y][x+1] != '*' and checked[y][x+1] == False:
        checked[y][x+1] = checked[y][x] + 1
        queue2.append([y,x+1])
    if y > 0:
      if grid[y-1][x] != 'X' and grid[y-1][x] != '*' and checked[y-1][x] == False:
        checked[y-1][x] = checked[y][x] + 1
        queue2.append([y-1,x])
    if y < R-1:
      if grid[y+1][x] != 'X' and grid[y+1][x] != '*' and checked[y+1][x] == False:
        checked[y+1][x] = checked[y][x] + 1
        queue2.append([y+1,x])
if checked[endy][endx] == False:
  print ("KAKTUS")
else:
  print (checked[endy][endx])
