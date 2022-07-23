# 1018 : 체스판 다시 칠하기
import sys
R, C = map(int, input().split())
chessboard = [sys.stdin.readline().strip() for _ in range(R)]

def checkColor(chessboard, curR, curC, c):
    color = ['B', 'W']
    paint = 0
    firstColor = color[c]
    for i in range(curR, curR+8):
        for j in range(curC, curC+8):
            if chessboard[i][j] != firstColor:
                paint += 1
            if j == (curC + 7):
                continue
            c = 1 if c == 0 else 0
            firstColor = color[c]
    return paint

def checkChessboard(chessboard, R, C):
    pMin = 64
    for r in range(R-7):
        for c in range(C-7):
            cnt = min(checkColor(chessboard, r, c, 0), checkColor(chessboard, r, c, 1))
            if cnt == 0:
                return cnt
            if pMin > cnt:
                pMin = cnt
    return pMin

print(checkChessboard(chessboard, R, C))