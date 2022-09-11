import sys
sys.stdin = open('input.txt')

board = [list(map(int, input().split())) for _ in range(5)]
answer = [list(map(int, input().split())) for _ in range(5)]
temp = [0] * 25

def checkBingo():
    cnt = 0
    diag1 = diag2 = 0
    for row in range(5):
        if sum(board[row]) == 0:
            cnt += 1
        col_cnt = 0
        for col in range(5):
            col_cnt += board[col][row]
        if col_cnt == 0:
            cnt += 1
        diag1 += board[row][row]
        diag2 += board[row][4-row]
    if diag1 == 0: cnt += 1
    if diag2 == 0: cnt += 1
    return cnt

for i in range(5):
    for j in range(5):
        temp[board[i][j]-1] = (i, j)

check = False
for sti in range(5):
    for stj in range(5):
        bi, bj = temp[answer[sti][stj]-1]
        board[bi][bj] = 0
        if checkBingo() >= 3:
            check = True
            break
    if check:
        break

print(sti*5 + (stj+1))

