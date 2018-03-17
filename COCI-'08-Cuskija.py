from collections import deque
N = int(raw_input())
arr = list(map(int,raw_input().split()))
cnt = [0 for x in range(3)]
nums = [[] for x in range(3)]
final = deque()
for i in range(N):
  cnt[arr[i]%3] += 1
  nums[arr[i]%3].append(arr[i])

if cnt[0] > cnt[1]+cnt[2]+1 or not cnt[0] and cnt[1] and cnt[2]:
  print "impossible"
else:
  ind = N/2
  if cnt[0]:
    final.append(0)
    cnt[0] -= 1
  while cnt[0]:
    if final[-1]:
      final.append(0)
      cnt[0] -= 1
    if cnt[0] and final[0]:
      final.appendleft(0)
      cnt[0] -= 1
    if cnt[1]:
      final.appendleft(1)
      cnt[1] -= 1
    if cnt[2]:
      final.append(2)
      cnt[2] -= 1
  while cnt[1]:
    final.appendleft(1)
    cnt[1] -= 1
  while cnt[2]:
    final.append(2)
    cnt[2] -= 1
  ind1 = 0
  ind2 = 0
  ind3 = 0
  for i in range(N):
    if final[i] == 0:
      final[i] = nums[0][ind1]
      ind1 += 1
    if final[i] == 1:
      final[i] = nums[1][ind2]
      ind2 += 1
    if final[i] == 2:
      final[i] = nums[2][ind3]
      ind3 += 1
  print " ".join([str(x) for x in final])

#0's cannot be adjacent, 1's cannot be adjacent to 2's. Try to get 0's in between alternating 1's and 2's
#impossible happens when 0 cannot be padded enough or when there are no 0's to pad 1s and 2s
#just stuff all 0's in the middle, 1's on the left, 2's on the right
