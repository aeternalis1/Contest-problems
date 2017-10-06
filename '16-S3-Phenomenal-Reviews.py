import sys
sys.setrecursionlimit(100000000)
raw_input = sys.stdin.readline
N,M = map(int,raw_input().split())
pho = list(map(int,raw_input().split()))
phos = [False for x in range(N)]
leaves = [True for x in range(N)]
paths = [[] for x in range(N)]
nodes = [False for x in range(N)]
total = 0
ind = [x for x in range(N)]
dists = [1 for x in range(N)]
maxdist = 0
def mark(curr,prev):
  if phos[curr] and not nodes[curr]:
    nodes[curr] = True
    global total
    total +=2
  for i in paths[curr]:
    if i != prev:
      mark(i,curr)
      if nodes[i] and not nodes[curr]:
        nodes[curr] = True
        global total
        total += 2

def dfs(curr,prev,dist):
  for i in paths[curr]:
    if i != prev and nodes[i]:
      dfs(i,curr,dist+1)
      if dists[i]+1 > dists[curr]:
        dists[curr] = dists[i]+1
        ind[curr] = ind[i]

def dfs2(curr,prev,dist):
  global maxdist
  if dist > maxdist:
    maxdist = dist
  for i in paths[curr]:
    if i != prev and nodes[i]:
      dfs2(i,curr,dist+1)

for i in range(M):
  phos[pho[i]] = True
for i in range(N-1):
  a,b = map(int,raw_input().split())
  paths[a].append(b)
  paths[b].append(a)
mark(pho[0],-1)
dfs(pho[0],-1,0)
dfs2(ind[pho[0]],-1,0)
total -= 2
print total-maxdist
