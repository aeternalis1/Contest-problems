n = int(raw_input()) #number of trips the rover takes

#again, a very very disgusting solution

for i in range(n):
  ahead = False #when true, the next command will take you in that direction
  roverx = 0 #moving east +, moving west -
  rovery = 0 #moving north +, moving south -
  d = 0 #directions: 0 = north, 1 = east, 2 = south, 3 = west (not sure if it resets per trip)
  while True:
    if ahead == False:
      num = int(raw_input())
      if num == 1:
        ahead = True
      elif num == 2:
        if d < 3:
          d += 1
        elif d == 3:
          d = 0
      elif num == 3:
        if d > 0:
          d -= 1
        elif d == 0:
          d = 3
      elif num == 0:
        break
    elif ahead == True:
      dist = int(raw_input())
      if d == 0:
        rovery += dist
      elif d == 1:
        roverx += dist
      elif d == 2:
        rovery -= dist
      elif d == 3:
        roverx -= dist
      ahead = False
      
  totdist = abs(roverx)+abs(rovery) #total distance
  if i >= 1 :
    print ("")
  print ("Distance is "+str(totdist))
  
  if totdist > 0: #if totdist = 0 then the rover didnt move
    d1 = 4 #set to 4 as default
    d2 = 4 #set to 4 as default
    if roverx > 0:
      d1 = 3 #direction in which to travel back to rover (west)
    elif roverx < 0:
      d1 = 1 #east
    if rovery > 0: 
      d2 = 2 #south
    elif rovery < 0:
      d2 = 0 #north
      
    if d1 == 4 or d2 == 4: #one axis did not change 
      if d1 == 4: #x-value did not change
        if d2 == 2: #rover needs to go south (turning 180, 90 both ways, not turning)
          if d == 0:
            print ("3")
            print ("3")
            print ("1")
            print (abs(rovery))
          elif d == 1:
            print ("2")
            print ("1")
            print (abs(rovery))
          elif d == 3:
            print ("3")
            print ("1")
            print (abs(rovery))
          elif d == 2:
            print ("1")
            print (abs(rovery))
        elif d2 == 0: #rover needs to go north (turning 180, 90 both ways, not turning)
          if d == 2:
            print ("3")
            print ("3")
            print ("1")
            print (abs(rovery))
          elif d == 1:
            print ("3")
            print ("1")
            print (abs(rovery))
          elif d == 3:
            print ("2")
            print ("1")
            print (abs(rovery))
          elif d == 0:
            print ("1")
            print (abs(rovery))
      elif d2 == 4: #y-value did not change
        if d1 == 1: #rover needs to go east (turning 180, 90 both ways, not turning)
          if d == 3:
            print ("3")
            print ("3")
            print ("1")
            print (abs(roverx))
          elif d == 2:
            print ("3")
            print ("1")
            print (abs(roverx))
          elif d == 0:
            print ("2")
            print ("1")
            print (abs(roverx))
          elif d == 1:
            print ("1")
            print (abs(roverx))
        elif d2 == 3: #rover needs to go west (turning 180, 90 both ways, not turning)
          if d == 1:
            print ("3")
            print ("3")
            print ("1")
            print (abs(rovery))
          elif d == 0:
            print ("3")
            print ("1")
            print (abs(rovery))
          elif d == 2:
            print ("2")
            print ("1")
            print (abs(rovery))
          elif d == 3:
            print ("1")
            print (abs(rovery))
    elif d == d2: #both axes have values, but rover is facing y-axis on return trip
      print ("1")
      print (abs(rovery))
      if d1 == 1 and d2 == 0 or d1 == 3 and d2 == 2:
        print ("2")
        print ("1")
        print (abs(roverx))
      elif d1 == 3 and d2 == 0 or d1 == 1 and d2 == 2:
        print ("3")
        print ("1")
        print (abs(roverx))
    elif d == d1: #both axes have values, but rover is facing x-axis on return trip
      print ("1")
      print (abs(roverx))
      if d1 == 1 and d2 == 0 or d1 == 3 and d2 == 2:
        print ("3")
        print ("1")
        print (abs(rovery))
      elif d1 == 3 and d2 == 0 or d1 == 1 and d2 == 2:
        print ("2")
        print ("1")
        print (abs(rovery))
    #next sections require finding the direction closer to current direction, then rotating to it, then rotating to final direction
    elif d == 0 and d2 == 2 or d == 2 and d2 == 0: #if y-direction is opposite intended direction (e.g d = north, d2 = south)
      if d == 0 and d1 == 1 or d == 2 and d1 == 3: #first move on x-axis before on y-axis
        print ("2")
        print ("1")
        print (abs(roverx))
        print ("2")
        print ("1")
        print (abs(rovery))
      elif d == 0 and d1 == 3 or d == 2 and d1 == 1: #first move on x-axis before on y-axis
        print ("3")
        print ("1")
        print (abs(roverx))
        print ("3")
        print ("1")
        print (abs(rovery))
    elif d == 1 and d1 == 3 or d == 3 and d1 == 1: #if x-direction is opposite intended direction (e.g d = east, d2 = west)
      if d == 1 and d2 == 2 or d == 3 and d2 == 0: #first move on y-axis before on x-axis
        print ("2")
        print ("1")
        print (abs(rovery))
        print ("2")
        print ("1")
        print (abs(roverx))
      elif d == 1 and d2 == 0 or d == 3 and d2 == 2: #first move on x-axis before on y-axis
        print ("3")
        print ("1")
        print (abs(rovery))
        print ("3")
        print ("1")
        print (abs(roverx))
