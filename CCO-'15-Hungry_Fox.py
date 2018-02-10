N,W = map(int,raw_input().split())
nums = []
for i in range(N):
  nums.append(int(raw_input()))
nums = sorted(nums)
if W > nums[0] and W < nums[-1]:
  ans1 = abs(W-nums[0])+abs(W-nums[-1])
else:
  ans1 = min(abs(W-nums[0]),abs(W-nums[-1]))+(nums[-1]-nums[0])
ans2 = abs(W-nums[0])
l = 1
r = N-1
for i in range(N-1):
  if i%2==0:
    ans2 += max(abs(nums[r]-W),nums[r]-nums[l-1])
    r -= 1
  else:
    ans2 += max(abs(nums[l]-W),nums[r+1]-nums[l])
    l += 1
l = 0
r = N-2
ans3 = abs(W-nums[-1])
for i in range(N-1):
  if i%2==1:
    ans3 += max(abs(nums[r]-W),nums[r]-nums[l-1])
    r -= 1
  else:
    ans3 += max(abs(nums[l]-W),nums[r+1]-nums[l])
    l += 1
print ans1,max(ans2,ans3)
