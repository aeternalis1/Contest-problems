n = input()
for i in range(n):
  r = input()
  c = input()
  pr = r-input()
  pc = input()-1
  kr = r-input()
  kc = input()-1
  win = False
  stale = -1
  board = [[10000 for x in range(c)] for x in range(r)]
  board[kr][kc] = 0
  queue = [[kr,kc]]
  while queue:
    y,x = queue.pop(0)
    if y > 0 and x > 1:
      if board[y-1][x-2] > board[y][x] + 1:
        board[y-1][x-2] = board[y][x] + 1
        queue.append([y-1,x-2])
    if y > 1 and x > 0:
      if board[y-2][x-1] > board[y][x] + 1:
        board[y-2][x-1] = board[y][x] + 1
        queue.append([y-2,x-1])
    if y > 0 and x < c-2:
      if board[y-1][x+2] > board[y][x] + 1:
        board[y-1][x+2] = board[y][x] + 1
        queue.append([y-1,x+2])
    if y > 1 and x < c-1:
      if board[y-2][x+1] > board[y][x] + 1:
        board[y-2][x+1] = board[y][x] + 1
        queue.append([y-2,x+1])
    if y < r-1 and x > 1:
      if board[y+1][x-2] > board[y][x] + 1:
        board[y+1][x-2] = board[y][x] + 1
        queue.append([y+1,x-2])
    if y < r-2 and x > 0:
      if board[y+2][x-1] > board[y][x] + 1:
        board[y+2][x-1] = board[y][x] + 1
        queue.append([y+1,x-1])
    if y < r-1 and x < c-2:
      if board[y+1][x+2] > board[y][x] + 1:
        board[y+1][x+2] = board[y][x] + 1
        queue.append([y+1,x+2])
    if y < r-2 and x < c-1:
      if board[y+2][x+1] > board[y][x] + 1:
        board[y+2][x+1] = board[y][x] + 1
        queue.append([y+2,x+1])
  for j in range(pr):
    if board[pr-j][pc] == j or (j-board[pr-j][pc])%2 == 0 and board[pr-j][pc] < j:
      win = j
      break
    elif board[pr-j-1][pc] == j and stale == -1:
      stale = j
      if j == 2:
        print (pr,pc,kr,kc)
  if win:
    print "Win in",win,"knight move(s)."
  elif stale != -1:
    print "Stalemate in",stale,"knight move(s)."
  else:
    print "Loss in",j,"knight move(s)."
