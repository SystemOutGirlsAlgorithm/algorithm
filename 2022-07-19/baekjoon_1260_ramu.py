from collections import deque
import sys

def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=" ")
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    while(queue):
        v = queue.popleft()
        print(v, end=" ")
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True

def sortGraph(N, graph):
    for i in range(1, N+1):
        graph[i].sort()

def inputGraph(M, graph):
    for _ in range(M):
        a, b = map(int, sys.stdin.readline().split())
        graph[a].append(b)
        graph[b].append(a)
    
N, M, V = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited1 = [False] * (N+1)
visited2 = [False] * (N+1)
inputGraph(M, graph)
sortGraph(N, graph)
dfs(graph, V, visited1)
print()
bfs(graph, V, visited2)