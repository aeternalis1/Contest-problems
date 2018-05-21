import sys
raw_input = sys.stdin.readline
T = int(raw_input())

for i in range(T):
  N = int(raw_input()) #amount of cars
  
  postp = [0]
  cars = []
  
  for j in range(N):
    cars.append(int(raw_input()))
    
  j = 1
  success = True
  carind = N - 1  #car index
  
  while success == True and j <= N:
    if carind >= 0 and cars[carind] == j:
      carind -= 1
      j += 1
    elif len(postp) > 1 and postp[len(postp)-1] == j:
      postp.pop(len(postp)-1)
      j += 1
    elif carind>=0:
      postp.append(cars[carind])
      carind -= 1
    else:
      success = False
      break
    
  if success == False:
    print ("N")
  else:
    print ("Y")
