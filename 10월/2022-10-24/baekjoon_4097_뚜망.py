# 백준 4097 - 수익

import sys
input = sys.stdin.readline

while 1:
    N = int(input())
    if not N:
        break
    dp = [int(input()) for _ in range(N)]
    for i in range(1, N):
        if dp[i - 1] > 0:
            dp[i] = dp[i - 1] + dp[i]

    print(max(dp))
