n = int(raw_input())
balloons = map(int, raw_input().split())
array = [0] * (n+1)
count = 0

for i in range(len(balloons)):
    if not array[balloons[i]]:
        array[balloons[i] - 1] += 1
        count += 1
    else:
        array[balloons[i]] -= 1
        array[balloons[i] - 1] += 1

print count
