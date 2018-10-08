N = raw_input()

def larger(N): #finds smallest handsome number larger than N
  N = list(N) #change to list to make easily mutable
  N = [int(x) for x in N]
  found = False
  for i in range(len(N)-1):
    if N[i]%2==N[i+1]%2 and not found: #same parity
      if N[i+1] != 9:
        N[i+1] += 1
      else:
        return None
      found = True
    elif found:
      if N[i]%2 == 0:
        N[i+1] = 1
      else:
        N[i+1] = 0
  return int(''.join([str(x) for x in N]))

def smaller(N): #finds largest handsome number less than N
  N = list(N) #change to list to make easily mutable
  N = [int(x) for x in N]
  found = False
  for i in range(len(N)-1):
    if N[i]%2==N[i+1]%2 and not found: #same parity
      if N[i+1] != 0:
        N[i+1] -= 1
      else:
        return None
      found = True
    elif found:
      if N[i]%2==0:
        N[i+1] = 9
      else:
        N[i+1] = 8
  return int(''.join([str(x) for x in N]))

large = larger(N)
small = smaller(N)

if large != None and small != None:
  if abs(large-int(N)) == abs(int(N)-small):
    print small,large
  elif abs(large-int(N)) > abs(int(N)-small):
    print small
  else:
    print large
elif large == None:
  print small
else:
  print large
