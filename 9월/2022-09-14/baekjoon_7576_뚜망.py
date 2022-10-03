import sys
from collections import deque
input = sys.stdin.readline

def bfs():
    global cnt
    while queue:
        si, sj = queue.popleft()
        for di, dj in ((1, 0), (-1, 0), (0, -1), (0, 1)):
            ni, nj = di+si, dj+sj
            if -1< ni < n and -1 < nj < m and arr[ni][nj] == 0:
                arr[ni][nj] = arr[si][sj] + 1
                cnt -= 1
                queue.append((ni, nj))
    if not cnt:
        return arr[si][sj] -1
    return -1

m, n = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]

cnt, queue = 0, deque()
for i in range(n):
    for j in range(m):
        if arr[i][j] == 0:
            cnt += 1
        elif arr[i][j] == 1:
            queue.append((i, j))

print(bfs())