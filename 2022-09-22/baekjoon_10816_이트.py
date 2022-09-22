# 상근이가 가지고 있는 숫자 카드의 개수 N
n = int(input())
nn = list(map(int, input().split()))
m = int(input())
mm = list(map(int, input().split()))

from collections import Counter
nnn = Counter(nn)

for i in mm:
    print(nnn[i], end=' ')