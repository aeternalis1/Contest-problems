from copy import deepcopy
import sys
raw_input = sys.stdin.readline
T,N = map(int,raw_input().split())
breaks = list(map(int,raw_input().split()))
output = [0 for x in range(N)]
sums = [[0]]
checked = [False for x in range(T+1)]
greatest = 0
for i in range(N):
  for j in range(len(sums)):
    if sums[j][0] + breaks[i] <= T:
      if not checked[sums[j][0]+breaks[i]]:
        temp = deepcopy(sums[j])
        temp[0] += breaks[i]
        temp.append(i)
        checked[temp[0]] = True
        if temp[0] > greatest:
          greatest = temp[0]
        sums.append(temp)
for i in sums:
  if i[0] == greatest:
    inds = deepcopy(i)
    inds.pop(0)
    break
cur = 0
checked = [False for x in range(N)]
for i in inds:
  output[i] = cur
  cur += breaks[i]
  checked[i] = True
cur = 0
for i in range(N):
  if not checked[i]:
    output[i] = cur
    cur += breaks[i]
print (" ".join([str(x) for x in output]))
