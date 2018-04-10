N = int(raw_input())
nums = list(map(int,raw_input().split()))
nums2 = list(map(int,raw_input().split()))
nums3 = list(map(int,raw_input().split()))
inds = [0 for x in range(N+1)]
cnt = [0 for x in range(N+1)]
cnt2 = [0 for x in range(N+1)]
for i in range(N):
  inds[nums[i]] = i
  cnt[nums2[i]] += 1
  cnt2[nums3[i]] += 1
queue = []
checked = [0 for x in range(N+1)]
for i in range(1,N+1):
  if not cnt[i] or not cnt2[i]:
    checked[i] = True
    queue.append(i)
ans = 0
while queue:
  c = queue.pop(0)
  ind = inds[c]
  ans += 1
  cnt[nums2[ind]] -= 1
  cnt2[nums3[ind]] -= 1
  if not cnt[nums2[ind]] and not checked[nums2[ind]]:
    checked[nums2[ind]] = True
    queue.append(nums2[ind])
  if not cnt2[nums3[ind]] and not checked[nums3[ind]]:
    checked[nums3[ind]] = True
    queue.append(nums3[ind])
print ans
