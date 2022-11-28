# 가장 긴 바이토닉 부분 수열

N = int(input())
lst = list(map(int, input().split()))
dp = [[1, 1] for _ in range(N)]

for i in range(N):
    for j in range(i + 1, N):
        if lst[i] < lst[j]:
            dp[j][0] = max(dp[j][0], dp[i][0] + 1)
        ii, jj = N - i - 1, N - j - 1
        if lst[ii] < lst[jj]:
            dp[jj][1] = max(dp[jj][1], dp[ii][1] + 1)

print(max(map(lambda x: x[0] + x[1], dp)) - 1)