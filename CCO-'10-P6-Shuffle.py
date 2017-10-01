string = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','_']
code = []
codes = [[] for x in range(27)]

for i in range(27):
  code.append(input())
  
for i in range(len(code)): #find each cycle
  current = code[i]
  while True:
    if current == string[i]:
      codes[i].insert(0,current)
      break
    else:
      codes[i].append(current)
    current = code[string.index(current)]

I = int(input()) #amount of times letters shuffle

sentence = list(input()) #starting sentence

for i in range(len(sentence)):
  sentence[i] = codes[string.index(sentence[i])][I%len(codes[string.index(sentence[i])])]

print (''.join(sentence))
