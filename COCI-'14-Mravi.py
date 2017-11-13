N = int(input()) #number of nodes in the tree
answer = 0

nodes1 = [0 for x in range(N)]
percents = [0 for x in range(N)]
powers = [0 for x in range(N)]

for i in range(N-1):
  a,b,p,s = map(int,input().split()) #pipe 1 to pipe 2 with p percentage and s superpower (0 or 1)
  nodes1[b-1] = a-1
  percents[b-1] = p
  powers[b-1] = s
  
nodes = input().split()
leaves = []
waters = []

for i in range(N):
  if nodes[i] != '-1':
    leaves.append(i)
    waters.append(int(nodes[i]))
    
for i in range(len(leaves)): #already indexed from 0
  current = leaves[i]
  water = waters[i]
  while current != 0:
    if powers[current] == 1:
      water = water**0.5
    water = water/(percents[current]/100)
    current = nodes1[current]
  if water > answer:
    answer = water
    
print (answer)
