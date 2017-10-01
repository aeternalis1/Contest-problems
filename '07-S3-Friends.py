n = int(input()) #number of students in class
students = {}

for i in range(n):
  s,f = input().split() #student and his friend
  students[s] = f

while True:
  s,f = input().split() #query (is student 1 connected to friend?)
  count = 0
  found = False
  if s == '0' and f == '0':
    break
  else:
    for i in range(n):
      if s in students:
        if students[s] == f:
          print ("Yes",count)
          found = True
          break
        else:
          s = students[s]
          count += 1
      else:
        break
  if found == False:
    print ("No")
