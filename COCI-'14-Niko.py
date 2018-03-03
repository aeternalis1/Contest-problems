N = int(raw_input())
forms = []
for i in range(N):
  forms.append(list(map(int,raw_input().split('-'))))
M = int(raw_input())
chars = "OVN"
paths = [[] for x in range(M)]
for i in range(M):
  q = raw_input()
  if len(q) == 1:
    paths[i].append(chars.find(q))
  else:
    for j in range(len(q)):
      paths[i].append(chars.find(q[j]))
      
def dfs(i,form):
  for j in paths[i]:
    for k in range(form[j]):
      if not checked[j][k]:
        checked[j][k] = True
        if taken[j][k] == -1:
          taken[j][k] = i
          return True
        elif dfs(taken[j][k],form):
          taken[j][k] = i
          return True

for i in forms:
  taken = [[],[],[]]
  taken[0] = [-1 for x in range(i[0])]
  taken[1] = [-1 for x in range(i[1])]
  taken[2] = [-1 for x in range(i[2])]
  for j in range(M):
    checked = [[0 for x in range(10)] for x in range(3)]
    dfs(j,i)
  if -1 in taken[0] or -1 in taken[1] or -1 in taken[2]:
    print "NE"
  else:
    print "DA"
