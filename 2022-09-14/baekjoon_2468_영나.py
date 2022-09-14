import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
graph = []

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(graph,x,y,value,visited):
    queue = deque()
    queue.append((x,y))
    visited[x][y]=True
    
    while queue:
        a,b = queue.popleft()
        
        for i in range(4):
            nx = a+dx[i]
            ny = b+dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if graph[nx][ny] > value and not visited[nx][ny]:
                visited[nx][ny]=True
                queue.append((nx,ny))
            

for _ in range(n):
    graph.append(list(map(int,input().split())))
    
    
# 제일 큰 수를 구하고 큰 수 -1 까지 돌리고 카운트 체크 
value = 0
for i in range(n):
    for j in range(n):
        if graph[i][j] > value:
            value = graph[i][j]
            
result = 0
for i in range(value):
    visited= [ [False]*n for _ in range(n)]
    count = 0
    for j in range(n):
        for k in range(n):
            if graph[j][k] > i and not visited[j][k]:
                bfs(graph,j,k,i,visited)
                count+=1

    if count > result:
        result = count
print(result)