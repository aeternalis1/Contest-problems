N = 100
arr = [[100 for x in range(N)] for x in range(N)]
arr[0][0] = 1
arr[0][1] = 1
arr[0][2] = 1
print N
for i in range(N-1):
  if i%2:
    arr[i][0] = 1
  elif i < N-1:
    arr[i][2] = 1
for i in range(N-1):
  print " ".join([str(x) for x in arr[i][:-i-1]])
