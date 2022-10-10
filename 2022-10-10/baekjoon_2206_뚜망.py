# 벽 부수고 이동하기

import sys
from collections import deque
input = sys.stdin.readline

N, M = map(int, input().split())
arr = [list(map(int, input().strip())) for _ in range(N)]
visit = [[[0, 0] for _ in range(M)] for _ in range(N)]
queue = deque([(0, 0, 0)])
res = -1

while queue:
    r, c, wall = queue.popleft()
    if (r, c) == (N-1, M-1):
        res = visit[r][c][wall] + 1
        break

    for dr, dc in ((-1, 0), (1, 0), (0, 1), (0, -1)):
        nr, nc = r + dr, c + dc
        if -1 < nr < N and -1 < nc < M and not visit[nr][nc][wall]:    
            if not wall and arr[nr][nc]:
                visit[nr][nc][1] = visit[r][c][wall] + 1
                queue.append((nr, nc, 1))
            elif not arr[nr][nc]:
                visit[nr][nc][wall] = visit[r][c][wall] + 1
                queue.append((nr, nc, wall))
print(res)