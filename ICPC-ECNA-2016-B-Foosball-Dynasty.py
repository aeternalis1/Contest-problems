n = int(input()) #amount of players
players = input().split()
points = input()
dynasties = []
wlength = 0
blength = 0
longest = 0

w1 = players[0] #white offense
b1 = players[1] #white defense
w2 = players[2] #black offense
b2 = players[3] #black defense
fw = w1
sw = w2
fb = b1
sb = b2

for i in range(len(points)):
  if points[i] == 'W':
    wlength += 1
    blength = 0
    w1,w2 = w2,w1
    players.append(b2)
    b2 = b1
    b1 = players[4+i]
    fb = b2
    sb = b1
  elif points[i] == 'B':
    blength += 1
    wlength = 0
    b1,b2 = b2,b1
    players.append(w2)
    w2 = w1
    w1 = players[4+i]
    fw = w2
    sw = w1
  if wlength > longest:
    longest = wlength
    dynasties = []
    dynasties.append([fw,sw])
  elif wlength == longest:
    dynasties.append([fw,sw])
  if blength > longest:
    longest = blength
    dynasties = []
    dynasties.append([fb,sb])
  elif blength == longest:
    dynasties.append([fb,sb])
    
for i in range(len(dynasties)):
  print (' '.join(dynasties[i]))
