# 14467 : 소가 길을 건너간 이유 1
import sys
FIRST = 10
LEFT = 0
RIGHT = 1

change = [FIRST]*11

cnt = 0
for _ in range(int(input())):
    n, pos = map(int, sys.stdin.readline().split())
    if change[n] != FIRST and pos != change[n]:
        cnt += 1
    change[n] = pos

print(cnt)