import sys
raw_input = sys.stdin.readline
N,M,A,B = map(int,raw_input().split())
nums = {'A':0,'B':1,'C':2,'D':3,'E':4,'F':5}
seats = [[True for x in range(6)] for x in range(N+1)]
rooms = [0,0] #secure room 1, secure room N
tree = [0 for x in range(N+1)]
answers = []
total = 2*N
diff = []
ans = 9999999999999999

for i in range(1,N+1):
  j = i+(i&-i)
  tree[i] += 2
  if j <= N:
    tree[j] += tree[i]
    
def update(i):
  while i <= N:
    tree[i] -= 1
    i += i&-i

def query(i):
  ans = 0
  while i > 0:
    ans += tree[i]
    i -= i&-i
  return ans

for i in range(M):
  q = raw_input().strip('\n')
  b = nums[q[-1]]
  a = int(q[:-1])
  seats[a][b] = False
  res = 0
  temp = query(a)
  temp2 = total - temp
  if b == 2:
    temp2 += seats[a][3]
  elif b == 3:
    temp2 += seats[a][2]
  else:
    temp2 += seats[a][2] + seats[a][3]
  if b == 0:
    temp += seats[a][1]
    temp2 += seats[a][1]
  elif b == 2 or b == 3:
    temp -= 1
    total -= 1
    update(a)
  elif b == 5:
    temp += seats[a][4]
    temp2 += seats[a][4]
  answers.append([temp,temp2])
  diff.append(abs(temp2-temp))

diff,answers = map(list,zip(*sorted(zip(diff,answers),reverse=True)))

first = []
last = []
mid = []

for i in answers:
  if i[0] < i[1]:
    first.append(i)
  elif i[0] > i[1]:
    last.append(i)
  else:
    mid.append(i)

first = first+mid+last[::-1]

for i in range(1,M):
  first[i][0] += first[i-1][0]
  first[i][1] += first[i-1][1]

first = [[0,0]]+first

for i in range(M+1):
  hi = M-i
  lo = i
  res = (((hi-1)*hi/2)+((lo-1)*lo/2))*B
  res += (first[M][1]-first[lo][1]+first[lo][0])*A
  ans = min(ans,res)
print ans
