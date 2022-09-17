import copy
from collections import deque
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
shark = deque()

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            shark.append((i, j))

distance = deque()
for row in range(n):
    for col in range(m):
        if (row, col) not in shark:
            visit = copy.deepcopy(arr)
            queue = deque()
            queue.append((row, col))
            check = False
            while queue:
                si, sj = queue.popleft()
                for di, dj in ((1, 1), (-1, 1), (1, -1), (-1, -1), (1, 0), (0, 1), (-1, 0), (0, -1)):
                    ni, nj = si+di, sj+dj
                    if -1 < ni < n and -1 < nj < m and visit[ni][nj] == 0:
                        visit[ni][nj] = visit[si][sj] + 1
                        queue.append((ni, nj))
                    elif (ni, nj) in shark:
                        distance.append(visit[si][sj]+1)
                        check = True
                        break
                if check:
                    break

print(max(distance))
