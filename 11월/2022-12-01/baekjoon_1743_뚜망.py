# BOJ 음식물 피하기
import sys
input = sys.stdin.readline

N, M, K = map(int, input().split())
v = [[0] * M for _ in range(N)]

for _ in range(K):
    r, c = map(int, input().split())
    v[r - 1][c - 1] = 1

mV = 0
for r in range(N):
    for c in range(M):
        if v[r][c] == 1:
            v[r][c] = 0
            q = [(r, c)]
            cnt = 1
            while q:
                i, j = q.pop(0)
                for di, dj in (1, 0), (-1, 0), (0, -1), (0, 1):
                    ni, nj = i + di, j + dj
                    if -1 < ni < N and -1 < nj < M and v[ni][nj] == 1:
                        v[ni][nj] = 0
                        cnt += 1
                        q.append((ni, nj))
            mV = max(cnt, mV)

print(mV)