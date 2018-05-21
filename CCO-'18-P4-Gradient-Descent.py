import sys

R,C,K = map(int,raw_input().split())
lo = 1
hi = R
lo2 = 1
hi2 = C
ans = 9999999999
checked = {}
while lo < hi or lo2 < hi2:
  mid = (lo+hi)/2
  mid2 = (lo2+hi2)/2
  try:
    a = checked[(mid,mid2)]
  except:
    print "?",mid,mid2
    sys.stdout.flush()
    a = int(raw_input())
    checked[(mid,mid2)] = a
  if mid < hi:
    try:
      b = checked[(mid+1,mid2)]
    except:
      print "?",mid+1,mid2
      sys.stdout.flush()
      b = int(raw_input())
      checked[(mid+1,mid2)] = b
  else:
    b = 99999999999
  if mid2 < hi2:
    try:
      c = checked[(mid,mid2+1)]
    except:
      print "?",mid,mid2+1
      sys.stdout.flush()
      c = int(raw_input())
      checked[(mid,mid2+1)] = c
  else:
    c = 99999999999
  ans = min(ans,a,b,c)
  if a > b and a > c:
    lo = mid+1
    lo2 = mid2+1
  elif a < b and a < c:
    hi = mid
    hi2 = mid2
  elif b < a and b < c:
    lo = mid+1
    hi2 = mid2
  elif c < a and c < b:
    hi = mid
    lo2 = mid2+1
  elif b==c and a > b:
    lo = mid+1
    lo2 = mid2+1
  elif a==b and c > b:
    lo = mid+1
    hi2 = mid2
  elif a==c and b > a:
    hi = mid
    lo2 = mid2+1
  elif a==b and b==c:
    break
try:
  ans = min(ans,checked[(lo,lo2)])
except:
  print "?",lo,lo2
  sys.stdout.flush()
  ans = min(ans,int(raw_input()))
print "!",ans
