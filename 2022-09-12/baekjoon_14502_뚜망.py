import sys
import copy
from collections import deque
input = sys.stdin.readline

def wall(idx, level):
    global maxV
    if level == 3:
        copymap = copy.deepcopy(labmap)
        queue = deque()
        cnt = len(po_2) + cnt_1 + 3
        for po in po_2:
            queue.append(po)

        while queue:
            vi, vj = queue.popleft()
            for di, dj in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                ni, nj = vi + di, vj + dj
                if 0 <= ni < n and 0 <= nj < m and copymap[ni][nj] == 0:
                    copymap[ni][nj] = 2
                    cnt += 1
                    queue.append((ni, nj))
        maxV = max(maxV, n * m - cnt)
        return

    for p in range(idx, len(po_0)):
        pi, pj = po_0[p]
        if labmap[pi][pj] == 0:
            labmap[pi][pj] = 1
            wall(p+1, level + 1)
            labmap[pi][pj] = 0

n, m = map(int, input().split())
labmap = [list(map(int, input().split())) for _ in range(n)]
maxV = 0

cnt_1 = 0
po_2, po_0 = [], []
for i in range(n):
    for j in range(m):
        if labmap[i][j] == 1:
            cnt_1 += 1
        elif labmap[i][j] == 2:
            po_2.append((i, j))
        else:
            po_0.append((i, j))

wall(0, 0)
print(maxV)
