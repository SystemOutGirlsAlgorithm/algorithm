import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = sorted(list(map(int, input().split())))
visit = [0] * N
tmp = []

def f(i, lst):
    if i == M:
        tmp.append(tuple(lst))
        return

    for j in range(N):
        if visit[j] == 0:
            visit[j] = 1
            f(i+1, lst+[arr[j]])
            visit[j] = 0

f(0, [])
tmp = sorted(set(tmp))
for t in tmp:
    print(*t)