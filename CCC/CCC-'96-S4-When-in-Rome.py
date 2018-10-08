nums = ['I','V','X','L','C','D','M'] #numerals 1,5,10,50,100,500,1000
nums2 = [1,5,10,50,100,500,1000]
roman = [[1000, 'M'], [900, 'CM'], [500, 'D'], [400, 'CD'], [ 100, 'C'], [ 90, 'XC'], [ 50, 'L'], [ 40, 'XL'], [  10, 'X'], [  9, 'IX'], [  5, 'V'], [  4, 'IV'],[   1, 'I']]

n = int(raw_input()) #number of expressions to follow

for i in range(n):
  string = raw_input()
  n1,n2 = string.split('+')
  value1 = 0
  value2 = 0
  sub = False
  
  for j in range(len(n1)):
    if len(n1) > 1:
      if sub == False:
        if j < len(n1) - 1:
          if nums.index(n1[j]) >= nums.index(n1[j+1]):
            value1 += nums2[nums.index(n1[j])]
          elif nums.index(n1[j]) < nums.index(n1[j+1]):
            value1 += nums2[nums.index(n1[j+1])] - nums2[nums.index(n1[j])]
            sub = True
        else:
          value1 += nums2[nums.index(n1[j])]
      else:
        sub = False
    else:
      value1 += nums2[nums.index(n1[0])]
      
  sub = False
  
  for j in range(len(n2)-1):
    if len(n2)-1 > 1:
      if sub == False:
        if j < len(n2) - 2:
          if nums.index(n2[j]) >= nums.index(n2[j+1]):
            value2 += nums2[nums.index(n2[j])]
          elif nums.index(n2[j]) < nums.index(n2[j+1]):
            value2 += nums2[nums.index(n2[j+1])] - nums2[nums.index(n2[j])]
            sub = True
        else:
          value2 += nums2[nums.index(n2[j])]
      else:
        sub = False
    else:
      value2 += nums2[nums.index(n2[0])]
  
  value3 = value1 + value2
  output = ''
  i = 0
  if value3 > 1000:
    output = 'CONCORDIA CUM VERITATE'
  else:
    while value3 > 0:
      if roman[i][0] <= value3:
        while roman[i][0] <= value3:
          output += roman[i][1]
          value3 -= roman[i][0]
      else:
        i += 1
  print (string+output)
