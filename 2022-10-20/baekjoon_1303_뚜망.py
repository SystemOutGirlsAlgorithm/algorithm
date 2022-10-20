# 백준 1303 전투

def bfs(s, *po):
	cnt = 1
	q = [po]
	war[po[0]][po[1]] = 0
	while q:
		r, c = q.pop(0)
		for dr, dc in ((0, 1), (1, 0), (0, -1), (-1, 0)):
			nr, nc = r + dr, c + dc
			if -1 < nr < M and -1 < nc < N and war[nr][nc] == s:
				war[nr][nc] = 0
				cnt += 1
				q.append((nr, nc))
	return cnt ** 2

N, M = map(int, input().split())
war = [list(input()) for _ in range(M)]

cnt_w = cnt_b = 0
for i in range(M):
	for j in range(N):
		if war[i][j] == 'B':
			cnt_b += bfs('B', i, j)
		elif war[i][j] == 'W':
			cnt_w += bfs('W', i, j)

print(cnt_w, cnt_b)