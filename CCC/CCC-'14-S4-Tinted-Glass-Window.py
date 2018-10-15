N = int(input())
T = int(input())
arr = []
xs = []
ys = []
for i in range(N):
    a,b,c,d,e = map(int,input().split())
    xs.append([a,b,d,e])
    xs.append([c,b,d,-e])
    ys.append(b)
    ys.append(d)
xs = sorted(xs)
ys = sorted(list(set(ys)))
nums = [0 for x in range(len(ys)-1)]
L = len(nums)
ind = 0
lx = 0
ans = 0
for i in xs:
    for j in range(L):
        if nums[j]>=T:
            ans += (ys[j+1]-ys[j])*(i[0]-lx)
    for j in range(L):
        if i[1]<=ys[j] and i[2]>=ys[j+1]:
            nums[j] += i[3]
    lx = i[0]
print (ans)
