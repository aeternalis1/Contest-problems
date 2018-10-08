import sys
raw_input = sys.stdin.readline

f = int(raw_input()) #amount of flooring
r = int(raw_input()) #rows
c = int(raw_input()) #columns
room = []
checked = []
row = []
rooms = []
total = 0

def bfs(y,x):
  queue = []
  current = []
  area = 1
  if y < r-1:
    if room[y+1][x] == '.' and checked[y+1][x] == 0:
      checked[y+1][x] = 1
      area += 1
      queue.append([y+1,x])
  if y > 0:
    if room[y-1][x] == '.' and checked[y-1][x] == 0:
      checked[y-1][x] = 1
      area += 1
      queue.append([y-1,x])
  if x < c-1:
    if room[y][x+1] == '.' and checked[y][x+1] == 0:
      checked[y][x+1] = 1
      area += 1
      queue.append([y,x+1])
  if x > 0:
    if room[y][x-1] == '.' and checked[y][x-1] == 0:
      checked[y][x-1] = 1
      area += 1
      queue.append([y,x-1])
    
  while len(queue)>0:
    current = queue.pop(0)
    if current[1] > 0 and checked[current[0]][current[1]-1] == 0 and room[current[0]][current[1]-1] == '.':
      area += 1
      checked[current[0]][current[1]-1] = 1
      queue.append([current[0],current[1]-1])
    if current[1] < c-1 and checked[current[0]][current[1]+1] == 0 and room[current[0]][current[1]+1] == '.':
      area += 1
      checked[current[0]][current[1]+1] = 1
      queue.append([current[0],current[1]+1])
    if current[0] > 0 and checked[current[0]-1][current[1]] == 0 and room[current[0]-1][current[1]] == '.':
      area += 1
      checked[current[0]-1][current[1]] = 1
      queue.append([current[0]-1,current[1]])
    if current[0] < r-1 and checked[current[0]+1][current[1]] == 0 and room[current[0]+1][current[1]] == '.':
      area += 1
      checked[current[0]+1][current[1]] = 1
      queue.append([current[0]+1,current[1]])
  return area
  
  
for i in range(r):
  row = []
  room.append(raw_input())
  for i in range(c):
    row.append(0)
  checked.append(row)
  
for i in range(r):
  for j in range(c):
    if checked[i][j] == 0 and room[i][j] == '.': #if the point found hasnt been checked before(is a new room)
      checked[i][j] = 1
      rooms.append(bfs(i,j))
      
rooms.sort()

for i in range(1,len(rooms)+1):
  if rooms[-i] <= f:
    total += 1
    f -= rooms[-i]
  else:
    break

if total == 1:
  print ("1 room, "+str(f)+" square metre(s) left over")
else:
  print (str(total)+" rooms, "+str(f)+" square metre(s) left over")
