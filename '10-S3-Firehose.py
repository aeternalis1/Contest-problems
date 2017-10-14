H = int(raw_input())
houses = []
for i in range(H):
  houses.append(int(raw_input()))
houses.sort()
K = int(raw_input())
lo = -1
hi = 1000000

def solve(size):
  size *= 2
  ans = H
  i = 0
  while i < H and houses[i] <= houses[0]+size:
    curr = 1
    end = houses[i]
    j = i+1
    while j < H and houses[j] < houses[i]-size+1000000:
      if houses[j] > end:
        end = houses[j] + size
        curr += 1
      j += 1
    ans = min(curr,ans)
    i += 1
  return ans

while lo < hi-1:
  mid = (lo+hi)/2
  if solve(mid) > K:
    lo = mid
  else:
    hi = mid
print hi
