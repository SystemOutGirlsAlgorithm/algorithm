import sys

input = sys.stdin.readline

t = int(input())


def dfs(v):
    visited[v]=True
    next = graph[v]
    if not visited[next]:
            dfs(next)

for _ in range(t):
    n = int(input())
    result = 0
    graph = [0]+list(map(int,input().split()))
    visited = [False]*(n+1)
    
    for i in range(1,n+1):
        if not visited[i]:
            dfs(i)
            result +=1
    print(result)
            
    
