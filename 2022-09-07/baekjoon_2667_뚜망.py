# 단지 번호 붙이기
n = int(input())
arr = [list(map(int, input())) for _ in range(n)]
visited = [[0] * n for _ in range(n)]
lst = []

for i in range(n):
    for j in range(n):
        if arr[i][j] == 1 and visited[i][j] == 0:
            queue = [(i, j)]
            visited[i][j] = 1
            cnt = 1
            while queue:
                sti, stj = queue.pop(0)
                for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                    ni, nj = sti + di, stj + dj
                    if 0 <= ni < n and 0 <= nj < n and arr[ni][nj] == 1 and visited[ni][nj] == 0:
                        visited[ni][nj] = 1
                        cnt += 1
                        queue.append((ni, nj))
            lst.append(cnt)

lst.sort()
print(len(lst))
for l in lst:
    print(l)


# 2

n = int(input())
arr = [list(map(int, input())) for _ in range(n)]
lst = []

for i in range(n):
    for j in range(n):
        if arr[i][j] == 1:
            queue = [(i, j)]
            arr[i][j] = 0
            cnt = 1
            while queue:
                sti, stj = queue.pop(0)
                for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                    ni, nj = sti + di, stj + dj
                    if 0 <= ni < n and 0 <= nj < n and arr[ni][nj] == 1:
                        arr[ni][nj] = 0
                        cnt += 1
                        queue.append((ni, nj))
            lst.append(cnt)

lst.sort()
print(len(lst))
print('\n'.join(map(str, lst)))