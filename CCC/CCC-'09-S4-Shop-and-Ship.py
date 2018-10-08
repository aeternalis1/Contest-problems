import sys
raw_input = sys.stdin.readline

N = int(raw_input())
T = int(raw_input())
cities = [[0 for x in range(N)] for x in range(N)]
answers = [100000 for x in range(N)]
checked = [0 for x in range(N)]
least = 100000

for i in range(T):
  x,y,z = map(int,raw_input().split())
  cities[x-1][y-1] = z
  cities[y-1][x-1] = z
    
K = int(raw_input())

for i in range(K): #initial costs for pencils
  x,y = map(int,raw_input().split())
  answers[x-1] = y #cities with pencils

D = int(raw_input()) #destination city

while True:
    current = 0
    for i in range(N):
        if answers[i] < answers[current] and not checked[i]:
            current = i
    if current == D-1 or checked[current] == True:
        print (answers[D-1])
        break
    checked[current] = True
    for i in range(N):
      if cities[current][i] != 0:
        if answers[current] + cities[current][i] < answers[i]:
          answers[i] = answers[current]+cities[current][i]
