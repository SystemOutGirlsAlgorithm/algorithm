import sys

input = sys.stdin.readline


n = int(input())
v= int(input())

graph = [ [] for _ in range(n+1)]

for _ in range(v):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    
    
visited = [False] * (n+1)

result = 0
def dfs(graph,v,visited):
    visited[v] = True
    global result
    for i in graph[v]:
        if not visited[i]:
            dfs(graph,i,visited)
            result += 1
            
dfs(graph,1,visited)
print(result)