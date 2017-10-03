n,m = map(int,input().split())
langs = input().split()
langs.insert(0,'English')
trans = {}
for i in range(m):
  l1,l2,w = input().split()
  w = int(w)
  l1 = langs.index(l1)
  l2 = langs.index(l2)
  try:
    trans[l1].append([l2,w])
  except:
    trans[l1] = [[l2,w]]
  try:
    trans[l2].append([l1,w])
  except:
    trans[l2] = [[l1,w]]
langs = [x+1 for x in range(n)]
queue = [0]
found = []
dp = [100000000 for x in range(n+1)] #keeps track of minimum cost to each language (w/ min translations)
dp[0] = 0
ans = 0
while queue and langs:
  for i in range(len(queue)):
    current = queue.pop(0)
    for i in trans[current]:
      if i[0] in langs: #found new language(there's only meaning to continuing if its a new language)
        found.append(i[0])
        if i[1] < dp[i[0]]:
          dp[i[0]] = i[1]
        if i[0] not in queue:
          queue.append(i[0])
  for i in found:
    try:
      langs.remove(i)
    except:
      None
if langs == []:
  for i in dp:
    ans += i
  print (ans)
else:
  print ("Impossible")
