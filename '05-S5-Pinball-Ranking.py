from __future__ import division
import bisect
import sys
raw_input = sys.stdin.readline

def update(tree,i,v,N):
  while i <= N:
    tree[i] += v
    i += i&(-i)

def getsum(tree,i):
  ans = 0
  while i > 0:
    ans += tree[i]
    i -= i&(-i)
  return ans

N = input()
array = []
for i in range(N):
  array.append(int(raw_input()))
array2 = [x for x in array]
array2 = sorted(array2)
for i in range(N):
  array[i] = bisect.bisect_left(array2,array[i])+1
tree = [0 for x in range(N+1)]
ans = 0
for i in range(N-1,-1,-1):
  ans += getsum(tree,array[i]-1)
  update(tree,array[i],1,N)
print (round((ans+N)/N,2))
