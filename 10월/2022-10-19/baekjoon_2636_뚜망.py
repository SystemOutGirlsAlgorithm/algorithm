# BOJ 2636 치즈

N, M = map(int, input().split())
cheese = [list(map(int, input().split())) for _ in range(N)]
direction = [(1, 0), (0, 1), (0, -1), (-1, 0)]

q, cq = [], {0: [(0, 0)]}
for i in range(N):
    for j in range(M):
        if (i == 0 or i == N-1) or (j == 0 or j == M-1):
            cq[0].append((i, j))

def melting():
    i = 0
    while cq.get(i):
        q = cq.get(i)[:]
        while q:
            cr, cc = q.pop(0)
            for dir in direction:
                nr = cr + dir[0]
                nc = cc + dir[1]
                if nr < 0 or nr >= N or nc < 0 or nc >= M:
                    continue
                if cheese[nr][nc] == 1:
                    if cq.get(i+1): 
                        cq[i+1].append((nr, nc))
                    else:
                        cq[i+1] = [(nr, nc)]
                    cheese[nr][nc] = i + 2
                elif cheese[nr][nc] == 0:
                    cheese[nr][nc] = -1
                    q.append((nr, nc))
            # print(cq)
        i += 1
melting()

print(f'{max(cq.keys())} \n{len(cq.get(max(cq.keys())))}')