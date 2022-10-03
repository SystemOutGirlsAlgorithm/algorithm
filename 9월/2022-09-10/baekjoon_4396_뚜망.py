import sys
sys.stdin = open('input.txt')

n = int(input())
mineMap = [input() for _ in range(n)]
arr = [list(input()) for _ in range(n)]
mine = []

for i in range(n):
    for j in range(n):
        if mineMap[i][j] == '*':
            mine.append((i, j))

check = False
for i in range(n):
    for j in range(n):
        if arr[i][j] == 'x':
            if (i, j) in mine:
                check = True
                continue
            cnt = 0
            for di, dj in ((-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1)):
                if (i+di, j+dj) in mine:
                    cnt += 1
            arr[i][j] = cnt

if check:
    for mi, mj in mine:
        arr[mi][mj] = '*'

for row in arr:
    print(*row, sep='')