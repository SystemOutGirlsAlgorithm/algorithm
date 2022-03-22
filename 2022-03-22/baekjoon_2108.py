import sys
from collections import Counter
input = sys.stdin.readline
n = int(input())

value = []
for _ in range(n) :
    value.append(int(input()))
value.sort()

# 산술평균
sAvg = round(sum(value) / n)
print(sAvg)

# 중앙값
mid = (n-1) // 2
print(value[mid])

# 최빈값
if len(value) == 1 :
    print(value[0])
else :
    cnt = Counter(value)
    if len(cnt) == 1 :
        print(cnt)
        print(max(cnt))
    else :
        cnt = cnt.most_common(2)
        print(cnt)
        if cnt[0][1] > cnt[1][1] :
            print(cnt[0][0])
        elif cnt[0][1] == cnt[1][1] :
            print(cnt[1][0])
        
#범위
print(max(value) - min(value))