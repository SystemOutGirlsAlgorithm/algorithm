import sys
input = sys.stdin.readline


def Knapsack(N, K, WV):
    arr = [[0] * (K+1) for _ in range(N+1)]
    for i in range(1, N+1):
        for j in range(1, K+1):
            w = WV[i][0]
            v = WV[i][1]

            if j < w:
                arr[i][j] = arr[i-1][j]
            else:
                arr[i][j] = max(arr[i-1][j], arr[i-1][j-w]+v)

    print(arr[N][K])


N, K = map(int,input().split())
WV = [[0,0]]
for i in range(N):
    WV.append(list(map(int,input().split())))

Knapsack(N,K,WV)


