from collections import deque
import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())

load = [[0] * m for _ in range(n)]

for _ in range(k) : 
    a, b = map(int, input().split())
    load[a-1][b-1] = 1

answer = 0
def solution(i, j) :
    global answer
    queue = deque()
    queue.append([i, j])
    load[i][j] = -1
    count = 1
    while queue :
        p, q = queue.popleft()
        for a, b in ([-1, 0], [1, 0], [0, 1], [0, -1]) :
            if 0 <= p + a <= n-1 and 0 <= q + b <= m - 1 :
                if load[p+a][q+b] == 1 :
                    queue.append([p+a, q+b])
                    load[p+a][q+b] = -1
                    count += 1
    answer = max(answer, count)
    
for i in range(n) :
    for j in range(m) :
        if load[i][j] == 1 :
            solution(i, j)
print(answer)