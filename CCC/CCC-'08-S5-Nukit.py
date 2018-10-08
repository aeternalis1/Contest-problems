n = input()
moves = [[2,1,0,2],[1,1,1,1],[0,0,2,1],[0,3,0,0],[1,0,0,1]]
dp = [[[[False for x in xrange(31)]for x in xrange(31)] for x in xrange(31)] for x in xrange(31)]

def losing(a,b,c,d):
  if a < 0 or b < 0 or c < 0 or d < 0:
    return False
  else:
    if dp[a][b][c][d]:
      return False
    else:
      return True

for i in xrange(31):
  for j in xrange(31):
    for k in xrange(31):
      for l in xrange(31):
        for m in xrange(5): #number of moves to try out
          if losing(i-moves[m][0],j-moves[m][1],k-moves[m][2],l-moves[m][3]):
            dp[i][j][k][l] = True

for i in xrange(n):
  a,b,c,d = map(int,raw_input().split())
  if dp[a][b][c][d]:
    print ("Patrick")
  else:
    print ("Roland")
