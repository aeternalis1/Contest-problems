roads = {}
paths = []
lets = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
while True:
  road = raw_input()
  if road == '**':
    break
  try:
    roads[road[0]].append(road[1])
  except:
    roads[road[0]] = [road[1]]
  try:
    roads[road[1]].append(road[0])
  except:
    roads[road[1]] = [road[0]]
  paths.append(road)
ans = []
for i in range(len(paths)):
  queue = ['A']
  checked = {}
  for j in range(26):
    checked[lets[j]] = False
  checked['A'] = True
  found = False
  curr = paths[i]
  while queue and not found:
    c = queue.pop(0)
    for j in roads[c]:
      if not checked[j] and c+j!=curr and j+c != curr:
        queue.append(j)
        checked[j] = True
        if j=='B':
          found = True
          break
  if not found:
    ans.append(curr)
for i in ans:
  print i
print "There are",len(ans),"disconnecting roads."
