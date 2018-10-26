N = int(raw_input())
arr = [int(raw_input()) for x in range(N)]
temp = sorted(arr)
ans = []
while arr != temp:
    for i in range(N):
        if arr[i] != temp[i]:
            f = 0
            for j in range(i+1,N):
                if temp[j]==arr[i] and arr[j]==temp[i]:
                    arr[i],arr[j] = arr[j],arr[i]
                    ans.append([i,j])
                    f = 1
                    break
            if not f:
                for j in range(i+1,N):
                    if temp[i]==arr[j] and temp[j]!=arr[j]:
                        arr[i],arr[j] = arr[j],arr[i]
                        ans.append([i,j])
                        break
print len(ans)
for i in ans:
    print i[0]+1,i[1]+1
