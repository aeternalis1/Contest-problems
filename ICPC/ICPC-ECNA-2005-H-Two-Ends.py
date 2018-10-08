def solve(l,r):
  if l>=r:
    return 0
  elif dp[l][r]:
    return dp[l][r]
  else:
    if nums[r] > nums[l+1]:
      ans = solve(l+1,r-1)+nums[l]
    else:
      ans = solve(l+2,r)+nums[l]
    if nums[l] >= nums[r-1]:
      ans = max(ans,solve(l+1,r-1)+nums[r])
    else:
      ans = max(ans,solve(l,r-2)+nums[r])
    dp[l][r] = ans
    return ans
cnt = 0
while True:
  cnt += 1
  nums = list(map(int,raw_input().split()))
  if nums == [0]:
    break
  n = nums.pop(0)
  dp = [[0 for x in range(n)] for x in range(n)]
  print "In game "+str(cnt)+", the greedy strategy might lose by as many as",solve(0,n-1)-(sum(nums)-solve(0,n-1)),"points."
