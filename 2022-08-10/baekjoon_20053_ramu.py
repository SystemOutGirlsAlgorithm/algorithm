# 20053 : 최소, 최대 2
import sys

T = int(input())

for i in range(T):
    N = int(input())
    test = list(map(int, sys.stdin.readline().split()))
    print(min(test), max(test))
