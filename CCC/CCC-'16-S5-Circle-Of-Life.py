from math import log
import sys
input = sys.stdin.readline

#credit to https://amorim.ca/display/CS/Circle+of+Life

N,T = map(int,input().split())
oldgen = list(map(int,list(input().strip('\n'))))
newgen = [False for x in range(N)]
def nextgens(T):
  gens = 1<<int(log(T,2))
  if gens > T:
    gens /= 2
  return int(gens)

def cell(ind,N):
  ind = ind%N
  if ind < 0:
    return ind+N
  else:
    return ind

def generations(T,N):
  for i in range(N):
    newgen[i] = oldgen[cell(i-T,N)]^oldgen[cell(i+T,N)]
    
while T > 0:
  gens = nextgens(T)
  T -= gens
  generations(gens,N)
  newgen,oldgen = oldgen,newgen

print (''.join(str(x) for x in oldgen))
