import sys
input = sys.stdin.readline

# 오영식이 이미 가지고 있는 랜선의 개수 K, 필요한 랜선의 개수 N
k, n = map(int, input().split())
kk = []
for _ in range(k):
    kk.append(int(input()))
    
left = 1
right = sum(kk)//n
while (left <= right):
    mid = (left + right) // 2

    cnt = 0
    for j in kk:
        cnt += j // mid

    if cnt >= n:
        left = mid + 1

    else:
        right = mid - 1

print(right)