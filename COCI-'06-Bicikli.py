from collections import deque
import sys
sys.setrecursionlimit(10000000)
raw_input = sys.stdin.readline
N,M = map(int,raw_input().split())
paths = {}
answers = [0 for x in range(N)]
answers[0] = 1
for i in range(M):
  a,b = map(int,raw_input().split())
  a,b = a-1,b-1
  try:
    paths[a].append(b)
  except:
    paths[a] = [b]
    
GRAY,BLACK = 0,1

def topsort(graph):
  order, enter, state = deque(), set(graph), {}
  def dfs(node,cycle,checked):
    state[node] = GRAY
    for k in graph.get(node, ()):
      sk = state.get(k, None)
      if sk == GRAY:
        cycle = True
        if k in checked:
          continue
        else:
          checked.append(node)
          if dfs(k,cycle,checked):
            cycle = False
            checked = []
          else:
            return False
      elif sk == BLACK: 
        continue
      else:
        enter.discard(k)
        if k == 1 and cycle:
          return False
        if not dfs(k,cycle,checked):
          return False
    order.appendleft(node)
    state[node] = BLACK
    return True
  global cycle
  cycle = False
  if dfs(0,cycle,[]):
    return order
  else:
    print 'inf'
    sys.exit()
order = topsort(paths)
for i in range(len(order)):
  c = order.popleft()
  try:
    for j in paths[c]:
      answers[j] += answers[c]
  except:
    None

if len(str(answers[1])) > 9:
  print (str(answers[1])[-9:])
else:
  print (answers[1])
