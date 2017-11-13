import sys
raw_input = sys.stdin.readline
N,M,K = map(int,raw_input().split())
nums = [0 for x in range(M+1)]
dp = [0 for x in range(K+1)] #maximum value for number of divisions/removals
total = 0
for i in range(N):
  nums[int(raw_input())] += 1
for i in range(1,M+1):
  total += (nums[i]+1)*nums[i]/2
  
def val(num,div):
  a = num/div
  b = num%div
  return ((a+2)*(a+1)/2)*b+((a+1)*a/2)*(div-b)

for i in range(1,M+1):
  if nums[i]:
    subsum = (nums[i]+1)*nums[i]/2
    for j in range(K-1,-1,-1): #j amount of divisions (for dp)
      for k in range(1,K-j+1): #k amount of divisions (for current consideration)
        curr = val(nums[i],k+1)
        if dp[j+k] < dp[j]+(subsum-curr):
          dp[j+k] = dp[j]+(subsum-curr)
        if nums[i]==k:
          break
print total-max(dp)
