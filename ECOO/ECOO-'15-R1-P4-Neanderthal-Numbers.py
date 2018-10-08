nums = ['ug','ook','oog','ooga','mook','ugug','oogum','oogam','ookook','mookmook']

for i in range(10):
  string = raw_input()
  answers = [0 for x in range(len(string)+1)]
  answers[0] = 1
  for j in range(len(string)):
    for k in range(10):
      if j + len(nums[k]) <= len(string):
        if string[j:j + len(nums[k])] == nums[k]:
          answers[j+len(nums[k])] += answers[j]
  print (answers[len(string)])
