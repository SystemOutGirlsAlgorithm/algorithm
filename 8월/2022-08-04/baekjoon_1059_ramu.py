# 1059 : 좋은 구간
import sys

size = int(input())
a = list(map(int, sys.stdin.readline().split()))
a.sort()
N = int(input())
result1, result2 = 0, 0

for i in range(size):
    if a[i] == N:
        break
    elif a[i-1] < N < a[i]:
        result1 = N - a[i-1] - 1
        result2 = a[i] - N - 1
        break
    elif a[0] > N :
        result1 = N - 1
        result2 = a[0] - N - 1
        break

print(result1 * result2 + result1 + result2)