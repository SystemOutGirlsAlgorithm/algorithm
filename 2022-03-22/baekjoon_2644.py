from collections import deque
n = int(input())
a, b = map(int, input().split())

m = int(input())

fam = [[] for _ in range(n+1)]
visited = [0] * (n+1)
for _ in range(m) :
    x, y = map(int, input().split())
    fam[x].append(y)
    fam[y].append(x)
    
queue = deque()
queue.append(a)
while queue : 
    q = queue.popleft()
    for f in fam[q] :
        if visited[f] == 0 :
            queue.append(f)
            visited[f] = visited[q] + 1
            if f == b :
                break

if visited[b] == 0 :
    print(-1)
else :
    print(visited[b])