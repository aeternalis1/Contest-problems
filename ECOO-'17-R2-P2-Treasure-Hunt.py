for _ in range(10):
  N = int(raw_input())
  grid = []
  for i in range(N):
    grid.append(list(raw_input()))
    for j in range(N):
      if grid[i][j]=='S':
        sy = i
        sx = j
  queue = [[sy,sx]]
  doors = []
  keys = 0
  ans = 0
  checked = [[0 for x in range(N)] for x in range(N)]
  checked[sy][sx] = 1
  while queue:
    while queue:
      y,x = queue.pop(0)
      if y > 0:
        if not checked[y-1][x]:
          if grid[y-1][x] == 'T':
            ans += 1
            queue.append([y-1,x])
          elif grid[y-1][x] == 'K':
            keys += 1
            queue.append([y-1,x])
          elif ord(grid[y-1][x]) >= ord('1') and ord(grid[y-1][x]) <= ord('9'):
            doors.append([y-1,x,int(grid[y-1][x])])
          elif grid[y-1][x] == '.':
            queue.append([y-1,x])
          checked[y-1][x] = True
      if y < N-1:
        if not checked[y+1][x]:
          if grid[y+1][x] == 'T':
            ans += 1
            queue.append([y+1,x])
          elif grid[y+1][x] == 'K':
            keys += 1
            queue.append([y+1,x])
          elif ord(grid[y+1][x]) >= ord('1') and ord(grid[y+1][x]) <= ord('9'):
            doors.append([y+1,x,int(grid[y+1][x])])
          elif grid[y+1][x] == '.':
            queue.append([y+1,x])
          checked[y+1][x] = True
      if x > 0:
        if not checked[y][x-1]:
          if grid[y][x-1] == 'T':
            ans += 1
            queue.append([y,x-1])
          elif grid[y][x-1] == 'K':
            keys += 1
            queue.append([y,x-1])
          elif ord(grid[y][x-1]) >= ord('1') and ord(grid[y][x-1]) <= ord('9'):
            doors.append([y,x-1,int(grid[y][x-1])])
          elif grid[y][x-1] == '.':
            queue.append([y,x-1])
          checked[y][x-1] = True
      if x < N-1:
        if not checked[y][x+1]:
          if grid[y][x+1] == 'T':
            ans += 1
            queue.append([y,x+1])
          elif grid[y][x+1] == 'K':
            keys += 1
            queue.append([y,x+1])
          elif ord(grid[y][x+1]) >= ord('1') and ord(grid[y][x+1]) <= ord('9'):
            doors.append([y,x+1,int(grid[y][x+1])])
          elif grid[y][x+1] == '.':
            queue.append([y,x+1])
          checked[y][x+1] = True
    for i in doors:
      if keys >= i[2]:
        doors.remove(i)
        queue.append([i[0],i[1]])
  print ans
