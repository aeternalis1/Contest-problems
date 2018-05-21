T = int(input()) #favourite team
N = int(input()) #games played already
status = [False,False,False,False,False,False] #1-2, 1-3, 1-4, 2-3, 2-4, 3-4
count = 0

for i in range(N):
  t1,t2,p1,p2 = map(int,input().split())
  if t1 == 1:
    if t2 == 2:
      if p1 > p2:
        status[0] = 'W'
      elif p1 < p2:
        status[0] = 'L'
      else:
        status[0] = 'T'
    elif t2 == 3:
      if p1 > p2:
        status[1] = 'W'
      elif p1 < p2:
        status[1] = 'L'
      else:
        status[1] = 'T'
    elif t2 == 4:
      if p1 > p2:
        status[2] = 'W'
      elif p1 < p2:
        status[2] = 'L'
      else:
        status[2] = 'T'
  elif t1 == 2:
    if t2 == 3:
      if p1 > p2:
        status[3] = 'W'
      elif p1 < p2:
        status[3] = 'L'
      else:
        status[3] = 'T'
    elif t2 == 4:
      if p1 > p2:
        status[4] = 'W'
      elif p1 < p2:
        status[4] = 'L'
      else:
        status[4] = 'T'
  elif t1 == 3:
    if p1 > p2:
      status[5] = 'W'
    elif p1 < p2:
      status[5] = 'L'
    else:
      status[5] = 'T'
      
pos = []

for i in status: #how many possibilities there are altogether (3 for undecided games, 1 for decided)
  if i == False:
    pos.append(3)
  else:
    pos.append(1)
    
pos2 = [] #actual possibilities (complete strings)

for i in range(pos[0]):
  for j in range(pos[1]):
    for k in range(pos[2]):
      for l in range(pos[3]):
        for m in range(pos[4]):
          for n in range(pos[5]):
            newpos = []
            if pos[0] == 1:
              newpos.append(status[0])
            elif i == 0:
              newpos.append('W')
            elif i == 1:
              newpos.append('L')
            elif i == 2:
              newpos.append('T')
            if pos[1] == 1:
              newpos.append(status[1])
            elif j == 0:
              newpos.append('W')
            elif j == 1:
              newpos.append('L')
            elif j == 2:
              newpos.append('T')
            if pos[2] == 1:
              newpos.append(status[2])
            elif k == 0:
              newpos.append('W')
            elif k == 1:
              newpos.append('L')
            elif k == 2:
              newpos.append('T')
            if pos[3] == 1:
              newpos.append(status[3])
            elif l == 0:
              newpos.append('W')
            elif l == 1:
              newpos.append('L')
            elif l == 2:
              newpos.append('T')
            if pos[4] == 1:
              newpos.append(status[4])
            elif m == 0:
              newpos.append('W')
            elif m == 1:
              newpos.append('L')
            elif m == 2:
              newpos.append('T')
            if pos[5] == 1:
              newpos.append(status[5])
            elif n == 0:
              newpos.append('W')
            elif n == 1:
              newpos.append('L')
            elif n == 2:
              newpos.append('T')
            pos2.append(newpos)

def winning(pos,team):
  
  scores = [0,0,0,0]
  if pos[0] == 'W':
    scores[0] += 3
  elif pos[0] == 'L':
    scores[1] += 3
  else:
    scores[0] += 1
    scores[1] += 1
  if pos[1] == 'W':
    scores[0] += 3
  elif pos[1] == 'L':
    scores[2] += 3
  else:
    scores[0] += 1
    scores[2] += 1
  if pos[2] == 'W':
    scores[0] += 3
  elif pos[2] == 'L':
    scores[3] += 3
  else:
    scores[0] += 1
    scores[3] += 1
  if pos[3] == 'W':
    scores[1] += 3
  elif pos[3] == 'L':
    scores[2] += 3
  else:
    scores[1] += 1
    scores[2] += 1
  if pos[4] == 'W':
    scores[1] += 3
  elif pos[4] == 'L':
    scores[3] += 3
  else:
    scores[1] += 1
    scores[3] += 1
  if pos[5] == 'W':
    scores[2] += 3
  elif pos[5] == 'L':
    scores[3] += 3
  else:
    scores[2] += 1
    scores[3] += 1
    
  if scores[T-1] == max(scores) and scores.count(scores[T-1]) == 1:
    return True
  else:
    return False
    
for i in range(len(pos2)):
  if winning(pos2[i],T):
    count += 1

print (count)
