# 4396 : 지뢰 찾기

import sys
dir = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

def bomb():
    bomblist = []
    for i in range(N):
        for j in range(N):
            if bombmap[i][j] == '*':
                bomblist.append((i, j))
    for (r, c) in bomblist:
        resultmap[r][c] = '*'

def cntBomb(i, j):
    cnt = 0
    if bombmap[i][j] == '*':
        bomb()
        return
    for r, c in dir:
        dr, dc = i + r, j + c
        if 0 <= dr < N and 0 <= dc < N and bombmap[dr][dc] == '*':
            cnt += 1
    resultmap[i][j] = cnt

N = int(input())
bombmap = list(sys.stdin.readline().strip() for _ in range(N))
currmap = list(sys.stdin.readline().strip() for _ in range(N))
resultmap = list(['.'] * N for _ in range(N))
for i in range(N):
    for j in range(N):
        if currmap[i][j] != '.':
            cntBomb(i, j)
        

for i in range(N):
    print(*resultmap[i], sep='')