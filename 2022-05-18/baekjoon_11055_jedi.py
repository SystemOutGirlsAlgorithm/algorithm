#baekjoon_11055_jedi.py
#DP

num = 10 # int(input())
arr = [1, 100, 2, 50, 60, 30, 5, 6, 7, 8]  # list(map(int, input().split()))

dp = arr[:]

for i in range(num):
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j]+arr[i])

print(dp)