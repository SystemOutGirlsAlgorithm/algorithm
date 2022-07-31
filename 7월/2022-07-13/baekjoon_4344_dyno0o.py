import sys

c = int(input())
score = []
for i in range(c):
    score = list(map(int, sys.stdin.readline().split()))
    n = score[0]
    score = score[1:]

    mean = 0
    for s in score:
        mean += s
    mean = mean / n

    p = 0
    for s in score:
        if s > mean:
            p += 1

    ratio = (p/n) * 100
    print("{:.3f}%".format(round(ratio,3)))

## Using numpy
# import sys
# import numpy as np
# c = int(input())
# score = []
# for i in range(c):
#     score = list(map(int, sys.stdin.readline().split()))
#     n = score[0]
#     score = np.delete(score, 0)
#     mean = score.mean()
#     p = np.where(score > mean)
#     ratio = (len(p[0])/n) * 100
#     print("{:.3f}%".format(round(ratio,3)))
