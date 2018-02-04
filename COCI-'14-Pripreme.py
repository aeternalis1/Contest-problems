N = int(raw_input())
nums = list(map(int,raw_input().split()))
if max(nums)<=sum(nums)/2:
    print sum(nums)
else:
    print max(nums)*2
