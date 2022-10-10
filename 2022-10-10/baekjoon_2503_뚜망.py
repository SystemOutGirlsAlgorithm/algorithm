# 숫자 야구

from itertools import permutations

N = int(input())
arr = [[] for _ in range(N)]
cnt = 0
for i in range(N):
    arr[i] = list(map(int, input().split()))

lst = list(map(lambda x: ''.join(map(str, x)), list(permutations(range(1, 10), 3))))
for num in lst:
    for i in range(N):
        s = b = 0
        for j in range(3):
            if num[j] == str(arr[i][0])[j]:
                s += 1
            elif num[j] in str(arr[i][0]):
                b += 1
        if (s, b) != (arr[i][1], arr[i][2]):
            break
    else:
        cnt += 1

print(cnt)