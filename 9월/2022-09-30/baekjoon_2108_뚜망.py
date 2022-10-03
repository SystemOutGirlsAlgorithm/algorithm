import sys
from collections import Counter
input = sys.stdin.readline

N = int(input())
lst = sorted([int(input()) for _ in range(N)])

# 산술평균
avg = round(sum(lst) / N)

# 중앙값
mid = lst[N//2]

# 범위
rng = lst[-1] - lst[0]

# 최빈값
arr = sorted(Counter(lst).most_common(), key=lambda x:(-x[1]))
tmp = arr[0][0]
if len(arr) > 1 and arr[0][1] == arr[1][1]:
    tmp = arr[1][0]

print(avg)
print(mid)
print(tmp)
print(rng)