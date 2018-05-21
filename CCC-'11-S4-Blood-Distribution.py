blood = input().split()
needy = input().split()
patients = 0
exON = 0
exOP = 0
exAN = 0
exAP = 0
exBN = 0
exBP = 0
exabN = 0

#DONT JUDGE ME THIS IS ONE OF THE FIRST PROGRAMS IVE EVER WRITTEN

for i in range(8):
  blood[i] = int(blood[i])
  needy[i] = int(needy[i])

for i in range(8):
  if i == 0:
    if blood[i] >= needy [i]:
      patients += int(needy[i])
      exON = int(blood[i]) - int(needy[i])
      needy[i] = 0
    elif blood [i] < needy[i]:
      patients += int(blood[i])
      blood[i] = 0
  elif i == 1:
    if blood [i] >= needy [i]:
      patients += int(needy[i])
      exOP = int(blood[i]) - int(needy[i])
      needy[i] = 0
    elif blood [i] < needy[i]:
      patients += int(blood[i])
      needy[i] = int(needy[i]) - int(blood[i])
      blood[i] = 0
      if exON > 0:
        if exON >= needy [i]:
          patients += int(needy[i])
          exON = exON - int(needy[i])
          needy[i] = 0
        elif exON < needy[i]:
          patients += exON
          needy[i] = int(needy[i]) - exON
          blood[i] = 0
          exON = 0
  elif i == 2:
    if blood [i] >= needy [i]:
      patients += int(needy[i])
      exAN = int(blood[i]) - int(needy[i])
      needy[i] = 0
    elif blood [i] < needy[i]:
      patients += int(blood[i])
      needy[i] = int(needy[i]) - int(blood[i])
      blood[i] = 0
      if exON > 0:
        if exON >= needy [i]:
          patients += int(needy[i])
          exON = exON - int(needy[i])
          needy[i] = 0
        elif exON < needy[i]:
          patients += exON
          needy[i] = int(needy[i]) - exON
          exON = 0
  elif i == 3:
    if blood [i] >= needy [i]:
      patients += int(needy[i])
      exAP = int(blood[i]) - int(needy[i])
      needy[i] = 0
    elif blood [i] < needy[i]:
      patients += int(blood[i])
      needy[i] = int(needy[i]) - int(blood[i])
      blood[i] = 0
      if exOP > 0:
        if exOP >= needy [i]:
          patients += int(needy[i])
          exOP = exOP - int(needy[i])
          needy[i] = 0
        elif exOP < needy[i]:
          patients += exOP
          needy[i] = int(needy[i]) - exOP
          exOP = 0
      if exAN > 0 and needy[i] > 0:
        if exAN >= needy [i]:
          patients += int(needy[i])
          exAN = exAN - int(needy[i])
          needy[i] = 0
        elif exAN < needy[i]:
          patients += exAN
          needy[i] = int(needy[i]) - exAN
          exAN = 0
      if exON > 0 and needy[i] > 0:
        if exON >= needy [i]:
          patients += int(needy[i])
          exON = exON - int(needy[i])
          needy[i] = 0
        elif exON < needy[i]:
          patients += exON
          needy[i] = int(needy[i]) - exON
          exON = 0
  elif i == 4:
    if blood [i] >= needy [i]:
      patients += int(needy[i])
      exBN = int(blood[i]) - int(needy[i])
      needy[i] = 0
    elif blood [i] < needy[i]:
      patients += int(blood[i])
      needy[i] = int(needy[i]) - int(blood[i])
      blood[i] = 0
      if exON > 0:
        if exON >= needy [i]:
          patients += int(needy[i])
          exON = exON - int(needy[i])
          needy[i] = 0
        elif exON < needy[i]:
          patients += exON
          needy[i] = int(needy[i]) - exON
          exON = 0
  elif i == 5:
    if blood [i] >= needy [i]:
      patients += int(needy[i])
      exBP = int(blood[i]) - int(needy[i])
      needy[i] = 0
    elif blood [i] < needy[i]:
      patients += int(blood[i])
      needy[i] = int(needy[i]) - int(blood[i])
      blood[i] = 0
      if exOP > 0:
        if exOP >= needy [i]:
          patients += int(needy[i])
          exOP = exOP - int(needy[i])
          needy[i] = 0
        elif exOP < needy[i]:
          patients += exOP
          needy[i] = int(needy[i]) - exOP
          exOP = 0
      if exBN > 0 and needy[i] > 0:
        if exBN >= needy [i]:
          patients += int(needy[i])
          exBN = exBN - int(needy[i])
          needy[i] = 0
        elif exBN < needy[i]:
          patients += exBN
          needy[i] = int(needy[i]) - exBN
          exBN = 0
      if exON > 0 and needy[i] > 0:
        if exON >= needy [i]:
          patients += int(needy[i])
          exON = exON - int(needy[i])
          needy[i] = 0
        elif exON < needy[i]:
          patients += exON
          needy[i] = int(needy[i]) - exON
          exON = 0
  elif i == 6:
    if blood[i] >= needy [i]:
      patients += int(needy[i])
      exabN = int(blood[i]) - int(needy[i])
      needy[i] = 0
    elif blood [i] < needy[i]:
      patients += int(blood[i])
      needy[i] = needy[i] - blood[i]
      blood[i] = 0
      if exAN > 0 and needy[i] > 0:
        if exAN >= needy [i]:
          patients += int(needy[i])
          exAN = exAN - int(needy[i])
          needy[i] = 0
        elif exAN < needy[i]:
          patients += exAN
          needy[i] = int(needy[i]) - exAN
          exAN = 0
      if exBN > 0 and needy[i] > 0:
        if exBN >= needy [i]:
          patients += int(needy[i])
          exBN = exBN - int(needy[i])
          needy[i] = 0
        elif exBN < needy[i]:
          patients += exBN
          needy[i] = int(needy[i]) - exBN
          exBN = 0
      if exON > 0 and needy[i] > 0:
        if exON >= needy [i]:
          patients += int(needy[i])
          exON = exON - int(needy[i])
          needy[i] = 0
        elif exON < needy[i]:
          patients += exON
          needy[i] = int(needy[i]) - exON
          exON = 0    
  else:
    if blood[i] >= needy [i]:
      patients += int(needy[i])
      needy[i] = 0
    elif blood [i] < needy[i]:
      patients += int(blood[i])
      needy[i] = needy[i] - blood[i]
      blood[i] = 0
      if exAN > 0:
        if exAN >= needy [i]:
          patients += int(needy[i])
          exAN = exAN - int(needy[i])
          needy[i] = 0
        elif exAN < needy[i]:
          patients += exAN
          needy[i] = int(needy[i]) - exAN
          exAN = 0
      if exBN > 0 and needy[i] > 0:
        if exBN >= needy [i]:
          patients += int(needy[i])
          exBN = exBN - int(needy[i])
          needy[i] = 0
        elif exBN < needy[i]:
          patients += exBN
          needy[i] = int(needy[i]) - exBN
          exBN = 0
      if exON > 0 and needy[i] > 0:
        if exON >= needy [i]:
          patients += int(needy[i])
          exON = exON - int(needy[i])
          needy[i] = 0
        elif exON < needy[i]:
          patients += exON
          needy[i] = int(needy[i]) - exON
          exON = 0   
      if exOP > 0 and needy[i] > 0:
        if exOP >= needy [i]:
          patients += int(needy[i])
          exOP = exOP - int(needy[i])
          needy[i] = 0
        elif exON < needy[i]:
          patients += exOP
          needy[i] = int(needy[i]) - exOP
          exOP = 0    
      if exAP > 0 and needy[i] > 0:
        if exAP >= needy [i]:
          patients += int(needy[i])
          exAP = exAP - int(needy[i])
          needy[i] = 0
        elif exAP < needy[i]:
          patients += exAP
          needy[i] = int(needy[i]) - exAP
          exAP = 0
      if exBP > 0 and needy[i] > 0:
        if exBP >= needy [i]:
          patients += int(needy[i])
          exBP = exBP - int(needy[i])
          needy[i] = 0
        elif exBP < needy[i]:
          patients += exBP
          needy[i] = int(needy[i]) - exBP
          exBP = 0
      if exabN > 0 and needy[i] > 0:
        if exabN >= needy [i]:
          patients += int(needy[i])
          exabN = exabN - int(needy[i])
          needy[i] = 0
        elif exabN < needy[i]:
          patients += exabN
          needy[i] = int(needy[i]) - exabN
          exabN = 0
          
print (patients)
