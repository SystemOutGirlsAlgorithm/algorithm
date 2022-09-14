import sys
from collections import deque

input = sys.stdin.readline

n = int(input())

graph = []
result = []
dx = [-1,1,0,0]
dy = [0,0,-1,1]

for _ in range(n):
    graph.append(list(map(int,input())))
    

def bfs(graph,x,y):
    queue= deque()
    queue.append((x,y))
    graph[x][y]=0
    count=1
    while queue:
        a,b=queue.popleft()
        
        for i in range(4):
            nx = a+dx[i]
            ny = b+dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if  graph[nx][ny]==1:
                graph[nx][ny]=0
                queue.append((nx,ny))
                count +=1
    return count
        
for i in range(n):
    for j in range(n):
        if graph[i][j]==1:
            result.append(bfs(graph,i,j))
            
print(len(result))
result.sort()
for i in range(len(result)):
    print(result[i])
            