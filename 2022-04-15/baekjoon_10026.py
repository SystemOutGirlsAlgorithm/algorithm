from collections import deque
import sys
input = sys.stdin.readline

n =int(input())
graph = []

for _ in range(n) :
    graph.append(list(input()))

def bfs(i, j) :
    queue = deque()
    visited[i][j] = 1
    tmp = graph[i][j]
    queue.append([i, j])
    while queue :
        p, q = queue.popleft()
        for a, b in ([-1, 0], [1, 0], [0, 1], [0, -1]) :
            if 0 <= p+a < n and 0 <= q+b < n :
                if tmp == graph[p+a][q+b] and visited[p+a][q+b] == 0 :
                    visited[p+a][q+b] = 1
                    queue.append([p+a, q+b])
                    if graph[p+a][q+b] == 'R' :
                        graph[p+a][q+b] = 'G'
    return 1
    
# 적록색약이 아닌 사람
visited = [[0] * n for _ in range(n)]
count = 0    
for i in range(n) :
    for j in range(n) :
        if visited[i][j] == 0 :
            count += bfs(i, j)
            if graph[i][j] == 'R' :
                graph[i][j] = 'G'
print(count, end=" ")        

# 적록색약인 사람
visited = [[0] * n for _ in range(n)]
count = 0    
for i in range(n) :
    for j in range(n) :
        if visited[i][j] == 0 :
            count += bfs(i, j)
print(count, end=" ")  