## 2696 중앙값 구하기
## https://www.acmicpc.net/problem/2696
## heap...

import sys, math
import statistics

input = sys.stdin.readline
t = int(input())

for _ in range(t):
    size = int(input().rstrip())
    arr = []
    med = []

    for i in range(size//10 + 1):
        arr.extend([*map(int, input().rstrip().split())])

    ss = math.ceil(size/2)
    for j in range(ss):
        med.append(int(statistics.median(arr[:2*j+1])))
    
    print(ss)
    for k in range(ss//10 + 1):
        print(*med[10*k:10*(k+1)])