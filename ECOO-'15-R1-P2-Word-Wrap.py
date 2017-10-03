for i in range(10):
  W = int(raw_input()) #width of output(characters)
  sentence = raw_input().split() #sentence to divide up (stored in list)
  while len(sentence) > 0:
    output = [] #this will be the printed line
    length = 0
    j = 0
    if len(sentence[j]) > W:
      word = sentence[j]
      sentence[j] = word[W:]
      output.append(word[0:W])
    else:
      while length < W and len(sentence) > 0:
        if len(sentence[j]) + length <= W:
          output.append(sentence[j])
          length += len(sentence[j]) + 1
          sentence.remove(sentence[j])
        else:
          break
    print (' '.join(output))
    if len(sentence) == 0:
      break
  print ("=====")
