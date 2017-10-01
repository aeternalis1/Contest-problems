import sys
raw_input = sys.stdin.readline
n = int(raw_input())
paths = [[] for x in range(n)]
paths2 = [[] for x in range(n)]
answers = [0 for x in range(n)]

while True:
  n1,n2 = map(int,raw_input().split())
  if n1 == 0 and n2 == 0:
    break
  paths[n1-1].append(n2-1)
  paths2[n2-1].append(n1-1) #predecessor slides
  
queue = [0]
answers[0] = 1

while len(queue) > 0:
  c = queue.pop(0)
  for i in paths[c]:
    answers[i] += answers[c]
    paths2[i].remove(c)
    if len(paths2[i]) == 0 and i != n-1:
      queue.append(i)
      
print (answers[n-1])
