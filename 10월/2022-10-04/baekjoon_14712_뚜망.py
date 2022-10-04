# 14712 넴모넴모(Easy)
import sys
def nemo(cnt):
    global res
    if cnt == N * M:
        res += 1
        # for row in arr:
        #     print(*row)
        # print()
        return

    x = cnt // M
    y = cnt % M

    if 0 < x < N and 0 < y < M and arr[x][y-1] and arr[x-1][y-1] and arr[x-1][y]:
        nemo(cnt+1)
    else:
        arr[x][y] = 1
        nemo(cnt+1)
        arr[x][y] = 0
        nemo(cnt+1)

N, M = map(int,sys.stdin.readline().split())
arr = [[0] * M for _ in range(N)]
res = 0

nemo(0)
print(res)
