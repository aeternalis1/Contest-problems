from __future__ import division
from math import sqrt
x,y,z = map(int,raw_input().split())
x2,y2,z2 = map(int,raw_input().split())
x = x2-x
y = y2-y
z = z2-z
ans = x*x+y*y+z*z
while True:
  dist,c = raw_input().split()
  dist = int(dist)
  nx = x-dist
  if nx*x < 0:
    ans = min(ans,y*y+z*z)
  else:
    ans = min(ans,nx*nx+y*y+z*z)
  if c == 'E':
    break
  x = nx
  t = x
  if c == 'R':
    x = -y
    y = t
  elif c == 'L':
    x = y
    y = -t
  elif c == 'U':
    x = z
    z = -t
  elif c == 'D':
    x = -z
    z = t
if ans == 0:
  print 0.00
else:
  print "%.2f"%(int(sqrt(ans)*100+0.5)/100)
