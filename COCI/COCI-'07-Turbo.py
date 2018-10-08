import sys
raw_input = sys.stdin.readline
N = int(raw_input())
nums = [0 for x in range(N+1)]
tree = [0 for x in range(N+1)]
def update(i,v):
  while i <= N:
    tree[i] += v
    i += i&-i
def query(i):
  ans = 0
  while i > 0:
    ans += tree[i]
    i -= i&-i
  return ans
for i in range(N):
  nums[int(raw_input())] = i+1
  update(i+1,1)
l = 1
r = N
for i in range(N):
  if i%2==0:
    update(nums[l],-1)
    ind = query(nums[l])
    print ind-query(0)
    l += 1
  else:
    update(nums[r],-1)
    ind = query(nums[r]-1)
    print query(N)-ind
    r -= 1
