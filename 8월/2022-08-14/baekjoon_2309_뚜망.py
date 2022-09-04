import sys
input = sys.stdin.readline

arr = [int(input()) for _ in range(9)]
cnt = [0] * 100
temp = [0] * 10

# 0 이 없으니까 숫자칸에 바로 집어넣기
for i in range(9):
    cnt[arr[i]] += 1

for j in range(1, 100):
    cnt[j] += cnt[j-1]

for k in range(8, -1, -1):
    temp[cnt[arr[k]]] = arr[k]
    cnt[arr[k]] -= 1
arr = temp[1:]

cnt = 0
for i in range(1<<9):
    temp = []
    for j in range(9):
        if i & (1<<j):
            temp.append(arr[j])
    if len(temp) == 2 and sum(arr) - sum(temp) == 100:
        for i in range(2):
            arr.remove(temp[i])
        break
print(*arr, sep='\n')