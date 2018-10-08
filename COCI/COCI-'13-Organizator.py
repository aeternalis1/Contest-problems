import sys
raw_input = sys.stdin.readline
N = int(raw_input())
clubs = list(map(int,raw_input().split()))
nums = [0 for x in range(2000001)]

for i in range(N):
  nums[clubs[i]] += 1
 
ans = 0
for i in range(1,2000001):
  res = 0
  j = 1
  while j*i < 2000001:
    res += nums[j*i]
    j += 1
  if res > 1:
    ans = max(res*i,ans)

print (ans)
