N = int(input())
num = int(input())
arr = [[0] * N for _ in range(N)]

cnt = N ** 2
for i in range(N):
    arr[i][0] = cnt
    cnt -= 1

i, j = N-1, 0
d = 1
while cnt > 0:
    N -= 1
    for _ in range(N):
        j += d
        arr[i][j] = cnt
        cnt -= 1

    d *= -1
    for _ in range(N):
        i += d
        arr[i][j] = cnt
        cnt -= 1

for row in arr:
    print(*row)

for idx in range(len(arr)):
    if num in arr[idx]:
        print(idx+1, arr[idx].index(num)+1)
        break