# 미로탐색
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
maze = [list(map(int, input().strip())) for _ in range(n)]
visited = [[0]*m for _ in range(n)]
visited[0][0] = 1
queue = [(0, 0)]


while 1:
    i, j = queue.pop(0)
    for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        ni, nj = i + di, j + dj
        if 0 <= ni < n and 0 <= nj < m and maze[ni][nj] and not visited[ni][nj]:
            visited[ni][nj] = visited[i][j] + 1  
            queue.append((ni, nj))

    if (i+1, j+1) == (n, m):
        break

print(visited[i][j])
