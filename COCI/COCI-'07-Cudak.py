import sys
sys.setrecursionlimit(10000000)
a,b,s = map(int,raw_input().split())
dp = [[[[-1 for x in range(200)] for x in range(20)] for x in range(2)] for x in range(2)]
digs = []
digs.append([int(x) for x in list(str(b))])
digs.append([int(x) for x in list(str(a))])
for i in range(len(digs[1]),len(digs[0])):
    digs[1].insert(0,0)
ans = [1000000000000000000]
def solve(dep, v, v2, t, cur, li):
    if dp[v][v2][dep][cur]!=-1:
        return dp[v][v2][dep][cur]
    if dep==len(digs[0]):
        if cur == t:
            dp[v][v2][dep][cur] = 1
            ans[0] = min(ans[0],int("".join(str(x) for x in li)))
            return 1
        else:
            return 0
    if not v:
        r = 10
    else:
        r = digs[0][dep]+1
    if not v2:
        l = 0
    else:
        l = digs[1][dep]
    res = 0
    for i in range(l,r):
        li.append(i)
        res += solve(dep+1,v&(i==r-1),v2&(i==l),t,cur+i,li)
        li.pop(-1)
    dp[v][v2][dep][cur] = res
    return res

print solve(0,1,1,s,0,[])
print ans[0]
