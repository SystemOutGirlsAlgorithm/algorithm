import sys
from collections import deque

input = sys.stdin.readline


n, m = map(int,input().split())

graph = [ [] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    
def bfs (graph,start,visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i]=True
                
visited = [False] * (n+1)

count = 0

for i in range(1,n+1):
    if not visited[i]:
        bfs(graph,i,visited)
        count+=1
        
print(count)