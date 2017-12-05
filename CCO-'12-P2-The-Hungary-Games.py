import sys
raw_input = sys.stdin.readline
N,M = map(int,raw_input().split())
paths = [[] for x in range(N)]
for i in range(M):
  a,b,c = map(int,raw_input().split())
  paths[a-1].append([b-1,c])

queue = [0]
ans = [[999999999,999999999] for x in range(N)]
ans[0] = [0,999999999]
checked = [False for x in range(N)]
while queue:
  c = queue.pop(0)
  checked[c] = False
  for i in paths[c]:
    b,d = i #next node, dist
    if ans[c][0] + d < ans[b][0]:
      ans[b][1] = ans[b][0]
      ans[b][0] = ans[c][0]+d
      if not checked[b]:
        queue.append(b)
        checked[b] = True
    elif ans[c][0] + d < ans[b][1] and ans[c][0]+d != ans[b][0]:
      ans[b][1] = ans[c][0]+d
      if not checked[b]:
        queue.append(b)
        checked[b] = True
    if ans[c][1] + d < ans[b][1] and ans[c][1]+d != ans[b][0]:
      ans[b][1] = ans[c][1]+d
      if not checked[b]:
        queue.append(b)
        checked[b] = True
if ans[N-1][1] == 999999999:
  print -1
else:
  print ans[N-1][1]
