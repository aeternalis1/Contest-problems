N = int(input())

for i in range(N):
  L = int(raw_input())
  list1 = raw_input().split()
  list2 = raw_input().split()
  maxnum = 0
  curr = 0
  currj = 0
  for i in range(L):
    if curr != list1[i]:
      curr = list1[i]
      numfound = False
      for j in range(i,L):
        if list1[i] == list2[j]:
          numfound = True
          currj = list2[j]
          if j - i > maxnum:
            maxnum = j-i
        if list2[j] != currj and list2[j-1] == currj and numfound == True:
          break
        
  print "The maximum distance is "+str(maxnum)
