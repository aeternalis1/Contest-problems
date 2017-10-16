#convert the pens to a graph, with animals as nodes and pen edges as edges between nodes. Use Kruskal's algorithm with disjoint set
#to find the MST including outside, then MST not including outside, answer is minimum of the two.

import sys
raw_input = sys.stdin.readline
M = int(raw_input())
edges = []
edges2 = {} #verifies if an edge leads to outside or to another pen; each edge should have a and b, the nodes they connect. 0 will be outside
graph = []
graph2 = []
for i in range(1,M+1):
  pen = list(map(int,raw_input().split()))
  num = pen.pop(0)
  for j in range(num):
    if j < num-1:
      try:
        edges2[(pen[j],pen[j+1])].append(i)
      except:
        try:
          edges2[(pen[j+1],pen[j])].append(i)
        except:
          edges.append([pen[j+num],pen[j],pen[j+1]])
          edges2[(pen[j],pen[j+1])] = [i]
    else:
      try:
        edges2[(pen[j],pen[0])].append(i)
      except:
        try:
          edges2[(pen[0],pen[j])].append(i)
        except:
          edges.append([pen[j+num],pen[j],pen[0]])
          edges2[(pen[j],pen[0])] = [i]
for i in edges:
  if len(edges2[(i[1],i[2])]) == 1: #connects to outside
    graph.append([i[0],edges2[(i[1],i[2])][0],0])
  else:
    graph.append([i[0]]+edges2[(i[1],i[2])])
    graph2.append([i[0]]+edges2[(i[1],i[2])])
graph.sort()
par = [x for x in range(M+1)]
rank = [0 for x in range(M+1)]

def parent(i):
  if par[i] == i:
    return i
  return parent(par[i])
  
def join(a,b):
  if rank[a] < rank[b]:
    par[a] = b
  elif rank[a] > rank[b]:
    par[b] = a
  else:
    par[b] = a
    rank[a] += 1
ans = 0
cnt = 0
for i in graph:
  c,a,b = i
  a,b = parent(a),parent(b)
  if a == b:
    continue
  else:
    cnt += 1
    ans += c
    join(a,b)
    if cnt == M:
      break
ans2 = 0
cnt = 0
graph2.sort()
par = [x for x in range(M+1)]
rank = [0 for x in range(M+1)]
for i in graph2:
  c,a,b = i
  a,b = parent(a),parent(b)
  if a==b:
    continue
  else:
    cnt += 1
    ans2 += c
    join(a,b)
    if cnt == M-1:
      break
print min(ans,ans2)
