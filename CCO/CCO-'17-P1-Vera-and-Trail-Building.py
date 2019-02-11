K = int(raw_input())
paths = [[] for x in range(5000)]
cnt = 0
tot = 0
while K:
    cur = 1
    while cur*(cur+1)/2<=K:
        cur += 1
    cur -= 1
    K -= cur*(cur+1)/2
    for i in range(cnt,cnt+cur):
        paths[i].append(i+1)
    paths[cnt+cur].append(cnt)
    tot += cur+1
    paths[cnt+cur].append(cnt+cur+1)
    cnt += cur+1
    tot += 1
print cnt+1,tot
for i in range(cnt):
    for j in paths[i]:
        print i+1,j+1
