import sys
input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))
dp = [0] * n

for i in range(n) :
    # 2중 반복문을 이용해서 현재 원소 이전과 비교
    for j in range(i) :
        # 이전 원소보다 작고, 누적 수열의 길이가 길면 +1
        if arr[j] > arr[i] :
            if dp[j] >= dp[i] :
                dp[i] = dp[j] + 1
    # 이전 원소보다 클 경우 
    if dp[i] == 0 :
        dp[i] = 1
print(max(dp))