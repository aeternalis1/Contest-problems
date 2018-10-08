t = int(raw_input())
for _ in range(t):
  n = int(raw_input())
  adj = {}
  checked = {}
  nodes = []
  for i in range(n):
    s = raw_input()
    if i != 0:
      try:
        adj[nodes[i-1]].append(s)
      except:
        adj[nodes[i-1]] = [s]
    nodes.append(s)
    checked[s] = False
  try:
    adj[s].append(nodes[0])
  except:
    adj[s] = [nodes[0]]
  queue = [s]
  checked[s] = True
  ans = 0
  while queue:
    for i in range(len(queue)):
      c = queue.pop(0)
      for j in adj[c]:
        if not checked[j]:
          queue.append(j)
          checked[j] = True
    ans += 1
  print n*10-(ans-1)*20
