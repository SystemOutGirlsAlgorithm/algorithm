# 10773 : 제로

import sys

K = int(input())
result = []
for _ in range(K):
    num = int(input())
    if num != 0:
        result.append(num)
    else:
        del result[-1]

cnt = 0
for n in result:
    cnt += n

print(cnt)