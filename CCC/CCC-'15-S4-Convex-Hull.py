import sys
raw_input = sys.stdin.readline

K,N,M = map(int,raw_input().split())

islands = [[] for x in range(N+1)]

for i in range(M):
  a,b,t,h = map(int,raw_input().split())
  islands[a].append([b,t,h])
  islands[b].append([a,t,h])

a,b = map(int,raw_input().split())

array=[[10000000 for j in range(K+1)]for i in range(N+1)] 

for i in range(K+1):
  array[a][i] = 0
  
checked=[False for i in range(N+1)] 
queue=[a]                              
while queue:                         
  u=queue.pop(0)
  checked[u]=False
  for v in islands[u]:
    for i in range(K-v[2]+1):
      if array[u][i]+v[1]<array[v[0]][i+v[2]]:
        array[v[0]][i+v[2]]=array[u][i]+v[1]
        if not checked[v[0]]:
          queue.append(v[0])
          checked[v[0]]=True
            
if array[b][K-1] == 10000000:
  print (-1)
else:
  print (array[b][K-1])
