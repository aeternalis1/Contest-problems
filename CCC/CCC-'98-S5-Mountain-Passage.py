T = int(input()) #test cases

for i in range(T):
  n = int(input()) #side length
  grid = []
  checked = []
  for j in range(n):
    row = []
    row2 = []
    for k in range(n):
      row.append(int(input()))
      row2.append(False)
    grid.append(row)
    checked.append(row2)
    
  queue = []
  thresh = grid[0][0]
  
  if abs(grid[1][0]-grid[0][0])<=2:
    queue.append([1,0])
    if grid[1][0] > thresh:
      checked[1][0] = 1
  if abs(grid[0][1]-grid[0][0])<=2:
    queue.append([0,1])
    if grid[0][1] > thresh:
      checked[0][1] = 1
  while len(queue)>0:
    if checked[n-1][n-1] != False:
      break
    current = queue.pop(0)
    y,x = current[0],current[1]
    if y > 0:
      if abs(grid[y-1][x]-grid[y][x])<=2 and checked[y-1][x] == False:
        if [y-1,x] not in queue:
          queue.append([y-1,x])
          if grid[y-1][x] > thresh or grid[y][x] > thresh:
            checked[y-1][x] = checked[y][x] + 1
          else:
            checked[y-1][x] = checked[y][x]
    if y < n-1:
      if abs(grid[y+1][x]-grid[y][x])<=2 and checked[y+1][x] == False:
        if [y+1,x] not in queue:
          queue.append([y+1,x])
          if grid[y+1][x] > thresh or grid[y][x] > thresh:
            checked[y+1][x] = checked[y][x] + 1
          else:
            checked[y+1][x] = checked[y][x]
    if x > 0:
      if abs(grid[y][x-1]-grid[y][x])<=2 and checked[y][x-1] == False:
        if [y,x-1] not in queue:
          queue.append([y,x-1])
          if grid[y][x-1] > thresh or grid[y][x] > thresh:
            checked[y][x-1] = checked[y][x] + 1
          else:
            checked[y][x-1] = checked[y][x]
    if x < n-1:
      if abs(grid[y][x+1]-grid[y][x])<=2 and checked[y][x+1] == False:
        if [y,x+1] not in queue:
          queue.append([y,x+1])
          if grid[y][x+1] > thresh or grid[y][x] > thresh:
            checked[y][x+1] = checked[y][x] + 1
          else:
            checked[y][x+1] = checked[y][x]
  if checked[n-1][n-1] == False:
    if i > 0:
      print ("")
    print ("CANNOT MAKE THE TRIP")
  else:
    if i > 0:
      print ("")
    print (checked[n-1][n-1])
