T = int(raw_input())
good = [
    [0,1,1,1,0],
    [0,2,1,2,0],
    [0,0,2,0,0],
    [0,0,0,0,0],
    [0,0,0,0,0]
]

def solve(m,x,y):
    if not m:
        return 0
    nx,ny = x/pow(5,m-1),y/pow(5,m-1)
    if good[ny][nx]!=2:
        return good[ny][nx]
    return solve(m-1,x%pow(5,m-1),y%pow(5,m-1))

for i in range(T):
    m,a,b = map(int,raw_input().split())
    if solve(m,a,b):
        print "crystal"
    else:
        print "empty"
