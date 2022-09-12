import sys
from collections import deque
input = sys.stdin.readline

def bfs(n, h):
    global cnt_0
    while queue:
        si, sj = queue.popleft()
        for di, dj in ((n, 0), (-n, 0), (-1, 0), (1, 0), (0, -1), (0, 1)):
            if (di == 1 and si%n == n-1) or (di == -1 and si%n == 0):
                continue
            ni, nj = si + di, sj + dj
            if 0 <= ni < n * h and 0 <= nj < m and arr[ni][nj] == 0:
                arr[ni][nj] = arr[si][sj] + 1
                cnt_0 -= 1
                queue.append((ni, nj))

    if cnt_0 == 0:
        return arr[si][sj] - 1
    else:
        return -1

m, n, h = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n*h)]

cnt_0, queue = 0, deque()
for i in range(n*h):
    for j in range(m):
        if arr[i][j] == 0:
            cnt_0 += 1
        elif arr[i][j] == 1:
            queue.append((i, j))

print(bfs(n, h))
