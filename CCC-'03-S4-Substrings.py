N = int(input())

def prefix(a,b): #find longest common prefix between suffix and the suffix before
  n = min(len(a),len(b)) #the longest common prefix can only go up to the smaller length of suffixes
  for k in range(n):
    if a[k:k+1] != b[k:k+1]: #if the letters don't match, the longest common prefix goes up to 'k', the length so far
      return k
  return n
    
for i in range(N):
  string = input()
  suffix = []
  final = []
  count = 0
  for j in range(len(string)):
    suffix.append(string[j:])
  suffix.sort()
  
  count += len(suffix[0])+1 #each suffix is a distinct substring already
  
  for j in range(1,len(string)):
    lcp = prefix(suffix[j],suffix[j-1]) #find longest common prefix
    count += len(suffix[j])-lcp
    
  print (count)
