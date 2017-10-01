from __future__ import division
import math
N = int(raw_input())
cost = 0

while N > 1:
  f = 2
  rootN = int(math.sqrt(N)) +1
  while f <= rootN and N % f != 0:
    f += 1
  if f < N and N%f == 0: #confirms N is not prime (the factor is not N itself, nor can it be 1)
    x = N/f
    N = N - x
    cost = cost + N/x
  else: #if N is prime, just add N to cost and subtract 1 from N
    N -= 1
    cost += N
print (int(cost))
