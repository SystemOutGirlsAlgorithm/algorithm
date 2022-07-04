import sys
from collections import deque
input = sys.stdin.readline

n, m, r = map(int, input().split())

graph = []

for _ in range(n) :
    graph.append(list(map(int, input().split())))

temp = [[0] * m for _ in range(n)]

start = 0
while True : 
    if temp[start][start] != 0 :
        break
    queue = deque()
    # 상단
    for j in range(start, m-start) :
        queue.append(graph[start][j])
    # 우측
    for i in range(start + 1, n-start-1) :
        queue.append(graph[i][m-start-1])
    # 하단
    for j in range(m-start-1, start-1, -1) :
        queue.append(graph[n-start-1][j])
    # 좌측
    for i in range(n-start-2, start, -1) :
        queue.append(graph[i][start])
    queue.rotate(-r)
    
    # 상단
    for j in range(start, m-start) :
        temp[start][j] = queue.popleft()
    # 우측
    for i in range(start + 1, n-start-1) :
        temp[i][m-start-1] = queue.popleft()
    # 하단
    for j in range(m-start-1, start-1, -1) :
        temp[n-start-1][j] = queue.popleft()
    # 좌측
    for i in range(n-start-2, start, -1) :
        temp[i][start] = queue.popleft()
    start += 1

for i in range(n) :
    for j in range(m) :
        print(temp[i][j], end=" ")
    print()