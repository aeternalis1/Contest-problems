D = int(raw_input()) #dogs in neighborhood
times = [0 for x in range(D)]
paths = [[] for x in range(D)]
answers = [0 for x in range(D)]
delays = [0 for x in range(D)] #if dog is currently waiting, set delay to time waiting
changed = [False for x in range(D)]
for i in range(D):
  times[i] = int(raw_input())
  
F = int(raw_input())
for i in range(F):
  a,b = map(int,raw_input().split())
  paths[a-1].append(b-1)
T = int(raw_input())
queue = [0]
answers[0] += 1
for i in paths[0]:
  delays[i] = times[i]
for i in range(T):
  changed = [False for x in range(D)]
  for j in range(D):
    if delays[j] > 0 and not changed[j]:
      delays[j] -= 1
      if delays[j] == 0:
        changed[j] = True
        answers[j] += 1
        for k in paths[j]:
          if delays[k] == 0 and not changed[k]:
            changed[k] = True
            delays[k] = times[k]
for i in answers:
  print i
