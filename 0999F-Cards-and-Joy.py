n,k = map(int,raw_input().split())
nums = list(map(int,raw_input().split()))
cnt = [0 for x in range(100001)]
cnt2 = [0 for x in range(100001)]
favs = list(map(int,raw_input().split()))
vals = [0]+list(map(int,raw_input().split()))
for i in nums:
  cnt[i] += 1
for i in favs:
  cnt2[i] += 1
ans = 0
for i in set(nums):
  if cnt2[i]:
    N = min(cnt2[i]*k,cnt[i])+1
    dp = [[0 for x in range(N)] for x in range(cnt2[i]+1)]
    for m in range(1,cnt2[i]+1):
      for j in range(N-1,-1,-1):
        for l in range(1,k+1):
          if l+j>=N:
            break
          if vals[l]+dp[m-1][j] > dp[m][j+l]:
            dp[m][j+l] = vals[l]+dp[m-1][j]
    ans += max(dp[cnt2[i]])
print ans
