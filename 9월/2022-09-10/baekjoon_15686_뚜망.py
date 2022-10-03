#
from itertools import combinations
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
chickens, home = [], []

for i in range(n):
    for j in range(n):
        if arr[i][j] == 2:
            chickens.append((i, j))
        elif arr[i][j] == 1:
            home.append((i, j))

min_sum = n ** n
for chi in combinations(chickens, m):
    sumV = 0
    for h in home:
        hi, hj = h
        minV = n * n
        for c in chi:
            ci, cj = c
            temp = abs(ci - hi) + abs(cj - hj)
            minV = temp if minV > temp else minV
        sumV += minV
    min_sum = sumV if min_sum > sumV else min_sum

print(min_sum)

#
import sys
from itertools import combinations
input = sys.stdin.readline
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
chickens, home = [], []

for i in range(n):
    for j in range(n):
        if arr[i][j] == 2:
            chickens.append((i, j))
        elif arr[i][j] == 1:
            home.append((i, j))

min_sum = n ** n
for chi in combinations(chickens, m):
    sumV = 0
    for h in home:
        sumV += min([abs(h[0] - c[0]) + abs(h[1] - c[1]) for c in chi])
        if sumV > min_sum:
            break
    min_sum = min(min_sum, sumV)

print(min_sum)

#
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
chickens, house = [], []
ans = n**n

for i in range(n):
    for j in range(n):
        if arr[i][j] == 2:
            chickens.append((i, j))
        elif arr[i][j] == 1:
            house.append((i, j))

lh, lc = len(house), len(chickens)
distance = [[0] * lc for _ in range(lh)]
for h in range(lh):
    for c in range(lc):
        distance[h][c] = abs(house[h][0] - chickens[c][0]) + abs(house[h][1] - chickens[c][1])

def dfs(k, lst):
    global ans
    if len(lst) == m:
        sumV = 0
        for h in range(lh):
            sumV += min([distance[h][l] for l in lst])
            if sumV > ans:
                break
        ans = min(ans, sumV)

    for c in range(k, lc):
        if len(lst) >= m:
            break
        dfs(c+1, lst+[c])

dfs(0, [])
print(ans)
