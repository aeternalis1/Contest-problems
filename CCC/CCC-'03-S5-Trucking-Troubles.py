import sys
raw_input = sys.stdin.readline

c,r,d = map(int,raw_input().split()) #cities, roads, destinations
dists = [[] for x in range(c)]
bridges = [[] for x in range(c)]
dests = []
answers = [0 for x in range(c)]
ans = 10000000

for i in range(r):
  c1,c2,w = map(int,raw_input().split())
  bridges[c1-1].append(c2-1)
  bridges[c2-1].append(c1-1)
  dists[c1-1].append(w)
  dists[c2-1].append(w)

for i in range(d):
  dests.append(int(raw_input())-1)
  
queue = [x for x in bridges[0]]

for i in range(len(bridges[0])):
  answers[bridges[0][i]] = dists[0][i]
  
while len(queue):
  c2 = queue.pop(0)
  for i in range(len(bridges[c2])):
    if min(dists[c2][i],answers[c2]) > answers[bridges[c2][i]] and bridges[c2][i] != 0: 
      answers[bridges[c2][i]] = dists[c2][i]
      queue.append(bridges[c2][i])

for i in dests:
  if answers[i] < ans:
    ans = answers[i]

print (ans)
