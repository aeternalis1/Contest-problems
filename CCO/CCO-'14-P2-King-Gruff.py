#credit to benjamin li's github (github.com/benjaminbli), which has a very nice explanation on how to solve this problem
from bisect import bisect_right
import sys
raw_input = sys.stdin.readline
N,M,A,B = map(int,raw_input().split())
A,B = A-1,B-1
paths = [[] for x in range(N)]
paths2 = [[] for x in range(N)]
edges = []
costs = []
ans1 = [999999999999 for x in range(N)]
ans2 = [999999999999 for x in range(N)]
for i in range(M):
  a,b,c,d = map(int,raw_input().split())
  paths[a-1].append([b-1,c])
  paths2[b-1].append([a-1,c])
  edges.append([a-1,b-1,c])
  costs.append(d)

checked = [False for x in range(N)]
queue = [A]
ans1[A] = 0
while queue:
  c = queue.pop(0)
  checked[c] = False
  for i in paths[c]:
    if ans1[i[0]]>ans1[c]+i[1]:
      ans1[i[0]] = ans1[c]+i[1]
      if not checked[i[0]]:
        queue.append(i[0])
        checked[i[0]] = True

checked = [False for x in range(N)]
queue = [B]
ans2[B] = 0
while queue:
  c = queue.pop(0)
  checked[c] = False
  for i in paths2[c]:
    if ans2[i[0]]>ans2[c]+i[1]:
      ans2[i[0]] = ans2[c]+i[1]
      if not checked[i[0]]:
        queue.append(i[0])
        checked[i[0]] = True
dists = []
for i in edges:
  dists.append(ans1[i[0]]+ans2[i[1]]+i[2])
dists,costs = list(zip(*sorted(zip(dists,costs))))
dists = [0]+list(dists)
costs = [0]+list(costs)
for i in range(2,M+1):
  costs[i] += costs[i-1]
Q = int(raw_input())
for i in range(Q):
  q = int(raw_input())
  print costs[bisect_right(dists,q)-1]
