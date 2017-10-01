n = int(input()) #number of set inequalities
sets = []
subsets = []
dict = {}

for i in range(n):
  a,b,c = input().split() #a and b are the set and subset
  if a not in sets:
    sets.append(a)
    subsets.append([c])
  else:
    subsets[sets.index(a)].append(c)
    
for i in range(len(sets)):
  queue = []
  checked = []
  popped = 0
  for j in range(len(subsets[i])):
    if subsets[i][j-popped] == subsets[i][j-popped].upper(): #if the subset is a set, add to queue then pop
      queue.append(subsets[i][j-popped])
      subsets[i].pop(j-popped)
      popped += 1
      
  while len(queue) > 0:
    if queue[0] in sets:
      if queue[0] not in checked:
        checked.append(queue[0])
        for j in subsets[sets.index(queue[0])]:
          if j == j.upper():
            if j not in queue:
              queue.append(j)
          elif j == j.lower():
            if j not in subsets[i]:
              subsets[i].append(j)
      queue.pop(0)
    else: #if it isnt in sets, make a new set for it with nothing in it
      sets.append(queue[0])
      subsets.append([])
      queue.pop(0)
  
for i in range(len(sets)):
  subsets[i].sort()
  dict[sets[i]] = subsets[i]
  
for key in sorted(dict.keys()):
  print ("%s = {%s}" % (key, ','.join(dict[key])))
