# 16234 : 인구 이동

import sys, copy
from collections import deque

N, L, R = map(int, input().split())
couns = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]


dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def shift(unions):
    for union, people, connect in unions:
        avg = people/connect
        for (r, c) in union:
            couns[r][c] = int(avg)

def bfs():
    unions = []
    visited = [[False] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            connect = 1
            union = []
            if visited[i][j] == False:
                people = couns[i][j]
                queue = deque([(i, j)])
                union.append((i, j))
                visited[i][j] = True
                while(queue):
                    (r, c) = queue.popleft()
                    for dr, dc in dir:
                        nr, nc = r + dr, c + dc
                        if 0 <= nr < N and 0 <= nc < N:
                            if not visited[nr][nc] and L <= abs(couns[r][c] - couns[nr][nc]) <= R:
                                people += couns[nr][nc]
                                connect += 1
                                visited[nr][nc] = True
                                union.append((nr, nc))
                                queue.append((nr, nc))
                    
                if len(union) > 1:
                    unions.append((union, people, connect))
    return unions

cnt = 0
while(True):
    counscopy = copy.deepcopy(couns)
    shift(bfs())
    if counscopy == couns:
        break
    cnt += 1

print(cnt)