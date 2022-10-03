# N-Queen
def queen(row):
    global cnt
    if row == N:
        cnt += 1
        return

    for col in range(N):
        if cols[col] == 0:
            for i in range(row):
                if row - i == abs(col - diagonal[i]):
                    break
            else:
                cols[col] = 1
                diagonal[row] = col
                queen(row+1)
                cols[col] = 0
                
N = int(input())
diagonal = [0] * N
cols = [0] * N
cnt = 0

queen(0)
print(cnt)