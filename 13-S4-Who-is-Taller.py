import sys
raw_input = sys.stdin.readline

N,M = map(int,raw_input().split()) #amount of people in class, amount of connections
links = []

def checker(p1,p2,N):
  checked = []
  for i in range(N):
    checked.append(False)
  queue = []
  for i in links[p1]:
    queue.append(i)
  while len(queue) > 0:
    current = queue.pop(0)
    if current == p2:
      return True
    elif not checked[current]:
      checked[current] = True
      for i in links[current]:
        queue.append(i)
  return False
  
for i in range(N):
  links.append([])

for i in range(M):
  p1,p2 = map(int,raw_input().split())
  links[p1-1].append(p2-1) #everyone in p1's list is shorter than p1
  
p1,p2 = map(int,raw_input().split())

if checker(p2-1,p1-1,N):
  print ("no")
elif checker(p1-1,p2-1,N):
  print ("yes")
else:
  print ("unknown")
