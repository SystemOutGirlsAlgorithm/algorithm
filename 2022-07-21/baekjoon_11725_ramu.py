from collections import deque
import sys
N = int(input())
graph = [[] for _ in range(N + 1)]
parent = [0] * (N + 1)
visited = [False] * (N + 1)

def inputGraph(graph, N):
    for _ in range(N-1):
        a, b = map(int, sys.stdin.readline().split())
        graph[a].append(b)
        graph[b].append(a)

# def dfs(graph, v, visited, parent):
#     visited[v] = True
#     for i in graph[v]:
#         if not visited[i]:
#             parent[i] = v
#             dfs(graph, i, visited, parent)

def bfs(graph, start, visited, parent):
    queue = deque([start])
    visited[start] = True
    while(queue):
        v = queue.popleft()
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                parent[i] = v
                visited[i] = True

inputGraph(graph, N)
bfs(graph, 1, visited, parent)
print(*parent[2:], sep="\n")