from math import log

n = raw_input()

ans = 1
for i in range(1,300000):
  ans = ans + log(i,10)
  if int(ans) == len(n):
    break
if i > 10:
  print (i)
else:
  if int(n) <= 362880:
    n = int(n)
    ans = 0
    fact = 1
    while n > 1:
      n = n/fact
      ans += 1
      fact += 1
    if ans == 0:
      ans = 1
    print (ans)
