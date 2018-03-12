n,m,p = map(int,raw_input().split())
paths = [[] for x in range(n)]
toys = [0 for x in range(m)]
cats = [[] for x in range(p+1)]
cnts = [0 for x in range(p+1)]
lims = [0 for x in range(p+1)]
lims[0] = 999999
taken = [-1 for x in range(m)]
for i in range(n):
  temp = list(map(int,raw_input().split()))
  for j in range(temp.pop(0)):
    paths[i].append(temp[j]-1)
for i in range(1,p+1):
  temp = list(map(int,raw_input().split()))
  for j in range(temp.pop(0)):
    temp[j] -= 1
    toys[temp[j]] = i
    cats[i].append(temp[j])
  lims[i] = temp[-1]
for i in range(m):
  if not toys[i]:
    cats[0].append(i)

def dfs(i):
  for j in paths[i]:
    if checked[j]:
      continue
    checked[j] = True
    if taken[j] != -1:
      if dfs(taken[j]):
        taken[j] = i
        return True
    elif cnts[toys[j]] == lims[toys[j]]:
      for k in cats[toys[j]]:
        if taken[k] != -1:
          for l in paths[taken[k]]:
            if taken[l] == -1 and cnts[toys[l]] < lims[toys[l]]:
              taken[l] = taken[k]
              taken[k] = i
              return True
            elif taken[l] != -1:
              if dfs(taken[l]):
                taken[l] = taken[k]
                taken[k] = i
                return True
    else:
      taken[j] = i
      cnts[toys[j]] += 1
      return True
  return False

for i in range(n-1,-1,-1):
  checked = [0 for x in range(m)]
  dfs(i)
ans = 0
for i in taken:
  if i != -1:
    ans += 1
print ans

#This code probably doesn't always AC, but it passes on DMOJ and I assume it also passes official data
