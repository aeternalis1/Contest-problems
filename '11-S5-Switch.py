K = int(input())
lights = ""
count = 0
for i in range(K):
  lights = lights + (str(input()))
  
while lights.count('1') > 0 and lights.count('0') > 0:
  left = lights.find('10')
  if left >= 0:
    lpos = left + 1
    lsize = 0
    while left >= 0 and lights[left] == '1':
      left -= 1
      lsize += 1
  else:
    lpos = -1
    lsize = 99999
  right = lights.rfind('01')
  if right > 0:
    rpos = right
    rsize = 0
    right += 1
    while right < len(lights) and lights[right] == '1':
      right += 1
      rsize += 1
  else:
    rpos = -1
    rsize = 99999
  if lpos > 0:
    if lsize <= rsize:
      lights = lights[0:lpos] +  "1" + lights[lpos+1:]
    else:
      lights = lights[0:rpos] +  "1" + lights[rpos+1:]
  else:
    lights = lights[0:rpos] +  "1" + lights[rpos+1:]
  count += 1
  lights = lights.replace("1111111","0000000")
  lights = lights.replace("111111","000000")
  lights = lights.replace("11111","00000")
  lights = lights.replace("1111","0000")
  if lights.count('1') == 0 or lights.count('0') == 0:
    break

print (count)
