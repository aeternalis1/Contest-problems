from collections import deque
N = int(raw_input())
nums = list(map(int,raw_input().split()))
nums = sorted(nums)
count = {}
arr = deque()
for i in nums:
  try:
    count[i] += 1
  except:
    count[i] = 1
    arr.append(i)
turn = 0                            #0 = mirko turn, 1 = slavko turn
while len(arr) > 2:
  cnt1 = count[arr[0]]
  cnt2 = count[arr[-1]]
  if cnt1 > cnt2:
    if turn:
      count[arr[1]] += cnt2-1
      count[arr[-2]] += cnt2
      count[arr[0]] -= cnt2-1
    else:
      count[arr[1]] += cnt2
      count[arr[-2]] += cnt2
      count[arr[0]] -= cnt2
    arr.pop()
    turn = 0
  elif count[arr[0]] == count[arr[-1]]:
    if turn:
      count[arr[1]] += cnt2-1
      count[arr[0]] = 1
      count[arr[-2]] += cnt2
      turn = 0
      arr.pop()
    else:
      count[arr[1]] += cnt2
      count[arr[-1]] = 1
      count[arr[-2]] += cnt2-1
      turn = 1
      arr.popleft()
  else:
    if not turn:
      count[arr[1]] += cnt1
      count[arr[-2]] += cnt1-1
      count[arr[-1]] -= cnt1-1
    else:
      count[arr[1]] += cnt1
      count[arr[-2]] += cnt1
      count[arr[-1]] -= cnt1
    arr.popleft()
    turn = 1
if turn:
  print "Mirko"
else:
  print "Slavko"
if len(arr) > 1:
  print arr[0],arr[1]
else:
  print arr[0],arr[0]

#mirko goes first with min - 2nd min, then slavko with max - 2nd max
