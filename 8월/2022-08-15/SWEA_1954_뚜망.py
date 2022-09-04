T = int(input())

for tc in range(T):
    N = int(input())
    arr = [[0] * N for _ in range(N)]

    cnt, x, y, idx = 1, 0, -1, 1
    while N:
        for _ in range(N):
            y += idx
            arr[x][y] = cnt
            cnt += 1

        N -= 1
        for _ in range(N):
            x += idx
            arr[x][y] = cnt
            cnt += 1

        idx *= -1
    
    print('#%d' %(tc+1))
    for row in arr:
        print(*row)