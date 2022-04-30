import sys
input = sys.stdin.readline

n = int(input())
dp = [0] * sum([i for i in range(1, n+1)])
arr = []

for _ in range(n) :
    arr += list(map(int, input().split()))

dp[0] = arr[0]
start = 0
for i in range(n-1) :
    for j in range(start, start+i+1) :
        dp[j+i+1] = max(dp[j] + arr[j+i+1], dp[j+i+1])
        dp[j+i+2] = max(dp[j] + arr[j+i+2], dp[j+i+2])
    start += i+1
    
print(max(dp))