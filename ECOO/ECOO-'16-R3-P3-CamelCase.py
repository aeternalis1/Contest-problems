import sys
input = sys.stdin.readline

N = int(input())
words = set([input().strip() for x in range(N)])

for i in range(10):
  string = input()
  length = len(string)
  array = [10000 for x in range(length+1)]
  array[0] = 0
  for j in range(length+1):
    for k in range(j):
      if string[k:j] in words:
        array[j] = min(array[j],array[k]+1)
  print (array[-2]-1)
