import sys
input = sys.stdin.readline

N = int(input())
grid = [list(input()) for x in range(N)]
answers = [[0 for x in range(N)] for x in range(N)]
ans = 0
for i in range(N-1,-1,-1):
  for j in range(N):
    if grid[i][j] == '#':
      answers[i][j] += 1 
      if i < N-1 and j > 0 and j < N-1:
        answers[i][j] += min(answers[i+1][j],answers[i+1][j+1],answers[i+1][j-1])
    ans += answers[i][j]
    
print (ans)
