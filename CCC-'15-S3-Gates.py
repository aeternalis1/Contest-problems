import sys
raw_input = sys.stdin.readline

G = int(raw_input()) #number of gates
P = int(raw_input()) #number of planes
planes = []
gates = []

for i in range(G+1):
  gates.append(0)

i = 0
stop = False
total = 0

while i < P and stop == False:
  plane = int(raw_input())
  while plane > 0 and gates[plane] > 0:
    gates[plane],plane = gates[plane] + 1,plane - gates[plane]
  if plane <= 0:
    break
  else:
    gates[plane] = 1
    total += 1
  i += 1
    
print (total)
