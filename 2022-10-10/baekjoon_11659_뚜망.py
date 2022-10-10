import sys
input = sys.stdin.readline

N, M = map(int, input().split())
lst = list(map(int, input().split()))

for i in range(1, N):
    lst[i] += lst[i-1]

res = []
for _ in range(M):
    i, j = map(int, input().split())
    if i - 1 > 0:
        res.append(lst[j-1] - lst[i-2])
    else:
        res.append(lst[j-1])

print('\n'.join(map(str,res)))