# 1913 : 달팽이
import sys
N = int(input())
result = int(input())

snail = [[0] * N for _ in range(N)]
idx = [0] * (N * N + 1)

dir = [(1, 0), (0, 1), (-1, 0), (0, -1)]
def fillSnail():
    num = N * N
    d = 0
    currR, currC = 0, 0
    snail[currR][currC] = num
    idx[num] = (currR + 1, currC + 1)
    dirR, dirC = dir[d]
    while num > 1:
        num -= 1
        r, c = currR + dirR, currC + dirC
        if r < 0 or r == N or c < 0 or c == N or snail[r][c] != 0:
            d = (d + 1) % 4
        dirR, dirC = dir[d]
        currR, currC = currR + dirR, currC + dirC
        snail[currR][currC] = num
        idx[num] = (currR + 1, currC + 1)


fillSnail()
for i in range(N):
    print(*snail[i], sep=' ')
print(idx[result][0],idx[result][1])
