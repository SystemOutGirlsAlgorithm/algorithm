from collections import deque

n, m = map(int, input().split())

visited = [[0] * (m) for _ in range(n)]

floor = []

for _ in range(n) :
    floor.append(input())

queue = deque()
count = 0
for i in range(n) :
    for j in range(m) :
        if visited[i][j] > 0:
            continue
        queue.append((floor[i][j], i, j))
        count += 1
        while queue :
            q, a, b  = queue.popleft()
            visited[a][b] = count
            if q == '-' :
                if b >= m - 1 :
                    continue
                if floor[a][b+1] == '-' :
                    visited[a][b+1] = count
                    queue.append(('-', a, b+1))
            elif q == '|' :
                if a >= n - 1 :
                    continue
                if floor[a+1][b] == '|' :
                    visited[a+1][b] = count
                    queue.append(('|', a+1, b))
print(count)            
            