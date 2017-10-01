import sys
raw_input = sys.stdin.readline
N = int(raw_input())
readings = [0 for x in range(1001)] #frequency
highs = []
highs2 = []
second = 0

for i in range(N):
  r = int(raw_input())
  readings[r] += 1

currmax = max(readings)

for i in range(len(readings)):
  if readings[i] == currmax:
    highs.append(i)
    
if len(highs) > 1:
  highs.sort()
  print (highs[len(highs)-1]-highs[0])
else:
  currmax = max(readings)
  for i in range(len(readings)):
    if readings[i] < currmax and readings[i] > second:
      highs2 = []
      highs2.append(i)
      second = readings[i]
    elif readings[i] == second:
      highs2.append(i)
  highs2.sort()
  if abs(highs2[0]-highs[0]) > abs(highs2[-1]-highs[0]):
    print (abs(highs2[0]-highs[0]))
  else:
    print (abs(highs2[-1]-highs[0]))
