# DFS

import sys

c = int(input())
clink = [[] for _ in range(c+1)]
visited = [False]*(c+1)
for _ in range(int(input())) :
    a, b = map(int, sys.stdin.readline().split())
    clink[a].append(b)
    clink[b].append(a)

def dfs(v):
    visited[v] = True
    for i in clink[v]:
        if not visited[i]:
            dfs(i)
dfs(1)
print(visited.count(True)-1)


# BFS

from collections import deque
import sys

def appendInput(graph):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

def bfs(start, visited, cnt):
    queue = deque([start])
    visited[start] = True
    while(queue):
        v = queue.popleft()
        for i in graph[v]:
            if not visited[i]:
                visited[i] = True
                cnt += 1
                queue.append(i)
    return cnt

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
graph = [[] for _ in range(N+1)]
visited = [False] * (N+1)
for i in range(M):
    appendInput(graph)
print(bfs(1, visited, 0))