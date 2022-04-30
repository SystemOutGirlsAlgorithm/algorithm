from collections import deque
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
virus = []
for _ in range(n) :
    virus.append(list(map(int, input().split())))

s, x, y = map(int, input().split())

queue = []

for i in range(n) :
    for j in range(n) :
        if virus[i][j] != 0 :
            queue.append([virus[i][j], i, j, 0])

queue.sort()
queue = deque(queue)

while queue :
    num, i, j, time = queue.popleft()
    if time == s :
        break
    for p, q in ([-1, 0], [1, 0], [0, -1], [0, 1]) :
        if 0<= i+p <= n-1 and 0<= j+q <= n-1 :
            if virus[i+p][j+q] == 0 :
                virus[i+p][j+q] = num
                queue.append([virus[i+p][j+q], i+p, j+q, time+1])

print(virus[x-1][y-1])