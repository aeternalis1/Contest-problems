p1,p2 = input().split()
N = int(input())

for i in range(N):
  games = input().split()
  p1win = 0
  p2win = 0
  valid = True
  for j in range(len(games)):
    game = games[j]
    
    if len(games)>= 4:
      print ("ne")
      valid = False
      break
    elif p1win == 2 or p2win == 2:
      print ("ne")
      valid = False
      break
    elif len(games[j])>= 4:
      if j == 2:
        g1,g2 = games[j].split(':')
        if int(g1) - 2 == int(g2):
          p1win += 1
        elif int(g2) - 2 == int(g1):
          p2win += 1
        else: 
          print ("ne")
          valid = False
          break
      else:
        print ("ne")
        valid = False
        break
    elif int(game[0]) <= 5 and int(game[2]) <= 5:
      print ("ne")
      valid = False
      break
    elif int(game[0]) > int(game[2]):
      if game[0] == '6' and int(game[2]) <= 4:
        p1win += 1
      elif game[0] == '7':
        if j <= 1:
          if int(game[2]) == 6 or int(game[2]) == 5:
            p1win += 1
          else: 
            print ("ne")
            valid = False
            break
        else:
          if int(game[2]) <= 5:
            p1win += 1
          else:
            print ("ne")
            valid = False
            break
      elif int(game[0]) > 7:
          if j <= 2:
            print ("ne")
            valid = False
            break
          else:
            if int(game[0]) - 2 == int(game[2]):
              p1win += 1
            else:
              print ("ne")
              valid = False
              break
      else:
        print ("ne")
        valid = False
        break
    elif int(game[0]) < int(game[2]):
      if game[2] == '6' and int(game[0]) <= 4:
        p2win += 1
      elif game[2] == '7':
        if j <= 1:
          if int(game[0]) == 6 or int(game[0]) == 5:
            p2win += 1
          else: 
            print ("ne")
            valid = False
            break
        else:
          if int(game[2]) - 2 == int(game[0]):
            p2win += 1
          else:
            print ("ne")
            valid = False
            break
      elif int(game[2]) > 7:
        if j <= 1:
          print ("ne")
          valid = False
          break
        else:
          if int(game[2]) - 2 == int(game[0]):
            p2win += 1
          else:
            print ("ne")
            valid = False
            break
      else:
        print ("ne")
        valid = False
        break
    else:
      print ("ne")
      valid = False
      break
  
  if valid == True:
    if p1win == p2win:
      print ("ne")
    elif p1win >= 3 or p2win >= 3:
      print ("ne")
    elif p1win <= 1 and p2win <= 1:
      print ("ne")
    elif p1 == 'federer' and p2win >= 1:
      print ("ne")
    elif p2 == 'federer' and p1win >= 1:
      print ("ne")
    else:
      print ("da")
