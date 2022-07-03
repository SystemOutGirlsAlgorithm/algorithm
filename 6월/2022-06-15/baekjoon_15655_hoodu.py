import sys
input = sys.stdin.readline


# 백트레킹
def backtracking(start):
    if len(l) == M:
        print(' '.join(list(map(str,l))))
    
    else:
        for i in range(start, N):
            if k[i] not in l:
                l.append(k[i])
                backtracking(i+1)
                l.pop()


N, M = map(int,input().split())
k = sorted(list(map(int,input().split())))
l = []
backtracking(0)