import sys
raw_input = sys.stdin.readline
N,P = map(int,raw_input().split())
planets = []
fuel = 0
for i in range(N):
  a,b = map(int,raw_input().split())
  if i != P-1:
    planets.append([b,a])
  else:
    fuel += a
ans = 0
planets.sort()
for i in planets:
  if i[1] > i[0] and i[0] <= fuel:
    fuel += i[1] - i[0]
    ans += 1
  elif i[0] == i[1] and i[0] <= fuel:
    ans += 1
print fuel
print ans+1
