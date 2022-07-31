# 1325 : 효율적인 해킹

from collections import deque
import sys

def bfs(graph, start, N):
    flag = [False] * (N + 1)
    queue = deque([start])
    flag[start] = True
    cnt = 1
    while(queue):
        v = queue.popleft()
        for i in graph[v]:
            if not flag[i]:
                queue.append(i)
                flag[i] = True
                cnt += 1
    return cnt

N, M = map(int, input().split())
arr = [[] for _ in range(N+1)]
for i in range(M):
    a, b = map(int, sys.stdin.readline().split())
    arr[b].append(a)

maxHack = 0
maxlist = []
for i in range(1, N+1):
    result = bfs(arr, i, N)
    if maxHack > result:
        continue
    elif maxHack == result:
        maxlist.append(i)
    else:
        maxHack = result
        maxlist = [i]


print(*maxlist, sep=" ")