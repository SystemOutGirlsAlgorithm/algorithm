import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())

war = []
wteam, bteam = 0, 0
visited = [[0]*n for _ in range(m)]

for _ in range(m) :
    war.append(input())
    
queue = deque()
for i in range(m) :
    for j in range(n) :
        if visited[i][j] == 1:
            continue
        queue.append((i, j))
        power = 1
        visited[i][j] = 1
        while queue :
            q = queue.popleft()
            for a, b in [[-1, 0], [0, 1], [1, 0], [0, -1]] :
                da = a + q[0]
                db = b + q[1]
                if 0 <= da <= m-1 and 0 <= db <= n-1 and war[da][db] == war[i][j]:
                    if visited[da][db] == 0 :
                        queue.append((da, db))
                        visited[da][db] = 1
                        power += 1
        if war[i][j] == 'W' :
            wteam += power**2
        else :
            bteam += power**2

print(wteam, bteam)