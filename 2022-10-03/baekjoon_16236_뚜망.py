# 16236 - 아기상어

def bfs(start):
    global time
    queue = [start]
    visit = [[0] * N for _ in range(N)] 
    select = (N, N)
    min_d = 1e9
    while queue:
        si, sj = queue.pop(0)
        for di, dj in ((-1, 0), (0, -1), (1, 0), (0, 1)):
            ni, nj = si + di, sj + dj 
            if -1 < ni < N and -1 < nj < N and visit[ni][nj] == 0:
                visit[ni][nj] = visit[si][sj] + 1
                if visit[ni][nj] > min_d:
                    break
                if arr[ni][nj] == 0 or arr[ni][nj] == size:
                    queue.append((ni, nj))
                elif arr[ni][nj] < size:
                    min_d = visit[ni][nj]
                    select = min(select, (ni, nj))
    if select == (N, N):
        return (-1, -1)
    time += min_d
    return select

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
size, eat, time = 2, 0, 0

fish = 0
for i in range(N):
    for j in range(N):
        if arr[i][j] == 9:
            arr[i][j] = 0
            start = (i, j)
        elif arr[i][j]:
            fish += 1

while fish:
    start = bfs(start)
    if start == (N, N):
        break
    fish -= 1
    eat += 1
    if eat == size:
        size += 1
        eat = 0

print(time)
