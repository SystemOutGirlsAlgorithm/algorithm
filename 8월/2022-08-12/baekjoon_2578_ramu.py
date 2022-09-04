# 2578 : 빙고
import sys

def bingo():
    bingo = 0
    if remove[0][0] == 1 and remove[1][1] == 1 and remove[2][2] == 1 and remove[3][3] == 1 and remove[4][4] == 1:
        bingo += 1
    if remove[0][4] == 1 and remove[1][3] == 1 and remove[2][2] == 1 and remove[3][1] == 1 and remove[4][0] == 1:
        bingo += 1
    for n in range(5):
        if remove[0][n] == 1 and remove[1][n] == 1 and remove[2][n] == 1 and remove[3][n] == 1 and remove[4][n] == 1:
            bingo += 1
        if bingo >= 3:
            return True
        if remove[n][0] == 1 and remove[n][1] == 1 and remove[n][2] == 1 and remove[n][3] == 1 and remove[n][4] == 1:
            bingo += 1
        if bingo >= 3:
            return True

csplate = [(0, 100, 100)] * 26
for i in range(5):
    j = 0
    for num in list(map(int, sys.stdin.readline().split())):
        csplate[num] = (num, i, j)
        j += 1

mcplate = [0]
for i in range(5):
    for num in list(map(int, sys.stdin.readline().split())):
        mcplate.append(num)
remove = list([0] * 5 for _ in range(5))
for n in range(1, 26):
    (num, i, j) = csplate[mcplate[n]]
    remove[i][j] = 1
    if n >= 10:
        if bingo() == True:
            print(n)
            break