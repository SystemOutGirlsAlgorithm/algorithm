from collections import deque
n, m = map(int, input().split())

answer = [0] * (n+1)

friend = [[] for _ in range(n+1)]

for _ in range(m) :
    a,b = map(int, input().split())
    friend[a].append(b)
    friend[b].append(a)

for i in range(1, n+1) :
    visited = [0] * (n+1)
    queue = deque()
    queue.append(i)
    while queue :
        q = queue.popleft()
        for f in friend[q] :
            if visited[f] == 0 and f != i:
                visited[f] += visited[q] + 1
                queue.append(f)
    answer[i] = sum(visited)

minVal = answer[1]
minPer = 1
for i in range(2, n+1) :
    if minVal > answer[i] :
        minVal = answer[i]
        minPer = i
    elif minVal == answer[i] :
        minPer = min(minPer, i)

print(minPer)
        