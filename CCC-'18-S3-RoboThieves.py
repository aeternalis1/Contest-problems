N, M = map(int, raw_input().split())
grid = []
cams = []
con = "LRUD"
moves = [[0, -1], [0, 1], [-1, 0], [1, 0]]
checked = [[999999 for x in range(M)] for x in range(N)]
valid = [[True for x in range(M)] for x in range(N)]
for i in range(N):
    grid.append(list(raw_input()))
    for j in range(M):
        if grid[i][j] == 'S':
            sy = i
            sx = j
        elif grid[i][j] == 'C':
            cams.append([i, j])

for i in cams:
    y, x = i[0], i[1]
    valid[y][x] = False
    for j in range(y, N):
        if grid[j][x] == 'W':
            break
        valid[j][x] = False
    for j in range(y, -1, -1):
        if grid[j][x] == 'W':
            break
        valid[j][x] = False
    for j in range(x, M):
        if grid[y][j] == "W":
            break
        valid[y][j] = False
    for j in range(x, -1, -1):
        if grid[y][j] == "W":
            break
        valid[y][j] = False

queue = [[sy, sx]]
checked[sy][sx] = 0
if valid[sy][sx]:
    while queue:
        y, x = queue.pop(0)
        if grid[y][x] in con:
            ind = con.find(grid[y][x])
            ny = y + moves[ind][0]
            nx = x + moves[ind][1]
            if checked[ny][nx] > checked[y][x] and grid[ny][nx] != 'W':
                if valid[ny][nx] or grid[ny][nx] in con:
                    checked[ny][nx] = checked[y][x]
                    queue.append([ny, nx])
            continue
        if grid[y - 1][x] != 'W' and checked[y - 1][x] > checked[y][x] + 1:
            if valid[y - 1][x] or grid[y - 1][x] in con:
                checked[y - 1][x] = checked[y][x] + 1
                queue.append([y - 1, x])
        if grid[y + 1][x] != 'W' and checked[y + 1][x] > checked[y][x] + 1:
            if valid[y + 1][x] or grid[y + 1][x] in con:
                checked[y + 1][x] = checked[y][x] + 1
                queue.append([y + 1, x])
        if grid[y][x - 1] != 'W' and checked[y][x - 1] > checked[y][x] + 1:
            if valid[y][x - 1] or grid[y][x - 1] in con:
                checked[y][x - 1] = checked[y][x] + 1
                queue.append([y, x - 1])
        if grid[y][x + 1] != 'W' and checked[y][x + 1] > checked[y][x] + 1:
            if valid[y][x + 1] or grid[y][x + 1] in con:
                checked[y][x + 1] = checked[y][x] + 1
                queue.append([y, x + 1])

for i in range(N):
    for j in range(M):
        if grid[i][j] == '.':
            if checked[i][j] != 999999:
                print checked[i][j]
            else:
                print -1
