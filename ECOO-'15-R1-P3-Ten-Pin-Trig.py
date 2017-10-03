for i in range(10): #change to 10 for final
  x1,x2,y1,y2,s1,s2,n = input().split()
  pin1x = round(float(x1)*10**(int(x2)),int(n))
  pin1y = round(float(y1)*10**(int(y2)),int(n))
  side = round(float(s1)*10**(int(s2)),int(n))
  height = (side**2-(side/2)**2)**0.5 #height of triangle
  pin7x = pin1x - side/2
  pin7y = pin1y + height
  pin10x = pin1x + side/2
  pin2x = pin1x - side/6
  pin2y = pin1y + height/3
  pin3x = pin2x + side/3
  pin4x = pin2x - side/6
  pin4y = pin2y + height/3
  pin5x = pin4x + side/3
  pin6x = pin5x + side/3
  pin8x = pin1x - side/6
  pin9x = pin1x + side/6
  pins = [[pin1x,pin1y],[pin2x,pin2y],[pin3x,pin2y],[pin4x,pin4y],[pin5x,pin4y],[pin6x,pin4y],[pin7x,pin7y],[pin8x,pin7y],[pin9x,pin7y],[pin10x,pin7y]]
  final = []
  for j in range(5):
    x1,x2,y1,y2 = input().split()
    x = float(x1)*10**(int(x2))
    y = float(y1)*10**(int(y2))
    pin = 0
    dist = 1000000
    for k in range(10):
      if ((pins[k][0]-x)**2+(pins[k][1]-y)**2)**0.5 < dist:
        dist = (abs(pins[k][0]-x)**2+abs(pins[k][1]-y)**2)**0.5
        pin = k+1
    final.append(pin)
  final = [str(x) for x in final]
  print (' '.join(final))
