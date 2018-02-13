def convex_hull(points):
  points = sorted(points)
  if len(points) <= 1:
    return points
  def cross(o, a, b):
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])
  lower = []
  for p in points:
    while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
      lower.pop()
    lower.append(p)
  upper = []
  for p in reversed(points):
    while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
      upper.pop()
    upper.append(p)
  return lower[:-1] + upper[:-1]

n = int(raw_input())
points = []
for i in range(n):
  points.append(list(map(int,raw_input().split())))
points = convex_hull(points)

points.append(points[0])
ans = 0
for i in range(len(points)-1):
  ans += points[i][0]*points[i+1][1]
for i in range(len(points)-1):
  ans -= points[i][1]*points[i+1][0]
print abs(ans)/100
