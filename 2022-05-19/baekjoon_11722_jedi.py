#baekjoon_11722_jedi.py
#DP

num = 6 # int(input())
arr = [10, 30, 10, 20, 20, 10] # list(map(int, input().split()))

dp = [0] * num

for i in range(num):
    for j in range(i):
        if arr[i] < arr[j]:
            dp[i] = max(dp[i], dp[j]+1)

print(max(dp)+1)
