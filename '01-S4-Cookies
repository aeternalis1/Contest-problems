n = int(input())
cookies = []
ans = 0

for i in range(n):
  cookies.append(list(map(int,input().split()))) #x,y

for i in range(n):
  for j in range(n):
    for k in range(n):
      if i != j != k != i:
        a = (abs(cookies[i][1]-cookies[j][1])**2+abs(cookies[i][0]-cookies[j][0])**2)**0.5
        b = (abs(cookies[i][1]-cookies[k][1])**2+abs(cookies[i][0]-cookies[k][0])**2)**0.5
        c = (abs(cookies[j][1]-cookies[k][1])**2+abs(cookies[j][0]-cookies[k][0])**2)**0.5
        s = (a+b+c)/2
        d = 0
        if s == 0 or a * a + b * b - c * c < 0 or b * b + c * c - a * a < 0 or c * c + a * a - b * b < 0:
          if a > d:
            d = a
          if b > d:
            d = b
          if c > d:
            d = c
        else:
          d = 2*(a*b*c/(4*(s*(s-a)*(s-b)*(s-c))**0.5))
        if d > ans:
          ans = d

print (round(ans,2))
