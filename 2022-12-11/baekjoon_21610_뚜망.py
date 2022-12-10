# BOJ 마법사 상어와 비바라기

N, M = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]
move = [list(map(int, input().split())) for _ in range(M)]
dir_r = [0, -1, -1, -1, 0, 1, 1, 1]
dir_c = [-1, -1, 0, 1, 1, 1, 0, -1]

q = [[N -2, 0], [N -1, 0], [N -2, 1], [N -1, 1]]
for i in range(M):
    # 구름이 n번 방향으로 이동하고 비가 1씩 내림
    d, s = move[i][0] - 1, move[i][1] % N
    d1, d2 = dir_r[d] * s, dir_c[d] * s
    ex = {}
    for j in range(len(q)):
        r, c = q[j]
        nr = (r + (d1 + N) if d1 < 0 else r + d1) % N
        nc = (c + (d2 + N) if d2 < 0 else c + d2) % N
        q[j] = [nr, nc]
        ex[(nr, nc)] = 1
        grid[nr][nc] += 1

    # 대각선 방향에 물이 있는 개수만큼 물의 양 증가
    while q:
        r, c = q.pop(0)
        cnt = 0
        for dr, dc in (-1, -1), (1, -1), (-1, 1), (1, 1):
            nr, nc = r + dr, c + dc
            if -1 < nr < N and -1 < nc < N and grid[nr][nc] > 0:
                cnt += 1
        grid[r][c] += cnt

    # 물의 양이 2이상인 것만 q에 담고 2만큼 줄어듦
    
    for i in range(N):
        for j in range(N):
            if grid[i][j] >= 2 and not ex.get((i, j)):
                grid[i][j] -= 2
                q.append([i, j])


sV = sum([grid[i][j] for j in range(N) for i in range(N)])
print(sV)
    
