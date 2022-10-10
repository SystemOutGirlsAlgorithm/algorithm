# 유기농 배추

import sys
input = sys.stdin.readline

for _ in range(int(input())):
    M, N, K = map(int, input().split())
    arr = [[0] * M for _ in range(N)]
    v = [[0] * M for _ in range(N)]
    cnt = 0

    for _ in range(K):
        x, y = map(int, input().split())
        arr[y][x] = 1

    for i in range(N):
        for j in range(M):
            if arr[i][j] and v[i][j] == 0:
                cnt += 1
                queue = [(i, j)]
                v[i][j] = 1
                while queue:
                    r, c = queue.pop()
                    for dr, dc in ((0, 1), (1, 0), (-1, 0), (0, -1)):
                        nr, nc = r + dr, c + dc
                        if -1 < nr < N and -1 < nc < M and v[nr][nc] == 0 and arr[nr][nc]:
                            v[nr][nc] = 1
                            queue.append((nr, nc))
        
    print(cnt)