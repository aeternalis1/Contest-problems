from __future__ import division
N = int(raw_input())
arr = []
ans = 0

for i in range(N):
  arr.append(list(map(int,raw_input().split())))
  if arr[i][0] > arr[i][2]:
    arr[i] = [arr[i][2],arr[i][3],arr[i][0],arr[i][1]]

def check(l1,l2):
  if l1[0]==l1[2]:
    m1 = None
  else:
    m1 = (l1[3]-l1[1])/(l1[2]-l1[0])
  if l2[0]==l2[2]:
    m2 = None
  else:
    m2 = (l2[3]-l2[1])/(l2[2]-l2[0])
  if m1 == None or m2 == None:
    if m1 == m2:
      if l1[0]==l2[0]:
        if max(l1[1],l1[3]) >= min(l2[1],l2[3]) and max(l1[1],l1[3]) <= max(l2[1],l2[3]):
          return True
        if max(l2[1],l2[3]) >= min(l1[1],l1[3]) and max(l2[1],l2[3]) <= max(l1[1],l1[3]):
          return True
    return False
  if abs(m1-m2) > 0.00001:
    return False
  b1 = l1[1]-m1*l1[0]
  b2 = l2[1]-m2*l2[0]
  if abs(b1-b2) > 0.00001:
    return False
  if l1[0] <= l2[2] and l1[0] >= l2[0] or l2[0] <= l1[2] and l2[0] >= l1[0]:
    return True
  return False

def new(l1,l2):
  res = [0,0,0,0]
  if l1[0]==l1[2]:
    res = [l1[0],min(l1[1],l1[3],l2[1],l2[3]),l1[0],max(l1[1],l1[3],l2[1],l2[3])]
  elif l1[1]==l1[3]:
    res = [min(l1[0],l1[2],l2[0],l2[2]),l1[1],max(l1[0],l1[2],l2[0],l2[2]),l1[1]]
  else:
    if l1[0] < l2[0]:
      res[0],res[1] = l1[0],l1[1]
    elif l1[0]==l2[0]:
      if l1[1] > l2[1]:
        res[0],res[1] = l1[0],l1[1]
      else:
        res[0],res[1] = l2[0],l2[1]
    else:
      res[0],res[1] = l2[0],l2[1]
    if l1[2] > l2[2]:
      res[2],res[3] = l1[2],l1[3]
    elif l1[2]==l2[2]:
      if l1[3] < l2[3]:
        res[2],res[3] = l1[2],l1[3]
      else:
        res[2],res[3] = l2[2],l2[3]
    else:
      res[2],res[3] = l2[2],l2[3]
  return res

found = True
while found:
  found = False
  for i in range(len(arr)):
    for j in range(i+1,len(arr)):
      if check(arr[i],arr[j]):
        found = True
        arr.append(new(arr[i],arr[j]))
        arr.pop(j)
        arr.pop(i)
        break
    if found:
      break

def solve2(pts):
  arr = [[0,0,0] for x in range(2)]
  for i in range(2):
    arr[i][0] = pts[i][3]-pts[i][1]
    arr[i][1] = pts[i][0]-pts[i][2]
    arr[i][2] = arr[i][0]*pts[i][0]+arr[i][1]*pts[i][1]
  det = arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0]
  if det==0:
    return 0
  x = (arr[1][1]*arr[0][2]-arr[0][1]*arr[1][2])/det
  y = (arr[0][0]*arr[1][2]-arr[1][0]*arr[0][2])/det
  t1 = [pts[0][0],pts[0][2]]
  t2 = [pts[0][1],pts[0][3]]
  t3 = [pts[1][0],pts[1][2]]
  t4 = [pts[1][1],pts[1][3]]
  if x <= max(t1) and x >= min(t1) and x <= max(t3) and x >= min(t3) and y <= max(t2) and y >= min(t2) and y <= max(t4) and y >= min(t4):
    return [x,y]
  return 0

def solve(lines):
  pt1 = solve2([lines[0],lines[1]])
  pt2 = solve2([lines[1],lines[2]])
  pt3 = solve2([lines[0],lines[2]])
  arr = [pt1,pt2,pt3]
  if 0 in arr:
    return False
  if abs(arr[0][0]-arr[1][0]) < 0.00001 and abs(arr[0][1]-arr[1][1]) < 0.00001:
    return False
  if abs(arr[2][0]-arr[1][0]) < 0.00001 and abs(arr[2][1]-arr[1][1]) < 0.00001:
    return False
  if abs(arr[0][0]-arr[2][0]) < 0.00001 and abs(arr[0][1]-arr[2][1]) < 0.00001:
    return False
  return True

N = len(arr)

for i in range(N):
  for j in range(i+1,N):
    for k in range(j+1,N):
      if solve([arr[i],arr[j],arr[k]]):
        ans += 1

print ans

#brute force all combinations of 3 line segments. If there are 3 intersections, check if they make a triangle (i.e. no repeated points of intersection).
#https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-line-intersection-and-its-applications/
