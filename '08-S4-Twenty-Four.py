import sys
sys.setrecursionlimit(1000000000)

N = int(raw_input())

def solve(ops,stack): #number of operations done, current hand
  if len(stack) == 1 and ops == 4:
    if stack[0] <= 24 and stack[0] >= 0:
      answers.append(stack[0])
  if ops < 4:
    for j in range(4):
      if not used[j]:
        used[j] = True
        temp = [x for x in stack]
        temp.append(cards[j])
        solve(ops+1,temp)
        used[j] = False
  if len(stack) > 1:
    temp = [x for x in stack]
    a = temp.pop()
    b = temp.pop()
    temp2 = [x for x in temp]
    temp2.append(a+b)
    solve(ops,temp2)
    temp2 = [x for x in temp]
    temp2.append(a-b)
    solve(ops,temp2)
    temp2 = [x for x in temp]
    temp2.append(a*b)
    solve(ops,temp2)
    if b != 0 and a%b == 0:
      temp2 = [x for x in temp]
      temp2.append(a/b)
      solve(ops,temp2)
    
for i in range(N):
  cards = [int(raw_input()) for x in range(4)]
  used = [False for x in range(4)]
  answers = []
  solve(0,[])
  print (max(answers))
