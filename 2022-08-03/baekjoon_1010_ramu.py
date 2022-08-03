# 1010 : 다리 놓기

import sys
import math

a = [list(map(int, sys.stdin.readline().split())) for _ in range(int(input()))]

for i in a:
    big = max(i)
    small = min(i)
    b = math.factorial(big)/(math.factorial(small) * math.factorial(big-small))
    print(int(b))